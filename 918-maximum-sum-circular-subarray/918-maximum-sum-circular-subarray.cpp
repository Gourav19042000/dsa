class Solution {
public:
    //my thought ...just assume concadenating 2 arrays!//not possible!as it takes same element twice!
    //very very good question!
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmax=0,curmin=0,maxi=nums[0],mini=nums[0],sum=0;
        for(auto it:nums){
            sum+=it;
         curmax=max(it,curmax+it);
            maxi=max(maxi,curmax);
            curmin=min(it,curmin+it);
            mini=min(mini,curmin);
            cout<<maxi<<mini<<" ";
        }
        return maxi>0?max(maxi,sum-mini):maxi;
    }
};