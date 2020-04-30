
#include "../header/myheader.h"

class LT0721
{
public:



// discuss

//        Map<String, String> owner = new HashMap<>();
//        Map<String, String> parents = new HashMap<>();
//        Map<String, TreeSet<String>> unions = new HashMap<>();
//
//        第一次循环accounts。从本元素的第二个元素开始，owner中保存邮箱->人名(就是当前元素->第一个元素)
//                                          parents，每个元素是自己的parent(即当前元素->当前元素)
//
//        第二次循环accounts。找到本元素的第二个元素的parent，把这个parent作为当前元素中所有邮箱的parent。
//
//        第三次循环，找到当前元素的第二个元素的parent，把这个元素中所有的邮箱都放入unions[parent]中。





    // 45 / 49.... tle
    vector<vector<string>> lt0721d(vector<vector<string>>& accounts)
    {
        map<string, int> map1;
        map<int, set<string>> map2;
        map<int, string> map3;

        int m1 = 0;

        for (vector<string>& acc : accounts)
        {
            m1++;
            set<int> set1;
            map3[m1] = acc[0];
            for (int i = 1; i < acc.size(); i++)
            {
                string email = acc[i];
                if (map1.find(email) != map1.end())
                {
                    set1.insert(map1[email]);
                }
            }
            for (int i = 1; i < acc.size(); i++)
            {
                string email = acc[i];
                map1[email] = m1;
                map2[m1].insert(email);
            }
            if (!set1.empty())
            {
                for (int i : set1)
                {
                    for (string email : map2[i])
                    {
                        map1[email] = m1;
                        map2[m1].insert(email);
                    }
                    map2.erase(i);
                }
            }
        }

        vector<vector<string>> ans;
        for (auto entry : map2)
        {
            vector<string> v2;
            v2.push_back(map3[entry.first]);
            for (string email : entry.second)
            {
                v2.push_back(email);
            }
            ans.push_back(v2);
        }

        #ifdef __test
        cout<<endl<<ans.size()<<endl;
        for (auto v2 : ans)
        {
            for_each(v2.begin(), v2.end(), fun_cout_s);
            cout<<endl;
        }
        cout<<endl;
        #endif // __test

        return ans;
    }


    // error
    vector<vector<string>> lt0721c(vector<vector<string>>& accounts)
    {
        map<string, int> map1;      // email->int
        map<int, int> map2;         // 转换。value!
        map<int, set<int>> mapa;    // map2.val -> map2.key
        map<int, string> map3;      // int->name

        int m1 = 0;
        int m3 = 0;

        for (vector<string>& acc : accounts)
        {
            m1++;
            m3++;
            map3[m3] = acc[0];
            map2[m1] = m3;
            mapa[m3].insert(m1);
            for (int i = 1; i < acc.size(); i++)
            {
                map<string, int>::iterator it = map1.find(acc[i]);
                if (it == map1.end())
                {
                    map1[acc[i]] = m1;
                }
                else
                {
                    int map2val = map2[it->second];
                    mapa[m3].insert(it->second);
                    for (int k2 : mapa[map2val])
                    {
                        map2[k2] = m3;
//                        mapa[m3].insert(k2);
                    }
                    map2[it->second] = m3;
                }
            }

            #ifdef __test
//            cout<<map2.size()<<" ,--------------,,"<<endl;
//            for(auto p : map2)
//            {
//                cout<<p.first<<", "<<p.second<<endl;
//            }
            cout<<" --------- "<<endl;
            for (auto p : mapa)
            {
                cout<<p.first<<endl;
                for (int a : p.second)
                {
                    cout<<a<<", ";
                }
                cout<<endl;
            }
            #endif // __test

        }

        map<int, set<string>> map5;     // map2.value -> set{map1.key}

        for (map<string, int>::iterator it = map1.begin(); it != map1.end(); it++)
        {
            map5[map2[it->second]].insert(it->first);
        }

        vector<vector<string>> ans;
        for (auto p = map5.begin(); p != map5.end(); p++)
        {
            vector<string> v2;
            v2.push_back(map3[p->first]);
            for (string s2 : p->second)
            {
                v2.push_back(s2);
            }
            ans.push_back(v2);
        }

        #ifdef __test
        cout<<ans.size()<<endl;
        cout<<map5.size()<<endl;
//        cout<<q<<endl;
        for (auto p : ans)
        {
            cout<<p.size()<<", ";
            for_each(p.begin(), p.end(), fun_cout_s);
            cout<<endl;
        }
        #endif // __test

        return ans;

    }


    // 46/49 tle...并查集怎么写？
    vector<vector<string>> lt0721b(vector<vector<string>>& accounts)
    {
        map<string, vector<vector<string>>> map1;

        for (vector<string>& acc : accounts)
        {
            std::sort(acc.begin(), acc.end());
            acc.erase(unique(acc.begin(), acc.end()), acc.end());

            string name = acc[0];
            if (map1.find(name) != map1.end())
            {
                map1[name].push_back(acc);
            }
            else
            {
                map1[name].push_back(acc);
            }
        }

//        cout<<"ddd "<<map1.size()<<endl;

        for (map<string, vector<vector<string>>>::iterator it = map1.begin(); it != map1.end(); it++)
        {

            vector<vector<string>>& vv2 = it->second;
//            cout<<"for "<<vv2.size()<<endl;

            int sz2 = 0;
            do
            {
                vv2 = it->second;
                sz2 = vv2.size();
                bool contain = false;
                for (int i = 0; i < vv2.size(); i++)
                {
                    vector<string>& v1 = vv2[i];
                    for (int j = i + 1; j < vv2.size(); j++)
                    {
                        vector<string>& v2 = vv2[j];
                        for (int ii = 1; ii < v1.size(); ii ++)
                        {
                            for (int jj = 1; jj < v2.size(); jj++)
                            {
                                if (v1[ii] == v2[jj])
                                {
                                    contain = true;

//                                    cout<<"v1 sz "<<v1.size()<<endl;
//                                    for_each(v1.begin(), v1.end(), fun_cout_s);
//                                    for_each(v2.begin(), v2.end(), fun_cout_s);

                                    for (int jjj = 1; jjj < v2.size(); jjj++)
                                    {
//                                    cout<<"   ?  "<<v2[jjj]<<endl;
//                                    cout<<"1!! "<<(std::lower_bound(v1.begin(), v1.end(), v2[jjj]) == v1.end())<<endl;

                                        // lower_bound cannot find, maybe return end(), *end() -> head-buffer-overflow....
                                        // v1.insert(p, v1[jjj])
                                        // ... end is the postion which v2[jjjj] should insert...不，v1最开始是无序的。。所以不应该用lowerbound。可能lowerbound在无序的情况下，依然二分，导致搜不到数据，返回end，。。end会push_back，这会导致重复
//                                        auto p = std::lower_bound(v1.begin(), v1.end(), v2[jjj]);
//                                        if (p == v1.end() || *p != v2[jjj])
//                                            v1.push_back(v2[jjj]);

                                        // md..
                                        auto p = std::find(v1.begin(), v1.end(), v2[jjj]);
                                        if (p == v1.end())
                                            v1.push_back(v2[jjj]);

                                    }

//                                    cout<<"v1 sz 1 "<<v1.size()<<endl;
//                                    for_each(v1.begin(), v1.end(), fun_cout_s);
//                                    for_each(v2.begin(), v2.end(), fun_cout_s);
//                                    cout<<"1111 "<<vv2.size()<<endl;

                                    vv2.erase(vv2.begin() + j);

//                                    cout<<"2222 "<<vv2.size()<<endl;

//                                    break;
                                    goto AAA;
                                }
                            }
//                            if (c)
                        }
                    }
                }
                AAA:

                if (contain)
                {

                }


            } while (sz2 != vv2.size());
        }

        #ifdef __test
//        cout<<"map1 "<<map1["David"].size()<<endl;
        #endif // __test

        vector<vector<string>> ans;

        for (map<string, vector<vector<string>>>::iterator it = map1.begin(); it != map1.end(); it++)
        {
            vector<vector<string>>& vv2 = it->second;
            for (vector<string>& v1 : vv2)
            {
                std::sort(v1.begin() + 1, v1.end());
                ans.push_back(v1);
            }
        }

        #ifdef __test
        cout<<ans.size()<<endl;
//        cout<<q<<endl;
        for (auto p : ans)
        {
            cout<<p.size()<<", ";
            for_each(p.begin(), p.end(), fun_cout_s);
            cout<<endl;
        }
        #endif // __test

        return ans;
    }


    // error, david012345
    vector<vector<string>> lt0721a(vector<vector<string>>& accounts)
    {
        map<string, int> map1;          // mail -> int
        map<int, string> map2;          // int -> name
        int q = 0;

        for (vector<string>& acc : accounts)
        {
            string name = acc[0];
            int q2 = -1;
            for (int i = 1; i < acc.size(); i++)
            {
                if (map1.find(acc[i]) != map1.end())
                {
                    q2 = map1[acc[i]];
                    break;
                }
                else
                {
//                    map1[acc[i]] = q;
//                    map2[q] = name;
//                    q++;
                }
            }
            if (q2 == -1)
            {
                q2 = q++;
                map2[q2] = name;
            }
            for (int i = 1; i < acc.size(); i++)
            {
                map1[acc[i]] = q2;
            }
        }

        vector<vector<string>> ans(q);
        for (int i = 0; i < q; i++)
        {
            vector<string> v2;
            v2.push_back(map2[i]);
            for (map<string, int>::iterator it = map1.begin(); it != map1.end(); it++)
            {
                if (it->second == i)
                {
                    v2.push_back(it->first);
                }
            }
            std::sort(v2.begin() + 1, v2.end());
            ans[i] = v2;
        }

        #ifdef __test
        cout<<ans.size()<<endl;
        cout<<q<<endl;
        for (auto p : ans)
        {
            cout<<p.size()<<", ";
            for_each(p.begin(), p.end(), fun_cout_s);
            cout<<endl;
        }
        #endif // __test

        return ans;
    }

};

int main()
{

//    vector<vector<string>> accs = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};

//    vector<vector<string>> accs = {{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};

    vector<vector<string>> accs = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};


//    vector<vector<string>> accs = {
//    {"David","David0@m.co","David4@m.co","David3@m.co"},
//    {"David","David5@m.co","David5@m.co","David0@m.co"},
//    {"David","David1@m.co","David4@m.co","David0@m.co"},
//    {"David","David0@m.co","David1@m.co","David3@m.co"},
//    {"David","David4@m.co","David1@m.co","David3@m.co"}
//    };



    LT0721 lt;


    lt.lt0721d(accs);

    return 0;
}
