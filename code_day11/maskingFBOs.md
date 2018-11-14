## Masks and FBOs

__General Concept__

We will create am alpha mask to set the transparency values for another image.

- By setting a pixels transparency to 0 it becomes fully transparent, setting it to 255 is opaque. If the pixels in an image are transparent, we will be able to see through that image to the images drawn behind it.
- We can dynamically set the alpha channel of the pixels of an image by using a grayscale texture and applying it as an alpha mask.
- We can also set the transparency of a camera feed, in order to mask out certain regions of the camera image.

- The basic steps to take are :
    1. load two images
        - foreground image (image 1)
        - background image (image 2)
    2. Create an alpha mask
        - either in an FBO or,
        - using another grayscale texture
    3. Apply mask to alpha channel foreground image.
        - pixels in the mask that are white (255) will be opaque
        - pixels in the mask that are black (0) will be transparent
    4. draw background image
    5. draw foreground image on top of background image
        - see through foreground image to background

__Drawing your own alpha Mask__

For this first example, we will draw our own alpha mask using the x/y position of the mouse and drawing into a FBO (a frame buffer object), which will store our mask.

We will use :
- Two `ofImage`, one for a foreground and one for a background.
- `ofFbo maskFbo`, that we will draw our mask into.

We will follow the pipeline above-
1. load two images
```c++
backgroundImg.load("squash.jpg");
foregroundImg.load("kandp.jpg");
```
2. Create an alpha mask
    - We will be using an ofFbo to set our mask, to use an ofFbo we need to follow these steps -
        1. allocate the FBO
        ```c++
        maskFbo.allocate(width, height, GL_RGBA); // <-- notice RGBA
        ```
        2. clear the FBO in `setup()`
        ```c++
        maskFbo.begin();
        ofClear(0, 0, 0, 0); // <--- notice the 4th alpha channel
        maskFbo.end();            // clearing everything to be transparent
        ```
        3. Draw into the FBO.
            - drawing into the mask FBO happens in-between `maskFbo.begin()` and `maskFbo.end()`
            - any draw commands that happens in-between will be drawn into the FBO.
            - Anything drawn into the FBO will not be erased until `ofClear()` is called (as happened in setup).
3. Apply alpha mask to foreground image.
    - the alpha mask gets applied to the _texture_ of the foreground image
    ```c++
    // apply mask to foreground image
    foregroundImg.getTexture().setAlphaMask(maskFbo.getTexture());
    ```

4. Draw background image
5. Draw foreground image

```c++
// draw background image
backgroundImg.draw(0, 0);

// draw foreground image, see image 2 through mask of 1
foregroundImg.draw(0, 0);
```

### Mask from camera pixels

If we are setting _all_ the pixels in our alpha mask, we have to do things a little differently (in the previous example we were actually only drawing the mask where our mouse was).

__Concept__
- we will use a thresholded ofVideoGrabber to set an aplha Mask
- we will apply the alpha mask to
    1. a foreground image
    2. the grabber texture itself
- the mask will apply transparent pixels from _dark pixels_ and opaque pixels from bright ones.

One major difference in this example than the previous one is that we technically do not need an FBO.
- We make our mask using this process -
- thresholded pixels -> thresholded texture -> apply texture to alpha channel of 1. an image, or 2. the grabber texture.

The other major difference is that we _need to set the version of the openGL renderer we are using_.  
- There is a way to do this without changing the GL version but its inefficient and lazy.
- We need to change the GL version to 3.2

in main.cpp

```c++
#include "ofMain.h"
#include "ofApp.h"

//================================================================
int main( ){

    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);
    settings.decorated = true;
    settings.setSize(1024, 768);
    settings.setPosition({0, 0});
    ofCreateWindow(settings);

	ofRunApp(new ofApp());
}
```
__We will use--__
- `ofVideoGrabber grabber` for a camera feed and to make our mask
- `ofPixels grayscalePixels` to hold out thresholded pixels
- `ofTexture grayscaleTexture` to draw our pixels into, this texture will be our mask.
- Two `ofImage`, one for a foreground and one for a background
- For this example, another `ofTexture` for our grabber copy.


1. load foreground and background image, also setup the grabber
2. create a black and white mask from the grabber by iterating through the grabber pixels and thresholding the brightness values.
3. load the grayscalePixels into the grayscaleTexture.
    - This grayscaleTexture will be our mask.
4. Apply mask as the alpha channel for foreground image
```c++
foreground.getTexture().setAlphaMask(grayscaleTex);
```
or, if the foreground it going to be the grabber copy (which is a texture)
```c++
grabberCopy.setAlphaMask(grayscaleTex);
```

5. Draw the background image, then draw the foreground
```c++
// draw background image
background.draw(width/2, height/2, width/2, height/2);
// draw foreground
foreground.draw(width/2, height/2, width/2, height/2);
```
