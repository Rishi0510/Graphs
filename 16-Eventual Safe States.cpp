//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfsCheck(int node,vector<int>adj[],int vis[],int vispath[],
    int check[])
    {
        check[node] = 1;
        vis[node] = 1;
        vispath[node] = 1;
        
        for(auto it : adj[node])
        {
            if(vis[it] == 0)
            {
                if(dfsCheck(it,adj,vis,vispath,check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(vispath[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        vispath[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int vispath[V] = {0};
        
        vector<int>safeNodes;
        int check[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfsCheck(i,adj,vis,vispath,check);
        }
        
        for(int i=0;i<V;i++)
        if(check[i] == 1) safeNodes.push_back(i);
        
        return safeNodes;
        
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
