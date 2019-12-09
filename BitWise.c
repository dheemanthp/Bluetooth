

https://www.geeksforgeeks.org/extract-k-bits-given-position-number/
// Function to extract k bits from p position 
// and returns the extracted value as integer 
int bitExtracted(int number, int k, int p) 
{ 
    return (((1 << k) - 1) & (number >> (p - 1))); 
} 
  
// Driver code 
int main() 
{ 
    int number = 171, k = 5, p = 2; 
    printf("The extracted number is %d",  
               bitExtracted(number, k, p)); 
    return 0; 
} 
