#include<stdio.h>
#include<conio.h>
struct link_list
{
	int n;
	struct link_list *next;
};
typedef struct link_list node;
void create(node *p,int i);
void print(node *p);
void insert(node *p);
node *search(node *p,int num);
void del(node *p,node *key);
int count(node *p);
node *reverse(node *x);
int main()
{
	node *head,*key;
	int n,number,ch;
	clrscr();
	printf("How many elements?");
	scanf("%d",&n);
	head=(node*)malloc(sizeof(node));
	create(head,n);
	for(;;)
	{
		printf("\n1. Insert\n2. delete\n3.display\n4.clear scran\n5.count node\n6.reverse\n7.exit");
		printf("\n\nEnter choise:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the value after which the node will be inserted");
			scanf("%d",&number);
			key=search(head,number);
			insert(key);
			printf("\nItem inserted");
			break;
			case 2:printf("\nEnter the value to be deleted");
			scanf("%d",&number);
			key=search(head,number);
			del(head,key);
			break;
			case 3:print(head);
			break;
			case 4:clrscr();
			break;
			case 5:number=count(head);
			printf("\nThe number of node is %d",number);
			break;
			case 6:head=reverse(head);
			break;
			case 7:exit();
			default:printf("\n\n\n\n\tWrong input!!!");
		}
	}

}
void create(node *p,int i)
{
	printf("Input number");
	scanf("%d",&(p->n));
	if(i!=1)
	{
		p->next=(node*)malloc(sizeof(node));
		create(p->next,i-1);
	}
	else
	{
		p=NULL;
	}
}
void print(node *p)
{
	if(p->next!=NULL)
	{
		printf("%d-->",p->n);
		print(p->next);
	}
	else
	{
		printf("%d",p->n);
	}
}
void insert(node *p)
{
	node *x;
	x=(node*)malloc(sizeof(node));
	printf("\nEnter the value");
	scanf("%d",&(x->n));
	x->next=p->next;
	p->next=x;
}
node *search(node *p,int num)
{
	  if(p->n==num)
	  {
		return(p);
	  }
	  else if(p->n==NULL)
	  {
		return(NULL);
	  }
	  else
	  {
		search(p->next,num);
	  }
}
void del(node *p,node *key)
{
	node *x;
	x=(node*)malloc(sizeof(node));
	if(p->next==key)
	{
		x=key->next;
		p->next=x;
		free(key);
	}
	else
	{
		if(key!=NULL)
		{
			del(p->next,key);
		}
		else
		{
			printf("Not found");
		}
	}
}
int count(node *p)
{
	int n=0;
	for(;;)
	{
		if(p->next==NULL)
		{
			break;
		}
		else
		{
			n++;
			p=p->next;
		}
	}
	n++;
	return(n);
}
node *reverse(node *x)
{
	node *p,*q,*r;
	p=x;
	q=0;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	x=q;
	return(x);
}
