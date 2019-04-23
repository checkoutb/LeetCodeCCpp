
#include "../header/myheader.h"


using namespace std;

// ����ŷ�����Ӧ����LC��������LT��Ϊ��һ�£����Ǽ���LT�ɡ�

//Runtime: 16 ms, faster than 99.21% of C++ online submissions for Burst Balloons.
//Memory Usage: 8.8 MB, less than 91.79% of C++ online submissions for Burst Balloons.

// �������ǿ���discuss��д�ġ��Լ�д������

class LT0312 {
public:
    int lt0312a(vector<int>& nums) {
        int result = 0;
        nums.insert(nums.end(), 1);
        nums.insert(nums.begin(), 1);

//        cout<<"lt"<<endl;
//        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//            cout<<*it<<",";
//        cout<<endl<<nums.size()<<endl;


        int len = nums.size();
        int arr1[len][len] = {{0}};     // �����0�г��˵�0��Ϊ0�⣬��������������������ж���0��0�в�Ӱ������

//        cout<<arr1[2][4]<<"aaaa"<<endl;

//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < len; j++)
//            {
////                arr1[i][j] = 0;
//                cout<<arr1[i][j]<<"  ";
//            }
//            cout<<endl;
//        }

        for (int i = 1; i < len - 1; i++)           // ���   i
        {
            for (int j = 1; j < len - i; j++)       // ��ʼ   j
            {
                for (int k = j; k < j + i; k++)     // [��ʼ����ʼ+���]��[j, j + i - 1]
                {
                    // ������� ���� [��ʼ����ʼ+���] ������ �����ֵ��������Ϊ []��ʣ�µ����һ��������k
                    // �ͱ���� ��ʼ-1 * k * ��ʼ+���+1 + ����[��ʼ��k)��(k, ��ʼ+����] ���Ե����ֵ ��Ϊ ���� [] �����ֵ��
                    int t1 = nums[j - 1] * nums[k] * nums[j + i] + arr1[j][k - 1] + arr1[k + 1][j + i - 1];

//                    cout<<i<<","<<j<<","<<k<<","<<t1<<","<<arr1[i][j]<<endl;

                    if (arr1[j][j + i - 1] < t1)
                        arr1[j][j + i - 1] = t1;
                }
            }
        }

        // �����Ǿ���
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < len; j++)
//            {
//                cout<<arr1[i][j]<<"  ";
//            }
//            cout<<endl;
//        }

        result = arr1[1][len - 2];

        return result;
    }
};


void fun_cout(int i)
{
    cout<<i<<",";
}

int main()
{
    cout<<"hi"<<endl;
    LT0312 lt = LT0312();
//    vector<int> v(2,1);           // 2ge 1
//    v.insert(v.begin(),3,5);

    int arr[] = {3,1,5,8};
    vector<int> v(arr, arr + 4);

    for_each(v.begin(), v.end(), fun_cout);

    int result = lt.lt0312a(v);
    cout<<result<<endl;
    return 0;
}
