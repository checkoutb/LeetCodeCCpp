
#include "../header/myheader.h"

// * class NestedInteger {
// *   public:
// *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
// *     bool isInteger() const;
// *
// *     // Return the single integer that this NestedInteger holds, if it holds a single integer
// *     // The result is undefined if this NestedInteger holds a nested list
// *     int getInteger() const;
// *
// *     // Return the nested list that this NestedInteger holds, if it holds a nested list
// *     // The result is undefined if this NestedInteger holds a single integer
// *     const vector<NestedInteger> &getList() const;
// * };

class NestedInteger
{
public:
    bool isInt;
    int i;
    vector<NestedInteger> list2;
    bool isInteger() const
    {
        return isInt;
    }
    int getInteger() const
    {
        return i;
    }
    const vector<NestedInteger>& getList() const
    {
        return list2;
    }
};




//Runtime: 20 ms, faster than 100.00% of C++ online submissions for Flatten Nested List Iterator.
//Memory Usage: 17.8 MB, less than 54.39% of C++ online submissions for Flatten Nested List Iterator.

// c++ is very very very very very very very very very very very difficult...


// 本来只有stk一个类变量，后来[[][]]炸了。所以增加了flag，next1.。next变成了next_self...
// flag 是为了防止 连续多次next。加个标记位来表示，next1是不是以前的。



class NestedIterator
{
private:
    stack<NestedInteger*> stk;
    bool flag = true;
    NestedInteger* next1;
public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        vector<NestedInteger> v1 = nestedList;            // ++，太难了，，+++++++， 应该是这里调用了 复制构造。导致 stk压栈的是 局部变量。
                                                                // 是的，v1的地址 和 nestedList不一样，，nestedList和外部的地址是一样的。+++++++
                                                                    // vector 重写了 operator=
        for (int i = v1.size() - 1; i >= 0; i--)
        {
            stk.push(&nestedList[i]);            // bad_alloc.
            #ifdef __test
            NestedInteger* nip2 = stk.top();
//            cout<<"init: "<<nip2->isInteger()<<"..."<<nip2->getInteger()<<"..sz : "<<nip2->getList().size()<<endl;
            cout<<"......                     "<<(int) nip2<<endl;
            #endif // __test
        }
        #ifdef __test
//        cout<<(int) &v1[0]<<endl;
//        cout<<(int) &nestedList[0]<<" . . . . .. . . . . .. . "<<endl;
//        cout<<stk.size()<<"      .."<<endl;
//        NestedInteger* nia1 = stk.top();
//        cout<<nia1->isInteger()<<endl;
        #endif // __test
    }

    int next()
    {
        if (flag)
        {
            hasNext();
        }
        flag = true;
        return this->next1->getInteger();
    }

    NestedInteger* next_self()
    {
        #ifdef __test
        cout<<"; ; ; "<<stk.size()<<endl;
        #endif // __test
        while (true)
        {
            if (stk.empty())
                return NULL;
            NestedInteger* ni = stk.top();
            stk.pop();
            #ifdef __test
            cout<<"zzz1  "<<ni->isInteger()<<"  ..  "<<ni->i<<endl;                 // 为什么会isInteger变成32？应该是0啊。。。
            cout<<".......                            "<<(int) ni<<endl;
            #endif // __test
            if (ni->isInteger())
            {
//                return ni->getInteger();
                return ni;
            }
            else
            {
                const vector<NestedInteger> v3 = ni->getList();

                #ifdef __test
//                cout<<"zzzsswd  "<<(int) &v3[0]<<" ..... "<<(int) &ni->getList()[0]<<endl;        // 不一样。。
                #endif // __test

                for (int i = v3.size() - 1; i >= 0; i--)
                {
//                    NestedInteger ni3a = v3[i];
//                    stk.push(&ni3a);            // 直接 &v3[i] 会报错。。真难。。。
                    NestedInteger& ni3a = const_cast<NestedInteger&>(ni->getList()[i]);

                    #ifdef __test
                    cout<<"zzzdqqq  "<<(int) &ni->getList()[i]<<" ... "<<(int) &ni3a<<endl;     // 不一样。/ 加上const ，， & 以后，一样了。，，但是push。。
                    #endif // __test

                    stk.push(&ni3a);            // 没有const type &，，所以只好 const_cast了。。
                }
            }
        }

        #ifdef __test
        cout<<"...."<<endl<<";;;;;"<<endl;
        #endif // __test

        return NULL;
    }

    bool hasNext()
    {
        #ifdef __test
//        NestedInteger* nia2 = stk.top();
//        cout<<"................  hasnext "<<nia2->isInteger()<<endl;
        #endif // __test
//        return !stk.empty();
        if (flag)
            this->next1 = next_self();
        flag = false;
        return this->next1 != NULL;
    }
};

int main()
{
    // [[1,1],2,[1,1]]

    NestedInteger ni;
    ni.isInt = true;
    ni.i = 1;
    NestedInteger n2;
    n2.isInt = true;
    n2.i = 1;
//    vector<NestedInteger> v1;
//    v1.push_back(ni);
//    v1.push_back(n2);
    NestedInteger nn1;
    nn1.isInt = false;
    nn1.i = -1;
    nn1.list2.push_back(ni);
    nn1.list2.push_back(n2);

    NestedInteger n4;
    n4.isInt = true;
    n4.i = 1;
    NestedInteger n5;
    n5.isInt = true;
    n5.i = 1;
    NestedInteger nn3;
    nn3.isInt = false;
    nn3.i = -2;
    nn3.list2.push_back(n4);
    nn3.list2.push_back(n5);

    NestedInteger n3;
    n3.isInt = true;
    n3.i = 2;

//    NestedInteger nnn1;
//    nnn1.isInt = false;
//    nnn1.list2.push_back(nn1);
//    nnn1.list2.push_back(n3);
//    nnn1.list2.push_back(nn3);

    vector<NestedInteger> va3;
    va3.push_back(nn1);
    va3.push_back(n3);
    va3.push_back(nn3);


    NestedIterator lt(va3);
//    cout<<lt.hasNext()<<endl;
//    cout<<lt.next()<<e;
//    cout<<lt.hasNext();

//    cout<<(int) &va3[0]<<" ...... waibu dizhi"<<endl;

    while (lt.hasNext())
    {
        cout<<"..                    >>>>>>>>>>>>>>>>  "<<lt.next()<<endl;
    }

    return 0;
}
