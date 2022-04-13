
#include "../header/myheader.h"

class LT0715
{
public:



};


// error


class RangeModule {
    map<int, int> map2;
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        if (map2.size() == 0)
        {
            map2[left] = right;
            return;
        }
//    cout<<"."<<endl;
        map<int, int>::iterator it = map2.upper_bound(left);
//        if (it == end(map2))      // {1,1111}  add {2,22}
//        {
//            map2[left] = right;
//            return;
//        }
        if (it != begin(map2))
            it = prev(it);

//            cout<<"1."<<endl;

        if (it->second < left)
        {
            it++;                   // map2 空时， it++, next(it) 都会卡死。不知道是不是死循环。
//        cout<<"."<<endl;
//            it = next(it);
//            cout<<" ?."<<endl;
        }
        if (it == end(map2))
        {
            map2[left] = right;
            return;
        }
//cout<<"111"<<endl;
        int k2 = min(left, it->first);
        int t2 = right;
        for (; it != end(map2); )       // first <= left
        {
//            cout<<".";
            if (it->first < right)
            {
                t2 = max(t2, it->second);
                it = map2.erase(it);
            }
            else
            {
                break;
            }
        }
        map2[k2] = t2;

        #ifdef __test
        cout<<"after add"<<endl;
        for (pair<const int, int>& p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test

    }

    bool queryRange(int left, int right) {
        map<int, int>::iterator it = map2.upper_bound(left);
//        if (it == end(map2))
//            return false;
        if (it == begin(map2))
            return false;
        it = prev(it);
        return it->second >= right;
//        for (it = std::prev(it); it != map2.end(); it++)        // prev <=
//        {
//
//        }
    }

    void removeRange(int left, int right) {
        map<int, int>::iterator it = map2.upper_bound(left);
        if (it != begin(map2))
            it = prev(it);
        for (; it != end(map2); )
        {
            if (it->first >= left)
            {
                if (it->second <= right)
                {
                    it = map2.erase(it);
                }
                else
                {
//                    it->first = right;        // pair<const int, int>
//                    map2[it->first] = right;
                    if (it->first >= right)
                        break;
                    else
                    {
                        map2[right] = it->second;
                        map2.erase(it);
                        break;
                    }
                }
            }
            else        // first < left
            {
                if (it->second >= left)
                {
                    if (it->second <= right)
                        it->second = left;
                    else
                    {
                        map2[right] = it->second;
                        it->second = left;
//                        cout<<".... "<<&(map2[right])<<", "<<&(it->second)<<endl;
//                        cout<<right<<", "<<map2[right]<<endl;
                    }
                }
                it++;
            }
        }
        #ifdef __test
        cout<<"after remove"<<endl;
        for (auto& p : map2)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        #endif // __test
    }
};



int main()
{

    LT0715 lt;

    RangeModule rangeModule;
//    cout<<"..0"<<endl;
//    rangeModule.addRange(10, 20);
//    cout<<"..1"<<endl;
//    rangeModule.removeRange(14, 16);
//    cout<<"..2"<<endl;
//    cout<<endl<<rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
//    cout<<endl<<rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
//    cout<<endl<<rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)

//["RangeModule","queryRange","addRange","addRange","removeRange","removeRange","queryRange","addRange","queryRange","removeRange"]
//[[],[4,7],[3,5],[1,2],[1,2],[5,9],[6,7],[5,6],[1,3],[1,8]]
    bool b2 = false;
//    b2 = rangeModule.queryRange(4,7);
//    cout<<b2<<endl;
//    rangeModule.addRange(3,5);
//    rangeModule.addRange(1,2);
//    rangeModule.removeRange(1,2);
//    rangeModule.removeRange(5,9);
//    b2 = rangeModule.queryRange(6,7);
//    cout<<b2<<endl;
//    rangeModule.addRange(5,6);
//    b2 = rangeModule.queryRange(1,3);
//    cout<<b2<<endl;
//    rangeModule.removeRange(1,8);
////    rangeModule.


    rangeModule.addRange(44,53);
    rangeModule.addRange(69,89);
    b2 = rangeModule.queryRange(23,26);
    cout<<b2<<endl;

    return 0;
}
