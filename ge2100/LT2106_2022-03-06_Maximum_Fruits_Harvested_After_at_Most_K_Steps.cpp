
#include "../header/myheader.h"

class LT2106
{
public:


// D D


//    auto l = upper_bound(begin(fruits), end(fruits), vector<int>{pos - k});
//    int sum = 0, max_sum = 0;
//    for (auto r = l; r != end(fruits) && (*r)[0] <= pos + k; ++r) {
//        sum += (*r)[1];
//        while(min(pos - 2 * (*l)[0] + (*r)[0], 2 * (*r)[0] - (*l)[0] - pos) > k)
//            sum -= (*l++)[1];
//        max_sum = max(max_sum, sum);
//    }
//    return max_sum;




//Runtime: 807 ms, faster than 32.74% of C++ online submissions for Maximum Fruits Harvested After at Most K Steps.
//Memory Usage: 120.1 MB, less than 92.88% of C++ online submissions for Maximum Fruits Harvested After at Most K Steps.
// 不可能 多次 来回跑。 所以 直接 2种可能，第一种： 向右走到底，然后从头尝试 ，，不不不，就是 尝试拿左面 0/1/2/3/4/5... 个水果后 往右走到底，
//                                                           或者 尝试 拿 右面1/2/3/4。。 个水果后， 往左走到底。
// 10^5 ... 感觉。。需要先计算下啊。。 不,指针
    int lt2106a(vector<vector<int>>& fruits, int startPos, int k)
    {
        vector<vector<int>>::iterator it = std::lower_bound(begin(fruits), end(fruits), startPos, [](vector<int>& vi, int pos){
            return vi[0] < pos;
        });
        int idx = std::distance(begin(fruits), it);
        int ans = 0;
        int sz1 = fruits.size();

        #ifdef __test
        cout<<idx<<endl;
        #endif // __test

        // 往右到底
        int t2 = 0;
        int i2 = idx;
        while (i2 < sz1 && fruits[i2][0] <= startPos + k)
        {
            t2 += fruits[i2][1];
            i2++;
        }
        i2--;
//        setAns(ans, t2);
        setMax(ans, t2);
//        ans = t2;

//        #ifdef __test
//        cout<<ans<<endl;
//        #endif // __test

        // 尝试先向左
        int i3 = idx - 1;
        while (i3 >= 0 && fruits[i3][0] + k >= startPos)
        {
            t2 += fruits[i3][1];
            int t5 = startPos + (k - 2 * (startPos - fruits[i3][0]));           // 向右的距离。
            while (fruits[i2][0] > t5)
            {
                t2 -= fruits[i2][1];
                i2--;
            }
//            ans = max(t2, ans);
//            setAns(ans, max(t2, ans));
            #ifdef __test
            cout<<i3<<" - "<<i2<<endl;
            #endif // __test
            setMax(ans, t2);
            i3--;
        }

        #ifdef __test
        cout<<"===="<<endl;
        #endif // __test

        // .
        t2 = 0;
        i2 = idx;
        i3 = idx;
        if (i2 == sz1 || fruits[i2][0] > startPos)
        {
            i2--;
        }
        else
        {
            i3++;
        }
        while (i2 >= 0 && fruits[i2][0] >= startPos - k)
        {
            t2 += fruits[i2][1];
            i2--;
        }
        i2++;
//        setAns(ans, max(t2, ans));
        setMax(ans, t2);
//        ans = max(t2, ans);
        while (i3 < sz1 && fruits[i3][0] <= startPos + k)           // 应该只需要一半。
        {
            t2 += fruits[i3][1];
            int t5 = startPos - (k - 2 * (fruits[i3][0] - startPos));
            while (fruits[i2][0] < t5)
            {
                t2 -= fruits[i2][1];
                i2++;
            }
//            ans = max(ans, t2);
//            setAns(ans, max(ans, t2));
            setMax(ans, t2);
            i3++;
        }
        return ans;
    }

    inline void setMax(int& ans, int val)
    {
        #ifdef __test
        cout<<ans<<" -> "<<val<<endl;
        #endif // __test
        ans = max(ans, val);
    }

//    void setAns(int& ans, int val)  // or ans = max(ans, val);
//    {
//        #ifdef __test
//        cout<<ans<<" -> "<<val<<endl;
//        #endif // __test
//        ans = val;
//    }

};

int main()
{

    LT2106 lt;

//    myvvi vv = {{2,8},{6,3},{8,6}};
//    int st = 5;
//    int k = 4;

//    myvvi vv = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
//    int st = 5;
//    int k = 4;

//    myvvi vv = {{0,3},{6,4},{8,5}};
//    int st = 3;
//    int k = 2;

    myvvi vv = {{0,1111}};
    int st = 20000;
    int k = 20000;


//// 71
//    myvvi vv = {{0,7},{7,4},{9,10},{12,6},{14,8},{16,5},{17,8},{19,4},{20,1},{21,3},{24,3},{25,3},{26,1},{28,10},{30,9},{31,6},{32,1},{37,5},{40,9}};
//    int st = 21;
//    int k = 30;


    cout<<lt.lt2106a(vv, st, k)<<endl;

    return 0;
}
