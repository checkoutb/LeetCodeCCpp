
#include "../header/myheader.h"


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *


 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *



 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */



class NestedInteger
{
public:
    void setInteger(int v)
    {
        cout<<"  int: "<<v<<endl;
    }

    void add(const NestedInteger &ni)
    {
        cout<<"  list:"<<endl;
    }
};


class Solution {
public:


    NestedInteger deserialize(string s) {
        return recursiona3(s);
    }







// 不容易。。。。details中标杆是20ms。。。。。。
//Runtime: 128 ms, faster than 5.24% of C++ online submissions for Mini Parser.
//Memory Usage: 355.1 MB, less than 5.03% of C++ online submissions for Mini Parser.


// details：
//isdigit

// 12ms
//        if(s.size()==0) return NestedInteger();
//        if(s[0]!='[') return NestedInteger(stoi(s));
//        if(s.size()<=2) return NestedInteger();
//        int start = 1;
//        int depth = 0;
//        NestedInteger result;
//        for(int i=1;i<s.size();++i)
//        {
//            if(depth == 0 && (s[i]==',' || i==s.size()-1))
//            {
//                result.add(deserialize(s.substr(start, i-start)));
//                start = i+1;
//            }
//            else if(s[i]=='[') depth++;
//            else if(s[i]==']') depth--;
//        }
//        return result;
// 递归，用depth记录[]，来决定是否是需要加到result中。!=0说明是 (非本层)/(子元素) 的元素. >0说明是子元素的，<0说明是父元素的。<0应该可以直接return出去吧。
// 第二行。。不，没问题。。。传进去的就是substr(start, i-start);..所以i从1开始，不是start+1.做了切割。
// ,做为分隔符。并且是depth为0时，,做为分隔符。


// 16ms
//        vector<NestedInteger> stack;
//        int sign=1, number=0;
//        bool isNum = false;
//        for(int i=0;i<s.length();i++){
//            if(s[i]=='[') stack.push_back(NestedInteger());
//            else if(s[i]==',') {
//                if(stack.empty() && isNum) stack.push_back(NestedInteger(number*sign));
//                else if(isNum) stack.back().isInteger()?stack.push_back(NestedInteger(number*sign)):stack.back().add(NestedInteger(number*sign));
//                number=0;sign=1, isNum = false;
//            }
//            else if(s[i]=='-') sign = -1;
//            else if(s[i]==']') {
//                NestedInteger list = stack.back();
//                if(isNum) list.add(NestedInteger(number*sign));
//                number=0; sign=1;isNum=false;
//                stack.pop_back();
//                stack.empty()?stack.push_back(list):stack.back().add(list);
//            }
//            else if(s[i]>='0'&&s[i]<='9') {
//                number=number*10+(s[i]-'0');
//                isNum=true;
//            }
//        }
//        if(stack.empty()) stack.push_back(NestedInteger(number*sign));
//        else if(stack.back().isInteger() && isNum ) stack.push_back(NestedInteger(number*sign));
//        return stack.front();
// stack


// 20ms
//    NestedInteger helper(string &s, int &idx) {
//        if (isdigit(s[idx]) || s[idx] == '-') {
//            int length = 1;
//            while(isdigit(s[idx+length])) length++;
//            idx += length;
//            return NestedInteger(stoi(s.substr(idx-length, length)));
//        }
//        else {
//            NestedInteger ni;
//            idx++;
//            while(s[idx] != ']') {
//                ni.add(helper(s, idx));
//                if (s[idx] == ',') idx++;
//            }
//            idx++;
//            return ni;
//        }
//    }
// isdigit。。。idx初始为0.
// int&....所以整个过程只有一个idx。。。。。。。。。。。。。。所以能[[[]]]。。。



// discuss

// StefanPochmann
//    class Solution {
//    public:
//        NestedInteger deserialize(string s) {
//            istringstream in(s);
//            return deserialize(in);
//        }
//    private:
//        NestedInteger deserialize(istringstream &in) {
//            int number;
//            if (in >> number)
//                return NestedInteger(number);
//            in.clear();
//            in.get();
//            NestedInteger list;
//            while (in.peek() != ']') {
//                list.add(deserialize(in));
//                if (in.peek() == ',')
//                    in.get();
//            }
//            in.get();
//            return list;
//        }
//    };
// istringstream        https://en.cppreference.com/w/cpp/io/basic_istringstream
// in >> number
// in.clear();      in.get();


// zhiqing_xiao
//        function<bool(char)> isnumber = [](char c){ return (c == '-') || isdigit(c); };
//        stack<NestedInteger> stk;
//        stk.push(NestedInteger());
//        for (auto it = s.begin(); it != s.end();) {
//            const char & c = (*it);
//            if (isnumber(c)) {
//                auto it2 = find_if_not(it, s.end(), isnumber);
//                int val = stoi(string(it, it2));
//                stk.top().add(NestedInteger(val));
//                it = it2;
//            }
//            else {
//                if (c == '[') {
//                    stk.push(NestedInteger());
//                }
//                else if (c == ']') {
//                    NestedInteger ni = stk.top();
//                    stk.pop();
//                    stk.top().add(ni);
//                }
//                ++it;
//            }
//        }
//        NestedInteger result = stk.top().getList().front();
//        return result;
// find_if_not
// stk.top().getList().front();
// function<bool(char)> isnumber = [](char c){ return (c == '-') || isdigit(c); };。。。。函数式编程了。。。=后面就是lambda了。
// https://en.cppreference.com/w/cpp/utility/functional/function
// Class template std::function is a general-purpose polymorphic function wrapper.


// 有-号
    NestedInteger recursiona3(string s, int start = 0)
    {
        NestedInteger ni;

        #ifdef __test
        cout<<"..  "<<start<<endl;
        #endif // __test

        if (s[start] == '[')
        {
            // list
            // [[[1,2]],3]..如何直接跳到3.
            start++;
            while (s[start] != ']')
            {
                if (s[start] == '[')
                {
                    NestedInteger ni3 = recursiona3(s, start);
                    ni.add(ni3);
                    // 跳
                    int f1 = 1;
                    int i = start + 1;
                    while (f1 != 0)
                    {
                        if (s[i] == '[')
                            f1++;
                        else if (s[i] == ']')
                            f1--;
                        i++;
                    }
                    start = i - 1;
                }
                else if (s[start] == '-' || (s[start] >= '0' and s[start] <= '9'))
                {
                    NestedInteger ni3 = recursiona3(s, start);
                    ni.add(ni3);
                    // ...
                    int n1 = s.find_first_of(']', start);
                    int n2 = s.find_first_of(',', start);
                    int n3 = (n2 == -1 ? n1 : min(n2, n1));
                    start = n3 - 1;
                }
                start++;
            }
            return ni;
        }
//        else if (s[start] == ',')
//        {
//            return NULL;          // cannot convert int -> NestedInteger...
//        }
        else
        {
            int flag = 1;
            if (s[start] == '-')
            {
                start++;
                flag = -1;
            }
            int next1 = s.find_first_of(']', start);
            int next2 = s.find_first_of(',', start);
            next2 = (next2 == -1 ? INT_MAX : next2);
            int next3 = min(next1, next2);
            int val = std::stoi(s.substr(start, next3 - start));
            val = val * flag;
            ni.setInteger(val);
            return ni;
        }
    }


    // ....error
    NestedInteger recursiona2(string s, int start = 0)
    {
        NestedInteger ni;

        #ifdef __test
        cout<<"..i: "<<start<<endl;
        #endif // __test

        if (s[start] >= '0' && s[start] <= '9')
        {
            int i = start;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9')
            {
                i++;
            }
//            i--;

            string s23 = s.substr(start, i - start);

            #ifdef __test
            cout<<s23<<", "<<start<<", "<<i - start<<endl;
            #endif // __test

            int t1 = std::stoi(s23);
            ni.setInteger(t1);
        }
        else
        {
            int i = start + 1;
            int t11 = 1;
            int i2 = i;
            while (t11 != 0)
            {
                if (s[i2] == '[')
                    t11++;
                else if (s[i2] == ']')
                    t11--;
                i2++;
            }
            if (start == i2 - 2)
                return ni;
            while (i < i2 && i != std::string::npos && i != -1)     // what is nops ?
            {

                #ifdef __test
                cout<<"--- i : "<<i<<endl;
                #endif // __test

                NestedInteger ni4 = recursiona2(s, i);
                ni.add(ni4);

                if (s[i] >= '0' && s[i] <= '9')
                {
                    int i4 = s.find_first_of(',', i);
                    int i5 = s.find_first_of(']', i);
                    i4 = i4 == -1 ? INT_MAX : i4;
//                    i5 = i5 == -1 ? INT_MAX : i5;
                    i = min(i4, i5);
                }
                else
                {
                    int t15 = 1;
                    int i3 = i + 1;
                    while (t15 != 0)
                    {
                        if (s[i3] == '[')
                            t15++;
                        else if (s[i3] == ']')
                            t15--;
                        i3++;
                    }
                    i = s.find_first_of(',', i3);        // [,,]

                    #ifdef __test
                    cout<<"++ i : "<<i<<", "<<i2<<", "<<i3<<", "<<std::string::npos<<endl;
                    #endif // __test
                }
            }
        }

        return ni;
    }


// ..."324"...
// error
    NestedInteger recursiona1(string s, int start = 0)
    {
        NestedInteger ni;

        int t3 = s.find_first_of('[', start + 1);
        int t4 = s.find_first_of(']', start + 1);
        int t5 = s.find_first_of(',', start + 1);

        if (start == t4 - 1)
            return ni;

        bool isList = (t3 != std::string::npos && t3 < t4) || (t5 != std::string::npos && t5 < t4);

        if (isList)
        {
            int i = start + 1;
            int t11 = 1;
            while (t11 != 0)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    t5 = s.find_first_of(',', i);
                    int t2 = std::stoi(s.substr(i, t5 - i));
                    NestedInteger ni2;
                    ni2.setInteger(t2);
                    ni.add(ni2);
                    t4 = s.find_first_of(']', i);
                    t5 = s.find_first_of(',', i);
                    i = min(t4, t5);
                }
                else if (s[i] == '[')
                {
                    t11++;
                    NestedInteger ni3 = recursiona1(s, i);
                    ni.add(ni3);
                    int t12 = 1;
                    int i12 = i + 1;
                    while (t12 != 0)
                    {
                        if (s[i] == '[')
                            t12++;
                        else if (s[i] == ']')
                            t12--;
                        i12++;
                    }
                    i = i12;
                }
                else if (s[i] == ']')
                {
                    t11--;
                }

                i++;
            }
        }
        else
        {
            int t1 = t4;
            int t2 = stoi(s.substr(start + 1, t1 - start - 1));
            ni.setInteger(t2);
        }
        return ni;
    }
};

// [123,[456,[789]]]


int main()
{
    Solution s;
    string str = "[123,[456,[789]]]";
    s.deserialize(str);
    return 0;
}
