class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return fun(0,0,word1,word2,dp);
    }
    int fun(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(ind1==s1.size() || ind2==s2.size()){
            return max(s1.size()-ind1,s2.size()-ind2);
        }
         if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=fun(ind1+1,ind2+1,s1,s2,dp);
        else{
        return dp[ind1][ind2]=1+min(fun(ind1+1,ind2,s1,s2,dp),fun(ind1,ind2+1,s1,s2,dp));
        }
       
    }
};