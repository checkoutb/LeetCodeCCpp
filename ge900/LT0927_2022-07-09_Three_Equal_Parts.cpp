
#include "../header/myheader.h"

class LT0927
{
public:

    // D D


    //int x = firstOne, y = secondOne, z = thirdOne;
    //while (x < n && y < n && z < n) {
    //    if (arr[x] == arr[y] && arr[y] == arr[z]) {
    //        x++; y++; z++;
    //    }
    //    else
    //        return { -1,-1 };
    //}
    //
    // 直接在 arr 上操作，这样就不需要判断 last0cnt了。

    // count(begin, end)




    //int len = ones / 3, j = 0, cnt = 0;
    //vector<vector<int>> mp(3);

    //for (int i = 0; i < n; ++i) {
    //    if (!v[i]) continue;
    //    ++cnt;
    //    mp[j].push_back(i);
    //    if (cnt % len == 0) ++j;
    //}

    //for (int i = 1; i < len; ++i) {
    //    int d0 = mp[0][i] - mp[0][i - 1];
    //    int d1 = mp[1][i] - mp[1][i - 1];
    //    int d2 = mp[2][i] - mp[2][i - 1];
    //    if (d0 != d1 || d1 != d2) return ans;
    //}




//Runtime: 47 ms, faster than 85.63 % of C++ online submissions for Three Equal Parts.
//Memory Usage : 40.4 MB, less than 24.38 % of C++ online submissions for Three Equal Parts.
    // 最后一步的0。。。 后缀0 只看 第三部分的， 其它部分可以作为 后续的前缀0，无所谓的。
    vector<int> lt0927a(vector<int>& arr)
    {

        vector<int> vi;
        int sz1 = arr.size();

        for (int i = 0; i < sz1; ++i)
        {
            if (arr[i])
                vi.push_back(i);
        }

        if (vi.size() % 3)
            return { -1, -1 };

        if (vi.empty())                     // ........
        {
            return { 0,2 };
        }

#ifdef __test
        showVectorInt(vi);
#endif

        int st1 = 1, st2 = vi.size() / 3 + 1, st3 = vi.size() / 3 * 2 + 1;
        while (st1 < vi.size() / 3)
        {
            if ((vi[st1] - vi[st1 - 1] != vi[st2] - vi[st2 - 1]) || (vi[st1] - vi[st1 - 1] != vi[st3] - vi[st3 - 1]))
            {
                return { -1, -1 };
            }
            st1++;
            st2++;
            st3++;
        }

        int lst0cnt = sz1 - vi[st3 - 1] - 1;
#ifdef __test
        // part 2's first,   part 3's first    sz1
        cout << st1 << ", " << st2 << ", " << st3 << endl;
        cout << "lst0 : " << lst0cnt << endl;
#endif

        if (vi[st1] - vi[st1 - 1] - 1 < lst0cnt || (vi[st2] - vi[st2 - 1] - 1 < lst0cnt))               //    -1
            return { -1, -1 };

        int ans1 = vi[st1 - 1] + lst0cnt;
        int ans2 = vi[st2 - 1] + lst0cnt + 1;
        return {ans1, ans2};


        //int sum2 = accumulate(begin(arr), end(arr));
        //if (sum2 % 3)
        //    return false;


        //int t2 = sum2 / 3;

        //int st1 = 0;
        //int sz1 = arr.size();
        //for (int i = 0; i < sz1; ++i)
        //{
        //    if (arr[i])
        //    {
        //        st1 = i;
        //        break;
        //    }
        //}

        //int t3 = t2;
        //for (int i = 0; i < sz1; ++i)
        //{

        //}

    }

};

int main()
{

    LT0927 lt;

    //myvi v = { 1,0,1,0,1 };
    //myvi v = { 1,1,0,1,1 };
    //myvi v = { 1,1,0,0,1 };

    //myvi v = { 0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0 };

    myvi v = {1,0,1,1,0};

    myvi v2 = lt.lt0927a(v);

    cout << v2[0] << " - " << v2[1] << endl;

    return 0;
}
