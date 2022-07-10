
#include "../header/myheader.h"

class LT2336
{
public:



};


// D D

// priority queue
// set



// ������Լ�¼�� ��Сֵ�����pop������ô�´� pop �ʹ� �����Сֵ��ʼ�ң� ���addBack ��С�� ��Сֵ����ôˢ����Сֵ��
//Runtime: 151 ms, faster than 100.00 % of C++ online submissions for Smallest Number in Infinite Set.
//Memory Usage : 35.1 MB, less than 100.00 % of C++ online submissions for Smallest Number in Infinite Set.
class SmallestInfiniteSet {
    //vector<int> vi(1001)

    bitset<1001> notExist;      // [0,0,0...]

public:
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        for (int i = 1; i < 1001; ++i)
        {
            if (!notExist[i])
            {
                notExist.set(i);
                return i;
            }
        }
        return -1;
    }

    void addBack(int num) {
        notExist.reset(num);
    }
};



int main()
{

    LT2336 lt;


    return 0;
}
