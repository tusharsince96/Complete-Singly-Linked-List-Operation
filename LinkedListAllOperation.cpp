// Creation in a linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *createList(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int item);
struct node *afternode(struct node *start,int data, int item);
struct node *beforenode(struct node *start,int data,int item);
struct node *position(struct node *start,int data,int pos);
struct node *delfirst(struct node *start);
struct node *delonly(struct node *start);
struct node *delbetwn(struct node *start,int pos);
struct node *dellast(struct node *start,int data);
struct node *reverse(struct node *start);

main()
{
	struct node *start=NULL;
	int choice,item,data,pos;
while(1)
{
	printf("********************************************************\n");
	printf(" 1. Create List\n");
	printf(" 2. Display\n");
	printf(" 3. Count\n");
	printf(" 4. Search\n");
	printf(" 5. Add to an Empty List || Add at Begining\n");
	printf(" 6. Add at End \n");
	printf(" 7. Add after node\n");
	printf(" 8. Add before node\n");
	printf(" 9. Add at Position\n");
	printf("10. Delete first node\n");
	printf("11. Delete the only node\n");
	printf("12. Delete in b/w the list\n");
	printf("13. Delete the last node\n");
	printf("14. Reverse a linked list\n");
	printf("15. Press to Exit!!\n");
	printf("\n**********************************************************\n");
	printf("***Enter your choice***: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			start=createList(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
		    count(start);
			break;	
		case 4:
			printf("Enter the element to be searche in the List: ");
			scanf("%d",&item);
		    search(start,item);
			break;	
		case 5: 
		    printf("Enter the element to be inserted: ");
			scanf("%d",&item);
			start=addatbeg(start,item);
			break;
		case 6:
		    printf("Enter the element to be inserted: ");
			scanf("%d",&item);
			start=addatend(start,item);
			break;
		case 7: 
		    printf("Enter the element to be inserted: ");
			scanf("%d",&data);
			printf("Enter the element after which to insert: ");
			scanf("%d",&item);
			start=afternode(start,data,item);
			break;
		case 8:
			printf("Enter the element to be inserted: ");
			scanf("%d",&data);
			printf("Enter the element before which to insert: ");
			scanf("%d",&item);
			start=beforenode(start,data,item);
			break;
		case 9: 
		    printf("Enter the element to be inserted: ");
		    scanf("%d",&data);
		    printf("Enter the position at which to insert: ");
		    scanf("%d",&pos);
		    start=position(start,data,pos);
		    break;
		case 10:
			start=delfirst(start);
			break;
		case 11:
		    start=delonly(start);
			break;	
		case 12:
			printf("Enter the position of the node to be deleted: ");
			scanf("%d",&pos);
		    start=delbetwn(start,pos);
			break;	
		case 13:
			printf("Enter the last element to be deleted: ");
			scanf("%d",&data);
		    start=dellast(start,data);
			break;
		case 14:
			start=reverse(start);
			break;
		case 15:
			exit(1);
		default:
		    printf("Wrong choice\n");
				
	}
}
}
struct node *createList(struct node *start)
{
	int n,data;
	printf("Enter no. of nodes: ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	return start;
	printf("Enter the data");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(int i=2;i<=n;i++)
	{
		printf("Enter the data");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	start = tmp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	p=start;
	while(p->next!=NULL)
	p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	return start;
}
void display(struct node *start)
{
	struct node *p;
	p=start;
	if(p==NULL)
	{
		printf("List is empty!");
		return;
	}
	printf("List is: ");
	while(p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n\n");
	
}

void count(struct node *start)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->next;
		cnt++;
		
	}
	printf("Number of element in the list are: %d \n",cnt);

}

void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			printf("Item %d found at position %d ",item,pos);
			return ;
		}
		p=p->next;
		pos++;
	}
	printf("Item %d not found in the list\n",item);
	
}

struct node *afternode(struct node *start,int data, int item)
{
	struct node *p=start;
	struct node *tmp;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->data=data;
			tmp->next=p->next;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("%d not present in the list",item);
	
	return start;
}

struct node *beforenode(struct node *start,int data,int item)
{
	struct node *p=start;
	struct node *tmp;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(item == start->data)
	{
		tmp->data=data;
		tmp->next=start;
		start=tmp;
		return start;
	}
	while(p->next!=NULL)
	{
		if(p->next->data==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->data=data;
			tmp->next=p->next;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("%d not present in the list",item);
	
	return start;
}

struct node *position(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	if(pos==1)
	{
		tmp->next=start;
		start=tmp;
		return start;
	}
	p=start;
	for(int i=1; i<pos-1 && p!=NULL;i++)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements in the list\n",pos);
		return start;
	}
	else
	{
		tmp->next=p->next;
		p->next=tmp;
	}
	return start;
		
}
struct node *delfirst(struct node *start)
{
	if(start==NULL)
	{
		printf("Sorry the list is alreday empty");
		return start;
	}
	struct node *tmp;
	tmp=start;
	start=start->next;
	free(tmp);
	return start;
}

struct node *delonly(struct node *start)
{
	if(start==NULL)
	{
		printf("Sorry the list is alreday empty");
		return start;
	}
	start=start->next;
	return start;
}

struct node *delbetwn(struct node *start,int pos)
{
	struct node *p;
	if(start==NULL)
	{
		printf("Sorry the list is alreday empty");
		return start;
	}
	p=start;
	if(pos==1)
	{
		struct node *tmp;
		tmp=start;
		start=tmp->next;
		free(tmp);
		return start;
	}
	for(int i=1;i<pos-1 && p!=NULL;i++)
	{
		p=p->next;
	}
	struct node *tmp;
	tmp=p->next;
	p->next=tmp->next;
	free(tmp);
	return start;
	
}
struct node *dellast(struct node *start,int data)
{
	struct node *p,*tmp;
	if(start == NULL)
	{
		printf("Sorry the list is already empty");
		return start;
	}
	if(start->data==data)
	{
		tmp=start;
		start=start->next;
		free(tmp);
		return start;
	}

	p=start;
	while(p->next!=NULL)
	{
		if(p->next->data==data)
		{
			tmp=p->next;
			p->next=tmp->next;
			free(tmp);
			return start;
		}
		p=p->next;
		
	}
	printf("Element %d not found in the list\n",data);
	printf("\n");
}

struct node *reverse(struct node *start)
{
	struct node *p,*prev,*next;
	prev=NULL;
	p=start;
	while(p!=NULL)
	{
		next = p->next;
		p->next=prev;
		prev=p;
		p=next;
	}
	start=prev;
	return start;
}

