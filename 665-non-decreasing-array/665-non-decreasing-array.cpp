class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                count++;
            }
           if(i<n-1 && i>=2){
               if(nums[i]<nums[i-1] &&  nums[i-2] > nums[i] && nums[i+1] < nums[i-1])return false;
           }
        }
        return count<=1;
    }
};