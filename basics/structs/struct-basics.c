#include <stdio.h>
#include <stdlib.h> // malloc() 
#include <string.h> 

struct Car{
    char model[20];
    int year;
    double price;

};

// Create a struct for pointer example 
struct Car2{
    char* model;
    int year;
    double price;

};

// Create a struct for struct array example 
struct Student{
    char name[20];
    int grade;
};

int main(){
    struct Car car1 = {"LAMBO", 2026, 375000.95};

    printf("Car 1 Model: %s\n", car1.model);
    printf("Car 1 Year: %d\n", car1.year);
    printf("%s Price: $%.2lf\n\n", car1.model, car1.price);
    
    // Create struct using pointers 
    struct Car2 *car2Ptr = malloc(sizeof(struct Car2));

    // We need to allocate memory for the model array 
    car2Ptr->model = malloc(20);
    strcpy(car2Ptr->model, "LAND CRUISER");

    car2Ptr->year = 2024;
    car2Ptr->price = 350000.75;
    
    printf("Car 2 Model: %s\n", car2Ptr->model);
    printf("Car 2 Year: %d\n", car2Ptr->year);
    printf("%s Price: $%.2lf\n\n", car2Ptr->model, car2Ptr->price);
    
    // Always free!
    free(car2Ptr->model);
    free(car2Ptr);


    // Struct array 
    struct Student students[2];
    
    // Info for Student 1
    strcpy(students[0].name, "JOHN");
    students[0].grade = 85;
    
    // Info for Student 2
    strcpy(students[1].name, "ERIC");
    students[1].grade = 99;

    for(int i = 0; i < 2; i++){
        printf("Student Name: %s\n", students[i].name);
        printf("%s's Grade: %d\n\n", students[i].name, students[i].grade);
    }

    return 0;
}
