
#include "../header/myheader.h"

class LT1298
{
public:

// D D

//vector<bool> reachableClosedBoxes(status.size(),false);
// 已经获得，但是没有钥匙。


//        for (int i : initialBoxes)
//            if ((status[i] += 5000) > 5000)
//                q.push(i);
//        while (!q.empty()) {
//            i = q.front(), q.pop();
//            res += candies[i];
//            for (int j : keys[i])
//                if ((status[j] += 5) == 5005)
//                    q.push(j);
//            for (int j : containedBoxes[i])
//                if ((status[j] += 5000) > 5000)
//                    q.push(j);
//        }
// 盒子值5000,钥匙值5.



//    while (!boxes.empty() && changed) {
//        changed = false;
//        vector<int> newBoxes;
//        for (auto b : boxes) {
//            if (status[b]) {
//                changed = true;
//                newBoxes.insert(end(newBoxes), begin(containedBoxes[b]), end(containedBoxes[b]));
//                for (auto k : keys[b]) status[k] = 1;
//                res += candies[b];
//            }
//            else newBoxes.push_back(b);
//        }
//        swap(boxes, newBoxes);
//    }
// 有key 就把status设置为1.   就不需要keyset了。



//Runtime: 120 ms, faster than 46.41% of C++ online submissions for Maximum Candies You Can Get from Boxes.
//Memory Usage: 40.3 MB, less than 30.72% of C++ online submissions for Maximum Candies You Can Get from Boxes.
    int lt1298a(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
    {
        queue<int> que1;            // box
        unordered_set<int> keyset;
        for (int i : initialBoxes)
            que1.push(i);

        bool changed = true;        // new key or new box
        int ans = 0;
        while (changed)
        {
            changed = false;
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                int box = que1.front();
                que1.pop();
                bool canOpen = status[box] || (keyset.find(box) != keyset.end());
                if (canOpen)
                {
                    ans += candies[box];
                    if (!keys[box].empty())
                    {
                        for (int k : keys[box])
                            keyset.insert(k);
                        changed = true;
                    }
                    if (!containedBoxes[box].empty())
                    {
                        for (int bx : containedBoxes[box])
                            que1.push(bx);
                        changed = true;
                    }
                }
                else
                {
                    que1.push(box);
                }
            }
        }
        return ans;
    }

};

int main()
{
//    myvi status = {1,0,1,0}, candies = {7,5,4,100};
//    myvvi keys = {{},{},{1},{}}, containedBoxes = {{1,2},{3},{},{}};
//    myvi initialBoxes = {0};

    myvi status = {1,0,0,0,0,0}, candies = {1,1,1,1,1,1};
    myvvi keys = {{1,2,3,4,5},{},{},{},{},{}}, containedBoxes = {{1,2,3,4,5},{},{},{},{},{}};
    myvi initialBoxes = {0};

    LT1298 lt;

    cout<<lt.lt1298a(status, candies, keys, containedBoxes, initialBoxes);

    return 0;
}
