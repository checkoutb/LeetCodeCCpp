
#include "../header/myheader.h"

class LT1528
{
public:

// D D

//            while(indices[i] != i){
//                swap(s[i], s[indices[i]]);
//                swap(indices[indices[i]], indices[i]);
//            }



//Runtime: 8 ms, faster than 93.22% of C++ online submissions for Shuffle String.
//Memory Usage: 15.5 MB, less than 70.40% of C++ online submissions for Shuffle String.
    string lt1528a(string s, vector<int>& indices)
    {
        string ans(s);
        for (int i = 0; i < s.size(); ++i)
            ans[indices[i]] = s[i];
        return ans;

//        // 擦， 不是只比较一次的。
//        // 每次搜索 indices， 和 s， 找到 第一个 indeices 不为-1，且 s[] == ch 的 下标。 作为 ch 的 大小，  然后设置为-1
//        std::sort(begin(s), end(s), [&indices, &s](const char& ch1, const char& ch2) {
//            int idx1{-1}, idx2{-1};
//            for (int i = 0; i < s.size(); ++i)
//            {
//                if (idx1 == -1 && ch1 == s[i] && indices[i] != -1)
//                {
//                    idx1 = i;
//                    indices[i] = -1;
////                    break;
//                }
//                if (idx2 == -1 && ch2 == s[i] && indices[i] != -1)
//                {
//                    idx2 == i;
//                    indices[i] == -1;
//                }
//                if (idx1 != -1 && idx2 != -1)
//                    break;
//            }
//            cout<<idx1<<idx2<<endl;
//            return idx1 < idx2;
////            for (int i = 0; i < s.size(); ++i)
////            {
////                if (ch1 == [s])
////            }
//        });
////        showVectorInt(indices);
//        return s;
    }

};

int main()
{
    string s = "codeleet";
    myvi v = {4,5,6,7,0,2,1,3};

    LT1528 lt;

    cout<<lt.lt1528a(s, v);

    return 0;
}
