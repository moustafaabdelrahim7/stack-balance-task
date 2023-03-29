#include<stdio.h>
/***********************************************************macros*****************************************************************************************/
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long  int uint32_t;
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long  int int32_t;
/**********************************************************global variables***************************************************************************************/
#define STACK_SIZE 10
typedef struct stack {
    uint8_t elements[STACK_SIZE];
    int8_t top;
} ST_stack_t;
uint8_t pooped_data;
ST_stack_t new_stak;

/****************************************************function prototypes********************************************************************************/
void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);
int8_t printStack(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
int8_t isFull(ST_stack_t *stack);
int8_t isEmpty(ST_stack_t *stack);
int8_t isBalancedParanthethes(uint8_t *expression);

/*************************************************************************************************************************************************/
void main (void)
{
   int8_t returns_status;
   createEmptyStack(&new_stak);

    int8_t expression[30];
    printf("please Enter a string: ");
    fgets(expression, sizeof(expression), stdin);
    returns_status = isBalancedParanthethes(&expression);
         if (returns_status == -1) {
            printf("unbalanced expression\n");
        }
        else if (returns_status == -2)
         {
            printf("no paranthethes\n");
        }
        else
        {
            printf("expression is balanced\n");
        }


}
/*****************************************************is balanced**********************************************************************************/

/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression)
{
    uint8_t index_i;

    for (index_i = 0; expression[index_i]; index_i++)
        {
    if (expression[index_i] == '{' || expression[index_i] == '(')
        {
            push(&new_stak, expression[index_i]);
        }
    else if (expression[index_i] == '}' || expression[index_i] == ')')
        {
          if (new_stak.top == -1)
             {
            return -1;
              }

             pop(&new_stak,&pooped_data );

           if (expression[index_i] == '}' && pooped_data != '{')
               {
                return -1;
               }
         else if(expression[index_i] == ')' && pooped_data != '(')
                {
                 return -1;
                 }
          }

        }

    if (!new_stak.top)
        {
        return -1;
    }
    else if (pooped_data == '\0')
        {
        return -2;
        }
    else
        {
     return 0;
        }



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
         stack->elements[++stack->top]=data;
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
