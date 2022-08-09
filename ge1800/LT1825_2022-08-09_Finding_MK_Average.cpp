
#include "../header/myheader.h"

class LT1825
{
public:



};

    // D D

    // Fenwick Tree
//class Fenwick:
//
//    def __init__(self, n: int):
//        self.nums = [0]*(n+1)
//
//    def sum(self, k: int) -> int:
//        k += 1
//        ans = 0
//        while k:
//            ans += self.nums[k]
//            k &= k-1 # unset last set bit
//        return ans
//
//    def add(self, k: int, x: int) -> None:
//        k += 1
//        while k < len(self.nums):
//            self.nums[k] += x
//            k += k & -k



//void addElement(int num) {
//    if (pos >= m)
//        remove(v[pos % m]);
//    add(num);
//    v[pos++ % m] = num;
//}
// 循环数组 代替 deque



//int m = 0, k = 0, sz = 0, pos = 0;
//long sum = 0;
//vector<int> v;
//multiset<int> left, mid, right;
//void remove(int n) {
//    if (n <= *rbegin(left))
//        left.erase(left.find(n));
//    else if (n <= *rbegin(mid)) {
//       auto it = mid.find(n);
//       sum -= *it;
//       mid.erase(it);
//    }
//    else
//        right.erase(right.find(n));
//    if (left.size() < k) {
//        left.insert(*begin(mid));
//        sum -= *begin(mid);
//        mid.erase(begin(mid));
//    }
//    if (mid.size() < sz) {
//        mid.insert(*begin(right));
//        sum += *begin(right);
//        right.erase(begin(right));
//    }
//}
//void add(int n) {
//    left.insert(n);
//    if (left.size() > k) {
//        auto it = prev(end(left));
//        mid.insert(*it);
//        sum += *it;
//        left.erase(it);
//    }
//    if (mid.size() > sz) {
//        auto it = prev(end(mid));
//        sum -= *it;
//        right.insert(*it);
//        mid.erase(it);
//    }
//}
//MKAverage(int m, int k) : m(m), k(k), sz(m - 2 * k) {
//    v = vector<int>(m);
//}
//void addElement(int num) {
//    if (pos >= m)
//        remove(v[pos % m]);
//    add(num);
//    v[pos++ % m] = num;
//}
//int calculateMKAverage() {
//    if (pos < m)
//        return -1;
//    return sum / sz;
//}





//Runtime: 497 ms, faster than 88.73% of C++ online submissions for Finding MK Average.
//Memory Usage: 147.1 MB, less than 58.09% of C++ online submissions for Finding MK Average.
class MKAverage {

    deque<int> deq;
    multiset<int> lft;
    multiset<int> mid;
    multiset<int> rgh;
    int m, k;
    long long sum2 = 0;

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        deq.push_back(num);
        mid.insert(num);
        sum2 += num;
        if (deq.size() > m)
        {
            int t2 = deq.front();
            deq.pop_front();
            if (lft.find(t2) != lft.end())
                lft.erase(lft.find(t2));
            else if (rgh.find(t2) != rgh.end())
                rgh.erase(rgh.find(t2));
            else
            {
                mid.erase(mid.find(t2));
                sum2 -= t2;
            }
        }
        if (deq.size() == m)
        {
            while (lft.size() < k)
            {
                int t2 = *mid.begin();
                mid.erase(mid.begin());
                lft.insert(t2);
                sum2 -= t2;
            }
            while (rgh.size() < k)
            {
                int t2 = *mid.rbegin();
                //mid.erase(mid.begin() + (int) (mid.size() - 1));
                //mid.erase(mid.rbegin());
                mid.erase(prev(mid.end()));
                rgh.insert(t2);
                sum2 -= t2;
            }
            bool chg = true;
            while (chg)
            {
                chg = false;
                while (*lft.rbegin() > *mid.begin())
                {
                    chg = true;
                    int t2 = *lft.rbegin();
                    int t3 = *mid.begin();
                    lft.erase(prev(lft.end()));
                    mid.erase(mid.begin());
                    lft.insert(t3);
                    mid.insert(t2);
                    sum2 += t2 - t3;
                }
                while (*mid.rbegin() > *rgh.begin())
                {
                    chg = true;
                    int t2 = *mid.rbegin();
                    int t3 = *rgh.begin();
                    mid.erase(prev(mid.end()));
                    rgh.erase(rgh.begin());
                    mid.insert(t3);
                    rgh.insert(t2);
                    sum2 += t3 - t2;
                }
            }

            #ifdef __test
//            cout<<" =-============ "<<endl;
//            for (int i : lft)
//                cout<<i<<", ";
//            cout<<endl;
//            for (int i : mid) cout<<i<<". "; cout<<endl;
//            for (int i : rgh) cout<<i<<"- "; cout<<endl;
//            cout<<sum2<<endl;
            #endif // __test

        }
    }

    int calculateMKAverage() {
        if (deq.size() < m)
            return -1;
        return sum2 / (m - 2 * k);
    }
};




// ... multiset . erase .. 我记得被坑过。
class MKAverage3 {

    deque<int> deq;
    multiset<int> lft;
    multiset<int> mid;
    multiset<int> rgh;
    int m, k;
    int sum2 = 0;

public:
    MKAverage3(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        deq.push_back(num);
        mid.insert(num);
        sum2 += num;
        #ifdef __test
        cout<<"insert "<<num<<endl;
        #endif // __test
        if (deq.size() > m)
        {
            int t2 = deq.front();
            deq.pop_front();
            if (rgh.find(t2) != rgh.end())
                rgh.erase(t2);
            else if (lft.find(t2) != lft.end())
                lft.erase(t2);
            else
            {
                mid.erase(t2);
                sum2 -= t2;
            }
        }
        if (deq.size() >= m)
        {
            while (lft.size() < k)
            {
                int t2 = *mid.begin();
                lft.insert(t2);
                mid.erase(t2);
                sum2 -= t2;
            }
            while (rgh.size() < k)
            {
                int t2 = *mid.rbegin();
                rgh.insert(t2);
                mid.erase(t2);
                sum2 -= t2;
            }
            bool chg = true;
            while (chg)
            {
                #ifdef __test
                cout<<" ==== "<<num<<" --";
                cout<<mid.size()<<" - "<<lft.size()<<" = "<<rgh.size()<<endl;
                for (int x : mid)
                    cout<<x<<".";
                cout<<endl;
                for (int x : lft)
                    cout<<x<<"-";
                cout<<endl;
                for (int x : rgh)
                    cout<<x<<"=";
                cout<<endl;
                #endif // __test
                chg = false;
                while (*lft.rbegin() > *mid.begin())
                {
                    chg = true;
                    int t2 = *lft.rbegin();
                    int t3 = *mid.begin();
                    lft.erase(t2);
                    mid.erase(t3);
                    lft.insert(t3);
                    mid.insert(t2);
                    sum2 += t2 - t3;
                }
                while (*mid.rbegin() > *rgh.begin())
                {
                    chg = true;
                    int t2 = *mid.rbegin();
                    int t3 = *rgh.begin();
                    mid.erase(t2);
                    rgh.erase(t3);
                    mid.insert(t3);
                    rgh.insert(t2);
                    sum2 += t3 - t2;
                }
            }
            #ifdef __test
            cout<<" ---------- "<<endl;

            cout<<mid.size()<<" - "<<lft.size()<<" = "<<rgh.size()<<endl;
            for (int x : mid)
                cout<<x<<".";
            cout<<endl;
            for (int x : lft)
                cout<<x<<"-";
            cout<<endl;
            for (int x : rgh)
                cout<<x<<"=";
            cout<<endl;
            cout<<" ===== "<<endl;
            #endif // __test
        }
    }

    int calculateMKAverage() {
        if (deq.size() < m)
            return -1;
        return sum2 / (m - 2 * k);
    }
};


class MKAverage2 {

    deque<int> deq;
    multiset<int> lft;
    multiset<int> mid;
    multiset<int> rgh;
    int m, k;
    int sum2 = 0;

public:
    MKAverage2(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        this->deq.push_back(num);
        rgh.insert(num);
        if (deq.size() > m)
        {
            int fnt = deq.front();
            deq.pop_front();
            if (rgh.find(fnt) != rgh.end())
                rgh.erase(fnt);
            else if (mid.find(fnt) != mid.end())
            {
                mid.erase(fnt);
                sum2 -= fnt;
            }
            else
                lft.erase(fnt);
        }
        if (deq.size() >= m)
        {
//            cout<<"11111  "<<num<<endl;
            while (rgh.size() > this->k)
            {
                if (mid.empty() || (*rgh.begin() >= *mid.rbegin()))
                {
                    int t2 = *rgh.begin();
                    rgh.erase(rgh.begin());
                    mid.insert(t2);
                    sum2 += t2;
                }
                else
                {
                    int t2 = *rgh.begin();
                    int t3 = *mid.rbegin();
                    rgh.erase(t2);
                    mid.erase(t3);
                    rgh.insert(t3);
                    mid.insert(t2);
                    sum2 += t2 - t3;
                }
            }
//            cout<<"122222"<<endl;
            while (mid.size() > (m - k * 2))
            {
                if (lft.empty() || (*mid.begin() >= *lft.rbegin()))
                {
                    int t2 = *mid.begin();
                    mid.erase(mid.begin());
                    lft.insert(t2);
                    sum2 -= t2;
                }
                else
                {
                    int t2 = *mid.begin();
                    int t3 = *lft.rbegin();
                    mid.erase(t2);
                    lft.erase(t3);
                    mid.insert(t3);
                    lft.insert(t2);
                    sum2 += t3 - t2;
                }
            }
//            cout<<"133333"<<endl;
            while (!rgh.empty() && !mid.empty() && *rgh.begin() < *mid.rbegin())
            {
                int t2 = *rgh.begin();
                rgh.erase(rgh.begin());
                mid.insert(t2);
                sum2 += t2;
            }
//            cout<<"144444"<<endl;
            while (!mid.empty() && !lft.empty() && *mid.begin() < *lft.rbegin())
            {
                int t2 = *lft.rbegin();
                lft.erase(t2);
                mid.insert(t2);
                sum2 += t2;
            }
//            cout<<"155555"<<endl;
            cout<<lft.size()<<" -1 "<<mid.size()<<endl;
            while (lft.size() < k & !mid.empty())
            {
                int t2 = *mid.begin();
                mid.erase(t2);
                lft.insert(t2);
                sum2 -= t2;
            }
            cout<<rgh.size()<<" -2 "<<mid.size()<<endl;
//            cout<<"16666"<<endl;
            while (rgh.size() < k & !mid.empty())
            {
                int t2 = *mid.rbegin();
                mid.erase(t2);
                rgh.insert(t2);
                sum2 -= t2;
            }
            #ifdef __test
            //cout<<" - "<<sum2<<endl;
            #endif // __test
//            cout<<"17777"<<endl;

//            while (lft.size() > k)            // 应该不会发生。
//            {
//
//            }
//            while (mid.size() > (m - k * 2))
//            {
//
//            }
        }
    }

    int calculateMKAverage() {
        if (deq.size() < m)
            return -1;
        return sum2 / (m - 2 * k);
    }
};


int main()
{

    LT1825 lt;

    MKAverage obj(3, 1);
    obj.addElement(3);        // current elements are [3]
    obj.addElement(1);        // current elements are [3,1]
    cout<<endl<<obj.calculateMKAverage(); // return -1, because m = 3 and only 2 elements exist.
    obj.addElement(10);       // current elements are [3,1,10]
    cout<<endl<<obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
                              // After removing smallest and largest 1 element the container will be [3].
                              // The average of [3] equals 3/1 = 3, return 3
    obj.addElement(5);        // current elements are [3,1,10,5]
    obj.addElement(5);        // current elements are [3,1,10,5,5]
    obj.addElement(5);        // current elements are [3,1,10,5,5,5]
    cout<<endl<<obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
                              // After removing smallest and largest 1 element the container will be [5].
                              // The average of [5] equals 5/1 = 5, return 5


    return 0;
}
