#include <iostream>
#include <cstdlib>

using namespace std;

int ReadNumber(string Msg)
{
    int Number;
    cout << Msg << endl;
    cin >> Number;

    return Number;
}

void PrintMatrix(short Matrix[3][3])
{
    cout << "The 3x3 Matrix:" << endl;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

bool FindNumberInMatrix(short Matrix[3][3], short Number)
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectingNumbers(short Matrix1[3][3], short Matrix2[3][3])
{
    cout << "Intersecting numbers are: " << endl;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (FindNumberInMatrix(Matrix2, Matrix1[i][j]))
            {
                cout << Matrix1[i][j] << "\t";
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short Matrix1[3][3] = {{9, 12, 2}, {31, 18, 100}, {131, 101, 33}};
    short Matrix2[3][3] = {{12, 13, 2}, {0, 9, 0}, {0, 0, 9}};
    PrintMatrix(Matrix1);

    PrintIntersectingNumbers(Matrix1, Matrix2);

    return 0;
}