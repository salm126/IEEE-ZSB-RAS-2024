/* ***************************************** Dynamic memory allocate ******************************************* */
/*
//Assiement_1//
#include<stdio.h>
#include<stdlib.h>
int main(){
  int *ptr1,*ptr2,*ptr3,*ptr4;
  ptr1= (int*)malloc(5 *sizeof(int));
   if (ptr1==NULL){
    printf("Error! memory not allocated for ptr1");
    exit(1);
   }
   else {
    for (int i = 0; i < 5; i++)
    {
       ptr1[i]=i * 5;
       printf("The values ptr1[%d]: %d\n",i,ptr1[i]);
   }
    }
       printf("\n");

  ptr2= (int*)calloc(7,sizeof(int));
   if (ptr2==NULL){
    printf("Error! memory not allocated for ptr2");
    exit(1);
   }
   else {
    for (int i = 0; i < 7; i++)
    {
       ptr2[i]=i * 10;
       printf("The Values ptr2[%d]: %d\n",i,ptr2[i]);
   }
    }
     
     printf("\n");

  ptr3= (int*)realloc(ptr2,9*sizeof(int));
   if (ptr3==NULL){
    printf("Error! memory not allocated for ptr3");
    exit(1);
   }
   else {
    for (int i = 0; i < 9; i++)
    {
       ptr3[i]=i * 10;
       printf("The Values ptr3[%d]: %d\n",i,ptr3[i]);
   }
   printf("\n");
    }
  ptr4 = (int*)malloc(10 * sizeof(int));
   if (ptr4 == NULL) {
     printf("Error! Memory not allocated for ptr4");
     exit(1);
    } else {
      for (int i = 0; i < 10; i++) 
      {
       ptr4[i] = i * 20;
       printf("The Values ptr4[%d]: %d\n", i, ptr4[i]);
   }
    }
    
    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);
     return 0;
   }
   */

  /* ******************************************read name input from user*******************************************/
/*
  #include<stdio.h>
  #include<string.h>
int main(){
  
  int len,i;
  char name[100];

  printf("Enter the maximum length for the name: ");
  scanf("%d",&len);

  printf("Enter the name: ");
  fflush(stdin);
  gets(name);
 
  printf("print name: %s\n",name);

  char freq='\0';
  int count=0;
  
  for(int i=0; name[i]!='\0' ;i++){
    int char_count=0;
 for (int j=0; name[j]!='\0' ;j++) {
        if(name[i]==name[j]){
          char_count++;
        }
    }
    if(char_count> count){
      count=char_count;
      freq=name[i];
    }
  }
    printf("frequency: %c\n",freq);
    printf("count character is repeated: %d\n",count);
  
    return 0;
}
*/

//Assiement_2//
/* *************************************** time im variable format ******************************************* */
/*
#include<stdio.h>
int main(){
  int hour,min,sec,time;
  
  do{
  printf("Enter Time(hh:mm:ss): ");
  scanf("%d:%d:%d",&hour,&min,&sec);

  if (hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
        printf("Invalid time format. Please enter valid values.\n");
    }
    else{
     printf("The Time is Entered: %02d:%02d:%02d\n",hour,min,sec);
     time=hour*60*60+min*60+sec;
     printf("time in seconds: %d sec",time);
    }
  }
  while(hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 59);
    return 0;
  }
  */

 /* ********************************************* print unique character *************************************** */

/*
#include<stdio.h>
#include<string.h>
int main(){
  int i;
  char stopCode[] = "!!";
  char str[100];
  while (1) {
  printf("Enter the string: ");
  gets(str);
  printf("\nYour String is : ");
  puts(str);
        
  str[strcspn(str, "\n")] = '\0';
  if (strcmp(str, stopCode) == 0) {
  printf("Stop code detected. Exiting the program.\n");
  return 0;
  }
  
   printf("Unique characters: ");
  for(int i=0;i<strlen(str);i++){
    int isUnique = 1;

 for (int j=i+1;j<strlen(str);j++) {
   if(str[i] == str[j]) {
     isUnique=0;
     break;
 }
  }
  if (isUnique) {
   printf("%c ",str[i]);
  }
  }
  printf("\n");
  }
  return 0;
} 
*/


//Assiement_3//

/*best case?
   macro:used for defining constants short utility functions, or conditional compilation.
   inline:suitable for small, frequently used functions
   Regular Function: suitable for complex or larger functions that are reused at multiple locations within the code.  
   */
  
/*
#include <stdio.h>
#define my_sizeof_macro(type) ((char *)(&type + 1) - (char *)&type)

size_t my_sizeof_inline(const double var) {
  return sizeof(var);
}
int main() {
  double x;
  printf("Size of x (macro): %zu bytes\n", my_sizeof_macro(x));
  printf("Size of x (inline): %zu bytes\n", my_sizeof_inline(x));
  return 0;
}
*/

/* ****************************************** linked_list ***************************************************** */

//linked list is dynamic as size but array fixed as size//
//easy insert and delete oposite array//
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *head=NULL;
void ADD_data(int data);
void Delete_data();
void Print_data();
int main(){
  while (1){
     char choice;
    printf("Enter ('+' to add, '-' to delete, 'p' to print,'x' to Exit): ");
    scanf(" %c", &choice);
    switch (choice){
    case '+':
       printf("Enter data to add: ");
       int dataToAdd;
      scanf("%d", &dataToAdd);
       ADD_data(dataToAdd);
       break;

    case '-':
    printf("Enter data to delete: ");
      int dataToDelete;
       scanf("%d", &dataToDelete);
      Delete_data();
      break;
    case 'p':
     Print_data();
    break;
     case 'x':
     printf("Exit from program!!");
    exit(0);
     break;
    default:
    printf("Invalid choice try again\n");
    
    }
  }
  return 0;
}
void ADD_data(int data){
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->link=head;
  head=newnode;
}
void Delete_data(){
if(head==NULL){
    printf("Linklist is empty\n");
  return;
}
struct node *temp=head;
head=head->link;
free(temp);
}
void Print_data(){
  if(head==NULL){
    printf("linklist is empty\n");
    return;
  }
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->link;
  }
  printf("\n"); 
}
*/
