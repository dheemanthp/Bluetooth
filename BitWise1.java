```
very good link : https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/
https://medium.com/@codingfreak/bit-manipulation-interview-questions-and-practice-problems-27c0e71412e7
```
```
IN C:https://leetcode.com/problems/reverse-bits/
uint32_t reverseBits(uint32_t num) {
    unsigned int count = sizeof(num) * 8;//31 
    unsigned int reverse_num = 0; 
    while(num) 
    { 
       reverse_num <<= 1;//left shift by 1        
       reverse_num |= num & 1;  //OR
       num >>= 1; //drop bits
       count--;//until num becomes zero decrement count 
    }
    printf(" the count value is %d", count);
    if(count != (sizeof(num) * 8)){
        reverse_num <<= count; // left shift by count times 
    }
    return reverse_num;// reverse the number
}


//Reverse bits in an Integer
public class Solution {
int total = Integer.SIZE - 1;//total number of Bits is 31
//Drop the input 0th bit ,everytime you loop
public int reverseBits(int n) {
  int result = 0;
  //loop through 31 bits or until the number becomes zero
  while(total >= 0 && n !=0) {
    //check if the 0th bit is set
    if ((n & 1) != 0) {
        //OR the result by LEFT SHIFTING 1 TOTAL TIMES
        result = result  | (1 << total);
    }
    n >>= 1;//drop the 0th bit by doing a RIGHT SHIFT
    total--;//decrement count
  }
return result;  
}
}
````

https://www.geeksforgeeks.org/extract-k-bits-given-position-number/
// Function to extract k bits from p position 
// and returns the extracted value as integer 
int bitExtracted(int number, int k, int p) 
{ 
    return (((1 << k) - 1) & (number >> (p - 1))); 
    // ((1 << k) - 1) , will move 1 by 5 positions , which will become 32 , and subtracting by 1 , will give 31
    // 0001 0000 --> 32
    // 0000 1111 ---> 31
    // (number >> (p - 1)) , will right shift the number by (p-1) positions
} 
  
// Driver code 
int main() 
{ 
    int number = 171, k = 5, p = 2; 
    printf("The extracted number is %d",  
               bitExtracted(number, k, p)); 
    return 0; 
} 
