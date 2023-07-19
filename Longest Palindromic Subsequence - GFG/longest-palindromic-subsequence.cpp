//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  private:
    int lcs(string s1, string s2)
    {
        // shifting of index
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);
        // base case for initialisation
        for(int j=0; j<=m; j++)
        {
            prev[j] = 0;
        }
        // exploring all paths while copying recurrence
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                // matched condition
                if(s1[i-1]==s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
  public:
    int longestPalinSubseq(string s) {
        //code here
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends