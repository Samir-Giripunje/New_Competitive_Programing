// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// here noticable difrence is i did with O(2n) here solution is of O(N/2)

class Solution
{
public:
    //
}
}
;

//------------O(N)and fast---------//
int max(int a) { return (a > -a ? a : -a); }
vector<int> sortedSquares(vector<int> &nums)
{

    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n;)
    {
        if (max(nums[i]) < nums[n - 1])
        {
            ans.push_back(nums[n - 1] * nums[n - 1]);
            n--;
        }
        else
        {
            ans.push_back(nums[i] * nums[i]);
            i++;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
    //----------------code end---------------//

    //---------------hashing   (working)----------------//
    int arr[20000] = {0};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        arr[max(nums[i], -nums[i])]++;
    }

    vector<int> ans;

    for (int i = 0; i < 20000; i++)
    {
        while (arr[i]--)
        {
            ans.push_back((i) * (i));
        }
    }
    //----------------code end---------------//