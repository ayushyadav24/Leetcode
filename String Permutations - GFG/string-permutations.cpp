//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
     vector<string> permutationRet(string ans, string input)
	    {
	       
	        if(input.empty())
            {
                vector<string>temp;
                temp.push_back(ans);
                return temp;
            }

            vector<string>res;
            char ch = input[0];
        
            for (int i = 0; i <= ans.length(); i++)
            {
                string f = ans.substr(0, i);
                string e = ans.substr(i, ans.length()-i);
                vector<string> sub = permutationRet(f+ch+e, input.substr(1));
                res.insert(res.end(), sub.begin(), sub.end());
            }
            return res;
	    }
	    
    vector<string> permutation(string S)
    {
         vector<string>ans = permutationRet("", S);
		 sort(ans.begin(), ans.end());
		  return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends