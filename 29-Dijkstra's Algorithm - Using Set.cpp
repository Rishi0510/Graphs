//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	#define pii pair<int,int>
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pii>st;
        vector<int>dist(V);
        for(int i=0;i<V;i++)
        dist[i] = 1e9;
        
        //src ko insert kardo with 0 dist in array and in set
        // DIST , NODE
        st.insert({0,S});
        dist[S] = 0;
        
        while(!st.empty())
        {
            auto it = *(st.begin()); // top element ko st.befin point krega, star laga ke wo mil jayega
            int dis = it.first;
            int node  = it.second;
            st.erase(it);
            
            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeW = it[1];
                
                if(dis + edgeW < dist[adjNode])
                {
                    //kya ye infinite hai ya nahi
                    if(dist[adjNode] != 1e9)st.erase({dist[adjNode],adjNode});
                    
                    dist[adjNode] = dis + edgeW;
                    st.insert({dis+edgeW,adjNode});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
