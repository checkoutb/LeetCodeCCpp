
#include "../header/myheader.h"

class LT1640
{
public:

// D D

//    vector<int> ps(101, -1);
//    for (int i = 0; i < pieces.size(); ++i)
//        ps[pieces[i][0]] = i;
//    for (int i = 0; i < arr.size(); ) {
//        int p = ps[arr[i]], j = 0;
//        if (p == -1)
//            return false;
//        while (j < pieces[p].size())
//            if (arr[i++] != pieces[p][j++])
//                return false;
//    }
// 保存 每条 piece 的 第一个元素， 与 整条piece 所在的下标。
// for arr, 如果 元素 在 ps中 有下标，说明 元素 是 某条piece 的开始，



//Runtime: 8 ms, faster than 72.45% of C++ online submissions for Check Array Formation Through Concatenation.
//Memory Usage: 10.2 MB, less than 89.46% of C++ online submissions for Check Array Formation Through Concatenation.
// 元素应该相同吧。  bu
// num1 + "-" + num2 + "-" .....  还有 需要 最小匹配。 那就排序pieces，size倒序。
// 还有  5111111    51  1111 ， 先1111的话 会导致  5    111
// distinct
    bool lt1640a(vector<int>& arr, vector<vector<int>>& pieces)
    {
//        sort(begin(pieces), end(pieces) [](const vector<int>& v1, const vector<int>& v2){ return v1.size() > v2.size(); });
        for (vector<int>& vi : pieces)
        {
//            if (vi.size() == 1)
//                continue;
            for (int i = 0; i < arr.size(); ++i)
            {
                if (arr[i] == vi[0])
                {
                    for (int j = 1; j < vi.size(); ++j)
                    {
                        if (arr[i + j] != vi[j])
                        {
                            return false;
                        }
                    }
                    goto AAA;
                }
            }
            return false;
            AAA:
            continue;
        }
        return true;
    }

};

int main()
{

    LT1640 lt;


    return 0;
}
