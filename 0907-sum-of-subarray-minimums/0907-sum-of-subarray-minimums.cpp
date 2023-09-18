class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>st1,st2;
        vector<int>left,right;
        int n=arr.size();
        for(int i=0;i<n;i++){
           while(!st1.empty() and st1.top().first>=arr[i]){
               st1.pop();
            }
            int val=(st1.empty())?0:st1.top().second+1;
            left.push_back(i-val);
            st1.push({arr[i],i});
        }
          for(int i=n-1;i>=0;i--){
        while(!st2.empty() and st2.top().first>arr[i]){
            st2.pop();
        }
        int val=(st2.empty())?n-1:st2.top().second-1;
        right.push_back(val-i);
        st2.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    long long ans=0;
    int mod=1e9+7;
    for(int i=0;i<n;i++){
      ans = (ans + (long long)(left[i]+1) * (long long)(right[i]+1) * (long long)arr[i])%mod;
    }
    return ans;
    }
};