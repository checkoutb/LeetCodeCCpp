
#include "../header/myheader.h"

class LT0895
{
public:



};

// D D
//    int maxfreq;
//    unordered_map<int, int>cnt;
//    unordered_map<int, stack<int>>rf;

//    multimap<int, int, greater_equal<int>> stack;
//    unordered_map<int, int> freq;


//    unordered_map<int, int> freq;
//    unordered_map<int, stack<int>> m;
//    int maxfreq = 0;
//
//    void push(int x) {
//        maxfreq = max(maxfreq, ++freq[x]);
//        m[freq[x]].push(x);
//    }
//
//    int pop() {
//        int x = m[maxfreq].top();
//        m[maxfreq].pop();
//        if (!m[freq[x]--].size()) maxfreq--;          // .
//        return x;
//    }



// most are 150 - 200
// heap ? or map<count, vector<int>> ?
//Runtime: 400 ms, faster than 8.24% of C++ online submissions for Maximum Frequency Stack.
//Memory Usage: 79 MB, less than 91.69% of C++ online submissions for Maximum Frequency Stack.
class FreqStack {
    priority_queue<tuple<int, int, int>> priq;      // <count, time, value>
    int tm = 1;
    unordered_map<int, int> map2;       // value, count
public:
    FreqStack() {

    }

    void push(int val) {
        int cnt = map2[val];
        map2[val] = ++cnt;
        priq.push(std::make_tuple(cnt, tm++, val));
    }

    int pop() {
        tuple<int, int, int> tp = priq.top();
        priq.pop();
        int t2 = std::get<2>(tp);
        map2[t2]--;
        return t2;
    }
};


int main()
{


    FreqStack freqStack;
    freqStack.push(5); // The stack is [5]
    freqStack.push(7); // The stack is [5,7]
    freqStack.push(5); // The stack is [5,7,5]
    freqStack.push(7); // The stack is [5,7,5,7]
    freqStack.push(4); // The stack is [5,7,5,7,4]
    freqStack.push(5); // The stack is [5,7,5,7,4,5]
    cout<<endl<<freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout<<endl<<freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout<<endl<<freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout<<endl<<freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].


    LT0895 lt;


    return 0;
}
