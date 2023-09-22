class Solution {
public:
    
    bool solve(string &s,string&t,int i,int j){
        if(i==s.size())return true;
        if(j==t.size())return false;
        
        // same
        bool tk=0,nt=0;
        if(s[i]==t[j])tk=solve(s,t,i+1,j+1);
        else nt=solve(s,t,i,j+1);
        
        return (tk|nt);
    }
    
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};