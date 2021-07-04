#include <iostream>
#include "Sysinfo.h"
#include "ProcessParser.h"
#include "Process.h"
#include "ProcessContainer.h"
#include <curses.h>
using namespace std;

//ncurses library will be used to display info on the terminal.....
//ncurses is a dedicated API for writing terminal-independent text outputs.
//It refreshes the relevant data every second.
//ncurses also creates percentage bars and separate windows within the terminal.
char* getCString(string s) {
    int len = s.length();
    char *cstring  = new char[len+1];
    strcpy(cstring,s.c_str());
    return cstring;
}

void writeSysInfoToConsole(SysInfo sys, WINDOW* sys_win) {
    sys.setAttributes();
    mvwprintw(sys_win,2,2,getCString(( "OS: " + sys.getOsName())));
    mvwprintw(sys_win,3,2,getCString(( "Kernel version: " + sys.getKernelVersion())));
    mvwprintw(sys_win,4,2,getCString( "CPU: "));
    wattron(sys_win,COLOR_PAIR(1));
    wprintw(sys_win,getCString(Util::getProgressBar(sys.getCpuPercent())));
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,5,2,getCString(( "Other cores:")));
    wattron(sys_win,COLOR_PAIR(1));
    std::vector<std::string> val = sys.getCoresStats();
    for (int i = 0; i < val.size(); i++) {
        mvwprintw(sys_win,(6+i),2,getCString(val[i]));
    }
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,10,2,getCString(( "Memory: ")));
    wattron(sys_win,COLOR_PAIR(1));
    wprintw(sys_win,getCString(Util::getProgressBar(sys.getMemPercent())));
    wattroff(sys_win,COLOR_PAIR(1));
    mvwprintw(sys_win,11,2,getCString(( "Total Processes:" + sys.getTotalProc())));
    mvwprintw(sys_win,12,2,getCString(( "Running Processes:" + sys.getRunningProc())));
    mvwprintw(sys_win,13,2,getCString(( "Up Time: " + Util::convertToTime(sys.getUpTime()))));
}

// This function prints the first 10 processes from the host machine,
// which are stored in a string vector.
// They are distributed across 10 rows in a dedicated window.
// Every invocation of the function refreshes the process list and prints refreshed data.

void getProcessListToConsole(ProcessContainer procs,WINDOW* win) {
    procs.refreshList();
    wattron(win,COLOR_PAIR(2));
    mvwprintw(win,1,2,"PID:");
    mvwprintw(win,1,9,"User:");
    mvwprintw(win,1,16,"CPU[%]:");
    mvwprintw(win,1,26,"RAM[MB]:");
    mvwprintw(win,1,35,"Uptime:");
    mvwprintw(win,1,44,"CMD:");
    wattroff(win, COLOR_PAIR(2));

    vector<std::string> processes = procs.getList();

    for(int i = 0; i < 10; i++) {
        mvwprintw(win,2 +i,2,getCString(processes[i]));
    }
}

//The binding function for consistent display of data via ncurses is the printMain()function.
// This function accepts two parameters: a SysInfo object and a ProcessContainer.
//The function initializes the ncurses screen, separate windows, and a coloring scheme.
void printMain(SysInfo sys,ProcessContainer procs) {
    initscr(); // start curses mode
    noecho(); // not printing input values
    cbreak(); // Terminating on classic ctrl + c
    start_color(); // Enabling color change of text
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax); // getting size of window measured in lines and columns(column one char length)
    WINDOW *sys_win = newwin(17,xMax-1,0,0);
    WINDOW *proc_win = newwin(15,xMax-1,18,0);

    init_pair(1,COLOR_BLUE,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);

    while (1) {
        box(sys_win,0,0);
        box (proc_win,0,0);
        writeSysInfoToConsole(sys,sys_win);
        getProcessListToConsole(procs,proc_win);
        wrefresh(sys_win);
        wrefresh(proc_win);
        refresh();
        sleep(1);
    }
    endwin();
}



int main() {

    //Object which contains list of current processes, Container for Process Class
    ProcessContainer procs;

    // Object which contains relevant methods and attributes regarding system details
    SysInfo sys;
    printMain(sys,procs);

    return 0;
}