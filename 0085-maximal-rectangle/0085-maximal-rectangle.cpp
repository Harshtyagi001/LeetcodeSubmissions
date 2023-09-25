class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(); int m=matrix[0].size();
        vector<vector<int>>pre_mat(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            pre_mat[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int crr=matrix[i][j]-'0';
                pre_mat[i][j]=(crr==0)?0:pre_mat[i-1][j]+crr;
            }
        }
        for(auto i:pre_mat){
            for(auto j:i)cout<<j<<"   ";
            cout<<endl;
        }
        
        int maxi=0;
        stack<int>st;
        vector<int>left,right;
        
        for(int ct=0;ct<n;ct++){
        vector<int>nums=pre_mat[ct];
        for(int i=0;i<m;i++){
            while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
            int val=st.empty()?0:st.top()+1;
            left.push_back(i-val);
            st.push(i);
        }
            
        while(!st.empty())st.pop();
        
        for(int i=m-1;i>=0;i--){
             while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
            int val=st.empty()?m-1:st.top()-1;
            right.push_back(val-i);
            st.push(i);
        }
        reverse(right.begin(),right.end());
            
        while(!st.empty())st.pop();
            
        for(int j=0;j<m;j++){
            maxi=max(maxi,(left[j]+right[j]+1)*pre_mat[ct][j]);
        }
            left.clear();
            right.clear();
        }
        return maxi;
    }
};