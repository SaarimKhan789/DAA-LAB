#include <iostream>
using namespace std;

int main()
{

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

        int key;
        cin >> key;
        int comparisons = 0;
        bool flag = false;

        for (int i = 0; i < n; i++)
        {

            ++comparisons;
            if (arr[i] == key)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "Element is Present" << endl;
        }
        else
        {
            cout << "Element is not Present" << endl;
        }

        cout << "Total no of comparisons=" << comparisons << endl;
    }
}