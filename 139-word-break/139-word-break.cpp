 class Solution {
 public:
//     //searching for trie....found this rather as dp question!!
  
   
 bool wordBreak(string s, vector<string>& w) {
        vector<char> mem(s.size(),-1);
     unordered_set<string> st(w.begin(),w.end());
        return canBrk(0,s,st,mem);    
    }
    bool canBrk(int start, string& s, unordered_set<string>& wordDict,vector<char>& mem) {
        int n = s.size();
        if(start == n) return 1;
        if(mem[start]!= -1) return mem[start];
        string sub;
        for(int i = start; i<n; i++) if(wordDict.count(sub+=s[i]) && canBrk(i+1,s,wordDict,mem)) return mem[start] = 1; 
        return mem[start] = 0;
    }
 };
    
   