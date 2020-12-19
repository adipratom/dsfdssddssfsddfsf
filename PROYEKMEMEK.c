#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

#define SIZE 1000

int  password();
void addReview();
void searchMovie();
void editpassword();
void deleteReview();
void mainMenu();
void movieRank();
int welcomeScreen();
void swap();
void arrowHere();
void rateandtitlelist();

struct reviewMovie              //menggunakan modul struct
{
    char title[50];
    char year[5];
    char genre[50];
    char rate[5];
    char synopsis[500];
    char review[1000];
    char casts[100];
};

struct reviewMovie film;

int i;

int main()
{
    welcomeScreen();
    mainMenu();
    return 0;
}

void mainMenu()
{
    system("cls");
    int ch,d; 
    char choice;

    choice=password();

    if(choice==1)
    {
        exit (0);
    }

    do
    {
        printf("                              _.-.  \n");
        printf("                         /  99\\n");
        printf("                        (      `\\n");
        printf("                        |\\ ,  ,|\n");
        printf("                __      | \\____/\n");
        printf("          ,.--`-..   /   `---'\n");
        printf("      _.-'          '-/      |\n");
        printf("  _.-   |   '-.             |_/_\n");
        printf(",__.-'  _,.--\\      \\      ((    /-\\n");
        printf("',_..--'      `\\     \\      \\_ /\n");
        printf("            `-,   )      |\' \n");
        printf("              |   |-.,, (  \n");
        printf("              |   |   `\\   `',_\n");
        printf("              )    \\    \\,(\\(\\-'\n");
        printf("              \\     `-,_\n");
        printf("               \\_(\\-(\\`-`\n");
        printf("                  "  "\n");

        
        printf("                    o \n");
        printf("       o       / \n");
        printf("       \\     / \n");
        printf("        \\   / \n");
        printf("         \\ / \n");
        printf("+--------------v-------------+ \n");
        printf("|  __________________      @ | \n");
        printf("| /                  \\       | \n");
        printf("| |                  |  (\\)  | \n");
        printf("| |                  |       | \n");
        printf("| |                  |  (-)  | \n");
        printf("| |                  |       | \n");
        printf("| \\                   / :|||: | \n");
        printf("|  -ooo--------------  :|||: | \n");
        printf("+----------------------------+ \n");
        printf("   []                    [] \n");


        printf("\n\n\t***********************************\n");
        printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");
        printf("\t***********************************");
        
        while(1)
        {
            printf("\n\n\t\tMAIN MENU:");
            printf("\n\n[1]\tAdd Review");
            printf("\n[2]\tSearch Movie");
            printf("\n[3]\tMovie Ranking");
            printf("\n[4]\tDelete Review");
            printf("\n[5]\tExit");
            printf("\n\n\tENTER YOUR CHOICE:");
            scanf("%d",&ch);
            
            switch(ch)
            {
            case 1:
                addReview();
                break;
            case 2:
                searchMovie();
                break;
            case 3:
                movieRank();
                break;
            case 4:
                deleteReview();
                break;
            case 5:
                printf("\n\n\t\tTHANK YOU FOR USING THIS PROGRAM ");
                getch();
                exit(0);

            default:
                printf("\nYOU ENTERED WRONG CHOICE..");
                printf("\nPRESS ANY KEY TO TRY AGAIN");
                getch();
                break;
            }

            system("cls");
        }
    }
    while(choice=='Y'||choice=='y');
}

int welcomeScreen()
{
    system("cls");

    int position = 1, keypress = 0;

    printf(" ________   _______    ________   ________   ________   ________    ________   ___                                                  \n");        
    printf("|\\   __  \\ |\\  ___ \\  |\\   __  \\ |\\   ____\\ |\\   __  \\ |\\   ___  \\ |\\   __  \\ |\\  \\                                 \n");  
    printf("\\ \\  \\|\\  \\\\ \\   __/| \\ \\  \\|\\  \\\\ \\  \\___|_\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\\\ \\  \\|\\  \\\\ \\  \\              \n"); 
    printf(" \\ \\   ____\\\\ \\  \\_|/__\\ \\   _  _\\\\ \\_____  \\\\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\\\ \\   __  \\\\ \\  \\                 \n"); 
    printf("  \\ \\  \\___| \\ \\  \\_|\\ \\\\ \\  \\\\  \\|\\|____|\\  \\\\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\\\ \\  \\ \\  \\\\ \\  \\____      \n"); 
    printf("   \\ \\__\\     \\ \\_______\\\\ \\__\\\\ _\\  ____\\_\\  \\\\ \\_______\\\\ \\__\\\\ \\__\\\\ \\__\\ \\__\\\\ \\_______\\         \n");
    printf("    \\|__|      \\|_______| \\|__|\\|__||\\_________\\\\|_______| \\|__| \\|__| \\|__|\\|__| \\|_______|                            \n");
    printf("                     _____ ______   \\|_________|___      ___  ___   _______                                                        \n");
    printf("                    |\\   _ \\  _   \\ |\\   __  \\ |\\  \\    /  /||\\  \\ |\\  ___ \\                                             \n");
    printf("                    \\ \\  \\\\\\__\\ \\  \\\\ \\  \\|\\  \\\\ \\  \\  /  / /\\ \\  \\\\ \\   __/|                                  \n");
    printf("                     \\ \\  \\\\|__| \\  \\\\ \\  \\\\\\  \\\\ \\  \\/  / /  \\ \\  \\\\ \\  \\_|/__                                \n");
    printf("                      \\ \\  \\    \\ \\  \\\\ \\  \\\\\\  \\\\ \\    / /    \\ \\  \\\\ \\  \\_|\\ \\                              \n");
    printf("                       \\ \\__\\    \\ \\__\\\\ \\_______\\\\ \\__/ /      \\ \\__\\\\ \\_______\\                                  \n");
    printf("                 ___ \\|__|_____\\|__|_\\|_______|_\\|__|/  ______\\|__| \\|_______| ___                                         \n");
    printf("                |\\  \\ |\\   __  \\ |\\  \\|\\  \\ |\\   __  \\ |\\   ___  \\ |\\   __  \\ |\\  \\                              \n");
    printf("                \\ \\  \\\\ \\  \\|\\  \\\\ \\  \\\\\\  \\\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\\\ \\  \\|\\  \\\\ \\  \\            \n");
    printf("              __ \\ \\  \\\\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\   _  _\\\\ \\  \\\\ \\  \\\\ \\   __  \\\\ \\  \\              \n");
    printf("             |\\  \\\\_\\  \\\\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\  \\\\  \\|\\ \\  \\\\ \\  \\\\ \\  \\ \\  \\\\ \\  \\____   \n");
    printf("             \\ \\________\\\\ \\_______\\\\ \\_______\\\\ \\__\\\\ _\\ \\ \\__\\\\ \\__\\\\ \\__\\ \\__\\\\ \\_______\\         \n");
    printf("              \\|________| \\|_______| \\|_______| \\|__|\\|__| \\|__| \\|__| \\|__|\\|__| \\|_______|                           \n\n");
    printf("            ------      P R E S S     A N Y T H I N G     T O     C O N T I N U E    ------                                  \n");
    getch();
    system("cls");

    while(keypress != 13)
    {
        system("cls");
        printf("               Welcome to your Personal Movie Journal\n\n");
        arrowHere(1, position);printf("     Input Password to Continue\n");
        arrowHere(2, position);printf("         Set Up Password\n");
        arrowHere(3, position);printf("               EXIT\n");

        keypress = getch();

        if( keypress == 80 && position != 3)
        {
            position++;
        }
        else if( keypress == 72 && position != 1)
        {
            position--;
        }
        else
        {
            position=position;
        }
    }

    switch(position)
    {
        case 1:
            system("cls");
            mainMenu();
            break;
        case 2:
            system("cls");
            editpassword();
            break;
        case 3:
            system("cls");
            printf("Bye-Bye! Thankyou for using the program!");
            return 0;
            break;
    }
}

void arrowHere(int realPosition, int arrowPosition)
{
    if(realPosition == arrowPosition)
    {
        printf("               o>");
    }
    else
    {
        printf("                 ");
    }
}

void addReview()
{ 
    system("cls");
    FILE *fp ;  //menggunakan modul pointer

    char another = 'Y' ,title[50];
    struct reviewMovie e;
    char filename[30], *movietitle;
    int choice;

    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE REVIEW MENU! *");
    printf("\n\t\t***************************\n\n");

    printf("\n\n\tEnter The Movie's Name >> ");

    fflush(stdin);

    movietitle=gets(filename);

    fp = fopen (strcat(movietitle, ".txt") , "a");

    if ( fp == NULL )
    {
        fp=fopen (strcat(movietitle, ".txt") , "w");
        if(fp==NULL)
        {
            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
        }
    }

        choice=0;
        fflush(stdin);
        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)
        {
            if(strcmp(e.title,title)==0)
            {
                printf("\n\tThe Review Already Exists.\n");
                choice=1;
            }
        }

        if(choice==0)
        {
            strcpy(e.title,movietitle);

            fflush(stdin);
            printf("\tRating:");
            fwrite(gets(e.rate), sizeof (e.rate), 1 ,fp);
            strcpy(film.rate, e.rate);
            rateandtitlelist(film,e.title);

            fflush(stdin);
            printf("\tYears:");
            fwrite(gets(e.year), sizeof (e.year), 1 ,fp);

            fflush(stdin);
            printf("\tGenre:");
            fwrite(gets(e.genre), sizeof (e.genre), 1 ,fp);

            fflush(stdin);
            printf("\tCasts:");
            fwrite(gets(e.casts), sizeof (e.casts), 1 ,fp);

            fflush(stdin);
            printf("\tSynopsis:");
            fwrite(gets(e.synopsis), sizeof (e.synopsis), 1 ,fp);

            fflush(stdin);
            printf("\tReview:");
            fwrite(gets(e.review), sizeof (e.review), 1 ,fp);

            printf("\nYOUR RECORD IS ADDED...\n");
        }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}

void rateandtitlelist(struct reviewMovie e, char*filmname)
{
    FILE *fp;
    fp=fopen ("MOVIE LIST AND NAME.txt" , "a+");
    fprintf(fp, "%s \t %s\n\n", e.rate, filmname);
    fclose(fp);
}

void searchMovie()
{
    FILE *fpsearch ;
   
    system("cls");

    struct reviewMovie movie ;
    char time[6],filename[30];
    int ch;
    char *title;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE VIEWING MENU *");
    printf("\n\t\t*******************************\n\n");

    printf("\n\tEnter the name of the Movie >> ");

    fflush(stdin);

    title=gets(filename);

    fpsearch = fopen (strcat(title, ".txt") , "a+");

    if ( fpsearch == NULL )
    {
        puts ( "\nSorry, no results found\n" ) ;
        printf("Press any key to back...");
        getch();
        return ;
    }
    
    printf("\n!! %s Review !!",filename);
    
    //menggunakan modul searching
    printf("\n"); 
    fread ( &movie.rate, sizeof ( movie.rate ), 1, fpsearch );
    printf("\nRating   : %s",movie.rate);
    fread ( &movie.year, sizeof ( movie.year ), 1, fpsearch );
    printf("\nYears    : %s",movie.year);
    fread ( &movie.genre, sizeof ( movie.genre ), 1, fpsearch );
    printf("\nGenre    : %s",movie.genre);
    fread ( &movie.casts, sizeof ( movie.casts ), 1, fpsearch );
    printf("\nCasts    : %s",movie.casts);
    fread ( &movie.synopsis, sizeof ( movie.synopsis ), 1, fpsearch );
    printf("\nSynopsis : %s",movie.synopsis);
    fread ( &movie.review, sizeof ( movie.review ), 1, fpsearch );
    printf("\nReview   : %s", movie.review);    
  
    printf("\n");       
    
    printf("\nPRESS ANYTHING TO GO BACK TO MENU");
    getch();
    return;
}

int password()
{
    char pass[40]= {0},check[40]= {0},ch;
    FILE *fpp;
    int i=0, j, d;

    printf("Please enter your password to continue . . .");
    printf("\nYou have maximum of 3 tries");

    for(j=0; j<3; j++)
    {
        i=0;
        printf("\n\n\tENTER THE PASSWORD:");
        pass[0]=getch();
        while(pass[i]!='\r')
        {
            if(pass[i]=='\b')
            {
                i--;
                printf("\b");
                printf(" ");
                printf("\b");
                pass[i]=getch();
            }
            else
            {
                printf("*");
                i++;
                pass[i]=getch();
            }
        }

        pass[i]='\0';

        fpp=fopen("PASSWORD","r");

        if (fpp==NULL)
        {
            printf("\n!!! ERROR ERROR ERROR !!!\n");
            printf("\n!!! ERROR ERROR ERROR !!!\n");
            printf("\nPASSWORD FILE IS MISSING \n");
            printf("\n!!! ERROR ERROR ERROR !!!\n");    
            printf("\n!!! ERROR ERROR ERROR !!!\n\n\n");
            printf("Press anything to go back . . .");
            getch();
            return 1;
        }

        else
            i=0;
            
        while(1)
        {
            ch=fgetc(fpp);

            if(ch==EOF)
            {
                check[i]='\0';
                break;
            }

            check[i]=ch-5;
            i++;
        }

        if(strcmp(pass,check)==0)
        {
            printf("\n\n\tACCESS GRANTED...\n");
            return 0;
        }

        else
        {
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
            printf("\t    ");
            for(d=0;d<3;d++)
            {
                printf(".");
                Sleep(450);
            }
            system("cls");
        }
    }

    printf("\n\n\t<< Your login trial has ran out >>");
    printf("\n\t<< PRESS ANY KEY TO GO BACK... >>\n");

    getch();
    system("cls");
    return 1;
}

void editpassword()
{

    system("cls");
    printf("\n");

    char pass[40]= {0},confirm[40]= {0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("PASSWORD","r");

    if(fp==NULL)
    {
        fp=fopen("PASSWORD","w");

        if(fp==NULL)
        {
            system("cls");
            printf("\nSYSTEM ERROR... PASSWORD HASNT BEEN SET UP");
            printf("\nPRESS ANYTHING TO CHANGE PASSWORD\n\n");
            getch();
            return ;   
        }

        fclose(fp);

        printf("\nPRESS ANYTHING TO CHANGE PASSWORD\n\n");
        getch();
    }

    fclose(fp);

    check=password();

    if(check==1)
    {
        return ;
    }

    do
    {
        if(check==0)
        {
            i=0;
            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);
            pass[0]=getch();

            while(pass[i]!='\r')
            {
                if(pass[i]=='\b')
                {
                    i--;

                    printf("\b");
                    printf(" ");
                    printf("\b");

                    pass[i]=getch();
                }

                else
                {

                    printf("*");
                    i++;
                    pass[i]=getch();
                }
            }

            pass[i]='\0';
            i=0;

            printf("\n\tCONFIRM PASSWORD:");
            confirm[0]=getch();
            
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;

                    printf("\b");
                    printf(" ");
                    printf("\b");

                    confirm[i]=getch();
                }

                else
                {
                    printf("*");
                    i++;
                    confirm[i]=getch();
                }
            }
            confirm[i]='\0';
            if(strcmp(pass,confirm)==0)
            {
                fp=fopen("PASSWORD","w");
                if(fp==NULL)
                {
                    printf("\n\t\tSYSTEM ERROR");
                    getch();
                    return ;
                }
                i=0;
                while(pass[i]!='\0')
                {
                    ch=pass[i];
                    putc(ch+5,fp);
                    i++;
                }
                putc(EOF,fp);
                fclose(fp);
            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                choice=1;
            }
        }
    }
    while(choice==1);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
    welcomeScreen();
}

void deleteReview()
{
    system("cls");
    FILE *fp,*fptr ;
    struct reviewMovie file ;
    char filename[30],another = 'Y' ,time[10];;
    int choice,check;
    printf("\n\n\t\t*************************\n");
    printf("\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t*************************\n\n");
    printf("\n\tENTER THE MOVIE TO DELETE THE REVIEW : ");
    fflush(stdin);
        gets(filename);
        fp = fopen (filename, "w" ) ;
        if ( fp == NULL )
        {
            printf("\nTHE FILE DOES NOT EXISTS");
            printf("\nPRESS ANY KEY TO GO BACK.");
            getch();
            return ;
        }
        fclose(fp);
        remove(filename);
        printf("\nDELETED SUCCESFULLY...");
        

    while(choice<1||choice>2);
    printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
    fflush(stdin);
    scanf("%c",&another);


    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}

void movieRank(){
    char *strFileName = "MOVIE LIST AND NAME.txt";
    char *strFileSummary = "SORTED LIST.txt";
    char strTempData[100], displaysorting[100];
    char **strData = NULL; // String List
    int i, j, a;
    int noOfLines = 0;

    FILE * ptrFileLog = NULL;
    FILE * ptrSummary = NULL;
    FILE * sortDisplay; 

    if ( (ptrFileLog = fopen(strFileName, "r")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n", strFileName);
        
    }
    if ( (ptrSummary = fopen(strFileSummary, "w")) == NULL ) {
        fprintf(stderr,"Error: Could not open %s\n", strFileSummary);
    }

    // Read and store in a string list.
    while(fgets(strTempData, 100, ptrFileLog) != NULL) {
        // Remove the trailing newline character
        if(strchr(strTempData,'\n'))
            strTempData[strlen(strTempData)-1] = '\0';
        strData = (char**)realloc(strData, sizeof(char**)*(noOfLines+1));
        strData[noOfLines] = (char*)calloc(100,sizeof(char));
        strcpy(strData[noOfLines], strTempData);
        noOfLines++;
    }
    // Sort the array.
    for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(strcmp(strData[j], strData[j+1]) < 0) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    // Write it to outfile. file.
    for(i = 0; i < noOfLines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);
    // free each string
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
    // free string list.
    free(strData);
    fclose(ptrFileLog);
    fclose(ptrSummary);

    system("cls");
    printf("Here's Top 5 Movie list by rating and title\n");
    printf("Rating \t Title\n");
    printf("-------------------------\n");

    sortDisplay = fopen("MOVIE LIST AND NAME.txt", "r");
    while(fgets(displaysorting, MAXCHAR, sortDisplay))
    {
        a++;
        if(a == 5)
        {
            break;
        }
        printf("  %s", displaysorting);
    }

    printf("\n\nPress anything to go back...");
    getch();
}

//     for(i=0; i< SIZE; i++){
//         for(j=0; j<SIZE-i-1; j++){
//             if(rate[j]>rate[j+1]){
//                 swap = rate[j];
//                 rate[j] = rate[j+1];
//                 rate[j+1] = swap;
//             }
//         }
//     }

//     printf("Sorted movie by rating");
//     for(i=0; i<SIZE; i++){
//         printf("%d. %s (%s)", i+1, e.title, e.rate);
//     }
// }
