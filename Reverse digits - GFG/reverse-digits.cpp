//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	long long int sum = 0;
	    void rev(long long int n)
	    {
	        if(n==0)
	            return;
	       
	        int rem = n%10;
	        sum = sum*10 + rem;
	        rev(n/10);
	    }
		long long int reverse_digit(long long int n)
		{
		    rev(n);
		    return sum;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends