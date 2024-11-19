
#include "../header/myheader.h"

class LT3235
{
public:


    // D

    // 我想到的 solution中有提到， 主要就是 example4， 圆 无限靠近 右上的时候， x-r y-r 是小于 mxx，mxy的， 有4个顶点。 这种 矩形外的 圆 是不参与的。 不然 会 连通图 从外面走一圈 来连接 上侧边和 右侧边
    

    // 太繁了。

    // 1000 * 1000  应该不会tle吧。
    // 连通图，uf，计算每个连通图的最左/右/上/下 是否可以与 矩形边 相交/切
    // tag: 0000  左右上下 相交/切
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        // int x,y,r;
        std::vector<int> vtag;
        for (int i = 0; i < circles.size(); ++i) {
            // x = circles[i][0];
            // y = circles[]

            int& [x,y,r] = circles[i];
            
        }
    }

    // -1: out, 0: no touch, bbbb: touch
    int stateOfCircle(int x, int y, int r, int mxx, int mxy) {
        // if (x + r < 0 || y + r < 0 || x - r > mxx || y - r > mxy)
        //     return -1;

        int ans = 0;
        if (x >= 0 && x <= mxx) {
            
        }

        if (y >= 0 && y <= mxy) {
            
        }

        
    }

};

int main()
{

    LT3235 lt;


    return 0;
}
