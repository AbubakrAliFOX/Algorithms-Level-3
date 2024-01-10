#include <iostream>
#include <cstdlib>

using namespace std;

void PrintFibinocciToRecursion(int Prev1, int Prev2, int Current)
{
    int To = 20;
    if (Current == 1)
    {
        cout << "1  ";
    }

    int FebNum = Prev1 + Prev2;
    cout << FebNum << "  ";
    Prev2 = Prev1;
    Prev1 = FebNum;
    if (Current <= To)
    {
        Current++;
        PrintFibinocciToRecursion(Prev1, Prev2, Current);
    }
}

int main()
{
    PrintFibinocciToRecursion(1, 0, 1);
    return 0;
}