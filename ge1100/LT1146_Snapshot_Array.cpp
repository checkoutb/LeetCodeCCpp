
#include "../header/myheader.h"

class LT1146
{
public:



};


// map<map>
// vector<vector<pair<int,int>>>
class SnapshotArray {
    vector<vector<pair<int, int>>> vvp;
    int snapcnt = 0;
public:
    SnapshotArray(int length) {
        vvp = vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, {0, 0}));
    }

    void set(int index, int val) {
        vector<pair<int, int>>& vp = vvp[index];
//        if (vp.empty())
//        {
//            vp.push_back({snapcnt, val});
//        }
//        else
//        {
            if (vp[vp.size() - 1].first == snapcnt)
            {
                vp[vp.size() - 1].second = val;
            }
            else
            {
                vp.push_back({snapcnt, val});
            }
//        }
    }

    int snap() {
        return snapcnt++;
    }

    int get(int index, int snap_id) {
        vector<pair<int, int>>& vp = vvp[index];
        auto p = std::lower_bound(begin(vp), end(vp), snap_id,
            [](pair<int, int>& p1, int s){ return p1.first < s; }
        );
        return p->second;
    }
};


int main()
{

//["SnapshotArray","snap","snap","get","set","snap","set"]
//[[4],[],[],[3,1],[2,4],[],[1,4]]


// heap-buffer-overflow...
    SnapshotArray sa(4);
    cout<<sa.snap();
    cout<<sa.snap();
    cout<<sa.get(3, 1);
    sa.set(2,4);
    cout<<sa.snap();
    sa.set(1,4);


//    SnapshotArray sa(3);
//    sa.set(0, 5);
//    int snap = sa.snap();
//    sa.set(0, 6);
//    cout<<sa.get(0, snap)<<endl;;

    LT1146 lt;


    return 0;
}
