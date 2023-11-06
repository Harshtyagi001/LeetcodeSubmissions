//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int solve(vector<int>&arr,int low,int high){
        int pivot=low;
        int i=low;
        int j=high;
        while(i<j){
            while(i<=high and arr[i]<=arr[pivot])i++;
            while(j>=low and arr[j]>arr[pivot])j--;
            if(i<j)swap(arr[i],arr[j]);
        }
        swap(arr[pivot],arr[i-1]);
        return i-1;
    }
    
    void quickSort(vector<int>&arr,int st,int end){
        // for(auto i:arr)cout<<i<<"  ";
        // cout<<endl;
        // cout<<"st: "<<st<<"   end: "<<end<<endl;
        if(st>=end)return;
        int partition=solve(arr,st,end);
        // cout<<"partition: "<<partition<<endl;
        quickSort(arr,st,partition-1);
        quickSort(arr,partition+1,end);
    }
    
    vector<int> sortArr(vector<int>arr, int n){
        // quick sort
        quickSort(arr,0,n-1);
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends