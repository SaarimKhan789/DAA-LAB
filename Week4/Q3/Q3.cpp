#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int l, int r)
{

    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            // Swapping arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        }
    }

    // Swapping arr[i] and arr[r]
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}

int kthSmallest(int *arr, int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {

        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];

        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
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

        int k;
        cin >> k;

        int ans = kthSmallest(arr, 0, n - 1, k);

        cout << ans << endl;
    }
}