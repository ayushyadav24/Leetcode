//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <cmath>
class Solution
{
	public:
	
	    long long int reverse(long long int n, int digits)
	    {
	        if(n%10 == n)
	            return n;
	            
	        return (n%10) * pow(10, digits-1) + reverse(n/10, digits-1);
	    }
	
		long long int reverse_digit(long long int n)
		{
		    int digits = (int)(log10(n)+1);
		    return reverse(n, digits);
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