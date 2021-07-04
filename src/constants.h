#pragma once
#include <string>
using namespace std;

enum CPUStates{
    S_USER = 1,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

class Path{
public:
    static string basePath(){
        //proc is virtual file system created on the fly when system reboots...
        //this directory contains system files containing information
        // about running processes...
        return "/proc/";
    }

    //all files below are under /proc/ directory......
    static string cmdPath(){
        //file shows parameters passed to kernel at the time of boot.....
        return "/cmdline";
    }
    static string statusPath(){
        //each running process has its own status file containing information about
        //that particular process....
        return "/status";
    }
    static string statPath(){
        //this file contain information about number of running processes and cpu usage....
        return "stat";
    }
    static string upTimePath(){
        //This file contains information detailing how long
        // the system has been on since its last restart....
        return "uptime";
    }
    static string meminfoPath(){
        //this file constain information about current memory usage and status....
        return "meminfo";
    }
    static string versionPath(){
        //information about version of operating system...
        return "version";
    }

};

