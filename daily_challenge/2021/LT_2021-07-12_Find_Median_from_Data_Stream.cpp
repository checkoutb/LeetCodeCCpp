
#include "../../header/myheader.h"

class LT
{
public:



};

// D D

// 都是2个priq的。


//    if (even) {
//        large.offer(num);
//        small.offer(large.poll());
//    } else {
//        small.offer(num);
//        large.offer(small.poll());
//    }
// 放到另一个，然后拿另一个的top


//        large.add((long) num);
//        small.add(-large.poll());
//        if (large.size() < small.size())
//            large.add(-small.poll());


//。。
//07/12/2021 09:02	Accepted	172 ms	46.9 MB	cpp
//07/12/2021 08:54	Wrong Answer	N/A	N/A	cpp
//04/23/2021 10:51	Accepted	196 ms	25.5 MB	python3
//04/23/2021 10:50	Output Limit Exceeded	N/A	N/A	python3
//11/30/2018 17:06	Time Limit Exceeded	N/A	N/A	java
//11/30/2018 16:25	Time Limit Exceeded	N/A	N/A	java
//11/30/2018 16:09	Wrong Answer	N/A	N/A	java

// AC           172ms, beats 17.5% ....    但我感觉 2个heap，应该是够快的啊，还能怎么更快？
// 2heap
class MedianFinder {

    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

        // empty.
        if (minq.empty())
        {
            minq.push(num);
            return;
        }

        if (minq.size() <= maxq.size())         // minq's elements >= maxq's
        {
            if (maxq.top() > num)
            {
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(num);
            }
            else
            {
                minq.push(num);
            }
        }
        else
        {
            if (minq.top() >= num)
            {
                maxq.push(num);
            }
            else
            {
                maxq.push(minq.top());
                minq.pop();
                minq.push(num);
            }
        }
    }

    double findMedian() {
        if (minq.size() > maxq.size())
        {
            return minq.top();
        }
        else
        {
            return ((double) minq.top() + (double) maxq.top()) / 2.0;
        }
    }
};


int main()
{
//    priority_queue<int> priq;
//    priq.push(3);
//    priq.push(5);
//    cout<<priq.top()<<endl;               // max-heap


    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout<<endl<<medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout<<endl<<medianFinder.findMedian(); // return 2.0

//    medianFinder.addNum(40);
//    medianFinder.addNum(12);
//    medianFinder.addNum(16);
//    cout<<endl<<medianFinder.findMedian();


    LT lt;


    return 0;
}
