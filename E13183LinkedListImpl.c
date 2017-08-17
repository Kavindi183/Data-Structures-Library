#include <stdlib.h>
#include "StackAndQueue.h"
#define NO_OF_ELEMENTS 100000

typedef struct node {// Define the s_node structure with the value of the node and the pointer to the next node
        int val;
        struct node * next;
    }s_Node;

/* Stack Linked List Implementation
 * 
 * 
 *  */
 
 struct stack{// Define the stack structure with a pointer to s_Node (the first element of the linked list)
        s_Node *top_stack;
        int count;
    };

Stack* CreateStack(){
	Stack* stack;
	stack=(Stack*)malloc(sizeof(Stack));
	stack->top_stack=NULL;
	stack->count=0;
	return stack;
	}
	
int StackPush(Stack* stack, int value){
	s_Node * current;
	current=(s_Node*)malloc(sizeof(s_Node));
	stack->count++;
	if(stack->count>NO_OF_ELEMENTS){// Returns -1 if the stack is full
		stack->count--;
		return -1;
		}else{
			current->val=value;// Pushes value to the stack. Returns 0 if it could Push.
                current->next=stack->top_stack;
                stack->top_stack=current;
                return 0;
			
			}
	}
int StackPop(Stack* stack, int* value){
	s_Node *temp;
	if(stack->top_stack==NULL){ // Check if the stack is empty
		return -1;
		}else{
		
		 temp=stack->top_stack;  // store the top_stack in a temp  Node to free it after
            *value=stack->top_stack->val;// Store the popped element in value 
            stack->top_stack=stack->top_stack->next;// Point the top_stack to the next element 
            free(temp);// Free the popped Node
            stack->count--; 
            return 0;
			}
	}
	
int StackPeek(const Stack* stack, int* value){
	if(stack->top_stack==NULL){
		return -1;
		}else{
			*value=stack->top_stack->val; // store the top_stack value in the value pointer
			return 0;
			
			}
	
	}
int DeleteStack(Stack* stack){//free the all node in stack until top_stack become NULL
		s_Node *temp;
		while(stack->top_stack!=NULL){
			temp=stack->top_stack;  
            stack->top_stack=stack->top_stack->next; 
            free(temp);
            stack->count--; 
			
			}
			return 0;

	}
	
	/* Queue Linked List Implementation
	 * 
	 * 
	 *  */
	
 struct queue{// Define the queue structure with two pointers for the first node and rear node
        s_Node *front;
        s_Node *rear;
        int count;
    };
    
Queue* CreateQueue(){
	Queue* queue;
	queue=(Queue*)malloc(sizeof(Queue));
	queue->front=NULL;
	queue->rear=NULL;
	queue->count=0;
	return queue;
	}
	
int QueueEnqueue(Queue* queue, int value){
	s_Node * current;
	current=(s_Node*)malloc(sizeof(s_Node));
	queue->count++;
	current->val=value;
	if(queue->count>NO_OF_ELEMENTS){
		return -1;// Returns -1 if the queue is full
		}else{
			if(queue->front==NULL){// Pushes value to the queue. Returns 0 if it could Push.
				queue->front=current;
				queue->rear=current;
				queue->front->next=queue->rear->next=NULL;
				}else{
				queue->rear->next=current;
				queue->rear=current;
				queue->rear->next=NULL;
					
					}
                return 0;
			
			}
	}
int QueueDequeue(Queue* queue, int* value){
	s_Node *temp;
	if(queue->front==NULL){// Check if the stack is empty.
		return -1;
		}else{
			temp=queue->front;
			*value=queue->front->val;
			queue->front=queue->front->next;
			free(temp);
			queue->count--;
			return 0;
		
			}
	
	}
	
int QueuePeek(const Queue* queue, int* value){
	if(queue->front==NULL){// Check if the stack is empty
		return -1;
		}else{
			*value=queue->front->val; // store the value of front node in the value pointer
			return 0;
			
			}
	
	}
int DeleteQueue(Queue* queue){// free all the nodes in the queue until it the front node become NULL
	s_Node *temp;
	while(queue->front!=NULL){
		temp=queue->front;
			queue->front=queue->front->next;
			free(temp);
			queue->count--;
		}
			
			return 0;

	}
