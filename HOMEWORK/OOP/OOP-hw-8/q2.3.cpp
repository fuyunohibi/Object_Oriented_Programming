#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Text_base
{
protected:
    const string text_;

public:
    Text_base(string text) : text_(text) {}

    virtual string get_text() const
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

    virtual string get_text() const override
    {
        if (text_ptr_)
        {
            return text_ptr_->get_text();
        }
        else
        {
            return Text_base::get_text();
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
    const string opening_symbol_;
    const string closing_symbol_;

public:
    Quoted_text(string text, string opening_symbol, string closing_symbol)
        : Decorated_text(text), opening_symbol_(opening_symbol), closing_symbol_(closing_symbol) {}

    virtual string get_text() const override
    {
        return opening_symbol_ + Decorated_text::get_text() + closing_symbol_;
    }
};

class Crypted_text : public Decorated_text
{
public:
    Crypted_text(string text) : Decorated_text(text) {}

    virtual string get_text() const override
    {
        string decrypted_text = Decorated_text::get_text();
        for (int i = 0; i < decrypted_text.length(); i++)
        {
            if (decrypted_text[i] >= 'a' && decrypted_text[i] <= 'z')
            {
                decrypted_text[i] = static_cast<char>('a' + 'z' - decrypted_text[i]);
            }
            else if (decrypted_text[i] >= 'A' && decrypted_text[i] <= 'Z')
            {
                decrypted_text[i] = static_cast<char>('A' + 'Z' - decrypted_text[i]);
            }
        }
        return decrypted_text;
    }
};

class Text
{
private:
    Text_base *text_;

public:
    Text(string text) : text_(new Text_base(text)) {}
    Text(string text, string opening_symbol, string closing_symbol) : text_(new Quoted_text(text, opening_symbol, closing_symbol)) {}
    Text(string text, string opening_symbol) : text_(new Quoted_text(text, opening_symbol, opening_symbol)) {}
    Text(Text_base *text) : text_(text) {}
    Text(Crypted_text text) : text_(new Decorated_text(text)) {}

    string get_text() const
    {
        return text_->get_text();
    }
};

int main()
{
    vector<Text> words{
        Text("C++", "<i>", "</i>"),   // Quoted_text
        Text(new Crypted_text("Zidane")), // Crypted_text
        Text("Rust", "*"),            // Quoted_text
        Text("Python", "[[", "]]"),   // Quoted_text
        Text(new Text_base("Vivi"))   // Text_base
    };

    for (const auto &w : words)
    {
        cout << w.get_text() << endl;
        ;
    }
}