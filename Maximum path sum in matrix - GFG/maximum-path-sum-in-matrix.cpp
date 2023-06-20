//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        // initialisation
        for(int j=0; j<n; j++)
        {
            dp[0][j] = arr[0][j];
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int ld, rd;
                int s = arr[i][j] + dp[i-1][j];
                ld = arr[i][j];
                if(j-1>=0)
                    ld += dp[i-1][j-1];
                else
                    ld += -1e9;
                rd = arr[i][j];
                if(j+1 < n)
                    rd += dp[i-1][j+1];
                else
                    rd += -1e9;
                dp[i][j] = max(s, max(ld, rd));
            }
        }
        
        int maxi = dp[n-1][0];
        for(int j=1; j<n; j++)
        {
            maxi = max(maxi, dp[n-1][j]);
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