
#include "../header/myheader.h"

class LT1472
{
public:



};

// D D

// dual link list



//void visit(string url) {
//    ++pos;
//    history.resize(pos);
//    history.push_back(url);
//}
//pos = max(0, pos - steps);
//pos = min((int)history.size() - 1, pos + steps);


// 2 stack
//void visit(string url) {
//    h_forward = stack<string>();
//    h_back.push(cur);
//    cur = url;
//}
//    while (--steps >= 0 && !h_back.empty()) {
//        h_forward.push(cur);
//        cur = h_back.top();
//        h_back.pop();
//    }
//    return cur;
//    while (--steps >= 0 && !h_forward.empty()) {
//        h_back.push(cur);
//        cur = h_forward.top();
//        h_forward.pop();
//    }
//    return cur;


//Runtime: 172 ms, faster than 91.77% of C++ online submissions for Design Browser History.
//Memory Usage: 54.5 MB, less than 91.48% of C++ online submissions for Design Browser History.
class BrowserHistory {

    vector<string> urls;
    int now;
    int mxsz1;

public:
    BrowserHistory(string homepage) {
        this->urls.push_back(homepage);
        this->now = 0;
        this->mxsz1 = 1;
    }

    void visit(string url) {
        if (urls.size() > now + 1)
        {
            urls[++now] = url;
            mxsz1 = now + 1;
        }
        else
        {
            urls.push_back(url);
            now++;
            mxsz1 = urls.size();
        }
//        #ifdef __test
//        cout<<endl<<" - -vvvvv- sss- -"<<endl;
//        cout<<now<<", "<<mxsz1<<endl;
//        for (string& s : urls)
//            cout<<s<<", ";
//        cout<<endl<<" - -vvvvv- eee- -"<<endl;
//        #endif // __test
    }

    string back(int steps) {
        int idx = now - steps;
        idx = max(idx, 0);
        now = idx;
        return urls[idx];
    }

    string forward(int steps) {
        int idx = now + steps;
        idx = min(idx, mxsz1 - 1);
        now = idx;
        return urls[idx];
    }
};

int main()
{

    LT1472 lt;

    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    cout<<endl<<browserHistory.back(1); // return "facebook.com"
    cout<<endl<<browserHistory.back(1); // return "google.com"
    cout<<endl<<browserHistory.forward(1); // return "facebook.com"
    browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    cout<<endl<<browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
    cout<<endl<<browserHistory.back(2);     // return "google.com"
    cout<<endl<<browserHistory.back(7);    // return "leetcode.com"



    return 0;
}
