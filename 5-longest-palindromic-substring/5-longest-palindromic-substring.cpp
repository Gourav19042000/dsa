// class Solution {
// public:
//     string longestPalindrome(string s) {
//         //pepcoding 100%easy code...similar qstn palindromic substring!
//         int n=s.size();
//         string s2="";
//         vector<vector<bool>> dp(n,vector<bool> (n,false));
//          for(int gap=0;gap<n;gap++){
//              for(int i=0,j=gap;j<n;j++,i++){
//                  if(gap==0){
//                      dp[i][j]=true;
//                  }
//                  else if(gap==1){
//                      if(s[i]==s[j] ){
//                          dp[i][j]=true;
//                      }
//                  }
//                  else{
//                      if(s[i]==s[j] && dp[i+1][j-1]==true){
//                          dp[i][j]=true;                   
//                      }
//                  }
//                  if(dp[i][j]){
                    
//                      s2=s.substr(i,j-i+1);//here j-i+1 is the length!..and                                         not the ending point!
//                  }
//              }
//          }
       
//         return s2;
//     }
// };

//just a random try from discussion
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};