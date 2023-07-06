//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        int ans = 0;
        int left[N];
        int right[N];
        left[0] = A[0];
        right[N-1] = A[N-1];
        for(int i=1; i<N; i++)
        {
            left[i] = min(A[i], left[i-1]);
        }
        for(int j=N-2; j>=0; j--)
        {
            right[j] = max(right[j+1], A[j]);
        }
        int i=0; 
        int j=0;
        while(i<N && j<N)
        {
            if(left[i] <= right[j])
            {
                ans = max(ans, j-i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends