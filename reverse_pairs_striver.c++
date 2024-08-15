class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int left = low;
        int right = mid + 1;

        // Counting reverse pairs
        while (left <= mid && right <= high) {
            if (nums[left] > (long long)2 * nums[right]) {
                cnt += (mid - left + 1);  // All elements from nums[left] to nums[mid] will form a valid pair with nums[right]
                right++;
            } else {
                left++;
            }
        }

        // Merging the two halves
        left = low;
        right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int mergesort(vector<int>& nums, int i, int j) {
        int cnt = 0;
        if (i >= j) {
            return cnt;
        }
        int mid = (i + j) / 2;
        cnt += mergesort(nums, i, mid);
        cnt += mergesort(nums, mid + 1, j);
        cnt += merge(nums, i, mid, j);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
