//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int utility(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        // base case i.e on reaching last row
        int n = triangle.size();
        if(i == n-1)
        {
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // two possible movements
        int down = triangle[i][j] + utility(i+1, j, triangle, dp);
        int dia = triangle[i][j] + utility(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, dia);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        // vector<vector<int>>dp(n, vector<int>(n, 0));
        vector<int>next(n, 0);
        // initialise
        for(int j=0; j<n; j++)
        {
            next[j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int>curr(n, 0);
            for(int j=n-2; j>=0; j--)
            {
                int down = triangle[i][j] + next[j];
                int dia = triangle[i][j] + next[j+1];
                curr[j] = min(down, dia);
            }
            next = curr;
        }
        
        return next[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends