#include <stdio.h>
#include <stdbool.h>

bool ehPerfeito(int x) {
    if (x <= 1) {
        return false;
    }

    int somaDivisores = 1;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            somaDivisores += i;
            if (i != x / i) {
                somaDivisores += x / i;
            }
        }
    }

    return somaDivisores == x;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);
        
        if (ehPerfeito(X)) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }
    
    return 0;
}