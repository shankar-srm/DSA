

#include<stdio.h>
int len;
struct node
{
	int info;
	struct node *link;
};

struct node *START = NULL;

struct node* createNode()
{
	struct node *n =(struct node*) malloc(sizeof(struct node));
	return n;
}
int length()
{
	struct node* temp;
	int count = 0;
	temp = START;
	while(temp != NULL)
	{
		count++;
		temp = temp ->link;
	}
	return count;	
}
void addAtBegin()
{
	struct node* temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Node Data :");
	scanf("%d",&temp -> info);
	temp ->link = NULL;
	if(START == NULL)
	{
		START = temp;
	}
	else
	{
		temp -> link = START;//first Right connection
		START = temp;// after Left connection
	}
}
void addAtEnd()
{
	struct node *temp,*t;
	temp = createNode();
	printf("Enter Node INFO:");
	scanf("%d",&temp -> info);
	temp -> link = NULL;
	if(START == NULL)
	{
		START = temp;
	}else
	{	
		t = START;
		while(t ->link != NULL)
		{
			t = t -> link;
		}
		 t ->link = temp;
	}
}
void addAfter()
{
	struct node *temp,*p;
	int len,i=1,loc;
	temp = createNode();
	printf("Enter Node Data:");
	scanf("%d",&temp -> info);
	temp ->link =NULL;
	len = length();
	printf("Enter location where u want to add info:");
	scanf("%d",&loc);
	if(loc > len)
	{
		printf("Invlaid location\n");
		printf("currently list has %d nodes only",len);
	}
	else
	{
		p = START;
		while(i < loc)
		{
			p = p -> link;
			i++;
		}
		temp ->link = p -> link;//right connection
		p ->link = temp;;//left
	}

}
void swapNode()
{
	struct node *p, *q, *r;
	int i=1,loc;
	
	printf("Enter Loc to Swap:");
	scanf("%d",&loc);
	if(loc > length())
	{
		printf("Invalid location!!!!\n");
	}
	else
	{
		p = START;
		while(i < loc-1)
		{
			p = p -> link;
			i++;
		}
		q = p ->link;
		r = q ->link;

		// swaping code
		q -> link = r ->link;
		r ->link = q;
		p -> link = r;
	}
 
}

void deleteNode()
{
	struct node *d;
	int loc;
	printf("\n Enter location to remove Data:");
	scanf("%d",&loc);
	
	if(START == NULL)
	{
		printf("List is Empty!!\n");
	}
	
		else if(loc > length())
		{
			printf("Invalid location!!!!!!!!\n");
		}
			else if(loc == 1)
                {
		
				d = START;
				START = d -> link;
				d -> link = NULL;
				free (d);
				
		
		}

			else
		{
			struct node *p,*q;
			int i;
			p = START;
			while(i < loc -1)
			{
				p= p ->link;
				i++;

			}
			q = p ->link;
			p -> link = q -> link;
			q-> link = NULL;
			free(q);
			
		}

}
void displayList()
{
	struct node *t;
	t = START;
	if(START == NULL)
	{printf("list is Empty!\n");}
	else{
		while(t  != NULL)
		{
			printf("%d-->",t ->info);
			t = t -> link;
		}
	}

}
void reverseList()
{
	int i,j,k,len,temp;
	struct node *p, *q;
	p = q = START;
	len = length();
	j = len-1;
	i =0;	
	while(i < j)
	{
		k = 0;

		while(k < j)
		{
			q = q ->link;
			k++;
		}
		temp = p -> info;
		p -> info = q -> info;
		q -> info = temp;

		i++;
		j--;
		p = p->link;
		q = START;
	}
}
int option()
{
	int ch;
	printf("\n Enter Choice :");
	printf("\n1.Append Info in list\n");
	printf("2. Add info in Begin\n");
	printf("3.Delete  info from list\n");
	printf("4.Display list\n");
	printf("5.Find length\n");
	printf("6 Add data at particular loc\n");
	printf("7 for swapping Node\n");
	printf("8.For Reverse element in Link list\n");
	printf("9.Exit\n");
	//printf("Invalid choice\n");
	scanf("%d",&ch);
	return ch;
}
void main()
{
	while(1)
	{
		switch(option())
		{
			case 1:
				addAtEnd();
				break;
			case 2:
				addAtBegin();
				break;
			case 3:
				deleteNode();
				break;
				
			case 4:
				displayList();
				break;
			case 5:
				len = length();
				printf("Total information in List are:%d\n",len);
				break;
			case 6:
				addAfter();
				break;
			case 7:
				swapNode();
				break;
			case 8:
				reverseList();
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid choice");
		}
	}

}


