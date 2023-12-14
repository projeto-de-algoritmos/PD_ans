#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    while (cin >> N)
    {
        int custo_dia; cin >> custo_dia;

        vector<int> receita(N);

        for (int i = 0; i < N; ++i) {
            cin >> receita[i];
        }

        // Vetor para armazenar o lucro máximo até cada dia
        vector<int> lucroMaximoAte(N, 0);

        // Inicialização do lucro máximo até o primeiro dia
        lucroMaximoAte[0] = max(0, receita[0] - custo_dia);
        int lucroMaximo = lucroMaximoAte[0];

        // Iteração pelos dias para calcular o lucro máximo até cada dia
        for (int i = 1; i < N; ++i)
        {
            // O lucro máximo até o dia i é o máximo entre 0 e o lucro até o dia i-1
            // somado ao lucro do dia i e subtraído do custo diário
            lucroMaximoAte[i] = max(0, lucroMaximoAte[i - 1] + receita[i] - custo_dia);

            // Atualiza o lucro máximo global
            lucroMaximo = max(lucroMaximo, lucroMaximoAte[i]);
        }

        // Imprime o lucro máximo
        cout << lucroMaximo << '\n';
    }

 return 0;
}
