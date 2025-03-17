#include <stdio.h>
#include <stdlib.h> 

// CHALLENGE 4
// Pointer to a Struct 
/*
    - Dynamically allocate memory for a single Soldier struct using pointers (malloc). 
    - Initialize the struct's fields through pointer notation. 
    - Print values, then free the memory.
*/
typedef enum{
    PRIVATE,
    CORPORAL
} Rank;

typedef enum{
    AK12,
    AK47
} Weapon;

struct Soldier{
    char name[20];
    Rank rank;
    Weapon weapon;
    unsigned int ammo;
    unsigned int health;
};

int main(){
    // Create arrays to print and assign enums 
    char *weapons[] = {"AK-12", "AK-47"};
    char *ranks[] = {"Private", "Corporal"};

    struct Soldier *soldier1 = malloc(sizeof(struct Soldier)); // Allocate memory for one struct 

    soldier1->ammo = 250;
    soldier1->health = 100;
    
    // Give soldier a name with snprintf
    snprintf(soldier1->name, sizeof(soldier1->name), "%s", "Alex");

    // Assign rank and weapon
    soldier1->rank = PRIVATE;
    soldier1->weapon = AK12;

    // Print Output
    printf(
        "Soldier Name: %s\n"
        "Soldier Rank: %s\n"
        "Soldier Weapon: %s\n"
        "Soldier Ammo: %d\n"
        "Soldier Health: %d\n\n",
        soldier1->name, ranks[soldier1->rank], weapons[soldier1->weapon], soldier1->ammo, soldier1->health
    );
    
    // Free Memory 
    free(soldier1);
    return 0;  
}
