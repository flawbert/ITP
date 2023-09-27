#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    if (n <= 0 || n > 30 || m <= 0 || m > 30) {
        return 1;
    }
    
    int A[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    char ch;
    int x;
    scanf(" %c", &ch);
    
    if (ch != 'l' && ch != 'c') {
        return 1;
    }
    scanf("%d", &x);
    int maiorElemento = (ch == 'l') ? A[x][0] : A[0][x];
    for (int i = 0; i < ((ch == 'l') ? m : n); i++) {
        int e = (ch == 'l') ? A[x][i] : A[i][x];
        if (e > maiorElemento) {
            maiorElemento = e;
        }
    }
    
    if (ch == 'l') {
        printf("%d\n", maiorElemento);
    } else {
        printf("%d\n", maiorElemento);
    }
    
    return 0;
}
