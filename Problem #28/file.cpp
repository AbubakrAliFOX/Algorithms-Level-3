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

char InvertChar(char charachter)
{
    return isupper(charachter) ? tolower(charachter) : toupper(charachter);
}

string InvertString(string Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = InvertChar(Str[i]);
    }

    return Str;
}

int main()
{
    string Sentence = ReadString();

    cout << "Inverted String:\n\n"
         << endl;
         
    cout << InvertString(Sentence);
    return 0;
}