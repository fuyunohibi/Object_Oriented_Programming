#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <sstream>
#include "../header/html_for_q2.hpp"

using namespace std;

class Hero
{
protected:
    string name;

public:
    Hero(const string &name = "Nameless Hero")
    {
        this->name = name;
    }

    virtual ~Hero() {}

    virtual string greetings() const
    {
        return "I'm the hero with no name.";
    }

    virtual string get_name() const
    {
        return name;
    }

    virtual void read(istream &is)
    {
        is >> name;
    }

    virtual html::tag print() const
    {
        return html::tr(html::td(name) + html::td(greetings()));
    }
};

class Warrior : public Hero
{
public:
    Warrior(const string &name = "Nameless Warrior") : Hero(name) {}

    string greetings() const override
    {
        return "I'm " + name + ", I will save the world.";
    }

    void read(istream &is) override
    {
        is >> name;
    }

    html::tag print() const override
    {
        return html::tr(html::td(name) + html::td(greetings()));
    }
};

class Fighter : public Hero
{
public:
    Fighter(const string &name = "Nameless Fighter") : Hero(name) {}

    string greetings() const override
    {
        return "I'm " + name + ", I will crush the evil.";
    }

    void read(istream &is) override
    {
        is >> name;
    }

    html::tag print() const override
    {
        return html::tr(html::td(name) + html::td(greetings()));
    }
};

class Mage : public Hero
{
public:
    Mage(const string &name = "Nameless Mage") : Hero(name) {}

    string greetings() const override
    {
        return "I'm " + name + ", I can cook with fire magic.";
    }

    void read(istream &is) override
    {
        is >> name;
    }

    html::tag print() const override
    {
        return html::tr(html::td(name) + html::td(greetings()));
    }
};

string generate_hero_table(const vector<unique_ptr<Hero>> &heroes)
{
    // TODO: ostringstream oss - stores the output in a string stream before returning it | use oss.str() to get the string
    ostringstream oss;

    oss << html::table();

    for (const auto &hero : heroes)
    {
        oss << hero->print();
    }

    oss << html::table_end();

    return oss.str();
}

int main()
{
    Warrior Ironman("IronMan");
    Fighter Spiderman("Spiderman");
    Mage Thor("Thor");

    vector<unique_ptr<Hero>> heroes;
    heroes.emplace_back(make_unique<Warrior>(Ironman));
    heroes.emplace_back(make_unique<Fighter>(Spiderman));
    heroes.emplace_back(make_unique<Mage>(Thor));

    string html_table = generate_hero_table(heroes);
    cout << html_table;
}
