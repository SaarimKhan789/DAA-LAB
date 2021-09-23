#include <bits/stdc++.h>
using namespace std;

void find(int *arr, int n, int target)
{

    sort(arr, arr + n);
    bool flag = false;
    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            flag = true;
            cout << arr[left] << " " << arr[right] << ",";
            left++;
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << endl;
    if (!flag)
        cout << "No Such Pair Exist" << endl;
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

        int target;
        cin >> target;

        find(arr, n, target);
        cout << endl;
    }
}