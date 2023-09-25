class Solution {
public:
//     int totalStrength(vector<int>& str) {
//         int n=str.size();
//         vector<int>pre(n,0);
//         pre[0]=str[0];
//         for(int i=1;i<n;i++)pre[i]=pre[i-1]+str[i];
//         vector<int>preOfpre(n,0);
//         preOfpre[0]=pre[0];
//         for(int i=1;i<n;i++)preOfpre[i]=preOfpre[i-1]+pre[i];
//         vector<int>left,right;
//         stack<int>l,r;
        
//         for(int i=0;i<n;i++){
//             while(!l.empty() and str[l.top()]>=str[i])l.pop();
//             int val=l.empty()?-1:l.top();
//             left.push_back(val);
//             l.push(i);
//         }
//         // for(auto i:left)cout<<i<<"   ";
//         // cout<<endl;
//         for(int i=n-1;i>=0;i--){
//             while(!r.empty() and str[r.top()]>str[i])r.pop();
//             int val=r.empty()?n:r.top();
//             right.push_back(val);
//             r.push(i);
//         }
//         reverse(right.begin(),right.end());
//         // for(auto i:right)cout<<i<<"   ";
//         // cout<<endl;
        
//         int ans=0;
        
//         for(int i=0;i<n;i++){
//             int l_sz=i-left[i];
//             int r_sz=right[i]-i;
//             int x=(i-1>=0)?preOfpre[i-1]:0;
//             int y=(left[i]==-1)?0:preOfpre[left[i]];
//             int val= l_sz*(preOfpre[right[i]-1] - x) - r_sz*(x - y);
            
//             ans+=(str[i]*val);
//         }
        
//         return ans;
//     }
    
    int totalStrength(vector<int>& st) {
    long long MOD = 1000000007;
    const int N = st.size();
    // sum of first k elements
    vector<long long> prefix(N + 1, 0L);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = (prefix[i] + st[i]) % MOD;
    }
    // sum of first k prefix
    vector<long long> prefix_sum(N + 2, 0L);
    for (int i = 0; i <= N; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
    }
    
    // first index on the left < current st
    vector<int> left(N, -1);
    // mono increase
    vector<int> stack;
    for (int i = 0; i < N; ++i) {
        while (!stack.empty() && st[stack.back()] >= st[i]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    
    // first index on the right <= current st
    vector<int> right(N, N);
    stack.clear();
    for (int i = N - 1; i >= 0; --i) {
        while (!stack.empty() && st[stack.back()] > st[i]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? N : stack.back();
        stack.push_back(i);
    }
    
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        res += ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD + MOD * 2 - 
               (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD) % MOD * st[i] % MOD;
        res %= MOD;
    }
    return (int) res;
}
    
};
