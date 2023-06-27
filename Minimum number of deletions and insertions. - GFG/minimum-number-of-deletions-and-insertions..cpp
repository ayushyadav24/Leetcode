//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(string s1, string s2)
	{
	    int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // base case
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0; j<=m; j++)
        {
            dp[0][j] = 0;
        }
        
        // explore all paths
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
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