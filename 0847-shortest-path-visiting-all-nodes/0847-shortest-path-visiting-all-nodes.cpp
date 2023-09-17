class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // track visited path and node
        vector<vector<bool>>visited(n,vector<bool>(1<<n,false));
        queue<pair<int,int>>Q;
        // push all nodes and masks initially into queue and also mark visited
        for(int i=0;i<n;i++)
        {
            Q.push({i,(1<<i)});
            visited[i][(1<<i)] = true;
        }
        
        int finalVal = (1<<n)-1;
        int dist=-1;
        // BFS travers in level order 
        while(!Q.empty())
        {
            int s = Q.size();
            dist++;
            while(s--)
            {
               int node = Q.front().first;
               int mask = Q.front().second;
                Q.pop();
                
                // all nodes visited then return path length
                if(mask == finalVal)return dist;
                
                // look at the mask of all neighbor nodes
                for(int &adj: graph[node])
                {
                    // update mask as neighbor node visited
                   int nextMask = mask | 1<<adj;
                    
                    // if neighbor node visited array contains updated mask then ignore to avoid cycle
                    if(visited[adj][nextMask]==0){
                    visited[adj][nextMask] = true;
                    Q.push({adj,nextMask});
                    }
                }
            }
        }
        
        return dist;
    }
};