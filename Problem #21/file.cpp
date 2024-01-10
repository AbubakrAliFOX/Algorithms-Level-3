#include <iostream>
#include <cstdlib>

using namespace std;


void PrintFibinocciTo(short To)
{   
    cout << "1  ";
    int FebNum = 0;
    int Prev1 = 1, Prev2 = 0;
    for (short i = 2; i < To; i++)
    {
        FebNum = Prev1 + Prev2;
        cout << FebNum <<"  ";
        Prev2 = Prev1;
        Prev1 = FebNum;
    }
}

int main()
{
    PrintFibinocciTo(20);
    return 0;
}