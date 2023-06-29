//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int n)
    {
        if(n==1 || n==7)
            return 1;
        int sum = n;
        int curr = n;
        
        // make sum of square as a single digit number
        while(sum > 9)
        {
            // sum will be zero at start of everyt iteration
            sum = 0;
            
            // find sum of square of digits
            while(curr > 0)
            {
                int d = curr%10;
                sum += d*d;
                curr = curr/10;
            }
            
            // for lines such as 100, 1000, 10, ....
            if(sum == 1)
                return 1;
                
            curr = sum;
        }
        if(sum == 7)
            return 1;
        else
            return 0;
    }
    int nextHappy(int N){
        // code here
        int next = N+1;
        while(true)
        {
            if(isHappy(next) == 1)
                return next;
            next++;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends