#include <bits/stdc++.h>
using namespace std;
int main()
{

    //
    int myarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(myarray) / sizeof(int);
    int k = 4; // here k%n should be there for rotation of size more than the array
    int rotate[k];

    // Brute Force    space O(k), timeO(n)
    // It can be also done by taking ARRAY OF 2n size and the applying loop from k to k+n where k=k%n

    // for (int i = 0; i < k; i++) {
    //     rotate[i] = myarray[i]; }
    // for (int i = 0; i < n - k; i++)  {
    //     myarray[i] = myarray[k + i];}
    // for (int i = 0; i < k; i++) {
    //     myarray[n - k + i] = rotate[i]; }

    // -------------------------------------
    //  Optimise approach                      |
    //                                          |
    //     for (int i = k; i < k + n; i++)      |
    //     {                                    |
    //        cout << myarray[i % n] << " ";    |
    //     }                                    |
    //---------------------------------------

    // For printing Array
    for (int i = 0; i < n; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}
