from bisect import bisect_right, bisect_left

def solve(n, q, a, queries):
    a.sort()
    for query in queries:
        l1, r1, l2, r2 = query
        count1 = bisect_right(a, r1) - bisect_left(a, l1)
        count2 = bisect_right(a, r2) - bisect_left(a, l2)
        intersection_left = max(l1, l2)
        intersection_right = min(r1, r2)
        count_intersection = 0
        if intersection_right >= intersection_left:
            count_intersection = bisect_right(a, intersection_right) - bisect_left(a, intersection_left)
        print(count1 + count2 - count_intersection)

n, q = map(int, input().split())
a = list(map(int, input().split()))
queries = [list(map(int, input().split())) for _ in range(q)]
solve(n, q, a, queries)