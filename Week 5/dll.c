#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head=NULL,*tail=NULL,*cur,*t1,*t2,*prev,*next;

void create()
{
	int n,i;
	printf("enter number of nodes\n");
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%d",&(cur->data));
		cur->prev = NULL;
		cur->next = NULL;
		if(head==NULL)
		{
			head=tail=cur;
		}
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail = cur;
		}
	}
}


void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%d",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev = cur;
	head = cur;
}

void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%d",&(cur->data));
	cur->next = NULL;
	cur->prev = tail;
	tail->next = cur;
	tail = cur;
}

void insert_at_pos()
{
	int pos,c = 1;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%d",&(cur->data));
	printf("enter position");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}

void insert_before()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%d",&(cur->data));
	printf("enter the data before which node we need to insert: ");
	scanf("%d",&value);
	t1 = head;
	while(t1!=NULL && t1->data!=value)
	{
		t2 = t1;
		t1 = t1 -> next;
	}
	t2 -> next = cur;
	cur -> prev = t2;
	cur -> next = t1;
	t1 -> prev = cur;

}	

void insert_after()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%d",&(cur->data));
	printf("enter the data after which node we need to insert: ");
	scanf("%d",&value);
	t1 = head;
	while(t1!=NULL && t1->data!=value)
	{
		t1 = t1 -> next;
	}
	cur-> next = t1->next;
	t1-> next-> prev = cur;
	t1-> next = cur;
	cur -> prev = t1;
}


void delete_at_begin()
{
	cur = head;
	head = head -> next;
	head -> prev = NULL;
	cur -> next = NULL;
	printf("Deleted element is %d", cur-> data);
	free(cur);
}


void delete_at_end()
{
	cur = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	cur -> prev = NULL;
	printf("Deleted element is %d", cur-> data);
	free(cur);
}


void delete_at_pos()
{
	int c = 1,pos;
	printf("enter position of deletion \n");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next= t1 -> next;
	t1 -> next->prev = t2;
	printf("deleted data is %d",t1->data);
	free(t1);
}


void delete_before()
{
	t1 = head;
	int value;
	printf("enter the data of a node to delete before");
	scanf("%d",&value);
	while(t1->next->data!=value && t1-> next != NULL)
	{
		t2 = t1;
		t1 = t1 -> next;
	}
	t2 -> next = t1 -> next;
	t1-> next -> prev = t2;
	printf("deleted element %d", t2->data);
	free (t2);
}


void delete_after()
{
	int value;
	t1 = head;
	printf("enter the data of a node to delete after");
	scanf("%d",&value);
	while(t1 != NULL && t1->data != value)
	{
		t1 = t1 -> next;
	}
	t2 = t1 -> next;
	t1 -> next = t2 -> next;
	t2 -> next -> prev = t1;
	printf("deleted element %d", t2->data);
	free (t2);
}


void display()
{
	if(head == NULL)
	printf("list is empty");
	else
	{
		cur = head;
		while(cur != NULL)
		{
			printf("%d<->",cur->data);
			cur = cur -> next;
		}
	}
}

void reverse()
{
	if(head == NULL)
	printf("list is empty");
	else
	{
		cur = tail;
		while(cur != NULL)
		{
			printf("%d<->",cur->data);
			cur = cur -> prev;
		}
	}
}
			

void search()
{
	int value;
	int flag = 0, c = 1;
	printf("enter the value to be searched: ");
	scanf("%d",&value);
	t1 = head;
	while(t1 != NULL)
	{
		if(t1 -> data == value)
		{
			flag = 1;
			break;
		}
		t1 = t1 -> next;
		c++;
	}
	if(flag == 1)
	{
		printf("element is present in the list at %d position",c);
	}
	else
		printf("element is not present in the list");
}


void sort()
{
	struct node *p1,*p2;
	int t;
	int c = 0;
	p1 = head;
	while(p1 != NULL)
	{
		c++;
		p1 = p1->next;
	}
	for(int i=0;i<c;i++)
	{
		p2 = head;
		while(p2->next!= NULL)
		{
			if(p2->data > p2->next->data)
			{
				t = p2->data;
				p2->data = p2->next->data;
				p2->next->data = t;
			}
		p2 = p2->next;
		}
	}
}


int main()
{
	int ch;
	while(1)
	{
	printf("program for double linked list\n");
	printf("---------------------------------------------\n");
	printf("1-create\n2-insert at begin\n3-insert at end\n4-insert at position\n5-insert before");
	printf("\n6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
	printf("11-delete after\n12-display\n13-display in reverse\n14-search\n15-sort\n");
	printf("---------------------------------------------\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: create();
			 break;
		case 2: insert_at_begin();
			break;
		case 3: insert_at_end();
			break;
		case 4: insert_at_pos();
			break;
		case 5: insert_before();
			break;
		case 6: insert_after();
			break;
		case 7: delete_at_begin();
			break;
		case 8: delete_at_end();
			break;
		case 9: delete_at_pos();
			break;
		case 10: delete_before();
			break;
		case 11: delete_after();
			break;
		case 12: display();
			break;
		case 13: reverse();
			break;
		case 14: search();
			break;
		case 15: sort();
			break;
		case 16: exit(0);
	}
	}
	return 0;
} 