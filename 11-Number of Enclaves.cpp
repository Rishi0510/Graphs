class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // pushing the lands on boundaries in queue
                if(i==0 || i == n-1 || j == m || j == m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow < n && nrow >=0 && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && 
                grid[nrow][ncol] == 1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0) ++cnt;
            }
        }
        return cnt;
    }
};
