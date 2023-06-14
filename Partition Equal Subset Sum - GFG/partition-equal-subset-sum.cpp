//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool subsetSum(int arr[], int n, long long sum)
    {
        if(sum == 0)
            return true;
        if(n==0 && sum !=0)
            return false;
            
        if(arr[n-1] > sum)
            return subsetSum(arr, n-1, sum);
        
        return subsetSum(arr, n-1, sum - arr[n-1]) || subsetSum(arr, n-1, sum);
    }
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
        }
        if(sum % 2 != 0)
            return false;
            
        if(sum % 2 == 0)
        {
            return subsetSum(arr, N, sum/2);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends