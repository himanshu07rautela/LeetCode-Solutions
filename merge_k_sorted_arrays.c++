#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    // there is one efficent way;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    //here int is value , arrindex, elemindex;
    for(int i=0;i<k;i++){
        if (!kArrays[i].empty()) { 
            pq.push(make_tuple(kArrays[i][0], i, 0));
        }

    }
    vector<int>ans;
    while(!pq.empty()){
        tuple<int, int, int> top = pq.top();
        pq.pop();

        
        int val = get<0>(top);
        int arrindex = get<1>(top);
        int elemindex = get<2>(top);

        ans.push_back(val);

        
        if(elemindex+1 < kArrays[arrindex].size()){
          pq.push(make_tuple(kArrays[arrindex][elemindex+1], arrindex, elemindex + 1));
        }
    }
    return ans;
}
