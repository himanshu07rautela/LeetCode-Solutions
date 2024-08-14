#include<vector>
#include<unordered_map>

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    // we're gonna use maps , do it
    unordered_map<int,bool>mp;
    vector<int>ans;
    for(int i=0;i<a.size();i++){
        if(mp[a[i]]==true){
            ans.push_back(a[i]);
            continue;
        }
        mp[a[i]]=true;
    }
    for(int i=1;i<=a.size();i++){
        if(mp.find(i) == mp.end()){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}