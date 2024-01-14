#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string ReadString()
{
    string Str;
    cout << "Please Enter Your String?\n";
    getline(cin, Str);
    return Str;
}


bool isPunc (char Ch) {
    return Ch == ',' || Ch == '.' || Ch == '\'' || Ch == '\"' || Ch == '\\';
}

string RemovePunctuation(string Str)
{
    string Punc = ",'./\"";
    string StrWithoutPunc = "";
    for (short i = 0; i < Str.length(); i++)
    {
        if (!isPunc(Str[i])) {
            StrWithoutPunc += Str[i];
        }
    }

    return StrWithoutPunc;
}

int main()
{
    string Str = "I will, go out, there. now\" out";
    cout << RemovePunctuation(Str) << endl;

    return 0;
}