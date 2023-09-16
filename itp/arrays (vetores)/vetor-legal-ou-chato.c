#include <stdio.h>

void vetores(int x) {
    int array[x];
    int y;

    for (int i = 0; i < x; i++) {
        scanf("%d", &y);
        array[i] = y;
    }
    int par = 1;
    for (int i = 0; i < x - 1; i++) {
        if ((array[i] + array[i+1]) % 2 != 0) {
            par = 0;
            break;
        }
    }
    
    if (par) {
        printf("Legal\n");
    }
    else {
        printf("Chato\n");
    }
}

int main() {
    int x;
    scanf("%d", &x);

    vetores(x);

    return 0;
}
