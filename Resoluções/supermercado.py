import bisect
import sys

def menor_custo_lista(lista_sra_jones, produtos):
    M = len(lista_sra_jones)
    N = len(produtos)

    dp = [float('inf')] * (M + 1)
    dp[0] = 0

    for i in range(N):
        for j in range(M - 1, -1, -1):
            if produtos[i][0] == lista_sra_jones[j]:
                dp[j + 1] = min(dp[j] + produtos[i][1], dp[j + 1])

    return dp[M] if dp[M] != float('inf') else "Impossible"

def process_input():
    for line in sys.stdin:
        M, N = map(int, line.split())
        if M == 0 and N == 0:
            break

        lista_sra_jones = list(map(int, input().split()))
        produtos = []
        for _ in range(N):
            produto, preco = map(float, input().split())
            produtos.append((int(produto), preco))

        result = menor_custo_lista(lista_sra_jones, produtos)
        if isinstance(result, str):
            print(result)
        else:
            print("{:.2f}".format(result))

if __name__ == "__main__":
    process_input()
