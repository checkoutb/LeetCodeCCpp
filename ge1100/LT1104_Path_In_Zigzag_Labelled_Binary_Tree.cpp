
#include "../header/myheader.h"

class LT1104
{
public:


// D D

//return self.pathInZigZagTree(3 * 2 ** (len(bin(x)) - 4) - 1 - x / 2) + [x] if x > 1 else [1]

//  while (1 << level <= label) ++level;
//  vector<int> res(level);
//  for(; label >= 1; label /= 2, --level) {
//    res[level - 1] = label;
//    label = (1 << level) - 1 - label + (1 << (level - 1));
//  }
//  return res;




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Path In Zigzag Labelled Binary Tree.
//Memory Usage: 6.6 MB, less than 6.24% of C++ online submissions for Path In Zigzag Labelled Binary Tree.
    vector<int> lt1104a(int label)
    {
        vector<int> ans;
        int t = 1;
        bool left = true;
        while (t <= label)
        {
            t *= 2;
            left = !left;
        }
        t /= 2;
        left = !left;
        int t2 = left ? label - t : t - (label - t) - 1;
        left = !left;
        t2 /= 2;
        t /= 2;
        ans.push_back(label);

        while (t > 0)
        {
            ans.push_back(left ? t + t2 : t + t - 1 - t2);
            left = !left;
            t /= 2;
            t2 /= 2;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

};

int main()
{

    int arr[] = {14,26};


    LT1104 lt;

    for (int i : arr)
    {
        vector<int> v = lt.lt1104a(i);
        for_each (begin(v), end(v), fun_cout);
        cout<<endl;
    }

    return 0;
}
