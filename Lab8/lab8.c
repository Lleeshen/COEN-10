//New Surf Lesson program created by Lyman Shen at 11/10/16

#include <stdio.h>
#include <string.h>

int count = 0;
char lessons[5][20];
char rnumbers[5][20];
int rsize[5] = {0,0,0,0,0};
const int SIZE = 5;
void request(void);
void cancel(void);
void list(void);
void letter(void);
void group(void);

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
        printf("Enter 1 to request a lesson, 2 to cancel a lesson, 3 to list lessons, 4 to list names starting with a letter, 5 to list reservations of a group size, or 9 to quit.\n");
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
                list();
                break;
            case 4:
                //List names starting with character
                letter();
                break;
            case 5:
                //List reservations with group size
                group();
                break;
            case 9:
                //End program
                return 0;
            default:
                printf("Please enter the number 1, 2, 3, 4, 5, or 9.\n");
        }
    }
}

//Request lesson
void request(void)
{
    int i;
    char user[20];
    char usernumber[20];
    int groupsize;
    //Check if lesson slots are full
    if(count == SIZE)
    {
        printf("All lessons are full today, check back later.\n");
    }
    else
    {
        //Add new lesson with name input in next slot
        i=count-1;
        printf("What is the name?\n");
        scanf("%s",&user);
        //Tell user if name is taken, change name if so
        if(count != 0)
        {
            i=0;
            while(i<count)
            {
                if(strcmp(user,lessons[i]) == 0)
                {
                    printf("The name is taken, choose a different one.\n");
                    scanf("%s",&user);
                    i=0;
                }
                else
                {
                    i++;
                }
            }
        }
        //Proceed if name is availible
        strcpy(lessons[count],user);
        //Put phone number in array
        printf("What is the phone number?\n");
        scanf("%s",&usernumber);
        strcpy(rnumbers[count],usernumber);
        //Put group size in array
        do
        {
            printf("What is the size of group? Please let the size be between 1 and 4.\n");
            scanf("%d",&groupsize);
            rsize[count] = groupsize;
            //Ensure size is between 1 and 4
        } while (groupsize < 1 || groupsize > 4);
        printf("%s has successfully signed up for a lesson at %d pm.\n",user,count+1);
        count++;
        return;
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
        printf("There are no lessons reserved.\n");
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
                printf("Message to %s : %s has successfully cancelled the lesson at %d pm.\n",rnumbers[i],user,i+1);
                lessons[i][0] = '\0';
                rnumbers[i][0] = '\0';
                rsize[i] = 0;
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
                strcpy(rnumbers[i],rnumbers[i+1]);
                rsize[i] = rsize[i+1];
                printf("Message to %s :The lesson under %s has been moved from %d pm to %d pm.\n",rnumbers[i],lessons[i],i+2,i+1);
            }
            lessons[i][0] = '0';
        }
    }
    return;
}

//List all lessons
void list(void)
{
    int i;
    printf("There are currently %d lessons signed up.\n",count);
    //List of lessons that are signed up
    for(i=0;i<count;i++)
    {
        printf("%s with number %s has reserved for a lesson at %d pm with group size %d.\n",lessons[i],rnumbers[i],i+1,rsize[i]);
    }
    //List of lessons that are not signed up
    for(i=count;i<SIZE;i++)
    {
        printf("Free at %d pm.\n",i+1);
    }
    return;
}

//List reservation names starting with a letter
void letter(void)
{
    char namel;
    int i;
    //Check if there are any lessons signed up, end if there is none
    if (count == 0)
    {
        printf("There are no lessons signed up.\n");
        return;
    }
    //Input starting character
    printf("What does the name start with?\n");
    scanf(" %c",&namel);
    //Search through lessons for name that start with character
    for(i=0;i<SIZE;i++)
    {
        if(lessons[i][0] == namel)
        {
            printf("%s has reserved a lesson with a group of %d at %d pm.\n",lessons[i],rsize[i],i+1);
        }
    }
    return;
}

//List reservations with a group size
void group(void)
{
    int groupsize;
    int i;
    //Check if there are any lessons signed up, end if there is none
    if (count == 0)
    {
        printf("There are no lessons signed up.\n");
        return;
    }
    do {
        printf("What is the group size? All sizes are between 1 and 4.\n");
        scanf("%d",&groupsize);
        //Make sure checking group size between 1 and 4
    } while (groupsize < 1 || groupsize > 4);
    for(i=0;i<count;i++)
    {
        //Show all reservations with matching group size
        if(groupsize == rsize[i])
        {
            printf("%s has a reservation of size %d at %d pm.\n",lessons[i],groupsize,i+1);
        }
    }
    return;
}