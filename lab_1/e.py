def drunkard(boris, nursik):
    moves = 0

    for _ in range(10**6):

        if len(boris) == 0 or len(nursik) == 0:
            break

        boris_card = boris.pop(0)
        nursik_card = nursik.pop(0)

        if (boris_card > nursik_card) and not (boris_card == 9 and nursik_card == 0):
            boris.extend([boris_card, nursik_card])
        elif boris_card == 9 and nursik_card == 0:
            nursik.extend([boris_card, nursik_card])
        
        if (boris_card < nursik_card) and not (boris_card == 0 and nursik_card == 9):
            nursik.extend([boris_card, nursik_card])
        elif boris_card == 0 and nursik_card == 9:
            boris.extend([boris_card, nursik_card])

        moves += 1

    if len(boris) > len(nursik):
        return "Boris", moves
    elif len(nursik) > len(boris):
        return "Nursik", moves
    else:
        return "blin nichya"

boris = list(map(int, input().split()))
nursik = list(map(int, input().split()))

winner, moves = drunkard(boris, nursik)
print(winner, moves)
