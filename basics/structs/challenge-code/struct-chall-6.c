#include <stdio.h>
#include <stdlib.h>

// CHALLENGE 6 - NESTED STRUCT
/*
    - Define a struct called FileMeta that contains nested structs for: 
        - Permissions (read/write/execute flags 
        - Created and modified timestamps 
        - File size 
    - Initialize an instance with realistic values and print
*/

struct FilePermissions{
    unsigned int owner_read : 3;
    unsigned int owner_write : 3;
    unsigned int owner_exec : 3;
    
    unsigned int group_read : 3;
    unsigned int group_write : 3;
    unsigned int group_exec : 3;
    
    unsigned int other_read : 3;
    unsigned int other_write : 3;
    unsigned int other_exec : 3;
};

struct Timestamp{
    int year, month, day, hour, minute, second;
};


struct FileMeta{
    char filename[50];
    struct Timestamp created_at, modified_at, accessed_at;
    struct FilePermissions permissions;
};

int main(){
    // Initialize struct 
    struct FileMeta *file1 = malloc(sizeof(struct FileMeta));
    
    // Give File a name 
    snprintf(file1->filename, sizeof(file1->filename), "%s", "myFile.exe");
    
    // Give the file timestamps 
    file1->created_at.year = 2025;
    file1->created_at.month = 3;
    file1->created_at.day = 17;
    
    file1->accessed_at.hour = 23;
    file1->accessed_at.minute = 45;
    file1->accessed_at.second = 0;
    
    // Give the file permissions 
    file1->permissions.owner_read = 4;
    file1->permissions.owner_write = 2;
    file1->permissions.owner_exec = 1;
    
    file1->permissions.group_read = 4;
    file1->permissions.group_write = 2;
    file1->permissions.group_exec = 1;
    
    file1->permissions.other_read = 4;
    file1->permissions.other_write = 0;
    file1->permissions.other_exec = 0;

    // Print 
    printf("Name: %s, Created At: %d/%d/%d, Permissions UGO: %d/%d/%d\n", 
        file1->filename, file1->created_at.year, file1->created_at.month, file1->created_at.day,
        (file1->permissions.owner_read + file1->permissions.owner_write + file1->permissions.owner_exec),
        (file1->permissions.group_read + file1->permissions.group_write + file1->permissions.group_exec),
        (file1->permissions.other_read + file1->permissions.other_write + file1->permissions.other_exec)
    );

    free(file1); // Always Free Memory! 
    return 0;
}  
