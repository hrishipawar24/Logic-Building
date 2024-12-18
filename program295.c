#include<stdio.h> // Include the standard input/output library for printf function
//Functions like malloc(), calloc(), realloc(), and free() are declared here for dynamic memory management.
#include<stdlib.h> // Include the standard library for general utility functions (not used in this program)

// Disable padding, ensuring the structure members are tightly packed
#pragma pack(1)

// Define a structure named 'node'
struct node
{
    int data; // An integer variable to store data
    struct node *next; // A pointer to another 'node' structure (used for linked lists)
};

int main() // Main function, the entry point of the program
{
    struct node obj; // Declare a variable 'obj' of type 'struct node'

    // Calculate and print the size of the 'obj' structure
    printf("Size of node is : %d", sizeof(obj)); 

    return 0; // Return 0 to indicate successful program execution
}
