#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        // size of subarrays
        //  2  5  4  1  5  7  8  9
        int p, l, h, mid;

        for (p = 2; p <= n; p = 2 * p)
        { // pass size
            for (int i = 0; i < n - p + 1; i += p)
            {
                l = i;
                h = i + p - 1;
                mid = (l + h) / 2;
                merge(nums, l, mid, h);
            }
        }
        if (p / 2 < n)
            merge(nums, 0, p / 2, n - 1);

        return nums;
    }

private:
    void merge(vector<int> &nums, int l, int mid, int h)
    {
        int i = l, j = mid + 1, k = 0;
        vector<int> res(h - l + 1);
        while (i <= mid && j <= h)
        {
            if (nums[i] < nums[j])
                res[k++] = nums[i++];
            else
                res[k++] = nums[j++];
        }
        for (; i <= mid; i++)
            res[k++] = nums[i];
        for (; j <= h; j++)
            res[k++] = nums[j];

        for (int i = 0; i < res.size(); i++)
            nums[l + i] = res[i]; // yea it suks
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    Solution sol;
    sol.sortArray(nums);
    for (auto n : nums)
        cout << n << " ";
    return 0;
}