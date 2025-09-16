#include <bits/stdc++.h>
#include<vector>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int ind=-1;
 // Step 1: Find the pivot (first element from the right that is smaller than its next one)
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]< nums[i+1])
            {
                ind=i;
                break;
            }
        }
  // Step 2: If no pivot found, array is already the largest permutation
        if(ind==-1)
        {
            reverse(nums.begin(),nums.end()); // just reverse whole array to smallest permutation
                 return;
        }

 // Step 3: Find the rightmost element greater than nums[ind]
        for(int i=n-1;i>=ind; i--)
        {
            if(nums[i]> nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }}
         reverse(nums.begin() + ind + 1, nums.end());

    }
};