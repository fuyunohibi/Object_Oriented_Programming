#include <iostream>

void replace(char *s, char c1, char c2)
{
    int i = 0;
    while (s[i] != '\0') // iterate over the characters in the string
    {
        if (s[i] == c1) // if the character matches c1, replace it with c2
        {
            s[i] = c2;
        }
        i++;
    }
}

int main()
{
    char sentence[] = "Hello, World!";
    std::cout << "==========================Q1.2==========================" << std::endl;
    std::cout << "Original string: " << sentence << std::endl;
    replace(sentence, 'l', 'X');
    std::cout << "Modified string: " << sentence << std::endl;

    return 0;
}
