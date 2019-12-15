#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED 1


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

//------
#include "listnode.h"
#include "treenode.h"

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

#endif // MYHEADER_H_INCLUDED

using namespace std;
