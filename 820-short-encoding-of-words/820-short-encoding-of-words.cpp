class Solution {
public:
    //description is absolutely not understandable!!
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(),words.end());
        for(auto it:s){
            for(int i=1;i<it.size();i++){
                s.erase(it.substr(i));
            }
        }
        int ans=0;
        for(auto it:s)ans+=it.size()+1;
        return ans;
    }
};