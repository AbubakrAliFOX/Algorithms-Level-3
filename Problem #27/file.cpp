#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadChar()
{
    char charachter;
    cout << "Enter a char: " << endl;
    cin >> charachter;

    return charachter;
}


char InvertChar (char charachter) {
    return isupper(charachter)? tolower(charachter) : toupper(charachter);
} 


int main()
{
    char charachter = ReadChar();

    cout << "Inverted Char:" << endl;
    cout << InvertChar(charachter);

    return 0;
}