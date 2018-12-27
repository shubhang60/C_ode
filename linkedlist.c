#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct antinode //Creating a node.
{
    int data;
    struct antinode *next;
};
typedef struct antinode node;// Node datatype creation
node *start = NULL;
node *create_ll(node *);
node *display_ll(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *insert_b4(node *);
node *insert_aftr(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_aftr(node *);
node *delete_node(node *, int);
node *delete_ll(node *);
node *dublicate(node *);
node *sort_ll(node *);

int main()
{
    int option;
    do
    {
        printf("\n******Linked List Operations******");
        printf("\n1. Create a Linked list");
        printf("\n2. Display a linked list");
        printf("\n3. Insert a node at the beginning");
        printf("\n4. Insert a node at the end");
        printf("\n5. Insert a node before a data");
        printf("\n6. Insert a node after a data");
        printf("\n7. Delete a node in the beginning");
        printf("\n8. Delete a node in the end");
        printf("\n9. Delete a given node");
        printf("\n10. Delete nodes after a data");
        printf("\n11. Delete the linked list");
        printf("\n12. Sort the linked list");
        printf("\n13. Remove dublicate entries");
        printf("\n14. EXIT");
        printf("\nEnter your option no.");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            start = create_ll(start);
            break;
        case 2:
            start = display_ll(start);
            break;
        case 3:
            start = insert_beg(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 4:
            start = insert_end(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 5:
            start = insert_b4(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 6:
            start = insert_aftr(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 7:
            start = delete_beg(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 8:
            start = delete_end(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 9:
            int value;
            printf("\nEnter the value to be deleted");
            scanf("%d", &value);
            start = delete_node(start, value);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 10:
            start = delete_aftr(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 11:
            start = delete_ll(start);
            printf("List has been deleted\n");
            break;
        case 12:
            start = sort_ll(start);
            printf("Updated list is :\n");
            display_ll(start);
            break;
        case 13:
            start = dublicate(start);
            printf("Refined list is :\n");
            display_ll(start);
        default:
            printf("\nWrong Choice !!!");
            break;
        }
    } while (option != 13);
    return 0;
}

node *create_ll(node *first) //Creates linked list
{
    node *new_node, *var_node;
    int number;
    printf("\nEnter -1 to end ");
    printf("\nEnter the data");
    scanf("%d", &number);
    while (number != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        (*new_node).data = number;
        if (first == NULL)
        {
            (*new_node).next = NULL;
            first = new_node;
        }
        else
        {
            var_node = first;
            while ((*var_node).next != NULL)
            {
                var_node = (*var_node).next;
            }
            (*var_node).next = new_node;
            (*new_node).next = NULL;
        }
        printf("\nEnter the data ");
        scanf("%d", &number);
    }
    return (first);
}

node *display_ll(node *first) //Displays linked lists
{
    node *var_node;
    var_node = first;
    while (var_node != NULL)
    {
        printf("%d\n", (*var_node).data);
        var_node = (*var_node).next;
    }
    return (first);
}

node *insert_beg(node *first) //Insert a node at beginning
{
    node *new_node;
    int number;
    printf("\nEnter the data");
    scanf("%d", &number);
    new_node = (node *)malloc(sizeof(node));
    (*new_node).data = number;
    (*new_node).next = first;
    first = new_node;
    return (first);
}

node *insert_aftr(node *first) //Insert after a given node
{
    node *new_node, *prevar_node, *var_node;
    int number, value;
    printf("\nEnter the data");
    scanf("%d", &number);
    printf("\nEnter the value after which data to be inserted");
    scanf("%d", &value);
    new_node = (node *)malloc(sizeof(node));
    (*new_node).data = number;
    var_node = first;
    prevar_node = var_node;
    while ((*prevar_node).data != value)
    {
        prevar_node = var_node;
        var_node = (*var_node).next;
    }
    (*prevar_node).next = new_node;
    (*new_node).next = var_node;
    return (first);
}

node *insert_b4(node *first) //Insert before a given node
{
    node *new_node, *postvar_node, *var_node;
    int number, value;
    printf("\nEnter the data");
    scanf("%d", &number);
    printf("\nEnter the value before which data is to be inserted");
    scanf("%d", &value);
    new_node = (node *)malloc(sizeof(node));
    (*new_node).data = number;
    var_node = first;
    while ((*var_node).data != value)
    {
        postvar_node = var_node;
        var_node = (*var_node).next;
    }
    (*postvar_node).next = new_node;
    (*new_node).next = var_node;
    return (first);
}

node *insert_end(node *first) //Insert node at end
{
    node *new_node, *var_node;
    int number;
    printf("\nEnter the data");
    scanf("%d", &number);
    new_node = (node *)malloc(sizeof(node));
    (*new_node).data = number;
    var_node = first;
    while ((*var_node).next != NULL)
    {
        var_node = (*var_node).next;
    }
    (*var_node).next = new_node;
    (*new_node).next = NULL;

    return (first);
}

node *delete_beg(node *first) //Delete a node iat beginning
{
    node *var_node;
    var_node = first;
    first = (*first).next;
    free(var_node);
    return (first);
}

node *delete_end(node *first) //Delete a node at start
{
    node *var_node, *free_node;
    free_node = first;
    while ((*free_node).next != NULL)
    {
        var_node = free_node;
        free_node = (*free_node).next;
    }
    (*var_node).next = NULL;
    free(free_node);
    return (first);
}

node *delete_node(node *first, int value) //Delete a given node
{
    node *var_node, *free_node;

    free_node = first;
    if ((*free_node).data == value)
    {
        first = delete_beg(first);
        return (first);
    }
    else
    {
        while ((*free_node).data != value)
        {
            var_node = free_node;
            free_node = (*free_node).next;
        }
        (*var_node).next = (*free_node).next;
        free(free_node);
        return (first);
    }
}

node *delete_aftr(node *first) //Delete a node after a given node
{
    node *var_node, *free_node;
    int value;
    printf("\nEnter the value after which has to be deleted");
    scanf("%d", &value);
    free_node = first;
    while ((*free_node).data != value)
    {
        var_node = free_node;
        free_node = (*free_node).next;
    }
    (*var_node).next = NULL;
    return (first);
}

node *sort_ll(node *first) //Sort the linked list
{
    node *var_node1, *var_node2;
    int temp;
    var_node1 = first;
    while ((*var_node1).next != NULL)
    {
        var_node2 = (*var_node1).next;
        while ((*var_node2).next != NULL)
        {
            if ((*var_node1).data > (*var_node2).data)
            {
                temp = (*var_node1).data;
                (*var_node1).data = (*var_node2).data;
                (*var_node2).data = temp;
            }
            var_node2 = (*var_node2).next;
        }
        var_node1 = (*var_node1).next;
    }
    return (first);
}

node *delete_ll(node *first) //Delete the linked list
{
    node *var_node;
    if (first != NULL)
    {
        var_node = first;
        while (var_node != NULL)
        {
            printf("\nData to be deleted is %d .", (*var_node).data);
            first = delete_beg(var_node);
            var_node = first;
        }
    }
    return (first);
}

node *dublicate(node *first) //Remove the duplicates
{
    node *var_node, *free_node;
    int temp;
    var_node = first;
    while ((*var_node).next != NULL)
    {
        temp = (*var_node).data;
        free_node = first;
        while ((*free_node).next != NULL)
        {
            if (temp == (*free_node).data && (*var_node).next != (*free_node).next)
            {
                first = delete_node(first, temp);
            }
            free_node = (*free_node).next;
        }
        var_node = (*var_node).next;
    }
    return (first);
}