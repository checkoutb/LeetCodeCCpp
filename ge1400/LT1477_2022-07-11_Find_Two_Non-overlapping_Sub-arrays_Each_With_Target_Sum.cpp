
#include "../header/myheader.h"

class LT1477
{
public:

    // D D


    // prefix sum ��ת map<sum, idx> ����value>0������prefix sum û���ظ��ġ�
    // Ȼ�� for(0..sz1-1)�����ݵ�ǰ�±��ǰ׺�ͣ��ҵ� ����� ��һ���ܹ����target���±꣬����У���ô min(ans,(��ǰ���鳤�� + min(֮ǰ������ĳ���)))
    //      Ȼ�� ���� min(���������鳤��)


    // �� ���飬��ʾ ����±�֮ǰ����С�� ���鳤�ȡ�
    // for�� �������һ�� target�����飬��ô�� ����  ����[st-1] ��ֵ��




//Runtime: 224 ms, faster than 56.59 % of C++ online submissions for Find Two Non - overlapping Sub - arrays Each With Target Sum.
//Memory Usage : 82.6 MB, less than 50.29 % of C++ online submissions for Find Two Non - overlapping Sub - arrays Each With Target Sum.
    // ... non-overlapping ��ָ����ȫ�ص����� ������ û���κ��ص����֡�
    // .....�������˴��룬������������ġ���
    // ......����� ��ȫ���ص��� д���� ����ȫ�ص��� Ȼ����ˣ�����Ϊ ��Ҫ ����ȫ�ص�������
    int lt1477a(vector<int>& arr, int target)
    {
        vector<pair<int, int>> vp;
        int sum2 = 0;
        int st = 0;
        int sz1 = arr.size();
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += arr[i];
            while (sum2 > target)
            {
                sum2 -= arr[st++];
            }
            if (sum2 == target)
            {
                vp.push_back({ st, i });            // [st, i]
            }
        }
        int ans = INT_MAX;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> priq;

        for (pair<int, int>& p : vp)
        {
            priq.push({ p.second - p.first + 1, p });
#ifdef __test
            cout << priq.size() << " --- " << p.first << " - " << p.second << endl;
#endif
        }

        for (int i = 0; i < vp.size(); ++i)
        {
            int st = vp[i].first;
            int en = vp[i].second;

            while ((!priq.empty()) && priq.top().second.first <= en)        // <= st ���ǲ���ȫ�ص�
                priq.pop();

            if (priq.empty())
                break;
            ans = std::min(ans, int(en - st + 1 + (priq.top().first)));
        }

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT1477 lt;

    //myvi v = { 3,2,2,4,3 };
    //int t = 3;

    //myvi v = { 1,6,3,4,7 };
    //int t = 7;

    //myvi v = { 4,3,2,6,2,3,4 };
    //int t = 6;

    myvi v = { 1,7,1 };
    int t = 8;

    cout << lt.lt1477a(v, t) << endl;

    return 0;
}
