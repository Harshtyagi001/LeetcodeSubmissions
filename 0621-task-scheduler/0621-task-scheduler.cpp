class Solution {
public:
  
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int>mp;
        for(auto t:tasks){
            mp[t]++;
        }
        vector<int>vec;
        for(auto i:mp)vec.push_back(i.second);
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        cout<<vec[0]-1<<endl;
        int ideal=(vec[0]-1)*n;
        
        for(int i=1;i<vec.size();i++){
            ideal-=(min(vec[0]-1,vec[i]));
        }
        return max(ideal+tasks.size(),tasks.size());
    }
};