#include <bits/stdc++.h>
using namespace std;

void find(int *arr1, int m, int *arr2, int n)
{

    int i = 0, j = 0;

    while (i < m && j < n)
    {

        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    cout << endl;
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

        int n1;
        cin >> n1;
        int *arr1 = new int[n1];

        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }

        int n2;
        cin >> n2;
        int *arr2 = new int[n2];

        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }

        find(arr1, n1, arr2, n2);
    }
}