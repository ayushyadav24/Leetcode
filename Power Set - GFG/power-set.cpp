//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector <string> subseq(string res, string s)
	    {
	        if(s.empty())
	        {
	            vector<string>list;
	            if(!res.empty())
	                list.push_back(res);
	            return list;
	        }
	        char ch = s[0];
	        vector<string>left = subseq(res+ch, s.substr(1));
	        vector<string>right = subseq(res, s.substr(1));
	        
	        // concatenate two vectors
	        left.insert(left.end(), right.begin(), right.end());
	        return left;
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans = subseq("", s);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends