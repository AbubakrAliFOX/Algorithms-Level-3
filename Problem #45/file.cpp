#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string ReadString(string Msg)
{
    string Str;
    cout << Msg << "\n";
    getline(cin, Str);
    return Str;
}

int ReadNumber(string Msg)
{
    int Number;
    cout << Msg << "\n";
    cin >> Number;
    return Number;
}

struct User
{
    string Name;
    string AccNumber;
    int PinCode, PhoneNumber;
    float AccBalance;
};

User CreateUser(User UserData)
{
    UserData.Name = ReadString("Please Enter Name");
    UserData.AccNumber = ReadString("Please Enter Account Number");
    UserData.PinCode = ReadNumber("Please Enter Pin Code");
    UserData.PhoneNumber = ReadNumber("Please Enter PhoneNumber");
    UserData.AccBalance = ReadNumber("Please Enter Account Balance");

    return UserData;
}

string ConvertRecordToLine(User UserData, string Seperator)
{
    string ClientRecord = "";
    ClientRecord += UserData.Name + Seperator;
    ClientRecord += UserData.AccNumber + Seperator;
    ClientRecord += to_string(UserData.PinCode) + Seperator;
    ClientRecord += to_string(UserData.PhoneNumber) + Seperator;
    ClientRecord += to_string(UserData.AccBalance);
    return ClientRecord;
}

int main()
{
    User User1;
    cout << ConvertRecordToLine(CreateUser(User1), "--");
    return 0;
}