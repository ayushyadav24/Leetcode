//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
         if(a==b)
            return false;
         if(a==1 && b == 3 || a==3 && b==1)
            return false;
         else
            return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}
// } Driver Code Ends