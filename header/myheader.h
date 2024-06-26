#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED 1
using namespace std;

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <climits>

#include <unordered_set>
#include <unordered_map>

#include <time.h>
//#include <windows.h>      // ubuntu g++7.4 cannot find this file

#include <numeric>

#include <sstream>

#include <array>

#ifndef __test
#define __test 1
#endif // TEST

void fun_cout(int i)
{
    cout<<i<<", ";
}

void fun_cout_s(string s)
{
    cout<<"f_cout_s :"<<s<<"; "<<endl;
}

void show_stack_int(stack<int> stk)
{
    cout<<endl<<"...stack...start..."<<endl;
    while (!stk.empty())
    {
        cout<<stk.top()<<endl;
        stk.pop();
    }
    cout<<"...stack....end...."<<endl<<endl;
}

//------
#include "listnode.h"
#include "treenode.h"
#include "mytool.h"     // 里面使用到了 fun_cout，所以需要 在fun_cout定义后包含。

#endif // MYHEADER_H_INCLUDED


