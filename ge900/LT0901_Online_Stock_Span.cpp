
#include "../header/myheader.h"

class LT0901
{
public:



};



// D D
//stack<pair<int, int>> s;




//Runtime: 1556 ms, faster than 5.00% of C++ online submissions for Online Stock Span.
//Memory Usage: 86.4 MB, less than 29.82% of C++ online submissions for Online Stock Span.
class StockSpanner {
    vector<int> v;
public:
    StockSpanner() {

    }

    int next(int price) {
        int ans = 1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (price >= v[i])
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        v.push_back(price);
        return ans;
    }
};




int main()
{

    int arr[] = {100, 80, 60, 70, 60, 75, 85};

    LT0901 lt;

    StockSpanner ss;

    for (int i : arr)
    {
        cout<<ss.next(i)<<endl;
    }

    return 0;
}
