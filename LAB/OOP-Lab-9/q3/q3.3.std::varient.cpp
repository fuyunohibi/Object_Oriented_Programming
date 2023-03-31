#include <iostream>
#include <memory>
#include <vector>
#include <variant>
#include "../header/html_for_q3.hpp" // include nse::html library

class Circle
{
public:
    std::unique_ptr<nse::html::node> draw() const
    {
        auto circle = std::make_unique<nse::html::element>("circle");
        circle->set_attribute("cx", "50");
        circle->set_attribute("cy", "50");
        circle->set_attribute("r", "40");
        return circle;
    }
};

class Rect
{
public:
    std::unique_ptr<nse::html::node> draw() const
    {
        auto rect = std::make_unique<nse::html::element>("rect");
        rect->set_attribute("x", "10");
        rect->set_attribute("y", "10");
        rect->set_attribute("width", "80");
        rect->set_attribute("height", "80");
        return rect;
    }
};

using Shape = std::variant<Circle, Rect>;

int main()
{
    std::vector<Shape> shapes;
    shapes.emplace_back(Circle{});
    shapes.emplace_back(Rect{});

    nse::html::element svg("svg");
    svg.set_attribute("width", "100");
    svg.set_attribute("height", "100");

    for (const auto &shape : shapes)
    {
        std::visit([&svg](const auto &s)
                   {
            auto shape_element = s.draw();
            svg.add_child(std::move(shape_element)); },
                   shape);
    }

    std::cout << svg.to_string() << '\n';

    return 0;
}
