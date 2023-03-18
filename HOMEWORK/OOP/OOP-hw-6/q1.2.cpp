#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void replace(char *s, char c1, char c2) {\
    size_t array_size = strlen(s);

    for(size_t i = 0; i < array_size; i++) {
        if(s[i] == c1) {
            s[i] = c2; 
        }
    }
}

int main() 
{
    char sentence[11] = "I love C+";
    replace(sentence, '+', '#');
    cout << sentence;

    return 0;
}
