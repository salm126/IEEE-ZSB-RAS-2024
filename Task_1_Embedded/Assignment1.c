
//Assigments 1//
//problem 1//
/*
#include<stdio.h>
 int main(){
    int length=5;
    int arr[length];
    int i,j;
    int count=0;
    printf("Enter %d the elements\n",length);
    for(i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<=length;i++){
     for(j=i+1;j<=length;j++){
        if(arr[i]==arr[j]){
            count++;
            break;
        }
        }
}
printf("The Total Count of  duplicate element %d\n",count);
    return 0;
}
*/
/*-----------------------------------------------------------------------*/
/*
//problem 2//
#include<stdio.h>
 int main(){
 int i,j,size;
  printf("Enter size of array: ");
  scanf("%d",&size);
  int arr[size];

printf("Enter Array elements:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
 }
 printf("Uniqie Elements:\n");
    for(i=0;i<size;i++){
       int count=0;
     for(j=0;j<size;j++){
        if(i!=j){
        if(arr[i]==arr[j]){
          count++;
          break;
        }
        }
     }
     if(count==0){
     printf("%d ",arr[i]);
     }
    }
    return 0;
     
 }
 */
/*----------------------------------------------------------------------*/
 //problem 3//
 /*
#include <stdio.h>
void counting_freqency(int arr[], int size);

int main() {
  int arr[] = {1, 2, 3, 2, 3, 4, 1, 2, 5, 6, 2, 9, 3};
   int size = sizeof(arr) / sizeof(arr[0]);
   counting_freqency(arr, size);
    return 0;
}
void counting_freqency(int arr[], int size) {
  printf("Frequency of all elements in the array:\n");
 for (int i = 0; i < size; i++) {
   int count = 1;
  if (arr[i] != -1) {
   for (int j = i + 1; j < size; j++) {
    if (arr[i] == arr[j]) {
     count++;
     arr[j] = -1;
    }
   }
   printf("%d occurs %d times\n", arr[i], count);
  }
 }
}
*/
/*-----------------------------------------------------------------------*/
/*
//problem 4//
#include<stdio.h>
 int add(int*x,int*y);
  int main(){
    int x,y;
    int sum;
    printf("\nAdd two number using call by reference:\n");
    printf("\n---------------------------------------\n");
    printf("Enter the first  number: ");
    scanf("%d",&x);
    printf("Enter the second number: ");
    scanf("%d",&y);

    sum=add(&x,&y);
    printf("The sum of %d & %d is %d",x,y,sum);
    return 0;
 }
  int add(int*x,int*y){
    int sum;
    sum=*x+*y;
    return sum; 
 }
 */
/*--------------------------------------------------------------------------------*/
/*
//Assignment 2//
#include<stdio.h>
int main() {
    int x= 3;
    int y= 4;
    int z= 5;
    int *p, *q, *r;
  //set address of the pointer
    p = &x;
    q = &y;
    r = &z;
    printf("Values:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("p = %p, q = %p, r = %p\n", p, q, r);
    printf("p* = %d, q* = %d, r* = %d\n", *p, *q, *r);

    printf("\nSwapping pointers:");
    int *temp=r;
    r = p;
    p = q;
    q = temp;

//The values after Swapping
    printf("\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("p = %p, q = %p, r = %p\n", p, q, r);
    printf("p* = %d, q* = %d, r* = %d\n", *p, *q, *r);

    return 0;
}
*/
/*----------------------------------------------------------------------------*/
//Assignment 3
//problem 1//
/*
#include<stdio.h>
#include<string.h>
int main(){
  char str[50];
  printf("Input a string : ");
  scanf("%s",str);
  printf("Your string : %s\n",str);
   return 0;
}
*/
/*---------------------------------------------------------------------------------*/
//problem 2 //
/*
#include<stdio.h>
#include<string.h>
int main(){
  char str[50];
  int i=0;
  printf("Input a string : ");
  gets(str);
  while(str[i]!='\0'){
  printf("%c ",str[i]);
  i++;
  }
   return 0;
}
*/
/*--------------------------------------------------------------------------------*/
//problem 3 //
/*
#include <stdio.h>
#include <string.h>
int compare(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i;
    int count = 0;

    for (i = 0; i < len1 && i < len2; i++) {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        } else {
            count++;
        }
    }

    if (count == len1 && count == len2) {
        return 0;
    } else if (len1 < len2) {
        return -1;
    } else {
        return 1;
    }
}

int main() { 
    char str1[50], str2[50];
    printf("Enter the first string:");
    scanf("%s", str1);
    printf("Enter the second string:");
    scanf("%s", str2);

    int result = compare(str1, str2);

    if (result == 0) {
        printf("Both strings are equal\n");
    } else if (result > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str2 is greater than str1\n");
    }

    return 0;
}
*/
/*-------------------------------------------------------------------------------*/

 /*
 //problem 4 //
#include <stdio.h>
#include <string.h>
int main() {
    char str1[10], str2[10];
    int i;
    printf("Enter the string1: ");
    scanf("%s",str1);
    for(i=0;str1[i]!='\0';i++){
    str2[i]=str1[i];
   }
 str2[i]= '\0';
 printf("string2 is : %s\n",str2);
  return 0;
}
*/
/*----------------------------------------------------------------------------------*/
          










