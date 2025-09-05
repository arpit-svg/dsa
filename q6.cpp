#include <iostream>
using namespace std;

// Function to display sparse matrix in triplet form
void display(int A[20][3])
{
    int n = A[0][2];
    for (int i = 0; i <= n; i++)
    {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

// Transpose of Sparse Matrix
void transpose(int A[20][3], int B[20][3])
{
    int rows = A[0][0], cols = A[0][1], n = A[0][2];
    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = n;

    int k = 1;
    for (int col = 0; col < cols; col++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (A[i][1] == col)
            {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

// Addition of two Sparse Matrices
void addSparse(int A[20][3], int B[20][3], int C[20][3])
{
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        cout << "Addition not possible (different dimensions)\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int n1 = A[0][2], n2 = B[0][2];

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= n1 && j <= n2)
    {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }
        else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1]))
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }
        else
        { // same row & column
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
            k++;
        }
    }

    while (i <= n1)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    while (j <= n2)
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    C[0][2] = k - 1;
}

int main()
{
    int A[20][3], B[20][3], C[20][3], T[20][3];
    int n;

    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> n;
    cout << "Enter rows, cols, non-zeros: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= n; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "\nMatrix A in triplet form:\n";
    display(A);

    // Transpose
    transpose(A, T);
    cout << "\nTranspose of Matrix A:\n";
    display(T);

    // Second matrix for addition
    cout << "\nEnter number of non-zero elements in Matrix B: ";
    cin >> n;
    cout << "Enter rows, cols, non-zeros: ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= B[0][2]; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    cout << "\nMatrix B in triplet form:\n";
    display(B);

    // Addition
    addSparse(A, B, C);
    cout << "\nAddition Result (C = A + B):\n";
    display(C);

    return 0;
}
