


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

bool checkPalidrome(char * str, int len) {
    
    int i = 0;
    int j = len-1;
    while(i < j) {
        printf(" \n %c and %c ",str[i],str[j]);
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}



int main()
{
    char name[10] = {'d','h','e','e','m','a','n','t','h','\0'};
    char str[10] = {'m','a','l','a','y','a','l','a','m','\0'};
    
    
    int len  = sizeof(name)/sizeof(name[0]);
    int index = -1;
    printf(" the len is %d",len);
    reverse_string_recursively(name, len-1,index);        
    reverse_normally(name, len-2,index+1);    
    bool result = checkPalidrome(str,strlen(str));
    printf(" \n palindrome result is %s\n",result?"true":"false");
    printf(" \nthe xyz string is %s\n",name);
    return 0;
}

/*******************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

/*
Most of the modern processors are little-endian, while all network protocols are big-endian.
That is history and more on that you can find on Wikipedia. 
But that means our processors convert between little- and big-endian millions of times 
while we browse the Internet.
*/

//little endian to big endian
void little_endian_to_big_endian(){
  unsigned int val = 0x01000000;// MSB is 00 , and LSB 01
  char *c = (char*)&val;
  
  if(*c == 1) {
    //LSB is placed at the lowest address
    printf(" this is little endian\n");
  } else {
    //MSB is placed at the lowest address
    printf(" this is big endian\n");
  }
}

//convert endianness 
unsigned int convert_little_endian_to_big_endian_viceversa(unsigned int val) {
  return     ((val >>24) |
    				 ((val & 0x00ff0000) >>8)  |
    				 ((val & 0x0000ff00) <<8)  |
    				 ((val <<24)));
}


int custom_atoi(const char * str) {
  //remember each char will be in aschii format
  unsigned char len = strlen(str);
  bool sign = false;
  int output = 0;
  int i = 0;
  if(str[i] == '-') {
    i = 1;
    sign = true;
  }
  for(;i < len ;i++) {
    output = output * 10 + (str[i] - '0');
  }
  return (sign == true) ?( output * (-1)):output;
}

void swap(char * str, int len){
  int  i = 0 ;
  printf(" \n calling swap len is %d\n",len);
  while( i < len) {
    str[i] ^= str[len];
    str[len] ^= str[i];
    str[i] ^= str[len];
    i++;
    len--;
  }
}


char* custom_itoa(int val,char * output) {
  printf(" \n custom_itoa\n");
  int i = 0;
  bool sign = false;
  if(val < 0) {
  	sign = true;
    val = abs(val);
  }
  while(val > 0) {
    output[i] = val %10 + '0';
    val = val/10;
    i++;
 }
  if(sign == true) {
    output[i] = '-';
    i++;
  }
  swap(output,i-1);
  output[i] = '\0';
  return output;
}

int main() {

  little_endian_to_big_endian();
  unsigned int val = 0xdeadbeef;
  val = convert_little_endian_to_big_endian_viceversa(val);
  printf(" \nthe val is %x\n",val);
  const char* str = "12345";
  printf(" \n custom_atoi : the val is %d\n",custom_atoi(str));
    const char* str1 = "-12345";
  printf(" \n custom_atoi : the val is %d\n",custom_atoi(str1));
  int value = 12345;
  char output[100];
  printf(" \n custom_itoa first the value is %s\n",custom_itoa(value, output));
  int value1 = -12345;
  char output1[100];
  printf(" \n custom_itoa second the value is %s\n",custom_itoa(value1, output1));
    return 0;
}








