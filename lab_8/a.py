def hash_function(s):
    MOD = 10**9 + 7
    hash_val = 0
    for i in range(len(s)):
        hash_val = (hash_val + ((ord(s[i]) - 47) * pow(11, i, MOD)) % MOD) % MOD
    return str(hash_val)

def find_pairs(data):
    computed_hashes = {}
    possible_hashes = set(data)
    results = []
    for item in data:
        if item.isdigit():
            hash_val = hash_function(item)
            computed_hashes[hash_val] = item
            if hash_val in possible_hashes and (item, hash_val) not in results:
                results.append((item, hash_val))
    return results

N = int(input().strip())
data = [input().strip() for _ in range(2*N)]
pairs = find_pairs(data)

for string, hash_val in pairs:
    print(f'Hash of string "{string}" is {hash_val}')