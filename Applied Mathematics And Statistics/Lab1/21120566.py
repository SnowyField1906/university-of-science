import numpy as np

def gauss_elimination(A):
    for i in range(len(A)):
        pivot_row = i
        while pivot_row < len(A) and A[pivot_row][i] == 0:
            pivot_row += 1
        if pivot_row == len(A):
            continue
        (A[i], A[pivot_row]) = (A[pivot_row], A[i])
        for j in range(i+1, len(A)):
            factor = A[j][i] / A[i][i]
            for k in range(i+1, len(A[0])):
                A[j][k] -= factor * A[i][k]
            A[j][i] = 0
    return A

def back_substitution(A):
    n = len(A)
    x = [0] * n

    if A[n-1][n-1] == 0 and A[n-1][n] != 0:
        return "The system has no unique solution"
    elif A[n-1][n-1] == 0 and A[n-1][n] == 0:
        return "The system has infinite solutions"

    x[n-1] = A[n-1][n] / A[n-1][n-1]

    for i in range(n-2, -1, -1):
        sum = 0
        for j in range(i+1, n):
            sum += A[i][j] * x[j]
        x[i] = (A[i][n] - sum) / A[i][i]

    return x

def print_matrix(A):
    for row in A:
        for elem in row:
            if isinstance(elem, float):
                if elem.is_integer():
                    print(f"{int(elem):>6d}", end="")
                else:
                    print(f"{elem:>6g}", end="")
            else:
                print(f"{elem:>6}", end="")
        print()

def main():
    A = np.loadtxt('input.txt', delimiter=' ', dtype=str)

    print("\nMatrix:")
    print_matrix(A)

    A = [[float(j) for j in i] for i in A]
    print("\nGauss elimination:")
    print_matrix(gauss_elimination(A))
    print("\nBack substitution:", back_substitution(A))

if __name__ == '__main__':
    main()