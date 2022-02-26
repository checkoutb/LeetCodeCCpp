
#include "../header/myheader.h"

class LT2034
{
public:



};

// D D

//unordered_map<int, int> m;
//multiset<int> prices;
//int last_timestamp = 0, last_price = 0;


//    map<int, int> rec;
//    multiset<int> count;
//
//    void update(int t, int p) {
//        if (rec.find(t) != rec.end())
//            count.erase(count.find(rec[t]));
//        rec[t] = p;
//        count.insert(p);
//    }


//Runtime: 476 ms, faster than 85.52% of C++ online submissions for Stock Price Fluctuation .
//Memory Usage: 165.5 MB, less than 73.14% of C++ online submissions for Stock Price Fluctuation .
// 时间顺序，股价顺序
class StockPrice {
    map<int, int> tmap;     // time - price
    map<int, int> pmap;     // price - count
public:
    StockPrice() {

    }

    void update(int timestamp, int price) {
        if (tmap.find(timestamp) != end(tmap))
        {
            pmap[tmap[timestamp]]--;
        }
        tmap[timestamp] = price;
        pmap[price]++;
    }

    int current() {
        return rbegin(tmap)->second;
    }

    int maximum() {
        // no erase(reverse_iter)
        while (rbegin(pmap)->second == 0)
            pmap.erase(std::prev(end(pmap)));
        #ifdef __test
        cout<<"mxxxxx"<<endl;
        for (auto& p : pmap)
            cout<<p.first<<": "<<p.second<<endl;
        #endif // __test
        return rbegin(pmap)->first;
    }

    int minimum() {
        for (map<int, int>::iterator it = begin(pmap); it != end(pmap); )
        {
            if (it->second == 0)
            {
                pmap.erase(it++);
            }
            else
            {
                break;
            }
        }
        #ifdef __test
        cout<<"mnnnnn"<<endl;
        for (auto& p : pmap)
            cout<<p.first<<": "<<p.second<<endl;
        #endif // __test
        return begin(pmap)->first;
    }
};

int main()
{

    LT2034 lt;

    StockPrice stockPrice;
    stockPrice.update(1, 10); // Timestamps are [1] with corresponding prices [10].
    stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding prices [10,5].
    cout<<endl<<stockPrice.current();     // return 5, the latest timestamp is 2 with the price being 5.
    cout<<endl<<stockPrice.maximum();     // return 10, the maximum price is 10 at timestamp 1.
    stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong price, so it is updated to 3.
                              // Timestamps are [1,2] with corresponding prices [3,5].
    cout<<endl<<stockPrice.maximum();     // return 5, the maximum price is 5 after the correction.
    stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding prices [3,5,2].
    cout<<endl<<stockPrice.minimum();     // return 2, the minimum price is 2 at timestamp 4.


    return 0;
}
