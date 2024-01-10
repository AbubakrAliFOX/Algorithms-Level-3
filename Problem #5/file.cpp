#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void CreateMatrix(int Matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Matrix[i][j] = RandomNumber(1, 200);
        }
    }
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

void ColSum(int Matrix[3][3], int currentCol)
{
    int ColSumArr[3] = {0, 0, 0};
    for (int j = 0; j < 3; j++)
    {
        ColSumArr[currentCol] += Matrix[j][currentCol];
    }
    cout << "Col " << currentCol + 1 << " = " << ColSumArr[currentCol] << endl;
}

void SumMatrixRow(int Matrix[3][3])
{
    cout << "\n\nSum of columns:" << endl;
    for (int i = 0; i < 3; i++)
    {
        ColSum(Matrix, i);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    CreateMatrix(Matrix);
    PrintMatrix(Matrix);
    SumMatrixRow(Matrix);
    return 0;
}