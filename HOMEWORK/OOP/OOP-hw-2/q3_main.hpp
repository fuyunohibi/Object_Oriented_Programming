#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <istream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

class SVG{
    public:
        static void print_words(ostream& out, const vector<string>& words){
            for (const auto& w: words){
                out << w << endl;
            }
        }

    static double map(double x, double in_min, double in_max, double out_min, double out_max){
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }   

    static string hex_random_colour(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 255);
        string hex = "#";
        for (int i = 0; i < 3; i++){
            stringstream ss;
            ss << hex << dis(gen);
            string result(ss.str());
            if (result.size() == 1){
                result = "0" + result;
            }
            hex += result;
        }
        return hex;
    }     
};