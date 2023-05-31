//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  int BinarySearch(int arr[], int k, int s, int e)
  {
      if(s>e)
      {
          return -1;
      }
      
      int mid = s + (e-s)/2;
      
      if(arr[mid]==k)
      {
          return mid;
      }
      
      if(arr[mid] > k)
      {
          return BinarySearch(arr, k, s, mid-1);
      }
      
      return BinarySearch(arr, k, mid+1, e);
  }
  
    int binarysearch(int arr[], int n, int k) {
        int s=0;
        int e=n-1;
        return BinarySearch(arr, k, s, e);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends