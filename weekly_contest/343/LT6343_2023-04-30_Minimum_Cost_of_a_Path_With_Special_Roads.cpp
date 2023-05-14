
#include "../../header/myheader.h"

class LT6343
{
public:


    // g

    // 
    int lta(vector<int>& start, vector<int>& target, vector<vector<int>>& sr)
    {
        for (auto it = begin(sr); it != end(sr);)
        {
            if (abs((*it)[0] - (*it)[2]) + abs((*it)[1] - (*it)[3]) <= (*it)[4])
            {
                it = sr.erase(it);
            }
            else
            {
                it++;
            }
        }

        int sz1 = sr.size();
        vector<int> vi(sz1, INT_MAX);       // min length to pipeline's start point
        int a = start[0];
        int b = start[1];
        int c = target[0];
        int d = target[1];
        //queue<int> que1;
        set<int> set2;
        for (int i = 0; i < sz1; ++i)
        {
            vi[i] = abs(a - sr[i][0]) + abs(b - sr[i][1]);
            //que1.push(i);
            set2.insert(i);
        }

        vector<bool> vb(sz1, false);
        

        //while (!que1.empty())
        while (!set2.empty())
        {
            set<int> set3;

            for (int i = 0; i < sz1; ++i)
                vb[i] = false;      // changed?  same set3...
            
            vector<int> v2(begin(vi), end(vi));

            for (auto it = set2.begin(); it != set2.end(); it++)
            {
                int pipe = *it;

                int t2 = vi[pipe] + sr[pipe][4];        // pipeline's end

                for (int i = 0; i < sz1; ++i)
                {
                    if (vb[i])
                        continue;
                    
                    int t3 = lengtha1(sr, pipe, i);
                    if (vi[i] > t2 + t3)
                    {
                        vb[i] = true;
                        set3.insert(i);
                        v2[i] = t2 + t3;                        // 这步肯定错了，但是min 还是错。
                    }
                }

            }
            swap(v2, vi);
            swap(set2, set3);
        }

        int ans = abs(c - a) + abs(d - b);

        for (int i = 0; i < sz1; ++i)
        {
            ans = min(ans, vi[i] + sr[i][4] + abs(c - sr[i][2]) + abs(d - sr[i][3]));
        }
        return ans;
    }

    int lengtha1(vector<vector<int>>& vvi, int st, int en)
    {
        return abs(vvi[st][2] - vvi[en][0]) + abs(vvi[st][3] - vvi[en][1]);
    }

};

int main()
{

    LT6343 lt;

    myvi v = { 1,1 };
    myvi v2 = { 4,5 };
    myvvi vv = { {1,2,3,3,2},{3,4,4,5,1} };


    cout << lt.lta(v, v2, vv) << endl;

    return 0;
}
