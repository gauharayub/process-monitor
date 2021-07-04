# Process-Monitor-Linux

Install ncurses library using following commands on linux terminal:

### STEPS TO BUILD AND RUN THE PROJECT

1. Install dependencies

`sudo apt-get install libncurses5-dev libncursesw5-dev`

2. Commands to compile and run project locally:

`cd src`

`g++ main.cpp ProcessParser.cpp util.cpp -lncurses`

` ./a.out `


### PROJECT DEMO

![Process Monitor Linux](/demo-images/process-monitor.png)

