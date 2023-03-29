#include<stdio.h>
/**************************************MACROS************************************/
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long  int uint32_t;
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long  int int32_t;
#define STACK_SIZE 100

/***********************GLOBAL VARIABLES******************************************/

typedef struct stack {
    uint8_t elements[STACK_SIZE];
    int8_t top;
} ST_stack_t;

ST_stack_t new_stak;
/********************FUNCTION PROTOTYPES******************************************/
void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);
int8_t printStack(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
int8_t isFull(ST_stack_t *stack);
int8_t isEmpty(ST_stack_t *stack);

/**********************************MAIN****************************************/
void main (void)
{
uint8_t poped_data,top_data;
/*************************************************/
createEmptyStack(&new_stak);
printf("pushing 5 different elements to stack\n");
push(&new_stak,50);
push(&new_stak,40);
push(&new_stak,30);
push(&new_stak,20);
push(&new_stak,10);
printStack(&new_stak);
/***************************************************/
printf("\npoping one element\n");
pop(&new_stak,&poped_data);
printStack(&new_stak);
/**************************************************/
getStackTop(&new_stak,&top_data);
printf("\n printing the stack top:\n%d",top_data);
/**************************************************/
printf("\n printing all stack elements\n");
printStack(&new_stak);
/*************************************************/
printf("pushing 7 different elements to stack\n");
push(&new_stak,70);
push(&new_stak,69);
push(&new_stak,68);
push(&new_stak,67);
push(&new_stak,66);
push(&new_stak,65);
push(&new_stak,64);
printStack(&new_stak);
/***********************************************/
getStackTop(&new_stak,&top_data);
printf("\n printing the stack top:\n%d",top_data);
/*************************************************/
printf("\n printing all stack elements\n");
printStack(&new_stak);
/*************************************************/
printf("\npoping four element\n");
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
/**************************************************/
getStackTop(&new_stak,&top_data);
printf("\n printing the stack top:\n%d",top_data);
/*************************************************/
printf("\n printing all stack elements\n");
printStack(&new_stak);
/***********************************************/
printf("\npoping seven element\n");
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
pop(&new_stak,&poped_data);
/**************************************************/
printf("\n printing the stack top");
getStackTop(&new_stak,&top_data);
if (getStackTop(&new_stak,&top_data))
    printf("\nstack top equal to %d\n",new_stak.top);
else
    printf("\n printing the stack top:\n%d",top_data);
/****************************************************/
printf("\n printing all stack elements\n");

if(printStack(&new_stak))
    printf("\n stack is empty\n");
}

/********************************************create empty stack************************************************************************************************/
/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t *stack)
{
     stack->top=-1;
    for(uint8_t index_i=0;index_i<STACK_SIZE;index_i++)
    {
        stack->elements[index_i]=0;
    }
}

/*********************************************push to stack****************************************************************************************************/


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
 int8_t push(ST_stack_t *stack, uint8_t data)
 {
     if(isFull(stack))
     {
         return -1;
     }
        stack->top++;
         stack->elements[stack->top]=data;
         return 0;
 }


 /************************************pop from stack*********************************************************************************************************/

 /* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
 int8_t pop(ST_stack_t *stack, uint8_t *data)
 {
     if(isEmpty(stack))
     {
         return -2;
     }
     else
      *data = stack->elements[stack->top];
      stack->top--;
       return 0;

 }

 /******************************************************print stack*****************************************************************************************/

 /* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
 int8_t printStack(ST_stack_t *stack)
 {
     if(isFull(stack)==-1)
     {
         return -1;
     }
    if(isEmpty(stack))
     {
         return -2;
     }
    for(uint8_t index_i=stack->top+1;index_i>=1;index_i--)
       {
             printf("%d\n",stack->elements[index_i-1]);

    }

         return 0;

 }

 /********************************************************get stack top*****************************************************************************************/

 /* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    if(isEmpty(stack))
    {
    return -2;

    }
    else
        *topData=stack->elements[stack->top];
        return 0;

}

/*********************************************************is full check*********************************************************************************/


/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack)
{
    if(stack->top==STACK_SIZE-1)
    {
        return -1;
    }
    else

        return 0;

}

/*********************************************************is empty check********************************************************************************/

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack)
{
    if(stack->top==-1)
    {
        return -2;
    }
    else

        return 0;


}

/******************************************************************************************************************************************************/
