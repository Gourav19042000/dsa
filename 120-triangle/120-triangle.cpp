// class Solution {
// public:
//     int fun(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
//         if(i==triangle.size()-1){
//             return triangle[i][j];
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int down=triangle[i][j]+fun(i+1,j,triangle,dp);
//         int up=triangle[i][j]+fun(i+1,j+1,triangle,dp);
        
//         return dp[i][j]=min(down,up);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>> dp(triangle.size(),vector<int> (n,-1));
//         return fun(0,0,triangle,dp);
//     }
// };
class Solution {
public:
    //TABULATION METHOD NEEEDS PRACTICE!
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n,vector<int> (n,0));
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=triangle[n-1][j];
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int down=triangle[i][j]+dp[i+1][j];
    //             int right=triangle[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(down,right);
    //         }
    //     }
    //     return dp[0][0];
  //  }
    //space optimisation!!!just create 2 arrays in place of dp matrix;
    //possible if there is i+1 and i-1 in the dp!
    int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();  
        vector<int> curr(n,0),nxt(n,0);
        for(int i=0;i<n;i++){
            nxt[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+nxt[j];
                int right=triangle[i][j]+nxt[j+1];
                curr[j]=min(down,right);
            }
            nxt=curr;
        }
        return nxt[0];
    }  
};