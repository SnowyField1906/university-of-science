EMPTY: set = {True}

class Clause:
    def __init__(self, c: str | set):
        if c == EMPTY:
            self.literals = c
            return

        if isinstance(c, str):
            c = set(c.replace(' ', '').replace('\n', '').split('OR'))
        
        literals = sorted(list(c), key=lambda x: x[-1])

        for literal in range(0, len(literals) - 1):
            if literals[literal][-1] == literals[literal + 1][-1]:
                literals = EMPTY
                break

        self.literals = set(literals)

    def __str__(self) -> str:
        return '{}' if self.is_empty() else ' OR '.join(self.literals)

    def __eq__(self, other: 'Clause') -> bool:
        return set(self.literals) == set(other.literals)

    def __hash__(self) -> int:
        return hash(frozenset(self.literals))
    
    def __len__(self) -> int:
        return len(self.literals)
    
    def __iter__(self) -> iter:
        return iter(self.literals)

    def find_complementary_pairs(self, c2: 'Clause') -> list[str]:
        pairs = []

        for l1 in self.literals:
            if len(l1) == 1:
                if '-' + l1 in c2.literals:
                    pairs.append(l1[-1])
            elif '-' + l1 in c2.literals:
                pairs.append(l1[-1])

        return pairs

    def resolve(self, c2: 'Clause') -> 'Clause':
        complementary_pairs = self.find_complementary_pairs(c2)
        res = EMPTY

        if len(complementary_pairs) == 1:
            res = sorted(list(set(self.literals) | set(c2.literals)), key=lambda x: x[-1])
            res.remove('-' + complementary_pairs[0])
            res.remove(complementary_pairs[0])

        if len(res) == 0:
            return None

        return Clause(res)
    
    def is_empty(self) -> bool:
        return self.literals == EMPTY


class KnowledgeBase:
    def __init__(self, alpha: str, kb: list[str]):
        self.alpha: Clause = Clause(alpha)
        self.clauses: set[Clause] = set(Clause(c) for c in kb)

        for literal in self.alpha:
            if literal[0] == '-':
                minus_alpha = literal[-1]
            else:
                minus_alpha = '-' + literal

            self.clauses.add(Clause(minus_alpha))

    
    def recursive_resolution(self, generated_clauses: list[Clause] = []) -> tuple[bool, list[Clause]]:
        clauses_after = set()

        for clause1 in self.clauses:
            for clause2 in self.clauses:
                solution = clause1.resolve(clause2)

                if solution is None:
                    generated_clauses.append(clauses_after - self.clauses | {Clause(EMPTY)})
                    return True, generated_clauses
                elif solution.is_empty():
                    continue
                else:
                    clauses_after.add(solution)

        generated_clauses.append(clauses_after - self.clauses)

        if clauses_after.issubset(self.clauses):
            return False, generated_clauses

        self.clauses = self.clauses | clauses_after

        return self.recursive_resolution(generated_clauses)
        

    def pl_resolution(self) -> tuple[bool, list[Clause]]:
        if self.alpha.is_empty():
            return True, []
        
        return self.recursive_resolution()

def main():
    for i in range(1, 6):
        with open(f'input/{i}.txt', 'r') as infile:
            alpha = infile.readline().strip()
            n = int(infile.readline().strip())
            kb = [infile.readline().strip() for _ in range(n)]

        knowledge_base = KnowledgeBase(alpha, kb)
        entails, generated_clauses = knowledge_base.pl_resolution()

        with open(f'output/{i}.txt', 'w') as outfile:
            for clause in generated_clauses:
                outfile.write(f'{len(clause)}\n')

                for c in clause:
                    outfile.write(str(c) + '\n')
    
            outfile.write('YES' if entails else 'NO')

if __name__ == '__main__':
    main()
