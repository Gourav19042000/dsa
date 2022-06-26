class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int sum=0,maxsum=0,low=n-k;
        for(int i=0;i<2*n;i++){
            if(i>=n-k && i<n+k){
            sum+=c[i%n];
            if(i>=n){sum-=c[low%n];low++;}
            maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }
};