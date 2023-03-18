#include <iostream>

char *encode_hex(const char *s)
{
    std::cout << s << std::endl;
    const char hex[] = "0123456789ABCDEF"; // hex characters to encode with
    int len = 0;
    while (s[len] != '\0') // calculate length of input string
    {
        len++;
    }

    char *hex_str = new char[len * 2 + 1]; // allocate memory for encoded string (2 hex digits per character + 1 for null terminator)
    int i = 0;
    int j = 0;

    while (s[i] != '\0') // encode each character into two hex digits
    {
        hex_str[j] = hex[(s[i] >> 4) & 0xF]; // first hex digit (higher 4 bits)
        hex_str[j + 1] = hex[s[i] & 0xF];    // second hex digit (lower 4 bits)
        
        i++;
        j += 2;
    }
    hex_str[j] = '\0'; // add null terminator
    return hex_str;
}

int main()
{
    const char *s = "Hello, world!";
    char *hex = encode_hex(s);
    
    std::cout << hex << std::endl;
    delete[] hex;
    return 0;
}
