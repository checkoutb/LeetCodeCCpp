
#include "../header/myheader.h"

bool myComp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second;
}

class LT0420
{
public:




// details
//            if (isupper(s[i]))
//                has_upper = true;
//            if (islower(s[i]))
//                has_lower = true;
//            if (isdigit(s[i]))
//                has_digit = true;





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Strong Password Checker.
//Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Strong Password Checker.


    int lt0420a(string s)
    {
        int ans = 0;
        int sz1 = s.size();
        vector<pair<int, int>> v2;
        char last1 = '\0';
        int count1 = 0;
        int type = 0;
        int i = 0;
        int delSum = 0;
        int sumCount = 0;
        for (char ch : s)
        {
            if (ch == last1)
            {
                count1++;
            }
            else
            {
                if (count1 >= 3)
                {
                    v2.push_back(make_pair(i - count1, count1));
                    sumCount += count1;
                    delSum += (count1 - 2);
                }
                if (ch <= '9')
                {
                    type |= 1;
                }
                else if (ch <= 'Z')
                {
                    type |= 2;
                }
                else
                {
                    type |= 4;
                }
                count1 = 1;
            }
            i++;
            last1 = ch;
        }
        if (count1 >= 3)
        {
            v2.push_back(make_pair(i - count1, count1));
            sumCount += count1;
            delSum += (count1 - 2);
        }

        type = (type & 1) + ((type & 2) >> 1) + ((type & 4) >> 2);

        #ifdef __test
        cout<<type<<endl;
        sort(v2.begin(), v2.end(), myComp);
        cout<<sz1<<endl;
        if (v2.empty())
        {
            cout<<"v2 empty"<<endl;
        }
        else
        {
            cout<<"v2 : "<<endl;
            for (auto& p : v2)
            {
                cout<<p.first<<" : "<<p.second<<endl;
            }
            cout<<"v2 end"<<endl;
        }
        #endif // __test

        if (type == 3 && sz1 >= 6 && sz1 <= 20 && v2.empty())
            return 0;

        if (sz1 < 6)
        {
            int insert1 = 6 - sz1;
            ans = max(3 - type, insert1);
        }
        else if (sz1 > 20)
        {
            int del1 = sz1 - 20;
            del1 = del1 > delSum ? del1 : del1;
            sort(v2.begin(), v2.end(), myComp);         // 无意义了。
            int t1 = 0;
//            for (vector<pair<int, int>>::iterator it2 = v2.begin(); it2 != v2.end();)
//            {
////                if ((*it2).second - 2 <= del1)
////                {
////                    del1 -= (*it2).second - 2;
////                    it2 = v2.erase(it2);                // erase后，iterator的遍历行为不可预知。。vector需要通过erase的返回。。map可以在for中it++，当然erase返回也可以。
////                }
////                else
////                {
////                    (*it2).second = (*it2).second - del1;
////                    del1 = 0;
////                    break;
////                }
//
//
//                if ((*it2).second % 3 == t1 % 3)
//                {
//                    (*it2).second = (*it2).second - (t1 % 3 + 1 + (del1 >= 0 ? 0 : del1));
//
//                    if (del1 >= t1 % 3 + 1)
//                    {
//                        del1 -= (t1 % 3 + 1);
//                        (*it2).second = (*it2).second - (t1 % 3 + 1);
//                    }
//                    else
//                    {
//                        t1 = 0;
//                        it2 = v2.begin();
//                    }
//
//                    if ((*it2).second < 3)
//                    {
//                        it2 = v2.erase(it2);
//                    }
//                    else
//                    {
//                        it2++;
//                    }
//                }
//                else
//                {
//                    it2++;
//                }
//                if (del1 <= 0)
//                {
//                    break;
//                }
//                t1++;
//            }

            bool changed = true;
            while (changed)
            {
                changed = false;
//                t1 = t1 % 3 + 1;

                for (int t1 = 1; t1 <= 3; t1++)
                {
                    if (del1 == 0)
                        break;
                    for (vector<pair<int, int>>::iterator it2 = v2.begin(); it2 != v2.end();)
                    {
                        if (del1 == 0)
                            break;
                        if ((*it2).second % 3 == t1 - 1)            // 优先减 3,6,9,长度的。4，7，10优先级往后。
                        {
                            if (del1 >= t1)
                            {
                                del1 -= t1;
                                (*it2).second = (*it2).second - t1;
                                if ((*it2).second < 3)
                                {
                                    it2 = v2.erase(it2);
                                }
                                changed = true;
                                if (del1 == 0)
                                    break;

                                continue;
                            }
                        }
                        it2++;
                    }
                }
                if (del1 == 0)
                    break;
//                t1++;
            }

            #ifdef __test
            cout<<"del1 "<<del1<<"  change: "<<changed<<endl;
            #endif // __test

//            if (del1 > 0 || !changed)
//            {
//                ans = sz1 - 20 + (3 - type);
//            }
//            else
//            {
                int change1 = 0;
                for (pair<int, int> p : v2)
                {
                    change1 += (p.second / 3);
                }
                ans = max(change1, 3 - type) + sz1 - 20;
//            }
        }
        else
        {
            int change1 = 0;
            for (pair<int, int> p : v2)
            {
                change1 += p.second / 3;
            }
            ans = max(change1, 3 - type);
        }
        return ans;
    }
};

int main()
{
//    string s = "aaaabbaaabbaaa123456A";     // 38/42 excepted:3

//    string s = "AAAAAABBBBBB123456789a";        // 39/42   4

//    string s = "1010101010aaaB10101010";        // 17/42  heap buffer overflow...本地不越界。。

    string s = "1234567890123456Baaaaa";        // 也是38/42...3


    LT0420 lt;
    cout<<endl<<lt.lt0420a(s)<<endl;

    return 0;
}
