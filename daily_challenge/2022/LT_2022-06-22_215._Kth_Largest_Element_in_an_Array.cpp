
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());

    // partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());

    //public int findKthLargest(int[] nums, int k) {
    //    int start = 0, end = nums.length - 1, index = nums.length - k;
    //    while (start < end) {
    //        int pivot = partion(nums, start, end);
    //        if (pivot < index) start = pivot + 1;
    //        else if (pivot > index) end = pivot - 1;
    //        else return nums[pivot];
    //    }
    //    return nums[start];
    //}
    //
    //private int partion(int[] nums, int start, int end) {
    //    int pivot = start, temp;
    //    while (start <= end) {
    //        while (start <= end && nums[start] <= nums[pivot]) start++;
    //        while (start <= end && nums[end] > nums[pivot]) end--;
    //        if (start > end) break;
    //        temp = nums[start];
    //        nums[start] = nums[end];
    //        nums[end] = temp;
    //    }
    //    temp = nums[end];
    //    nums[end] = nums[pivot];
    //    nums[pivot] = temp;
    //    return end;
    //}


//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        int left = 0, right = nums.size() - 1, kth;
//        while (true) {
//            int idx = partition(nums, left, right);
//            if (idx == k - 1) {
//                kth = nums[idx];
//                break;
//            }
//            if (idx < k - 1) {
//                left = idx + 1;
//            }
//            else {
//                right = idx - 1;
//            }
//        }
//        return kth;
//    }
//private:
//    int partition(vector<int>& nums, int left, int right) {
//        int pivot = nums[left], l = left + 1, r = right;
//        while (l <= r) {
//            if (nums[l] < pivot && nums[r] > pivot) {
//                swap(nums[l++], nums[r--]);
//            }
//            if (nums[l] >= pivot) {
//                l++;
//            }
//            if (nums[r] <= pivot) {
//                r--;
//            }
//        }
//        swap(nums[left], nums[r]);
//        return r;
//    }




//Runtime: 15 ms, faster than 39.86 % of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage : 10.2 MB, less than 21.99 % of C++ online submissions for Kth Largest Element in an Array.
    int ltd(vector<int>& nums, int k)
    {
        priority_queue<int> priq;
        int mxsz = nums.size() - k + 1;
        for (int i : nums)
        {
            priq.push(i);
            if (priq.size() > mxsz)
                priq.pop();
        }
        return priq.top();
    }



//Runtime: 205 ms, faster than 5.02 % of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage : 10 MB, less than 61.91 % of C++ online submissions for Kth Largest Element in an Array.
    int ltc(vector<int>& nums, int k)
    {
        return dfsa1(nums, nums.size() - k, 0, nums.size() - 1);
    }

    int dfsa1(vector<int>& nums, int k, int st, int en)
    {
#ifdef __test
        cout << st << ", " << en << endl;
#endif
        int t2 = nums[st];
        //int st = 0, en = nums.size() - 1;
        int st2 = st, en2 = en;

        for (int i = st + 1; i <= en; ++i)
        {
            if (nums[i] <= t2)
            {
                nums[st++] = nums[i];
            }
            else
            {
                swap(nums[i], nums[en]);
                i--, en--;
            }
        }
        nums[st] = t2;
        if (st == k)
            return t2;
        else if (st > k)
        {
#ifdef __test
            cout << st2 << ",1 " << st << endl;
            showVectorInt(nums);
#endif
            return dfsa1(nums, k, st2, st - 1);
        }
        else
        {
#ifdef __test
            cout << st << ",2 " << en2 << endl;
#endif
            return dfsa1(nums, k, st + 1, en2);
        }
    }


//Runtime: 17 ms, faster than 29.72 % of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage : 9.9 MB, less than 86.09 % of C++ online submissions for Kth Largest Element in an Array.
    int ltb(vector<int>& nums, int k)
    {
        std::partial_sort(begin(nums), begin(nums) + (nums.size() - k + 1), end(nums));
#ifdef __test
        showVectorInt(nums);
#endif
        return nums[nums.size() - k];
    }


//Runtime: 10 ms, faster than 71.97 % of C++ online submissions for Kth Largest Element in an Array.
//Memory Usage : 9.9 MB, less than 86.09 % of C++ online submissions for Kth Largest Element in an Array.
    int lta(vector<int>& nums, int k)
    {
        sort(begin(nums), end(nums));
        return nums[nums.size() - k];
    }

};

int main()
{

    LT lt;

    //vector<int> vi = { 3,2,1,5,6,4 };
    //int n = 2;

    //vector<int> vi = { 3,2,3,1,2,4,5,5,6 };
    //int n = 4;

    vector<int> vi = { 1,1,1,1,1,1 };
    int n = 3;

    cout << lt.ltc(vi, n) << endl;

    return 0;
}
