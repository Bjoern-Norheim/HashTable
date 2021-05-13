typedef struct node{
  int data;
  struct node* nextNode;
}node;

typedef struct linkedList{
  node* firstNode;
  // If firstNode is NULL then we know array is size 0
}linkedList;

linkedList initializeArray(int size);
int getSize(linkedList* lst);
int getValue(linkedList* lst, int index);
void setValue(linkedList* lst, int data, int index);
void append(linkedList* lst);