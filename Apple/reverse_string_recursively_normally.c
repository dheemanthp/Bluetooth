


#include <stdio.h>

//reverse a string recursively
//reverse normally

void swap(char *name,int i, int j){

    if( i ==j) return;
    name[i] ^= name[j];
    name[j] ^= name[i];
    name[i] ^= name[j];
    return;
}

void reverse_string_recursively(char * name,int len,int index) {

    if(len <= index) return;
    printf(" \nthe len is %d & index is %d\n", len, index);
    len  = len -1;
    index = index + 1;
    reverse_string_recursively(name,len,index);
    swap(name,len,index);

}

void reverse_normally(char * name,int len,int index) {

    if(len <= index) return;
    printf(" \nthe len is %d & index is %d\n", len, index);
    while(len > index) {
        swap(name,len,index);
        len  = len -1;
        index = index + 1;
    }

}

int main()
{
    char name[10] = {'d','h','e','e','m','a','n','t','h','\0'};
    int len  = sizeof(name)/sizeof(name[0]);
    int index = -1;
    printf(" the len is %d",len);
    reverse_string_recursively(name, len-1,index);        
    reverse_normally(name, len-2,index+1);        
    printf(" \nthe xyz string is %s\n",name);
    return 0;
}
