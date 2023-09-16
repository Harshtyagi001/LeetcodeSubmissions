class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        for(auto h:hand)mp[h]++;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:mp)pq.push(i.first);
        while(!pq.empty()){
            int top=pq.top();
            cout<<"top: "<<top<<endl;
            int sz=groupSize-1;
            mp[top]--;
            if(mp[top]==0)pq.pop();
            while(sz--){
                if(mp[top+1]==0){cout<<"not exist: "<<top+1<<endl; return false;}
                mp[top+1]--;
                if(mp[top+1]==0){
                    cout<<"become zero: "<<top+1<<endl;
                    int ntop=pq.top();
                    cout<<"ntop: "<<ntop<<endl;
                    if(ntop==top+1){cout<<"equal so pop"<<endl; pq.pop();}
                    else return false;
                } 
                top++;
            }
        }
        return true;
    }
};