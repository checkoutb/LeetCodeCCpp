
#include "../header/myheader.h"

class LT1125
{
public:


    // g


    // 38 / 38 test cases passed, but took too long.         +   36/38 tle。
    // 0-1 背包？
    // 某个人员技能被 某个人 完全覆盖？   req_skills are unique.
    // Every skill in people[i] is a skill in req_skills.   不需要提前filter people 的技能。
    vector<int> lt1125a(vector<string>& req_skills, vector<vector<string>>& people)
    {
        for (int i = 0; i < people.size(); ++i)
        {
            sort(begin(people[i]), end(people[i]));
        }

        unordered_map<string, int> map5;
        for (int i = 0; i < people.size(); ++i)
        {
            vector<string>& vs = people[i];
            string key;
            for (string& s : vs)
            {
                key += (s + ",");
            }
            map5[key] = i;
        }

        sort(begin(people), end(people), [](vector<string>& vs1, vector<string>& vs2) { return vs1.size() > vs2.size(); });

        for (int i = 0; i < people.size(); ++i)
        {
            for (int j = i + 1; j < people.size(); ++j)
            {
                int ii = 0;
                int ji = 0;
                for (; ii < people[i].size() && ji < people[j].size(); ++ii)
                {
                    if (people[i][ii] == people[j][ji])
                    {
                        ii++;
                        ji++;
                    }
                    else
                    {
                        ii++;
                    }
                }
                if (ji == people[j].size())
                {
                    // [i] contain [j]
                    people.erase(begin(people) + j);
                    --j;
                }
            }
        }

#ifdef __test
        // ... 做了转换后，下标的信息消失了。。。
        for (vector<string>& vs : people)
        {
            for (string& s : vs)
            {
                cout << s << ", ";
            }
            cout << endl;
        }
#endif

        vector<int> ans;
        vector<int> vi;
        unordered_map<string, int> map2;
        for (string& s : req_skills)
            map2[s] = 0;

        dfsa1(people, map2, 0, vi, ans);

#ifdef __test
        cout << "1-1-2-34" << endl;
        showVectorInt(ans);
#endif

        for (int i = 0; i < ans.size(); ++i)
        {
            string key;
            for (string& s : people[ans[i]])
            {
                key += (s + ",");
            }
#ifdef __test
            cout << " 1 " << key << endl;
#endif
            ans[i] = map5[key];
        }

        return ans;
    }

    void dfsa1(vector<vector<string>>& people, unordered_map<string, int>& map2, int idx, vector<int>& vi, vector<int>& ans)
    {
        if (idx == people.size())
        {
            if (ans.empty() || (vi.size() < ans.size()))
            {
                for (auto& p : map2)
                {
                    if (p.second == 0)
                    {
                        goto AAA;
                    }
                }
#ifdef __test
                cout << " ans: " << endl;
                showVectorInt(ans);
                cout << " --- vi" << endl;
                showVectorInt(vi);
#endif
                ans = vi;
            }
            AAA:
            return;
        }

        bool b2 = true;     // true: not choose any people
        for (int i = idx; i < people.size(); ++i)
        {
            bool b4 = false;        // true: useful
            for (int j = 0; j < people[i].size(); ++j)
            {
                if (map2.find(people[i][j]) != map2.end() && (map2[people[i][j]] == 0))
                {
                    b4 = true;
                    break;
                }
            }
            if (b4)
            {
                b2 = false;
                for (string& s : people[i])
                {
                    if (map2.find(s) != map2.end())
                        map2[s]++;
                }
                vi.push_back(i);
                dfsa1(people, map2, i + 1, vi, ans);
                vi.pop_back();
                for (string& s : people[i])
                    //// error C2039: "contains": 不是 "std::unordered_map<std::string,int,std::hash<std::string>,std::equal_to<std::string>,std::allocator<std::pair<const std::string,int>>>" 的成员
                    //if (map2.contains(s))           // since c++ 20, it can work?
                    //    map2[s]--;
                    if (map2.find(s) != map2.end())
                        map2[s]--;
            }
        }
        if (b2)
        {
            dfsa1(people, map2, people.size(), vi, ans);
        }
    }

};

int main()
{

    LT1125 lt;

    //vector<string> v = { "java","nodejs","reactjs" };
    //vector<vector<string>> vv = { {"java"}, {"nodejs"}, {"nodejs", "reactjs"} };

    vector<string> v = { "algorithms", "math", "java", "reactjs", "csharp", "aws" };
    vector<vector<string>> vv = { {"algorithms", "math", "java"},{"algorithms", "math", "reactjs"},{"java", "csharp", "aws"},{"reactjs", "csharp"},{"csharp", "math"},{"aws", "java"} };


    myvi vi = lt.lt1125a(v, vv);

    showVectorInt(vi);

    return 0;
}
