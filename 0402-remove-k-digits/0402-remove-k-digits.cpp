class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            while(!st.empty() and k>0 and st.top()>nums[i]){st.pop(); k--;}
            st.push(nums[i]);
        }
        while(!st.empty() and k--)st.pop();  // if K is remaining
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string finalAns;
        int i=0;
        bool fl=false;
        while(i<ans.size()){
            if(fl==false and ans[i]=='0');
            else {fl=true; finalAns.push_back(ans[i]);}
            i++;
        }
        if(finalAns.size()==0)return "0";
        return finalAns;
    }
};