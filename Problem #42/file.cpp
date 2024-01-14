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

string ReplaceString (string Str, string Item, string Replace) {
    short pos = Str.find(Item);
    while ( pos != std::string::npos)
    {
        Str = Str.replace(pos, Item.length(), Replace);
        pos = Str.find(Item);
        
    }

    return Str;
    
}

int main()
{
    string Str = ReadString();
    string Item = ReadString();
    string Replace = ReadString();
    cout << ReplaceString(Str,Item,Replace);

    return 0;
}