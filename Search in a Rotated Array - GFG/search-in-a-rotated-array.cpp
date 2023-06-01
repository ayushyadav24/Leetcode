//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int s, int e, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        if(s>e)
            return -1;
            
        int mid = s + (e-s)/2;
        if(arr[mid] == key)
            return mid;
            
        // for lhs that is sorted
        if(arr[s] <= arr[mid])
        {
            if(key >= arr[s] && key <= arr[mid])
            {
                return search(arr, s, mid-1, key);
            }
            else
                return search(arr, mid+1, e, key);
        }
        
        // for second half that is rhs
        if(key >= arr[mid] && key <= arr[e])
            return search(arr, mid+1, e, key);
        else
            return search(arr, s, mid-1, key);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends