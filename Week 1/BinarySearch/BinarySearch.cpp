#include <fstream>
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

        int arr[1000];

        for (int i = 0; i < n; i++)
        {
            in >> arr[i];
        }

        int key;
        in >> key;
        int comparisons = 0;
        int lo = 0;
        int hi = n - 1;
        bool flag = false;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            ++comparisons;
            if (arr[mid] == key)
            {
                flag = true;
                break;
            }
            else if (arr[mid] > key)
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
            out << "Present"
                << " " << comparisons << endl;
        }
        else
        {
            out << "Not Present"
                << " " << comparisons << endl;
        }
    }
}
