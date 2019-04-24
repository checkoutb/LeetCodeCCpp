
#include "../header/myheader.h"


class LT0316
{
public:


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Remove Duplicate Letters.
//Memory Usage: 8.8 MB, less than 61.43% of C++ online submissions for Remove Duplicate Letters.

//  基本都是回溯。不过discuss的回溯是在foreach(s)中回溯的，我是在26个字母里。
//    for (char c : s) {
//        cand[c]--;
//        if (visited[c]) continue;
//        while (c < result.back() && cand[result.back()]) {
//            visited[result.back()] = false;
//            result.pop_back();
//        }
//        result += c;
//        visited[c] = true;
//    }

// while当下一个char，小于result的最后一个 且 cand > 0, 那么就删除最后一个。cand是保存了s中char的个数。

// 我的思路是：26个字母从a开始，如果a之后的所有字母要么不在s中出现，要么最后一次出现是在a的第一次出现之后，那么a就是result的第一个字符。
// 如果a后面的某个字母，最后一次出现的位置在a的第一次出现之前，那么 这个字母 在result的顺序 必然在 a之前。需要前进到这个字母，然后再回溯到a。
// 对于每个s中出现的字母，字典顺序大于它的字母的最后一次出现位置 必须都 大于 现有result的最后一个字母在s中的位置之后 这个字母的第一次出现位置。这样才能保证 这个字母在result的顺序是正确的。

    string lt0316c(string s)
    {
        string result;
        int len = s.length();
        int arr1[26], arrf[26], arrL[26];
        int i, j;

        for (i = 0; i < 26; i++)
        {
            arr1[i] = -1;
            arrf[i] = -1;
            arrL[i] = -1;
        }

        for (i = 0; i < len; i++)
        {
            j = s[i] - 97;
            if (arr1[j] == -1)
            {
                arr1[j] = -2;
                arrf[j] = i;
            }
            arrL[j] = i;
        }

        int start = 0;

#ifdef __test
        for_each(begin(arr1), end(arr1), fun_cout);
        cout<<endl<<"zzzz"<<endl;
        for_each(begin(arrf), end(arrf), fun_cout);
        cout<<endl<<"qqqq";
        for_each(begin(arrL), end(arrL), fun_cout);
        cout<<endl<<"aaaa";
#endif // __test

        start = -1;
        i = 0;
        bool flag = false;
        AAA:
        for (; i < 26; i++)
        {
            if (arr1[i] != -2)
                continue;

            if (!flag)
                start = arrf[i];

            int t3 = s.find_first_of((char) (i + 97), start);

            #ifdef __test
            cout<<endl<<t3<<",ll,,,"<<start<<","<<i<<endl;
            #endif // __test

            // 应该可以一次跳过多个的。这里一个个跳。
            for (j = i + 1; j < 26; j++)
                if (arrL[j] != -1 && arrL[j] <= t3 && arr1[j] <= 0)
                {
                    i++;
                    #ifdef __test
                    cout<<",,,"<<"goto"<<arrL[j]<<","<<arr1[j]<<","<<j<<endl;
                    #endif // __test
                    goto AAA;
                }

            int index = s.find_first_of((char)(i + 97), start);
            start = index;
            arr1[i] = index;
            flag = true;
            arrL[i] = -1;

            #ifdef __test
            cout<<endl<<"................"<<endl;
            cout<<index<<", "<<i<<", "<<start<<endl;
            #endif // __test

            j = i;
            for (; i >= 0; i--)
                if (arr1[i] == -2)
                {
                    j = i;
                }
            i = --j;

            #ifdef __test
            cout<<i<<",,,"<<j<<endl;
            #endif // __test
        }

#ifdef __test
        for_each(begin(arr1), end(arr1), fun_cout);
#endif // __test

        int t1 = INT_MAX;
        int indexMin = -1;
        for (i = 0; i < 26; i++)
        {
            if (arr1[i] == -1)
                continue;

            t1 = INT_MAX;
            for (j = 0; j < 26; j++)
            {
                if (arr1[j] == -1)
                    continue;
                if (arr1[j] < t1)
                {
                    t1 = arr1[j];
                    indexMin = j;
                }
            }
            result = result + (char) (indexMin + 97);
            arr1[indexMin] = INT_MAX;
        }

        return result;
    }


//deprecated
    string lt0316b(string s)
    {
        string result;
        int len = s.length();
        int arr_f[26], arr_l[26], arr1[26];
        int last = -1;

        for (int i = 0; i < 26; i++)
        {
            char ch = i + 97;
            arr_f[i] = s.find_first_of(ch);
            arr_l[i] = s.find_last_of(ch);
        }

        for (int i = 0; i < 26; i++)
        {
            char ch = i + 97;
            int start = 1;
            if (arr_f[i] == -1)
            {
                arr1[i] = -1;
                continue;
            }
            if (arr_l[i] < last)
            {

            }
            else
            {
                int index = s.find_first_of(ch, start);
                arr1[i] = index;
                start = index;
            }
        }

        return result;
    }

//deprecated
    string lt0316a(string s)
    {
        string result;
        int len = s.length();
        int arr1[26];
        int arr2[26];
        int arr3[26];

        // 不如自己for 1遍。
        // 这个好像没什么太大的意义。不需要也可以的。
        for (int i = 0; i < 26; i++)
        {
            char ch = i + 97;
            arr1[i] = s.find_first_of(ch);
            arr2[i] = s.find_last_of(ch);
            arr3[i] = -1;
        }

        #ifdef __test
//        for (int i = 0; i < )
        for_each(begin(arr1), end(arr1), fun_cout);
        cout<<endl;
        for (int ia2 : arr2)
            cout<<ia2<<", ";
        #endif // __test

        int start = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] == -1)
                continue;
            char ch = 'a' + i;

            if (arr1[i] >= start)
            {
                arr3[ch - 'a'] = i;
                start = i;
            }
            else
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (arr1[j] == -1)
                        continue;
                    int index = s.find_first_of(ch, arr3[i - 1]);
//                    if (index <)
                }
            }
        }


        return result;
    }
};


int main()
{
//    string s;
//    s += "asd";
//    cout<<s<<(s == "asd")<<endl;

    string args[] = {"bcabc","cbacdcbc","baa"};
//    cout<<(sizeof(args))<<", "<<sizeof(args[0])<<endl;
    LT0316 lt;
    for (int i = 0; i < (sizeof(args) / sizeof(args[0])); i++)
    {
        cout<<lt.lt0316c(args[i])<<endl<<endl<<endl;
    }

}
