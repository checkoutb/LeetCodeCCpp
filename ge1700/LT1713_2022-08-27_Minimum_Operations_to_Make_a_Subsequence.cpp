
#include "../header/myheader.h"

class LT1713
{
public:





    // ���������ˣ�  ���� Ȼ����¡�   g��  �´Ρ�

    // hint
    // �������������ôд�ģ�����ֻ�ܱ�������
    int lt1713b(vector<int>& target, vector<int>& arr)
    {
        int sz1 = target.size();
        int sz2 = arr.size();

        unordered_map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            map2[target[i]] = i;
        }

        for (int i = 0; i < sz2; ++i)
        {
            if (map2.find(arr[i]) != map2.end())
            {
                arr[i] = map2[arr[i]];
            }
            else
            {
                arr[i] = INT_MAX;
            }
        }

        int ans = 0;
        unordered_map<int, int> map3;
        for (int i = 0; i < sz2; ++i)
        {
            if (arr[i] == INT_MAX)
                continue;

            for (int j = 0; j < arr[i]; ++j)
            {

            }

        }

        return ans;
    }


    // tle��
    // ������Ӵ���ʣ�µ�ȫ����Ҫ����ġ�
    // ���� ����̫���ˡ��� distinct ����û��ʲô�á�
    int lt1713a(vector<int>& target, vector<int>& arr)
    {
        int sz1 = target.size();
        int sz2 = arr.size();

//        vector<vector<int>>

        vector<int> vi(sz2, 0);

        for (int i = 0; i < sz1; ++i)
        {
            vector<int> v2(sz2, 0);
            for (int j = 0; j < sz2; ++j)
            {
                if (target[i] == arr[j])
                {
                    v2[j] = j == 0 ? 1 : (vi[j - 1] + 1);
                }
                else
                {
                    v2[j] = j == 0 ? vi[j] : max(vi[j], v2[j - 1]);
                }
            }
            swap(vi, v2);
        }
        return sz1 - vi[sz2 - 1];
    }

};

int main()
{

    LT1713 lt;

    //myvi v1 = { 5,1,3 };
    //myvi v2 = { 9,4,2,3,4 };

    myvi v1 = { 6,4,8,1,3,2 };
    myvi v2 = { 4,7,6,2,3,8,6,1 };

    cout << lt.lt1713a(v1, v2) << endl;

    return 0;
}
