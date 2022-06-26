
#include "../header/myheader.h"

class LT1737
{
public:


    // D D

    //for (int i = 0; i < 26; ++i) {
    //    res = min(res, m + n - c1[i] - c2[i]);
    //    if (i > 0) {
    //        c1[i] += c1[i - 1];
    //        c2[i] += c2[i - 1];
    //    }
    //    if (i < 25) {
    //        res = min(res, m - c1[i] + c2[i]); // condition 1
    //        res = min(res, n - c2[i] + c1[i]); // condition 2
    //    }
    //}


    //int suma = ca[0], sumb = cb[0], res = sza - ca[0] + szb - cb[0];
    //for (auto c = 1; c < 26; ++c) {
    //    res = min({ res, suma + szb - sumb, sumb + sza - suma,
    //               sza - ca[c] + szb - cb[c] });
    //    suma += ca[c];
    //    sumb += cb[c];
    //}


//Runtime: 43 ms, faster than 86.52 % of C++ online submissions for Change Minimum Characters to Satisfy One of Three Conditions.
//Memory Usage : 14.8 MB, less than 61.70 % of C++ online submissions for Change Minimum Characters to Satisfy One of Three Conditions.
    int lt1737a(string a, string b)
    {
        int arra[123] = { 0 };
        int arrb[123] = { 0 };
        for (char ch : a)
            arra[ch]++;
        for (char ch : b)
            arrb[ch]++;

        //int ans = INT_MAX;

        // 3 distinct
        int mxa = *max_element(begin(arra), end(arra));
        int mxb = *max_element(begin(arrb), end(arrb));
        
        int ans = a.size() - mxa + b.size() - mxb;

        for (int i = 'b'; i <= 'z'; ++i)
        {
            arra[i] += arra[i - 1];
            arrb[i] += arrb[i - 1];
        }


        // 1 a < b
        for (int i = 'a'; i < 'z'; ++i)            // i is max(a)
        {
            int t2 = a.size() - arra[i] + (arrb[i]);
            ans = min(t2, ans);

            t2 = b.size() - arrb[i] + arra[i];      // 2 a > b    i is max(b)
            ans = min(t2, ans);
        }
        return ans;

        // 2 a > b
        //for (int i = 'a'; i <)


    }

};

int main()
{

    LT1737 lt;

    //string a = "aba", b = "caa";

    string a = "dabadd", b = "cda";

    cout << lt.lt1737a(a, b) << endl;

    return 0;
}
