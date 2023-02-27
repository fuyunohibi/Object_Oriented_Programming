#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>
#include <list>
#include <random>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::vector;
using std::sort;

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

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist{-1, 1};

    const int center_x1 = 220;
    const int center_y1 = 240;
    const int center_x2 = 420;
    const int center_y2 = 240;

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    std::ofstream out("testsvg.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    print_words(cout, head_tag);
    for (int i = 1; i <= N; i++)
    {
        double x = map(dist(rng), -1, 1, 0, 640);
        
        double y = map(dist(rng), -1, 1, 0, 480);
        
        // find that point is in the circle that both intersect or not
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
    print_words(cout, tail_tag);
    
}