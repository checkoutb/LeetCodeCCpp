
#include "../header/myheader.h"

class LT2349
{
public:



};

// D D



//    unordered_map<int, int> ind_num;
//    unordered_map<int, set<int>> num_inds;
//    void change(int index, int number) {
//        auto it = ind_num.find(index);
//        if (it != end(ind_num))
//            num_inds[it->second].erase(index);
//        ind_num[index] = number;
//        num_inds[number].insert(index);
//    }
//    int find(int number) {
//        auto it = num_inds.find(number);
//        return it == end(num_inds) || it->second.empty() ? -1 : *begin(it->second);
//    }
// 。。。






//Runtime: 637 ms, faster than 33.33% of C++ online submissions for Design a Number Container System.
//Memory Usage: 167.1 MB, less than 33.33% of C++ online submissions for Design a Number Container System.
// upsert 数字 到 下标
// 返回 数字的 最小下标
// 也是 pri_q ??????
class NumberContainers {

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map2;        // val - {idx}
    unordered_map<int, int> map3;       // idx - val

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        map2[number].push(index);
        map3[index] = number;
    }

    int find(int number) {
        while (!map2[number].empty())
        {
            int t2 = map2[number].top();
            if (map3[t2] == number)
                return t2;
            else
                map2[number].pop();
        }
        return -1;
    }
};



int main()
{

    LT2349 lt;


    return 0;
}
