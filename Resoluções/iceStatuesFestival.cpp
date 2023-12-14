#include <bits/stdc++.h>

using namespace std;

int min_blocks(int N, int M, vector<int>& blocks)
{
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = blocks[i]; j <= M; ++j)
        {
            dp[j] = min(dp[j], dp[j - blocks[i]] + 1);
        }
    }

 return dp[M];
}

int main()
{
    int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N, M; cin >> N >> M;

        vector<int> blocks(N);

        for (int i = 0; i < N; ++i) {
            cin >> blocks[i];
        }

        int result = min_blocks(N, M, blocks);
        cout << result << '\n';
    }

 return 0;
}
