#include <stdio.h>
#include <string.h>

int main() {
    int t, n;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        char s[101];
        scanf("%s", s);
        
        int len = strlen(s);
        
        char minChar = 'z' + 1; 
        int minPos = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] < minChar) {
                minChar = s[i];
                minPos = i;
            }
        }
        
        if (n == 2) {
            if (minPos > 0) {
                for (int i = len - 1; i >= 0; --i) {
                    putchar(s[i]);
                }
            }
            printf("%s", s);
        } else {
            printf("%s", s);
        }
        printf("\n");
    }
    
    return 0;
}