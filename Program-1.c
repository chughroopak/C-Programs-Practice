// Program 1: Write a program to sort a number of strings using bubble sort. 
// Input is a number of strings and the output is the sorted list based on the length of strings.  
// For e.g.: If input is jyoti, sareeka, anisha, sangita, savita, suja  
// The output is suja, jyoti, anisha, savita, sareeka, sangita

#include<stdio.h>
#include<string.h>

#define MAX 100
 
void sortStrings(char arr[][MAX], int n)
{
    char temp[MAX];
 
    // Sorting strings using bubble sort
    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strlen(arr[j])>strlen(arr[i]))
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }        
            
        }
    }
}

int main()
{
    char arr[][MAX] = {"jyoti", "sareeka", "anisha", "sangita", "savita", "suja"};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    sortStrings(arr, n);
 
    for (int i=0; i<n; i++)
        printf("%s, ", arr[i]);
    return 0;
}
