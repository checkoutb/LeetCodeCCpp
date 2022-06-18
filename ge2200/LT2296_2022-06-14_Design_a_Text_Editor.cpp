
#include "../header/myheader.h"

class LT2296
{
public:



};


// hint : 前后分段，以cursor


// tle， 全部addText，每次都是40*"a"
class TextEditor {
    string str;
    int cur;        // next of left part ...  first of right part
public:
    TextEditor() {
        this->cur = 0;
    }

    void addText(string text) {
#ifdef __test
        //cout << "add" << this->cur << endl;
#endif
        string s2(this->str, 0, this->cur);
        string s3(this->str, this->cur);
        this->str = s2 + text + s3;
        this->cur = s2.size() + text.size();
    }

    int deleteText(int k) {
        int t2 = this->cur - k;
#ifdef __test
        //cout << "del " << t2 << endl;
#endif
        if (t2 <= 0)
        {
            this->str = this->str.substr(this->cur);
            t2 = this->cur;
            this->cur = 0;
            return t2;
        }
        string s2(this->str, 0, t2);
        string s3(this->str, this->cur);
        this->str = s2 + s3;
        this->cur = s2.size();
        return k;
    }

    string cursorRight(int k) {
        if (this->cur + k >= this->str.size())
        {
            this->cur = this->str.size();
            if (this->cur <= 10)
                return this->str;

            string s2(this->str, this->str.size() - 10);        // cur == size
            return s2;
        }
        this->cur += k;
        if (this->cur <= 10)
        {
            return string(this->str, 0, this->cur);
        }
        return string(this->str, this->cur - 10, 10);
    }

    string cursorLeft(int k) {
        if (this->cur <= k)
        {
            this->cur = 0;
            return "";
        }
        this->cur -= k;
        if (this->cur <= 10)
        {
            return string(this->str, 0, this->cur);
        }
        return string(this->str, this->cur - 10, 10);
    }
};


int main()
{

    LT2296 lt;

    TextEditor te;
    te.addText("leetcode");
    cout << endl << te.deleteText(4);
    te.addText("practice");
    cout << endl << te.cursorRight(3);
    cout << endl << te.cursorLeft(8);
    cout << endl << te.deleteText(10);
    cout << endl << te.cursorLeft(2);
    cout << endl << te.cursorRight(6);

    return 0;
}
