class Solution {
public:

    bool findSubstr(string& s,int len){
        int n=s.size();
        int freq[26]={0};
        unordered_map<int,int>ump;
        int i=0;
        int ct=0;
        while(i<n){
           if(i<len){
               freq[s[i]-'a']++; 
               if(freq[s[i]-'a']==len){
                   ump[s[i]-'a']++;
               }
           }
           else{
              freq[s[i-len]-'a']--;
              freq[s[i]-'a']++;
              if(freq[s[i]-'a']==len){
                  ump[s[i]-'a']++;
              }
           }
           i++;
        }
       for(auto &i:ump)if(i.second>2)return true;
        return false;
    }

    int maximumLength(string s) {
        int n=s.size();
        int low=1,high=n;
        int maxi=-1;
        while(low<high){
            int len=low+(high-low)/2;
            cout<<low<<"  "<<high<<"  :  "<<len<<endl;
            bool ct=findSubstr(s,len);
            if(ct==false){high=len; cout<<"left"<<endl;}
            else{
                cout<<"right"<<endl;
            maxi=max(maxi,len);
             low=len+1;
            }
        }
        return maxi;
    }
};