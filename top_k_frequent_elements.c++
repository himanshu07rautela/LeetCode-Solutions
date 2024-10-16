class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        //we are using maxheap;
        
        unordered_map<int,int>mp;

        //1st int is frequency;
        for(int i=0;i<nums.size();i++){
            

            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;

            }else{
                mp[nums[i]]=1;

            }
            
        }
        priority_queue<pair<int,int>>pq;
        for(auto a:mp){
            int val=a.first;
            int freq=a.second;
            pq.push(make_pair(freq,val));
        }
        while(k--){
            pair<int,int>a=pq.top();
            pq.pop();
            ans.push_back(a.second);
        }
        return ans;
        
    }
};