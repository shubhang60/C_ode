#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct polynode //Creates the basic node or single term of the polynomial
{
    int coff;
    int expo;
    struct polynode *next;
};
typedef struct polynode node;
node *start[4] = {NULL, NULL, NULL, NULL};
node *create_poly(node *);
node *display_poly(node *);
node *add_poly(node *, node *, node *);
node *sub_poly(node *, node *, node *);
node *add_node(node *, int, int);
node *sort_ll(node *);
int main()
{
    int option;
    do
    {
        printf("\n####Polynomial Opeations####");
        printf("\n1. Enter polynomials");
        printf("\n2. Display polynomials");
        printf("\n3. Add two polynomial");
        printf("\n4. Substract two polynomial");
        printf("\n5. EXIT");
        printf("\nEnter your choice number");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter first polynomial");
            start[0] = create_poly(start[0]);
            printf("\nEnter second polynomial");
            start[1] = create_poly(start[1]);
            printf("\nPolynomial have been recorded");
            break;
        case 2:
            printf("\nFirst polynomial is :\n");
            start[0] = display_poly(start[0]);
            printf("\nThe second polynomial is :\n");
            start[1] = display_poly(start[1]);
            break;
        case 3:
            start[2] = add_poly(start[2], start[0], start[1]);
            printf("\nThe result is ");
            display_poly(start[2]);
            break;
        case 4:
            start[3] = sub_poly(start[3], start[0], start[1]);
            printf("\nThe result is ");
            display_poly(start[3]);
            break;
        }
    } while (option != 5);
    return 0;
}

node *create_poly(node *first) //Creates a new polynomial
{
    node *new_node, *var_node;
    int co, ex;
    printf("\nEnter 0 to end");
    printf("\nEnter the coefficient");
    scanf("%d", &co);
    printf("\nEnter its power");
    scanf("%d", &ex);
    while (co != 0)
    {
        new_node = (node *)malloc(sizeof(node));
        (*new_node).coff = co;
        (*new_node).expo = ex;
        (*new_node).next = NULL;
        if (first == NULL)
        {
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
        }
        printf("\nEnter the coefficient");
        scanf("%d", &co);
        if (co == 0)
        {
            break;
        }
        printf("\nEnter its power");
        scanf("%d", &ex);
    }
    first = sort_ll(first);
    return (first);
}

node *display_poly(node *first) //Displays the polynomial
{
    node *var_node;
    var_node = first;
    printf("%dx^%d", (*var_node).coff, (*var_node).expo);
    var_node = (*var_node).next; 
    while (var_node != NULL)
    {
        if ((*var_node).coff < 0)
        {
            printf("%dx^%d", (*var_node).coff, (*var_node).expo);
        }
        else
        {
            printf("+%dx^%d", (*var_node).coff, (*var_node).expo);
        }
        var_node = (*var_node).next;
    }
    first = sort_ll(first);
    return (first);
}

node *add_poly(node *result, node *first, node *second) //Adds the polynomial
{
    node *var_node1, *var_node2;
    int sum;
    var_node1 = first;
    var_node2 = second;
    while (var_node1 != NULL && var_node2 != NULL)
    {
        if ((*var_node1).expo == (*var_node2).expo)
        {
            sum = (*var_node1).coff + (*var_node2).coff;
            result = add_node(result, sum, (*var_node1).expo);
            var_node1 = (*var_node1).next;
            var_node2 = (*var_node2).next;
        }
        else if ((*var_node1).expo > (*var_node2).expo)
        {
            result = add_node(result, (*var_node1).coff, (*var_node1).expo);
            var_node1 = (*var_node1).next;
        }
        else if ((*var_node1).expo < (*var_node2).expo)
        {
            result = add_node(result, (*var_node2).coff, (*var_node2).expo);
            var_node2 = (*var_node2).next;
        }
    }
    if (var_node1 == NULL)
    {
        while (var_node2 != NULL)
        {
            result = add_node(result, (*var_node2).coff, (*var_node2).expo);
            var_node2 = (*var_node2).next;
        }
    }
    if (var_node2 == NULL)
    {
        while (var_node1 != NULL)
        {
            result = add_node(result, (*var_node1).coff, (*var_node1).expo);
            var_node1 = (*var_node1).next;
        }
    }
    return (result);
}

node *sub_poly(node *result, node *first, node *second) //Substract the polynomial
{
    node *var_node1, *var_node2;
    int diff;
    var_node1 = first;
    var_node2 = second;
    while (var_node1 != NULL && var_node2 != NULL)
    {
        if ((*var_node1).expo == (*var_node2).expo)
        {
            diff = (*var_node1).coff - (*var_node2).coff;
            result = add_node(result, diff, (*var_node1).expo);
            var_node1 = (*var_node1).next;
            var_node2 = (*var_node2).next;
        }
        else if ((*var_node1).expo > (*var_node2).expo)
        {
            result = add_node(result, (*var_node1).coff, (*var_node1).expo);
            var_node1 = (*var_node1).next;
        }
        else if ((*var_node1).expo < (*var_node2).expo)
        {
            result = add_node(result, (*var_node2).coff, (*var_node2).expo);
            var_node2 = (*var_node2).next;
        }
    }
    if (var_node1 == NULL)
    {
        while (var_node2 != NULL)
        {
            result = add_node(result, 0 - (*var_node2).coff, (*var_node2).expo);
            var_node2 = (*var_node2).next;
        }
    }
    if (var_node2 == NULL)
    {
        while (var_node1 != NULL)
        {
            result = add_node(result, (*var_node1).coff, (*var_node1).expo);
            var_node1 = (*var_node1).next;
        }
    }
    return (result);
}

node *add_node(node *first, int co, int ex) //Add new term to polynomial
{
    node *var_node, *new_node;
    new_node = (node *)malloc(sizeof(node));
    (*new_node).coff = co;
    (*new_node).expo = ex;
    (*new_node).next = NULL;
    if (first == NULL)
    {
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
    }
    return (first);
}
node *sort_ll(node *first) // Sort the terms according to exponent order
{
    node *var_node1, *var_node2, *temp_node;
    int temp_co, temp_ex;
    var_node1 = first;
    while (var_node1 != NULL)
    {
        var_node2 = (*var_node1).next;
        while (var_node2 != NULL)
        {
            if ((*var_node1).expo < (*var_node2).expo)
            {
                temp_co = (*var_node1).coff;
                temp_ex = (*var_node1).expo;
                (*var_node1).coff = (*var_node2).coff;
                (*var_node1).expo = (*var_node2).expo;
                (*var_node2).coff = temp_co;
                (*var_node2).expo = temp_ex;
            }
            var_node2 = (*var_node2).next;
        }
        var_node1 = (*var_node1).next;
    }
    return (first);
}