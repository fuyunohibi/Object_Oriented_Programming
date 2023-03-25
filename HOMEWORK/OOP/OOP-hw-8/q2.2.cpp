#include <iostream>
#include <string>

using namespace std;

class Text_base
{
protected:
    string text_;

public:
    Text_base(string text)
    {
        this->text_ = text;
    }

    virtual string text()
    {
        return text_;
    }
};

class Decorated_text : public Text_base
{
private:
    Text_base *text_ptr_;

public:
    Decorated_text(string text) : Text_base(text), text_ptr_(nullptr) {}
    virtual string text() override
    {
        if (text_ptr_)
        {
            return text_ptr_->text();
        }
        else
        {
            return Text_base::text();
        }
    }
    virtual void set_text(Text_base *text)
    {
        text_ptr_ = text;
    }
};

class Quoted_text : public Decorated_text
{
private:
    string opening_symbol_;
    string closing_symbol_;

public:
    Quoted_text(string text, string opening_symbol, string closing_symbol)
        : Decorated_text(text), opening_symbol_(opening_symbol), closing_symbol_(closing_symbol) {}

    virtual string text() override
    {
        return opening_symbol_ + Decorated_text::text() + closing_symbol_;
    }
};

class Crypted_text : public Decorated_text
{
public:
    Crypted_text(string text) : Decorated_text(text) {}

    virtual string text() override
    {
        string encrypted_text = Decorated_text::text();
        for (int i = 0; i < encrypted_text.length(); i++)
        {
            if (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z')
            {
                encrypted_text[i] = static_cast<char>('a' + 'z' - encrypted_text[i]);
            }
            else if (encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z')
            {
                encrypted_text[i] = static_cast<char>('A' + 'Z' - encrypted_text[i]);
            }
        }
        return encrypted_text;
    }
};

int main()
{
    string text1 = "Hello, World";

    Decorated_text *text = new Crypted_text(text1);
    cout << text->text() << endl;

    string text2 = "Quoted text";
    text = new Quoted_text(text2, "*", "*");
    cout << text->text() << endl;

    Text_base *base_text = new Text_base("Another text");
    text->set_text(base_text);
    cout << text->text() << endl;

    text = new Quoted_text(text2, "<em>", "</em>");
    cout << text->text() << endl;

    text = new Quoted_text(text1, "++", "--");
    text->set_text(new Crypted_text(text1));
    cout << text->text() << endl;

    return 0;
}
