//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int Count(int arr[], int n, int tar, int i)
	{
	    int cnt=0;
	    if(i==n)
	        return cnt;
	        
	   if(arr[i] == tar)
	        cnt++;
	        
	  return cnt + Count(arr, n, tar, i+1);
	}
	int count(int arr[], int n, int x) {
	    // code here
	   return Count(arr, n, x, 0);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends