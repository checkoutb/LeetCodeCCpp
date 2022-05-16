
#include "../header/myheader.h"

class LT2276
{
public:



};

// D

// add 的时候更新map。。。。 count() 直接返回 cnt
//
//    void add(int left, int right) {
//        auto it = m.upper_bound(left);
//        if (it != begin(m) && prev(it)->second >= left)
//            it = prev(it);
//        for (; it != end(m) && it->first <= right; m.erase(it++)) {
//            left = min(left, it->first);
//            right = max(right, it->second);
//            cnt -= it->second - it->first + 1;
//        }
//        cnt += right - left + 1;
//        m[left] = right;
//    }




// tle..
class CountIntervals {
    map<int, int> map2;
public:
    CountIntervals() {

    }

    void add(int left, int right) {
        this->map2[left] = max(this->map2[left], right);
    }

    int count() {
        int ans = 0;
        int lsten = -2;
        int lstst = -1;

//        map<int, int> map3;
//
//        #ifdef __test
//        cout<<map2.size()<<endl;
//        #endif // __test
//
//        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
//        {
//            int st = it->first;
//            int en = it->second;
//            if (st > lsten)
//            {
//                if (lstst > 0)
//                    map3[lstst] = lsten;
//                ans += lsten - lstst + 1;
//                lstst = st;
//                lsten = en;
//            }
//            else
//            {
//                lsten = max(lsten, en);
//            }
//        }
//
//        #ifdef __test
//        cout<<map2.size()<<endl;
//        #endif // __test
//
//        ans += lsten - lstst + 1;
//        if (lstst > 0)
//            map3[lstst] = lsten;
//
//        this->map2 = map3;
//        return ans;

        for (map<int, int>::iterator it = begin(map2); it != end(map2); )
        {
            int st = it->first;
            int en = it->second;

            #ifdef __test
            cout<<lstst<<", "<<lsten<<" - - "<<st<<", "<<en<<endl;
            #endif // __test

            if (st > lsten)
            {
                if (lstst > 0)
                    map2[lstst] = lsten;

                ans += lsten - lstst + 1;
                lstst = st;
                lsten = en;
                it++;
            }
            else
            {
                lsten = max(lsten, en);
                it = map2.erase(it);
            }
        }
        ans += lsten - lstst + 1;
        if (lstst > 0)
            map2[lstst] = lsten;
        return ans;

////        int en = this->map2.begin()->first - ;
//        int ent = -1;
//        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
//        {
//            int st = it->first;
//            int en = it->second;
//            if (ent < st)
//            {
//                ans += (en - st + 1);
//                ent = en;
//            }
//            else
//            {
//                if (ent > en)
//                {
//                    ;
//                }
//                else
//                {
//                    ans += (en - ent + 1);
//                    ent = en;
//                }
//            }
//        }
    }
};



int main()
{

    LT2276 lt;


    CountIntervals ci;

//    ci.add(2,3);
//    cout<<ci.count()<<endl;
//    ci.add(7,10);
//    cout<<ci.count()<<endl;
//    ci.add(5,8);
//    cout<<ci.count()<<endl;

// [54,497],[769,937],[572,995],[],[],[590,700],[],[729,950],[914,972],[314,926],[572,965],[]
    ci.add(54,497);
    ci.add(769,937);
    ci.add(572,995);
//    cout<<ci.count()<<endl;
    ci.add(590,700);
//    cout<<ci.count()<<endl;
    ci.add(729,950);
    ci.add(914,972);
    ci.add(314,926);
    ci.add(572,965);
//    ci.add();
    cout<<ci.count()<<endl;

    return 0;
}
