#include <stdio.h> 

// This illustrates the basic concept of pointer arithmetic. 

int main(){
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int *numbersPtr = numbers;

    for (int i = 0; i < 6; i++){
        printf("Address: %p, Value: %d\n", numbersPtr + i, *(numbersPtr + i));
    }


    // A pointer to an array behaves similarly to an array name
    printf("%d, %d\n", numbers[0], *numbersPtr); // Both give 10
    printf("%d, %d\n", numbers[1], *(numbersPtr + 1)); // Both give 20

    return 0;
}
