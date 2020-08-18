#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/* 
Your previous C++ content is preserved below:


Goal: minimize OS calls
Approach: Pre-allocate Buffers
  Alloc Call-1: 1024
  Alloc Call-2: 1024
  Alloc Call-3: 1024
  .....
  
  CLIENT APP - alloc/free.
  LIB_MEM_INIT() -> library should allocate 1024byte buffer for this client
  LIB_MEM_ALLOC(100) -> library should check if sufficient buffer is there
                        if present, then allocate [SKIP]
                        1024 -> used 800bytes
                        ask 100 -> after this. used 900bytes
                        if not present, then allocate another 1024byte buffer
  LIB_MEM_ALLOC(200) -> curr used = 900b
                        unused = 124b
                        alloc 1024bytes more
                        used = 1100b. total = 1024 + 1024 = 2048. free = 2048-1100
  LIB_MEM_FREE()
  LIB_MEM_FREE_ALL() -
*/

#define POOL_SIZE 1024

typedef struct buff {
  char data;
}BUFF;


//tracks references for each pool
typedef struct node_ref {
  int pool_id;
  BUFF * pool_address_start;
  int pool_size_used;// let us say 124 bytes are used
  int pool_size_remaining; // then it will contain 1024-124 = 900 bytes

  struct node_ref * next; // will point to the next pool
}NODE_REF;

//each client ID INFO
typedef struct client_info {
  int client_id;
  int pools_allocated; //Number of pools allocated_so far
   // Linked list of references 
   NODE_REF * head;
}CLIENT_INFO;


CLIENT_INFO client_array[10];

//insert references of the pool into the queue
NODE_REF * insert_into_reference_Queue(int pool_id, NODE_REF * head , BUFF * address, int size_requested) {
  
  //newly allocated refrence NODE in queue
  NODE_REF * new_node = new_node = (NODE_REF *) malloc(sizeof(NODE_REF));
  new_node->pool_id = pool_id;
  new_node->pool_address_start = address;
  new_node->pool_size_used = size_requested;
  new_node->pool_size_remaining = POOL_SIZE - size_requested;
  
  
  NODE_REF * current_node = head;
  if(current_node == NULL) {

    new_node->next = NULL;
    head = new_node;
    return head;
  }
    else {
          new_node->next = current_node;
    }
          head = new_node;
          return head;
  }


//create a new pool
  BUFF * create_new_pool () {
    //newly allocated region of POOL
    BUFF *ptr = (BUFF *) malloc(POOL_SIZE * sizeof(BUFF)); // 1024 * 1 byte
    return ptr;
  }

// generate a unique_pool_id
int get_unique_pool_id() {
  return 0;
  
}

//check if we can allocate from exisiting pool
BUFF * check_current_pool (CLIENT_INFO * client_info, int size_requested) {

  //we can accomodate the request from the already allocated pool , so no need to create new pool
  if (client_info->head != NULL && client_info->head->pool_size_remaining > size_requested) {

    
    client_info->head->pool_size_remaining = client_info->head->pool_size_remaining - size_requested;
    client_info->head->pool_size_used = client_info->head->pool_size_used + size_requested;
    
    //return the address from the existing pool pointing to the next free location

    return (client_info->head->pool_address_start + client_info->head->pool_size_used);
  }
  //NOTE
  //i have not taken care of fragmentation here
  //we can allocate left over portion from old pool , and some from new pool
  
 
      // else create new pool
  else {

        BUFF * ptr = create_new_pool();
        int pool_id = get_unique_pool_id();
        
        client_info->head = insert_into_reference_Queue(pool_id, client_info->head,ptr,size_requested);
       return client_info->head->pool_address_start;
    }
}





//init , allow all clients for now
bool LIB_MEM_INIT(int client_id) {
  
  BUFF *ptr = create_new_pool();
  client_array[client_id].client_id = client_id;
  client_array[client_id].pools_allocated = 1;
  int pool_id = get_unique_pool_id();
  // we just create a pool , so memory needed for now zero
  client_array[client_id].head = insert_into_reference_Queue(pool_id, NULL,ptr,0); 
  printf("LIB_MEM_INIT COMPLETE\n");
  
  return true;
}


BUFF * LIB_MEM_ALLOC(int client_id, int size_requested) {

  BUFF * ptr = check_current_pool (client_array + client_id, size_requested);
  printf("LIB_MEM_ALLOC COMPLETE\n");
  return ptr;
  
  
  
}


void LIB_MEM_FREE_ALL(int client_id) {
//free all the pools specific to this client id
  NODE_REF * curr_node = client_array[client_id].head;
  while(curr_node != NULL) {//free the queue
    NODE_REF * temp = curr_node;
    free(temp->pool_address_start);//free
    curr_node = curr_node->next;
    free(temp);//free
  }
  client_array[client_id].pools_allocated = 0;//RESET
  //Not resetting the client ID for now 
    printf("LIB_MEM_FREE_ALL COMPLETE\n");

}




// To execute C, please define "int main()"
//NOTE FROM DHEEMANTH
//i have implemented the basic outline 
// there is so much more that could done here :)


int main() {
    LIB_MEM_INIT(1);
    LIB_MEM_ALLOC(1, 200);
    LIB_MEM_FREE_ALL(1);

}
