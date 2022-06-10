class Solution {
    //ONE OF THE BEST 2 PINTER TECHNIQUE QUESTIONS !!!
    
public:
    //this is the code for subarray with atmost k distinct integers!
    int maxwithkdiffintegers(vector<int> &nums,int k){
        int low=0;int n=nums.size();
        int high=0;
        int count=0;
        unordered_map<int,int> mpp;
        for(int high=0;high<n;high++){
            mpp[nums[high]]++;
            while(mpp.size()>k){
               mpp[nums[low]]--; 
                if(mpp[nums[low]]==0){
                   mpp.erase(nums[low]); 
                }
                low++;
            }
            count+=high-low+1;//this is equal to number of subarrays!
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return maxwithkdiffintegers(nums,k)-maxwithkdiffintegers(nums,k-1);
        // //this is all the subarray wiht at max 3 differemt int -all the                 subarray withatmax 2 diff int!
        // //would have been more clr if longest substring with atmax k diff                 integers was not locked!
        
    }
};