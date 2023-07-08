//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <algorithm> // Include the <algorithm> header for the sort function

class Solution {
public:
    int missingNumber(int arr[], int n) {
        sort(arr, arr + n); // Sort the array in ascending order

        int ans = 1; // Initialize the answer to the smallest positive number

        // Find the smallest positive number missing from the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == ans) {
                ans++; // Increment the answer if the current element matches
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends