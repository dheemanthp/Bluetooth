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
    //character array
    char arr1[10] = {'d','h','e','e','m','a','n','t','h','\0'};
    char arr2[50] = "dheemanth";//try to reduce and increase size here from 50 to say 3 , and see garbage output
    char *arr3 = "dheemanth";
    
    //play with the 3 arrays
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
    printf(" the char  of arr3 is %c\n",*(arr3+1));//increasing the character address by 1 location
    printf(" the char  of arr3 is %c\n",*arr3+1);//dereferencing and then doing a +1 to its achii value
    printf(" the address of arr3 is %p\n",&arr3);
    
    printf(" the address of arr3[0] is %p\n",arr3+0);
    printf(" the address of arr3[1] is %p\n",arr3+1);
    printf(" the address of arr3[1] is %p\n",arr3+2);
    
    
    //integer pointers
    int *ptr = 21;
    printf(" the ptr address is %p\n",&ptr);
    printf(" the ptr contains is %d\n",ptr);
    //printf(" the ptr value is %d\n",*ptr); will cause SEG fault as you are assinging 21 to ptr instead of an address
    
    //integer pointers
    int num = 21;
    int * ptr1;
    ptr1 = &num;
    printf(" the ptr1 address is %p\n",&ptr1);
    printf(" the ptr1 contains is %d\n",ptr1);
    printf(" the ptr1 value is %d\n",*ptr1);
    
    
    //2D arrays
    int abc[2][3] = {};//init to all zeros
    printf(" the abc value is %d\n",abc[0][0]);
    printf(" the abc value is %d\n",abc[0][1]);
    
    int xyz[2][3];//not initialized , so will contain all garbage
    printf(" the xyz value is %d\n",xyz[0][0]);
    printf(" the xyz value is %d\n",xyz[1][2]);
    
    int abcd[2][3] = {1,2,3,4,5,6};//init to all zeros
    
    
    //play with 2D pointers
    printf(" the abcd starting address is %p\n",abcd);
    printf(" the abcd address is %p\n",&abcd);
    printf(" the abcd address is %p\n",(abcd+1));//increment by one row , each row contains 3 integers
    printf(" the abcd address is %p\n",(abcd+2));//increment by one row
    
    printf(" the abcd value is %d\n",**(abcd+0));//first row and first value
    printf(" the abcd value is %d\n",**(abcd+1));//second row first value
    
    printf(" the abcd value is %d\n",*(*(abcd+0)+0));//first row and first value
    printf(" the abcd value is %d\n",*(*(abcd+0)+1));//first row and second value
    printf(" the abcd value is %d\n",*(*(abcd+0)+2));//first row and third value
    
    printf(" the abcd value is %d\n",*(*(abcd+1)+0));//second row and first value
    printf(" the abcd value is %d\n",*(*(abcd+1)+1));//second row and second value
    printf(" the abcd value is %d\n",*(*(abcd+1)+2));//second row and third value
    
    
    
    
    
    
}
