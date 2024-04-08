//Assiement_1
/*
#include <stdio.h>
int main() {
int n=5;
char c='S';
long long l1=1262002;

int*p1=&n;
char*p2=&c;
long long*p3=&l1;
printf("Before increment:\n");
printf("p1 =%p\n",p1);
printf("p2 =%p\n",p2);
printf("p3 =%p\n",p3);

p1++;
p2++;
p3++;

printf("\n");
printf("After increment:\n");
printf("p1 =%p\n",p1);
printf("p2 =%p\n",p2);
printf("p3 =%p\n",p3);
return 0;
}
*/

/*----------------------------------------------------------------------------------------------*/
/*
//problem_2
#include <stdio.h>
int main(){
    int num=0xA123BC;
    int *ptr= &num;
    printf("*ptr: %d \n",*ptr);

    //Read Value  & implement in the next line
    printf("*ptr++: %d\n",*ptr++);

    // implement in the same line then Read new Value
    printf("*++ptr: %d\n",*++ptr);

    //icrement value then Read new Value
    printf("++*ptr: %d\n",++*ptr);
 return 0;

}
*/
/*
#include <stdio.h>
int main(){
    int num=0xA123BC;
    int *ptr= &num;
    printf("*ptr: %d \n",*ptr);

 printf("++*ptr: %d\n",++*ptr);
 return 0;
}
*/
/*-------------------------------------------------------------------------------*/

/*
//Assiement_2//
//problem_1//
#include <stdio.h>

void increment(int*ptr){
  *ptr=(*ptr)+ 1;       //  || ++(*ptr)
  
}
int main(){
    int num=6;
    printf("Before increment: %d\n",num);
    increment(&num);
    printf("After increment: %d\n",num);
    return 0;
}
*/
/*-------------------------------------------------------------------------------*/

/*
//problem_2//
#include <stdio.h>
int main(){
    int arr[5]={10,20,30,40};
    int i,*ptr;
    ptr=&arr[0];
    for (i = 0; i <= 3; i++) {
        printf("The value of element%d: %d\n",i,*ptr);
      ptr++;
    }
    return 0;

}
*/