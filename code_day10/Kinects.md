About the Kinect.

- Kinect v1
    - model 1414
    - model 1473

- Kinect for Windows v1
    - designed for XBox or something

- Kinect v2 (or Kinect for Windows v2)
    - "newest version", using a different technique than the others

- [0 oo] is...
- an infrared projector
- an infrared camera
- an RGB camera
- Basically,
    - the IR projector sends out a pattern of IR dots. the IR camera "knows" what the pattern is and knows when it is distorted. Based on reading these distortions, it can determine how far the dots have been projected and thus, determine distances of objects form the sensor.
- But! The Kinect v2...
    - Uses a technique called Time-of-Flight depth sensing.
    - Time-of-Flight 3D depth sensors emit a very short infrared light pulse. The distance between a sensor and an object is measured based on the time difference between the emission of am IR burst and its return to the sensor, after being reflected by an object. Its more accurate and faster.
    - the v2 also has a higher resolution RGB camera

- Note about Registered Pixels
    - The IR camera and the RGB camera are not in the same location, so they do not have the same perspective.  In order to align the RGB pixels with the depth image, you have to do some funky math. Luckily, the v2 does this for us provides the alignment as Registered image.

We will be using a fork of the ofxKinectV2 addon. You can find it [here](https://github.com/ajbajb/ofxKinectV2) and [here](https://github.com/bakercp/ofxKinectV2)

This addon works specifically for the Kinect for Windows V2. If using a Kinect 1414 please use the ofxKinect addon and follow the instructions in the README.md.

Will this addon work on Windows? Doesn't seem like it. Instead use [ofxKinectForWindows2](https://github.com/elliotwoods/ofxKinectForWindows2).

- This addon only gives you access to the RGB camera, IR camera, depth pixels, and Registered pixels. From there you can easily generate a point cloud.  It will not give you skeleton tracking or hand tracking. This kind of functionality is available with some Windows frameworks. So... The easiest way to get skeleton tracking is to use a windows machine (until I find something else ;) ).

1. Clone the addon:
    - Open up a terminal and `cd` to your addons folder.
    ```
    git clone https://github.com/ajbajb/ofxKinectV2.git
    ```
2. In Project Generator, import the example included in the addon.
3. Plug in the Kinect and check if it shows up as a USB device in System Information.
    - About This Mac -> System Report... -> USB
    - Under USB 3.0 Bus, check that you have listed 'XBox NUI Sensor'
    - Kinect v2 _requires_ a USB 3 connection.  If your USB connection does not have a transfer speed that is at least as fast as USB 3 (5gbps), then you are out of luck (check System Information if you are unsure what type of USB port your computer carries).f
4. Run the example.








- create an image sequence `ffmpeg -i input.mp4 outputFolder/output-%04d.png`
