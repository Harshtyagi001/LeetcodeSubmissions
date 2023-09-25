// class Solution {
// public:
//     int maxSumMinProduct(vector<int>& nums) {
//         int n=nums.size();
//         vector<long long>pre(n,0);
//         pre[0]=nums[0];
//         for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
//         stack<int>st; 
        
//         long long maxi=0;
//         for(int i=0;i<n;i++){
//             while(!st.empty() and nums[st.top()]>nums[i]){
//                 int min_idx=st.top();
//                 st.pop();
//                 int x=(st.empty())?0:pre[st.top()];
//                 long long sum=pre[i-1]-x;
//                 maxi=max(maxi,sum*nums[min_idx]);
//             }
//             st.push(i);
            
//         }
//         while(!st.empty()){
//            int top=st.top();
//             st.pop();
//             long long x=st.empty()?0:pre[st.top()];
//             long long sum=pre[n-1]-x;
//             maxi=max(maxi,sum*nums[top]);
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long ans = LONG_MIN;
        vector<long> prefix(nums.size(), 0);
        stack<int> s;
        
        prefix[0] = nums[0];
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0) {
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            while (s.size() && nums[s.top()] > nums[i]) {
                int max_idx = s.top();
                s.pop();
                long its_sum = s.size() ? prefix[i - 1] - prefix[s.top()] : prefix[i - 1];
                ans = max(ans, its_sum * nums[max_idx]);
            }
            s.push(i);
        }
        
        while (s.size()) {
            int max_idx = s.top();
            s.pop();
            long its_sum = s.size() ? prefix[nums.size() - 1] - prefix[s.top()] : prefix[nums.size() - 1];
            ans = max(ans, its_sum * nums[max_idx]);
        }
        
        return ans % 1000000007;
    }
};