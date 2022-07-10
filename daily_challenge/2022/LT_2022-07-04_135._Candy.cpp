
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //Arrays.fill(candies, 1);// Give each child 1 candy 
    //
    //for (int i = 1; i < candies.length; i++) {// Scan from left to right, to make sure right higher rated child gets 1 more candy than left lower rated child
    //    if (ratings[i] > ratings[i - 1]) candies[i] = (candies[i - 1] + 1);
    //}
    //
    //for (int i = candies.length - 2; i >= 0; i--) {// Scan from right to left, to make sure left higher rated child gets 1 more candy than right lower rated child
    //    if (ratings[i] > ratings[i + 1]) candies[i] = Math.max(candies[i], (candies[i + 1] + 1));
    //}


    //To use two variables 'up' and 'down' to count the steps of continuous up and down respectively, and a 'peak' representing the peak before going down.In the below example :

    //[0, 1, 20, 9, 8, 7]

    //Scan from left to right, first child is given 1 candy;
    //the second child is given 2 candies, and up = 1;
    //the third child is given 3 candies, and up = 2; peak = 2;
    //the fourth child is given 1 candy, and down = 1;and third child still has 3 candies since peak = 2;
    //the fifth child is given 1 candy, and down = 2;and the previous child needs 1 more candy now but the third child no need more;
    //the sixth child is given 1 candy, and down = 3;and both the fifthand fourth child needs 1 more candy now, and the peak, the third child need 1 more as well.

    //if (ratings.Length == 0) return 0;
    //int ret = 1;
    //int up = 0, down = 0, peak = 0;
    //for (int i = 1; i < ratings.Length; i++) {
    //    if (ratings[i - 1] < ratings[i]) {
    //        peak = ++up;
    //        down = 0;
    //        ret += 1 + up;
    //    }
    //    else if (ratings[i - 1] == ratings[i]) {
    //        peak = up = down = 0;
    //        ret += 1;
    //    }
    //    else {
    //        up = 0;
    //        down++;
    //        ret += 1 + down + (peak >= down ? -1 : 0);
    //    }
    //}
    //
    // Lazy upate for peak element.


//Runtime: 48 ms, faster than 20.03 % of C++ online submissions for Candy.
//Memory Usage : 18.1 MB, less than 35.95 % of C++ online submissions for Candy.
    // 从rating最低的开始。
    int lta(vector<int>& ratings)
    {
        int sz1 = ratings.size();
        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
            vi[i] = i;

        sort(begin(vi), end(vi), [&](int a, int b) { return ratings[a] < ratings[b]; });

#ifdef __test
        showVectorInt(vi);
#endif

        vector<int> candy(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            int idx = vi[i];
            int vl = idx == 0 ? INT_MAX : ratings[idx - 1];     // left neighbour's rating
            int vr = idx == sz1 - 1 ? INT_MAX : ratings[idx + 1];   // right

            int cnt = 1;
            if (ratings[idx] > vl)
                cnt = candy[idx - 1] + 1;
            if (ratings[idx] > vr)
                cnt = max(cnt, candy[idx + 1] + 1);

            candy[idx] = cnt;
        }
#ifdef __test
        showVectorInt(candy);
#endif
        return accumulate(begin(candy), end(candy), 0);
    }

};

int main()
{

    LT lt;

    //myvi v = { 1,0,2 };
    myvi v = { 1,2,2 };

    cout << lt.lta(v) << endl;

    return 0;
}
