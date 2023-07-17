def compute_lps_array(pattern):
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_search(pattern, text):
    m = len(pattern)
    n = len(text)
    lps = compute_lps_array(pattern)
    i = 0  # index for text
    j = 0  # index for pattern
    indices = []
    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        if j == m:
            indices.append(i - j + 1)  # store the index of occurrence
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return indices

# Input reading
s1 = input()
s2 = input()

# KMP Search
occurrences = kmp_search(s1, s2)

# Output
print(len(occurrences))
print(" ".join(str(index) for index in occurrences))