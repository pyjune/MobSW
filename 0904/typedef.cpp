#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	double grade;
}StudentType;

typedef struct list {
	int n;
	struct list *next;
}ListType;

typedef unsigned int u32_t;

int main(void)
{
	StudentType s1 = { 1, 3.5 };

	ListType a = { 10 };
	struct list b = { 20 };
	struct list c = { 30 };
	struct list *pHead;

	pHead = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("%d\n", pHead->next->n);

	system("pause");
}
