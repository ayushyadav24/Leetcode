//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int linearSearch(int arr[], int n, int target, int i)
    {
         if(arr[i] == target)
            return i;
            
        // base condition
        if(i == n-1)
            return -1;
        return linearSearch(arr, n, target, i+1);
    }
    int search(int arr[], int N, int X)
    {
        // Your code here
        return linearSearch(arr, N, X, 0);
    }

};

//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends