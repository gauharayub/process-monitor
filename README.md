# Process-Monitor-Linux
This project displays information about CPU usage, RAM usage, Uptime of various process running on system using ncurses library.
The information about processes is extracted by extensive use of file handling.

Install ncurses library using following commands on linux terminal:

sudo apt-get install libncurses5-dev libncursesw5-dev

Commands to run project locally:

g++ main.cpp ProcessParser.cpp util.cpp -lncurses     (6*&nbsp);       //link ncurses library with other executables...

