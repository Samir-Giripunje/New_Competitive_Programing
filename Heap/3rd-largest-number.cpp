
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();

        //>>>>--------------------working code start but O(NLOG(N)) ------------->>>//
        //      set<int> s;
        //         for(int j=0;j<n;j++)
        //         {
        //             s.insert(nums[j]);
        //             if(s.size()>3)
        //                 s.erase(*s.begin());

        //         }

        //             n=s.size()==3?*s.begin():*s.rbegin();
        //>>>>--------------------working code ------------->>>//

        //---------------below code is of order 0(N)------------//
        int n1 = nums[0], n2 = INT_MIN, n3 = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            if (n1 < nums[i])
            {
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            }
            else if (nums[i] > n2 && nums[i] != n1)
            {
                n3 = n2;
                n2 = nums[i];
            }
            else if (nums[i] > n3 && (nums[i] != n1 && nums[i] != n2 && nums[i] != n3))
            {
                n3 = nums[i];
            }
        }
        int ans = n3;
        if (n3 == INT_MIN || n3 == n2 || n2 == INT_MIN || n1 == n2)
            ans = n1;

        return ans;
    }
};

//----------------tried with priority que but wasn't able to traverse it without poping it----------------//

//             priority_queue<int,vector<int>,greater<int>> minh;
//             for(int i=0;i<n;i++)
//             {

//                 for(priority_queue<int>::iterator it = minh.begin(); it != minh.end(); ++it)
//                 {
//                     if(*it==nums[i])
//                         check=true;
//                 }

//                 minh.push(nums[i]);
//                 if(minh.size()>3)
//                     minh.pop();
//             }
