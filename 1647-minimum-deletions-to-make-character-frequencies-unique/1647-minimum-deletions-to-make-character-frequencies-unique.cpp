class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int> v(26,0);
        for (int i=0;i<n;i++){
           
            v[s[i]-'a']++;
        }
        int result=0;
        sort(v.begin(),v.end(),greater<int> ());
        int maxi=v[0];
      for(int i=1;i<26;i++){
          while(v[i]>=maxi) {
              if(v[i]>0){
                  v[i]--;
                  result++;
              }
              else{
                  break;
              }
          }
          maxi=v[i];
      }
       
        return result;
    }
    
};