/*
Write C/C++ program to implement KMP string matching
method to find the pattern string in a text string both given by the
user. Compute the complexity of the method for a text string of
length N and pattern string of length M, where N>M.
*/

include <stdio.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 1000

static int complexity = 0;

int pi[MAX_M];

void build_pi_table(char *pattern, int m) {
    int j = 0;
    pi[0] = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = pi[j-1];
            complexity++;
        }
        if (pattern[j] == pattern[i]) {
            j++;
            complexity+=2;
        }
        pi[i] = j;
        complexity++;
    }
    complexity++;
}

void kmp(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    build_pi_table(pattern, m);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != text[i]) {
            j = pi[j-1];
            complexity++;
        }
        if (pattern[j] == text[i]) {
            j++;
            complexity+=2;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - m + 1);
            j = pi[j-1];
            complexity+=2;
        }
        complexity++;
    }
    complexity++;
}

int main() {
    char text[MAX_N], pattern[MAX_M];
    printf("Enter the text string: ");
    fgets(text, MAX_N, stdin);
    printf("Enter the pattern string: ");
    fgets(pattern, MAX_M, stdin);
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';
    kmp(text, pattern);
    printf("Time Complexity: %d", complexity);
    return 0;
}
