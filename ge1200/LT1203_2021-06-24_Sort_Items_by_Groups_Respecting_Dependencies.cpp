
#include "../header/myheader.h"

class LT1203
{
public:

// D

// topological sort





// tle....
    vector<int> lt1203b(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
//        int sz1 =
        unordered_set<int> emp_set;

        // item and it's befores
        vector<unordered_set<int>> vsi1(n, emp_set);        // can?  all reference to emp_set ?
//        vector<unordered_set<int>> vsi2(m, emp_set);

        // group and group's element's before (which is not in this group)
        vector<unordered_set<int>> vsi2(m);

        vector<int> ans(n, -1);
//        unordered_set<int> set2;
        for (int i = 0; i < n; ++i)
        {
//            set2.clear();
            unordered_set<int> set2;
            if (beforeItems[i].empty())
            {
//                vsi1[]
            }
            else
            {
                unordered_set<int> line;
                if (!dfsb1(beforeItems, i, set2, line))
                    return vector<int>();

                int grp = group[i];
                if (grp != -1)
                    for (int bef : set2)
                    {
                        if (
//                            group[bef] != -1 &&
                            group[bef] != grp
    //                         && vsi2[grp].find())
                        )
                            vsi2[grp].insert(bef);
//                            vsi2[grp].insert(group[bef]);
                    }

//                vsi1[i] = set2;
                swap(vsi1[i], set2);


                #ifdef __test
                cout<<&set2<<" =?= "<<&emp_set<<endl;         // 不相等，但是 每次 set2都是同一个。。..
                #endif // __test

////                queue<int> que1;
//                for (int bef : beforeItems[i])
//                {
//                    set2.insert(bef);
////                    que1.push(bef);
//                }

//                while (!que1.empty())
//                {
//                    int szq = que1.size();
//                    while (szq-- > 0)
//                    {
//                        int fnt = que1.front();
//                        que1.pop();
//                        for (int bef : beforeItems[fnt])
//                        {
//                            if (set2.find(bef) != set2.end())
//                                return vector<int>();       // circle     // no  1->2->3    1->4->3...
//                            set2.insert(bef);
//                            que1.push(bef);
//                        }
//                    }
//                }

            }
        }

//        for (int i = 0; i < n; ++i)
//        {
//
//        }

        #ifdef __test
        for (int i = 0; i < vsi1.size(); ++i)
        {
            cout<<i<<": ";
            for (int a : vsi1[i])
            {
                cout<<a<<". ";
            }
            cout<<endl;
        }
        cout<<" ==================== "<<endl;
        for (int i = 0; i < vsi2.size(); ++i)
        {
            cout<<i<<": ";
            for (int a : vsi2[i])
                cout<<a<<", ";
            cout<<endl;
        }
        #endif // __test

        int ansi = 0;
        int previ = -1;
        vector<bool> vb(n);     // is in ans

        while (previ != ansi)
        {
            previ = ansi;
            for (int i = 0; i < n; ++i)
            {
                if (!vb[i])
                {
                    if (vsi1[i].empty())
                    {
                        if (group[i] == -1)
                        {
                            ans[ansi++] = i;
                            vb[i] = true;
                            removeb1(vsi1, vsi2, i);
                        }
                        else
                        {
                            // all group's element has no before
                            if (vsi2[group[i]].empty())
                            {
                                // 这里需要 整个group都放进来的。。。。
                                // 组内的顺序。
                                int grp = group[i];

                                // dfsb1能过，那就说明不存在 元素间的环
                                vector<int> vt;
                                for (int a = 0; a < n; ++a)
                                {
                                    if (group[a] == grp)
                                    {
                                        vt.push_back(a);
                                    }
                                }
                                int ti2 = -1;
                                while (ti2 != ansi)
                                {
                                    ti2 = ansi;
                                    for (int j = 0; j < vt.size(); ++j)
                                    {
                                        if (vb[vt[j]])
                                            continue;

                                        if (vsi1[vt[j]].empty())
                                        {
                                            ans[ansi++] = vt[j];
                                            vb[vt[j]] = true;
                                            removeb1(vsi1, vsi2, vt[j]);
                                        }
                                    }

//                                    if (ti2 == ansi)      // 不存在环，所以不需要判断。肯定都符合的。
                                }

//                                ans[ansi++] = i;
//                                vb[i] = true;
//                                removeb1(vsi1, vsi2, i);
                            }
                        }
                    }
                }
            }
        }

        if (ansi == ans.size())
            return ans;

        #ifdef __test
        showVectorInt(ans);
        #endif // __test
        return vector<int>();
    }

//    bool

    bool removeb1(vector<unordered_set<int>>& vs1, vector<unordered_set<int>>& vs2, int rm)
    {

        for (int i = 0; i < ((int) vs2.size()); ++i)
        {
//            if (i >= 2)
//            {
////                break;
////                cout<<" ???? "<<i<<endl;
//                    if (i >= 10000)
//                    {
//                        cout<<" ???? "<<endl;
//                        break;
//                    }
//                continue;
//            }
//            #ifdef __test
//                        // i就没有被 for的条件限制住。。这是什么原因。。感觉是bug了。。
////            cout<<i<<", "<<vs2.size()<<endl;            // ? 感觉有点不对劲啊，，这里输出了 2, 2 。。。 i不可能取到vs2.size()的啊。。
//            #endif // __test
            if (vs2[i].find(rm) != vs2[i].end())
            {
                vs2[i].erase(rm);
            }
//            cout<<"."<<endl;
        }

        // 原本这个for 是第一个， 放到这里以后， 这里的 越界， 上面的不越界了。。
        for (int i = 0; i < (int) vs1.size(); ++i)
        {
//            #ifdef __test
////            cout<<i<<", "<<&i<<endl;        // 打印地址以后， 直接中断了，AddressSanitizer说有nested bug, abort...
//            #endif // __test
            if (vs1[i].find(rm) != vs1[i].end())
            {
                vs1[i].erase(rm);
            }
        }

        return true;                    // holy shit....  我准备注释掉这个方法，然后重新写一个的时候， 发现这个方法返回bool。。但我并没有写 return。。 加上后就可以了。
    }

    bool dfsb1(vector<vector<int>>& vvi, int idx, unordered_set<int>& set2, unordered_set<int>& line)
    {
        for (int bef : vvi[idx])
        {
            if (line.find(bef) != line.end())
            {
                return false;
            }
            line.insert(bef);
            if (set2.find(bef) == set2.end())
                set2.insert(bef);

            bool b2 = dfsb1(vvi, bef, set2, line);
            if (!b2)
                return false;
            line.erase(bef);
        }
        return true;
    }


//。。。。。..unfinish
// n个物品，属于0或m个组之一， 或者-1,没组。  组里可以没有物品
// 排序：
//      一个组的在一起
//      before.
// nogroup 随便放。
// group 是覆盖 [-1,m] 的？
    vector<int> lt1203a(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        unordered_map<int, vector<int>> map2;       // group -> items     -1:nogroup
//        unordered_map<int, vector<int>> map3;       // group -> befores
//        unordered_set<int> set2;        // all befores
        unordered_map<int, unordered_set<int>> map4;    // group -> before's group              group : previous group
        unordered_map<int, unordered_set<int>> map5;        // no group's item -> befores' group
        int sz1 = group.size();
        for (int i = 0; i < sz1; ++i)
        {
            int grp = group[i];
            map2[grp].push_back(i);
            if (grp == -1)
            {
                if (!beforeItems[i].empty())
                    for (int bef : beforeItems[i])
                    {
//                        if (group[bef] != -1)
                            map5[i].insert(group[bef]);
                    }
                else
                    int t2 = map5[i].size();
            }
            else
            {
                if (!beforeItems[i].empty())
                {
                    for (int bef : beforeItems[i])
                    {
                        if (group[bef] != -1 && group[bef] != grp)
                            map4[grp].insert(group[bef]);
        //                map3[grp].push_back(bef);
                    }
                }
                else
                {
                    int tz = map4[grp].size();
                }
            }
        }
        unordered_set<int> set3;        // group
        vector<int> ans(sz1, -1);
        int ansi = 0;
        int prevansi = -1;
        unordered_set<int> prevall;
        while (ansi != prevansi)
        {
            prevansi = ansi;

            // no group
            for (unordered_map<int, unordered_set<int>>::iterator it = map5.begin(); it != map5.end(); it++)
            {
                if (it->second.empty())
                {
                    int t4 = it->first;
                    ans[ansi++] = t4;
                    prevall.insert(t4);

                }

            }
            // 如果一个元素的前驱包含一个no group，那么就看 prevall 里有没有这个

        }

        if (ansi == ans.size())
        {
            return ans;
        }
        return vector<int>();

//        for (int gp = 0; gp < m; gp++)
//        {
//            if (map4.find(gp) == map4.end())
//            {
//                vector<int> vi = map2[gp];
//                // 循环before。。 跨组循环before
//                // before no group
//                // before(no group) has a before(group)..
//
//
////                for (int itm : map2[gp])
////                {
//////                    ans[ansi++] = itm;
////
////                }
//            }
//        }

//        return ans;
//
//        AAA:
//        return new vector<int>();
    }

};

int main()
{
    int m = 8, n = 2;
    myvi grp = {-1,-1,1,0,0,1,0,-1};
//    myvvi vvi = {{},{6},{5},{6},{3,6},{0},{},{1}};
    myvvi vvi = {{},{6},{5},{6},{3,6},{},{},{}};

//    int m = 8, n = 2;
//    myvi grp = {-1,-1,1,0,0,1,0,-1};
//    myvvi vvi = {{},{6},{5},{6},{3},{},{4},{}};


    LT1203 lt;

    myvi vi = lt.lt1203b(m,n,grp,vvi);

    cout<<vi.size()<<endl;
    showVectorInt(vi);

    return 0;
}
