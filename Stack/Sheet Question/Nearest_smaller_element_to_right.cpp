#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 3, 4, 2, 1};
    stack<int> st;
    vector<int> ans;

    for (int i = sizeof(arr) / sizeof(int) - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        int p = st.empty() ? -1 : st.top();
        ans.push_back(p);
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}