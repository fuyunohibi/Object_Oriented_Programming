#include <iostream>
#include <memory>
#include <sstream>
#include <string>

class Shape
{
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual void print(std::ostream &os) const = 0;
};

class Circle : public Shape
{
public:
    Circle(double x = 0, double y = 0, double r = 0)
        : x_(x), y_(y), r_(r) {}

    double area() const override { return 3.14159 * r_ * r_; }

    void print(std::ostream &os) const override
    {
        os << "[Circle: (" << x_ << ", " << y_ << ", " << r_ << ")]";
    }

private:
    double x_, y_, r_;
};

class Rectangle : public Shape
{
public:
    Rectangle(double x = 0, double y = 0, double w = 0, double h = 0)
        : x_(x), y_(y), w_(w), h_(h) {}

    double area() const override { return w_ * h_; }

    void print(std::ostream &os) const override
    {
        os << "[Rectangle: (" << x_ << ", " << y_ << ", " << w_ << ", " << h_
           << ")]";
    }

private:
    double x_, y_, w_, h_;
};

int main()
{
    std::istringstream iss("C 50 50 15 R 40 40 20 20");

    std::unique_ptr<Shape> shape1 = nullptr, shape2 = nullptr;
    char shape_type;
    double x, y, r, w, h;

    while (iss >> shape_type)
    {
        switch (shape_type)
        {
        case 'C':
            iss >> x >> y >> r;
            shape1 = std::make_unique<Circle>(x, y, r);
            break;
        case 'R':
            iss >> x >> y >> w >> h;
            if (!shape1)
                shape1 = std::make_unique<Rectangle>(x, y, w, h);
            else
                shape2 = std::make_unique<Rectangle>(x, y, w, h);
            break;
        default:
            std::cerr << "Unknown shape type: " << shape_type << std::endl;
            return 1;
        }
    }

    // [Circle: (50, 50, 15)]
    if (shape1)
    {
        shape1->print(std::cout);
        std::cout << std::endl;
    }

    // [Rectangle: (40, 40, 20, 20)]
    if (shape2)
    {
        shape2->print(std::cout);
        std::cout << std::endl;
    }

    return 0;
}
