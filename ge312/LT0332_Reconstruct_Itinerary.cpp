
#include "../header/myheader.h"

class LT0332
{
public:


//Runtime: 308 ms, faster than 5.04% of C++ online submissions for Reconstruct Itinerary.
//Memory Usage: 220.9 MB, less than 5.04% of C++ online submissions for Reconstruct Itinerary.

    // 可以提升的地方，map<string, sorted list<string>>..把这个机场可能的目的地全部排序好.其他想不出了。
    // &形参 会有提升!.. test1,,,test2.

    // set，multiset 都是有序的(虽然不清楚默认的排序规则。)。。而且，确实，应该multiset，允许元素重复。
    // 有个 unordered_set..unordered_map...

// 有序的。
//template < class T,                        // set::key_type/value_type
//           class Compare = less<T>,        // set::key_compare/value_compare
//           class Alloc = allocator<T>      // set::allocator_type
//           > class set;

// 也是有序的。
//template < class Key,                                     // map::key_type
//           class T,                                       // map::mapped_type
//           class Compare = less<Key>,                     // map::key_compare
//           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
//           > class map;

// java可以用 Collections.sort(entry.getValue());。


// StefanPochmann
// java
//public List<String> findItinerary(String[][] tickets) {
//    for (String[] ticket : tickets)
//        targets.computeIfAbsent(ticket[0], k -> new PriorityQueue()).add(ticket[1]);
//    visit("JFK");
//    return route;
//}
//
//Map<String, PriorityQueue<String>> targets = new HashMap<>();
//List<String> route = new LinkedList();
//
//void visit(String airport) {
//    while(targets.containsKey(airport) && !targets.get(airport).isEmpty())
//        visit(targets.get(airport).poll());
//    route.add(0, airport);
//}

// java
//public List<String> findItinerary(String[][] tickets) {
//    Map<String, PriorityQueue<String>> targets = new HashMap<>();
//    for (String[] ticket : tickets)
//        targets.computeIfAbsent(ticket[0], k -> new PriorityQueue()).add(ticket[1]);
//    List<String> route = new LinkedList();
//    Stack<String> stack = new Stack<>();
//    stack.push("JFK");
//    while (!stack.empty()) {
//        while (targets.containsKey(stack.peek()) && !targets.get(stack.peek()).isEmpty())
//            stack.push(targets.get(stack.peek()).poll());
//        route.add(0, stack.pop());
//    }
//    return route;
//}

// c++
//vector<string> findItinerary(vector<pair<string, string>> tickets) {
//    for (auto ticket : tickets)
//        targets[ticket.first].insert(ticket.second);
//    visit("JFK");
//    return vector<string>(route.rbegin(), route.rend());
//}
//
//map<string, multiset<string>> targets;
//vector<string> route;
//
//void visit(string airport) {
//    while (targets[airport].size()) {
//        string next = *targets[airport].begin();
//        targets[airport].erase(targets[airport].begin());
//        visit(next);
//    }
//    route.push_back(airport);
//}




    vector<string> lt0332b(vector<vector<string>>& tickets)
    {
        int sz1 = tickets.size();
        vector<string> result = {"JFK"};
        string last = "JFK";
        bool arr[sz1] = {};
        result = recursionb1(tickets, result, arr);
        return result;
    }

    vector<string> recursionb1(vector<vector<string>>& t, vector<string> s, bool arr[])
    {
        if (s.size() == (t.size() + 1))
            return s;
        string last = s.back();
        int sz1 = t.size();
        vector<string> v;
        vector<int> index_v;
        int m1;
        string s1;
        int m2;
        string s2;
        for (int i = 0; i < sz1; i++)
        {
            if (arr[i])
                continue;
            v = t[i];
            if (v[0] == last)
            {
                index_v.push_back(i);
            }
        }
        while (!index_v.empty())
        {
            m1 = index_v[0];
            s1 = t[m1][1];
            int mi = 0;
            for (int i = 1; i < index_v.size(); i++)
            {
                // min
                m2 = index_v[i];
                s2 = t[m2][1];
                for (int k = 0; k < 3; k++)
                {
                    if (s1[k] != s2[k])
                    {
                        if (s1[k] > s2[k])
                        {
                            m1 = m2;
                            s1 = s2;
                            mi = i;
                        }
                        break;
                    }
                }
            }
            index_v.erase(index_v.begin() + mi);

            arr[m1] = true;
            vector<string> v2 = s;
            v2.push_back(s1);
            v = recursionb1(t, v2, arr);
            arr[m1] = false;

            #ifdef __test
            cout<<"..."<<v2.size()<<endl;
            for_each(s.begin(), s.end(), fun_cout_s);
            cout<<endl;
            for_each(v2.begin(), v2.end(), fun_cout_s);
            cout<<"............."<<v.size()<<endl;
            #endif // __test

            if (v.size() == (t.size() + 1))
            {
                return v;
            }
        }
        v.clear();
        return v;
    }

    // 环。。。
    vector<string> lt0332a(vector<vector<string>>& tickets)
    {
        int sz1 = tickets.size();
        vector<string> result = {"JFK"};
        string last = "JFK";
        int i = 0;
        int m1 = 0;
        int l1 = 0;
        int l2 = 0;
        bool arr[sz1] = {};

        #ifdef __test
        for (int kq = 0; kq < sz1; kq++)
            cout<<arr[kq]<<", ";
        cout<<endl;
        #endif // __test

        vector<string> v1;
        vector<int> index_v;
        string s1;
        string s2;
        while (result.size() <= sz1)
        {
            #ifdef __test
            cout<<result.size()<<"..."<<sz1<<"..last..."<<last<<endl;
            #endif // __test

            index_v.clear();
            for (int j = 0; j < sz1; j++)
            {
                if (arr[j])
                    continue;
                v1 = tickets[j];
                if (v1[0] == last)
                {
                    index_v.push_back(j);
                }
            }
            #ifdef __test
            for_each(index_v.begin(), index_v.end(), fun_cout);
            cout<<endl;
            #endif // __test
            m1 = index_v[0];                // ...
            s1 = tickets[m1][1];
            for (int j = 1; j < index_v.size(); j++)
            {
                s2 = tickets[index_v[j]][1];
                for (int k = 0; k < 3; k++)
                {
#ifdef __test
                    cout<<"kkk"<<k<<"...."<<s1<<".,"<<s2<<endl;
                    cout<<s1[k]<<"............."<<s2[k]<<endl;
#endif // __test
                    if (s1[k] != s2[k])
                    {
                        if (s1[k] > s2[k])
                        {
                            s1 = s2;
                            m1 = j;
                        }
                        break;
                    }
//                    if ((int) s1[k] > (int) s2[k])
//                    {
//                        s1 = s2;
//                        m1 = j;
//                        break;
//                    }
                }
            }
            arr[m1] = true;
            last = s1;
            #ifdef __test
            cout<<"s1.."<<s1<<".."<<m1<<endl;
            #endif // __test
            result.push_back(s1);
        }
        return result;
    }



    void test1(vector<int>& a)
    {
        a.push_back(1111);
    }

    void test2(vector<int> a)
    {
        a.push_back(3333);
    }

};

int main()
{
//    vector<vector<string>> v = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
//    vector<vector<string>> v = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> v = {{"JFK","ATL"},{"ORD","PHL"},{"JFK","ORD"},{"PHX","LAX"},{"LAX","JFK"},{"PHL","ATL"},{"ATL","PHX"}};
//    vector<vector<string>> v = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};     // 环。。。

    LT0332 lt;
    vector<string> v2 = lt.lt0332b(v);
    cout<<endl<<endl;
    for_each(v2.begin(), v2.end(), fun_cout_s);
    cout<<endl;

    vector<int> iv1 = {1,2,3};
    vector<int> iv2 = {3,2,1};

    lt.test1(iv1);
    lt.test2(iv2);

    for_each(iv1.begin(), iv1.end(), fun_cout);
    cout<<endl;
    for_each(iv2.begin(), iv2.end(), fun_cout);
    cout<<endl<<iv1.size()<<"..."<<iv2.size()<<endl;

    return 0;
}
