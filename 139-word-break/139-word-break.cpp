 class Solution {
 public:
//     //searching for trie....found this rather as dp question!!
//     bool wordBreak(string s, vector<string>& w) {
//         vector<char> dp(s.size(),-1);
//         set<string> st(w.begin(),w.end());
//         return fun(0,s,st);
//     }
//     bool fun(int ind,string &s,set<string> &st){
//         if(ind==s.size())return 1;
//         return 0;
//     }

 // bool wordBreak(string s, vector<string>& w) {
 //        vector<char> mem(s.size(),-1);
 //     unordered_set<string> st(w.begin(),w.end());
 //        return canBrk(0,s,st,mem);    
 //    }
 //    bool canBrk(int start, string& s, unordered_set<string>& wordDict,vector<char>& mem) {
 //        int n = s.size();
 //        if(start == n) return 1;
 //        if(mem[start]!= -1) return mem[start];
 //        string sub;
 //        for(int i = start; i<n; i++) if(wordDict.count(sub+=s[i]) && canBrk(i+1,s,wordDict,mem)) return mem[start] = 1; 
 //        return mem[start] = 0;
 //    }
 // };
    
    bool solve(string s , unordered_set<string> &st , map<string , bool> &dp) {
        if (st.find(s) != st.end())  return true ; 
        if (!s.size()) return false ; 
        if (dp.find(s) != dp.end())  return dp[s] ; 
        
        for (int i = 1 ; i < s.size() ; i++) {
            string left = s.substr(0,i) ;
            if (st.count(left)) {
                if (solve(s.substr(i) , st , dp)) return dp[s] = true ; 
            }
        } 
        return dp[s] = false ; 
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st ;
        map<string , bool> dp ; 
        for (auto it: wordDict) st.insert(it) ; 
        return solve(s, st , dp) ; 
    }
};