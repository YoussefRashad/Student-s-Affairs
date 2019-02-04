#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "affairs.h"


// 23 course ...

struct person P[1000];
//int indexPro=0;


    void StudentControl();
   // float countGpa();



int main()
{
    LoadSystemData();
    int ch=1;
    printf("\n\n\n\n\n\n\t\t\t\t\t  Affairs's Students :)\n");
    printf("\n\t\t\t\t  ====================================\n\n");
    printf("\n\t\t\t\t   Faculty Of Computers & Information\n\t\t\t\t\t   Helwan University \n\t\t\t\t\t      Department\n\t\t\t\t\t        ( SWE ) \n");
    printf("\n\n  Project By : youssef farag Rashad.\n\n\n\n\n");
    system("pause");
    system("cls");
    while(ch!=3){
        printf("\n\n\n\n\t\t\t\t=============================================");
        printf("\n\n\t\t\t\t    ||Welcome To Affairs's Student ...||\n");
        printf("\n\t\t\t\t=============================================\n\n");
        printf("\n\t\t\t\t  #                                      #\n");
        printf("\t\t\t\t  -|==========     Choose     ==========|-\n");
        printf("\t\t\t\t   |                                    |\n");
        printf("\t\t\t\t   |            1: Admin                |\n");
        printf("\t\t\t\t   |            2: Student              |\n");
        printf("\t\t\t\t   |            3: Exit                 |\n");
        printf("\t\t\t\t   |                                    |\n");
        printf("\t\t\t\t  -|==========  *End Choose*  ==========|-\n");
        printf("\t\t\t\t  #                                      #\n");
        printf("\n\n\t\tCh: ");
        scanf("%d",&ch);
        if(ch==1)
            if(CheckEnter()){
                system("cls");
                MainMenu();
            }
            else{
                printf("\n\n\t\t\t\tInvalid authentication ...\n\n");
            }
        if(ch==2)
                StudentControl();
        if(ch == 3){
                printf("\n\n\n\n\n\t\t\t\t #                                  #\n");
            printf("\t\t\t\t -||==============================||-\n");
            printf("\t\t\t\t  ||           Thanks YOU ...     ||\n");
            printf("\t\t\t\t -||==============================||-\n");
            printf("\t\t\t\t#                                   #\n\n\n\n");

            }
            else
                printf( "\n\n\n\t\tInvalid Choice\n\n");
        }

        SaveSystemData();
        system("pause");
        getchar();
        return 0;

}


void StudentControl()
{
    int ch,m;
    printf( "\n\n\n\t$ \t           Student Menu                    $\n\t_|________________________________________________|_\n");
    printf("\t |\t                                          |\n\t |\t1: Search By Student.                     |\n");
    printf("\t |\t2: Display your Grades.                   |\n");
    printf("\t |\t3: Display your Table OF Study.           |\n");
    printf("\t |\t4: Display your Table OF Exam.            |\n");

    printf("\t |\t0: Exit                                   |\n");
    printf( "\t_|________________________________________________|_\n\t$|\t                                          |$\n");
    printf("\n\n\n\tCh: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        m=LocationByID();
        if(m!=-1)
            Display(P[m]);
        else
            printf("Not exist ID ... \n");
        printf("\n\n");
        system("pause");
        StudentControl();
        break;

    case 2:
        m=LocationByID();
        if(m!=-1)
            Display(P[m]);
        else
            printf("Not exist ID ... \n");
        printf("\n\n");
        system("pause");
        StudentControl();

        break;
    case 3:
        DisplayTableOfStudy();
        StudentControl();
        break;
    case 4:

        break;
    }


}




void MainMenu()
{

    int ch,m;

    printf( "\n\n\n\t$ \t           Admin Menu                      $\n\t_|________________________________________________|_\n");

    printf("\t |\t                                          |\n\t |\t1: List all Students.                     |\n\t |\t2: Add new Student.                       |\n\t |\t3: Delete Info. OF Student.               |\n\t |\t4: Search by ID.                          |\n\t |\t5: Search by Name.                        |\n\t |\t6: Update Student info.                   |\n\t |\t7: Update Part OF  info To Student.       |\n\t |\t8: Check Lower Case & Convert To Upper.   |\n\t |\t9: Check Upper Case & Convert To Lower.   |\n\t |\t10: Sort File.                            |\n\t |\t11: Clear All Data in file.               |\n\t |\t12: Student Menu.                         |\n\t |\t0: to Exit                                |\n" );
    printf( "\t_|________________________________________________|_\n\t$|\t                                          |$\n");
    printf( "\t");
    printf("\n\n\t\t *your Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        listAllStudent();
        break;
    case 2:
        AddData();
        break;
    case 3:
        DeleteInfo();
        break;
    case 4:
        m=LocationByID();
        if(m!=-1){
            Display(P[m]);
        }
        else{
            printf("This ID is not find :) \n ");
        }
        printf("\n\n");
        system("pause");
        MainMenu();
        break;
    case 5:
        m=LocationByName();
        if(m!=-1){
            Display(P[m]);
        }
        else{
            printf("This Name is not find :) \n ");
        }
        printf("\n\n");
        system("pause");
        MainMenu();
        break;
    case 6:
        UpdateRow();
        break;
    case 7:
        UpdateElement();
        break;
    case 8:
        CheckSmall();
        break;
    case 9:
        CheckCapital();
        break;
    case 10:
        SortFinalExamData();
        break;
    case 11:
        clearFile();
        system("pause");
        break;
    case 12:
        StudentControl();
        MainMenu();
        break;
    default:
        system("cls");
        break;
    }
    SaveSystemData();
}





