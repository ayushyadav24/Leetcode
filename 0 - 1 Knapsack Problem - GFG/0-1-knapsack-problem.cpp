//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int func(int ind, int wt[], int val[], int W, vector<vector<int>> &dp)
    {
        // base case
        if(ind==0)
        {
            if(W >= wt[0])
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        // two option pick not pick
        int notPick = 0 + func(ind-1, wt, val, W, dp);
        int pick = INT_MIN;
        if(W >= wt[ind])
        {
            pick = val[ind] + func(ind-1, wt, val, W-wt[ind], dp);
        }
        
        return dp[ind][W] = max(notPick, pick);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n, vector<int>(W+1, -1));
       return func(n-1, wt, val, W, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends