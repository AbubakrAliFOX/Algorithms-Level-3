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

void RowSum(int Matrix[3][3], int currentRow)
{
    int RowSumArr[3] = {0, 0, 0};
    for (int j = 0; j < 3; j++)
    {
        RowSumArr[currentRow] += Matrix[currentRow][j];
    }
    cout << "Row " << currentRow + 1 << " = " << RowSumArr[currentRow] << endl;
}

void SumMatrixRow(int Matrix[3][3])
{
    cout << "\n\nSum of rows:" << endl;
    for (int i = 0; i < 3; i++)
    {
        RowSum(Matrix, i);
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