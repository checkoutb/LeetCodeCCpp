
#include "../header/myheader.h"

class LT0781
{
public:


// D D
//            if(a==0) res++;
//            else{
//                if(m[a]==0) res+=a+1;
//                m[a]++;
//                if(m[a]==a+1) m[a]=0;


//        unordered_map<int, int> c;
//        for (int i : answers) c[i]++;
//        int res = 0;
//        for (auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
//        return res;
// +i.first.. 这样就不必判断 是否是整除的。


// 这把真的文章本天成。 可以跳过t2==0.
//Runtime: 8 ms, faster than 45.19% of C++ online submissions for Rabbits in Forest.
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Rabbits in Forest.
// 10,9,3 --> 11... bu, 这个好像是 每只兔子的答案。 不是每群兔子的答案。
    int lt0781a(vector<int>& answers)
    {
        int arr[1000] = {0};
        for (int i : answers)
        {
            arr[i]++;
        }
        int ans = 0;
        for (int i = 0; i < 1000; i++)
        {
            int t2 = arr[i];
            ans += ((t2 % (i + 1)) ? i + 1: 0) + (t2 / (i + 1)) * (i + 1);
        }
        return ans;
    }


};

int main()
{

//    vector<int> v = {1,1,2};

    vector<int> v = {10,10,10};

    LT0781 lt;

    cout<<lt.lt0781a(v)<<endl;

    return 0;
}
