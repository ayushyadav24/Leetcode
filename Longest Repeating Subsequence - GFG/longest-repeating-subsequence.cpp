//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int utility(string &str, int i, int j, vector<vector<int>> &dp)
        {
            // base case
            if(i == str.length() || j == str.length())
                return 0;
                
            if(dp[i][j] != -1)
                return dp[i][j];
                
            // if character matches
            if(str[i] == str[j] && i != j)
                return dp[i][j] = 1 + utility(str, i+1, j+1, dp);
            
            return dp[i][j] = max(utility(str, i+1, j, dp), utility(str, i, j+1, dp));
        }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    vector<vector<int>> dp(n, vector<int>(n, -1));
		    return utility(str, 0, 0, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends