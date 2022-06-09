// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int  ans=0;
	   long long prefix=0;
	   int low=0,high=0;
	   while(high<n ){
	       prefix+=arr[high];
	       if(prefix>sum){
	           while(prefix>sum){
	           prefix-=arr[low];
	           low++;
	         }
	       }
	       ans=max(ans,(int)prefix);
	       high++;
	   }
	   return ans;
	}  

};
	  



// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends