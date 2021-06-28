
#include "../header/myheader.h"

class LT0591
{
public:

// D D


// stack， regular expression


//if (code.startsWith("<![CDATA[", i)) {




//Runtime: 4 ms, faster than 53.52% of C++ online submissions for Tag Validator.
//Memory Usage: 6.6 MB, less than 32.39% of C++ online submissions for Tag Validator.
// <![CDATA[CDATA_CONTENT]]>
    bool lt0591a(string code)
    {
        int idx = -1;
        int idxen = -1;
        while ((idx = (int) code.find("<![CDATA[")) != std::string::npos)
        {
            idxen = code.find("]]>", idx);
            if (idxen == std::string::npos)
                return false;
            code = code.substr(0, idx) + "-" + (code.substr(idxen + 3));        // <DI<![CDATA[CDATA_CONTENT]]>V>zxcv</DIV> ?
        }
        #ifdef __test
        cout<<code<<endl;
        #endif // __test
        if (code.size() < 7 || code[0] != '<' || code[code.size() - 1] != '>')
            return false;

        idx = 1;
        idxen = code.find('>');
        if (idxen == std::string::npos)
        {
            #ifdef __test
            cout<<"@ cannot find >"<<endl;
            #endif // __test
            return false;
        }
        string tagn = code.substr(1, idxen - idx);
        if (!isValidTagName(tagn))
        {
            #ifdef __test
            cout<<"@ not valid  "<<tagn<<endl;
            #endif // __test
            return false;
        }

        string tagn2 = code.substr(code.size() - tagn.size() - 1 - 2);
        if (tagn2[0] != '<' || tagn2[1] != '/' || tagn2.substr(2, tagn.size()) != tagn)
        {
            #ifdef __test                           // i should throw exception... but...
            cout<<"@first, error  "<<tagn2<<", "<<tagn<<endl;
            #endif // __test
            return false;
        }

        stack<string> stk1;
        for (int i = 0; i < code.size(); ++i)
        {
            if (code[i] == '<')
            {
                idxen = code.find('>', i);
                if (idxen == std::string::npos)
                {
                    #ifdef __test
                    cout<<"cannot find > "<<i<<endl;
                    #endif // __test
                    return false;
                }
                if (i == code.size() - 1)
                {
                    #ifdef __test
                    cout<<"< is the last..."<<endl;
                    #endif // __test
                    return false;
                }
                int t2 = 1;
                bool isEnd = false;
                if (code[i + 1] == '/')
                {
                    isEnd = true;
                    t2++;
                }
                string tagName = code.substr(i + t2, idxen - i - t2);       // startIndex, length... not endIndex...
                if (!isValidTagName(tagName))
                {
                    #ifdef __test
                    cout<<tagName<<", is not valid tag name "<<(i + t2)<<" - "<<idxen<<endl;
                    #endif // __test
                    return false;
                }
                if (isEnd)
                {
                    if (stk1.empty())
                    {
                        #ifdef __test
                        cout<<"stk1 is empty222"<<endl;
                        #endif // __test
                        return false;
                    }
                    string str2 = stk1.top();
                    if (str2 != tagName)
                    {
                        #ifdef __test
                        cout<<str2<<"  <>  "<<tagName<<endl;
                        #endif // __test
                        return false;
                    }
                    stk1.pop();
                }
                else
                {
                    #ifdef __test
                    cout<<" // push "<<tagName<<endl;
                    #endif // __test
                    stk1.push(tagName);
                }
                i = idxen;
            }
            else
            {
                if (stk1.empty())
                {
                    #ifdef __test
                    cout<<"stk1 is empty."<<endl;
                    #endif // __test
                    return false;
                }
            }
        }
        return stk1.empty();
//        return true;
    }

    bool isValidContent(string& s)
    {
        return s.find('<') == std::string::npos;
    }

    bool isValidTagName(string& s)
    {
        if (s.size() >= 1 && s.size() <= 9)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (!std::isupper(s[i]))
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        return true;
    }

};

int main()
{
//    string s = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
//    string s = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
//    string s = "<A>  <B> </A>   </B>";
//    string s = "<DIV>  div tag is not closed  <DIV>";

    string s = "<A></A><B></B>";        // false.... 整个string 只是一个标签。？

    LT0591 lt;

    cout<<lt.lt0591a(s)<<endl;

    return 0;
}
