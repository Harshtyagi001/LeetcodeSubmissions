class Solution {
public:
    
int solve(unordered_map<int,vector<int>>&mp,int crr,unordered_map<int,unordered_map<int,int>>&chk,int hash,int n,vector<vector<int>>&dp){
    // cout<<"crr: "<<crr<<endl;
    // cout<<"hash and 1<<n:  "<<hash<<"   "<<(1<<n)-1<<endl;
        if(hash==(1<<n)-1){return 1;}
        if(dp[crr][hash]!=-1)return dp[crr][hash];
        int mini=INT_MAX;
        
        for(auto x:mp[crr]){
            // cout<<"x:  "<<x<<endl;
            if(chk[crr][x]==0){
                // cout<<"enter"<<endl;
                chk[crr][x]=1;
                mini=min(mini,solve(mp,x,chk,hash|(1<<x),n,dp));
                chk[crr][x]=0;
            }
        }
         // cout<<"mini:  "<<mini<<endl;
        return dp[crr][hash]= mini==INT_MAX?mini:mini+1;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>mp;
        int n=graph.size();
        for(int i=0;i<n;i++){
            for(auto j:graph[i])mp[i].push_back(j);
        }
        int ans=INT_MAX;
        for(auto i:mp){
            unordered_map<int,unordered_map<int,int>>chk;
            vector<vector<int>>dp(graph.size()+1,vector<int>((1<<13),-1));
            int val=solve(mp,i.first,chk,(1<<i.first),graph.size(),dp);
            // cout<<"val: "<<i.first<<"  :  "<<val<<endl;
            if(val!=INT_MAX)val--;
            ans=min(ans,val);
        }
        
        return ans==INT_MAX?0:ans;
    }
};