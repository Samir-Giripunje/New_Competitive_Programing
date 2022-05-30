// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> l, r;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }
            l.push_back(st.empty() ? -1 : st.top().second);
            st.push({arr[i], i});
        }

        stack<pair<int, int>> st2;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && st2.top().first > arr[i])
            {
                st2.pop();
            }
            r.push_back(st2.empty() ? n : st2.top().second);
            st2.push({arr[i], i});
        }

        reverse(r.begin(), r.end());

        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans > arr[i] * (r[i] - l[i] - 1) ? ans : arr[i] * (r[i] - l[i] - 1);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[] = {6, 2, 5, 4, 5, 1, 6};
//     vector<int> r, l;
//     stack<pair<int, int>> st;

//     // Next smaller to the left
//     for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//     {
//         while (!st.empty() && st.top().first >= arr[i])
//         {
//             st.pop();
//         }

//         r.push_back(st.empty() ? 0 : st.top().second);

//         st.push({arr[i], i});
//     }

//     // Next smaller element to the right
//     for (int i = sizeof(arr) / sizeof(int) - 1; i >= 0; i--)
//     {
//         while (!st.empty() && st.top().first >= arr[i])
//         {
//             st.pop();
//         }
//         l.push_back(st.empty() ? sizeof(arr) / sizeof(int) - 1 : st.top().second);
//         st.push({arr[i], i});
//     }

//     vector<int> ans;
//     for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//     {
//         ans.push_back(arr[i] * (l[i] - r[i] + 1));
//     }

//     int final_ans = 0;
//     for (int i = 0; i < ans.size(); i++)
//     {
//         final_ans = max(final_ans, ans[i]);
//     }

//     cout << final_ans << " ";
//     return 0;
// }
