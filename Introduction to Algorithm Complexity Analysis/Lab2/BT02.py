
import random
import time
import matplotlib.pyplot as plt

def on_measure(func: callable) -> callable:
    def wrapper(s1: str, s2: str):
        start_time = time.time()
        func(s1, s2)
        elapsed_time = time.time() - start_time
        return elapsed_time
    return wrapper

@on_measure
def can_be_rearranged_idea1(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return False
    
    for char in s1:
        for i in range(len(s2)):
            if char == s2[i]:
                continue
            break
    
    return True

@on_measure
def can_be_rearranged_idea2(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return False
    
    char_count_s1 = [0] * 26
    char_count_s2 = [0] * 26
    
    for char in s1:
        char_count_s1[ord(char) - ord('A')] += 1
    
    for char in s2:
        char_count_s2[ord(char) - ord('A')] += 1
    
    return char_count_s1 == char_count_s2

@on_measure
def can_be_rearranged_idea3(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return False
    
    set_s2 = set()

    for char in s2:
        set_s2.add(char)  

    for char in s1:
        if char not in set_s2:
            return False
        
    return True

def random_string(n: int) -> str:
    return ''.join(random.choices('ABCDEFGHIJKLMNOPQRSTUVWXYZ', k=n))

def plot_statistics():
    n_values = [10 ** i for i in range(1, 6)] # 1e1, 1e2, 1e3, 1e4, 1e5
    avg_times_idea1 = []
    avg_times_idea2 = []
    avg_times_idea3 = []

    for n in n_values:
        times_idea1 = []
        times_idea2 = []
        times_idea3 = []

        for j in range(5): # for finding average time
            s1 = random_string(n)
            s2 = random_string(n)

            times_idea1.append(can_be_rearranged_idea1(s1, s2))
            times_idea2.append(can_be_rearranged_idea2(s1, s2))
            times_idea3.append(can_be_rearranged_idea3(s1, s2))

        avg_times_idea1.append(sum(times_idea1) / len(times_idea1))
        avg_times_idea2.append(sum(times_idea2) / len(times_idea2))
        avg_times_idea3.append(sum(times_idea3) / len(times_idea3))


    plt.figure(figsize=(12, 6))
    plt.plot(n_values, avg_times_idea1, label='Idea 1')
    plt.plot(n_values, avg_times_idea2, label='Idea 2')
    plt.plot(n_values, avg_times_idea3, label='Idea 3')
    plt.xlabel('length of string')
    plt.ylabel('average time (s)')
    plt.legend()
    plt.title('Can Be Rearranged algorithms\' complexity statistics')
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    plot_statistics()