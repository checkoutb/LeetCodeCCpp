
#include "../header/myheader.h"

class LT1880
{
public:

// D D

//public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
//    return getNum(firstWord) + getNum(secondWord) == getNum(targetWord);
//}
//
//int getNum(String s) {
//    return s.chars().map(c -> c - 'a').reduce((i, j) -> i * 10 + j).getAsInt();
//}



// ....
//Runtime: 4 ms, faster than 28.03% of C++ online submissions for Check if Word Equals Summation of Two Words.
//Memory Usage: 5.9 MB, less than 56.14% of C++ online submissions for Check if Word Equals Summation of Two Words.
// 有个标题stoi。估计是 str[i] = (str[i] - 'a' + '0'). 然后stoi,, 是的，  -49 那个也是。
    bool lt1880b(string firstWord, string secondWord, string targetWord)
    {
        // a is 0, so remove 0 if 0 is prefix. then +
        int t2 = 0;
        for (int i = 0; i < firstWord.size() && firstWord[i] == 'a'; ++i)
        {
            t2++;
        }
        if (t2 != 0)
            firstWord = firstWord.substr(t2);
        t2 = 0;
        for (int i = 0; i < secondWord.size() && secondWord[i] == 'a'; ++i)
            t2++;
        if (t2 != 0)
            secondWord = secondWord.substr(t2);

        t2 = 0;
        for (int i = 0; i < targetWord.size() && targetWord[i] == 'a'; ++i)
            t2++;
        if (t2 != 0)
            targetWord = targetWord.substr(t2);

        // 怎么重载 string的 operator+ ？  得自己写个类继承。。 能单独改一个方法吗？  不知道是不是 friend的。

        int i1 = 0;
        int i2 = 0;
        if (targetWord.size() < max(firstWord.size(), secondWord.size()))
            return false;
        int sz1 = firstWord.size();
        int sz2 = secondWord.size();
        i1 = sz1 - 1;
        i2 = sz2 - 1;
        int i3 = targetWord.size() - 1;
        int c = 0;
        while (i1 >= 0 || i2 >= 0)
        {
            char t1 = i1 >= 0 ? firstWord[i1--] : 'a';
            char t2 = i2 >= 0 ? secondWord[i2--] : 'a';
            int t3 = (t1 + t2 + c - 'a' - 'a') + 'a';
            char tar = (char) (t3 % 'k' + (t3 >= 'k' ? 'a' : 0));           // ....
            c = 0;
            if (t3 >= 'k')
                c = 1;      // .... buxuyao 任何计算。。
            #ifdef __test
            cout<<tar<<endl;
            #endif // __test
            if (tar != targetWord[i3--])
            {
                #ifdef __test
                cout<<(int) tar<<", "<<tar<<","<<t3<<", "<<t1<<", "<<t2<<", "<<targetWord[i3 + 1]<<", "<<endl;
                #endif // __test
                return false;
            }
        }

        #ifdef __test
        cout<<c<<", "<<i3<<endl;
        #endif // __test

        if (c > 0)
        {
            if (i3 == 0)
            {
                return targetWord[0] == (char) ('a' + c);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return i3 == -1;
        }
    }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Word Equals Summation of Two Words.
//Memory Usage: 6 MB, less than 13.19% of C++ online submissions for Check if Word Equals Summation of Two Words.
// 99.4 的通过率。。。。。
    bool lt1880a(string firstWord, string secondWord, string targetWord)
    {
        int arr[3] = {0};
        string arr2[3] = {firstWord, secondWord, targetWord};
        for (int i = 0; i < 3; ++i)
        {
            int t1 = 0;
            for (char ch : arr2[i])
            {
                t1 *= 10;
                t1 += (ch - 'a');
            }
            arr[i] = t1;
        }
        return (arr[1] + arr[0] == arr[2]);
    }

};

int main()
{
    string arr[3] = {"acb", "cba", "cdb"};
//    string arr[3] = {"aaa", "a", "aab"};
//    string arr[3] = {"aaa", "a", "aaaaaaaa"};
//    string arr[3] = {"j","j","bi"};

    LT1880 lt;

    cout<<lt.lt1880b(arr[0],arr[1],arr[2]);

    return 0;
}
