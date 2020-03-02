import sys

def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * (n + 1) for _ in range(n + 1)]
    s = [[0] * (n + 1) for _ in range(n + 1)]

    for length in range(2, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return m[1][n], s

if __name__ == "__main__":
    dims = [10, 30, 5, 60]
    cost, s = matrix_chain_order(dims)
    assert cost == 4500
    print(f"Matrix chain optimal multiplications: {cost}")

// Updated: 2020-03-02 - feat(dp): matrix chain multiplication dynamic programming
