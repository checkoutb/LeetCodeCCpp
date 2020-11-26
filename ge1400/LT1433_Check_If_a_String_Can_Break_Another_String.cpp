
#include "../header/myheader.h"

class LT1433
{
public:

// D D

// sort, 看是否始终大于，或小于。  不过速度慢，  sort的 在 350ms附近。
//        for(int i=0;i<n;i++)
//        {
//            if(s1[i]<s2[i])f1=false;
//            if(s2[i]<s1[i])f2=false;
//        }



//Runtime: 32 ms, faster than 90.57% of C++ online submissions for Check If a String Can Break Another String.
//Memory Usage: 11.9 MB, less than 57.89% of C++ online submissions for Check If a String Can Break Another String.
    bool lt1433a(string s1, string s2)
    {
        int arr1[123] = {0};
        int arr2[123] = {0};
        for (char ch : s1)
            arr1[ch]++;
        for (char ch : s2)
            arr2[ch]++;
        #ifdef __test
        for (int i = 'a'; i <= 'z'; ++i)
            cout<<arr1[i]<<", ";
        cout<<endl;
        for (int i = 'a'; i <= 'z'; ++i)
            cout<<arr2[i]<<", ";
        cout<<endl;
        #endif // __test

        int remain = 0;
        bool ans = false;
        // s1 > s2 ?
        for (int i = 'z'; i >= 'a'; --i)
        {
            if (arr1[i] == 0 && arr2[i] == 0)
                continue;
            if (remain + arr1[i] < arr2[i])
                goto AAA;
            remain = remain + arr1[i] - arr2[i];
        }
        ans = true;
        return ans;

        AAA:
        remain = 0;         // ...
        // s2 < s1 ?
        for (int i = 'z'; i >= 'a'; --i)
        {
            if (arr1[i] == 0 && arr2[i] == 0)
                continue;
            if (remain + arr2[i] < arr1[i])
                return false;
            remain = remain + arr2[i] - arr1[i];
        }
        return true;
    }

};

int main()
{
//    string s1{"abc"}, s2{"axy"};
//    string s1{"abe"}, s2{"acd"};
//    string s1{"leetcode"}, s2{"interview"};
    string s1 = "ediyevsblccxdjkhiqblacemlxuwhdvkiaqkdlzzuxetimcvstxqps";
    string s2 = "nrmjhujrebtqdfhgnirairiqipemwdxlcurlrrzxqvsatjoveecsev";


    LT1433 lt;

    cout<<lt.lt1433a(s1, s2);

    return 0;
}
