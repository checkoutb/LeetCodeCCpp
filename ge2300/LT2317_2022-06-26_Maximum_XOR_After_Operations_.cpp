
#include "../header/myheader.h"

class LT2317
{
public:

    // D D


    // return reduce(nums.begin(), nums.end(), 0, bit_or());
    // cpp

    // return accumulate(begin(nums), end(nums), 0, bit_or<int>());



//Runtime: 113 ms, faster than 50.00 % of C++ online submissions for Maximum XOR After Operations .
//Memory Usage : 48.1 MB, less than 50.00 % of C++ online submissions for Maximum XOR After Operations .
    // �о� ֻҪ ��� bit ���ֹ�����ô�϶��ܴ����� ans�С�
    // ȷʵ��ֻ��Ҫ ��� bit ���ֹ��� �� �������ֵ� ��bit ���ó�0 ��ok �ˡ�
    int lt2317a(vector<int>& nums)
    {
        int ans = 0;
        for (int n : nums)
        {
            ans |= n;
        }
        return ans;
    }

};

int main()
{

    LT2317 lt;

    //myvi v = { 3,2,4,6 };
    myvi v = { 1,2,3,9,2 };

    cout << lt.lt2317a(v) << endl;

    return 0;
}
