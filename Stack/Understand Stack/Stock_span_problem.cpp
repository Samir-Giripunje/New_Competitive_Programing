#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {100, 82, 72, 92, 82, 70};
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        while (!st.empty() && st.top().first <= arr[i])
        {
            st.pop();
        }

        ans.push_back(st.empty() ? -1 : st.top().second);
        st.push({arr[i], i});
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << i - ans[i] << " ";
    }
    return 0;
}

// 100,82,72,92,82,70      1 1 1 3 1 1