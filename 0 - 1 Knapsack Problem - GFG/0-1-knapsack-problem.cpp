//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>prev(W+1);
       vector<int>curr(W+1);
       
       // base case initialisation
       for(int w = wt[0]; w <= W; w++)
       {
           prev[w] =  val[0];
       }
       
       for(int i=1; i<n; i++)
       {
           for(int w=0; w<= W; w++)
           {
               int np = 0 + prev[w];
               int p = INT_MIN;
               if(w >= wt[i])
                    p = val[i] + prev[w-wt[i]];
                curr[w] = max(p, np);
           }
           prev = curr;
       }
       
       return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends