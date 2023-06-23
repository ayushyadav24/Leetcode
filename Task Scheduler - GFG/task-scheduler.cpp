//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        // code here
        int arr[26]={0};
        int maxF = 0; // maximum no of frquency
        int maxFc = 0; // maximum no of characters with max frequency
        for(char task : tasks)
        {
            arr[task - 'A']++;
        }
        for(int x : arr)
        {
            if(maxF == x)
                maxFc++;
            if(maxF < x)
            {
                maxF = x;
                maxFc = 1;
            }
        }
        
        int gaps = maxF - 1;
        int gap_len = k - (maxFc - 1);
        int avail_slot = gaps * gap_len;
        int avail_task = N - maxF * maxFc;
        int idle = max(0, avail_slot-avail_task);
        return N+idle;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends