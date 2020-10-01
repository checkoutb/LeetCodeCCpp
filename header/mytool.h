

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


