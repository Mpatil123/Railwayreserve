#include <stdio.h>
#include<string.h>

struct player
{
    char name[20],country[20],category[20];
    int age;
    int avgbs;
    int now,t20,odi;
}p[10];

void accept(int n)
{
   for(int i=0;i<n;i++)
   {
       printf("\nEnter details of player %d\n",(i+1));
       printf("Enter the name ");
       scanf(" %[^\n]%*c",p[i].name);
       printf("\nEnter the country ");
       scanf(" %[^\n]%*c",p[i].country);
       printf("\nEnter the category ");
       scanf(" %[^\n]%*c",p[i].category);
       if(strcmp(p[i].category,"batsman")==0||strcmp(p[i].category,"all rounder")==0)
       {
           printf("\nEnter the average batting score ");
           scanf("%d",&p[i].avgbs);
       } 
       if(strcmp(p[i].category,"bowler")==0||strcmp(p[i].category,"all rounder")==0)
       {
           printf("\nEnter the no. of wickets taken ");
           scanf("%d",&p[i].now);
       }
       printf("\nEnter the age ");
       scanf("%d",&p[i].age);
       printf("\nEnter the no. of T20s played ");
       scanf("%d",&p[i].t20);
       printf("\nEnter the no. of ODIs played ");
       scanf("%d",&p[i].odi);

   }
}

void display(int n)
{
    for(int i=0;i<n;i++)
   {
       printf("\n----------------------------------------");
       printf("\nDetails of player: %d \n",(i+1));
       printf("\nName: %s",p[i].name);
       printf("\nCountry: %s",p[i].country);
       printf("\nCategory: %s",p[i].category);
       printf("\nAge: %d",p[i].age);
       printf("\nNo. of T20s played: %d",p[i].t20);
       printf("\nNo. of ODIs played: %d",p[i].odi);
   }
}

void nob(char c[],int n)
{
    int t=0;
    for(int i=0;i<n;i++)
    {
        if((strcmp(p[i].country,c)==0)&&(strcmp(p[i].category,"batsman")==0))
           t++;
        else if((strcmp(p[i].country,c)==0)&&(strcmp(p[i].category,"all rounder")==0))
           t++;   
    }
    printf("\nThe number of batsman of %s are %d ",c,t);
}

void noB(char c[],int n)
{
    int t=0;
    for(int i=0;i<n;i++)
    {
        if((strcmp(p[i].country,c)==0)&&(strcmp(p[i].category,"bowler")==0))
           t++;
        else if((strcmp(p[i].country,c)==0)&&(strcmp(p[i].category,"all rounder")==0))
           t++;
    }
    printf("\nThe number of bowler of %s are %d ",c,t);
}

void sort(int n)
{
   int  max;
 
   char temp[100];
   int tem=0;
   int t=0;
    for (int i = 0; i < n-1; i++)
    {
    
        max = i;
        for (int j = i+1; j < n; j++)
          if (p[j].avgbs > p[max].avgbs)
            max = j;

tem=p[max].avgbs;
p[max].avgbs=p[i].avgbs;
p[i].avgbs=tem;
  strcpy(temp, p[max].name);
  strcpy(p[max].name,p[i].name);
  strcpy(p[i].name,temp);
t=p[max].age;
p[max].age=p[i].age;
p[i].age=t;
  strcpy(temp, p[max].country);
  strcpy(p[max].country,p[i].country);
  strcpy(p[i].country,temp);
    strcpy(temp, p[max].category);
  strcpy(p[max].category,p[i].category);
  strcpy(p[i].category,temp);
   t=p[max].now;
p[max].now=p[i].now;
p[i].now=t;
   t=p[max].t20;
   p[max].t20=p[i].t20;
   p[i].t20=t;
   t=p[max].odi;
   p[max].odi=p[i].odi;
   p[i].odi=t;
    }
 printf("\nName\tCountry\tCategory\tAge\tWickets\tBat. avg.\tT20s\tODIs");
for(int i=0;i<n;i++)
{
  printf("\n%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].name,p[i].country,p[i].category,p[i].age,p[i].now,p[i].avgbs,p[i].t20,p[i].odi);
}

}  

void highage(int n)
{
    int h=0;
    int high=p[0].age;
    for(int i=0;i<n;i++)
        if(p[i].age>high&&strcmp(p[i].category,"batsman")==0)
            h=i;
    printf("\nThe details of batsman are ");
    printf("\nName\tCountry\tCategory\tAge\tWickets\tBat. avg.\tT20s\tODIs");
    printf("\n%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[h].name,p[h].country,p[h].category,p[h].age,p[h].now,p[h].avgbs,p[h].t20,p[h].odi);
}

void highwic(int n)
{
    int h=0;
    int high=p[0].now;
    for(int i=0;i<n;i++)
        if(p[i].now>high)
            h=i;
    printf("\nThe details of bowler are ");
    printf("\nName\tCountry\tCategory\tAge\tWickets\tBat. avg.\tT20s\tODIs");
    printf("\n%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[h].name,p[h].country,p[h].category,p[h].age,p[h].now,p[h].avgbs,p[h].t20,p[h].odi);
}

void dispinfo(char nm[],int n)
{
  int t=0;
  for(int i=0;i<n;i++)
    if(strcmp(nm,p[i].name)==0)
    {
         printf("\nName\tCountry\tCategory\tAge\tWickets\tBat. avg.\tT20s\tODIs");
         printf("\n%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].name,p[i].country,p[i].category,p[i].age,p[i].now,p[i].avgbs,p[i].t20,p[i].odi);
         t=1;
         break;
    }      
    if(t==0)
       printf("\nPlayer not found");
}
int main()
{
    int n;
    int op;
   char c[20];
    printf("\nEnter the number of players ");
    scanf("%d",&n);
    accept(n);
    while(1)
    {
       printf("\n-------------------------------------------------------------------\n");
    printf("\nEnter 1 to find the number of batsman of a particular country");
    printf("\nEnter 2 to find the number of bowler of a particular country");
    printf("\nEnter 3 to print sorted list acc. to avg. batting scores");
    printf("\nEnter 4 to print batsman with highest age");
    printf("\nEnter 5 to print bowler who has taken highest no. of wickets");
    printf("\nEnter 6 to print particular player's entire diplay board information ");
    printf("\nEnter 0 to exit\n");
    
    printf("\nEnter choice ");
    scanf("%d",&op);
    switch(op)
    {
        case 0:
           printf("\nThank you ");
           return 0;
        case 1:
           printf("\nEnter the country name (case sensitive) ");
           scanf(" %[^\n]%*c",c);
           nob(c,n);
           break;
        case 2:
           printf("\nEnter the country name in (case sensitive) ");
           scanf(" %[^\n]%*c",c);
           noB(c,n);
           break;
        case 3:
           sort(n);
           break;
        case 4:
           highage(n);
           break;
        case 5:
           highwic(n);
           break;
        case 6:
           printf("\nEnter the name of player ");
           char nm[100];
           scanf("%s",nm);
           dispinfo(nm,n);
           break;

        default:
           printf("\nEnter valid choice");
    }
    
    }
    return 0;
}
