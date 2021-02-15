/******************************************************************************

                            Computing in C++ : Coursework 1
                                    Kenza Bellahbib
                
*******************************************************************************/


// Question 1:
#include <stdio.h>

void printReverse(char c1, char c2) 
{ 
    printf("%c%c", c2, c1);
}

int main() 
{ 
    char c1 = 'B'; 
    char c2 = 'K';
    printReverse(c1, c2); 
    return 0; 
} 


// Question 2:

/* This function allows us to test the different loops given */
int main() {
  int i;

  for (i=10; i>=1; i-=4)
  {
    printf("%d ", i);
  }
  return 0;
}

/* Results:
for (i=10; i>=1; i-=4) ==> 3 times
for (i=10; i<10; i++) ==> 0 times
for (i=10; i>=1; i-=4) ==> 3 times
for (i=10; i==1; i-=4) ==> 0 times
*/

// Question 3:
#include <stdio.h>
int main()
{
    double number, count, max = 0;
    float min = 10000000000000;

    while(number >= 0.0)
    {
        printf("Enter a number: ");
        scanf("%lf", &number);
        if (number >= 0.0)
        {
            count += 1;
            if (number >= max)
            {
          max = number;
            }
            if (number <= min)
            {
          min = number;
            }
        }
    }

    printf("The mumber of values read is = %.2lf \n", count);
    printf("The minimum is = %.2lf \n", min);
    printf("The maximum is = %.2lf", max);

    return 0;
}

// Question 4:
#include <stdio.h>
#include <string.h>
void reverse(char*, int, int);

int main()
{
   char sentence[200];
   printf("Enter a string up to 200 characters: ");
   scanf("%[^\n]%*c", sentence);

   reverse(sentence, 0, strlen(sentence)-1);

   printf("%s\n", sentence);

   return 0;
}

void reverse(char *x, int begin, int end)
{
   char c;

   if (begin >= end)
      return;

   c = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end) = c;

   reverse(x, ++begin, --end);
}

// Question 5: Sleepy's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int concat(int a, int b) 
{ 
  
    char s1[20]; 
    char s2[20]; 
  
    // Convert both the integers to string 
    sprintf(s1, "%d", a); 
    sprintf(s2, "%d", b); 
  
    // Concatenate both strings 
    strcat(s1, s2); 
  
    // Convert the concatenated string to integer 
    int c = atoi(s1); 
  
    return c; 
} 

char main()
{
    int i;
    int j;
    int k;

    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            for (k = 1; k < 10; k++)
            {
                int numerator1 = concat(i,j);
                int denominator1 = concat(i,k);
                if ((numerator1/denominator1) == (j/k))
                {
                    printf("%d / %d \n", numerator1, denominator1);
                }
                int denominator2 = concat(k,i);
                if ((numerator1/denominator2) == (j/k))
                {
                    printf("%d / %d \n", numerator1, denominator2);
                    printf("%d / %d \n", denominator2, numerator1);
                }
                int numerator2 = concat(j,i);
                if ((numerator2/denominator2) == j/k)
                {
                    printf("%d / %d \n", numerator2, denominator2);
                }
            }
        }
    }

    return 0;
}

// Question 7: Prime numbers
#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int i,j;
    int *primes;
    int N;
    
    // Asks the user to enter N the boundary of prime numbers
    printf("Enter a number: ");
    scanf("%d", &N);
 
    // Array which will include all prime numbers
    primes = malloc(sizeof(int) * N);
 
    for (i = 2;i < N; i++)
        primes[i] = 1;
 
    for (i = 2;i < N; i++)
        if (primes[i]) // We test whether the number can be devided
            for (j = i;i * j < N; j++)
                primes[i * j] = 0;
                
    // Once the array completed, we will print all the prime numbers, i.e. the non zeros of the array
    printf("\nPrime numbers less than or equal to %d are: \n",N);
    for (i = 2;i < N; i++)
        if (primes[i])
            printf("%d\n", i);
 
return 0;
}

// Question 8: Horner's method

#include <stdio.h>
 
int main()
{
     float a[100],sum=0,x;
     int degree,i;
 
     // Sets the degree of the polynomial
     printf("\nEnter degree of the polynomial X: ");
     scanf("%d",&degree);
     // For each power, we set the coefficient
     for(i=degree;i>=0;i--)
     {
            printf("\nEnter Coefficient of X^%d: ",i);
            scanf("%f",&a[i]);
     }
 
     // Enters the value with which we want to evaluate the polynomial
     printf("\nEnter the value of X: ");
     scanf("%f",&x);
 
     // We multiply the variables by iteratiion until we reach the wanted degree
     for(i=degree;i>0;i--)
     {
        sum=(sum+a[i])*x;
     }
 
     // Adds the new element to the previous sum
     sum=sum+a[0];
 
     // Prints final value
     printf("\nValue of the polynomial is = [ %f ]\n",sum);
 
     return 0;
}

