//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        int lowA=0,highA=n-1;
        int lowB=0,highB=n-2;
        
        while(lowA<highA){
            int midB=lowB+(highB-lowB)/2;
            int midA=lowA+(highA-lowA)/2;
            // cout<<lowA<<"  "<<highA<<"      "<<lowB<<" "<<highB<<endl;
            // cout<<"midA: "<<midA<<"   midB: "<<midB<<endl;
            if(a[midA]<b[midB]){
                // cout<<"goes left"<<endl;
                highB=midB;
                highA=midA;
            }
            else if(b[midB]==a[midA]){
                // cout<<"equal Then: "<<endl;
                // if no. of elements in the left side are same then go right 
                if(midA==midB){
                    // cout<<"goes right"<<endl;
                    lowA=midA+1;
                    lowB=midB+1;
                }
                // otherwise left
                else {
                    // cout<<"goes left"<<endl;
                    highA=midA;
                    highB=midB;
                }
            }
            else{
                // cout<<"goes right"<<endl;
                lowB=midB+1;
                lowA=midA+1;
            }
        }
        return (a[lowA]!=b[lowB])?lowA:lowA-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends