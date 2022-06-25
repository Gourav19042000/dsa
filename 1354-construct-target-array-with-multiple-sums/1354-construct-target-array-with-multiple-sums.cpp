class Solution {
public:
    //quiet difficult question!!!...try to think reverse ..i.r from target array to 1s array!
   // great explanation!!https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/2189445/Visual-Explanation-or-JAVA-Max-Heap
    //1 explanation can solve all doubt!
    bool isPossible(vector<int>& target) {
        long long sum=0;
        for(auto it:target){
            sum+=it;
        }
        priority_queue<int> pq(target.begin(),target.end());
        while(pq.top()!=1){//this traverses the whole pq!
          int temp=pq.top();
            pq.pop();
           sum-=temp; 
            if(sum<1 || temp<=sum )return false;
            int ans=temp%sum;
            sum+=ans;
            
            pq.push(ans?ans:sum);
            
        }
        return true;
    }
};

    