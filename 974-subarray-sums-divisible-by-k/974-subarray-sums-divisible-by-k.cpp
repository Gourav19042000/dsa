class Solution {
public:
    //prefix sum problem...seems easy!
    int subarraysDivByK(vector<int>& nums, int k) {
       int count=0,n=nums.size(),sum=0;
        unordered_map<int,int> m;
       // m[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem==0)count++;
            if(rem<0)rem+=k;;
             if(m.find(rem)!=m.end()){
                count+=m[rem];
               
                 
            }
         m[rem]+=1;
        }
        return count;
    }
};