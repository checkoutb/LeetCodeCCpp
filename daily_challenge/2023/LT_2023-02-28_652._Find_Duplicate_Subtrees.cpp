
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // 直接转 string。

    // 大道至简。
    


    // 如果 example 1 的 最右的值为4的节点 下面挂 2个 值为4 的节点。 那么 4 会重复。
    // 1. 移除 set2. 复杂度一下子就上去了
    // 2. 对 vn 进行去重。 代码量。 还需要再计算/获得 下 节点的子树节点数，sum 等。
    //
    // 这里通过 节点数，root值，sum 进行分类， 这3个相同的 节点 进行 重复校验。
    // 如果重复，那么 这个节点 即下面的所有 节点都是重复的， 那么 下面的节点 就不需要计算了。
    // 所以 节点数 倒序， 并且 vsttree 获得 subtree 的所有节点。

    // g
    vector<TreeNode*> lta(TreeNode* root)
    {
        map<int, map<int, map<int, vector<TreeNode*>>>>& map2;
        dfsa1(root, 0, map2);

        set<TreeNode*> set2;
        vector<TreeNode*> vn;
        bool b2 = false;
        for (map<int, map<int, map<int, vector<TreeNode*>>>>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
            for (map<int, map<int, vector<TreeNode*>>>::iterator it2 = begin(it->second); it2 != end(it->second); it2++)
            {
                for (map<int, vector<TreeNode*>>::iterator it3 = begin(it2->second); it3 != end(it2->second); it3++)
                {
                    for (int i = 0; i < it3->second.size(); ++i)
                    {
                        if (vst.find(it3->second[i]) != vst.end())
                            continue;
                        b2 = false;
                        for (int j = i + 1; j < it3->second.size(); ++j)
                        {
                            if (vst.find(it3->second[i]) != vst.end())
                                continue;

                            if (eqtree(it3->second[i], it3->second[j]))
                            {
                                vsttree(it3->second[j], set2);
                                b2 = true;
                            }
                        }
                        if (b2)
                        {
                            vsttree(it3->second[i], set2);
                            vn.push_back(set2);
                        }
                    }
                }
            }
        }




    }

    void vsttree(TreeNode* n, set<TreeNode*> set2)
    {
        if (n == nullptr)
            return;
        set2.insert(n);
        vsttree(n->left, set2);
        vsttree(n->right, set2);
    }

    bool eqtree(TreeNode* n1, TreeNode* n2)
    {
        if (n1 == nullptr || n2 == nullptr)
            return n1 == n2;

        if (n1->val != n2->val)
            return false;

        return eqtree(n1->left, n2->left) && eqtree(n1->right, n2->right);
    }

    // node.val , sum, count  ... (depth)
    // sum, count
    // count -> node.val -> sum.
    pair<int, int> dfsa1(TreeNode* node, int depth, map<int, map<int, map<int, vector<TreeNode*>>>>& map2)
    {
        if (node == nullptr)
            return std::make_pair(0, 0);

        pair<int, int> p2 = dfsa1(node->left, depth + 1, map2);
        pair<int, int> p3 = dfsa1(node->right, depth + 1, map2);
        pair<int, int> p4 = std::make_pair(p2.first + p3.first + node->val, p2.second + p3.second + 1);
        //map2[node->val][p4.first][p4.second].push_back(node);
        map2[p4.count][node->val][p4.first].push_back(node);
        return p4;
    }

};

int main()
{

    LT lt;


    return 0;
}
