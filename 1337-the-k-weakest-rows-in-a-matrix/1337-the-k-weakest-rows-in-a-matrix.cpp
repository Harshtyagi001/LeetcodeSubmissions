class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int ct=0;
            for(auto j:mat[i]){
                if(j==1)ct++;
            }
            pq.push({ct,i});
        }
        vector<int>ans;
        while(k-- and !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};