
#include "../../header/myheader.h"

class LT
{
public:



};


// D D

// 2 stack






//Runtime151 ms
//Beats
//49.46 %
//Memory56.6 MB
//Beats
//99.5 %
class BrowserHistory {

    vector<string> vs;
    int mxsz;
    int idx;        // last index
    int fwsz;
public:
    BrowserHistory(string homepage) {
        //this->mxsz = 0;
        //this->idx = 0;
        this->vs.push_back(homepage);
        this->mxsz = 1;
        this->idx = 0;
        this->fwsz = 1;
    }

    void visit(string url) {
        ++this->idx;
        if (this->idx >= this->vs.size())
        {
            this->vs.push_back(url);
        }
        else
        {
            this->vs[idx] = url;
        }
        ++this->mxsz;
        this->fwsz = this->mxsz;
    }

    string back(int steps) {
        if (steps > this->idx)
        {
            this->mxsz = 1;
            this->idx = 0;
            return this->vs[0];
        }
        else
        {
            this->mxsz -= steps;
            this->idx -= steps;
            return this->vs[this->idx];
        }
    }

    string forward(int steps) {
        //....

        if (this->idx + steps >= this->fwsz)
        {
            this->idx = this->fwsz - 1;
            this->mxsz = this->fwsz;
        }
        else
        {
            this->idx += steps;
            this->mxsz = this->idx + 1;
        }

        return this->vs[this->idx];
    }

};


int main()
{

    LT lt;


    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    cout<<endl<<browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    cout << endl << browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
    cout << endl << browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    cout << endl << browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
    cout << endl << browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    cout << endl << browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"


    return 0;
}
