#include "q3_main.hpp"

using namespace std;

int main(){

    vector<string> head_tag{
        "<body>",
        "<svg width='500' height='500' xmlns='http://www.w3.org/2000/svg'>>",
        "<rect width='100%' height='100%' fill='#EEEEEE' />",
        "<circle cx='250' cy='250' r='250' stroke='black' stroke-width='2' fill='none' />",
        "<circle cx='250' cy='250' r='10' fill='#00FFFF' />",    
    };

    vector<string> tail_tag{
        "</svg>",
        "</body>",
    };

    int N;
    cout << "Enter the N value: ";
    cin >> N;

    mt19937 rng;
    rng.seed(random_device()());
    uniform_real_distribution<double> dist{-1, 1};

    ofstream out("svg_hw2.html");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    double center_x = 250;
    double center_y = 250;

    SVG::print_words(cout, head_tag);
    for (int i = 0; i < N; i++){
        double distance;
        double cx;
        double cy;
        cx = SVG::map(dist(rng), -1, 1, 0, 500);
        cy = SVG::map(dist(rng), -1, 1, 0, 500);
        distance = sqrt(pow(cx - center_x, 2) + pow(cy - center_y, 2));
        while (distance > 250){
            cx = SVG::map(dist(rng), -1, 1, 0, 500);
            cy = SVG::map(dist(rng), -1, 1, 0, 500);
            distance = sqrt(pow(cx - center_x, 2) + pow(cy - center_y, 2));
        }
        cout << "<circle cx='" << cx << "' cy='" << cy << "' r='10' fill='" + SVG::hex_random_colour() + "' />" << endl;
    }

    SVG::print_words(cout, tail_tag);
    return 0;
}