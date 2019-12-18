
#include "../header/myheader.h"

class LT0460
{
};

// d && d
// 都好长。。使用3个map，  使用Double Linked List<Struct>的


// 100-150ms
// ....300mb...
//Runtime: 1776 ms, faster than 5.01% of C++ online submissions for LFU Cache.
//Memory Usage: 339 MB, less than 9.09% of C++ online submissions for LFU Cache.

class LFUCache {
private:
    // k,v,cnt,times
    map<int, vector<int>> map1;
    long long cnt;
    int cap;

public:
    LFUCache(int capacity) {
        cnt = 1;
        cap = capacity;
    }

    int get(int key) {
        if (map1.find(key) != map1.end())
        {
            map1[key][2] = cnt++;
            map1[key][3]++;
            return map1[key][1];
        }
        return -1;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;
        if (map1.find(key) != map1.end())
        {
            map1[key][1] = value;
            map1[key][2] = cnt++;
            map1[key][3]++;
        }
        else
        {
            if (map1.size() < cap)
            {
                vector<int> a = {key, value, cnt++, 1};
                map1.insert({key, a});
            }
            else
            {
                vector<int> arr = map1.begin()->second;
                int mk = arr[0];
                int mv = arr[1];
                int mc = arr[2];
                int mt = arr[3];
                for (auto p : map1)
                {
                    arr = p.second;
                    if (arr[3] < mt || (arr[3] == mt && arr[2] < mc))
                    {
                        mk = arr[0];
                        mv = arr[1];
                        mc = arr[2];
                        mt = arr[3];
                    }
                }
                map1.erase(mk);
                vector<int> a = {key, value, cnt++, 1};
                map1[key] = a;
            }
        }
    }
};


class LFUCache3
{
private:

    vector<int[4]> arr;
    long long cnt;
    int cap;
    bool full;

public:
    LFUCache3(int capacity) {
        arr = vector<int[4]>(capacity);
        cnt = 1;
        cap = capacity;
        full = false;
    }

    int get(int key) {
        for (int i = 0; i < cap; i++)
        {
            if (arr[i][0] == key)
            {
                arr[i][2] = cnt++;
                arr[i][3]++;
                return arr[i][1];
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for (int i = 0; i < cap; i++)
        {
            if (arr[i][0] == key)
            {
                arr[i][1] = value;
                arr[i][2] = cnt;
                arr[i][3]++;
                cnt++;
                return;
            }
        }

        if (!full)
        {
            for (int i = 0; i < cap; i++)
            {
                if (arr[i][2] == 0)
                {
                    arr[i][0] = key;
                    arr[i][1] = value;
                    arr[i][2] = cnt;
                    arr[i][3] = 0;
                    cnt++;
                    return;
                }
            }
            full = true;
        }

        int mi = 0;
        int mc = arr[0][2];
        int mt = arr[0][3];

        for (int i = 1; i < cap; i++)
        {
            if (arr[i][3] <= mt)
            {
                if (arr[i][3] == mt)
                {
                    if (arr[i][2] > arr[mi][2])
                        continue;
                }
                mi = i;
                mc = arr[i][2];
                mt = arr[i][3];
            }
        }
        arr[mi][0] = key;
        arr[mi][1] = value;
        arr[mi][2] = cnt;
        arr[mi][3] = 0;
        cnt++;
    }
};


// error。 这好像是FIFO的感觉。。
class LFUCache2 {

    // O(capacity) 应该算O(1)吧
    // 二维数组 3*capacity，+ long
    // put 不算使用。。。

    vector<int[3]> arr;
    long long cnt;
    int cap;
    bool full;

public:
    LFUCache2(int capacity)
    {
        arr = vector<int[3]>(capacity);
        cnt = 1;
        cap = capacity;
        full = false;
    }

    int get(int key)
    {
        for (int i = 0; i < cap; i++)
        {
            if (arr[i][0] == key)
            {
                arr[i][2] = cnt++;
                return arr[i][1];
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < cap; i++)
        {
            if (arr[i][0] == key)
            {
                arr[i][1] = value;
                arr[i][2] = cnt;
                cnt++;
                return;
            }
        }

        if (!full)
        {
            for (int i = 0; i < cap; i++)
            {
                if (arr[i][2] == 0)
                {
                    arr[i][0] = key;
                    arr[i][1] = value;
                    arr[i][2] = cnt;
                    cnt++;
                    return;
                }
            }
            full = true;
        }

        int mi = 0;
        int mv = arr[0][2];

        for (int i = 1; i < cap; i++)
        {
            if (arr[i][2] < mv)
            {
                mi = i;
                mv = arr[i][2];
            }
        }
        arr[mi][0] = key;
        arr[mi][1] = value;
        arr[mi][2] = cnt;
        cnt++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LFUCache* cache = new LFUCache( 2 /* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    cout<<cache->get(1)<<endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout<<cache->get(2)<<endl;       // returns -1 (not found)
    cout<<cache->get(3)<<endl;       // returns 3.
    cache->put(4, 4);    // evicts key 1.
    cout<<cache->get(1)<<endl;       // returns -1 (not found)
    cout<<cache->get(3)<<endl;       // returns 3
    cout<<cache->get(4)<<endl;       // returns 4

    return 0;
}


