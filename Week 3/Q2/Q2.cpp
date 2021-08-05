#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int *arr, int n, int &comparisons, int &swaps)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];

        int pos = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
            ++comparisons;
        }

        int t = arr[pos];
        arr[pos] = arr[i];
        arr[i] = t;

        swaps++;
    }
}

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
        int comparisons = 0, swaps = 0;
        SelectionSort(arr, n, comparisons, swaps);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;

        delete[] arr;
    }
    return 0;
}
