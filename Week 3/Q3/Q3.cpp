#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream cin;
    cin.open("Input.txt");
    ofstream cout;
    cout.open("Output.txt");
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        delete[] arr;
    }
    return 0;
}
