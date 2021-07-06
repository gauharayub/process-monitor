# Process-Monitor-Linux

Install ncurses library using following commands on linux terminal:

### STEPS TO BUILD AND RUN THE PROJECT

1. Install dependencies

    1.1 install cmake using snap/apt or from offical website

    [CMake Downloads](https://cmake.org/download/)

    1.2 Install ncurses library
    
    `sudo apt-get install libncurses5-dev libncursesw5-dev`

2. Commands to build and run project locally (in Linux):

    `cd src`

    `cmake -S . -B ./out/build`

    `cd ../out/build`
    
    `make`

    `./PROCESS_MONITOR`


### PROJECT DEMO

![Process Monitor Linux](/demo-images/process-monitor.png)

