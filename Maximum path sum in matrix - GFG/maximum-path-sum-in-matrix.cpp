//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp)
    {
        // BASE CASES
        //1 OUT OF BOUND CASE
        if(j<0 || j>=n)
            return -1e9;
        
        //2 DESTINATION
        if(i==0)
            return arr[i][j];
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // EXPLORE ALL PATHS
        int s = arr[i][j] + helper(i-1, j, arr, n, dp);
        int ld = arr[i][j] + helper(i-1, j-1, arr, n, dp);
        int rd = arr[i][j] + helper(i-1, j+1, arr, n, dp);
        
        return dp[i][j] = max(s, max(ld, rd));
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int maxi = INT_MIN;
        for(int j=0; j<n; j++)
        {
            maxi = max(maxi, helper(n-1, j, matrix, n, dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends