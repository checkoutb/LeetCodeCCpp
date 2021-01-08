
#include "../header/myheader.h"

class LT0904
{
public:

// D D

//        int num_of_type = 0;
//        vector<int> v(tree.size(), 0);
// map


//        int last_fruit = -1, second_last_fruit = -1 ;


//        int res = 0, cur = 0, count_b = 0, a = 0, b = 0;
//        for (int c :  tree) {
//            cur = c == a || c == b ? cur + 1 : count_b + 1;
//            count_b = c == b ? count_b + 1 : 1;
//            if (b != c) a = b, b = c;
//            res = max(res, cur);
//        }
//        return res;


//        for (i = 0, j = 0; j < tree.size(); ++j) {
//            count[tree[j]]++;
//            if (count.size() > 2) {
//                if (--count[tree[i]] == 0)count.erase(tree[i]);
//                i++;
//            }
//        }





//Runtime: 320 ms, faster than 40.05% of C++ online submissions for Fruit Into Baskets.
//Memory Usage: 61.9 MB, less than 57.11% of C++ online submissions for Fruit Into Baskets.
// 2个数字出现的最大长度。
    int lt0904a(vector<int>& tree)
    {
        int ans = 0;
        unordered_map<int, int> map2;
//        int i = 0;
//        for (; i < tree.size(); ++i)
//        {
//            if (map2.size() < 2)
//                map2[tree[i]]++;
//            else
//                if (map2.find(tree[i]) != map2.end())
//                    map2[tree[i]]++;
//                else
//                    break;
//        }

        for (int i = 0, st = 0; i < tree.size(); ++i)
        {
            map2[tree[i]]++;
            while (map2.size() > 2)
            {
                if (map2[tree[st]] == 1)
                    map2.erase(tree[st]);
                else
                    map2[tree[st]]--;
                st++;
            }
            ans = max(ans, i - st + 1);
//            if (map2.size() < 2)
//                map2[tree[i]]++;
//            else
//                if (map2.find(tree[i]) != map2.end())
//                    map2[tree[i]]++;
//                else
//
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,1};
//    myvi v = {0,1,2,2};
//    myvi v = {1,2,3,2,2};
    myvi v = {3,3,3,1,2,1,1,2,3,3,4};

    LT0904 lt;

    cout<<lt.lt0904a(v);

    return 0;
}
