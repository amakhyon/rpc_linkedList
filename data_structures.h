#include <stdio.h>
#include <stdlib.h>

//struct node {
//	int data;
//	node *next;
//};

node* createNode(int data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = next;
 
    return new_node;
}

node* addToList(node* head, int data)
{
    
    node *m = head;
    while(m->next != NULL) //go to last node
        m = m->next;
        
    node* new_node = createNode(data,NULL);
    m->next = new_node;
 
    return head;
}

void printList(node *head){
	node *m = head;
	printf("\n %d",m->data);
	while(m->next != NULL){
		m = m->next;
		printf("\n %d",m->data);
	}
    printf("\n");
}

int countNodes(node *head){
	int count=1; node *m = head;
	while (m->next != NULL){
		m = m->next;
		count++;
	}
	return count;
}

node * fillList(){
	node* head; int choice; int dd;
	printf("\n enter head element: ");
    scanf("%d",&dd);
	head = createNode(dd,NULL);

	printf("\n 1)add another node \n 2)done \n choice: ");
	scanf("%d",&choice);
	
	while(choice == 1){
		printf("\n enter data: ");
		scanf("%d",&choice);
		head = addToList(head,choice);
		printf("\n 1)add another node \n 2)done \n choice: ");
		scanf("%d",&choice);
	}
	
	
	return head;
}
int * listToArray(node *head){
	node *m = head;  int count = countNodes(head); 
	int *array = (int*) malloc(sizeof(int) * count);
	int i=0;
	while (m->next != NULL){
		array[i] = m->data;
		m = m->next;
		i++;
	}
	array[i] = m->data;
	m = m->next;
	i++;
	return array;
}

node * arrayToList(int *array,int length){
	int i; node *head;
	head = createNode(array[0],NULL);
	for(i=1; i < length; i++){
		head = addToList(head,array[i]);
	}
	return head;
}
int *sortArray(int *array, int length){
	int max=0; int i; int temp; int j;
	for(i=0; i < length; i++){
		max = array[i];
		for(j=0; j < length; j++){
			if (array[j] > max){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return array;
}



