#include <iostream>
#include <vector>
#include <string>
#include <cstring>

char *encode_hex(const char *s) {
    size_t array_size = strlen(s);
    char *hex = new char[array_size];
    for(size_t i = 0; i < array_size; i++) {
        hex[i] = s[i];
    }
    return hex;
}

int main()
{
    char *s = "Hello";
    char *hex = encode_hex(s);
    std::cout << hex << std::endl;
    delete[] hex;
    return 0;

}