//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // sort both arrays
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        // create 4 vectors to store even and odd elements separately
        vector<int>aOdd, aEven, bOdd, bEven;
        long long sum=0 , ans=0;
        for(int i=0; i<N; i++)
        {
            sum = sum + (A[i]-B[i]);
            if(A[i]%2!=0)
                aOdd.push_back(A[i]);
            else
                aEven.push_back(A[i]);
                
            if(B[i]%2!=0)
                bOdd.push_back(B[i]);
            else
                bEven.push_back(B[i]);
        }
        
        if(sum!=0 || aOdd.size() != bOdd.size())
        {
            return -1;
        }
        
        // process for odd
        for(int i=0; i<aOdd.size(); i++)
        {
            ans = ans + (abs(aOdd[i]-bOdd[i])/2);
        }
        
         // process for evem
        for(int i=0; i<aEven.size(); i++)
        {
            ans = ans + (abs(aEven[i]-bEven[i])/2);
        }
        
        return ans/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends