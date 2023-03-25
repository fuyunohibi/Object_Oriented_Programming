#include <iostream>
#include <string>

using namespace std;

class Text_base
{
protected:
    string text_;

public:
    Text_base(string text) : text_(text) {}

    virtual string get_text()
    {
        return text_;
    }
};

class Quoted_text : public Text_base
{
private:
    string opening_symbol_ = "\"";
    string closing_symbol_ = "\"";

public:
    Quoted_text(string text) : Text_base(text) {}

    string get_text() override
    {
        string new_text = opening_symbol_ + text_ + closing_symbol_;
        return new_text;
    }
};

class Crypted_text : public Text_base
{
private:
    string encrypted_text_;

public:
    Crypted_text(string text) : Text_base(text) {}

    string get_text() override
    {
        if (encrypted_text_.empty())
        {
            // Encrypt the text if it hasn't been encrypted yet
            encrypted_text_ = "";
            for (int i = 0; i < text_.length(); i++)
            {
                char c = text_[i];
                if (c >= 'a' && c <= 'z')
                {
                    encrypted_text_ += static_cast<char>('a' + 'z' - c);
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    encrypted_text_ += static_cast<char>('A' + 'Z' - c);
                }
                else
                {
                    encrypted_text_ += c;
                }
            }
        }
        return encrypted_text_;
    }
};

int main()
{
    string text1 = "Hello, World";
    Text_base *text = new Crypted_text(text1);
    cout << text->get_text() << endl;

    string text2 = "Quoted text";
    text = new Quoted_text(text2);
    cout << text->get_text() << endl;

    delete text;
    return 0;
}
