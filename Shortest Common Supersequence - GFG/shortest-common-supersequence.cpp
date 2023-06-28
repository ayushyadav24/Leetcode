//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int utility(string s1, string s2,int ind1,int ind2, vector<vector<int>> &dp)
    {
        // base case
        if(ind1 == 0 || ind2 == 0)
            return 0;
            
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        // char matching
        if(s1[ind1-1] == s2[ind2-1])
            return dp[ind1][ind2] = 1 + utility(s1, s2, ind1-1, ind2-1, dp);
        
        return dp[ind1][ind2] = max(utility(s1, s2, ind1-1, ind2, dp), utility(s1, s2, ind1, ind2-1, dp));
    }
    int lcs(string s1, string s2, int m, int n)
    {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        vector<
        for(int i=0; i<=m; i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++)
        {
            dp[0][j] = 0;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int total = n+m;
        int llcs = lcs(X, Y, m, n);
        return total - llcs;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends