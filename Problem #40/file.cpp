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

short CountWords(string Str)
{
    string delim = " "; // delimiter
    cout << "\nYour string wrords are: \n\n";
    short pos = 0;
    string sWord; // define a string variable  // use find() function to get the position of the delimiters

    short Counter = 0;
    while ((pos = Str.find(delim)) != std::string::npos)
    {
        sWord = Str.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
            Counter++;
        }
        Str.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
    }
    if (Str != "")
    {
        cout << Str << endl; // it print last word of the string.
        Counter++;
    }

    return Counter;
}

string join(vector<string> vWords, string Delim)
{
    string Str;
    for (short i = 0; i < vWords.size(); i++)
    {
        Str = Str + vWords[i] + Delim;
    }

    return Str.substr(0, Str.length() - Delim.length());
}

string join(string vWords[100], int Length, string Delim)
{
    string Str;
    for (short i = 0; i < Length; i++)
    {
        Str = Str + vWords[i] + Delim;
    }

    return Str.substr(0, Str.length() - Delim.length());
}

int main()
{
    vector<string> vWords = {"Ahmad", "Khaled", "Menza"};
    string Arr[3] = {"Ahmad", "Khaled", "Menza"};

    cout << join(vWords, " *** ") << endl;

    cout << join(Arr, 3, " *** ") << endl;
    return 0;
}