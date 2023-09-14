// class Solution {
// public:
//     vector<string>res;
//     void solve(map<string,multiset<string>>&mp,map<pair<string,string>,int>&chk,string crr,vector<string>&ans,int size){
//         // cout<<"Map:: "<<endl;
//         // for(auto i:chk){
//         //     cout<<i.first.first<<"  "<<i.first.second<<"     "<<i.second<<endl;
//         // }
//         if(chk.size()==0){
//             for(auto i:ans)res.push_back(i);
//             return;
//         }
        
//         for(auto x:mp[crr]){
//             // cout<<"crr and x:  "<<crr<<"   "<<x<<endl;
//             if(chk[{crr,x}]==1){
//                 // cout<<"enter"<<endl;
//                 chk.erase({crr,x});
//                 ans.push_back(x);
//                 solve(mp,chk,x,ans,size);
//                 chk[{crr,x}]=1;
//                 ans.pop_back();
//             }
//         }
//         // cout<<"not found...."<<endl;
//     }
    
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         map<pair<string,string>,int>chk;
//         map<string,multiset<string>>mp;
//         for(auto t:tickets){
//             mp[t[0]].insert(t[1]);
//             chk[{t[0],t[1]}]=1;
//         }
//         vector<string>ans;
//         ans.push_back("JFK");
//         int size=tickets.size();
//         solve(mp,chk,"JFK",ans,size);
//         return res;
//     }
// };

class Solution {
private:
    bool dfs(unordered_map<string,vector<string>>& m, vector<string>& res, string s, int n) {
        if(res.size() == n+1) return true;
        if(m[s].size() == 0) return false;

        for(int i = 0; i < m[s].size(); i++) {
            string temp = m[s][i];
            res.push_back(temp);
            m[s].erase(m[s].begin() + i);
            bool x = dfs(m, res, temp, n);

            if(x) return true;
            m[s].insert(m[s].begin()+i, temp);
            res.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end());
        unordered_map<string,vector<string>> m;

        for(int i = 0; i < n; i++) {
            m[tickets[i][0]].push_back(tickets[i][1]);
        }

        vector<string> res;
        res.push_back("JFK");
        bool x = dfs(m, res, "JFK", n);
        return res;
    }
};