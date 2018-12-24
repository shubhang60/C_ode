#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int length = 0;
int revstr(char *);
int substring(char *);
int pattern(char *, int *);
int delpattern(char *, int);
int repattern(char *, int);
int inpattern(char *);
int palindrome(char *);
int main()
{
    printf("Enter a string.\n");
    char str[50];
    fgets(str, 50, stdin);
    int choice, pos;
    do
    {

        printf("**What you want to do with your string**\n");
        printf("1. Reverse the string.\n");
        printf("2. Extract a substring.\n");
        printf("3. Find a pattern.\n");
        printf("4. Replace a pattern.\n");
        printf("5. Delete a pattern.\n");
        printf("6. Insert a pattern.\n");
        printf("7. Check if string in palindrome.\n");
        printf("8. EXIT\n");
        printf("Enter your choice number.");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            revstr(str);
            break;

        case 2:
            substring(str);
            break;

        case 3:
            pos = pattern(str, &length);
            if (pos != 0)
            {
                printf("The postion of pattern match is %d.\n", pos);
            }
            else
            {
                printf("The given pattern is not found in the string.");
            }
            break;
        case 4:
            repattern(str, length);
            break;

        case 5:
            delpattern(str, length);
            break;

        case 6:
            inpattern(str);
            break;

        case 7:
            palindrome(str);
            break;

        default:
            printf("Wrong Choice !!!\n");
            break;
        }
    } while (choice != 8);

    return 0;
}

int revstr(char str[50]) //Reverses a string 
{
    length = strlen(str);
    int i;
    char revstr[length];
    for (i = 0; i < length; i++)
    {
        revstr[i] = str[length - i - 1];
    }
    printf("Reversed string is :\n");
    puts(revstr);
    return 0;
}

int substring(char str[50]) //Extracts a substring
{
    int pos;
    printf("Enter the postion of substring to start with.\n");
    scanf("%d", &pos);
    printf("Enter the length of the substring.\n");
    scanf("%d", &length);
    char substr[length];
    int j = 0;
    while (str[pos] != '\0' && length > 0)
    {
        substr[j] = str[pos];
        pos++;
        length--;
        j++;
    }
    printf("%s\n", substr);
    return 0;
}

int pattern(char str[50], int *length) //Finds the position of a pattern
{
    char patstr[20];
    printf("Enter pattern.\n");
    scanf("%s", patstr);
    int check, stle = strlen(str), pale = strlen(patstr), pos = 0, i = 0, j = 0;
    *length = pale;
    check = stle - pale + 1;
    while (j < pale && i != check)
    {
        if (str[i] == patstr[j])
        {
            i++;
            j++;
            pos++;
            check++;
        }
        else
        {
            i++;
            pos = 0;
            j = 0;
        }
    }
    if (pos == pale)
    {
        return (i - pos + 1);
    }
    else
    {
        return 0;
    }
}

int repattern(char str[50], int length) //Replace a given pattern
{
    int pos;
    pos = pattern(str, &length);
    if (pos != 0)
    {
        char repat[length];
        printf("Enter the pattern to replace.\n");
        scanf("%s", repat);
        int j = 0;
        while (j < length)
        {
            str[pos - 1] = repat[j];
            pos++;
            j++;
        }
        printf("The new string is : \n");
        puts(str);
    }
    else
    {
        printf("Given pattern not found in the string.\n");
    }
    return 0;
}

int delpattern(char str[50], int length) //Deletes a given pattern
{
    int pos, k = 0;
    char newstr[50];
    pos = pattern(str, &length);
    if (pos != 0)
    {
        while (str[k] != '\0')
        {
            if (k < pos - 1)
            {
                newstr[k] = str[k];
                k++;
            }
            else
            {
                newstr[k] = str[k + length];
                k++;
            }
        }
        printf("The new string is :\n");
        puts(newstr);
    }
    else
    {
        printf("The given pattern is not found in the given string.\n");
    }
    return 0;
}

int inpattern(char str[50]) //Insert a new pattern
{
    int pos;
    printf("Enter the position to insert a pattern.\n");
    scanf("%d", &pos);
    char patstr[10];
    printf("Enter a pattern to insert.\n");
    scanf("%s", patstr);
    length = strlen(patstr);
    char newstr[50 + length];
    int i = 0, j = 0, k = 0;
    while (str[k] != '\0')
    {
        if (pos - 1 == i)
        {
            while (j != length)
            {
                newstr[i] = patstr[j];
                j++;
                i++;
            }
        }
        else
        {
            newstr[i] = str[k];
            i++;
            k++;
        }
    }
    printf("The new string is :\n");
    puts(newstr);
    return 0;
}

int palindrome(char str[50]) //Checks Palindrome
{
    int i = strlen(str);
    for (int n = 0; n <= i - 1; ++n)
    {
        if (str[n] == str[i - n - 1])
        {
            continue;
        }
        else
        {
            printf(" '%s' is not a palindrome.\n", str);
            exit(0);
        }
    }
    printf("'%s' is a palindrome.\n", str);
    return 0;
}