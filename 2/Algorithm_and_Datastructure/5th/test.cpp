#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(const vector<int>& A, int n, int m) {
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // 初期化
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // 動的計画法による部分和の計算
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, q;

    // 入力
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;

        // 判定と出力
        if (isSubsetSum(A, n, m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
