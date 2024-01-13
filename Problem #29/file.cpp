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

int UpperCaseCount(string Str)
{
    int UpperCounter = 0;
    for (short i = 0; i < Str.length(); i++)
    {
        isupper(Str[i]) && UpperCounter++;
    }

    return UpperCounter;
    
}

int LowerCaseCount(string Str)
{
    int LowerCounter = 0;
    for (short i = 0; i < Str.length(); i++)
    {
        islower(Str[i]) && LowerCounter++;
    }

    return LowerCounter;
    
}


int main()
{
    string Sentence = ReadString();
 
    cout << "String Length: " << Sentence.length() << endl;
    cout << "UpperCase Letters Count: " << UpperCaseCount(Sentence) << endl;
    cout << "LowerCase Letters Count: " << LowerCaseCount(Sentence) << endl;

    return 0;
}