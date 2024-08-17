#include<vector>
#include<unordered_map>
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	unordered_map<int,int>mp;
	int cumsum=0;
	int ans=0;
	for(int i=0;i<arr.size();i++){
		cumsum+=arr[i];
		if(cumsum==0){
			ans=max(i+1,ans);

		}
		if(mp.find(cumsum)!=mp.end()){
			int l=i-mp[cumsum];
			ans=max(l,ans);
		}else{
			mp[cumsum]=i;
		}

	}
	return ans;
	
}