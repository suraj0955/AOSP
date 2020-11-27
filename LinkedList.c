#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void displayList();
void DeleteFront();
void DeleteEnd();
void Insert_At_Position();
void Insert_At_End();
void insert_front();
void FindMiddle_Delete_PreviousNode();
void FindLastNth();

int main()
{
    int n, Udata, choice;

    /*A
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while(1)
    {
        
    printf("\n**************MENU***************\n");
    printf("\n1: DisplayList 2: insertNodeAtBeginning 3: Insert_At_Position 4: Insert_At_End 5: DeleteFront\n 6: DeleteEnd ");
    printf("7: Insert_At_front 8:FindMiddle_Delete_PreviousNode 9:FindLastNth\n");
    printf("Enter the choice : ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        
    
    case 1:    
            printf("\nData in the list \n");
            displayList();
            break;
/***********************************************************/
    /*
     * Insert data at the beginning of the singly linked list
     */
     
     case 2:
            printf("\nEnter data to insert at beginning of the list: ");
            scanf("%d", &Udata);
    
            insertNodeAtBeginning(Udata);
            break;
            
    case 3:
    
             Insert_At_Position();
             break;
    case 4:
             Insert_At_End();
             break;
/************************************************/
    case 5:
             DeleteFront();
             break;
             printf("\nDeleted data in the list \n");

/************************************************/

    case 6:    
             DeleteEnd();
             break;

    case 7: insert_front();
            break;
        
    case 8:  
            FindMiddle_Delete_PreviousNode();
            break;

    case 9:
            FindLastNth();
            break;
            
    default:
            printf("Enter the right choice!!!\n");
    
    
    return 0;

    }
    
    }
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Input data of node from the user
         */        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link data field of newNode with data
                newNode->next = NULL; // Link address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/*
 * Create a new node and inserts at the beginning of the linked list.
 */
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode =malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

     printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}

void DeleteFront()
{
    
  
    
    struct node *toDelptr;
    if(head == NULL)
    {
        printf(" There are no node in the list.");
    }
    else
    {
        toDelptr = head;
        head = head->next;
        printf("\n Data of node 1 which is being deleted is :  %d\n", toDelptr->data);
        free(toDelptr);  // Clears the memory occupied by first node
    }
    
}

void DeleteEnd()
{
    
    struct node *temp , *prev=NULL;
    
    for(temp=head;temp->next;temp=temp->next)
    {
        
        prev=temp;
    }
    
    prev->next=temp->next;
    free(temp);
    
    

}

void Insert_At_End()
{
        struct node *temp, *prev=NULL, *ptr=head;
        int NODE;
        
        temp=malloc(sizeof(struct node));

        printf("\nEnter the new node\n");
        scanf("%d",&NODE);
      
        temp->data=NODE;
        temp->next=NULL;
        
        
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        
        ptr->next=temp;
    
        
}

void Insert_At_Position( )
{
    int i=0, pos=0, NODE=0;
    
    struct node *ptr, *temp;
    ptr=head;
    
    printf("\nEnter the node to insert\n");
    scanf("%d",&NODE);
    
    
    printf("\nEnter the position\n");
    scanf("%d",&pos);
    
    
    temp=malloc(sizeof(struct node));
    
    for(i=1;i<pos-1&&ptr!=NULL;i++)
    {
        ptr=ptr->next;
        
    }
    
    
    temp->data=NODE;
    
    temp->next=ptr->next;
    ptr->next=temp;
}

void insert_front() {
    
    int value;
    struct node * new_node = NULL;

    printf("Enter the value");
    scanf("%d",&value);
    /*Allocating memory for the new node*/
    new_node =malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->data = value;

    /*Pointing the new node to where head is currently pointing to*/
    new_node->next = head;

    /*Pointing head to new node.*/
    head = new_node;
}


void FindMiddle_Delete_PreviousNode()
{

	struct node *FastPtr=head, *SlowPtr=head , *prev ,*temp=head;
	
    if(head == NULL)
    {
        printf(" There are no node in the list.");
    }
    else
	{
	    
	
	while((FastPtr!=NULL)&&(FastPtr->next)!=NULL)
	{
		temp=temp->next;
		FastPtr=FastPtr->next->next;
		prev=SlowPtr;
		SlowPtr=SlowPtr->next;
	}


	printf("Middle Node is %d \n", temp->data);

	/*To delete previous node of middle node*/

	printf("Now we are deleting the previous node of middle node :%d\n", prev->data);	
	SlowPtr->next=prev->next;
	prev->next=NULL;
	free(prev);
	
	printf("Previous node of middle node deleted\n");


	}
	
}


void FindLastNth()
{
    
    struct node *temp=head;
    
    int number,count ,i;
    
    printf("Enter the number to find from last\n");
    scanf("%d",&number);
    
   while(temp)
   {
       count++;
       temp=temp->next;
   }
    temp=head;
    for (i=0;i<count-number;i++)
    {
        temp=temp->next;
        
    }
    
    printf("Last %d number element is : %d\n", number ,temp->data);
    
}
