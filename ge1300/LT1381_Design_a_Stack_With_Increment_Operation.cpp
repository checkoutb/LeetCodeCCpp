
#include "../header/myheader.h"

class LT1381
{
public:



};

// D D

//    void push(int x) {
//        if (stack.size() == n) return;
//        stack.push_back(x);
//        inc.push_back(0);
//    }
//
//    int pop() {
//        int i = stack.size() - 1;
//        if (i < 0) return -1;
//        if (i > 0) inc[i - 1] += inc[i];
//        int res = stack[i] + inc[i];
//        stack.pop_back();
//        inc.pop_back();
//        return res;
//    }
//
//    void increment(int k, int val) {
//        int i = min(k, (int)stack.size()) - 1;
//        if (i >= 0) inc[i] += val;
//    }



//Runtime: 44 ms, faster than 97.31% of C++ online submissions for Design a Stack With Increment Operation.
//Memory Usage: 21.4 MB, less than 43.76% of C++ online submissions for Design a Stack With Increment Operation.
class CustomStack {
    vector<int> vi;
    int mxsz;
public:
    CustomStack(int maxSize) {
        this->mxsz = maxSize;
    }

    void push(int x) {
        if (vi.size() < mxsz)
            vi.push_back(x);
    }

    int pop() {
        if (vi.empty())
            return -1;
        int bk = vi.back();
        vi.pop_back();
        return bk;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < vi.size(); ++i)
        {
            vi[i] += val;
        }
    }
};


int main()
{

    LT1381 lt;


    return 0;
}
