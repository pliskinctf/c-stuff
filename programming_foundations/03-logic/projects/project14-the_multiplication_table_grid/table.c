#include <stdio.h>

int main() {
    int size;
    printf("enter a integer: ");
    scanf("%d", &size);
    
    for (int row = 1; row <=size; row++) {

        for (int col = 1; col <=size; col++){
            printf("%d\t", row * col);
        }

        printf("\n");

    }

    return 0;
}