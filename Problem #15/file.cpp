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

void PrintMatrix(int Matrix[3][3])
{
    cout << "The 3x3 Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

short FindNumberInMatrix(int Matrix1[3][3], short Number)
{
    short Counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                Counter++;
            }
        }
    }
    return Counter;
}

void PrintFindNumberInMatrixResult(short Number, short Counter)
{
    cout << Number << "has been repeated " << Counter << " time(s).";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{9, 0, 2}, {0, 9, 0}, {0, 0, 9}};
    PrintMatrix(Matrix1);

    short Number = ReadNumber("Enter a number: ");

    int Results = FindNumberInMatrix(Matrix1, Number);
    PrintFindNumberInMatrixResult(Number, Results);
    return 0;
}