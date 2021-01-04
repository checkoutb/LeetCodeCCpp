
#include "../header/myheader.h"

class LT0636
{
public:

// D D


//struct Log {
//    int id;
//    string status;
//    int timestamp;
//};
//
//class Solution {
//public:
//    vector<int> exclusiveTime(int n, vector<string>& logs) {
//        vector<int> times(n, 0);
//        stack<Log> st;
//        for(string log: logs) {
//            stringstream ss(log);
//            string temp, temp2, temp3;
//            getline(ss, temp, ':');
//            getline(ss, temp2, ':');
//            getline(ss, temp3, ':');
//
//            Log item = {stoi(temp), temp2, stoi(temp3)};
//            if(item.status == "start") {
//                st.push(item);
//            } else {
//                assert(st.top().id == item.id);
//
//                int time_added = item.timestamp - st.top().timestamp + 1;
//                times[item.id] += time_added;
//                st.pop();
//
//                if(!st.empty()) {
//                    assert(st.top().status == "start");
//                    times[st.top().id] -= time_added;
//                }
//            }
//        }
//
//        return times;
//    }
//};



//Runtime: 16 ms, faster than 99.87% of C++ online submissions for Exclusive Time of Functions.
//Memory Usage: 13.6 MB, less than 79.79% of C++ online submissions for Exclusive Time of Functions.
    vector<int> lt0636a(int n, vector<string>& logs)
    {
        vector<int> ans(n);
        stack<int> stk1;
        int tine = 0;
        for (int i = 0; i < logs.size(); ++i)
        {
            int id = 0;
            for (char& ch : logs[i])
                if (std::isdigit(ch))
                    id = (id * 10 + ch - '0');
                else
                    break;

            int ts = 0;
            int t2 = 1;
            int j = logs[i].size() - 1;
            for (; logs[i][j] != ':'; --j, t2 *= 10)
                ts += (logs[i][j] - '0') * t2;

            bool isStart = logs[i][j - 1] == 't';

            int gap = ts - tine;
            tine = ts;

            #ifdef __test
            cout<<tine<<", "<<gap<<endl;
            #endif // __test

            if (isStart)
            {
                if (!stk1.empty())
                {
                    int idx = stk1.top();
                    ans[idx] += gap;
                }
                stk1.push(id);
            }
            else
            {
                gap++;
                int idx = stk1.top();
                stk1.pop();
                ans[idx] += gap;
                tine++;
            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
//    int n = 2;

//    vector<string> vs = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
//    int n = 1;

    vector<string> vs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    int n = 2;

    LT0636 lt;

    vector<int> v = lt.lt0636a(n, vs);

    showVectorInt(v);

    return 0;
}
