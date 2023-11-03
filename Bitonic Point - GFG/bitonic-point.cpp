//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int low=0,high=n-1;
	    while(low<high){
	        int mid=low+(high-low)/2;
	        int lft=(mid-1>=0)?arr[mid-1]:-1;
	        int rgt=(mid+1<n)?arr[mid+1]:-1;
	        if(arr[mid]>lft and arr[mid]>rgt)return arr[mid];
	        else{
	            if(rgt>lft)low=mid+1;
	            else high=mid;
	        }
	    }
	    return arr[low];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends