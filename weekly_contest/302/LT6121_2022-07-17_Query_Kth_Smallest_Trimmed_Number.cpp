
#include "../../header/myheader.h"

class LT6121
{
public:




    // AC������  ���� �������Ǹ� vvi ��
    // tle
    // string ������ͬ�� ���� ����
    // �Ƴ�������� x ������
    // ȷ�� �� k С�� ���ֵ��±꣬  ������ͬ�� �±�С�� ��С
    // 100
    // ���Ҳ࣬������ͬ������ ����ԭ�ȵ� ˳�� ֻ���� ��ͬǰ׺�� ����һЩ���⡣
    // 
    // ���� �����ģ��е� �Ҳ�ʣ�� x ����  Ȼ�� �� ��kС��ֵ ���ĸ��� ������ 
    // ֻ��Ӳ��ɣ�
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int sz1 = nums.size();
        int sz2 = queries.size();
        //sort(begin(nums), end(nums));
        vector<int> ans(sz2);

        vector<vector<int>> vvi(sz2);

        for (int i = 0; i < sz2; ++i)
        {
            vvi[i] = {queries[i][0], queries[i][1], i};
        }

        sort(begin(vvi), end(vvi), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });


        vector<pair<string, int>> vp;

        for (int i = 0; i < sz2; ++i)
        {
            int kth = vvi[i][0];
            int cut = nums[0].size() - vvi[i][1];

            if (i == 0 || vvi[i][1] != vvi[i - 1][1])
            {
                vp = vector<pair<string, int>>();
                for (int j = 0; j < sz1; ++j)
                {
                    vp.push_back({ nums[j].substr(cut), j });
                }
                sort(begin(vp), end(vp));
            }

#ifdef __test
            cout << " =======================" << endl;
            for (auto& p : vp)
            {
                cout << p.first << ", " << p.second << endl;
            }
#endif

            ans[vvi[i][2]] = vp[kth - 1].second;
        }

        return ans;
    }

};

int main()
{

    LT6121 lt;

    vector<string> vs = { "102","473","251","814" };
    myvvi vv = { {1,1},{2,3},{4,2},{1,2} };

    myvi v = lt.smallestTrimmedNumbers(vs, vv);

    showVectorInt(v);

    return 0;
}
