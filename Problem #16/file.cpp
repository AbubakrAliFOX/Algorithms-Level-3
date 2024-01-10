#include <iostream>
#include <cstdlib>

using namespace std;

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

bool IsSparseMatrix(int Matrix1[3][3])
{
    short ZeroCounter = 0, NumbersCounter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] == 0)
            {
                ZeroCounter++;
            } else {
                NumbersCounter++;
            }
        }
    }
    return ZeroCounter > NumbersCounter;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{9, 2, 2}, {0, 9, 0}, {0, 0, 9}};
    // int Matrix2[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};

    PrintMatrix(Matrix1);

    if (IsSparseMatrix(Matrix1))
    {
        cout << "Sprace Matrix";
    }
    else
    {
        cout << "Not Sprace Matrix";
    }
    return 0;
}