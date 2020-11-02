
#include "../header/myheader.h"

class LT1024
{
public:


// D D

//  sort(begin(clips), end(clips));
//  for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
//    while (i < clips.size() && clips[i][0] <= st) end = max(end, clips[i++][1]);
//    if (st == end) return -1;
//  }
//  return res;


//        sort(begin(clips), end(clips));
//        int res = 0;
//        for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
//            for (; i < clips.size() && clips[i][0] <= st; ++i)
//                end = max(end, clips[i][1]);
//            if (st == end) return -1;
//        }
//        return res;


//        unordered_map<int,int> max_ends(clips.size());
//        for(vector<int> &clip:clips)                                            //Get max end for each starting point.
//            max_ends[clip[0]]=max(max_ends[clip[0]],clip[1]);
//        int selectedEnd=-1,reachableEnd=0,count=0;
//        for(int i=0;i<=T;i++)
//        {
//            if(reachableEnd>=T||i>reachableEnd)        //If there is a break between clips or we already reached the end, return
//                break;
//            if(max_ends.count(i))                                 //If clip with i as starting point exists.
//            {
//                if(i>selectedEnd)                   //Increase the count if starting point is greater than previously selected clip end
//                    count++,selectedEnd=reachableEnd;              //New selected clip ends at max end
//                reachableEnd=max(reachableEnd,max_ends[i]);//Maximize reachable end till starting point is less than or equal to previously selected clip
//            }
//        }
//        return reachableEnd>=T?count:-1;
// 每个开始点的 最大结束时间，  max_ends
// i>reaahableEnd， 表明 中断了。



//Runtime: 4 ms, faster than 84.96% of C++ online submissions for Video Stitching.
//Memory Usage: 7.9 MB, less than 6.74% of C++ online submissions for Video Stitching.
    int lt1024a(vector<vector<int>>& clips, int T)
    {
        int ans = 0;
        sort(begin(clips), end(clips), [](vector<int>& v1, vector<int>& v2) { return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0]; });
        int ed = clips[0][1];
        int st = clips[0][0];
        if (st != 0)
            return -1;
        int ed2 = 0;
        ans = 1;

        for (int i = 1; i < clips.size();)
        {
            while (i < clips.size() && clips[i][0] <= ed)
            {
                ed2 = max(clips[i][1], ed2);
                i++;
            }
            if (ed == ed2)          // ...
                break;
            if (ed >= T)             // ... before while
                break;
            ed = ed2;
            ans++;
        }
        if (ed < T)
            return -1;

        return ans;
    }

};

int main()
{
//    vector<vector<int>> vv = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
//    int t = 10;

//    vector<vector<int>> vv = {{0,1},{1,2}};
//    int t = 5;

//    vector<vector<int>> vv = {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};
//    int t = 9;

    vector<vector<int>> vv = {{0,4},{0,3},{6,7},{1,2},{1,3},{4,7},{6,9}};
    int t = 9;

//    vector<vector<int>> vv = {{0,4},{2,8}};
//    int t = 5;

    LT1024 lt;

    cout<<lt.lt1024a(vv, t)<<endl;

    return 0;
}
