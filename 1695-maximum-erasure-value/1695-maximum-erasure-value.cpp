class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int low=0,sum=0,maxi=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
             while(low<=mp[nums[i]] && low<n){
                 sum-=nums[low];
                 low++;
             }
            }
            
                sum+=nums[i];
            maxi=max(sum,maxi);
            mp[nums[i]]=i;
        }
        return maxi;
    }
};