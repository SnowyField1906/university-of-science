import numpy as np

def innerproduct(v1, v2):
    if len(v1) != len(v2):
        return None
    
    dot_product = 0
    for i in range(len(v1)):
        dot_product += v1[i] * v2[i]
    
    return dot_product


def QR_factorization(A):
    m, n = len(A), len(A[0])

    Q = [[0] * m for _ in range(n)]
    R = [[0] * n for _ in range(n)]
    
    for j in range(n):
        v = [A[i][j] for i in range(m)]
        
        for i in range(j):
            R[i][j] = innerproduct(Q[i], v)
            v = [v[k] - R[i][j] * Q[i][k] for k in range(m)]
        
        R[j][j] = innerproduct(v, v) ** 0.5

        if R[j][j] == 0:
            return "Matrix is not full rank"
        
        for k in range(m):
            Q[j][k] = v[k] / R[j][j]
    
    return Q, R


def print_matrix(A):
    for row in A:
        for elem in row:
            if isinstance(elem, float):
                if elem.is_integer():
                    print(f"{int(elem):>13d}", end="")
                else:
                    print(f"{elem:>13g}", end="")
            else:
                print(f"{elem:>13}", end="")
        print()

def main():
    A = np.loadtxt('input.txt', delimiter=' ', dtype=str)

    print("\nMatrix:")
    print_matrix(A)

    A = [[float(j) for j in i] for i in A]

    factorization = QR_factorization(A)
    if type(factorization) == str:
        print(factorization)
        return
    
    Q, R = factorization
    print("Q:")
    print_matrix(Q)
    print("R:")
    print_matrix(R)

if __name__ == '__main__':
    main()