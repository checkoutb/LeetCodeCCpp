
#include "../header/myheader.h"

class LT1423
{
public:

// D D

//        int i,j=k-1,s=0,m=0,n=v.size()-1;
//        for(i=0;i<k;i++){
//            s=s+v[i];
//        }m=s;
//        for(i=0;i<k;i++){
//            s=s-v[j]+v[n];
//            m=max(m,s);
//            j--;n--;
//        }
//        return m;
// ...   }m=s;;;;;;;
// 感觉即使写 也是  }, m=s;  啊， 新特性？还是夏季吧写的。




//Runtime: 116 ms, faster than 58.12% of C++ online submissions for Maximum Points You Can Obtain from Cards.
//Memory Usage: 42.8 MB, less than 38.17% of C++ online submissions for Maximum Points You Can Obtain from Cards.
    int lt1423a(vector<int>& cardPoints, int k)
    {
        int sum2 = std::accumulate(begin(cardPoints), end(cardPoints), 0);
        if (k == cardPoints.size())
            return sum2;
        int gap = 0;
        int ans = 0;
        int gaplen = (cardPoints.size() - k);
        for (int i = 0; i < gaplen; ++i)
        {
            gap += cardPoints[i];
        }
        ans = sum2 - gap;
        for (int i = gaplen; i < cardPoints.size(); ++i)
        {
            gap += cardPoints[i] - cardPoints[i - gaplen];
            ans = max(sum2 - gap, ans);
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,2,3,4,5,6,1};
//    int k{3};
//    vector<int> v = {2,2,2};
//    int k{2};
//    vector<int> v = {9,7,7,9,7,7,9};
//    int k{7};

//    vector<int> v = {1,1000,1};
//    int k{1};

    vector<int> v = {1,79,80,1,1,1,200,1};
    int k{3};

    LT1423 lt;

    cout<<lt.lt1423a(v, k);

    return 0;
}
