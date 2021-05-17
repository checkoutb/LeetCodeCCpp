
#include "../header/myheader.h"

class LT1865
{
public:



};

// D D

//    int count(int val) {
//        int ans = 0;
//        for(auto x : a)
//            if(mp.count(val - x))
//                ans += mp[val - x];
//    	return ans;
//    }
// a是 nums1， 不可变的，所以保存为 vector<int>
// 关键就是 nums2 要转成map，这样能遍历nums1，并通过hash来快速判断。



//vector<int> n1, n2;
//unordered_map<int, int> m;
//FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
//    swap(n1, nums1);
//    swap(n2, nums2);                              // !
//    for (auto n : n2)
//        ++m[n];
//}
//void add(int index, int val) {
//    --m[n2[index]];
//    n2[index] += val;
//    ++m[n2[index]];
//}
//int count(int tot) {
//    int res = 0;
//    for (auto n : n1) {
//        if (n < tot) {                            // !
//            auto it = m.find(tot - n);        // ! find + 判断，减少一次hash。
//            if (it != end(m))
//                res += it->second;
//        }
//    }
//    return res;
//}





// 因为map1的size 远小于 map2， 所以 循环map1的执行循环体次数 <<< 循环map2时循环体执行的次数
//Runtime: 252 ms, faster than 100.00% of C++ online submissions for Finding Pairs With a Certain Sum.
//Memory Usage: 73.7 MB, less than 100.00% of C++ online submissions for Finding Pairs With a Certain Sum.
class FindSumPairs {

    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    vector<int> vi2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i : nums1)
            map1[i]++;
        for (int i : nums2)
            map2[i]++;
        vi2 = nums2;
    }

    void add(int index, int val) {
        int t2 = this->vi2[index];
        map2[t2]--;
        if (map2[t2] == 0)
            map2.erase(t2);
        map2[t2 + val]++;
        vi2[index] += val;
    }

    int count(int tot) {
        int ans = 0;
        for (unordered_map<int, int>::iterator it = map1.begin(); it != map2.end(); it++)
        {
            int t2 = tot - it->first;
            if (map2.find(t2) != map2.end())
            {
                ans += it->second * map2[t2];
            }
        }
        return ans;
    }
};



//// tle...
//class FindSumPairs {
//
//    unordered_map<int, int> map1;
//    vector<int> vi2;
//
//public:
//    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
//        for (int i : nums1)
//            this->map1[i]++;
//        vi2 = nums2;
//    }
//
//    void add(int index, int val) {
//        vi2[index] += val;
//    }
//
//    int count(int tot) {
//        int ans = 0;
//        for (int i = 0; i < vi2.size(); ++i)
//        {
//            int need = tot - vi2[i];
//            if (this->map1.find(need) != map1.end())
//            {
//                ans += map1[need];
//            }
//        }
//        return ans;
//    }
//};

int main()
{
    myvi v1 = {1, 1, 2, 2, 2, 3};
    myvi v2 = {1, 4, 5, 2, 5, 4};

    FindSumPairs findSumPairs(v1, v2);
    cout<<endl<<"ans: "<<findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
    findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
    cout<<endl<<"ans: "<<findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
    cout<<endl<<"ans: "<<findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
    findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
    findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
    cout<<endl<<"ans: "<<findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4


    LT1865 lt;


    return 0;
}
