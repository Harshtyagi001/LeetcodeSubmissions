//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and grid[i][j]==1){
                    // cout<<"pushing... "<<i<<"  "<<j<<endl;
                    q.push({i,j});
                    grid[i][j]=0;
                    
                }
            }
        }
        int rw[4]={1,-1,0,0};
        int cw[4]={0,0,-1,1};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int i=top.first;
            int j=top.second;
            // cout<<i<<"   "<<j<<endl;
            for(int k=0;k<4;k++){
                int nr=i+rw[k];
                int nc=j+cw[k];
                if(nr<n and nr>=0 and nc<m and nc>=0 and grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }
        int ct=0;
        for(auto i:grid){
            for(auto j:i){
                if(j==1)ct++;
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends