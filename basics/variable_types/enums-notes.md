# ENUMS 

- Enums or Enumerations are user defined data types that assign meaningful names to integer values.
- This improves readability, maintainability, and debugging. 
- Enums are good for defining fixed sets (flags, states, types)

## SYNTAX 

```C
typedef enum {
    VALUE_1, // Defaults to 0
    VALUE_2, // 1. . .
    VALUE_3
} ExampleEnum;

// Define Rank Enum
typedef enum {
    PRIVATE, // 0
    CORPORAL, // 1 . . .
    SERGEANT,
    LIEUTENANT
} Rank;

// Define Weapon Enum
typedef enum{
    AK12,
    AK47,
    AK74,
    PKM
} WeaponType;
```

**USING ENUMS IN STRUCTS FOR EXAMPLE:**

```C
int main(){

    // Map Enums to Strings for printing
    char *rank_names[] = {"Private", "Corporal", "Sergeant", "Lieutenant"};
    char *weapon_type[] = {"AK-12", "AK-47", "AK-74", "PKM"};

    
    // Assign rank to each soldier 
        for(int i = 0; i < 5; i++){
            soldier[i].rank = PRIVATE;
            soldier[i].weapon = AK12;
            soldier[i].ammo = 100;
            soldier[i].health = 100;
        }
        
        for(int i = 0; i < 5; i++){
            printf("Soldier Name: %s\n", soldier[i].name);
            printf("Soldier Rank: %s\n", rank_names[soldier[i].rank]);
            printf("Soldier Weapon: %s\n", weapon_type[soldier[i].weapon]);
```

- Enums are not only used in stucts. Use them wherever they make sense!
