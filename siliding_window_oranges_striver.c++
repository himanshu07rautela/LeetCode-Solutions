class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        unordered_map<int,int> mp;  
        priority_queue<int> heap;
        int j=0;
        vector<int> ans;
        while (j<v.size()) 
        {
            if (heap.size()<k)
            {
                heap.push(v[j]);
                mp[v[j]]++;
                if (heap.size() == k) 
                    ans.push_back(heap.top());
            } 
            else
            {
                mp[v[j - k]]--; 
                heap.push(v[j]);
                mp[v[j]]++;
                while (!heap.empty() && mp[heap.top()] == 0)
                    heap.pop();
                ans.push_back(heap.top());
            }
            j++;
        }
        return ans;
    }
};