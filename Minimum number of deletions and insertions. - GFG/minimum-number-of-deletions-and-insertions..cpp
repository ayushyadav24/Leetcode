//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int utility(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
	{
	    // base case
	    if(ind1 < 0 || ind2 < 0)
	        return 0;
	        
	   if(dp[ind1][ind2] != -1)
	        return dp[ind1][ind2];
	       
	    // char match
	    if(s1[ind1] == s2[ind2])
	        return dp[ind1][ind2] = 1+utility(ind1-1, ind2-1, s1, s2, dp);
	   
	   // char not matching    
	    return dp[ind1][ind2] = max(utility(ind1-1, ind2, s1, s2, dp), utility(ind1, ind2-1, s1, s2, dp));
	}
	int lcs(string s1, string s2)
	{
	    int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return utility(n-1, m-1, s1, s2, dp);
	}
	int minOperations(string s1, string s2) 
	{
	    int n = s1.length();
        int m = s2.length();
	    int llcs = lcs(s1, s2);
	    int deletion = n - llcs;
	    int insertion = m - llcs;
	    return deletion + insertion;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends