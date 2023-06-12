def elite(n, votes):
    i = 0
    while 'S' in votes and 'K' in votes:
        if votes[i] == 'S':
            votes = votes.replace('K', '', 1)
        else:
            votes = votes.replace('S', '', 1)
        i += 1
        print(i)
        if votes[i] == votes[-1]:
            i = 0
        print(votes)
        
    if 'S' in votes:
        return "SAKAYANAGI"
    else:
        return "KATSURAGI"

n = int(input().strip())
votes = input().strip()

print(elite(n, votes))