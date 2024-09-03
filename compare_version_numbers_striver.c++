class Solution {
public:
    void solve(string s,vector<int>&a){
        int n=s.size();
        int i=0;

        while(i<n){
            
            int val=0;
            int k=0;
            while(i<n &&s[i]!='.'){
                if(s[i]=='0' && k==0){
                    i++;
                    continue;

                }else if(k==0 && s[i]!='0'){
                    
                    k=1;
                    val=val*10+(s[i]-'0');
                    i++;
                }else if(k==1){
                   
                    val=val*10+(s[i]-'0');
                     i++;
                }

            }
            a.push_back(val);
            i++;

        }
        return;
    }
    int compareVersion(string version1, string version2) {
        vector<int>a1;
        vector<int>a2;
        solve(version1,a1);
        solve(version2,a2);
        int mini=min(a1.size(), a2.size());
        for(int i=0;i<mini;i++){
            if(a1[i]>a2[i]){
                return 1;
            }else if(a1[i]<a2[i]){
                return -1;
            }
        }
        int size1=a1.size();
        int size2=a2.size();
        if (size1 > size2) {
            for (int i = size2; i < size1; i++) {
                if (a1[i] > 0) {
                    return 1;
                }
            }
        } else if (size2 > size1) {
            for (int i = size1; i < size2; i++) {
                if (a2[i] > 0) {
                    return -1;
                }
            }
        }
        return 0;
    }
};