#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    while (cin >> N)
    {
        int custo_dia; cin >> custo_dia;

        vector<int> revenue(N);

        for (int i = 0; i < N; ++i) {
            cin >> revenue[i];
        }

        int maxProfit = 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = i; j < N; ++j)
            {
                int profit = 0;
                
                for (int k = i; k <= j; ++k) {
                    profit += revenue[k];
                }

                profit -= (j - i + 1) * custo_dia;
                maxProfit = max(maxProfit, profit);
            }
        }

        cout << maxProfit << endl;
    }

 return 0;
}
