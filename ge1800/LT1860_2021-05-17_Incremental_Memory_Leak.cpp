
#include "../header/myheader.h"

class LT1860
{
public:

// D D

//		for (int i = 1;; i++) {
//			if (i > m1 && i > m2)return { i,m1,m2 };
//			if (m1 >= m2)m1 -= i;
//			else m2 -= i;
//		}


//https://leetcode.com/problems/incremental-memory-leak/discuss/1210210/Python-O(1)-Solution
//n**2 + i*n = x
// 很长。


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Incremental Memory Leak.
//Memory Usage: 6.1 MB, less than 75.00% of C++ online submissions for Incremental Memory Leak.
    vector<int> lt1860a(int memory1, int memory2)
    {
        int leak = 1;
        while (memory1 >= leak or memory2 >= leak)
        {
            if (memory1 >= memory2)
            {
                memory1 -= leak;
            }
            else
            {
                memory2 -= leak;
            }
            leak++;
        }
        return {leak, memory1, memory2};
    }

};

int main()
{
//    int m1{2}, m2{2};
    int m1{8}, m2{11};

    LT1860 lt;

    myvi v = lt.lt1860a(m1, m2);

    showVectorInt(v);

    return 0;
}
