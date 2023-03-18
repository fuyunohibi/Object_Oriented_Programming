#include <iostream>
#include <string>
#include <vector>
#include <cstring> // for strlen, strcpy, etc.

using namespace std;

// ========================Start::1.2========================

char *c_style_substitute(const char *text, const char *word, const char *replace)
{
    // Determine the len
    int text_len = strlen(text);
    int word_len = strlen(word);
    int replace_len = strlen(replace);

    // Compute the len of new string
    int new_len = text_len;
    int count = 0;
    const char *p = text;
    while ((p = strstr(p, word)) != nullptr) // Find the next occurrence of word in text
    {
        count++;
        p += word_len;
        new_len += (replace_len - word_len);
    }

    char *new_text = new char[new_len + 1]; // Add one for the null terminator
    new_text[new_len] = '\0';               // Set the null terminator at the end of the new string

    // Copy the original string to the new string, replacing occurrences of the word
    char *q = new_text;
    p = text;
    while (count > 0)
    {
        const char *r = strstr(p, word);
        int len = r - p;
        memcpy(q, p, len); // Copy the substring to the new string
        q += len;
        memcpy(q, replace, replace_len); // Copy the replacement string to the new string
        q += replace_len;
        p = r + word_len;
        count--;
    }
    strcpy(q, p); // Copy the rest of the original string to the new string

    return new_text;
}

int main()
{
    const char *text3 = "abc python javapythonx";
    const char *word = "python";
    const char *replace = "C++";

    char *new_text = c_style_substitute(text3, word, replace);
    cout << "Original text: " << text3 << endl;
    cout << "New text(C-Style): " << new_text << endl;
    delete[] new_text;

    return 0;
}

// ========================End::1.2========================