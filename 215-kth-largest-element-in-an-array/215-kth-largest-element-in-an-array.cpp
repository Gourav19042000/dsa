class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // priority_queue<int,vector<int>,greater<int> > pq;
      //   int n=nums.size();
      //   for(int i=0;i<n;i++){//this has less complexity!!
      //       if(i<k){
      //           pq.push(nums[i]);
      //       }
      //       else{
      //           if(nums[i]>pq.top()){
      //           pq.pop();
      //           pq.push(nums[i]);
      //           }
      //       }
      //   }
        
         priority_queue<int > pq;//this has more complexity!
        for(auto it:nums){
            pq.push(it);
        }
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};