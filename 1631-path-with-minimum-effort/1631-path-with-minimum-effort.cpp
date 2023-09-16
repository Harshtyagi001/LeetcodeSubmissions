class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({0,{0,0}});
        int rw[4]={0,1,0,-1};
        int cw[4]={1,0,-1,0};
        map<pair<int,int>,pair<int,int>>parent;
        while(!q.empty()){
            auto it=q.top().second;
            int x=it.first;
            int y=it.second;
            
            int dst=q.top().first;
            // cout<<x<<" "<<y<<" "<<dst<<endl;
            q.pop();
            if(x==n-1 and y==m-1)return dst;
            
            for(int i=0;i<4;i++){
                int nr=x+rw[i];
                int nc=y+cw[i];
                // cout<<"nc< "<<nr<<" "<<nc<<endl;         
                if(nr>=0 and nc>=0 and nr<n and nc<m ){
                    int absDst=abs(heights[nr][nc]-heights[x][y]);
                    if(max(dst,absDst)<dist[nr][nc]){
                    q.push({max(dst,absDst),{nr,nc}});
                        dist[nr][nc]=max(dst,absDst);
                    }
                }
            }
        }
        return -1;
    }
};