//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int>adjRev[V];
        int indegree[V] = {0};
         for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        // kahns algo for topo sort
        queue<int>q;
        vector<int>topo;
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it : adjRev[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends