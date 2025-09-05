#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int a[r][c];

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Row sums:\n";
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += a[i][j];
        cout << "Row " << i << ": " << sum << "\n";
    }

    cout << "Column sums:\n";
    for (int j = 0; j < c; j++)
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += a[i][j];
        cout << "Col " << j << ": " << sum << "\n";
    }
}
