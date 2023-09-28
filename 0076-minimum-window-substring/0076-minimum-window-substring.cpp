class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpt,mps;
        for(auto ch:t)mpt[ch]++;
        int i=0,j=0;
        string ans;
        int mini=INT_MAX;
        pair<int,int>minPr;
        while(j<=s.size()){
          if(j-i<t.size() or mps.size()<mpt.size()){mps[s[j]]++; j++;} // map ka size hi kam hai
          else{
              bool inc=false;  // check ki j increment krna hai ya nahi
              int ct=0;
              for(auto i:mpt){
                  int actual=i.second;
                  int get=0;
                  if(mps.find(i.first)!=mps.end())get=mps[i.first];
                  if(get<actual){
                      inc=true;
                      break;
                  }
                  else if(get>=actual)ct++;  // ki saari values cover hogyi
              }
              if(inc==true){if(j==s.size())break; mps[s[j++]]++;}  // saari values cover nahi hui toh j bdhao
              else if(ct==mpt.size()){  // sari values aagyi tp min window find karo
                  if(j-i<mini){
                      mini=j-i;
                      minPr={i,j};  // update if minimum
                  }
                 //   if(mps.size()>=mpt.size()){  // is condition li surity hai
                           mps[s[i]]--;
                           if(mps[s[i]]==0)mps.erase(mps[s[i]]);
                           i++;
                 //   }
              }
          }
        }
        return s.substr(minPr.first,minPr.second-minPr.first);   // to avoid memory leekage instead of making str each time I store th etsarting and endking index in pair
    }
};