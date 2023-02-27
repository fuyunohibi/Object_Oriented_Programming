#include <vector>
#include <array>
#include <iostream>

using namespace std;

void to_upper(char s)
{
    s = int(s);
    if (s >= 97 && s <= 122)
    {
        s -= 32;
    }
    s = char(s);
    cout << s;
}

char *rev_dup(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    char *rev_str = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        rev_str[i] = s[len - i - 1];
    }

    rev_str[len] = '\0';

    return rev_str;
}

char *read_text(std::istream &input)
{
    int BUFFER_SIZE = 10; // initial buffer size
    char *buffer = new char[BUFFER_SIZE];
    int length = 0;
    char ch;
    while (input.get(ch))
    {
        if (ch == '!')
        {
            break; // stop reading at exclamation mark
        }
        if (length == BUFFER_SIZE - 1)
        {
            // buffer is full, resize it
            char *new_buffer = new char[BUFFER_SIZE * 2];
            std::copy(buffer, buffer + BUFFER_SIZE, new_buffer);
            delete[] buffer;
            buffer = new_buffer;
            BUFFER_SIZE *= 2;
        }
        buffer[length++] = ch;
    }
    buffer[length] = '\0'; // null-terminate the string
    return buffer;
}

int main()
{
    double coords[3] = {};
    double *p1 = coords;

    std::array<double, 4> pt4d;
    auto arr_it = pt4d.begin();

    std::vector<double> vec;
    auto vec_it = vec.begin();

    cout << "1.1)" << endl;

    // print size of coords and p1
    cout << sizeof(coords) << endl
         << sizeof(p1) << endl;

    // compute the number of elements in coords using sizeof
    cout << sizeof(coords) / sizeof(coords[0]) << endl;

    // compute the number of elements in coords through p1
    cout << sizeof(&p1) / sizeof(p1[0]) << endl;

    // compute the number of elements in vec using sizeof
    cout << sizeof(vec) / sizeof(vec_it) << endl;

    cout << endl;

    cout << "1.2)" << endl;

    string text1 = "Hello, World!";
    size_t i = 0;
    while (text1[i] != '\0')
    {
        to_upper(text1[i]);
        i += 1;
    }
    cout << endl
         << endl;

    cout << "1.3)" << endl;

    char text2[20] = "Hello, X";
    cout << rev_dup(text2) << endl
         << endl;

    cout << "1.4)" << endl;
    cout << read_text(cin) << endl;