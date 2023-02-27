#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <list>
#include <random>
#include <fstream>

using namespace std;

auto split(const string& s, char delim){
    vector<string> words;
    string word;
    for (const auto& c: s){
        if (c == delim){
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);
    return words;
}

void print_words(std::ostream& out, const vector<string>& words){
    for (const auto& w: words){
        out << w << endl;
    }
}

double map(double x, double in_min, double in_max, double out_min, double out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

string circle_tag(double cx, double cy, string fill){
    string tag = "<circle cx='" + std::to_string(cx) + "' cy='" + std::to_string(cy) + "' r='10' fill='" + fill + "' />";
    return tag;
}

int main(){
    string xy;

    vector<string> head_tag{
        "<body>",
        "<svg width='640' height='480' xmlns='http://www.w3.org/2000/svg'>",
        "<rect width='100%' height='100%' fill='#EEEEEE' />",
        "<circle cx='220' cy='240' r='200' stroke='black' stroke-width='2' fill='#80FF8080' />",
        "<circle cx='420' cy='240' r='200' stroke='black' stroke-width='2' fill='#8080FF80' />",    
    };

    vector<string> tail_tag{
        "</svg>",
        "</body>",
    };

    const int center_x1 = 220;
    const int center_y1 = 240;
    const int center_x2 = 420;
    const int center_y2 = 240;

    std::ifstream in("data.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    vector<string> words;
    while (getline(cin, xy)){
        words.push_back(xy);
    }

    std::cin.rdbuf(cinbuf);

    string ans;


    cout << "1. Print only left and right" << endl;
    cout << "2. Print only center" << endl;
    cout << "3. Print outside" << endl;
    cout << "4. Print all" << endl;
    cout << "What function do you want to use?: ";

    cin >> ans;

    std::ofstream out("testsvg.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    print_words(cout, head_tag);

    if(ans == "1"){
        for(const auto& w: words){
            auto xy = split(w, ' ');
            double x = std::stod(xy[0]);
            double y = std::stod(xy[1]);
            double d1 = sqrt(pow(x - center_x1, 2) + pow(y - center_y1, 2));
            double d2 = sqrt(pow(x - center_x2, 2) + pow(y - center_y2, 2));
            if (d1 <= 200 && !(d1 <= 200 && d2 <= 200)){
                cout << circle_tag(x, y, "#00FF00") << endl;
            }
            else if (d2 <= 200 && !(d1 <= 200 && d2 <= 200)){
                cout << circle_tag(x, y, "#0000FF") << endl;
            }
            else {
                continue;
            }
        }
    }
    else if(ans == "2"){
        for(const auto& w: words){
            auto xy = split(w, ' ');
            double x = std::stod(xy[0]);
            double y = std::stod(xy[1]);
            double d1 = sqrt(pow(x - center_x1, 2) + pow(y - center_y1, 2));
            double d2 = sqrt(pow(x - center_x2, 2) + pow(y - center_y2, 2));
            if (d1 <= 200 && d2 <= 200){
                cout << circle_tag(x, y, "#FF0000") << endl;
            }
            else{
                continue;
            }
        }
    }
    else if(ans == "3"){
        for(const auto& w: words){
            auto xy = split(w, ' ');
            double x = std::stod(xy[0]);
            double y = std::stod(xy[1]);
            double d1 = sqrt(pow(x - center_x1, 2) + pow(y - center_y1, 2));
            double d2 = sqrt(pow(x - center_x2, 2) + pow(y - center_y2, 2));
            if (d1 > 200 && d2 > 200){
                cout << circle_tag(x, y, "#000000") << endl;
            }
            else{
                continue;
            }
        }
    }
    else if(ans == "4"){
        for(const auto& w: words){
            auto xy = split(w, ' ');
            double x = std::stod(xy[0]);
            double y = std::stod(xy[1]);
            double d1 = sqrt(pow(x - center_x1, 2) + pow(y - center_y1, 2));
            double d2 = sqrt(pow(x - center_x2, 2) + pow(y - center_y2, 2));
            if (d1 <= 200 && d2 <= 200){
                cout << circle_tag(x, y, "#FF0000") << endl;
            }
            else if (d1 <= 200){
                cout << circle_tag(x, y, "#00FF00") << endl;
            }
            else if (d2 <= 200){
                cout << circle_tag(x, y, "#0000FF") << endl;
            }
            else {
                cout << circle_tag(x, y, "#000000") << endl;
            }
        }
    }
    else{
        cout << "Invalid input" << endl;
    }

    print_words(cout, tail_tag);

    return 0;
}