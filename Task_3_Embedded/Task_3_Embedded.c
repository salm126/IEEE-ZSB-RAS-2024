/*
//Assiement_1//
//Calculator using pointer to function operations//
#include <stdio.h>

float sum(float A, float B);
float sub(float A, float B);
float mul(float A, float B);
float divi(float A, float B);

int main(){

 float (*ptrfun[4])(float, float) = {sum, sub, mul, divi};   
 float A,B,result;
 int choice;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    printf("\nEnter the first number: ");
    scanf("%f",&A);
     printf("\nEnter the second number: ");
    scanf("%f",&B);

    result = ptrfun[choice - 1](A, B);
    printf("\nResult: %.2f\n", result);
    return 0;
}

float sum(float A, float B) {
    return A + B;
}
float sub(float A, float B) {
    return A - B;
}
float mul(float A, float B) {
    return A * B;
}
float divi(float A, float B) {
    return A / B;
}
*/
/*-------------------------------------------------------------------------------------------------*/

/*
#include<stdio.h>
int main(){
    char operation;
    float A,B,result;
    printf("Enter operation(+,-,*,/) : ");
    scanf("%c",&operation);
    printf("Enter the first number A:  ");
    scanf("%f",&A);
    printf("Enter the second number B:  ");
    scanf("%f",&B);

    switch (operation)
    {
    case '+':
      result= A+B;
      printf("result: %f",result);
        break;
    case '-':
   result= A-B;
   printf("result: %f",result);
     break;
     case '*':
     result=A*B;
     printf("result: %f",result);
     break;
     case '/':
     result= A/B;
     printf("result: %f",result);
     break;
    default:
    printf("Error operation");
        break;
    }
}
*/
// The Difference between normal if and #ifdef //
/* normal if */
/*
#include <stdio.h>
int main(){
    float Test;
    printf("Enter The Test: ");
    scanf("%f",&Test);
    if (Test >= 85 && Test <= 100) {
       printf("Grade A: %.2f \n",Test);
    }
    else if (Test >= 75 && Test < 85) {
        printf("Grade B: %.2f \n",Test);
    }
    else if (Test >= 65 && Test < 75) {
        printf("Grade C: %.2f \n",Test);
    } 
    else if (Test >= 50 && Test < 65) {
        printf("Grade D: %.2f \n",Test);
    }
    else
    printf("Failed! \n");
}

/* #ifdef #else #endif */
/*
#include <stdio.h>
#define Area
int main(){
    const float PI = 3.1432;
    float radius;
    printf("Enter The radius: ");
    scanf("%f",&radius);
    #ifdef Area
    printf("Area of Circle %f",PI *radius*radius);
    
    #else
    printf("Circumference of Circle    %f",2 * PI * radius );
    #endif
    return 0;
}
*/

/*#if #elif #else #endif*/
/*
#include<stdio.h>
#define Test 90
int main(){
    #if Test==50
    printf("success\n");
     printf("Test: %d",Test);
    #elif Test < 50
    printf("Fail\n");
    printf("Test: %d",Test);
    #else
    printf("Excellet\n");
    printf("Test: %d",Test);
    #endif
    return 0;
}
*/
