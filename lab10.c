//New Word Manipulation program created by Lyman Shen at 12/01/16

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int SIZE = 20;
char words[10][SIZE];
int length[10] = {0,0,0,0,0,0,0,0,0,0};
int numwords = 0;

void input(void);
void reverse(void);
void uppercase(void);
void info(void);
void output(void);

int main(void)
{
    input();
    reverse();
    uppercase();
    info();
    return 0;
}

//Get up to 10 words as input, put them in alphaetical order
void input(void)
{
    int i,j,k;
    char temp[SIZE];
    //Input words
    for(i=0;i<10;i++)
    {
        scanf("%s",words[i]);
        if(words[i][0] != '\0')
            numwords++;
    }
    fflush(stdin);
    //Put in alphabetical order
    for(i=0;i<numwords;i++)
    {
        for(j=i+1;j<numwords;j++)
        {
            //Move everything below current leetter if letter goes before current
            strcpy(temp,words[j]);
            if(strcasecmp(words[i],words[j]) > 0)
            {
                for(k=j;k>i;k--)
                {
                    strcpy(words[k],words[k-1]);
                }
                strcpy(words[i],temp);
            }
        }
    }
    printf("Here are your words in alphabetical order.\n");
    output();
    return;
}

//Reverse the order of the array
void reverse(void)
{
    //Define first and last index
    int i = 0;
    int j = numwords -1;
    char temp[SIZE];
    //Swap array represented indices, move "front index" up 1 and "end index" down 1
    while(i<j)
    {
        strcpy(temp,words[i]);
        strcpy(words[i],words[j]);
        strcpy(words[j],temp);
        i++;
        j--;
    }
    printf("Here are your words in reverse order.\n");
    output();
    return;
}

//Convert lower case letters to upper case and put length of words in length array
void uppercase(void)
{
    char *p;
    int i;
    //Check for each array
    for(i=0;i<numwords;i++)
    {
        //Check for every character
        p = words[i];
        while(*p != '\0')
        {
            //Convert lowercase letters to upper case
            if(islower((int)*p))
            {
                *p = toupper((int)*p);
            }
            p++;
        }
        //Put lengths in length array
        length[i] = strlen(words[i]);
    }
    printf("Here are your words in upper case.\n");
    output();
    return;
}

//Show longest word, shortest word, average length of word, words that do not start with letter
void info(void)
{
    int shortest = 0;
    int longest = 0;
    int average = 0;
    //flags for nonletter
    int nonletter[10] = {0,0,0,0,0,0,0,0,0,0};
    int i=0;
    //Go through arrays
    while(i<numwords)
    {
        //update "sum"
        average += length[i];
        //flag for nonletter
        if(! isalpha((int) words[i][0]))
            nonletter[i] = 1;
        //check for max length
        if(length[i] > length[longest])
            longest = i;
        //check for min length
        else if(length[i] < length[shortest])
            shortest = i;
        i++;
    }
    average /= numwords;
    printf("\n");
    printf("The longest word is %s.\n",words[longest]);
    printf("The shortest word is %s.\n",words[shortest]);
    printf("The average word length is %d.\n",average);
    printf("The following words do not start with a letter.\n");
    for(i=0;i<10;i++)
    {
        if(nonletter[i] == 1)
            printf("%s\n",words[i]);
    }
    return;
}

//Output the string array
void output(void)
{
    //print every string
    int i;
    for(i=0;i<numwords;i++)
    {
        printf("%s\n",words[i]);
    }
    return;
}
