// key -> values

typedef int valueType;
typedef struct kvPair{
  int key;
  valueType value;
} kvPair;

typedef struct node{
  kvPair data;
  struct node* nextNode;
}node;

typedef struct linkedList{
  node* firstNode;
  // If firstNode is NULL then we know array is size 0
}linkedList;

linkedList ll_initializeArray(int size);
int ll_getSize(linkedList lst);
kvPair ll_getValue(linkedList* lst, int index);
void ll_setValue(linkedList* lst, kvPair data, int index);
void ll_append(linkedList* lst, kvPair data);