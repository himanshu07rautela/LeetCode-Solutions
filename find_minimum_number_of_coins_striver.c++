vector<int> MinimumCoins(int n)
{
    // Write your code here
    // ok lets greedly do it man
    vector<int>arr;
    arr.push_back(1000);
    arr.push_back(500);
    arr.push_back(100);
    arr.push_back(50);
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(1);
    vector<int>ans;
    while(n>0){
        for(int i=0;i<arr.size();i++){
            if(n>=arr[i]){
                ans.push_back(arr[i]);
                n=n-arr[i];
                break;
            }
        }
    }
    return ans;

}