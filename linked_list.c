 #include <stdio.h>  
 #include <stdlib.h>  
  
 //Structure containing a Data part & a Link part   
  
 struct node  
 {  
   int data;  
   struct node *next;  
 }*Head;  
  
 // Deleting a node from List.  
  
 delnode(int num)  
 {  
    struct node *prev_ptr, *cur_ptr;  
  
    cur_ptr=Head;  
        
    while(cur_ptr != NULL)  
    {  
       if(cur_ptr->data == num)  
       {  
          if(cur_ptr==Head)  
          {  
             Head=cur_ptr->next;  
             free(cur_ptr);  
             return;  
          }  
          else  
          {  
             prev_ptr->next=cur_ptr->next;  
             free(cur_ptr);  
             return;  
          }  
       }  
       else  
       {  
          prev_ptr=cur_ptr;  
          cur_ptr=cur_ptr->next;  
       }  
    }  
  
    printf("\nElement %d is not found in the List", num);  
 }  
  
 //Adding a Node at the end of the list  
  
 append(int num)  
 {  
    struct node *temp,*r;  
  
    temp=(struct node *)malloc(sizeof(struct node));  
    temp->data=num;  
  
    // Copying the Head location into another node.  
    r=Head;  
  
    if (Head == NULL) // If List is empty we create First Node.  
    {  
       Head=temp;  
       Head->next =NULL;  
    }  
    else  
    {       // Traverse down to end of the list.   
       while(r->next != NULL)  
       r=r->next;  
         
       // Appending at the end of the list.  
       temp->next=NULL;  
       r->next =temp;    
    }  
 }  
  
 // Adding a Node at the Beginning of the List  
  
 addbeg(int num)  
 {  
    struct node *temp;  
  
    temp=(struct node *)malloc(sizeof(struct node));  
    temp->data = num;  
  
    if ( Head == NULL)  
    {  
       Head=temp;  
       Head->next=NULL;  
    }  
    else  
    {  
       temp->next=Head;  
       Head=temp;  
    }  
 }  
  
 // Adding a new Node after specifies number of Nodes  
  
 addafter(int num, int loc)  
 {  
    int i;  
    struct node *temp,*prev_ptr,*cur_ptr;  
       
    cur_ptr=Head;  
  
    if(loc > count()+1 || loc <= 0)  
    {  
       printf("\nInsertion at given location is not possible\n ");  
       return;  
    }  
  
    if (loc == 1)// if list is null then add at beginning   
    {  
       addbeg(num);  
       return;  
    }  
    else  
    {  
       for(i=1;i<loc;i++)  
       {  
          prev_ptr=cur_ptr;   // t will be holding previous value of r  
          cur_ptr=cur_ptr->next;  
       }  
  
       temp=(struct node *)malloc(sizeof(struct node));  
       temp->data=num;  
  
       prev_ptr->next=temp;  
       temp->next=cur_ptr;  
  
       return;  
    }  
 }  
  
 // Displaying list contents  
  
 display()  
 {  
    struct node *cur_ptr;  
    
    cur_ptr=Head;      
  
    if(cur_ptr==NULL)  
    {   
       printf("\nList is Empty");  
       return;  
    }  
  
    //traverse the entire linked list   
   
    while(cur_ptr!=NULL)  
    {  
       printf(" -> %d ",cur_ptr->data);  
       cur_ptr=cur_ptr->next;  
    }  
    printf("\n");  
 }  
  
 // Counting number of elements in the List  
  
 count()  
 {  
    struct node *cur_ptr;  
    int c=0;  
     
    cur_ptr=Head;  
  
    while(cur_ptr!=NULL)  
    {  
       cur_ptr=cur_ptr->next;  
       c++;  
    }  
    return(c);  
 }  
  
 //This function Reverses a Linked List  
  
 reverse()  
 {  
    struct node *prev_ptr, *cur_ptr, *temp;  
     
    cur_ptr=Head;  
    prev_ptr=NULL;  
  
    while(cur_ptr != NULL)  
    {  
       temp=prev_ptr;  
       prev_ptr=cur_ptr;  
    
       cur_ptr=cur_ptr->next;  
       prev_ptr->next=temp;  
    }  
   
    Head=prev_ptr;  
 }  
  
int main()  
{  
   int i;  
   Head=NULL;  
  
   while(1)   
   {  
      printf(" \nInsert a number \n1. At Beginning");  
      printf(" \n2. At End");  
      printf(" \n3. At a Particular Location in List");  
      printf(" \n\n4. Print the Elements in the List");  
      printf(" \n5. Print number of elements in the List");  
      printf(" \n6. Delete a Node in the List");  
      printf(" \n7. Reverse the linked List");  
      printf(" \n8. Exit");  
      printf(" \n\nChoose Option: ");  
      scanf("%d",&i);   
  
      switch(i)  
      {  
         case 1:  
        {  
            int num;  
            printf(" \nEnter the Number to insert: ");  
            scanf("%d",&num);  
            addbeg(num);  
            break;  
        }  
         case 2:  
         {  
            int num;  
            printf(" \nEnter the Number to insert: ");  
            scanf("%d",&num);  
            append(num);  
            break;  
         }  
  case 3:  
       {  
           int num, loc, k;  
           printf("\nEnter the Number to insert: ");  
           scanf("%d",&num);  
           printf("\nEnter the location Number: ");  
           scanf("%d",&loc);  
            addafter(num,loc);  
           break;  
      }    
  case 4:  
  {  
     printf(" \nElements in the List: ");  
            display();  
            break;  
        }  
  case 5:  
  {  
     display();  
           printf(" \nTotal number of Elements in the List: %d",count());  
     break;  
     }   
  case 6:  
  {  
     int num;  
           printf(" \nEnter the number to be deleted from List: ");  
           scanf("%d",&num);  
           delnode(num);  
          break;  
      }  
  case 7:  
  {  
     reverse();  
            display();  
            break;  
      }  
    case 8:  
   {  
     struct node *temp;  
      
       while( Head!=NULL)  
     {  
        temp = Head->next;  
        free(Head);  
        Head=temp;  
     }  
       exit(0);  
   }  
  default:   
  {  
     printf("\nWrong Option choosen");  
         }  
      }/* end if switch */  
   }/* end of while */  
}/* end of main */