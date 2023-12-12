#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

vector<int> bellmanFord(vector<vector<Aresta>>& arestas, int numVertices, int origem) {
    int valorMaximo = INT_MAX;
    vector<int> distancias(numVertices, valorMaximo);
    distancias[origem - 1] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (auto& arestaLista : arestas) {
            for (auto& aresta : arestaLista) {
                int u = aresta.origem;
                int v = aresta.destino;
                int w = aresta.peso;
                if (distancias[u - 1] != valorMaximo && distancias[u - 1] + w < distancias[v - 1]) {
                    distancias[v - 1] = distancias[u - 1] + w;
                }
            }
        }
    }

    return distancias;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Aresta>> arestas(N);

    for (int i = 0; i < M; ++i) {
        int Ui, Vi, Pi;
        cin >> Ui >> Vi >> Pi;
        Aresta arestaUV = {Ui, Vi, Pi};
        Aresta arestaVU = {Vi, Ui, Pi};
        arestas[Ui - 1].push_back(arestaUV);
        arestas[Vi - 1].push_back(arestaVU);
    }

    int S;
    cin >> S;

    vector<int> menoresCaminhos = bellmanFord(arestas, N, S);

    int pingMaximo = 0;
    int pingMinimo = INT_MAX;

    for (int i = 0; i < N; ++i) {
        if (i != S - 1) {
            pingMaximo = max(pingMaximo, menoresCaminhos[i]);
            pingMinimo = min(pingMinimo, menoresCaminhos[i]);
        }
    }

    int diferencaPing = pingMaximo - pingMinimo;

    cout << diferencaPing << endl;

    return 0;
}
