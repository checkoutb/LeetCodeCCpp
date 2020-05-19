
#include "../header/myheader.h"

class LT0767
{
public:


// D && D
// priority_queue<pair<int, char>>

// 还有一种，获得最多数量的char， 偶数(0,2,4,...) 下标，设置为 该char，直到数量用完。  for循环，while(char的数量>0){如果下标>size，那么下标为1， 下标所在位置设置为当前char，char的数量--,下标+=2}
// 因为数量最多的char已经被用掉了，所以后续for循环，是不可能导致相同char相遇的。
// 而且数量最多的char可能相遇的情况是，S长度是奇数 且 该char的数量是一半+1，且不以该char为起始。  所以数量最多的char作为起始，就不可能相遇了。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reorganize String.
//Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Reorganize String.
    string lt0767b(string S)
    {
        if (S.size() <= 2)
            return S;
        int arr1[26] = {0};
        int mx1 = S.size() / 2 + S.size() % 2;
        int mxi = -1;
        int i = -1;
        for (char ch : S)
        {
            arr1[ch - 'a']++;
            if (arr1[ch - 'a'] > mx1)
                return "";
            if (arr1[ch - 'a'] > mxi)
            {
                i = ch - 'a';
                mxi = arr1[ch - 'a'];
            }
        }

        string ans = "";
        ans.push_back((char) 'a' + i);
        arr1[i]--;
        int last = i;
        while (ans.size() < S.size())
        {
            mxi = -1;
            i = -1;
            for (int q = 0; q < 26; q++)
            {
                if (q == last)
                    continue;
                if (arr1[q] >= mxi)
                {
                    mxi = arr1[q];
                    i = q;
                }
            }
            ans.push_back((char) 'a' + i);
            arr1[i]--;
            last = i;
        }
        return ans;
    }


// 生成ans的方法错了。导致最后剩余了2个j。。。导致tle。。。估计应该每次取最多的那个char。次多的那个char。，。。不等于前一个的且出现剩余次数最多的char。
// 61/62. tle
// 任何char的数量不能超过 ceil(S.size()/2)?。
    string lt0767a(string S)
    {
        if (S.size() <= 2)
            return S;
        int arr1[26] = {0};
        int mx1 = S.size() / 2 + S.size() % 2;
        int i = -1, j = -1, mxi = 0;
        for (char ch : S)
        {
            arr1[ch - 'a']++;
            if (arr1[ch - 'a'] > mx1)
                return "";
//            if (arr1[ch - 'a'] >= mxi)
//            {
//                j = i;
//                i = ch - 'a';
//                mxi = arr1[ch - 'a'];
//            }
        }

        #ifdef __test

//        22, 16, 26, 15, 28, 22, 17, 28, 16, 11, 21, 11, 26, 23, 17, 18, 11, 18, 19, 16, 20, 24, 21, 18, 22, 14,
//        22, 16, 26, 15, 28, 22, 17, 28, 16, 9, 21, 11, 26, 23, 17, 18, 11, 18, 19, 16, 20, 24, 21, 18, 22, 14,

        for (int p = 0; p < 26; p++)
        {
            cout<<arr1[p]<<", ";
        }
        cout<<endl;
        #endif // __test

        for (int k = 0; k < 26; k++)
        {
            if (arr1[k] >= mxi)
            {
                mxi = arr1[k];
                i = k;
            }
        }
        mxi = 0;
        for (int k = 0; k < 26; k++)
        {
            if (k == i) continue;
            if (arr1[k] >= mxi)
            {
                mxi = arr1[k];
                j = k;
            }
        }
//        cout<<i<<", "<<j<<endl;
        int cnt = 0;
        string ans = "";
        int k = i;
        bool isi = true;
        while (ans.size() < S.size())
        {

//        hehehehehehehehehehehehehehehehehehehehehehehehehehehehemcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfawawawawawawawawawawawawawawawawawawawawawakukukukukukukukukukukukukukukukukukukukuksxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsrprprprprprprprprprprprprprprprprprpogogogogogogogogogogogogogogogogogtitititititititititititititititibdbdbdbdbdbdbdbdbdbdbdbdbdbdbdbzqzqzqzqzqzqzqzqzqzqzqzlzlzljljljljljljljljlj, 25, 25, 9


        cout<<ans<<", "<<k<<", "<<i<<", "<<j<<endl;
        getchar();
            if (arr1[k] > 0)
            {
                arr1[k]--;
                ans.push_back((char) k + 'a');
            }
            else
            {
                int skip = isi ? j : i;
                int mx2 = 0;
                int mx2index = 0;
                for (int q = 0; q < 26; q++)
                {
                    if (q == skip)
                        continue;
                    if (arr1[q] >= mx2)
                    {
                        mx2index = q;
                        mx2 = arr1[q];
                    }
                }
                if (isi) k = i = mx2index; else k = j = mx2index;
                continue;
            }
            k = isi ? j : i;
            isi = !isi;
        }
        return ans;
    }

};

int main()
{
                   //hehehehehehehehehehehehehehehehehehehehehehehehehehehehemcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfawawawawawawawawawawawawawawawawawawawawawakukukukukukukukukukukukukukukukukukukukuksxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsrprprprprprprprprprprprprprprprprprpogogogogogogogogogogogogogogogogogtitititititititititititititititibdbdbdbdbdbdbdbdbdbdbdbdbdbdbdbzqzqzqzqzqzqzqzqzqzqzqzlzlzljljljljljljljljlj
//    string arr[] = {"tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao"};

//    string arr[] = {"hehehehehehehehehehehehehehehehehehehehehehehehehehehehemcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcmcvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfyfawawawawawawawawawawawawawawawawawawawawawakukukukukukukukukukukukukukukukukukukukuksxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsxsrprprprprprprprprprprprprprprprprprpogogogogogogogogogogogogogogogogogtitititititititititititititititibdbdbdbdbdbdbdbdbdbdbdbdbdbdbdbzqzqzqzqzqzqzqzqzqzqzqzlzlzljljljljljljljljlj"};

    string arr[] = {"aab"};

    LT0767 lt;

    for (string s : arr)
    {
        cout<<lt.lt0767b(s)<<endl;
    }

    return 0;
}
