#include <bits/stdc++.h>
#include<vector>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        map<int, int> mp;
    mp[0]=1;  //for case where prefixSum=k
    int preSum=0;
    int count=0;
    for(int i=0; i<n; i++)
    {
        preSum+= nums[i];
        int remove= preSum-k; //to check if there is a prefixSum which on removing from current prefixSum gives k
        count+= mp[remove]; //add how many subarrays exist
        
        mp[preSum]+=1;
    }
        return count;
    }
};