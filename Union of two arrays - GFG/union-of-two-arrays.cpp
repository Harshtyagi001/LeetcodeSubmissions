//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        sort(a,a+n);
        sort(b,b+m);
      vector<int>v;
      v.push_back(-1);
      int i=0,j=0;
      while(i<n and j<m){
          if(a[i]<b[j]){
              if(v.back()<a[i])v.push_back(a[i]);
              i++;
          }
          else if(a[i]==b[j]){
              if(v.back()<a[i])v.push_back(a[i]);
              i++; j++;
          }
          else{
              if(v.back()<b[j])v.push_back(b[j]);
              j++;
          }
      }
      while(i<n){
          if(v.back()<a[i])v.push_back(a[i]);
          i++;
      }
      while(j<m){
          if(v.back()<b[j])v.push_back(b[j]);
          j++;
      }
      return v.size()-1;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends