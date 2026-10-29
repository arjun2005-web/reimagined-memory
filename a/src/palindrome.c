#include <stdio.h>
#include <ctype.h>

int main(void) {
    char input[256], clean[256];
    int n = 0;

    printf("Enter text: ");
    if (!fgets(input, sizeof input, stdin)) return 1;

    for (int i = 0; input[i]; i++) {
        if (isalnum((unsigned char)input[i])) {
            clean[n++] = (char)tolower((unsigned char)input[i]);
        }
    }
    clean[n] = '\0';

    int ok = 1;
    for (int i = 0; i < n / 2; i++) {
        if (clean[i] != clean[n - 1 - i]) {
            ok = 0;
            break;
        }
    }
    printf("%s\n", ok ? "Palindrome" : "Not a palindrome");
    return 0;
}
