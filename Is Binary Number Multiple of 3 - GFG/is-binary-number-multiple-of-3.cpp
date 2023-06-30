//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int sum=0;
	    int temp=1;
	    int n = s.length();
	    for(int i=n-1; i>=0; i--)
	    {
	        if(s[i] - '0' == 1)
	        {
	            sum = (sum + temp)%3;
	        }
	        temp = (temp * 2)%3;
	    }
	    if(sum == 0)
	        return 1;
	    else
	        return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends