//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        int x=A.size()-1;
        int y=B.size()-1;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({A[x]+B[y],{x,y}});
        vector<int>ans;
        unordered_map<int,unordered_map<int,int>>vis;
        vis[x][y]=1;
        while(K--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.first);
            int i=top.second.first;
            int j=top.second.second;
            if(i-1>=0 and !vis[i-1][j]){pq.push({A[i-1]+B[j],{i-1,j}}); vis[i-1][j]=1;}
            
            if(j-1>=0 and !vis[i][j-1]){pq.push({A[i]+B[j-1],{i,j-1}}); vis[i][j-1]=1;}
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends