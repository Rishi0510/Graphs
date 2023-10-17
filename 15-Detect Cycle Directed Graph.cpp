//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,vector<int>adj[],int vis[],int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1; 
        // ye dfs tabhi call hua hoga jab vis nahi hoga
        //adj nodes
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        
        //wapas ate time pathVis ko 0 kardena
        pathVis[node] = 0;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            if(dfs(i,adj,vis,pathVis) == true) return true;
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends