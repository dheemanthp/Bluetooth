/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
    char * Vstrcpy(char * dst,char * src){
        if(src == NULL) return NULL;
        char * ptr = dst; 
        while(*src != '\0') {
            *dst = *src;
            dst++;
            src++;
        }
        *dst = '\0';
        return ptr;
    }
int main()
{
    char *src  = "dheemanth";
    int length = strlen(src);
    char *dst = malloc(sizeof(char)*(length+1));
    char *result = Vstrcpy(dst,src);
    printf(" the result is %s",result);
    return 0;
}




