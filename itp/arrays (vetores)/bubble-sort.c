#include <stdio.h>

void bubble_sort(int x){
    int array[x];
    int y, aux;
    
    for (int i = 0; i < x; i++){
        scanf("%d", &y);
        array[i] = y;
    }
    for (int i = 0; i < x; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < x-1; i++){
        for (int j = 0; j < x-i-1;j++){
            if (array[j] > array[j+1]){
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
        for (int k = 0; k < x; k++){
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}
int main(){
    int x;
    scanf("%d", &x);
    int array[x];

    bubble_sort(x);
    
    printf("\n");

    return 0;
}


