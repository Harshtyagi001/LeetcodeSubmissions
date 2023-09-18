class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int low=0,high=mat[i].size()-1;
            while(low<high){
                int mid=low+(high-low)/2;
                if(mat[i][mid]==0)high=mid;
                else low=mid+1;
            }
            low=(mat[i][low]==1)?low+1:low;
            pq.push({low,i});
        }
        vector<int>ans;
        while(k-- and !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};