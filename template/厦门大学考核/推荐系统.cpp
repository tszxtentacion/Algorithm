//
// Created by syz on 2023/6/3.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int M = 52, N = 30009; // M表示类别，N表示每类最多数量
int m, n;
map<int, map<int, int> > types;    //  map[i]表示第i类的所有商品向量
typedef pair<int, int> PII;

bool cmp(PII &p1, PII &p2) {
    return p1.second > p2.second;
}


int main() {
    cin >> m >> n;
    // 每一类商品的内容都一样，只有类别不同。。。
    // 初始化
    for (int i = 0; i < n; i++) {
        int tid, tscore;
        cin >> tid >> tscore;
        for (int j = 0; j < m; j++)
            types[j][tid] = tscore;
    }

    int T;
    cin >> T;
    while (T--) {
        int op;
        cin >> op;
        if (op == 1) {
            int type, id, score;
            cin >> type >> id >> score;
            types[type][id] = score;
        } else if (op == 2) {
            int type, id;
            cin >> type >> id;
            types[type].erase(id);
        } else if (op == 3) {
            int K;
            vector<int> ks;
            cin >> K;
            for (int i = 0; i < m; i++) {
                int t_ks;
                cin >> t_ks;
                ks.push_back(t_ks);
            }
            for (int i = 0; i < m; i++)     // 对每一类进行考虑
            {
                // map无法排序，先进行转换
                vector<PII> type_PIIs;
                map<int, int>::iterator iter;
                int tmp_cnt = 0;        // 记录当前类别商品有多少种
                for (iter = types[i].begin(); iter != types[i].end(); iter++) {
                    tmp_cnt++;
                    PII tmp_PII;
                    tmp_PII.first = iter->first, tmp_PII.second = iter->second;
                    type_PIIs.push_back(tmp_PII);
                }
                // 排序
                std::sort(type_PIIs.begin(), type_PIIs.end(),cmp);
                // 按要求输出
                int tmp_idx = 0;
                while (tmp_cnt-- && ks[i]-- && K--)
                    tmp_idx++;
                if (!tmp_idx)
                    cout << -1 << endl;
                else {
                    for (int ii = 0; ii < tmp_idx; ii++)
                        cout << type_PIIs[ii].first << " ";
                    cout << endl;
                }
            }
        }
    }
    return 0;
}