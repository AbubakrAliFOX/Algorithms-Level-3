#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string Str;
    cout << "Enter a sentence: " << endl;
    getline(cin, Str);

    return Str;
}

char ReadChar()
{
    char charachter;
    cout << "Enter a char: " << endl;
    cin >> charachter;

    return charachter;
}

bool IsVowel(char Ch)
{
    Ch = tolower(Ch);
    return Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u';
}

void CountVowels(string String)
{
    int Counter = 0;

    for (short i = 0; i < String.length(); i++)
    {
        IsVowel(String[i]) && Counter++;
    }

    cout << Counter << " Vowels" << endl;
}

int main()
{
    string String = ReadString();
    // char Charachter = ReadChar();
    CountVowels(String);
    
    return 0;
}