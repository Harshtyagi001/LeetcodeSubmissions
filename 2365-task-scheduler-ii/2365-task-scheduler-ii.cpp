class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>ump;
        long long timer=0;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            if(timer>=ump[tasks[i]]){
                ump[tasks[i]]=timer+space+1;
            }
            else{
               timer=ump[tasks[i]];
               ump[tasks[i]]=timer+space+1;
            }
          timer++;
        }
        return timer;
    }
};