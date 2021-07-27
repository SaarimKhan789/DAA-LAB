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

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            in >> arr[i];
        }

        int key;
        in >> key;
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
