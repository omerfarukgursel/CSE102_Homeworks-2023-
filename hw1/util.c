#include <stdio.h>
#include "util.h"


int ebob()
{
    int s1,s2,i,ebob;
    printf("Enter two numbers to calculate gcd:");
    scanf("%d %d",&s1,&s2);
    for (i=1;s1>=i && s2>=i;i++)
    {
        if (s1%i==0 && s2%i==0)
        ebob=i;
    }
    printf("gcd of %d and %d is: %d",s1,s2,ebob);
    return 0;
}

int toplama()
{
    int s1,s2,top;
    printf("Enter two numbers to display their sum:");
    scanf("%d %d",&s1,&s2);
    top=s1+s2;
    printf("%7d\n%7d\n+\n-------\n%7d",s1,s2,top);
    return 0;
    
}

int carpma()
{
    int a,b,c,s1,s2;

    printf("Enter two numbers to multiply:");
    scanf("%d %d",&s1,&s2);
    a= s2%10; //birler basamagi
    b= (s2%100)/10; //onlar basamagi
    c= s2/100; //yuzler basamagi
    if(s2<10)
    {
        printf("First number : %d\nSecond number: %d\nResult:\n%10d\n%10d\n*\n-----------\n%10d",s1,s2,s1,s2,a*s1,b*s1,s1*s2);
    }
    if(s2>=10 && s2<100)
    {
        printf("First number : %d\nSecond number: %d\nResult:\n%10d\n%10d\n*\n-----------\n%10d\n%9d\n+\n----------\n%10d",s1,s2,s1,s2,a*s1,b*s1,s1*s2);
    }
    if(s2>=100){
        printf("First number : %d\nSecond number: %d\nResult:\n%10d\n%10d\n*\n-----------\n%10d\n%9d\n%8d\n+\n----------\n%10d",s1,s2,s1,s2,a*s1,b*s1,c*s1,s1*s2);
    }
    return 0;

   
}

int beslecomp()
{
    int number;
    printf("Enter the number:");
    scanf("%d",&number);

    if(number > 5 && number <= 10)
    {
    printf("The integer you entered is greater than 5");
    }
    if(number >= 1 && number <= 5)
    {
    printf("The integer you entered is less than or equal to 5");
    }
    if(number <= 1 || number > 10) 
    {
    printf("Invalid input");
    }
    return 0;
}
