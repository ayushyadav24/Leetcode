//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
       vector<int>ans;
       // storing index where wifi supply is there
       for(int i=0; i<N; i++)
       {
           if(S[i]=='1')
           {
               ans.push_back(i);
           }
       }
       
       // check for condition 1 that is if ans + 1 and ans - 1 > x than return false
       for(int i=0; i<ans.size()-1; i++)
       {
           if(ans[i+1]-ans[i]-1 > 2*X)
           {
               return false;
           }
       }
       
       // condition 2 first supply is > X
       if(ans[0]>X)
       {
           return false;
       }
       
       // condition 3 first and last supply
       if(N-1 - ans[ans.size()-1] > X)
       {
           return false;
       }
       
       return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends