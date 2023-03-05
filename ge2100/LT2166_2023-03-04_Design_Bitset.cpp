
#include "../header/myheader.h"

class LT2166
{
public:



};

// D D

//int size;
//Set<Integer> one = new HashSet<>();
//Set<Integer> zero = new HashSet<>();
//public Bitset(int size) {
//    this.size = size;
//    for (int i = 0; i < size; i++) zero.add(i);
//}



//int a = 0, sz = 0, cnt = 0, isFlip = 0;
//string s;
//Bitset(int size) {
//    sz = size;
//    s = string(sz, '0');
//}
//
//void fix(int idx) {
//    if (s[idx] == '0' + isFlip) {
//        s[idx] = '1' + '0' - s[idx];
//        cnt++;
//    }
//}
//
//void unfix(int idx) {
//    if (s[idx] == '1' - isFlip) {
//        s[idx] = '1' + '0' - s[idx];
//        cnt--;
//    }
//}
//
//void flip() {
//    isFlip ^= 1;
//    cnt = sz - cnt;
//}





// unsigned.

//Runtime419 ms
//Beats
//89.32 %
//Memory195.1 MB
//Beats
//97.9 %
class Bitset {

    int sz1;
    vector<int> vi;
    int cnt;
    bool flp;

public:
    Bitset(int size) {
        this->sz1 = size;
        this->vi = vector<int>((size + 31) / 32, 0);
        this->cnt = 0;
        this->flp = false;
    }

    void fix(int idx) {     // to 1
        int i = idx / 32;
        int j = idx % 32;
        if (!this->flp)
            if ((this->vi[i] & (1 << j)) != 0)
            {
                ;
            }
            else
            {
                ++(this->cnt);
                this->vi[i] |= (1 << j);
            }
        else
            // to 0
            if ((this->vi[i] & (1 << j)) != 0)
            {
                ++(this->cnt);
                this->vi[i] ^= (1 << j);
            }
    }

    void unfix(int idx) {       // to 0
        int i = idx / 32;
        int j = idx % 32;
        if (!this->flp)
        {
            if ((this->vi[i] & (1 << j)) != 0)
            {
                --(this->cnt);
                this->vi[i] ^= (1 << j);
            }
        }
        else
        {
            if ((this->vi[i] & (1 << j)) != 0)
            {
                ;
            }
            else
            {
                --(this->cnt);
                this->vi[i] |= (1 << j);
            }
        }
    }

    void flip() {
        this->flp = !this->flp;
        this->cnt = this->sz1 - this->cnt;

        //int i = idx / 32;
        //int j = idx % 32;
        //if ((this->vi[i] & (1 << j)) != 0)
        //{
        //    --(this->cnt);
        //    this->vi[i] ^= (1 << j);
        //}
        //else
        //{
        //    ++(this->cnt);
        //    this->vi[i] |= (1 << j);
        //}
    }

    bool all() {
        return this->count() == this->sz1;
    }

    bool one() {
        return this->count() != 0;
    }

    int count() {
        //if (this->flp)
        //    return this->sz1 - this->cnt;
        return this->cnt;
    }

    string toString() {

        if (this->flp)
        {
            string ans(this->sz1, '1');
            for (int i = 0; i < sz1; ++i)
                if ((this->vi[i / 32] & (1 << (i % 32))) != 0)
                    ans[i] = '0';
            return ans;
        }
        else
        {
            string ans(this->sz1, '0');
            for (int i = 0; i < this->sz1; ++i)
            {
                if ((this->vi[i / 32] & (1 << (i % 32))) != 0)
                    //ans[sz1 - 1 - i] = '1';
                    ans[i] = '1';
            }
            //reverse(begin(ans), end(ans));
            return ans;
        }
    }
};



int main()
{

    LT2166 lt;

    Bitset bs(5);
    bs.fix(3);
    cout << bs.toString() << endl;
    cout << bs.count() << endl;
    bs.fix(1);
    cout << bs.toString() << endl;
    cout << bs.count() << endl;
    bs.flip();
    cout << bs.toString() << endl;
    cout << bs.count() << endl;
    cout << bs.all() << endl;
    bs.unfix(0);
    cout << bs.toString() << endl;
    cout << bs.count() << endl;
    bs.flip();
    cout << bs.toString() << endl;
    cout << bs.count() << endl;
    cout << bs.one() << endl;

    bs.unfix(0);
    cout << bs.toString() << endl;
    cout << bs.count() << endl;

    return 0;
}
