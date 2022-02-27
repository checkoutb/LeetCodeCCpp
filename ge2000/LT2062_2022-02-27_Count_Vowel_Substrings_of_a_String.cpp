
#include "../header/myheader.h"

class LT2062
{
public:





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Vowel Substrings of a String.
//Memory Usage: 6.1 MB, less than 96.39% of C++ online submissions for Count Vowel Substrings of a String.
    int lt2062b(string word)
    {
        int arr[123] = {0};
        int ans = 0;
        int cnt = 0;
        int st = 0;
        int arr2[123] = {0};
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                if (arr[word[i]] == 0)
                {
                    cnt++;
                }
                arr[word[i]]++;

                if (cnt == 5)
                {
                    for (char ch : "aeiou")
                        arr2[ch] = 0;

                    for (int j = st; j <= i; j++)
                    {
                        arr2[word[j]]++;
                        if (arr2[word[j]] == arr[word[j]])
                            break;
                        ans++;
                    }
                    ans++;
                }
            }
            else
            {
                st = i + 1;
                cnt = 0;
                for (char ch : "aeiou")
                {
                    arr[ch] = 0;
                }
            }
        }
        return ans;
    }


    // error
    int lt2062a(string word)
    {
        int arr[123] = {0};
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                if (arr[word[i]] == 0)
                {
                    arr[word[i]] = ++cnt;
//                    cnt++;
//                    arr[word[i]] = 1;
                }
                if (cnt == 5)
                    ans++;
            }
            else
            {
                cnt = 0;
                for (char ch : "aeiou")
                {
                    arr[ch] = 0;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2062 lt;

    string s = "cuaieuouac";

    cout<<lt.lt2062b(s);

    return 0;
}
