
#include "../header/myheader.h"

class LT1893
{
public:

// D D

//        sort(ranges.begin(), ranges.end());
//        for (vector<int> r: ranges) {
//            if (r[0] > left) return false;
//            left = max(left, r[1] + 1);
//            if (left > right) return true;
//        }
// .................


//        for(int i = left; i <= right; ++i) {
//            bool ok = 0;
//            for(auto& e: ranges){
//                if (i >= e[0] && i <= e[1]){
//                    ok = 1;
//                    break;
//                }
//            }
//            if (!ok) return 0;
//        }


//        unordered_set<int> s;
//
//        for (int i = 0; i < ranges.size(); i++) {
//            for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
//                s.insert(j);
//            }
//        }
//
//        for (int i = left; i <= right; i++) {
//            if (!s.count(i)) {
//                return false;
//            }
//        }


//return all(any(l <= i <= r for l, r in ranges) for i in xrange(left, right + 1))


//	Arrays.sort(ranges, (x,y)->x[0]-y[0]);
//	for(int[] range: ranges)
//		if(left >= range[0] && left <= range[1])
//			left = range[1] + 1;
//	return left > right;


//        Arrays.sort(ranges, (x, y) -> x[0] - y[0]);
//
//        for(int[] range : ranges) {
//            if(range[0] > left) return false;
//            left = Math.max(left, range[1]+1);
//        }


//    int line[52] = {};
//    for (auto &r : ranges) {
//        line[r[0]] += 1;
//        line[r[1] + 1] -= 1;
//    }
//    for (int i = 1, overlaps = 0; i <= right; ++i) {
//        overlaps += line[i];
//        if (i >= left && overlaps == 0)
//            return false;
//    }
//    return true;
// ... 有没有区间。       区间的开始结束分别+1,-1.


// ... 根据约束，直接 vector<int>(51) 就可以了。
//Runtime: 4 ms, faster than 87.63% of C++ online submissions for Check if All the Integers in a Range Are Covered.
//Memory Usage: 8.7 MB, less than 71.36% of C++ online submissions for Check if All the Integers in a Range Are Covered.
    bool lt1893a(vector<vector<int>>& ranges, int left, int right)
    {
        std::sort(begin(ranges), end(ranges), [](const vector<int>& v1, const vector<int>& v2) {
                if (v1[0] == v2[0])
                    return v1[1] < v2[1];
                else
                    return v1[0] < v2[0];
            });
        #ifdef __test
        for (myvi& vi : ranges)
        {
            cout<<vi[0]<<", "<<vi[1]<<endl;
        }
        #endif // __test
        int i = 0;
        for (; i < ranges.size(); ++i)
        {
            if (ranges[i][1] >= left)
            {
//                i--;
                break;
            }
        }
        #ifdef __test
        cout<<"myi: "<<i<<endl;
        #endif // __test
//        if (i < 0)
//            return false;
        if (i == ranges.size())     // 都是升序
        {
            i--;
            if (ranges[i][1] >= right)
                return true;
            else
                return false;
        }
        if (ranges[i][0] > left)
            return false;
        int mx = ranges[i][1];
        i++;
        for (; i < ranges.size(); ++i)
        {
            if (mx >= right)
                return true;
            if (ranges[i][0] <= mx + 1)
            {
                mx = max(mx, ranges[i][1]);
            }
            else
            {
                #ifdef __test
                cout<<"return "<<i<<endl;
                #endif // __test
                return false;
            }
        }
        return ranges[ranges.size() - 1][1] >= right;
    }

};

int main()
{
//    myvvi vv = {{3,4},{1,2},{5,6},{1,4}};
//    int st = 2;
//    int en = 6;

//    myvvi vv = {{1,10},{10,20}};
//    int st = 2;
//    int en = 21;

//    myvvi vv = {{25,42},{7,14},{2,32},{25,28},{39,49},{1,50},{29,45},{18,47}};
//    int st = 15;
//    int en = 38;

    myvvi vv = {{50,50}};
    int st = 1;
    int en = 50;

//    myvvi vv = {{1,2},{3,4},{5,6}};
//    int st = 2;
//    int en = 5;

//    myvvi vv = {{13,43},{19,20},{32,38},{26,33},{3,38},{16,31},{26,48},{27,43},{12,24}};
//    int st{36};
//    int en{45};


    LT1893 lt;

    cout<<lt.lt1893a(vv, st, en);

    return 0;
}
