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

char LowercaseLetter(char Letter)
{
    return char(tolower(Letter));
}

char UppercaseLetter(char Letter)
{
    return char(toupper(Letter));
}

void UppercaseSentence(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = UppercaseLetter(Sentence[i]);
    }

    cout << Sentence << endl;
}

void LowercaseSentence(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = LowercaseLetter(Sentence[i]);
    }

    cout << Sentence << endl;
}

int main()
{
    string Sentence = ReadString();

    UppercaseSentence(Sentence);
    LowercaseSentence(Sentence);

    return 0;
}