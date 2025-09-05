#include <iostream>
using namespace std;

int arr[100], n = 0;

void create()
{
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void display()
{
    if (n == 0)
    {
        cout << "Array empty\n";
        return;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insert()
{
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
}

void del()
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
}

void linear_search()
{
    int key, found = -1;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = i;
            break;
        }
    }
    if (found != -1)
        cout << "Found at index " << found << "\n";
    else
        cout << "Not found\n";
}

int main()
{
    int ch;
    do
    {
        cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            del();
            break;
        case 5:
            linear_search();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid\n";
        }
    } while (ch != 6);
    return 0;
}
