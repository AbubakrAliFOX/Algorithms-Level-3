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

void PrintVowels(string String)
{
    string VowelsInString = "";

    for (short i = 0; i < String.length(); i++)
    {
        if (IsVowel(String[i]))
        {
            VowelsInString = VowelsInString + (String[i]) + "\t";
        };
    }

    cout << VowelsInString << endl;
}

int main()
{
    string String = ReadString();
    // char Charachter = ReadChar();
    PrintVowels(String);

    return 0;
}