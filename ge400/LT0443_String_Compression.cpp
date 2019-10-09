
#include "../header/myheader.h"

class LT0443
{
public:



// details
// 碰到一个char，直接前向遍历到不同的char为止。。
// to_string(int).....
// 遇到一个char，可以直接chars[j++] = ch; 不必在 num处存放。


// discuss
// if(end == chars.length-1 || chars[end] != chars[end + 1] ) {
// 做为触发num的条件。
// java String.valueOf(count).toCharArray();

// 直接记录开始，和结束，而不是++。记录本char的开始下标，当char不同时，直接当前下标-之前记录的下标。


// chars 也得改。。ans == j。。

//Runtime: 8 ms, faster than 85.27% of C++ online submissions for String Compression.
//Memory Usage: 9.2 MB, less than 83.33% of C++ online submissions for String Compression.

    int lt0443a(vector<char>& chars)
    {
        int ans = 0;
        char pre = chars[0];
        int num = 1;
        int sz1 = chars.size();
        int j = 0;
        for (int i = 1; i < sz1; i++)
        {
            char ch = chars[i];
            if (ch == pre)
            {
                num++;
            }
            else
            {
                if (num > 1)
                {
                    ans++;
                    chars[j++] = pre;
                    int t1 = 1;
                    while (t1 <= num)
                        t1 *= 10;
                    t1 /= 10;
                    while (t1 > 0)
                    {
                        ans++;
                        chars[j++] = num / t1 + '0';
                        num %= t1;
                        t1 /= 10;
                    }
                }
                else
                {
                    ans++;
                    chars[j] = pre;
                    j++;
                }
                num = 1;
            }
            pre = ch;
        }
        if (num > 1)
        {
            ans++;
            chars[j++] = pre;
            int t1 = 1;
            while (t1 <= num)
                t1 *= 10;
            t1 /= 10;
            while (t1 > 0)
            {
                ans++;
                chars[j++] = num / t1 + '0';
                num %= t1;
                t1 /= 10;
            }
        }
        else
        {
            ans++;
            chars[j] = pre;
            j++;
        }
        chars.resize(j);
        return ans;
    }
};

int main()
{
    vector<char> vArr[] = {{'a','a','b','b','c','c','c','c','c'},{'a'},
            {'a','b','b','b','b','b','b','b','b','b','b','b','b','b'}
            ,{'o','o','o','o','o','o','o','o','o','o'}};

    LT0443 lt;
    for(vector<char> v : vArr)
    {
        cout<<endl<<" result : "<<lt.lt0443a(v)<<endl;
        for(int i = 0; i < v.size(); i++)
            cout<<v[i]<<", ";
//        cout<<endl;
    }

    return 0;
}
