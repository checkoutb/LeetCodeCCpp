
#include "../header/myheader.h"

class LT2499
{
public:






    // g


    // error.. example 1... �������ȣ���ȫ����Ҫswap�����Ȼ��һ�� index �� swap 2�Ρ�
    // ���� Ҫ���£������� ��¼�Ƿ���swap��
    //
    // error�� �� ���� ���ֿ��ܵģ��������ĸ��ࡣ ���� {2,2} . bu,���ᡣ ����ֻ����ȵ�ʱ��Ż� ����ġ�
    // �����error ����� �±�1 ���� 2 - 3,  ������ 3-3�� ��ô�����ϣ����� map[a]++ �����ˣ� �´��� 5-6 �ǿ����� 2-3�ģ����Ǳ� �����ˡ�
    //  ���ǣ� ֻ����ȵ�ʱ��Ż����ģ� ���Բ���Ҫ�ж���ô�ࡣ
    long long lt2499b(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        map<int, int> map2;     // !key
        //vector<pair<int, bool>> vp;     // <index, swapped?>
        //vector<bool> vb(sz1, false);        // changed?
        vector<int> vp;

        int a, b;
        int t2, t3;
        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums1[i] == nums2[i])
            {
                //a = map2[i];
                a = 0;
                for (; a < vp.size(); ++a)
                {
                    if (nums1[vp[a]] != nums2[vp[a]])
                    {
                        continue;
                    }
                    t2 = vp[a];
                    //if (nums1[t2] != nums2[i] && nums1[i] != nums2[t2])
                    if (nums1[t2] != nums1[i])      // vp�е� ���� v1[first] == v2[first] �ģ����� ����Ҳ�� v1[i] == v2[i]
                    {
                        t3 = nums1[t2];
                        ans = ans + i + t2;
                        //vb[t2] = vb[i] = true;
                        //vp[a].second = true;
                        t3 = nums1[t2];
                        nums1[t2] = nums1[i];
                        nums1[i] = t3;

                        ++a;
                        goto AAA;
                    }
                }
                vp.push_back(i);

                AAA:
                map2[i] = a;
            }
        }

        map2.clear();

        for (int i = 0; i < vp.size(); ++i)
        {
            if (nums1[vp[i]] != nums2[vp[i]])
                continue;

            t2 = vp[i];
            //int a = map2[t2];
            int a = 0;
            for (; a < sz1; ++a)
            {
                //if (vb[a])
                //    continue;           // .

                if (nums1[a] != nums2[t2] && nums1[t2] != nums2[a])
                {
                    ans = ans + a + t2;
                    //vb[a] = true;
                    //vb[t2] = true;
                    t3 = nums1[a];
                    nums1[a] = nums1[t2];
                    nums1[t2] = t3;

                    ++a;
                    goto BBB;
                }
            }
            return -1;

            BBB:
            //map2[t2] = a;
            continue;
        }

        return ans;
    }


    // error  swap������ˡ�
    long long lt2499a(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, vector<int>> map2;
        int sz1 = nums1.size();
        for (int i = 0; i < sz1; ++i)
        {
            if (nums1[i] == nums2[i])
            {
                map2[nums1[i]].push_back(i);
            }
        }

        long long ans = 0LL;
        int mxcnt = 0;
        int totalcnt = 0;
        for (map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            totalcnt += it->second.size();
            mxcnt = max(mxcnt, (int)it->second.size());
            for (int i : it->second)
            {
                ans = ans + i;
            }
        }
        int t2 = 0;
        if (mxcnt > (totalcnt / 2))
        {
            t2 = mxcnt * 2 - totalcnt;
            for (int i = 0; i < sz1 && t2 > 0; ++i)
            {
                if (map2.find(nums1[i]) == map2.end())
                {
                    --t2;
                    ans = ans + i;
                }
            }
        }

        return t2 == 0 ? ans : -1;
    }

};

int main()
{

    LT2499 lt;

    //myvi v1 = { 1,2,2 };
    //myvi v2 = { 1,2,2 };

    //myvi v1 = { 2,2,2,1,3 };
    //myvi v2 = { 1,2,2,3,3 };

    //myvi v1 = { 1,2,2 };
    //myvi v2 = { 2,1,2 };

    //myvi v1 = { 1,2,3,4,5 };
    //myvi v2 = { 1,2,3,4,5 };

    myvi v1 = { 5,1,4,1,5,2,5,1,1 };
    myvi v2 = { 5,1,4,1,5,2,5,1,1 };

    cout << lt.lt2499b(v1, v2) << endl;

    return 0;
}
