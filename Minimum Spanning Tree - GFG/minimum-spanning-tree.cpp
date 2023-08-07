//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    // two vectors i.e for rank and parent
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    // creating a constructor
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    };

    // finding ultimate parent
    int findUparent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    // find rank
    void UnionbyRank(int u, int v)
    {
        int up_u = findUparent(u);
        int up_v = findUparent(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v])
            parent[up_u] = up_v;

        else if (rank[up_v] < rank[up_u])
            parent[up_v] = up_u;

        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void UnionbySize(int u, int v)
    {
        int up_u = findUparent(u);
        int up_v = findUparent(v);
        if(up_u == up_v)
            return;

        if(size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>>edges;
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjnode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int mstWt = 0;
        DisjointSet ds(V);
        
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            // belong to same component than we don;t add weight else we do i.e different case
            if(ds.findUparent(u) != ds.findUparent(v))
            {
                mstWt += wt;
                ds.UnionbySize(u, v);
            }
        }
        
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends