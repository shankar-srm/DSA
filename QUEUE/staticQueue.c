// static implementation of queue

# include <stdio.h>

# define CAPACITY 5

int queue[CAPACITY];
int front = 0;
int rear = 0;
void insert()
{
	if(rear == CAPACITY)
	{
		printf("Queue is FULL.....");
	}else
	{
		int ele;
		printf("\nEnter data :");
		scanf("%d",&ele);
		queue[rear] = ele;
		rear++;
	}
}
void delete()
{	
	int i;
	if(front == rear)
	{
		printf("Queue is Empty");
	}else
	{
		printf(" Deleted :%d",queue[front]);
		for(i =0; i < rear -1; i++)
		{
			queue[i] = queue[i+1];
		}
		rear--;

	}
}
void display()
{
	int i;
	if(front == rear)
	{
		printf("Queue is Empty");
	}else
	{
		printf("Queue Elements Are :");
		for(i = front; i < rear; i++)
		{
			printf("%d",queue[i]);
		}	
		
	}
}
int choice()
{	
	int ch;
	printf("\n Enter Your Choice :");
	//scanf("%d",&ch);
	printf("\n 1. Insertion:");
	printf("\n 2. Deletion:");
	printf("\n 3. Traversal:");
	printf("\n 4. Exit");
	scanf("%d",&ch);
	return ch;
}

void main()
{
	while(1)
	{
		switch(choice())
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);	
			default:
				printf("Invalid Option Selected!!!!\n");
		}
	}
}
