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

void LowercaseSentece(string Sentence)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ' && IsFirstLetter)
        {
            Sentence[i] = LowercaseLetter(Sentence[i]);
        }


        IsFirstLetter = Sentence[i] == ' ';
    }

    cout << Sentence << endl;
}

int main()
{
    string Sentence = ReadString();

    LowercaseSentece(Sentence);

    return 0;
}