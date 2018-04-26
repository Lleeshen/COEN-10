#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int
main(void)
{
	int i;
	int randnum1;
	int randnum2;
	int result;
	int correct;
	int counter = 0;

	srand((int)time(NULL));
	for(i=0;i<10;i++)
	{
		randnum1 = rand()%13;
		randnum2 = rand()%13;
		correct = randnum1 * randnum2;
		printf("What is %d times %d ?\n",randnum1,randnum2);
		scanf("%d",&result);
		if(correct == result)
		{
			printf("You got the question correct.\n");
			counter++;
		}
		else
		{
			printf("The correct answer is %d. \n",correct);
		}
	}
	counter *= 10;
	printf("You got %d percent correct!\n",counter);
	return 0;
}
