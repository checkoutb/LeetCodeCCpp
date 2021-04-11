
#include "../../header/myheader.h"

class LT5729
{
public:



};


// 。。。 发现结束后可以看别人的代码的。。。。


// 第一名，18min结束：第四题。。。。 ？？？？  这不就是， 我第一次tle的那种吗。  难道 python 还能比cpp 快？ 标准也差太多了吧。
//class MKAverage:
//    def __init__(self, m: int, k: int):
//        self.m = m
//        self.k = k
//        self.stream = []
//        self.sortedstream = []
//
//    def addElement(self, num: int) -> None:
//        self.stream.append(num)
//        if len(self.stream)>self.m:
//            self.stream.pop(0)
//
//    def calculateMKAverage(self) -> int:
//        if len(self.stream)<self.m:
//            return -1
//        container = sorted(self.stream)[self.k:-self.k]
//        return sum(container)//len(container)



// slay_tree ....


// 3个multiset 形成 3个heap










// 想不出咯。。。加钱升级硬件吧。。。

// 估计有种数据结构 适用于这种问题。
// priority queue ? <int, int> ? 前者是tiemstamp,后者是值，没什么用。

// stack？ 之前的比 本元素大的 所有数。


//1472 / 12113	Ouha 	12	0:44:26	0:04:05 	0:13:08 	0:44:26

// tle...
class MKAverage {

    deque<int> deq;
    int m;
    int k;
//    multiset<int> mset2;        // ..i remember erase is remove all..
    map<int, int> map2;
    int avg;

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        this->avg = -1;
    }

    void addElement(int num) {
        if (deq.size() == m)
        {
            int t2 = deq.front();
            deq.pop_front();
            map2[t2]--;
        }
        deq.push_back(num);
        map2[num]++;
        this->avg = -1;
    }

    int calculateMKAverage() {
        if (this->avg != -1)
            return this->avg;
        if (deq.size() < m)
            return -1;
        long sum2 = 0;
        map<int, int>::iterator it = map2.begin();
        int t2 = k;
        int cnt = m - k - k;
//        cout<<", , "<<cnt<<endl;
        while (t2 > 0)
        {
            t2 = t2 - it->second;
            if (t2 < 0)
            {
                sum2 += (long) it->first * (min(-t2, cnt));
                cnt += t2;
            }
            it++;
        }
        while (cnt > 0)
        {
            if (it->second == 0)
            {
                it++;
                continue;
            }
            cnt -= it->second;
            if (cnt < 0)
            {
                sum2 += (long) it->first * (it->second + cnt);
            }
            else
            {
                sum2 += (long) it->first * it->second;
            }
            it++;
        }
        this->avg = sum2 / (m - k - k);
        return this->avg;
    }
};




// tle....................
class MKAverage2 {

    vector<int> stream;
    int mxsz;
    int myk;

public:
    MKAverage2(int m, int k) {
        this->mxsz = m;
        this->myk = k;
    }

    void addElement(int num) {
        if (stream.size() == mxsz)
            stream.erase(stream.begin());           // deque.pop_front...
        stream.push_back(num);
    }

    int calculateMKAverage() {
        if (stream.size() < mxsz)
            return -1;
        vector<int> vi(begin(stream), end(stream));
        std::sort(vi.begin(), vi.end());
        long sum2 = 0;
        for (int i = myk; i < mxsz - myk; ++i)
        {
            sum2 += vi[i];
        }
        return sum2 / (mxsz - myk - myk);
    }
};




int main()
{
    MKAverage mk(3,1);
    mk.addElement(3);
    mk.addElement(3);
    cout<<mk.calculateMKAverage()<<endl;        // -1
    mk.addElement(10);
    cout<<mk.calculateMKAverage()<<endl;        // 3
    mk.addElement(5);
    mk.addElement(5);
    mk.addElement(5);
    cout<<mk.calculateMKAverage()<<endl;        // 5

    LT5729 lt;


    return 0;
}
