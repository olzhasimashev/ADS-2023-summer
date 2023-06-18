import bisect

def find_wins_and_powers(N, powers, P, marks):
    powers.sort()
    prefix_sums = [0]*(N+1)
    for i in range(1, N+1):
        prefix_sums[i] = prefix_sums[i-1] + powers[i-1]
    for p in marks:
        idx = bisect.bisect_right(powers, p)
        print(idx, prefix_sums[idx])

N = int(input().strip())
powers = list(map(int,input().strip().split()))
P = int(input().strip())
marks = [int(input().strip()) for _ in range(P)]
find_wins_and_powers(N, powers, P, marks)