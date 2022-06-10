class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       //       int n=s.size(),res=0;
    // for(int i=0;i<n;i++){
    //     vector <bool > v(256,false);
    //     for(int j=i;j<n;j++){
    //         if(v[s[j]]==true)break;
    //         else{
    //             res=max(res,j-i+1);
    //             v[s[j]]=true;
    //         }
    //     }
    // }return res;

        ///////O(N^2)
       
        
        //HASH MAP APPROCH! SOURCE -PEPCODING
        //THIS IS A O(2N) SOLUTION!
//         int n=s.size();
//        int i=0,j=0,maxi1=0;
//         while(true){
//              bool fun1=false;
            
//           bool fun2=false;         //BOOL TO NOT BREAK THE WHOLE LOOP IN LINE 34!
//             unordered_map<char,int> mp;
//             //acquire 
//             while(i<n){
//                 fun1=true;
                
//                 mp[s[i]]++;
               
//                 if(mp[s[i]]==2){
//                     break;
//                 }
//                 else{
//                     maxi1=max(maxi1,i-j+1);
//                 }
//                  i++;
                
//             }
//             //release
//             while(j<i){
//                 fun2=true;
                
//                 mp[s[j]]--;
//                 if(mp[s[j]]==1){
//                     break;
//                 }
//                 j++;
                
//             }
//             if(!fun1 && !fun2){
//                 break;
//             }
//         }
//         return maxi1;
         
        //first that comes to mind!!..easiest!
        //O(N) SOLUTION!   SOURCE STRIVER!!
        unordered_map<char,int> mpp;
        int low=0;int n=s.size();
        int len=0;
        for(int high=0;high<n;high++){
            if(mpp.find(s[high])!=mpp.end()){
               low=max(low,mpp[s[high]]+1); //increment low by 1!
            }
            mpp[s[high]]=high;
            len=max(len,high-low+1);
            
        }
        return len;
        
    }
};