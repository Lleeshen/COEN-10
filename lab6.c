//Surf Lesson program created by Lyman Shen at 10/27/16

#include <stdio.h>

int
main(void)
{
	int count=0;
	int lessons[5] = {0,0,0,0,0};
	int options;
	int timec;
	int i;
	const int SIZE = 5;

	while(1)
	{
		printf("Enter 1 to request a lesson, 2 to cancel a lesson, 3 to list all lessons, or 9 to quit.\n");
		scanf("%d",&options);
		switch(options)
		{
			case 1:
				for(i=0; i<SIZE; i++)
        			{
                			if(lessons[i] == 0)
                			{
                        			lessons[i] = i + 1;
                        			printf("You signed up for the lesson at %dpm.\n",lessons[i]);
                        			count++;
                        			break;
                			}
        			}
        			if (i == SIZE)
                			printf("All lessons are full today, check back tomorrow.\n");
				break;
			case 2:
				printf("Which lesson do you want to cancel? Please write the time.\n");
        			scanf("%d",&timec);
        			if(0 > timec || 6 < timec)
        			{
                			printf("Lessons are unavailible at this time.\n");
        			}
        			else if(lessons[timec - 1] == 0)
        			{
                			printf("There are no lessons signed up at this time.\n");
        			}
        			else
        			{
                			lessons[timec - 1] = 0;
                			printf("You have successfully cancelled the lessson at %dpm.\n",timec);
               				count--;
        			}
				break;
			case 3:
				printf("Here is list of the instructor's lessons.\n");
        			printf("He currently has %d lessons signeed up.\n",count);
        			for(i=0; i<SIZE; i++)
        			{
                			if(lessons[i] == 0)
                			{
                        			printf("There is no lessons signed up for %dpm.\n",i+1);
                			}
                			else
                			{
                			        printf("There is a lesson signed up for %dpm.\n",i+1);
              				}
        			}
				break;
			case 9:
				return 0;
			default :
				printf("Please enter the number 1,2,3, or 9.\n");
		}
		printf("Thank you for using this service.\n");
	}
}
