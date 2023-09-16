class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mp;
        for(auto h:hand)mp[h]++;
        int ct=0;
        while(ct<hand.size()){
            int sz=groupSize;
            int prev=-1;
            for(auto i:mp){
                cout<<"prev: "<<prev<<endl;
                cout<<i.first<<"   "<<i.second<<endl;
            if(prev!=-1 and i.first!=prev+1){cout<<"here: "<<prev<<"  "<<prev<<"  "<<i.first<<endl; return false;}
                ct++;
                mp[i.first]--;
                if(mp[i.first]==0){cout<<"erasing: "<<i.first<<endl; mp.erase(i.first);}
                sz--;
                prev=i.first;
                if(sz==0)break;
            }
            if(sz>0){cout<<"szHere: "<<sz<<endl; return false;}
        }
        return true;
    }
};