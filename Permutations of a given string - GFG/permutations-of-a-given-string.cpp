//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<string> permutation(string ans, string input)
	{
	    if(input.empty())
	    {
	        vector<string>temp;
	        temp.push_back(ans);
	        return temp;
	    }
	    unordered_set<string>unique;
	    char ch=input[0];
	    for(int i=0; i<= ans.length(); i++)
	    {
	        string f = ans.substr(0, i);
	        string e = ans.substr(i, ans.length()-i);
	        vector<string> sub = permutation(f+ch+e, input.substr(1));
	        
	        for(string str : sub)
	        {
	            unique.insert(str);
	        }
	    }
	    vector<string>res(unique.begin(), unique.end());
	    return res;
	}
		vector<string>find_permutation(string S)
		{
		    vector<string>ans = permutation("", S);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends