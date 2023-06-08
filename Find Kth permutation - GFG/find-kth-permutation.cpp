//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        int fact = 1;
        vector <int> num;
        for(int i = 1; i < n; i++)
        {
            fact = fact * i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k = k-1;
        while(true)
        {
            ans = ans + to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
            {
                break;
            }
            k=k%fact;
            fact = fact / num.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends