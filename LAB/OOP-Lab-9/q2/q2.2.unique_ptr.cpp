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

    /* LESSON: Smart Pointer - unique_ptr */

    // std::unique_ptr | smart pointer, automatically deletes the object when it's no longer needed.
    // std::make_unique | constructs the object directly inside the vector using the .emplaceback()
string generate_hero_table(const vector<unique_ptr<Hero>> &heroes)
{
    //TODO: ostringstream oss - stores the output in a string stream before returning it | use oss.str() to get the string
    ostringstream oss;

    oss << "<table>\n";

    int counter = 0;
    for (const auto &hero : heroes)
    {

        if(counter == 1) 
        {
            oss << "  <tr>\n"
                << "    <td>" << hero->get_name() << "</td>"
                << "\n    <td>" << hero->greetings() << "</td>\n"
                << "  </tr>\n";
        } 
        else 
        {
            oss << "  <tr> <td>" << hero->get_name() << "</td> "
                << "<td>" << hero->greetings() << "</td> </tr>\n";
        }
        counter++;
        
    }

    oss << "</table>\n";

    return oss.str();
}


int main()
{
    
    Warrior Ironman("IronMan");
    Fighter Spiderman("Spiderman");
    Mage Thor("Thor");

    /* LESSON: constructs the object directly inside the vector using the .emplaceback() 
    instead of .pushback() */

    // SLOWER: push_back, creates a temporary object outside of the vector's memory and then copying or moving it into the vector
    // FASTER: emplace_back, constructs the object directly inside the vector

    vector<unique_ptr<Hero>> heroes;
    heroes.emplace_back(make_unique<Warrior>(Ironman));
    heroes.emplace_back(make_unique<Fighter>(Spiderman));
    heroes.emplace_back(make_unique<Mage>(Thor));

    string html_table = generate_hero_table(heroes);
    cout << html_table;
}