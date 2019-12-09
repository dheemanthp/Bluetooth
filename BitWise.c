

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
