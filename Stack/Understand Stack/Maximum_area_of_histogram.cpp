#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    vector<int> r, l;
    stack<pair<int, int>> st;

    // Next smaller to the left
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }

        r.push_back(st.empty() ? 0 : st.top().second);

        st.push({arr[i], i});
    }

    // Next smaller element to the right
    for (int i = sizeof(arr) / sizeof(int) - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        l.push_back(st.empty() ? sizeof(arr) / sizeof(int) - 1 : st.top().second);
        st.push({arr[i], i});
    }

    vector<int> ans;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        ans.push_back(arr[i] * (l[i] - r[i] + 1));
    }

    int final_ans = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        final_ans = max(final_ans, ans[i]);
    }

    cout << final_ans << " ";
    return 0;
}