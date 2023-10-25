//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  private:
  int helper(int n)
  {
      if(n==0)
        return 0;
        
      if(n%2 == 0)
        return 1 + helper(n/2);
      else
        return 1 + helper(n-1);
  }
  public:
    int minOperation(int n)
    {
        //code here.
        if(n==1)
            return 1;
        return helper(n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends