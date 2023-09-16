class Twitter {
public:
    int timer;
    unordered_map<int,unordered_set<int>>mp;
    unordered_map<int,vector<pair<int,int>>>mpq;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mpq[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int sz=10;
        priority_queue<pair<int,vector<int>>>pq;
        vector<int>ans;
        int ind=mpq[userId].size()-1;
        if(ind>=0)pq.push({mpq[userId][ind].first,{mpq[userId][ind].second,userId,ind}});
        for(auto user:mp[userId]){
            cout<<user<<endl;
            if(mpq[user].size()>0){
                int index=mpq[user].size()-1;
               if(index>=0){
         pq.push({mpq[user][index].first,{mpq[user][index].second,user,index}});
               }
            }
        }
        while(!pq.empty() and sz--){
            auto top=pq.top();
            vector<int>temp=top.second;
            int user=temp[1];
            int ind=temp[2];
            pq.pop();
            ans.push_back(temp[0]);
            if(ind-1>=0){
            pq.push({mpq[user][ind-1].first,{mpq[user][ind-1].second,user,ind-1}});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       if(mp[followerId].find(followeeId)!=mp[followerId].end()) mp[followerId].erase(mp[followerId].find(followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */