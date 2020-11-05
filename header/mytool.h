

vector<string> splitMy(string s)
{
    istringstream iss(s);
    vector<string> ans;
    string st;
    while (std::getline(iss, st, ' '))
    {
        ans.emplace_back(st);
    }
    return ans;
}

vector<string> splitMy2(string s, char ch)
{
    istringstream iss(s);
    vector<string> ans;
    string st;
    while (std::getline(iss, st, ch))
    {
        ans.emplace_back(st);
    }
    return ans;
}

// 用& 的话，函数的返回 没有办法直接 直接变成形参。
void showVectorInt(vector<int> v)
{
    cout<<" show vector<int>:"<<endl;
    for_each(begin(v), end(v), fun_cout);
    cout<<endl;
}
