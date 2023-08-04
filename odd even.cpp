#include<stdio.h>
int main() {
	int number;
	int min,max;
	printf("Enter the minimum range: ");
	scanf("%d",&min);
	printf("Enter the maximum range: ");
	scanf("%d",&max);
	printf("Odd numbers in given range are: ");
	for (number = min;number <= max; number++)
	         if(number % 2 !=0)
	             printf("%d ",number);
	return 0;
}
