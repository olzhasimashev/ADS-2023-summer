import heapq

def min_cost(n, ducks):
    # Convert list to a heap
    heapq.heapify(ducks)
    total_cost = 0
    while len(ducks) > 1:
        # Pop the smallest element
        a = heapq.heappop(ducks)
        # Add it to the total cost
        total_cost += a
        # Add it to the next smallest element
        b = ducks[0] + a
        # Replace the next smallest element with the new sum
        heapq.heapreplace(ducks, b)
    return total_cost

# Test the function
print(min_cost(5, [2, 5, 4, 2, 8]))  # Output: 27
print(min_cost(5, [5, 5, 5, 5, 5]))  # Output: 40