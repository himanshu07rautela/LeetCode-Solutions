#include<vector>
vector<int> majorityElement(vector<int>& v) {
    int candi1 = 0, candi2 = 1; // These initial values won't matter after the first few steps
    int count1 = 0, count2 = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == candi1) {
            count1++;
        } else if (v[i] == candi2) {
            count2++;
        } else if (count1 == 0) {
            candi1 = v[i];
            count1 = 1;
        } else if (count2 == 0) {
            candi2 = v[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Verification Phase
    vector<int> ans;
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == candi1) {
            count1++;
        } else if (v[i] == candi2) {
            count2++;
        }
    }

    if (count1 > v.size() / 3) {
        ans.push_back(candi1);
    }
    if (count2 > v.size() / 3) {
        ans.push_back(candi2);
    }
	sort(ans.begin(), ans.end());

    

    return ans;
}
