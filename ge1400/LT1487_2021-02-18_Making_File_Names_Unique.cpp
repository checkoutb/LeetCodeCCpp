
#include "../header/myheader.h"

class LT1487
{
public:

// D D


//    HashMap<String, Integer> map = new HashMap<>();
//    String res[] = new String[names.length];
//    for(int i = 0; i < names.length; i++) {
//        if(map.containsKey(names[i])) {
//            Integer val = map.get(names[i]);
//            StringBuilder sb = new StringBuilder(names[i]);
//            sb.append('(');
//            sb.append(val);
//            sb.append(')');
//            while (map.containsKey(sb.toString())) {
//                val++;
//                sb = new StringBuilder(names[i]);
//                sb.append('(');
//                sb.append(val);
//                sb.append(')');
//            }
//            res[i] = sb.toString();
//            map.put(sb.toString(), 1);
//            map.put(names[i], val + 1);
//        } else {
//            res[i] = names[i];
//            map.put(names[i], 1);
//        }
//    }
//    return res;
// 当在map3的set 中存在， 必然在 map2的key中存在。


//        unordered_map<string, int> count;
//        vector<string> result;
//        unordered_set<string> lookup;
//        for (const auto& name : names) {
//            auto& c = count[name];
//            string name_with_suffix;
//            do {
//                name_with_suffix = c ? name + "(" + to_string(c) + ")" : name;
//                ++c;
//            } while (lookup.count(name_with_suffix));
//            result.emplace_back(name_with_suffix);
//            lookup.emplace(move(name_with_suffix));
//        }
//        return result;
// std::move
// std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝。
//int &&rr1 = 42;        //正确，字面值常量是右值
//int &&rr2 = rr1;        //错误，表达式rr1是左值
//int &&rr3 = std::move(rr1);    //正确
//move告诉编译器我们有一个左值，但我们希望像一个右值一样处理它。注意：调用move意味着承诺：除了对rr1赋值和销毁它以外，我们不再使用它。在调用move之后，我们不能对移后源对象的值做任何假设。
// 感觉 lookup 也可以被 count 替代。



//Runtime: 160 ms, faster than 88.04% of C++ online submissions for Making File Names Unique.
//Memory Usage: 59.4 MB, less than 66.51% of C++ online submissions for Making File Names Unique.
    vector<string> lt1487a(vector<string>& names)
    {
        unordered_map<string, int> map2;        // min
        unordered_map<string, unordered_set<int>> map3;     // skip
        for (int i = 0; i < names.size(); ++i)
        {
            string nm = names[i];
            if (map2.find(nm) == map2.end())
            {
                map2[nm] = 1;
                if (nm[nm.size() -  1] == ')')       // aaa(a12)  ?
                {
                    int lst = nm.rfind('(');
                    if (lst != string::npos)
                    {
                        string subs = nm.substr(lst + 1, nm.size() - lst - 2);
                        int skp = std::stoi(subs);
                        map3[nm.substr(0, lst)].insert(skp);
                        #ifdef __test
                        cout<<subs<<", "<<skp<<", "<<nm.substr(0, lst)<<endl;
                        #endif // __test
                    }
                }
            }
            else
            {
                int t2 = map2[nm];
                if (map3.find(nm) != map3.end())
                {
                    unordered_set<int>& set2 = map3[nm];
                    while (set2.find(t2) != set2.end())
                    {
                        t2++;
                    }
                }
                map2[nm] = t2 + 1;
                nm += "(" + to_string(t2) + ")";
                names[i] = nm;
                map2[nm] = 1;
            }
        }
        return names;
    }

};

int main()
{

//    vector<string> vs = {"kaido","kaido(1)","kaido","kaido(1)"};
    vector<string> vs = {"wano","wano(2)","wano","wano"};

    LT1487 lt;

    vector<string> ans = lt.lt1487a(vs);

    for (string& s : ans)
        cout<<s<<", ";

    return 0;
}
