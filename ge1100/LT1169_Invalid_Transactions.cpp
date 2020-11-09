
#include "../header/myheader.h"

class LT1169
{
public:




//Runtime: 88 ms, faster than 60.86% of C++ online submissions for Invalid Transactions.
//Memory Usage: 23.3 MB, less than 5.80% of C++ online submissions for Invalid Transactions.
    vector<string> lt1169a(vector<string>& transactions)
    {
        string name;
        int time;
        int amount;
        string city;
        int c1,c2,c3;
        unordered_map<string, vector<tuple<int, int, string>>> map2;        // name : <time,amount,city>
        for (string& s : transactions)
        {
            c1 = s.find(',');
            c2 = s.find(',', c1 + 1);
            c3 = s.find(',', c2 + 1);
            name = s.substr(0, c1);
            time = std::stoi(s.substr(c1 + 1, (c2 - c1)));
            amount = std::stoi(s.substr(c2 + 1, (c3 - c2)));
            city = s.substr(c3 + 1);
//            cout<<name<<", "<<time<<", "<<amount<<", "<<city<<endl;
            map2[name].push_back(std::make_tuple(time, amount, city));
        }
        vector<string> ans;

        for (auto& p : map2)
        {
            std::sort(begin(p.second), end(p.second));
        }

        for (auto& p : map2)
        {
            string name = p.first;
            vector<tuple<int, int, string>>& vt = p.second;
            for (int i = 0; i < vt.size(); i++)
            {
                if (std::get<1>(vt[i]) > 1000)
                    ans.push_back(name + "," + std::to_string(std::get<0>(vt[i])) + "," + std::to_string(std::get<1>(vt[i])) + "," + std::get<2>(vt[i]));
                time = std::get<0>(vt[i]) + 60;
                for (int j = i + 1; j < vt.size(); ++j)
                {
                    if (std::get<0>(vt[j]) <= time && std::get<2>(vt[j]) != std::get<2>(vt[i]))
                    {
                        if (std::get<1>(vt[i]) <= 1000)
                        {
                            ans.push_back(name + "," + std::to_string(std::get<0>(vt[i])) + "," + std::to_string(std::get<1>(vt[i])) + "," + std::get<2>(vt[i]));
                        }
                        if (std::get<1>(vt[j]) <= 1000)
                        {
                            ans.push_back(name + "," + std::to_string(std::get<0>(vt[j])) + "," + std::to_string(std::get<1>(vt[j])) + "," + std::get<2>(vt[j]));
                        }
                    }
                }
            }
        }

        // 交易  1,2,3,4 全在 1小时内，不同城市 发生， 结果就是1，2，3，4， 但是 上面的结果会是 1，2，3，4，2，3，4，3，4。
        // 主要是，map 和 transaction 脱节了， 应该来一个 {name : <time,amount,city,transaction>}。
        // 并且 准备一个 set， 这样 就能遍历前，先去重下，且 不需要拼接 transaction。
        unordered_set<string> set2(begin(ans), end(ans));
        ans = vector<string>(begin(set2), end(set2));
        return ans;
    }

};

int main()
{

//    vector<string> vs = {"alice,20,800,mtv","alice,50,100,beijing"};
//    vector<string> vs = {"alice,20,800,mtv","alice,50,1200,mtv"};
    vector<string> vs = {"alice,20,800,mtv","bob,50,1200,mtv"};

    tuple<int,int,string,string> tp = std::make_tuple(1,2,"s3","s4");
    cout<<std::get<0>(tp)<<get<1>(tp)<<get<2>(tp)<<get<3>(tp)<<endl;

    LT1169 lt;

    vector<string> ans = lt.lt1169a(vs);

    for_each(begin(ans), end(ans), fun_cout_s);
    cout<<endl;

    return 0;
}
