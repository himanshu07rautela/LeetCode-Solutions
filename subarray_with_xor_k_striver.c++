
#include<unordered_map>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int ans=0;
    int cumxor=0;
    unordered_map<int,int>mp;
    for(int i=0;i<a.size();i++){
        cumxor=cumxor^a[i];
        if(cumxor==b){
            ans++;
        }
        if(mp.find(cumxor^b)!=mp.end()){
            ans+=mp[cumxor^b];
        }
        mp[cumxor]++;
        
    }
    return ans;
}