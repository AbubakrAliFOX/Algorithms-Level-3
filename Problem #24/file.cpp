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

char CapitilizeLetter(char Letter)
{
    return char(toupper(Letter));
}

void CapatilizeSentence(string Sentence)
{
    bool IsFirstLetter = true;
    char CurrentChar;
    string NewSentence = "";

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ' && IsFirstLetter)
        {
            CurrentChar = CapitilizeLetter(Sentence[i]);
        }
        else
        {
            CurrentChar = Sentence[i];
        }

        NewSentence += CurrentChar;
        IsFirstLetter = Sentence[i] == ' ';
    }

    cout << NewSentence << endl;
}

int main()
{
    string Sentence = ReadString();

    CapatilizeSentence(Sentence);

    return 0;
}