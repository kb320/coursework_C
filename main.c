/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void printReverse(char c1, char c2) 
{ 
    printf("%c%c",
		c2, c1);
}
  
// Driver code 
int main() 
{ 
    char c1 = 'B'; 
    char c2 = 'K';
    printReverse(c1, c2); 
    return 0; 
} 