#pragma once
#include<fstream>
#include<string>
using namespace std;


class Util {

public:

    static string convertToTime(long int input_seconds);
    static string getProgressBar(string percent);
    static ifstream getStream(string path);

};
