
#include "../header/myheader.h"

class LT0846
{
public:


// D
//        for (int i : hand) c[i]++;
//        for (auto it : c)
//            if (c[it.first] > 0)
//                for (int i = W - 1; i >= 0; --i)
//                    if ((c[it.first + i] -= c[it.first]) < 0)
//                        return false;


//Runtime: 140 ms, faster than 77.63% of C++ online submissions for Hand of Straights.
//Memory Usage: 26 MB, less than 60.70% of C++ online submissions for Hand of Straights.
// [5,1] 2
// 是真的数学的连续，就是+1。。以为是hand中连续就可以了。
    bool lt0846a(vector<int>& hand, int W)
    {
        int sz1 = hand.size();
        if (sz1 % W != 0)
            return false;

        map<int, int> map2;
        for (int& i : hand)
        {
            map2[i]++;
        }

        while (map2.size() >= W)
        {
            bool canDel = map2.begin()->second == 1;
            int i = 0;
            int val2 = map2.begin()->first - 1;
            for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
            {
                i++;
                if (i > W)
                    break;

                val2++;
                if (it->first != val2)
                    return false;

                if (it->second == 1)
                {
                    if (canDel)
                    {
                        map2.erase(it->first);
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    canDel = false;
                    it->second--;
                }
            }
        }
        return map2.empty();
    }

};

int main()
{

//    vector<int> v = {1,2,3,6,2,3,4,7,8};
//    int w = 3;

//    vector<int> v = {1,2,3,4,5};
//    int w = 4;

    vector<int> v = {5,1};
    int w = 2;


    LT0846 lt;

    cout<<lt.lt0846a(v, w)<<endl;

    return 0;
}
