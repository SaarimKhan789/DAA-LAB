#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int *arr, int n, int &comparisons, int &shifts)
{

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curr)
        {
            ++comparisons;
            ++shifts;
            arr[j + 1] = arr[j];
            j--;
        }
        ++shifts;
        arr[j + 1] = curr;
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
        int comparisons = 0, shifts = 0;
        InsertionSort(arr, n, comparisons, shifts);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "shifts = " << shifts - 1 << endl;

        delete[] arr;
    }

    return 0;
}
