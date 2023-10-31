#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int count = 0;

typedef enum DataType 
{
    INT, CHAR, FLOAT
} DataType;

struct node 
{
	void* data;        
    DataType type;     
	struct node *link;
} *top = NULL;

int is_empty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

void push(void* data, DataType type)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));   
	
	if(new_node == NULL)
	{
		printf("Stack Overflow");
		exit(1);
	}
	
	switch(type) 
	{
        case INT:
            new_node->data = malloc(sizeof(int));
            *((int*)new_node->data) = *((int*)data);
            break;
        case CHAR:
            new_node->data = malloc(sizeof(char));
            *((char*)new_node->data) = *((char*)data);
            break;
        case FLOAT:
            new_node->data = malloc(sizeof(float));
            *((float*)new_node->data) = *((float*)data);
            break;
    }
	
	new_node->type = type;
	new_node->link = top;
	
	top = new_node;
	count++;
}

void* pop()
{
	struct node *temp;
	temp = top;
	
	if(is_empty())
	{
		printf("Stack Underflow");
		exit(1);
	}

	void* val = temp->data;   
	
	top = top->link;
	free(temp);
	count--;
	
	return val;
}

void peek() 
{
    if (is_empty()) 
	{
        printf("Stack Underflow\n");
        return;
    }
    
    switch(top->type) {
        case INT:
            printf("%d\n", *((int*)top->data));
            break;
        case CHAR:
            printf("%c\n", *((char*)top->data));
            break;
        case FLOAT:
            printf("%f\n", *((float*)top->data));
            break;
        default:
            printf("Unknown data type at the top of the stack.\n");
    }
}

int is_full()
{
    if (count == MAX_SIZE)
        return 1;
    else
        return 0;
}

void print()
{
	struct node *temp;
	temp = top;
	
	if(is_empty())
	{
		printf("Stack Underflow");
		exit(1);
	}
	
	printf("The elements of stack are: ");
	
	while(temp)
	{
		switch(temp->type) 
		{
            case INT:
                printf("%d ", *((int*)temp->data));
                break;
            case CHAR:
                printf("%c ", *((char*)temp->data));
                break;
            case FLOAT:
                printf("%f ", *((float*)temp->data));
                break;
        }
		temp = temp->link;
	}
	
	printf("\n");
}

int main()
{
	int choice;
    int intData;           
    char charData;         
    float floatData;       
    DataType typeChoice;  
	
	while(1)
	{
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. IsEmpty\n");
		printf("5. IsFull\n");
		printf("6. Print all elements\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
                printf("Select data type to push:\n");
                printf("1. Integer\n");
                printf("2. Character\n");
                printf("3. Float\n");
                scanf("%d", &typeChoice);

                switch(typeChoice-1) 
				{
                    case INT:
                        printf("Enter an integer value: ");
                        scanf("%d", &intData);
                        push(&intData, INT);
                        break;
                    case CHAR:
                        printf("Enter a character value: ");
                        scanf(" %c", &charData); 
                        push(&charData, CHAR);
                        break;
                    case FLOAT:
                        printf("Enter a float value: ");
                        scanf("%f", &floatData);
                        push(&floatData, FLOAT);
                        break;
                    default:
                        printf("Wrong data type choice.\n");
                }
				break;
				
			case 2: 
                pop();
				printf("Top element popped.\n");
				break;
				
			case 3:
				printf("The element at the top of the stack is: ");
                peek(); 
				break;
			
			case 4:
                if (is_empty())
                    printf("The stack is empty.\n");
                else
                    printf("The stack is not empty.\n");
				break;
				
			case 5:
				if (is_full())
        			printf("The stack is full.\n");
    			else
        			printf("The stack is not full.\n");
    			break;
				
			case 6:
				print();
				break;
			
			case 7:
				exit(1);
			
			default:
				printf("Wrong choice \n");
				break;
		}		
	}
	return 0;
}

