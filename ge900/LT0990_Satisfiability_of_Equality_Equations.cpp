
#include "../header/myheader.h"

class LT0990
{
public:



//Runtime: 8 ms, faster than 89.76% of C++ online submissions for Satisfiability of Equality Equations.
//Memory Usage: 11.5 MB, less than 49.76% of C++ online submissions for Satisfiability of Equality Equations.

    bool lt0990c(vector<string>& equations)
    {
        vector<int> arr(123, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = i;
        }

        for (string& s : equations)
        {
            if (s[1] == '=')
            {
                arr[getc1(arr, s[0])] = getc1(arr, s[3]);
            }
        }
        for (string& s : equations)
        {
            if (s[1] == '!')
            {
                if (getc1(arr, s[0]) == getc1(arr, s[3]))
                    return false;
            }
        }
        return true;
    }

    int getc1(vector<int>& arr, char ch)
    {
        int t2 = ch;
        while (arr[t2] != t2)
        {
            t2 = arr[t2];
        }
        return t2;
    }

// error
// xian ==, zai !=
    bool lt0990b(vector<string>& equations)
    {
        int arr[123];
        memset(arr, 0, sizeof arr);
        int nextVal = 1;
        for (string& s : equations)
        {
            if (s[1] == '=')
            {
                int& v1 = arr[s[0]];
                int& v2 = arr[s[3]];
                if (s[0] == s[3])
                {
                    v1 = nextVal++;
                    v2 = v1;
                }
                else
                {
                    if (v1 == 0 && v2 == 0)
                    {
                        v1 = nextVal++;
                        v2 = nextVal++;
                    }
                    else if (v1 == 0 && v2 != 0)
                    {
                        v1 = v2;
                    }
                    else if (v1 != 0 && v2 == 0)
                    {
                        v2 = v1;
                    }
                    else
                    {
                    cout<<s[0]<<" "<<s[3]<<endl;
                    cout<<v1<<v2<<endl;
                        if (v1 != v2)
                            return false;
                    }
                }
            }
        }
        for (string& s : equations)
        {
            if (s[1] == '!')
            {
                int& v1 = arr[s[0]];
                int& v2 = arr[s[3]];
                if (s[0] == s[3])
                    return false;
                if (v1 != 0 && v2 != 0 && v1 == v2)
                    return false;
            }
        }
        return true;
    }


// error
    bool lt0990a(vector<string>& equations)
    {
        int arr[123];
        memset(arr, 0, sizeof arr);
        int nextVal = 1;
        for (string& s : equations)
        {
            int& v1 = arr[s[0]];
            int& v2 = arr[s[3]];
            if (s[0] == s[3])
            {
                if (s[1] == '!')
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }

            if (v1 == 0 && v2 == 0)
            {
                v1 = nextVal++;
                if (s[1] == '!')
                {
                    v2 = nextVal++;
                }
                else
                {
                    v2 = v1;
                }
            }
            else if (v1 == 0 && v2 != 0)
            {
                if (s[1] == '!')
                {
                    v1 = nextVal++;
                }
                else
                {
                    v1 = v2;
                }
            }
            else if (v1 != 0 && v2 == 0)
            {
                if (s[1] == '!')
                {
                    v2 = nextVal++;
                }
                else
                {
                    v2 = v1;
                }
            }
            else
            {
                if (s[1] == '!')
                {
                    if (v1 == v2)
                        return false;
                }
                else
                {
                    if (v1 != v2)
                        return false;
                }
            }
        }

        return true;
    }

};

int main()
{

    vector<string> v = {
//    "a==b","b!=a"
//"b==a","a==b"
//"a==b","b==c","a==c"
//"a==b","b!=c","c==a"
//"c==c","b==d","x!=z"
//"a!=a"
//"c==c","f!=a","f==b","b==c"
"e==d","e==a","f!=d","b!=c","a==b"


    };

    LT0990 lt;

    cout<<lt.lt0990c(v)<<endl;

    return 0;
}
