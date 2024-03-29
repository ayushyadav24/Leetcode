//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int utility(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        int mod = 1e9+7;
        // base case
        if(i == 0 && j == 0 && grid[i][j] == 0)
            return 1;
        
        if(i < 0 || j < 0 || grid[i][j] == 1)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = 0;
        int left = 0;
        if(grid[i][j] == 0)
        {
            up = utility(i-1, j, grid, dp);
            left = utility(i, j-1, grid, dp);
        }
        return dp[i][j] = (up + left)%mod;;
    }
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        int mod = 1e9+7;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i== 0 && j == 0 && grid[i][j] == 0)
                    dp[i][j] = 1;
                
                else if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                     int up = 0;
                    if(i > 0)
                        up = dp[i-1][j];
                    int left = 0;
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = (up + left)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends