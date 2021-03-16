
#include "../header/myheader.h"

class LT1748
{
public:

// D D

//        for(auto i:nums)
//        {
//            if(m.find(i)!=m.end())
//            {
//                auto a=m.find(i);
//                sum=sum-(i*a->second);
//                m[i]=0;
//                continue;
//            }
//            m[i]++;
//            sum+=i;
//        }


//    for (auto n : nums)
//        res += ++cnt[n] == 1 ? n : cnt[n] == 2 ? - n : 0;


//        int[] cnt = new int[101];
//        IntStream.of(nums).forEach(n -> ++cnt[n]);
//        return IntStream.range(1, 101).filter(i -> cnt[i] == 1).sum();


//       return sum(k for k, v in Counter(nums).items() if v == 1)



//Runtime: 4 ms, faster than 65.77% of C++ online submissions for Sum of Unique Elements.
//Memory Usage: 7.8 MB, less than 75.88% of C++ online submissions for Sum of Unique Elements.
    int lt1748a(vector<int>& nums)
    {
        int arr[101] = {0};
        for (int i : nums)
            arr[i]++;
        int ans = 0;
        for (int i = 0; i < 101; ++i)
            if (arr[i] == 1)
                ans += i;
        return ans;
    }

};

int main()
{

    LT1748 lt;


    return 0;
}
