#include <bits/stdc++.h>
using namespace std;

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
        bool flag = false;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {

                    if (i != k && j != k)
                    {

                        int sum = arr[i] + arr[j];

                        if (arr[k] == sum)
                        {
                            flag = true;
                            out << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        }
                    }
                }
            }
        }

        if (!flag)
        {
            out << "No sequence found" << endl;
        }

        delete[] arr;
    }
    return 0;
}
