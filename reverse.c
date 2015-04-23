#include <stdio.h>

struct item
{
	int data;
	struct item* next;
};

struct item* reverse (struct item* head)
{
	struct item *p1, *p2, *tmp;

	p1 = head;
	p2 = head->next;

	while( p2 )
	{
		tmp = p2->next;
		p2->next = p1;
		p1 = p2;
		
		p2 = tmp;
	}
	head->next = NULL;
	return p1;
}
void printList(struct item* list)
{
	while(list)
	{
		printf("%d,",list->data);
		list=list->next;
	}
	printf("\b \n");
}
int main()
{
	struct item* head;

	struct item p1,p2,p3;
	p1.data=1;p1.next=&p2;
	p2.data=2;p2.next=&p3;
	p3.data=3;p3.next=NULL;
	head = &p1;
	printList(head);
	head = reverse(head);
	printList(head);
}