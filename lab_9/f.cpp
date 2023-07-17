#include <bits/stdc++.h>
#include <iostream>
#include <vector>
 
void computeLPSArray(char* pat, int M, int* lps);
 
// Prints occurrences of txt[] in pat[]
std::vector<int> KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int cnt = 0;
    std::vector<int> vect;
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            
            vect.push_back(i-j);
            j = lps[j - 1];
            cnt = cnt + 1;
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return vect;
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver code
int main()
{
    int length = 1e6;
    char txt[length];
    std::cin.getline(txt, length);

    char pat[length];
    std::cin.getline(pat, length);
    std::vector<int> answer = KMPSearch(pat, txt);
    std::cout << answer.size() << std::endl;
    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] + 1 << " ";
    }
    return 0;
}