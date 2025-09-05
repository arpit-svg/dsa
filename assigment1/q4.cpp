#include <iostream>
using namespace std;

void reverseArray()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void matrixMultiplication()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Multiplication not possible\n";
        return;
    }

    int a[r1][c1], b[r2][c2], c[r1][c2];

    cout << "Enter A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    cout << "Result:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
}

void transposeMatrix()
{
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int a[r][c];

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Transpose:\n";
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n1. Reverse Array\n2. Matrix Multiplication\n3. Transpose Matrix\n4. Exit\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            reverseArray();
            break;
        case 2:
            matrixMultiplication();
            break;
        case 3:
            transposeMatrix();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (ch != 4);
    return 0;
}
