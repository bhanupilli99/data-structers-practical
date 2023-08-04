# include<stdio.h>
#define MAX_SIZE 100
int main()
{
	int arr[MAX_SIZE];
	int i, n, pos, elem, choice;
	printf("enter the size of array:");
	scanf("%d",&n);
	printf("enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	while(1)
	{
		printf("\n array operations:\n");
		printf("1. insert\n");
		printf("2. slete\n");
		printf("3. display\n");
		printf("4. exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the position to insert:");
				scanf("%d",&pos);
				if(pos < 0 || pos > n)
				{
					printf("invalid position! please enter position betweenn0 to %d\n",n);
				}
				else
				{
					printf("enter the element to insert:");
					scanf("%d",&elem);
					for(i=n-1;i>=pos;i--)
					{
						arr[i+1]=arr[i];
					}
					arr[pos] = elem;
					n++;
				}
				break;
				case 2:
					printf("enter the position to delete:");
					scanf("%d",&pos);
					if(pos < 0 || pos >= n)
					{
						printf("invalid position!please enter position between o to %d\n",n-1);
					}
					else
					{
						for(i=pos;i<n-1;i++)
						{
							arr[i] = arr[i+1];
						}
						n--;
					}
					break;
					case 3:
						printf("the elements of the array are:");
						for(i=0;i<n;i++)
						{
							printf("%d",arr[i]);
						}
						printf("\n");
						break;
						case 4:
							printf("exiting the program...\n");
							exit(0);
							default:
								printf("invalid choice! please choose between 1 to 4.\n");
								break;
		}
	}
	return 0;
}
