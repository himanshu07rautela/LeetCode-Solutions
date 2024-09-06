class Solution{
	public:
	   // int solve(int n){
	   //     if(n==1){
	   //         return 1;
	   //     }
	   //     if(n==0){
    //             return 1;	            
	   //     }
	   //     return solve(n-1)+solve(n-2);// 1 step lega ya 2 step
	        
	   // }
		int nthStair(int n){
		    //  Code here
		    
		  //  i doesn't need dp it needs if therewas no order
		  if(n==1){
		      return 1;
		  }
		  if(n==2){
		      return 2;
		  }
		  int ans=0;
		  int e;
		  if(n%2==0){
		      e=(n/2)-1;
		      ans++;
		  }else{
		      e=(n-1)/2-1;
		      ans++;
		  }
		  for(int i=0;i<=e;i++){
		      ans++;
		  }
		  return ans;
		  
		}
};