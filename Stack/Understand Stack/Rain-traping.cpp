// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {

        vector<int> lg, rg;

        long long int cl = arr[0];
        long long int rl = arr[n - 1];

        for (long long int i = 0; i < n; i++)
        {
            cl = cl > arr[i] ? cl : arr[i];
            lg.push_back(cl);
        }

        for (long long int i = n - 1; i >= 0; i--)
        {
            rl = rl > arr[i] ? rl : arr[i];
            rg.push_back(rl);
        }
        reverse(rg.begin(), rg.end());

        long long int sum = 0;
        for (long long int i = 0; i < n; i++)
        {
            sum += ((min(lg[i], rg[i]) - arr[i]));
        }
        return sum;
        // code here
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends