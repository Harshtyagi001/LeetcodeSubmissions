//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        vector<long long>pre(N,0);
        pre[0]=A[0];
        for(int i=1;i<N;i++){
            pre[i]=A[i]+pre[i-1];
        }
        long long i=0,j=0;
        long long ans=0;
        long long sum=0;
        while(j<=N){
            if(sum<L){
                sum+=A[j];
                j++;
            }
            else if(sum>=L and sum<=R){
                ans++;
                long long lost=(i==0)?0:pre[i-1];
                long long val=sum-L+lost;
                long long ind=upper_bound(pre.begin(),pre.end(),val)-pre.begin();
                ind--;
                if(ind>=i){
                    ans+=(ind-i+1);
                }
               if(j<N) sum+=A[j];
                j++;
            }
            else {
                while(sum>R){
                sum-=A[i];
                i++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends