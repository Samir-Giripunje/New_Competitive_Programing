// Input: nums = [1,2,3,1]
// Output: true

// Input: nums = [1,2,3,4]
// Output: false

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
  
         
            sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==nums[i])
            return true;
        }
    return false;  
    }
};



// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
    
//             sort(nums.begin(),nums.end());
        
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i+1]-nums[i]==0)
//             return true;
//         }
//     return false;
//     }
// };









