#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	// toh jo bhi over lap karre hai unko hatao
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	int low =arr[0][0];
	int high=arr[0][1];
	for(int i=1;i<arr.size();i++){
		int start=arr[i][0];
		int end=arr[i][1];
		if(start>high){
			vector<int>a;
			a.push_back(low);
			a.push_back(high);
			ans.push_back(a);
			low=start;
			high=end;
			continue;
		}else{
			high=max(high,end);
		}
		
	}
	ans.push_back({low, high});
	return ans;


	
}