#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int lo, int hi, int pivot, int &comparisons, int &swaps)
{

    int i = lo, j = lo;

    while (i <= hi)
    {
        comparisons++;
        if (arr[i] <= pivot)
        {
            swaps++;

            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return j - 1;
}

void quickSort(int *arr, int lo, int hi, int &comparisons, int &swaps)
{

    if (lo < hi)
    {

        int pivot = arr[hi];
        int pi = partition(arr, lo, hi, pivot, comparisons, swaps);

        quickSort(arr, lo, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, hi, comparisons, swaps);
    }
}

int main()
{

    ifstream cin;
    ofstream cout;

    cin.open("Input.txt");
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
        int comparisons = 0;
        int swaps = 0;
        quickSort(arr, 0, n - 1, comparisons, swaps);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Comparisons=" << comparisons << endl;
        cout << "Swaps=" << swaps << endl;
    }
}