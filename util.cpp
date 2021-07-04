#include<fstream>
#include<string>
#include "util.h"
string  Util::convertToTime(long int input_seconds){
    long minutes = input_seconds/60;
    long hours = minutes/60;
    long seconds =  int(input_seconds%60);
    minutes = int(minutes%60);
    string result = to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
    return result;
}

//constructing string for progress bar
//50 bars is uniformly streched 0-100%
//every 2% is one bar (|)
string Util::getProgressBar(string percent){
    string result = "0%";
    int _size  = 50;
    //stof converts string into floating point number......
    int boundaries = (stof(percent)/100)*_size;
    for(int i=0;i<_size;i++){
        if(i<=boundaries){
            result+="|";
        }
        else{
            result+=" ";
        }
    }
    result += " "+percent.substr(0,5) + " /100%";
    return result;
}

//wrapper for creating streams
ifstream Util::getStream(string path) {
    ifstream stream(path);
    if(!stream){
        throw runtime_error("Non-existing PID");
        //PID= Process Identifiers
    }
    //returns input stream if PID exists for process....
    return stream;
}

