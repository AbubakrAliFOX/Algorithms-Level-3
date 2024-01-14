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

string TrimLeft(string Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ')
        {
            return Str.substr(i, Str.length() - i);
        }
    }

    return "";
}

string TrimRight(string Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        int pos = Str.length() - i - 1;
        if (Str[pos] != ' ')
        {
            return Str.substr(0, pos + 1);
        }
    }

    return "";
}

string Trim(string Str)
{
    Str = TrimRight(Str);
    Str = TrimLeft(Str);

    return Str;
}

int main()
{
    string Str = ReadString();
    
    cout << "Trim Left:\n" << TrimLeft(Str) << endl;
    cout << "Trim Right:\n" << TrimRight(Str) << endl;
    cout << "Trim: \n" << Trim(Str) << endl;

    return 0;
}