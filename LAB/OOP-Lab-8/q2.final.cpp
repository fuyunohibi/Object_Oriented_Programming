#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <sstream>

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

    virtual ostream &print(ostream &os) const
    {
        return os << "[" << name << ": Hero]";
    }
};

class Petch : public Hero
{
public: 
    Petch(const string &name = "Nameless Petch") : Hero(name) {}
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

    ostream &print(ostream &os) const override
    {
        return os << "[" << name << ": Warrior]";
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

    ostream &print(ostream &os) const override
    {
        return os << "[" << name << ": Fighter]";
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

    ostream &print(ostream &os) const override
    {
        return os << "[" << name << ": Mage]";
    }
};

int main()
{   
    Warrior warrior1("Cecil");
    Fighter fighter1;
    Mage mage1("Vivi");
    const Hero &hero1 = warrior1;
    const Hero &hero2 = fighter1;
    const Hero &hero3 = mage1;

    // "Cecil"
    auto name = hero1.get_name();
    // "Nameless Fighter"
    name = hero2.get_name();
    // "Vivi"
    name = hero3.get_name();

    // ...
    // "I'm Cecil, I will save the world."
    std::cout << hero1.greetings() << std::endl;
    // "I'm Nameless Fighter, I will crush the evil."
    std::cout << hero2.greetings() << std::endl;
    // "I'm Vivi, I can cook with fire magic."
    std::cout << hero3.greetings() << std::endl;

    const Hero hero4 = warrior1;
    // "I'm the hero with no name."
    std::cout << hero4.greetings() << std::endl;

    istringstream iss("W Cecil F Ryu M Vivi");
    vector<unique_ptr<Hero>> heroes;
    char hero_type;
    string hero_name;

    while (iss >> hero_type >> hero_name)
    {
        unique_ptr<Hero> hero_ptr;

        switch (hero_type)
        {
        case 'W':
            hero_ptr = make_unique<Warrior>(hero_name);
            break;
        case 'F':
            hero_ptr = make_unique<Fighter>(hero_name);
            break;
        case 'M':
            hero_ptr = make_unique<Mage>(hero_name);
            break;
        default:
            hero_ptr = make_unique<Hero>(hero_name);
            break;
        }

        heroes.push_back(move(hero_ptr));
    }

    // [Cecil: Warrior]
    heroes[0]->print(cout) << endl;
    // [Ryu: Fighter]
    heroes[1]->print(cout) << endl;
    // [Vivi: Mage]
    heroes[2]->print(cout) << endl;

    return 0;
}
