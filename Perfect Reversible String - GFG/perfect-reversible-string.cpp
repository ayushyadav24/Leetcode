//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    int isReversible(string str, int n) { 
         //complete the function here
         string temp = str;
         reverse(temp.begin(), temp.end());
         if(temp == str)
            return 1;
         else
            return 0;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.isReversible(s, n) << endl;
    }
return 0;
}


// } Driver Code Ends