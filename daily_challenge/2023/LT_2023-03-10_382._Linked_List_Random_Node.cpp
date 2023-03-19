
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //int getRandom() {
    //    int ans = 0, i = 1;
    //    ListNode* p = this->head;
    //    while (p) {
    //        if (rand() % i == 0) ans = p->val; // replace ans with i-th node.val with probability 1/i
    //        i++;
    //        p = p->next;
    //    }
    //    return ans;
    //}

    // 还有 一种是转成 vector， 一种是每次从head开始后移rand步。



    //Runtime28 ms
    //    Beats
    //    33.38 %
    //    Memory16.8 MB
    //    Beats
    //    26.59 %
    // 转vector， 然后 vi[random(0, sz1 - 1)]
    // 看了下onenote, 水塘抽样算法，水塘的大小是1， 就可以 应对 无限长度的， 但这里不适用。
    // 不用额外空间，想不出。
    // 而且 继续list 的话， 每次取 值 都需要遍历 半个 list，感觉tle 的。
    // 感觉是 循环列表，然后 每次 移动 random 个。 但是 会tle吧。 1w * 1w = 1e
    // topic 中有 水塘抽样，但是。。怎么应用？
    Solution(ListNode* head) {
        while (head != nullptr)
        {
            this->vi.push_back(head->val);
            head = head->next;
        }
        this->sz1 = vi.size();
        srand(time(nullptr));
    }

    int getRandom() {
        return this->vi[rand() % this->sz1];
    }

private:
    vector<int> vi;
    int sz1;

};

int main()
{

    LT lt;


    return 0;
}
