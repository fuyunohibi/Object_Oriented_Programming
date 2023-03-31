#include <iostream>
#include <memory>
#include <vector>

#include "../header/html_for_q3.hpp"

class Shape
{
public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<nse::html::node> draw() const = 0;
};

class Circle : public Shape
{
public:
    std::unique_ptr<nse::html::node> draw() const override
    {
        auto circle = std::make_unique<nse::html::element>("circle");
        circle->set_attribute("cx", "50");
        circle->set_attribute("cy", "50");
        circle->set_attribute("r", "40");
        return circle;
    }
};

class Rect : public Shape
{
public:
    std::unique_ptr<nse::html::node> draw() const override
    {
        auto rect = std::make_unique<nse::html::element>("rect");
        rect->set_attribute("x", "10");
        rect->set_attribute("y", "10");
        rect->set_attribute("width", "80");
        rect->set_attribute("height", "80");
        return rect;
    }
};

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>());
    shapes.emplace_back(std::make_unique<Rect>());

    nse::html::element svg("svg");
    svg.set_attribute("width", "100");
    svg.set_attribute("height", "100");

    for (const auto &shape : shapes)
    {
        auto shape_element = shape->draw();
        svg.add_child(std::move(shape_element));
    }

    std::cout << svg.to_string() << '\n';

    return 0;
}
