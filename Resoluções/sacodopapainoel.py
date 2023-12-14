def knapsack_packages(packages):
    total_brinquedos = sum(qt for qt, _ in packages)
    capacidade_maxima = 50

    dp = [[0] * (capacidade_maxima + 1) for _ in range(len(packages) + 1)]

    for i in range(1, len(packages) + 1):
        for j in range(capacidade_maxima + 1):
            qt, peso = packages[i - 1]
            if peso <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - peso] + qt)
            else:
                dp[i][j] = dp[i - 1][j]

    peso_total = 0
    pacotes_usados = []
    i, j = len(packages), capacidade_maxima
    while i > 0 and j > 0:
        if dp[i][j] != dp[i - 1][j]:
            qt, peso = packages[i - 1]
            peso_total += peso
            pacotes_usados.append(peso)
            j -= peso
        i -= 1

    pacotes_sobrando = len(packages) - len(pacotes_usados)

    return dp[len(packages)][capacidade_maxima], peso_total, pacotes_sobrando

def process_input():
    num_viagens = int(input())

    for _ in range(num_viagens):
        num_pacotes = int(input())
        packages = []

        for _ in range(num_pacotes):
            qt, peso = map(int, input().split())
            packages.append((qt, peso))

        total, peso_total, pacotes_sobrando = knapsack_packages(packages)

        print(f"{total} brinquedos")
        print(f"Peso: {peso_total} kg")
        print(f"sobra(m) {pacotes_sobrando} pacote(s)\n")

if __name__ == "__main__":
    process_input()
