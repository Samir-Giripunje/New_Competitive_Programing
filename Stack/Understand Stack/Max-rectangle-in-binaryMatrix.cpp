// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    //   int MAH( vector<int>  &s)
    //          {
    //               vector<int>r,l;
    //             int ans=0;
    //             stack<pair<int,int>> st,st1;

    //             // left smaller element
    //             for(int i=0;i<s.size();i++)
    //             {
    //                 while(!st.empty() && st.top().first>=s[i])
    //                 {st.pop();}
    //                 l.push_back(st.empty()?-1:st.top().second);
    //                 st.push({s[i],i});
    //             }

    //             //right smaller element
    //             for(int i=s.size()-1;i>=0;i--)
    //             {
    //                 while(!st1.empty() && st1.top().first>=s[i])
    //                 {st1.pop();}
    //                 r.push_back(st1.empty()?s.size():st1.top().second);
    //                 st1.push({s[i],i});
    //             }
    //             reverse(r.begin(),r.end());

    //             for(int i=0;i<s.size();i++)
    //             {
    //                 ans=max(ans,s[i]*(r[i]-l[i]-1));
    //             }

    //             return ans;
    //          }

    //     int maxArea(int M[MAX][MAX], int n, int m) {

    //         vector<int> s(m,0);
    //       int k=0;

    //         for(int i=0;i<n;i++)
    //         {
    //             for(int j=0;j<m;j++)
    //             {
    //                 s[i]=M[i][j]==0?0:s[i]+1;
    //             }
    //             k=max(k,MAH(s));
    //         }

    //     return k;

    //     int MAH(vector<int> &A,int n){
    //     vector<int> left(n,-1),right(n,n),st;
    //     for(int i=0;i<n;i++){
    //         while(st.size() and A[st.back()]>A[i]) st.pop_back();
    //         if(st.size()) left[i]=st.back();
    //         st.push_back(i);
    //     }
    //     st.clear();
    //     for(int i=0;i<n;i++){
    //         while(st.size() and A[st.back()]>A[i]){
    //             right[st.back()]=i;
    //             st.pop_back();
    //         }
    //         st.push_back(i);
    //     }
    //     int ans=0;
    //     for(int i=0;i<n;i++) ans=max(ans,(right[i]-left[i]-1)*A[i]);
    //     return ans;
    // }
    // int maxArea(int matrix[MAX][MAX], int n, int m) {
    //   vector<int> A(m,0);
    //   int res=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(matrix[i][j]==0) A[j]=0;
    //             else A[j]+=1;
    //         }
    //         res=max(res,MAH(A,m));
    //     }
    //     return res;

    int MAH(vector<int> &heights, int &m)
    {
        int n = heights.size();
        vector<int> l, r;
        stack<pair<int, int>> st, st1;

        // smaller element to the left
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first >= heights[i])
                st.pop();

            l.push_back(st.empty() ? -1 : st.top().second);
            st.push({heights[i], i});
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st1.empty() && st1.top().first >= heights[i])
                st1.pop();

            r.push_back(st1.empty() ? n : st1.top().second);
            st1.push({heights[i], i});
        }
        reverse(r.begin(), r.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (r[i] - l[i] - 1));
        }
        return ans;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {

        vector<int> s(m, 0);
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                s[j] = M[i][j] == 0 ? 0 : s[j] + 1;
            }
            k = max(k, MAH(s, m));
        }

        return k;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends