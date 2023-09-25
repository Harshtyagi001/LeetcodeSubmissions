class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        stack<int>st;
        vector<int>left,right;
        
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
            int val=st.empty()?0:st.top()+1;
            left.push_back(i-val);
            st.push(i);
        }
        // for(auto i:left)cout<<i<<"  ";
        // cout<<endl;
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--){
             while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
            int val=st.empty()?n-1:st.top()-1;
            right.push_back(val-i);
            st.push(i);
        }
        reverse(right.begin(),right.end());
        // for(auto i:right)cout<<i<<"  ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(left[i]+right[i]+1)*nums[i]);
        }
        return maxi;
    }
};