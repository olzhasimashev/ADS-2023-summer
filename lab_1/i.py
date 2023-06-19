def find_leader(n, votes):
    temp_list = list(votes)
    
    while len(set(temp_list)) > 1:
        i = 0
        while i < len(temp_list):
            if temp_list[i] == 'S':
                if 'K' in temp_list[i+1:]:
                    temp_list = temp_list[:i+1 + temp_list[i+1:].index('K')] + temp_list[i+2 + temp_list[i+1:].index('K'):]
                elif 'K' in temp_list:
                    temp_list = temp_list[:temp_list.index('K')] + temp_list[temp_list.index('K')+1:]
            elif temp_list[i] == 'K':
                if 'S' in temp_list[i+1:]:
                    temp_list = temp_list[:i+1 + temp_list[i+1:].index('S')] + temp_list[i+2 + temp_list[i+1:].index('S'):]
                elif 'S' in temp_list:
                    temp_list = temp_list[:temp_list.index('S')] + temp_list[temp_list.index('S')+1:]
            i += 1

    if temp_list[0] == 'S':
        return "SAKAYANAGI"
    else:
        return "KATSURAGI"

n = int(input().strip())
votes = input().strip()

print(find_leader(n, votes))