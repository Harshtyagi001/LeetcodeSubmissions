class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() and st.top()>nums[i] and n-i+st.size()>k)st.pop();
            st.push(nums[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        vector<int>finalAns;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<k;i++)finalAns.push_back(ans[i]);
        return finalAns;
    }
};