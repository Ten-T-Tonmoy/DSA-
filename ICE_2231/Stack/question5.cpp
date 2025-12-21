#include <iostream>
using namespace std;

void TOH(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << " disk 1 from " << from << " to " << to << endl;
        return;
    }
    //----------------recur calls----------------------
    TOH(n - 1, from, aux, to);
    cout << " disk " << n << " from " << from << " to " << to << endl;
    TOH(n - 1, aux, to, from);
}

int main()
{
    int numOfDisks = 8;
    TOH(numOfDisks, 'A', 'C', 'B');
    return 0;
}
