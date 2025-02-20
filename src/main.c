#include <stdio.h>

// Function prototype (Прототип функции)
void greet(const char *name){
    printf("Hello %s! Привет %s!\n", name, name);
}

// Pointer Demonstration (Демонстрация указателя)
void pointerDemo(){
    int number = 10;
    int *numberPtr = &number;

    printf("The value stored in 'numberPtr' is %d (Значение)\n", *numberPtr);
    printf("The memory address stored in 'numberPtr' is %p (Адресс памяти: %p)\n",(void *)numberPtr, (void *)numberPtr);
}

int main(){
    const char *name = "Alex";
    greet(name); // Greeting function call (Вызов функции приветствия)
    pointerDemo(); // Testing pointer demo function (Тестирование использования указателей)
    return 0;
}
