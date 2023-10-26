import matplotlib.pyplot as plt

def modified_fibonacci(n: int) -> tuple[int, int, int]:
    if n <= 1:
        return (1, 0, 1) # 1 comparison for if statement

    last = 1
    nextToLast = 1
    answer = 1

    comparisons = 1  # 1 comparison for if statement
    assignments = 3  # 3 assignments for initial values

    for i in range(2, n + 1):
        answer = last + nextToLast
        nextToLast = last
        last = answer
        
        comparisons += 1  # 1 comparison for loop condition
        assignments += 3  # 3 assignments for updating values

    return (answer, assignments, comparisons)

def plot_statistics():
    n_values = list(range(1, 41))
    assignment_counts = []
    comparison_counts = []

    for n in n_values:
        _, assignments, comparisons = modified_fibonacci(n)
        assignment_counts.append(assignments)
        comparison_counts.append(comparisons)

    plt.figure(figsize=(12, 6))
    plt.plot(n_values, assignment_counts, label='Count of assignments')
    plt.plot(n_values, comparison_counts, label='Count of comparisons')
    plt.xlabel('n-values')
    plt.ylabel('times')
    plt.legend()
    plt.title('Fibonacci algorithm\'s complexity statistics')
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    plot_statistics()
