//Assiement_1//

/* ************************************ Assiement_1 typedef bitfield ********************************* */

/*--------------------------------------------START------------------------------------------------*/
/*
#include<stdio.h>
#include <stdlib.h>
typedef struct student_info {
    unsigned int roll_num: 4;
    unsigned int age: 8;
    unsigned int mark: 3;
    char address[20];
    char name[50];  
}student_info;

void print_student_info(student_info student);
int main(){
student_info students[1];
    int i;
   unsigned int R_roll, A_age, M_mark;

    for(i=0;i<1;i++){
    printf("Student %d:\n", i + 1);
     printf("Enter Roll Number: ");
     scanf("%u", &R_roll);
     students[i].roll_num = R_roll;

     printf("Enter Age: ");
     scanf("%u", &A_age);
     students[i].age = A_age;

     printf("Enter Mark: ");
     scanf("%u", &M_mark);
     students[i].mark = M_mark;

     printf("Enter Address: ");
     scanf("%s", students[i].address);

     printf("Enter Name: ");
     fflush(stdin);
     gets(students[i].name);
     printf("\n");
    }
  printf("***********************************");
    for (i = 0; i < 1; i++) {
    printf("\nStudent %d:\n", i + 1);
    print_student_info(students[i]);
    }

    printf("The size of struct student_info: %ld\n",sizeof(struct student_info));
    return 0;
}
void print_student_info( student_info student) {
        printf("\nThe Roll num: %d\n",student.roll_num);
        printf("The Age: %d\n",student.age);
        printf("The Mark of student: %d\n",student.mark);
        printf("The Information of Student: \n");
        printf("The Address of student: %s\n",student.address);
        printf("The Name of Student: %s\n",student.name);
        printf("\n");
}
*/
/*-----------------------------------------------END------------------------------------------------*/


/*--------------------------------------------START------------------------------------------------*/
/*
#include<stdio.h>
typedef struct complex{
    float real;
    float img;
}complex;

complex Add_complex(complex num1,complex num2);
int main(){
  complex num1,num2,result;

  printf("Enter the first num_complex (real+imgi): ");
  scanf("%f+%fi",&num1.real,&num1.img);
  printf("\nEnter the second num_complex (real+imgi): ");
  scanf("%f+%fi",&num2.real,&num2.img);

  result=Add_complex(num1,num2);
  printf("\nAdd Complex two numbers (real+imgi): %f+%fi\n\n",result.real,result.img);

return 0;
}
  complex Add_complex(complex num1,complex num2){
    complex sum;
    sum.real=num1.real+num2.real;
    sum.img=num1.img+num2.img;
    return sum;
}
*/
/*--------------------------------------------END-----------------------------------------------------*/


/*-----------------------------------------------START------------------------------------------------*/

/*
#include<stdio.h>
typedef int Int;
typedef long Long;
typedef float Float;
typedef double Double;
typedef char Char;
typedef _Bool boolean;

int main() {
 Int A= 6;
  printf("size of integer: %lu\n", sizeof(A));
  Long B = 1234512345;
  printf("Size of Long: %lu\n", sizeof(B));
  Float C= 12.60;
  printf("Size of Float: %lu\n", sizeof(C));
  Double D = 1.2062002;
  printf("Size of double: %lu\n", sizeof(D));
  Char E='S';
  printf("Size of character: %lu\n", sizeof(E));
  boolean check=1;
  printf("Size of boolean: %lu\n", sizeof(check));
  return 0;
}
*/
/*-----------------------------------------------END------------------------------------------------*/


//Assiement_2//
/********************************************  Enumaration *****************************************/
/*
#include <stdio.h>
enum opera {add= '+' ,sub= '-' ,mul= '*' ,div= '/' ,and= '&' ,or= '|' ,not= '!' };
int main(){
  int operand1,operand2,result;
   char ch1;
  enum opera operation;
  printf("Enter The operand1: ");
  scanf("%d",&operand1);
  printf("Enter The operand2: ");
  scanf("%d",&operand2);
  printf("Enter the operation character (+, -, *, /, &, |, !): ");
  scanf(" %c", &ch1);

  switch (ch1){
  case'+':
   operation=add;
   result=operand1 + operand2;
      break;

    case '-':
   operation=sub;
   result=operand1 - operand2;
  break;

  case '*':
  operation=mul;
  result=operand1 * operand2;
  break;

  case'/':
  operation= div;
  result=operand1 / operand2;
  break;

  case'&':
  operation= and;
  result=operand1 & operand2;
  break;

  case'|':
  operation= or;
  result=operand1 |operand2 ;
  break;
  
  case'!':
  operation= not;
  result=!operand1;
  break;
  default:
   printf("Error: Invalid operation \n");
  }
    printf("\nThe Result= %d",result);

    //in memory the size of enum is the same size of int= 4 bytes//
    //default of enum always takes constant integer//
  printf("\nThe size of enum: %d bytes",sizeof(enum opera));
  return 0;
}
*/

/*---------------------------------------------END-----------------------------------------------------*/

//Assiement_3//

#include<stdio.h>
#define sort_Ascending

void sort_Ascending_order(int arr[],int size);
void sort_Descending_order(int arr[],int size);
int main(){
  int size,i;
  int arr[size];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter arr of element: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
#ifdef sort_Ascending
sort_Ascending_order(arr,size);
printf("\nsort_Ascending_order of array: ");
for ( i =0; i<size;i++){
printf("%d ",arr[i]);
}
printf("\n");

#elif defined (sort_Descending)
sort_Descending_order(arr,size);
 printf("sort_Descending_order of array: ");
 for ( i =0; i<size;i++){
printf("%d ",arr[i]);
}
printf("\n");
#endif
  return 0;
} 
void sort_Ascending_order(int arr[],int size){
  int temp;
  int i,j;
  for (i = 0; i <size; i++){
    for (j=i+1; j<size; j++)
    {
      if (arr[i] > arr[j])
      {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      } 
    }  
  }
}
void sort_Descending_order(int arr[],int size){
  int temp;
  int i,j;
  for (i = 0; i<size; i++){
    for (j=i+1; j<size; j++)
    {
      if (arr[i]< arr[j])
      {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      } 
    }
  }
}

/*-----------------------------------------------------END-----------------------------------------------*/

  /* ******************implement the two operations with the macros-like functions********************* */
 /*
#include<stdio.h>
#define ADD(num1, num2) num1 + num2
#define SUB(num1, num2) num1 - num2
int main (){
  float num1,num2,result;
  char operation;

  printf("Enter The first number: ");
  scanf("%f",&num1);
  printf("Enter The second number: ");
  scanf("%f",&num2);
  printf("Enter The operation(+ or -): ");
  scanf(" %c",&operation);

  switch (operation){
  case'+':
  result = ADD(num1,num2);
  printf("The Result= %.2f",result);
    break;
  case'-':
  result=SUB(num1,num2);
  printf("The Result= %.2f",result);
    break;
  default:
  printf("operation Error!!");
    break;
  }
  return 0;
}
*/
