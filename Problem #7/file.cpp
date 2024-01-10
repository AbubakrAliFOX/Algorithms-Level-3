#include <iostream>
#include <cstdlib>

using namespace std;



void CreateTrapozeMatrix(int Matrix[3][3])
{   
    short Counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Counter++;
            Matrix[j][i] = Counter;
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

// void ColSum(int Matrix[3][3], int currentCol)
// {
//     int ColSumArr[3] = {0, 0, 0};
//     for (int j = 0; j < 3; j++)
//     {
//         ColSumArr[currentCol] += Matrix[j][currentCol];
//     }
//     cout << "Col " << currentCol + 1 << " = " << ColSumArr[currentCol] << endl;
// }

// void SumMatrixRow(int Matrix[3][3])
// {
//     cout << "\n\nSum of columns:" << endl;
//     for (int i = 0; i < 3; i++)
//     {
//         ColSum(Matrix, i);
//     }
// }

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    CreateTrapozeMatrix(Matrix);
    PrintMatrix(Matrix);
    // SumMatrixRow(Matrix);
    return 0;
}