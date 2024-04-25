/*Create Struct*/
/*
//Assiement_1//
#include<stdio.h>
struct student {
    char name[100];
    int roll;
    int age;
    char address[100];
    int mark;
};
int student_inform(struct student str[], int size);
int main(){
    struct student str[15];
    int i;
    for(i=0;i<15;i++){
        printf("Enter the name of %d student: ",i+1);
        scanf("%s",&str[i].name);
        printf("Enter the roll number: ");
        scanf("%d",&str[i].roll);
        printf("Enter the age: ");
        scanf("%d",&str[i].age);
        printf("Enter the address: ");
        scanf("%s",&str[i].address);
        printf("Enter the mark: ");
        scanf("%d",&str[i].mark);
        printf("\n");
    }
    for(i=0;i<15;i++){
        printf("\nThe Information of Student:\n");
        printf("The Name of Student: %s\n",str[i].name);
        printf("The Roll: %d\n",str[i].roll);
        printf("The Age: %d\n",str[i].age);
        printf("The Address of student: %s\n",str[i].address);
        printf("The Mark of student: %d\n",str[i].mark);
    }
   int count=student_inform(str,15);
  printf("\n\nThe number of counts of student less Mark 12 degree:  %d\n",count);
    return 0;
}
int student_inform(struct student str[], int size) {
    int count=0;
    int i;
    for(i=0;i<15;i++){
        if(str[i].mark<12){
           count++;
    }
    }
    return count;
}
*/

/*---------------------------------------------------------------------------------------------------------*/
//Assiement2//

/*
#include <stdio.h>
struct  Date {
    int day;
    int month;
    int year;
    
};
int main(){
    struct Date date1;
    struct Date date2;
    char dateString[11];

   printf("\ncompare two dates\n");
   printf("Enter the First date1 (YYYY/MM/DD): ");   
   scanf("%s", dateString);
  sscanf(dateString, "%d/%d/%d",&date1.year,&date1.month,&date1.day);

   printf("Enter the Second date2 (YYYY/MM/DD): ");   
   scanf("%s", dateString);
   sscanf(dateString, "%d/%d/%d",&date2.year,&date2.month,&date2.day);

  if((date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)){
    printf("\ndates are equal\n");
}
else{
    printf("\ndates are not equal\n");
}
    return 0;
}
*/

/*---------------------------------------------------------------------------------------------------*/

/*
#include<stdio.h>
struct information{
    char name[50];
    int age;
};
int main(){
    struct information object;
    struct information *ptr;

    printf("\nEnnter the name of person: ");
    scanf("%s",object.name);
    printf("\nEnter the age of person: ");
    scanf("%d",&object.age);
    
     ptr=&object;
     printf("\nThe name is: %s",ptr->name);
     printf("\nThe age is: %d",ptr->age);

     return 0;
}
*/
/*---------------------------------------------------------------------------------------------------*/
/*
//Assiement_3//
#include<stdio.h>
struct test1{
    int id;
    char name[20];
    char class_id;             
};
struct test2{
    char name[20];
    int id;
    char class_id;
};
int main(){
    struct test1 size1;
    struct test2 size2;   //changing the order of the members doesn't affect the size of the struct 
                              because size of struct depend on Type of dataTypes // 
                               
printf("The size of struct test1: %ld\n",sizeof(struct test1));
printf("The size of struct test2: %ld\n",sizeof(struct test2));

return 0;
}
*/