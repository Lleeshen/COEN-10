//New Surf Lesson program created by Lyman Shen at 11/3/16

#include <stdio.h>
#include <string.h>

int count = 0;
char lessons[5][20];
const int SIZE = 5;

//Request lesson
void request(void)
{
    char user[20];
    //Check if lesson slots are full
    if(count == SIZE)
    {
        printf("All lessons are full today, check back later.\n");
    }
    else
    {
        //Add new lesson with name input in next slot
        printf("What is the name?\n");
        scanf("%s",&user);
        strcpy(lessons[count],user);
        printf("%s has successfully signed up for a lesson at %d pm.\n",user,count+1);
        count++;
    }
}

//Cancel lesson
void cancel(void)
{
    int i;
    char user[20];
    //Check is there are lessons
    if(count == 0)
    {
        printf("There are no lessons signed up.\n");
    }
    else
    {
        //Search for lessons with the name
        printf("What name is the lesson under?\n");
        scanf("%s",&user);
        for(i=0;i<count;i++)
        {
            if(strcmp(lessons[i], user) == 0)
            {
                lessons[i][0] = '\0';
		printf("%s has successfully cancelled the lesson at %d pm.\n",user,i+1);
                count--;
                break;
            }
        }
        if(i == count)
        {
            printf("There is no reservation under that name.\n");
        }
        else
        {
            //Shift lessons up so there is no empty slot between lessons
            for(;i<count;i++)
            {
                strcpy(lessons[i],lessons[i+1]);
                printf("The lesson under %s has been moved from %d pm to %d pm.\n",lessons[i],i+2,i+1);
            }
            strcpy(lessons[i],"");
        }
    }
}

//List all lessons
void llist(void)
{
    int i;
    printf("There are currently %d lessons signed up.\n",count);
    //List of lessons that are signed up
    for(i=0;i<count;i++)
    {
        printf("%s has signed up for a lesson at %d pm.\n",lessons[i], i+1);
    }
    //List of lessons that are not signed up
    for(i=count;i<SIZE;i++)
    {
        printf("Nobody signed up for the lesson at %d pm.\n",i+1);
    }
}

//List users starting with a letter
void nlist(void)
{
    int i;
    char namel;
    //Check if there are any lessons signed up
    if (count == 0)
    {
        printf("There are no lessons signed up.\n");
    }
    else
    {
        printf("What does the name start with?\n");
	scanf(" %c",&namel);
        //Search through lessons for name that start with character
        for(i=0;i<SIZE;i++)
        {
            if(lessons[i][0] == namel)
            {
                printf("%s has reserved a lesson.\n",lessons[i]);
            }
        }
    }
}

int main(void)
{
    int i;
    int options;
    //Initialize array of Strings;
    for(i=0;i<SIZE;i++)
    {
        lessons[i][0] = '\0';
    }
    while(1)
    {
        printf("Enter 1 to request a lesson, 2 to cancel a lesson, 3 to list lessons, 4 to list names starting with a letter, or 9 to quit.\n");
        scanf("%d",&options);
        switch(options)
        {
            case 1:
                //Request lesson
                request();
                break;
            case 2:
                //Cancel lesson
                cancel();
                break;
            case 3:
                //List lessons
                llist();
                break;
            case 4:
                //List names starting with character
                nlist();
                break;
            case 9:
                //End program
                return 0;
            default:
                printf("Please enter the number 1, 2, 3, 4, or 9.\n");
        }
    }
}
