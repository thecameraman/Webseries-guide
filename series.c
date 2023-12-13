#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void insert();
void display();
void sort();

struct webseries
{
    char name[50];
    char desc[200];
    float rating;
} d;

void main()
{
    int choice;
    char again;
    do
    {
        printf("\n________________________________\n");
        printf("\t WebSeries Guide");
        printf("\n________________________________\n");
        printf("1. Insert New Series \n2. Display Series \n3. Sort the Series According to Rating(highest rating) \n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: insert();
            break;

            case 2: display();
            break;

            case 3: sort();
            break;

            default: printf("wrong choice");
            break;
        }
        printf("\n Do You Want to Continue? (y/n)");
        scanf("%1s",&again);

    } while (again == 'y' || again == 'Y');
    getch();
}
void insert()
{
    FILE *fp;
    fp=fopen("series.txt","a");

    getchar();
    printf("Enter the details..\n\nSeries name:-\t");
    gets(d.name);
     printf("Description:-\t");
    gets(d.desc);
     printf("Rating:-\t");
	scanf("%f",&d.rating);
    fwrite(&d,sizeof(d),1,fp);
    printf("\nSeries added...");
    fclose(fp);

}
void display() 
{
    FILE *fp;
    int i=1;
    fp=fopen("series.txt","r");

    while(fread(&d,sizeof(d),1,fp))
    {
        printf("^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("%d  %s \n ^^^^^^^^^^^^^^^^^^^^^^^  \nDescription: %s\nRating: %.2f\n\n",i,d.name,d.desc,d.rating);
       
        i++;
    }
    fclose(fp);
}

void sort()
{
    FILE *fp;
    int ch,index=0,i,j;
    struct webseries obj[40],temp;
    
    fp=fopen("series.txt","r");

    while(fread(&d,sizeof(d),1,fp))
    {
        obj[index] = d;
        index++;
    }
    for(i=0;i<index-1;i++)
    {
        for(j=0;j<index-i-1;j++)
        {
            if(obj[j].rating < obj[j+1].rating)
            {
                temp = obj[j];
                obj[j] = obj[j+1];
                obj[j+1] = temp;
            }
        }
    }
    printf("\nSorted series list is..\n");
    for(i=0;i<index;i++)
    {
        printf("\n**********************************\n");
        printf("%d. %s\n",(i+1),obj[i].name);
        printf("\n**********************************\n");
        printf("\nDescription: %s",obj[i].desc);
        printf("\nRating: %.2f",obj[i].rating);
        printf("\n___________________________________\n");
    }
    fclose(fp);
}