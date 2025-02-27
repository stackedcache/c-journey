#include <stdio.h>

//  это функция складывает два числа
int add(int a, int b){
    int sum = (a+b);
    return sum;
}

// это функция выводит сообщение 
void greet(){
    printf("HELLO REPO! как дело?\n");
}


int main(){
    int sum = add(2,2);
    printf("Two plus two is: %d\n\n", sum);
    greet();
    return 0;
}
