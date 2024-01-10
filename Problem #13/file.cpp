#include <iostream>
#include <cstdlib>

using namespace std;

// int RandomNumber(int From, int To)
// {
//     int randNum = rand() % (To - From + 1) + From;
//     return randNum;
// }

// void CreateMatrix(int Matrix[3][3])
// {
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             Matrix[i][j] = RandomNumber(1, 200);
//         }
//     }
// }

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

bool IsIdentityMatrix(int Matrix1[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i == j && Matrix1[i][j] != 1) || (i != j && Matrix1[i][j] != 0))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    // int Matrix2[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};

    PrintMatrix(Matrix1);

    if (IsIdentityMatrix(Matrix1))
    {
        cout << "Identity Matrix";
    }
    else
    {
        cout << "Not Identity Matrix";
    }
    return 0;
}