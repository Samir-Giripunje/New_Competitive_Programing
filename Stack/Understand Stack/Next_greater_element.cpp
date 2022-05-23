#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 3, 4, 2};
    stack<int> st;
    vector<int> ans;

    for (int i = (sizeof(a) / sizeof(int)) - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= a[i])
        {
            st.pop();
        }

        // if (st.empty())
        // {
        //     ans.push_back(-1);
        //     st.push(a[i]);
        // }
        // else if (st.top() > a[i])
        // {
        //     ans.push_back(st.top());
        //     st.push(a[i]);
        // }

        int k = st.empty() ? -1 : st.top();
        ans.push_back(k);
        st.push(a[i]);
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
