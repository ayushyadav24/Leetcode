//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool Sort(int arr[], int index, int n)
    {
        // base condition
        if(index == n-1)
            return true;
            
        return arr[index] <= arr[index + 1] && Sort(arr, index+1, n);
    }
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        return Sort(arr, 0, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends