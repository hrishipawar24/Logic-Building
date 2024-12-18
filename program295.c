#include<stdio.h>
#include<stdlib.h>

#pragma pack(1) // This directive disables padding in the structure
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node obj;

    printf("Size of node is : %d",sizeof(obj));

    return 0;
}
