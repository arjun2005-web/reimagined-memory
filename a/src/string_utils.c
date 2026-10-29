#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *s) {
    int len = (int)strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int count_vowels(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char c = (char)tolower((unsigned char)s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    return count;
}

int main(void) {
    char text[256];

    printf("Enter a string: ");
    if (!fgets(text, sizeof text, stdin)) return 1;
    text[strcspn(text, "\n")] = '\0';

    printf("Length: %zu\n", strlen(text));
    printf("Vowels: %d\n", count_vowels(text));

    reverse(text);
    printf("Reversed: %s\n", text);
    return 0;
}
