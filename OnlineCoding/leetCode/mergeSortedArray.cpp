#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(m+n);
        int i=0, j=0;
        while (i<m && j<n) {
            if (nums1[i] < nums2[j]) {
                if (nums1[i]!=0) {
                    nums.push_back(nums1[i]);
                }
                ++i;
            }
            else if (nums2[j] < nums1[i]) {
                if (nums2[j]!=0) {
                    nums.push_back(nums2[j]);
                }
                ++j;
            }
        }
        if (i<m) {
            for (int a=i; a<m; ++a) {
                nums.push_back(nums1[a]);
            }
        }
        else if (j<n) {
            for (int a=j; a<n; ++a) {
                nums.push_back(nums2[a]);
            }
        }
        for (auto b:nums) {
            cout << b << " ";
        }
        
    }
};

int main() {
    Solution* s = new Solution();
    
    return 0;
}