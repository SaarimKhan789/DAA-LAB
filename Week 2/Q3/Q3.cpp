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
        int k;
        cin >> k;
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {

                int diff = abs(arr[i] - arr[j]);

                if (diff == k)
                {
                    ++count;
                }
            }
        }

        cout << count << endl;

        delete[] arr;
    }
    return 0;
}
