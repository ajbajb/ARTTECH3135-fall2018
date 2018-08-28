## Interactive Art / Creative Code, ARTTECH 3135

Semester, Year
:   Fall, 2018

Meeting Times
:   Wednesdays 9am-4pm

Meeting Location
:   MacLean 401

Instructor
:   Adam Bach

Teaching Assistant
:   Doug Rosman

Class Forum
:   [https://ats.community/c/courses/arttech-3135](https://ats.community/c/courses/arttech-3135)

Class Website
:   [https://ajbajb.github.io/ARTTECH3135-fall2018/](https://ajbajb.github.io/ARTTECH3135-fall2018/)

Code Examples
:   [https://github.com/ajbajb/ARTTECH3135-fall2018/](https://github.com/ajbajb/ARTTECH3135-fall2018/)

### Course Description
This studio course investigates the creative possibilities in programming, from interactivity to information visualization. Students explore interactive narratives and games, software art, simulations and emergent behaviors, and other code-based forms. Lectures, discussions, and demonstrations provide a conceptual, aesthetic and technical foundation in programming as a creative practice.

### Course Goals

__Key goals include:__

- Intermediate working knowledge of creative coding tools and techniques.
- Working knowledge of the landscape of contemporary open source coding tools.
- Working knowledge of coding tools such as Git, Xcode, Terminal, etc.
- Working knowledge of contemporary artists and groups that shape the fields of interactive art and creative code.

### Course Values
- Sharing / Open
    - Documentation
    - [DIWO](http://furtherfield.org/projects/diwo-do-it-others-resource)
    - Publish
    - [Cult of Done Manifesto](https://medium.com/@bre/the-cult-of-done-manifesto-724ca1c2ff13)

### Methodology
Students will engage in individual in-lab and home assignments, class presentations, lectures, discussions, assigned readings, group and individual projects and desk critiques.  Visiting artists / faculty may enhance the experience and offer additional perspectives.

### Assignments
The course may include workshops and several projects, relevant technical and theoretical reading, written online responses, technical research and outings.

### Class Text

- [ofBook](http://openframeworks.cc/ofBook/chapters/foreword.html)

### Reading and other Resources
Posted on the course website.

### Materials
Provided by the student as needed.

### Attendance
1. Students are best served by attending all classes.
2. Missing three classes will result in a class failure.  This is strictly enforced.
3. Six or more unexcused late arrivals or early departures will result in class failure.

_Tip: If you are going to be absent, late to class, or need to depart early, please contact me BEFORE class starts.  This is so I can make sure you have what you need to succeed!_

### Wait Lists
Students wait-listed for classes will be admitted on a space available basis determined by instructor’s discretion (in consultation with the department chair).

### Grading Procedure/Criteria
- Grades are credit / no-credit for this course. Credit is based on several factors: 30% participation (discussions, critiques, etc), 70% projects / assignments.
- All assignments must be completed and submitted as instructed.
- Incomplete grades will not be offered.

### Writing Assistance
[Writing Center](http://www.saic.edu/academics/academicresources/writingcenter/)

### Special Needs
[Disability and Learning Resource Center](http://www.saic.edu/lifeatsaic/wellnesscenter/disabilityandlearningresourcecenter/)
___
### Course Schedule

#### Session 00 -- Aug 29 2018
- Introduction to Creative Code
- Survey of some Art
    - Here is an incomplete [list]().        
- Survey of some coding tools & frameworks.
    - Visual Programming Language
        - [Max/MSP](https://cycling74.com/products/max/)
        - [Grasshopper](http://www.grasshopper3d.com/)
        - [Touch Designer](https://www.derivative.ca)
        - [Pd](https://puredata.info/)
        - [Isadora](https://troikatronix.com/)
    - Non-Visual Programming
        - [Processing](https://processing.org/)
            - Getting started: [http://hello.processing.org/](http://hello.processing.org/)
            - Variations
                - Javascript: [https://p5js.org/](https://p5js.org/)
                - Android: [http://android.processing.org/](http://android.processing.org/)
                - Python: [http://py.processing.org/](http://py.processing.org/)
        - [libCinder](https://libcinder.org/)
        - [openFrameworks](http://openFrameworks.cc)
    - Hybrid
        - [Unity3d](https://unity3d.com/)
        - [Unreal Engine](https://www.unrealengine.com)
        - [vvvv](https://vvvv.org/)
    - [Awesome Creative Coding list](https://github.com/terkelg/awesome-creative-coding#visual-programming-languages)
- This class will focus on openFrameworks (C++).    
- Introduction to class tools
    - X-Code
        - get x-code from the app store (this may take awhile)
        - what is an IDE?
        - alternative IDEs
            - QT-Creator
            - Visual Studio
    - openFrameworks
        - get it at openFrameworks.cc
        - file structure of an oF project
            - Where does the folder go?
            - Where do projects go?
            -What else is in the oF folder?
        - What is an addon?
        - Project Generator
    - a comment about code comments
        - (e.g. why? [this](http://qz.com/726338/the-code-that-took-america-to-the-moon-was-just-published-to-github-and-its-like-a-1960s-time-capsule/))
    - Common Errors
        - What is your compiler target?
        - Did you accidentally add a break point?
        - How do I start over? Answer: Project generator
    - Creative Code Meet-up and TA hours!
- ###### Lesson 00 -- Introduction to openFrameworks
    - Simple line drawings
    - The Objective
        - Create an oF project
        - learn x/y coordinate system
        - get acquainted with c++ syntax
            - variables
            - data types
            - whats a function
        - draw simple patterns or shapes
            - "Painters" metaphor
        - Drawing Shapes
            - `ofDrawRectangle(...)`
            - `ofDrawLine(...)`
        - Colors
            - `ofSetColor(...)`
        - Fill vs. Stroke
            - `ofSetFill()` and `ofNoFill()`
        - Background
            - `ofBackground(...)`
            -  `ofBackgroundGradient(...)`
        - fun [reference and inspiration](http://recodeproject.com/)
        -algorithmic instructions

###### Readings
- [What is Code?](https://www.bloomberg.com/graphics/2015-paul-ford-what-is-code/)
- [Computer Art History](http://www.vam.ac.uk/content/articles/a/computer-art-history/)
- ofBook [Forward](https://openframeworks.cc/ofBook/chapters/of_philosophy.html)
- ofBook [Philosophy](https://openframeworks.cc/ofBook/chapters/of_philosophy.html)
- ofBook [C++ Language Basics](https://openframeworks.cc/ofBook/chapters/cplusplus_basics.html)

###### Watch
- at least one (1) of these [videos](https://vimeo.com/eyeofestival/videos)

###### Homework
- Sol LeWitt Renderings
___

#### Session 01 -- Sept 5 2018
- Review assignment 1.
- Discuss readings.
##### Lesson 01 -- Anatomy of a Program & ofColor & Shapes
- learn about the update() and draw() loop
- learn how to control color  
- learn how to control the flow of your program
    - parts of an oF application
        - setup(), update(), draw(), main().
    - C++ --
        - flow control & iteration
            - `for(...)`, `if`, `else`, `else if`.
        - Variables and Types
            - Identifiers, reserved keywords
            - Saving information!
            - Foundational / POD
                - `bool`
                - `int`
                - `float`
            - Other
                - `std::string`
                - `auto`
        - Operators
            - Math `+`, `-`, `*`, `/`, `%`
            - Assignment `=` (tell) vs. identity `==` (ask)
            - Order of Operation
              - Prioritize with Parenthesis!
        - Program Flow
            - Typically execute statements, top to bottom, left to right.
            - Single statements vs. compound statements `{ ... }`
            - Flow Control
                - Selection
                    - `if` / `else if` / `else`
                    - `switch`
                - Iteration / Repetition
                    - `while (...) { ... };`
                    - Iterate while a condition is true.
                    - `do { ... } while (...);`
                    - Evaluate condition after contents of loop are executed.
                    - `for (...) { ... };`
                    - Iterate a fixed number of times.
                    - Range `for` loop
                    - `for(auto x : in_collection){...}`
                - Jumping
                  - `break`
                  - `continue`
                  - `goto` (avoid)
        - Output
            - Standard output streams
                - `std::cout`
                - `std::cerr`
            - oF output
                - `ofLogXXX()`
                    - Finer-grained control of output.
                - `ofSetLogLevel(...)`
    - oF Topics
        - `ofColor`
        - `ofPushStyle()`
        - `ofPopStyle()`
        - `ofPolyline`
        - `ofPath`
        - `ofFill`
- Color References
    - [Interaction of Colors, by Josef Albers](http://www.g-e-s-t-a-l-t.org/MEDIA/PDF/Interaction-of-Color.pdf)
    - [Manoloide](https://www.patreon.com/posts/colors-colors-18611429)

###### Readings
- ofBook- Intro to Graphics

###### Homework
- Digital Drawing Portraits
___

#### Session 02 -- Sept 12 2018
- Show and discuss homework
- Review `if` statements & `for` loops
- C++ Syntax
  - Reminder that tutorials are available ...
    - https://www.lynda.com/C-tutorials/Up-Running-C/167922-2.html
    - https://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html

##### Lesson 02 -- Digital paintbrush & simple interaction
- of Topics
    - interaction with mouse & keyboard
        - `ofGetMousePressed()`
        - `ofGetKeyPressed()`
    - `%`, `ofRandom(...)`, `ofSeedRandom(...)`
    - fading background with a transparent `ofDrawRectangle(...)`
    - `ofSetBackgroundAuto`
    - `ofPushMatrix()`
    - `ofPopMatrix()`
    - `ofPixels`
      - Quick review of binary numbers ...
      - How are pixels / color represented?
      - Looping
        - access a 1d array from a 2d for loop
        - y * w + x
    - `ofImage`
        - Manually setting colors.
        - Saving and loading images.
        - Raw vs. encoded.
        - Importance of encoding for "glitch".
    - ofPixels vs. ofTexture vs. ofImage
    - `ofGui`

###### Readings
- ofBook Animation

###### Homework
- Interactive Drawing Application
___

### Session 03 -- Sept 19 2018
##### Lesson 03 -- Animation
- oF Topics
    - periodic Signals
        - `ofNoise(),
        - sin()
        - cos()`
    - controlling color with sin()
    - counters
    - time
        `ofGetElapsedTimef()`
    - Scaling numbers
        - `ofMap(...)`
        - `ofLerp(...)`
        - `ofNormalize(...)`

- Activity
    - Pong game
    - generative line drawing with periodic signal
        - [reference](http://junkiyoshi.com/insta20180602/)
        - [reference](https://openframeworks.cc/ofBook/chapters/lines.html)

- ###### Readings
    - ofBook Sound
    - ofBook [std::map](https://openframeworks.cc/ofBook/chapters/stl_map.html)
    - ofBook [std::vector](https://openframeworks.cc/ofBook/chapters/stl_vector.html)

- ###### Homework
    - Create an Animated scene or game
___

### Session 04 -- Sept 26
##### Lesson 04 -- Animation cont. collections, ofSoundPlayer
- C++
 - `std::vector`, `std::map`, collections/containers, classes
 - working with [std::map](https://openframeworks.cc/ofBook/chapters/stl_map.html)
 - and [std::vector](https://openframeworks.cc/ofBook/chapters/stl_vector.html)
 - Arrays are collections of variables.
     - In C++ we usually use a `std::vector` to hold a collection of variables.
     - We must define the contents of the `std::vector` using a template argument like `std::vector<int>` for a collection of integers.
- oF Topics
    - `ofSoundPlayer`
        - check out [BBC sound archive](http://bbcsfx.acropolis.org.uk/)
    - `ofTrueTypeFont` for typography.
    - `ofGui`


- Back to C++
    - Object Oriented Programming.  
    - OOP vs Structured Programming
        - C++ is often described as C + object oriented code.
        - Structured → top down approach
        - OOP → create models problem
        - Why OOP?
            - Duplicate code can be confusing and lead to bug if it is modified in the future. You will always forget something!
            - Modeling the world using objects can often be more intuitive, better differentiating between form and function.
        - Classes
            - Classes are user defined data structures.
            - Classes are reusable between programs.
            - Classes are a way to aggregate or model form (attributes) and function (methods) into reusable units.
            - Classes are often used to easily represent multiples of a complex object.
            - Classes are "extensible" through inheritance.
            - An class "instance" is an independent "instantiated" variable form of a class.
            - In the same way that an `int` is a variable type and it is instantiated by calling `int i = 0;`, a class variable type like `Ball ball1;`  Now the `ball1` variable is its own "instance" that can be manipulated.  Other "instances" e.g. `Ball ball2;` will have the same capabilities as `ball1`, but it will behave independently by default.
            - Example: Writing a class definition for a ball.
                - What are the "attributes" (that can be represented as variables) of a ball?
                    - Position
                    - Velocity
                    - Color
                    - ...
    - Some inspiration
        - [John Whitney Matrix III](https://www.youtube.com/watch?v=ZrKgyY5aDvA)
        - [John Whitney Catalog](https://www.youtube.com/watch?v=TbV7loKp69s)

###### Readings
 - ofBook OOps!

###### Homework
- Create a custom class
- Perhaps find pattern or design in the 'real world' that you take inspiration from. For example, a pattern on stained glass, or these photographs by [Loredana Nemes](http://www.klv-artprojects.com/loredana-nemes-beyond/) or [bismuth crystals](https://en.wikipedia.org/wiki/Patterns_in_nature#/media/File:Wismut_Kristall_und_1cm3_Wuerfel.jpg). Don't try to mimic it closely! But use it as a guide.
___

#### Session 05 -- Oct 3 2018
- Share some Homework
- Review classes

##### Lesson 5 - Particle systems, 3D, Classes & Objects
- C++
 - Pointers `*`, References `&`, and memory.
 - functions and pass by value vs. pass by reference
- oF Topics
    - Particle System Examples
        - Replace ball variables with a Ball class.
        - Replace x / y / z variables with `ofPoint` (which is an alias for `ofVec3f` or in 0.10.0+ `glm::vec3`).
        - `ofPoint` is a "vector" of values, x, y, z and vector math can be performed in one line.
        - `ofPoint` is a class!
    - Particle systems in 3D!
        - Z-axis and handedness
            - (0,0) is now the center of the screen, with -z going into the screen, and y flipped.
            - `camera.setScale(1, -1, 1)`
        - ofEasyCam
        - ofMaterial
        - ofLight

    ###### Readings
     - [Nature of Code- Forces](https://natureofcode.com/book/chapter-2-forces/)

    ###### Homework
     - Create a particle system modeled from a natural phenomena
___

#### Session 06 -- Oct 10 2018
##### Basic Computer Vision
- Video FX
- ofVideoGrabber + webcam
    - example of [image distortion algorithm](http://junkiyoshi.com/insta20180505/)
- apply video to plane primitive as a texture
- [Slit Scan Imaging](https://makezine.com/2017/10/26/emulate-slit-scan-photography-for-beautifully-weird-images/)
    - [more Slit Scan](http://www.flong.com/texts/lists/slit_scan/)
- iterating through ofPixels
    - `y * width + x`

###### Readings
- ofBook Image Processing and Computer Vision
___

#### Session 07 -- Oct 17 2018
##### Mid-term lab day & crit
___

#### Session 08 -- Oct 24 2018
##### Computer Vision Cont.
- thresholding
- background subtraction/masking
- color differencing
- `ofGetBrightness()`
- `ofDist(...)`

- ###### Readings
    - Flong reading http://www.flong.com/texts/essays/essay_cvad/

- ###### Homework
    - Final Project Proposals and timeline
___

#### Session 09 -- Oct 31 2018
##### more Computer Vision
- Face finding/tracking
___

#### Session 10 -- Nov 7 2018
##### Sound Synthesis Class
- ofSoundBuffer
- Sound visualization
___

#### Session 11 -- Nov 14 2018
##### Class Lab
___

#### Session 12 -- Nov 28 2018
##### Class Lab Day
___

#### Session 13 -- Dec. 12 2018
##### Final Projects & Review
___
