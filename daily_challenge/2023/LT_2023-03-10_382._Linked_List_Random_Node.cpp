
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

    // ���� һ����ת�� vector�� һ����ÿ�δ�head��ʼ����rand����



    //Runtime28 ms
    //    Beats
    //    33.38 %
    //    Memory16.8 MB
    //    Beats
    //    26.59 %
    // תvector�� Ȼ�� vi[random(0, sz1 - 1)]
    // ������onenote, ˮ�������㷨��ˮ���Ĵ�С��1�� �Ϳ��� Ӧ�� ���޳��ȵģ� �����ﲻ���á�
    // ���ö���ռ䣬�벻����
    // ���� ����list �Ļ��� ÿ��ȡ ֵ ����Ҫ���� ��� list���о�tle �ġ�
    // �о��� ѭ���б�Ȼ�� ÿ�� �ƶ� random ���� ���� ��tle�ɡ� 1w * 1w = 1e
    // topic ���� ˮ�����������ǡ�����ôӦ�ã�
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
