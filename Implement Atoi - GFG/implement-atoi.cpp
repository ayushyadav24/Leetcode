//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int sign=1;
        if(s[0] == '-')
            sign = -1;
            
        int ans = 0;
        int i=0;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        while(i < s.length())
        {
            if(!isdigit(s[i]))
                return -1;
                
            ans = ans*10 + s[i]-'0';
            i++;
        }
        return (sign)*ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends