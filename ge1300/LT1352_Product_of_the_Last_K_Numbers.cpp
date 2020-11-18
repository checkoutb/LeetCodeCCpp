
#include "../header/myheader.h"

class LT1352
{
public:



};

// D D

//        if (num == 0) pr = {1};
//        else pr.push_back(pr.back() * num);
//
//        if (k >= pr.size()) return 0;
//        else return pr.back() / pr[pr.size() - 1 - k];


//    vector<int> A = {1};
//    void add(int a) {
//        if (a)
//            A.push_back(A.back() * a);
//        else
//            A = {1};
//    }
//
//    int getProduct(int k) {
//        return k < A.size() ? A.back() / A[A.size() - k - 1]  : 0;
//    }



//Runtime: 232 ms, faster than 76.12% of C++ online submissions for Product of the Last K Numbers.
//Memory Usage: 70.6 MB, less than 37.86% of C++ online submissions for Product of the Last K Numbers.
class ProductOfNumbers {
    vector<int> vi;
    int last0;
public:
    ProductOfNumbers() {
        vi.push_back(1);
        last0 = -1;
    }

    void add(int num) {
        if (num == 0)
        {
            last0 = vi.size();
            vi.push_back(1);
        }
        else
        {
            vi.push_back(num * vi.back());
        }
    }

    int getProduct(int k) {
        if (((int) vi.size() - k) <= last0)                 // size_type ....
            return 0;
        return vi.back() / vi[vi.size() - k - 1];
    }
};


int main()
{
    ProductOfNumbers pn;
//    pn.add(3);
//    pn.add(0);      // ...
//    pn.add(2);
//    pn.add(5);
//    pn.add(4);
//    cout<<endl<<pn.getProduct(2);
//    cout<<endl<<pn.getProduct(3);
//    cout<<endl<<pn.getProduct(4);
//    pn.add(8);
//    cout<<endl<<pn.getProduct(2);

    pn.add(1);
    cout<<endl<<pn.getProduct(1);
    cout<<endl<<pn.getProduct(1);


    LT1352 lt;


    return 0;
}
