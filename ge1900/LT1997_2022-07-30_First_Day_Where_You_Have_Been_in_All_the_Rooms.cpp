
#include "../header/myheader.h"

class LT1997
{
public:

    // D 

        //Let dp[i] be the number of days needed to jump from room 0 to room i.The answer is dp[N - 1].

        //For dp[i], on top of the days needed for reaching room i - 1, i.e.dp[i - 1], we need these extra days to go from room i - 1 to room i.

        //If A[i - 1] == i - 1, we just need 2 days
        //Otherwise, we need to jump to room A[i - 1] first, taking 1 day.Then spent dp[i - 1] - dp[A[i - 1]] days to go from room A[i - 1] to room i - 1 again.Lastly, take 1 day to go from room i - 1 to room i.So in total, we need extra 2 + dp[i - 1] - dp[A[i - 1]] days.

    // .?



    // g


    // ��ʼ day 0 , visit room 0
    // ������(��������)�� ��һ�� ����Է��� <= nxtVst[room] �� root
    // ż���Σ� (room+1) % n
    // ���� ��һ��������� ����room�� 1e9+7
    // dfs �϶����У� 1e9+7 �� stack
    // bfs Ӧ��Ҳ���У� �Ͼ�һ��� �ӵ� 1e9������
    // nxtVst <= i�� ���� ��Ҫ �����ߣ�ֻ�� ż����ʱ �ſ��ԡ�
    // Ҫ �� ���room �� ż���Σ� ��ô room-1 Ҳ������ż���Σ� ���� �Ż�� room-1 �ߵ� room ��Ȼ�����ߵ� room+1
    // room-1ż����room-2 ..-3...   
    // (room+1)%n ����Զ�ò����ģ� ���� n ��ʱ�򣬾� return�ˡ�
    // ���ң� ������ ż���� ���� room ʱ��  ǰ��� room-1,room-2...-3 Ҳ���� ż���ν��룬  �����´ν��� ���� �����ν����ˡ�
    // ������ ǰ�� �����������Σ� ���� ������� ż���� �Ϳ�������
    // �������� ���ǿ� nxtVst ����ǰ  �ǲ��� ȫ�� ������ ʹ�û��� �� �� nxtVst�� Ȼ�� һ·ż���Σ� ֱ�� room+1
    // ��� nxtVst �� ż����      ��� nxtVst �� ��ǰ  �д��� ż����
    // ��� nxtVst ��ż���� ֻ�� ֱ�� nxtVst�� Ȼ�� �����Σ� Ȼ�� ���� nxtVst ��  û�а취�ġ�
    // ��� nxtVst �� ��ǰ �� ���� ż���� ��Ҳû�а취�� ���� ��  �ߵ� �Ǹ� ż����Ȼ�� ���� nxtVst������
    // ���� ������� ���� ���� nxtVst �ģ� ������ ���硣
    // ������ ������ ���� nxtVst�� ż����+1 ��
    // ���ǣ��⻹�� brute-force�� �����ܵ� 1e9 ..
    // 
    int lt1997a(vector<int>& nextVisit)
    {

    }

};

int main()
{

    LT1997 lt;


    return 0;
}
