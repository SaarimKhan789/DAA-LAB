#include <bits/stdc++.h>
using namespace std;

int BS(int *arr, int n, int key)
{
    int lo = 0;
    int hi = n - 1;
    int count = 0;
    int mid = 0, idx = 0;
    bool flag = false;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;

        if (arr[mid] == key)
        {
            flag = true;
            idx = mid;
            break;
        }

        else if (key < arr[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if (flag)
    {
        int count = 1;
        int left = idx - 1, right = idx + 1;
        while (left >= 0 && arr[left] == key)
        {
            left--;
            ++count;
        }
        while (right < n && arr[right] == key)
        {
            right++;
            ++count;
        }

        return count;
    }
    else
    {
        return 0;
    }
}

int main()
{

    ifstream in;
    in.open("Input.txt");
    ofstream out;
    out.open("Output.txt");
    int t;
    in >> t;
    while (t--)
    {
        int n;
        in >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            in >> arr[i];
        }
        int key;
        in >> key;

        int count = BS(arr, n, key);

        if (count != 0)
        {
            out << key << " - " << count << endl;
        }
        else
        {
            out << "Key not Present" << endl;
        }
    }

    return 0;
}
