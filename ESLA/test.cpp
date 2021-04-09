#include <iostream>
#include <cstring>
#include<unordered_map>
using namespace std;

/* Tesla Inc. Wireless Software Engineer Screening Test
 * Time: 90 minutes
 * Max score: 100
 *
 * All solutions should compile without error or warnings
 *
 * Penalties:
 * -1 / minute over time
 * -3 for 1 or more compilation errors
 * -2 for 1 or more compilation warnings
 *
 * Do not use outside aid or share the content of this test
 *
 * A main() function is provided at the bottom for your use
 */
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// 1) Bit Manipulation (5 points)
//    Write a function that inverts (0 -> 1 or 1 -> 0) the most significant and
//    least significant bits of the data value pointed to by b.
typedef unsigned char uint8_t ;
void flip_hi_lo(uint8_t* b)
{

    //Since it has been clearly mentioned only MSB and LSB
    //we can use a mask , where only those bits which needs to be flipped are set
    //XOR property helps to further flip it
    //mask is 1000 0001
    uint8_t mask = 0x81;
    *b  = *b ^ mask; 

}

////////////////////////////////////////////////////////////////////////////////
// 2) Endianess (10 points)
//    The following memory dump was taken while debugging an issue.
//
// Memory Dump:
// Address:  Byte:
// 0x1000    0xA0
// 0x1001    0x0A
// 0x1002    0xBA
// 0x1003    0x48
// 0x1004    0x2C
// 0x1005    0xB7
// 0x1006    0x3B
// 0x1007    0x82
// 0x1008    0x9C
// 0x1009    0xE5
// 0x100A    0x17
// 0x100B    0x40
// 0x100C    0xEF
// 0x100D    0x47
// 0x100E    0x0F
// 0x100F    0x98
// 0x1010    0x6F
// 0x1011    0xD5
// 0x1012    0x70
// 0x1013    0x9E
// 0x1014    0x94
// 0x1015    0x99
// 0x1016    0x4A
// 0x1017    0xBA
// 0x1018    0xCA
// 0x1019    0xB2
// 0x101A    0x32
// 0x101B    0xE6
// 0x101C    0x8E
// 0x101D    0xB9
// 0x101E    0xC5
// 0x101F    0x2E
// 0x1020    0xC3
//
// System is 32-bit, little-endian.
// A variable called myPacket is of type packet_S (typedef below).
// (Default compiler options; unpacked, naturally aligned.)
// The address of myPacket is 0x1010.
//
typedef struct
{
    uint8_t count;
    uint16_t data[2];
    uint32_t timestamp;
} packet_S;
 
// a) What are the values of each member of myPacket?
/*
1) little endian : The least significant byte (the "little end") of the data is placed at the byte with the lowest address
2) Since structure is unpacked, naturally aligned , the structure will occupy a total of 12 bytes
3) With Pragma pack(1) it will occupy 9 bytes , this changes the default structure packing to byte packing, 
removing all padding bytes normally inserted to preserve alignment.


//little endian
count = 0x6F
data[0] = 0x9E70
data[1] = 0x9994
timestamp = 0xE632B2CA

// b) If the system was big-endian, what would the values of each member of
//    myPacket be?

1)big endian : The most significant byte (the "big end") of the data is placed at the byte with the lowest address
//Big endian
count = 0x6F
data[0] = 0x709E
data[1] = 0x9499
timestamp = 0xCAB232E6
*/

////////////////////////////////////////////////////////////////////////////////
// 3) Memory allocation (10 points)
//    The functions send_packet() and allocate_packet () are meant to:
//    1. Allocate memory for a packet.
//    2. Populate its contents
//    3. Send it out to the intended recipient
//    Let's assume that the contents of the packet are populated correctly
//    and the packet is sent out to the intended recipient.
//    Does the memory allocation look good? If not, please describe all issues.
//    Also propose a better way to do this.

  /*
  Does the memory allocation look good? If not, please describe all issues ?
  1) malloc takes the size (number of bytes to allocate) as an input , and here
  we are supposed to input the size occupied by the packet_S structure which will be
  12 bytes(unpacked) , but instead we are using the size of the pointer to packet_S which
  will be a constant size and either 4 bytes or 8 bytes depending on the opearting system.
  */
  /*
  propose a better way to do this:
  We can instead only have sizeof(packet_S)
  pkt = (packet_S *)malloc(sizeof(packet_S));

  2) It will be good if the caller can allocate the memory in advance , so that he is in better control
   also malloc and free should ideally be called in the same lexical scope so that it is is clean and readable.

  3)it is not very clear if the recipent will free the memory in this use case      
  */

void allocate_packet(packet_S *pkt)
{
    //pkt = (packet_S *)malloc(sizeof(packet_S *));//WRONG
    // Initialize rest of the structure
  
  //propose a better way to do this:
  //We can instead only have sizeof(packet_S)
  pkt = (packet_S *)malloc(sizeof(packet_S));//CORRECT WAY To Malloc
}

void send_packet()
{
    packet_S *pkt = NULL;
    allocate_packet(pkt);
    // Send to recipient.
}

////////////////////////////////////////////////////////////////////////////////
// 4) Dictonary (30 points)
//    Implement a dictionary that supports
//    - addition of a new word and its meaning
//    - deletion of a word
//    - look up a word with a complete of partial input and return its meaning.
//    Write a test stub to demonstrate all of the above functionality.
//    Feel free to use STL or other library.

//NOTE:
/*
1) I am little confused with the wording of the 4th question
"look up a word with a complete of partial input" , if parital input is possible.
For parital input a TRIE structure is useful. The we will have each character as the key, and then
value will contain hashmap again contain <character, hasmap>.
2) I was not clear if one word can have multiple meanings, Assumed that there will only be 1 meaning
for a given word , Other wise would have used a Vector as Value , 
containing many meanings for a given Key(word).
*/

#define MAX_STRING_SIZE 2048

class Dictonary {
public:
  Dictonary();
  virtual ~Dictonary();

  bool addEntry(const char *newWord, const char *meaning);
  bool deleteEntry(const char *word);
  bool searchEntry(const char *newWord, char *meaning);

  void dumpDict();

private:
//unordered map : order is not required to be tracked for this problem
unordered_map<string,string> umap;
};

Dictonary::Dictonary() {

}

Dictonary::~Dictonary() {
umap.clear();
}

bool Dictonary::addEntry(const char *newWord, const char *meaning) {
  bool entryAdded = false;
//if key is not found , add key,value pair
if (umap.find(newWord) == umap.end()){
    umap.insert(make_pair(newWord, meaning));
} else {
    ////if key is found , update the meaning
    umap[newWord] = meaning;
}
  entryAdded = true;
  return entryAdded;
}

bool Dictonary::deleteEntry(const char *word) {
  bool entryDeleted = false;
  //If key is found
  if (umap.find(word) != umap.end()){
    entryDeleted = true;
    cout << " Key match , deleting Entry "<<  word << endl;
    umap.erase (word);  
  //If key is not found
  } else {
    cout << " No Key match unable to delete Entry "<< word<<endl;
    entryDeleted = false;
  }
  return entryDeleted;
}

bool Dictonary::searchEntry(const char *newWord, char *meaning) {
  bool entryFound = false;
  string value;
    // If key is found
    if (umap.find(newWord) != umap.end()) {
    cout << " Key found: " << newWord << " ,Value: " << umap.at(newWord) << endl;
    value = umap.at(newWord);
    strcpy(meaning, value.c_str());
    entryFound = true;
    }
    //If key is not found 
    else 
    {
    cout << " Key not found: "<< newWord << endl;
    }
    
  return entryFound;
}

void Dictonary::dumpDict() {
// Traversing an unordered map
    cout << "==============dictorinary dump================" << endl;
    for (auto x : umap)
      cout << " Key: " << x.first << " ,Value: " << x.second << endl;
    cout << "==============================================" << endl;
}

////////////////////////////////////////////////////////////////////////////////
// 5a) Circular buffer (14 points)
//     Create a function to push a char into a FIFO. The FIFO should be implemented
//     as a circular buffer of length 20. The FIFO will be used to cache the most
//     recent data from a data stream, therefore, drop the oldest value if the
//     buffer is full.
 
#define BUFFER_SIZE 20
char fifo_buffer[BUFFER_SIZE];
static uint32_t buffer_level = 0;
void buffer_push_ISR(char data)
{
   //buffer level points to where next newest element can be inserted
   // once the buffer array is full filled up , then buffer level will have 2 meaning
   //points to the oldest element or where the next newest element shall be inserted
   //keep pushing each character into the fifo buffer and increment the buffer level
   //use modulo to treat it as a circular buffer   
   fifo_buffer[buffer_level] = data;
   buffer_level++;
   if(buffer_level >=BUFFER_SIZE) {
   buffer_level = buffer_level % BUFFER_SIZE;
   }
}
 
////////////////////////////////////////////////////////////////////////////////
// 5b) Print buffer (6 points)
//     Create a function to print out and empty the data buffer.
//     Data should be printed in order from oldest to newest, active elements only.
 
void print_and_empty_buffer(void)
{
//case 1
//in case the buffer is not completely filled , then we know it will contain null terminator
//hence we need to print from index 0 containing the oldest character until the end of array OR until we find a null terminator
int start = 0;
int end = BUFFER_SIZE-1;

//case 2
//this is a case where all the elements in the array are already filled up
//we use buffer level as reference as it points to the oldest element or where the next newest element has to be inserted , 
//we shall start printing from the oldest element, and use modulo to reach the newest element
//NOTE : if the buffer level is 0 , it means it is a straight forward case where we print from 0 to 
//BUFFER_SIZE - 1

if(fifo_buffer[buffer_level] != '\0' && (buffer_level != 0)) {
  start = buffer_level;
  end = buffer_level-1;
}

//print from start until end OR until we hit a null terminator
while ( start != end && fifo_buffer[start] != '\0') {
    printf(" the buffer is %c , index = %d\n",fifo_buffer[start],start);    
    start++;
    start = start %  BUFFER_SIZE;
    if(start == end){ //last valid index value
    printf(" the buffer is %c , index = %d\n",fifo_buffer[start],start);    
    }
}

//Empty the buffer
printf(" Empty the buffer , here i am just doing a memset\n");  
memset ( fifo_buffer, 0, BUFFER_SIZE );

}


////////////////////////////////////////////////////////////////////////////////
// 6) Unit Testing (10 points)
//    Write a unit test for validate_pointer_and_data that exercises all code paths
//    and branch conditions
 
// @param dataPtr - int32_t pointer to data to be used
//
// @return TRUE if pointer is non-NULL, data value is positive, non-zero and not
//         equal to the sentinel value 0x7FFFFFFF, FALSE otherwise
//
bool validate_pointer_and_data(int32_t* dataPtr)
{
    bool status = false;
    if ((dataPtr != NULL) &&
        (*dataPtr > 0)    &&
        (*dataPtr != 0x7FFFFFFF))
    {
        status = true;
    }
    return status;
}

void testpassorfail (bool result, int testcount)
{
  if(result == true)
  {
    printf("test %d pass\n", testcount);
  } else
  {
    printf("test %d fail\n", testcount);
  }
}
 
//
// @return TRUE if all tests pass, FALSE otherwise
//

bool TEST_validate_pointer_and_data(void)
{ 
  int testcount = 1;
  int a;
  int32_t* dataPtr = NULL;
  bool result = false;
  //Negative test 1, null check
  bool result1  = (validate_pointer_and_data(dataPtr) == false) ? true :false;
  testpassorfail(result1, testcount);
  testcount++;
  //Negative test 2, minimum negative value for a signed integer
  a = 0x80000000;  
  dataPtr = &a;
  bool result2 = (validate_pointer_and_data(dataPtr) == false) ? true :false;
  testpassorfail(result2, testcount);
  testcount++;
  //Negative test 3, zero
  a = 0;
  dataPtr = &a;
  bool result3 = (validate_pointer_and_data(dataPtr) == false) ? true :false;
  testpassorfail(result3, testcount);
  testcount++;
  //Negative test 4, maximum positive value for a signed integer 
  a = 0x7FFFFFFF;
  dataPtr = &a;  
  bool result4 = (validate_pointer_and_data(dataPtr) == false) ? true :false;
  testpassorfail(result4, testcount);
  testcount++;
  //Negative test 5, higher than the maximum Int value is wrapped around
  a = 0xFFFFFFFF;
  dataPtr = &a;  
  bool result5 = (validate_pointer_and_data(dataPtr) == false) ? true :false;
  testpassorfail(result5, testcount);
  testcount++;
  //Positive test 6
  a = 20;
  dataPtr = &a;
  bool result6 = (validate_pointer_and_data(dataPtr) == true) ? true :false;
  testpassorfail(result6, testcount);
  testcount++;
  //Positive test 6
  a = 0X6FFFFFFF;
  dataPtr = &a;
  bool result7 = (validate_pointer_and_data(dataPtr) == true) ? true :false;
  testpassorfail(result7, testcount);
  testcount++;  

 if(result1 && result1 && result3 && result4 && result5 && result6 && result7) {
   result = true;
 } else {
   result = false;
 }
 return result;
}

////////////////////////////////////////////////////////////////////////////////
// 7) Append Strings (15 points)
//    Fix as many problems with this code as you can find.
char *append_strings(char *str1, char* str2)
{
    //please note that i have not considered memory overlap etc in which case we can
    //use alternatives like memmove , as we are now dynamically allocating memory,
    //and the caller will free it 
    char *result_str;
    if(str1 == NULL && str2 == NULL){
        printf("%d:%s ERROR: NULL pointers detected\n",__LINE__, __FUNCTION__);
        return NULL;
    }
    int str1len = 0, str2len = 0;
    str1len = strlen(str1);
    str2len = strlen(str2);
    //allocate memory combining the 2 string lengths and also ensure we have
    //space for null termination '\0'
    result_str = (char*)malloc(str1len + str2len + 1);
  
    strncpy(result_str, str1,str1len);
    strncpy(result_str + str1len, str2,str2len);
        //store null terminator
  result_str[str1len + str2len] = '\0';
  
  return result_str;
}

void test_append_strings()
{   
    char* my_string1 = (char*)"String1";//supress warning
    char* my_string2 = (char*)"String2";
    char *result;
    printf("%d:%s Testing appending strings function\n",__LINE__, __FUNCTION__);
    result = append_strings(my_string1,my_string2);
    printf("Resulting string: %s\n", result);
    free(result);
}


// MAIN function
int main() {

  //Bit Manipulation Input 1
  //INPUT : 1111 1111 FF
  //OUTPUT : 0111 1110 7E
  printf("==============================================\n");
  printf("PROBLEM 1\n");
  printf("==============================================\n");
  uint8_t b=0xFF;
  printf ("Problem 1: Original %x\n", b);
  flip_hi_lo(&b);
  printf ("Problem 1: Flipped %x\n", b);
  
  //Bit Manipulation Input 2
  //INPUT : 0111 1110 7E
  //OUTPUT : 1111 1111 FF 
  uint8_t c=0x7E;
  printf ("Problem 1: Original %x\n", c);
  flip_hi_lo(&c);
  printf ("Problem 1: Flipped %x\n", c);
  printf("==============================================\n");
  printf("PROBLEM 4\n");
  printf("==============================================\n");

    // 4) Dictonary 
    Dictonary dict;

    dict.addEntry("Tesla", "Prolific innovator");
    dict.addEntry("Tesla", "Accelerates path to sustainable energy");
    dict.addEntry("laptop", "with SSD");
    dict.addEntry("Pollute", "Act of contamination with harmful substances");
    dict.deleteEntry("Pollution");

    char meaning[MAX_STRING_SIZE];
    dict.searchEntry("Tesla", meaning);
    dict.searchEntry("Desktop", meaning);
    std::cout << "Problem 4: Tesla = " << meaning << std::endl;
    dict.dumpDict();

  printf("==============================================\n");
  printf("PROBLEM 5\n");
  printf("==============================================\n");
    // Add relevant tests for the dictonary

    // 5) Circular buffer
    memset ( fifo_buffer, 0, BUFFER_SIZE );
    char sample[BUFFER_SIZE]={'a','b','c','d','e','f',
                              'z','x','e','g','h','j', 
                              'q','w','e','r','t','y',
                              '3','4'};
  
    for(int buf_idx = 0; buf_idx < BUFFER_SIZE; buf_idx++)
    {
        buffer_push_ISR(sample[buf_idx]);
    }

    for(int buf_idx = 13; buf_idx < 19; buf_idx++)
    {
        buffer_push_ISR(sample[buf_idx]);
    }

    print_and_empty_buffer();
  printf("==============================================\n");
  printf("PROBLEM 6\n");
  printf("==============================================\n");

  // 6) Unit Testing
    if( TEST_validate_pointer_and_data() == true)
    {
      printf("Problem 6 , all tests pass\n");
    }
    else
    {
      printf("Problem 6 , all tests fail\n");
    }
  printf("==============================================\n");
  printf("PROBLEM 7\n");
  printf("==============================================\n");
    // 7) Append Strings
    test_append_strings();
  printf("==============================================\n");

  return 0;
}
