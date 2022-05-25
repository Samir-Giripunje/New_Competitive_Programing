#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 3, 4, 2};
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        int p = st.empty() ? -1 : st.top();
        ans.push_back(p);
        st.push(arr[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}