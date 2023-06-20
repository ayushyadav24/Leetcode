//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int i, int j1, int j2,int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        // BASE CASES 
        // OUT OF BOUND CASES
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m )
        {
            return -1e8;
        }
        // DESTINATION
        if(i == n-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = -1e8;
        // EXPLORE ALL PATHS
        for(int dj1 = -1; dj1 <=1; dj1++)
        {
            for(int dj2 = -1; dj2 <= 1; dj2++)
            {
                if(j1 == j2)
                {
                    maxi = max(maxi, grid[i][j1] + helper(i+1, j1+dj1, j2+dj2, m , n, grid, dp));
                }
                else
                {
                    maxi = max(maxi, grid[i][j1]+ grid[i][j2] + helper(i+1, j1+dj1, j2+dj2, m , n, grid, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) 
    {
        // n -> row
        // m -> column
        // dp[n][m][m]
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(0, 0, m-1, m, n, grid, dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends