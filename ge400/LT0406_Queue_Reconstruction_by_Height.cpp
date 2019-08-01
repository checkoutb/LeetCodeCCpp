
#include "../header/myheader.h"







// discuss
//vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
//    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
//                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
//    sort(people.begin(), people.end(), comp);
//    vector<pair<int, int>> res;
//    for (auto& p : people)
//        res.insert(res.begin() + p.second, p);
//    return res;
//}

// res.insert...insert...sort规则：高的前面，相同高时 前面少的(vector[1]小) 放前面
// 比他高的已经在res中了，所以插入的时候根据vector[1]就知道他应该在哪里。
// 后续插入有2种情况，
//     1.比他矮，此时不会影响vector[1].
//     2.相同高度，但是vector[1]必然大于他，也不会影响他的vector[1].






// 递归穷举。map记录<height, count>
// 都可行的时候，身高升序

// 从最矮的开始。



//Runtime: 48 ms, faster than 89.41% of C++ online submissions for Queue Reconstruction by Height.
//Memory Usage: 12.5 MB, less than 61.93% of C++ online submissions for Queue Reconstruction by Height.


bool myComp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class LT0406
{
public:

    vector<vector<int>> lt0406b(vector<vector<int>>& people)
    {
        int sz1 = people.size();
        sort(people.begin(), people.end(), myComp);
        vector<vector<int>> ans(sz1);

        #ifdef __test
//        cout<<"..test.."<<endl;
//        for (int i = 0; i < ans.size(); i++)
//        {
//            cout<<ans[i].size()<<endl;        // 长度为0的非null，vector对象。就是new vector().
//        }
        #endif // __test

        for (int i = 0; i < sz1; i++)
        {
            vector<int> v2 = people[i];
            int c2 = v2[1];
            int a2 = v2[0];
            for (int j = 0; j < sz1; j++)
            {
                if (ans[j].size() == 0)
                {
                    if (c2 == 0)
                    {
                        ans[j] = v2;
                        break;
                    }
                    else
                    {
                        c2--;
                    }
                }
                else
                {
                    if (ans[j][0] >= a2)
                        c2--;
                }
            }
        }

        return ans;
    }



    // deprecated..
//    vector<vector<int>> lt0406a(vector<vector<int>>& people)
//    {
//        map<int, int> map2;
//        vector<int> v_in;
//        int sz1 = people.size();
//
//        for (int i = 0)
//        {
//
//        }
//
//        return people;
//    }
//
//    void find_indexa1(vector<int>& v_in, vector<vector<int>>& p, map<int, int>& map2, int start)
//    {
//        v_in.clear();
//        int sz1 = p.size();
//        for (int i = start; i < sz1; i++)
//        {
//            if (map2[p[i][0]] == p[i][1])
//            {
//                v_in.push_back(i);
//
//            }
//        }
//    }

};

int main()
{
    vector<vector<int>> p2 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    LT0406 lt;
    p2 = lt.lt0406b(p2);

    for (int i = 0; i < p2.size(); i++)
    {
        cout<<p2[i][0]<<", "<<p2[i][1]<<endl;
    }

    return 0;
}
