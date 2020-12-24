
#include "../header/myheader.h"

class LT0146
{
public:



};




// gg
// 用diff 来记录， key 在LRU中，又被刷新的情况。
//0 <= key <= 3000
class LRUCache {
    vector<int> vi;       // value
    vector<int> v2;       // cnt
    int sz1;
    int cnt;
    int diff;
public:
    LRUCache(int capacity) {
        sz1 = capacity;
        cnt = 0;
        diff = 0;
        vi = vector<int>(3001, -1);
        v2 = vector<int>(3001, -1);
    }

    int get(int key) {
        int val = vi[key];
        if (val == -1)
            return -1;
        #ifdef __test
//        cout<<"  "<<v2[key]<<" + "<<diff<<" ? "<<cnt<<" - "<<sz1<<endl;
        #endif // __test
        if (v2[key] + diff < cnt - sz1)
            return -1;

        v2[key] = cnt++;
//        diff++;
//        cout<<"       get "<<diff<<endl;

//        cout<<endl;
//        for (int i = 0; i <= 5; ++i)
//            cout<<vi[i]<<" , "<<v2[i]<<endl;

        return val;
    }

    void put(int key, int value) {
//        if (get(key) == -1)
//        {
//            vi[key] = value;
//            v2[key] = cnt++;
//        }
//        else
//        {
//
//        }
//        int v = get(key);

        if (vi[key] != -1 && (v2[key] + diff >= cnt - sz1))
        {
            diff++;
//            cout<<"  put "<<diff<<endl;
        }


        vi[key] = value;
//        if (v == -1)
            v2[key] = cnt++;
//        else
//            diff--;

//        cout<<endl;
//        for (int i = 0; i <= 5; ++i)
//            cout<<vi[i]<<" , "<<v2[i]<<endl;


    }
};



int main()
{

    LT0146 lt;

//    ["LRUCache","get","put","get","put","put","get","get"]
//    [[2],     [2],    [2,6],[1],  [1,5],[1,2],[1],    [2]]
//    [null,   -1,      null, -1,   null, null, 2,       6]


    LRUCache lRUCache(2);

    cout<<endl<<lRUCache.get(2);
    lRUCache.put(2,6);
    cout<<endl<<lRUCache.get(1);
    lRUCache.put(1,5);
    lRUCache.put(1,2);
    cout<<endl<<lRUCache.get(1);
    cout<<endl<<lRUCache.get(2);


//    lRUCache.put(1, 1); // cache is {1=1}
//    lRUCache.put(2, 2); // cache is {1=1, 2=2}
//    cout<<endl<<lRUCache.get(1);    // return 1
//    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//    cout<<endl<<lRUCache.get(2);    // returns -1 (not found)
//    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//    cout<<endl<<lRUCache.get(1);    // return -1 (not found)
//    cout<<endl<<lRUCache.get(3);    // return 3
//    cout<<endl<<lRUCache.get(4);    // return 4


    return 0;
}
