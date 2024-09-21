//c_tryouts
int lookup(int * arr, int len)
{
	return helper(arr, len, 0);
}

helper(int * arr, int len, int ind)
{
	if(arr[i] < 0)
	{
		return arr[i];
	}
	if(ind == len)
	{
		return 0;
	}
	return helper(arr, len, ind += 1 )
}


typdef struct Gradebook
{
	int class_avg;
	int grades[30];
	char class_symbol;
}Gradebook;


int main()
{
	int x = 1;
	int *p = &x;
	*p2 = 2;
	*p = 3; 
}

void addOne(int * point)
{
	*point = *point + 1;
	return point;
}


void push(int DAT)
{
	Node * new = malloc(sizeof(Node));
	if(new == NULL)
	{
		return NULL;
	}
	new.data = DAT
	new.next = head; 
	head = new; 
}


void deleteList()

	while(head.next != NULL)
	{
		Node tmp = head;
		head = head->next;
		free tmp;
	}
	free(head);
	
void printList()
	while(head.next != NULL)
	{
		printf(head->next); 
		tmp = head.next;	}
	free(head);
	