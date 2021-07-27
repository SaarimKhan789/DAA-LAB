#include <fstream>
#include <math.h>
using namespace std;
int JumpSearch(int *arr, int n, int key, int &comparisons)
{

    int prev = 0;
    int jumps = (int)sqrt(n);
    int steps = jumps;

    while (arr[min(steps, n) - 1] < key)
    {

        prev = steps;
        steps += jumps;
        ++comparisons;

        if (prev >= n)
        {
            return -1;
        }
    }

    while (arr[prev] < key)
    {
        ++comparisons;
        ++prev;

        if (prev == min(steps, n))
        {
            return -1;
        }
    }

    if (arr[prev] == key)
    {
        return prev;
    }

    return -1;
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

        int comparisons = 0;

        int res = JumpSearch(arr, n, key, comparisons);

        if (res == -1)
        {
            out << "Not Present"
                << " " << comparisons << endl;
        }
        else
        {
            out << "Present"
                << " " << comparisons << endl;
        }
    }
}