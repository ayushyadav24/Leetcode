//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string helper(string s, int start, int end)
    {
        int n = s.length();
        while(start >= 0 && end < n)
        {
            if(s[start] == s[end])
            {
                start--;
                end++;
            }
            else
            {
                break;
            }
        }
        return s.substr(start+1, end-start-1);
    }
    string longestPalin (string S) {
        int n = S.length();
        int len = 0;
        string ans = "";
        for(int i=0; i<n; i++)
        {
            string curr = helper(S, i, i); // odd
            if(curr.length() > len)
            {
                ans = curr;
                len = curr.length();
            }
            curr = helper(S, i, i+1); // even
            if(curr.length() > len)
            {
                ans = curr;
                len = curr.length();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends