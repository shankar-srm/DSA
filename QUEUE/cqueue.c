// circular queue

# include <stdio.h>

# define SIZE 5
int front = -1;
int rear = -1;
int cqueue[SIZE];


void insert(int ele)
{
	if( (rear == front -1) || (rear == SIZE-1))
	{
		printf("Cqueue is Full!!!\n");
	}
	else if(front == -1 & rear == -1)
	{
		front = rear =0;
		cqueue[rear] = ele;
	}
	else if(rear = SIZE -1)
	{
		rear = 0;
		cqueue[rear] = ele;
	}
	else
	{
		rear++;
		cqueue[rear] = ele;
	}
}
void delete()
{
	int ele;
	if(front == -1 & rear == -1)
	{
		printf("Cqueue is Empty!!!!\n");
	}else if(front == rear)
	{
		ele = cqueue[front];
		front = rear = -1;
	}
	else if(front == SIZE -1)
	{
		ele = cqueue[front];
		front = 0;

	}else
	{
		ele = cqueue[front];
		front++;
	}
}
void display()
{
	int i;
	front =0;
	for(i = front; i < SIZE -1; i++)
	{
		printf("%d ",cqueue[rear]);
	}
}
int choice()
{
	int ch;
	printf("\n Enter Your choice :\n");
	printf("\n 1. Enqueue:");
	printf("\n 2. Dequeue:");
	printf("\n 3. display:");
	printf("\n 4. Exit:\n");
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
				printf("Enter Data to insert :");
				scanf("%d",&item);
				insert(item);
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
				printf("Invalid choice!!!!!!!!!!\n");
		}
	}

}
