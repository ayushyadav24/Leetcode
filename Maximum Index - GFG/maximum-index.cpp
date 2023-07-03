//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int ans = INT_MIN;
        // two arrays to store maximum and minimum
        int right[n];
        int left[n];
        
        right[n-1] = arr[n-1];
        left[0] = arr[0];
        
        // left i.e small
        for(int i = 1; i < n; i++)
        {
            left[i] = min(left[i-1], arr[i]);  
        }
        
        // right i.e large
        for(int j = n-2; j >= 0; j--)
        {
            right[j] = max(right[j+1], arr[j]);
        }
        
        int i = 0;
        int j = 0;
        while(i<n && j<n)
        {
            if(left[i] <= right[j])
            {
                ans = max(ans, j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends