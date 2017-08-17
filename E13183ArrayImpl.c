#include <stdlib.h>
#include "StackAndQueue.h"
#define NO_OF_ELEMENTS 100000

/* 
 * 
 * Stack Array Implementation
 * 
 * 
 * */

struct stack {
	int top;
	int * myStack;
};


Stack* CreateStack(){
    Stack* stack;
	stack=(Stack*)malloc(sizeof(Stack));
	stack->myStack=(int*)malloc(sizeof(int)*NO_OF_ELEMENTS);// allocate memory for the array in the stack structure
	stack->top=0;
	return stack;
	}

int StackPush(Stack* stack, int value){
	if(stack->top==NO_OF_ELEMENTS){// Return -1 if the array exceed the NO_OF_ELEMENTS
		return -1;
		}else{
		    stack->myStack[stack->top]=value;
			stack->top++;
			return 0;
			}

	}
int StackPop(Stack* stack, int* value){
	if(stack->top==0){// return -1 if the stack is empty
		return -1;

		}else{

		*value=stack->myStack[stack->top-1];// store the value of the last element in stack in value pointer
		stack->top--;
		return 0;

			}

	}
int StackPeek(const Stack* stack, int* value){
	if (stack->top==0){// return -1 if the stack is empty
		return -1;
		}else{
			*value=stack->myStack[stack->top-1];
			return 0;
			}
	}

int DeleteStack(Stack* stack){
	stack->top=0;
	free(stack->myStack);// free the array in the stack
			return 0;

	}
	
	/* Queue Array Implementation
	 * 
	 * 
	 *  */
	
struct queue {
	int top;
	int* myQueue;
};

Queue* CreateQueue(){
	Queue* queue;
	queue=(Queue*)malloc(sizeof(Queue));
	queue->myQueue=(int*)malloc(sizeof(int)*NO_OF_ELEMENTS);// allocate memory for the array in the queue structure
	queue->top=0;
	return queue;
	}
	
int QueueEnqueue(Queue* queue, int value){
	if(queue->top==NO_OF_ELEMENTS){
		return -1;// Return -1 if the array exceed the NO_OF_ELEMENTS
		}else{
		    queue->myQueue[queue->top]=value;
			queue->top++;
			return 0;
			}
	
	
	}
	
int QueueDequeue(Queue* queue, int* value){
	if(queue->top==0){
		return -1;// return -1 if the stack is empty
		
		}else{
		*value=queue->myQueue[0];// store the value of the first element in stack in value pointer
		int i;
		for(i=0;i<queue->top;i++){
			queue->myQueue[i]=queue->myQueue[i+1];//shift the next element towards the frist elemment
			}
			queue->top--;
		
		return 0;
			
			}
	
	
	}
	
int QueuePeek(const Queue* queue, int* value){
	if (queue->top==0){
		return -1;// return -1 if the stack is empty
		}else{
			*value=queue->myQueue[0];
			return 0;
			}
	
	
	}
	
int DeleteQueue(Queue* queue){
	queue->top=0;
	free(queue->myQueue);// free the array in the queue
	return 0;
	}
