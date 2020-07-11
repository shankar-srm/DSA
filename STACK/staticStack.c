
// programming implemention of stack 
#include<stdio.h>

# define CAPACITY 5
int isFull(void);
int isEmpty(void);
int push(int);
int pop(void);
int stack[CAPACITY];// cant pass simple variable so used macros
int top = -1;
//int ele;
int isFull()
{
	if(top == CAPACITY - 1)
	{
		return 1;
	}else
	{
		return 0;
	}
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}else
	{
		return 0;
	}

}

int push(int  ele)//insertion operation
{
	if(isFull())
	{
		printf("STACK is Overflow!!!!!!!!!!!\n");
	}else
	{
		top++;
		stack[top] = ele;
		printf("Inserted element is: %d\n",ele);
	}


}
int pop()//deletion opertion
{
	int ele;
	if(isEmpty())
	{
		printf("Stack is UnderFlow!!!!!\n");
	}else
	{
		ele = stack[top];
		top--;
		printf("Element %d is Poped......\n",ele);
	}
	
}
int peek()
{
	int ele;
	if(isEmpty())
	{
		printf("Stack is UnderFlow!!!!!\n");
	}else
	{
		ele = stack[top];
	//	top--;
		printf("Element %d is Picked......\n",ele);
	}
}

void display()
{
	int i;
	printf("\nSTACK Elements Are:");
	for(i =0; i<= top; i++)
	{
		printf("%d",stack[i]);
	}
}
int choice()
{	
	int ch;
	printf("\n Enter What Operation You Want:");
	printf("\n 1.Insertion OPeration :");
	printf("\n 2.Deletion Operation ");
	printf("\n 3.Display");
	printf("\n 4. Peek the item from STACK:");
	printf("\n 5.Exit\n");
	printf("");
	scanf("%d",&ch);
	return ch;
	
}
void main()
{
	int item;
	while(1)
	{
	switch(choice())
	{	
		case 1:
			printf("\nEnter Item:");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid option!!!!!!!!!!!!!!!\n");
	}
	}
}
