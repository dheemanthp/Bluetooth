/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>


#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    char arr1[10] = {'d','h','e','e','m','a','n','t','h','\0'};
    char arr2[50] = "dheemanth";//try to reduce and increase size here from 50 to say 3 , and see garbage output
    char *arr3 = "dheemanth";
    
    
    int *ptr = 21;
    printf(" the ptr address is %p\n",&ptr);
    printf(" the ptr contains is %d\n",ptr);
    //printf(" the ptr value is %d\n",*ptr); will cause SEG fault as you are assinging 21 to ptr instead of an address
    
    
    
    //printf(" the ptr value is %d\n",*ptr);
    
    int num = 21;
    int * ptr1;
    ptr1 = &num;
    printf(" the ptr1 address is %p\n",&ptr1);
    printf(" the ptr1 contains is %d\n",ptr1);
    printf(" the ptr1 value is %d\n",*ptr1);
    
    
    
    
    
    
    
    
    
    
    
    printf(" the strng1 is %s\n",arr1);
    printf(" the len1 is %d\n",strlen(arr1));
    printf(" the strng2 is %s\n",arr2);
    printf(" the len2 is %d\n",strlen(arr2));
    printf(" the strng3 is %s\n",arr3);
    printf(" the len3 is %d\n",strlen(arr3));
    
    for(int i = 0;i<50;i++){
        printf(" char2 is %c\n",arr1[i]);
        
    }
    
    printf(" the address of arr3 is %p\n",arr3);
    printf(" the char  of arr3 is %c\n",*arr3);
    printf(" the char  of arr3 is %c\n",*(arr3+1));
    printf(" the char  of arr3 is %c\n",*arr3+1);
    printf(" the address of arr3 is %p\n",&arr3);
    
    printf(" the address of arr3[0] is %p\n",arr3+0);
    printf(" the address of arr3[1] is %p\n",arr3+1);
    printf(" the address of arr3[1] is %p\n",arr3+2);
    
    
    
    
    
    
}
