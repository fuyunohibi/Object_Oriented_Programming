
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;
using std::ostream;
using std::string;
using std::vector;

struct Point
{
    double x;
    double y;
};

class Poly_line
{
public:
    Poly_line() = default;
    Poly_line(const Poly_line &other)
    {
        for (auto p : other.points)
        {
            Point new_p = {p.x, p.y};
            this->points.push_back(new_p);
        }
    }
    ~Poly_line()
    {
        this->points.clear();
    }
    vector<Point> points;

    vector<Point> get_points()
    {
        return this->points;
    }
};

void print(Poly_line lines, std::ostream &out = std::cout)
{
    cout << "<polyline fill='none' stroke='black' points='";
    for (auto p : lines.get_points())
    {
        cout << p.x << "," << p.y << " ";
    }
    cout << "'/>" << endl;
}

void gen_svg(Poly_line lines, std::ostream &out_ = std::cout)
{
    vector<string> svg_head = {
        "<svg width='200' height='200' xmlns='http://www.w3.org/2000/svg'>",
    };
    vector<string> svg_tail = {
        "</svg>"};
    std::ofstream out("svg.html");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    for (auto s : svg_head)
    {
        cout << s << endl;
    }
    print(lines);
    for (auto s : svg_tail)
    {
        cout << s << endl;
    }
}

int main()
{

    Poly_line lines;
    Point p1 = {10, 10};
    Point p2 = {190, 20};
    Point p3 = {180, 180};
    Point p4 = {80, 110};
    Point p5 = {10, 10};
    lines.points.push_back(p1);
    lines.points.push_back(p2);
    lines.points.push_back(p3);
    lines.points.push_back(p4);
    lines.points.push_back(p5);
    gen_svg(lines);

    return 0;
}