
#include "../header/myheader.h"

class LT0722
{
public:

// D D

//return filter(None, re.sub('//.*|/\*(.|\n)*?\*/', '', '\n'.join(source)).split('\n'))
// python


//source.join($/).gsub(%r(//.*|/\*(.|\n)*?\*/), '').split($/).reject(&:empty?)
// ruby


//        for(int i = 0; i < source.size(); i++) {
//            for(int j = 0; j < source[i].size(); j++) {
//                if(!comment && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='/') break;
//                else if(!comment && j + 1 < source[i].size() && source[i][j] == '/' && source[i][j+1]=='*') comment = true, j++;
//                else if(comment && j + 1 < source[i].size() && source[i][j] == '*' && source[i][j+1]=='/') comment = false, j++;
//                else if(!comment) s.push_back(source[i][j]);
//            }
//            if(!comment && s.size()) ans.push_back(s), s.clear();
//        }



//Runtime: 4 ms, faster than 50.17% of C++ online submissions for Remove Comments.
//Memory Usage: 8.1 MB, less than 44.33% of C++ online submissions for Remove Comments.
// if the string // occurs in a block comment, it is ignored. Similarly, if the string /* occurs in a line or block comment, it is also ignored.
// */ 在 // 里应该也忽视吧？ ,不， //在block里 不算注释，所以 //无法忽略 */
    vector<string> lt0722a(vector<string>& source)
    {
        vector<string> ans;
        bool inBlock = false;
        bool ignore = false;
        bool contain = true;
        string s2;
        for (string& s : source)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                contain = true;
                if (s[i] == '/')
                {
                    if (inBlock)
                    {
                        if (i > 0 && s[i - 1] == '*')
                        {
                            inBlock = false;
                            ignore = false;
                            contain = false;
                        }
                    }
                    else
                    {
                        if (i + 1 < s.size() && s[i + 1] == '/')
                        {
                            break;
                        }
                        if (i + 1 < s.size() && s[i + 1] == '*')
                        {
                            (++i)++;
                            ignore = true;
                            inBlock = true;
                        }
                    }
                }
                if (!ignore && contain)
                {
                    s2 += s[i];
                }
            }
            if (s2.size() > 0 && !inBlock)
            {
                ans.push_back(s2);
                s2 = "";
            }


//            for (int i = 0; i < s.size(); ++i)
//            {
//                if (s[i] == '/')
//                {
//                    if (inBlock)
//                    {
//                        if (i > 0 && s[i - 1] == '*')
//                        {
//                            inBlock = false;
//                            if (i < s.size() - 1)
//                            {
//                                ans.push_back(s.substr(i + 1));
//                            }
//                        }
//                    }
//                    else
//                    {
//                        if (i + 1 < s.size() && s[i + 1] == '/')
//                        {
//                            if (i != 0)
//                            {
//                                ans.push_back(s.substr(0, i));
//                            }
//                            break;
//                        }
//                        if (i + 1 < s.size() && s[i + 1] == '*')
//                        {
//                            if (i != 0)
//                            {
//                                ans.push_back(s.substr(0, i));
//                            }
//                            inBlock = true;
//
//                            // /* 1 */      /* 2 */   123   /* 4 */
//                            for (++i++; i < s.size(); ++i)
//                            {
//                                if (s[i] == '/')
//                                {
//
//                                }
//                            }
//
//                            break;
//                        }
//                    }
//                }
//            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
//    vector<string> vs = {"a/*comment", "line", "more_comment*/b"};
//    vector<string> vs = {"a /*12*/  d w /* 42 */ /* 2 */    ."};

    // "struct Node{","    ","    int size;","    int val;","};"
    vector<string> vs = {"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};

    LT0722 lt;

    vector<string> ans = lt.lt0722a(vs);

    for (string& s : ans)
    {
        cout<<"? : "<<s.size()<<" : "<<s<<endl;
    }

    return 0;
}
