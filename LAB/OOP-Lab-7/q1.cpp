#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ========================Start::1.0========================

void substitute(string text, string word, string replace)
{
    string::size_type n = 0;
    while ((n = text.find(word, n)) != string::npos)
    {
        text.replace(n, word.length(), replace);
        n += replace.length();
    }
    cout << text << endl;
}

int main()
{
    string text1 = "abc python javapythonx";
    string text2 = "abcx yja helx yz01 23";


    substitute(text1, "python", "rust"); cout << endl;
    substitute(text1, " ", "rust"); cout << endl;
    substitute(text2, "python", "rust"); cout << endl;
    substitute(text2, "x y", "a b"); cout << endl;

    return 0;
}

// ========================End::1.1========================
