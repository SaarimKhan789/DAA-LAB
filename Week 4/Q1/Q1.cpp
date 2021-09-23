#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int lo, int mid, int hi, int &comparisons, int &inversions)
{

    int i = lo;
    int j = mid;
    int k = 0;
    int *temp = new int[hi - lo + 1];

    while (i < mid && j <= hi)
    {
        ++comparisons;
        if (arr[i] < arr[j])
        {

            temp[k++] = arr[i++];
        }
        else
        {

            temp[k++] = arr[j++];
            inversions += mid - i;
        }
    }

    while (i < mid)
    {

        temp[k++] = arr[i++];
    }
    while (j <= hi)
    {

        temp[k++] = arr[j++];
    }

    for (int i = lo, k = 0; i <= hi; i++, k++)
    {
        arr[i] = temp[k];
    }
    delete[] temp;
}

void mergeSort(int *arr, int lo, int hi, int &comparisons, int &inversions)
{

    if (lo < hi)
    {

        int mid = (lo + hi) / 2;

        mergeSort(arr, lo, mid, comparisons, inversions);
        mergeSort(arr, mid + 1, hi, comparisons, inversions);
        merge(arr, lo, mid + 1, hi, comparisons, inversions);
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
        int inversions = 0;
        mergeSort(arr, 0, n - 1, comparisons, inversions);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Comparisons=" << comparisons << endl;
        cout << "Inversions=" << inversions << endl;
    }
}