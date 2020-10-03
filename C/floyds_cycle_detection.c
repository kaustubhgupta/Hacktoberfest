#include <stdio.h>
#include <stdlib.h>

// struct for the Linked list
struct Node {
	int Data;
	struct Node *next;
};

void insertNode(struct Node **head, int data, int pos) {
	int k = 1;
	struct Node *new, *p = *head, *q;
	new = (struct Node *)malloc(sizeof(struct Node));
	new->Data = data;
	if (*head == NULL && pos > 1) {
		printf("Please create atleast a few elements\n");
		return;
	} else if (pos == 1) {
		new->next = p; // current node's next pointing to head
		*head = new;   // head assigned as to the current node
		return;
	} else {
		while (p != NULL && k < pos) {
			/*
			 * Althout there are better and efficient ways to do this, I found
			 * it easier.
			 */
			q = p;		 // temporary node holds the current node
			p = p->next; // current node pointing to it's next
			k++;
		}
		q->next = new;
		new->next = p;
	}
}

void deleteNode(struct Node **head, int pos) {
	struct Node *p = *head, *q;
	int k = 1;
	if (*head == NULL) {
		printf("Nothing to delete\n");
		return;
	} else if (pos == 1) {
		(*head) = (*head)->next; // head node now points to it's next
	} else {
		while (p != NULL && k < pos) {
			q = p;
			p = p->next;
			k++;
		}
		if (p == NULL) { // given positions node results in null
			printf("Invalid Position\n");
			return;
		} else {
			q->next = p->next; // node will point to its next's next
			free(p);
			return;
		}
	}
}

void printList(struct Node *head) {
	while (head != NULL) {
		printf("%2d -->", head->Data);
		head = head->next;
	}
	printf("NULL\n");
}

void making_cycle(struct Node **head) {
	struct Node *temp = *head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next =
		*head; // making last node point to the head node, resulting in cycle
}

void cycleDetection(struct Node **head) {
	struct Node *fst = *head,
				*slw =
					*head; // hare as fast pointer and tortoise as slow pointer
	while (fst->next->next && slw->next) {
		fst = fst->next->next; // hare moves fast (twice compared to tortoise)
		slw = slw->next;	   // tortoise moves slowly
		if (fst == slw) {	   // they meet, indicating a cycle in their path
			printf("Cycle Detected\n");
			printf("Tortoise and hare meeting at\n");
			printf("%d and %d\n", fst->Data, slw->Data);
			exit(0);
		}
	}
}

// the main funtion's code is just for test purpose the use may implement
// another approach of their choice
int main() {
	struct Node *head = NULL;
	// test code must be changed accordingly
	int n; // number of nodes
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int element, positon;
		// input format: element and it's positon
		scanf("%d %d", &element, &positon);
		insertNode(&head, element, positon);
	}
	int flag_bit = 1; // flag to make cycle or not
	scanf("%d", &flag_bit);
	if (flag_bit) {
		making_cycle(&head);
		/*
		 * running cycleDetection without making a cycle will result in seg
		 * fault since the fast point will reach the end of list and try to find
		 * last node's next's next or next's next of the second last node which
		 * are not allocated
		 */
		cycleDetection(&head);
		/*not showing the list as it will result in inf loop*/
	} else {
		printList(head);
	}
	free(head);
	return 0;
}
