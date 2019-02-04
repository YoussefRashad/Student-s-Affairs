#ifndef affairs
#include<ctype.h>

enum CourseName{CS=1, IS , E1 , E2 , HR , IT , Math1 , Math2 , Logic , PL1 , DB1 , DS , Mangement , Pl2 , Ethics , SW1 , Stat1 , DC , Negotiation , OR , OS , stat2 , Compiler };


const int SizeOfCourses=3;

struct course
{
    enum CourseName cName;
    float FinalExam,courseWork,practicalExam;
    float total;
};

struct person
{
    int id;
    char name[50];
    char gender;
    struct course Cdeg[7];
};


struct person P[1000];
int indexPro=0;



void DisplayTableOfStudy()
{
    printf("\n\n\n\t\t$                                                                         $\n");
    printf("\t\t_|_______________________________________________________________________|_\n");
    printf("\t\t | Day  |               Table OF Student To 4 levels                     |\n");
    printf("\t\t |______|________________________________________________________________|\n");
    printf("\t\t | SA   |     CS     |     IS     |     E1     |     E2     |     OS     |\n");
    printf("\t\t |______|____________|____________|____________|____________|____________|\n");
    printf("\t\t | SU   |     HR     |     IT     |   Math1    |   Math2    |     Pl2    |\n");
    printf("\t\t |______|____________|____________|____________|____________|____________|\n");
    printf("\t\t | MO   |   Logic    |     Pl1    |    DB1     |     DS     |    Stat1   |\n");
    printf("\t\t |______|____________|____________|____________|____________|____________|\n");
    printf("\t\t | TU   | Management |     Pl2    |   Ethics   |     SW1    |  Compiler  |\n");
    printf("\t\t |______|____________|____________|____________|____________|____________|\n");
    printf("\t\t | WE   |   Stat1    |     DC     |Negotiation |     OR     |     CS     |\n");
    printf("\t\t |______|____________|____________|____________|____________|____________|\n");
    printf("\t\t | TH   |   Logic    |     SW1    |     IT     |     DC     |     OS     |\n");
    printf("\t\t_|______|____________|____________|____________|____________|____________|_\n");
    printf("\t\t$                                                                         $\n");
    printf("\n\n");
    system("pause");

}

int CheckEnter()
{
    char user[20],pass[20];
    printf("\n\n\n\t\tPlease, press UserName & Password :) ");
    printf("\n\n\tUser Name: ");
    scanf("%s",user);
    printf("\n\tPassword: ");
    scanf("%s",pass);
    if((strcmp(user,"admin")==0)&&(strcmp(pass,"0000")==0))
        return 1;
    else
        return 0;
}




int DisplayCourses(struct person x)
{
    int arr[SizeOfCourses],j,c=0;

    for(j=0;(j<SizeOfCourses)&&(c<SizeOfCourses);j++){
            switch(x.Cdeg[j].cName)
            {
                case 1:
                    arr[c]=1;
                    break;
                case 2:
                    arr[c]=2;
                    break;
                case 3:
                    arr[c]=3;
                    break;
                case 4:
                    arr[c]=4;
                    break;
                case 5:
                    arr[c]=5;
                    break;
                case 6:
                    arr[c]=6;
                    break;
                case 7:
                    arr[c]=7;
                    break;
                case 8:
                    arr[c]=8;
                    break;
                case 9:
                    arr[c]=9;
                    break;
                case 10:
                    arr[c]=10;
                    break;
                case 11:
                    arr[c]=11;
                    break;
                case 12:
                    arr[c]=12;
                    break;
                case 13:
                    arr[c]=13;
                    break;
                case 14:
                    arr[c]=14;
                    break;
                case 15:
                    arr[c]=15;
                    break;
                case 16:
                    arr[c]=16;
                    break;
                case 17:
                    arr[c]=17;
                    break;
                case 18:
                    arr[c]=18;
                    break;
                case 19:
                    arr[c]=19;
                    break;
                case 20:
                    arr[c]=20;
                    break;
                case 21:
                    arr[c]=21;
                    break;
                case 22:
                    arr[c]=22;
                    break;
                case 23:
                    arr[c]=23;
                    break;
                default:
                    printf("Fail , course not registered  :( \n");
                } // End cases
                c++;
            }// End For

    return arr;
}



void Display(struct person x)
{
    int j,i;
    printf("\n\n\n\t\t#                                                                                  #\n");
    printf("\t\t-|======================          Info For Student             ======================|-\n");
    printf("\t\t |                                                                                   |\n");
    printf("\t\t |         ID: %d                               Name: %s           ",x.id,x.name);
    for(i=0;i<strlen(x.name);i++)
        printf(" ");
    printf("|\n");
    for(j=0;j<SizeOfCourses;j++){
        printf("\t\t |                             ID Of Course: ( %d )                                   |\n",x.Cdeg[j].cName);
        printf("\t\t |    Course Work: %0.1f                                                             |\n",x.Cdeg[j].courseWork);
        printf("\t\t |    Practical Exam: %0.1f                                                          |\n",x.Cdeg[j].practicalExam);
        printf("\t\t |    Final Exam: %0.1f                                                              |\n",x.Cdeg[j].FinalExam);
        printf("\t\t |                                Total Exam: %0.1f                                  |\n",x.Cdeg[j].total);
    }

    printf("\t\t |                                                                                   |\n");
    printf("\t\t-|======================            *End Info*                 ======================|-\n");
    printf("\t\t#                                                                                     #\n");

}




void LoadSystemData()
{
    int i,j;
    struct person x;
    FILE *fptr;
    if((fptr=fopen("SWE1.txt","r"))==NULL)
        printf("\n Sorry, File Of students Couldn't be Open :) ");

    else{
        fscanf(fptr,"%s%d",x.name,&x.id);
        for(j=0;j<SizeOfCourses;j++)
            fscanf(fptr,"%d%f%f%f%f",&x.Cdeg[j].cName,&x.Cdeg[j].courseWork,&x.Cdeg[j].practicalExam,&x.Cdeg[j].FinalExam,&x.Cdeg[j].total);
        while(!feof(fptr)){
            P[indexPro++]=x;
             fscanf(fptr,"%s%d",x.name,&x.id);
        for(j=0;j<SizeOfCourses;j++)
            fscanf(fptr,"%d%f%f%f%f",&x.Cdeg[j].cName,&x.Cdeg[j].courseWork,&x.Cdeg[j].practicalExam,&x.Cdeg[j].FinalExam,&x.Cdeg[j].total);
        }
    }
}



void SaveSystemData()
{
    FILE *fptr=fopen("SWE1.txt","w");
    int i,j;
    for(i=0;i<indexPro;i++){
        fprintf(fptr,"%s\t%d\t",P[i].name,P[i].id);
        for(j=0;j<SizeOfCourses;j++){
            fprintf(fptr,"%d\t",P[i].Cdeg[j].cName);
            fprintf(fptr,"%0.1f\t%0.1f\t%0.1f\t%0.1f\t",P[i].Cdeg[j].courseWork,P[i].Cdeg[j].practicalExam,P[i].Cdeg[j].FinalExam,P[i].Cdeg[j].total,P[i].gender);
        }
    }
}



void SortFinalExamData()
{
    int i,j;
    struct person temp;
    for(i=0;i<indexPro;i++){
        for(j=0;j<indexPro-1-i;j++){
            if(P[j].id>P[j+1].id){
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
    printf("\n\n\n\t\t\t\t#                                      #\n");
    printf("\t\t\t\t ||==================================||\n");
    printf("\t\t\t\t ||     Successful Operation ...     ||\n");
    printf("\t\t\t\t ||==================================||\n");
    printf("\t\t\t\t#                                      #\n");

    SaveSystemData();
    MainMenu();
}




void listAllStudent()
{
    struct person x;

    int i,j;

    printf("\n\n\n\t\t#                                                                                     #\n");
    printf("\t\t-|======================          Info For Students            ======================|-\n");
    printf("\t\t |                                                                                   |\n");
    for(i=0;i<indexPro;i++){
        printf("\t\t |                                                                                   |\n");
        printf("\t\t |         ID: %d                               Name: %s           ",P[i].id,P[i].name);
        for(j=0;j<strlen(P[i].name);j++)
            printf(" ");
        printf("|\n");
        for(j=0;j<SizeOfCourses;j++){
            printf("\t\t |                             ID Of Course: ( %d )                                   |\n",P[i].Cdeg[j].cName);
            printf("\t\t |    Course Work: %0.1f                                                             |\n",P[i].Cdeg[j].courseWork);
            printf("\t\t |    Practical Exam: %0.1f                                                          |\n",P[i].Cdeg[j].practicalExam);
            printf("\t\t |    Final Exam: %0.1f                                                              |\n",P[i].Cdeg[j].FinalExam);
            printf("\t\t |                                Total Exam: %0.1f                                  |\n",P[i].Cdeg[j].total);
        }
    printf("\t\t |                                                                                   |\n");
    printf("\t\t-|===================================================================================|-\n");

    }
    printf("\t\t#                                                                                     #\n");


    /*for(i=0;i<indexPro;i++){
        printf("ID: %d\tName: %s\t\n",P[i].id,P[i].name);
        for(j=0;j<SizeOfCourses;j++){
            printf("%d\t",P[i].Cdeg[j].cName);
            printf("(%0.1f\t%0.1f\t%0.1f) \t Total OF Degree :%0.1f\n",P[i].Cdeg[j].courseWork,P[i].Cdeg[j].practicalExam,P[i].Cdeg[j].FinalExam,P[i].Cdeg[j].total);
        }
    }

*/
    printf("\n\n\tPress Enter To return to Main Menu :) \n");
    getchar();
    getchar();
    MainMenu();
}


void AddData()
{
    int ch;
    char c;
    printf("\n\n\n\t\t\t\t#                                                      #\n");
    printf("\t\t\t\t ||==================================================||\n");
    printf("\t\t\t\t ||     Are you wanna add New Student ? (y/n)        ||\n");
    printf("\t\t\t\t ||==================================================||\n");
    printf("\t\t\t\t#                                                      #\n\n\n\t\t\tCh: ");
    getchar();
    scanf("%c",&c);
    if(c=='y'){

        printf("\tEnter This Data ... \n\n");
        printf("\t\tID: ");
        scanf("%d",&P[indexPro].id);
        printf("\t\tName: ");
        scanf("%s",P[indexPro].name);
        int j;

        for(j=0;j<SizeOfCourses;j++){
                printf("\n\n\n\t\t#                                                                      #\n");
        printf("\t\t-|======================     Choose Course      ======================|-\n");
        printf("\t\t |                                                                    |\n");
        printf("\t\t |        1: CS                                       2: IS           |\n");
        printf("\t\t |        3: English 1                                4: English 2    |\n");
        printf("\t\t |        5: HR                                       6: IT           |\n");
        printf("\t\t |        7: Math 1                                   8: Math 2       |\n");
        printf("\t\t |        9: Logic                                   10: PL1          |\n");
        printf("\t\t |       11: DB 1                                    12: DS           |\n");
        printf("\t\t |       13: Management                              14: Pl2          |\n");
        printf("\t\t |       15: Ethics                                  16: SW1          |\n");
        printf("\t\t |       17: Stat1                                   18: DC           |\n");
        printf("\t\t |       19: Negotiation                             20:OR            |\n");
        printf("\t\t |       21: OS                                      22: stat2        |\n");
        printf("\t\t |                           23: Compiler                             |\n");
        printf("\t\t |                                                                    |\n");
        printf("\t\t-|======================     *End Courses*      ======================|-\n");
        printf("\t\t#                                                                      #\n");

                printf("\n\n\t*your Choice: ");
                scanf("%d",&P[indexPro].Cdeg[j].cName);
                printf("\n\n\n\t\t#                                                              #\n");
                printf("\t\t-|==================        Press Info      ==================|-\n");
                printf("\t\t |                                                            |\n");
                printf("\t\t |        Enter courseWork, practicalExam, finalExam          |\n");
                printf("\t\t |                                                            |\n");
                printf("\t\t-|==================        **********      ==================|-\n");
                printf("\t\t#                                                              #\n\n\t\t>>> ");
                scanf("%f%f%f",&P[indexPro].Cdeg[j].courseWork,&P[indexPro].Cdeg[j].practicalExam,&P[indexPro].Cdeg[j].FinalExam);
                P[indexPro].Cdeg[j].total=P[indexPro].Cdeg[j].courseWork + P[indexPro].Cdeg[j].practicalExam + P[indexPro].Cdeg[j].FinalExam ;
        } // End For

        printf("\n\n\n\t\t\t\t#                                      #\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t ||     Successful Operation ...     ||\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t#                                      #\n");

        indexPro++;
        SaveSystemData();

    }
    printf("\n\n\n\t\t     press 1 To Add Info. Again OR 0 To exit & return to Main Menu !! \n ");
    printf("\t\t========================================================================\n\n\t\tCh: ");
    scanf("%d",&ch);
    if(ch==1)
        AddData();
    else if(ch==0)
        MainMenu();
    else{

            printf("\n\n\n\t\t\t\t#                                  #\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t ||       Invalid Choice ...     ||\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t#                                  #\n\n");
            }
}



void CheckSmall()
{
    int i;
    for(i=0;i<indexPro;i++)
        if(islower(P[i].name[0]))
            P[i].name[0]=toupper(P[i].name[0]);
        printf("\n\n\n\t\t\t\t#                                      #\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t ||     Successful Operation ...     ||\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t#                                      #\n");


    SaveSystemData();
    MainMenu();
}


void CheckCapital()
{
    int i;
    for(i=0;i<indexPro;i++)
        if(isupper(P[i].name[0]))
            P[i].name[0]=tolower(P[i].name[0]);
        printf("\n\n\n\t\t\t\t#                                      #\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t ||     Successful Operation ...     ||\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t#                                      #\n");

    SaveSystemData();
    MainMenu();
}



void UpdateRow()
{
    int ch;
    char c;
    int m=LocationByID();
    if(m!=-1){
        Display(P[m]);
        printf("\n\n\n\t\t\t\t#                                                #\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t ||     Are you wanna Update Student ?  (y/n)  ||\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t#                                                #\n\n\n\t\t\tCh: ");

        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y'){


            printf("\tEnter New Data ... \n\n");
            printf("\t\tID: ");
            scanf("%d",&P[m].id);
            printf("\t\tEnter Name: ");
            scanf("%s",P[m].name);
            int j;

        printf("\n\n\n\t\t#                                                                      #\n");
        printf("\t\t-|======================     Choose Courses      ======================|-\n");
        printf("\t\t |                                                                    |\n");
        printf("\t\t |        1: CS                                         2: IS         |\n");
        printf("\t\t |        3: English 1                                  4: English 2  |\n");
        printf("\t\t |        5: HR                                         6: IT         |\n");
        printf("\t\t |        7: Math 1                                     8: Math 2     |\n");
        printf("\t\t |        9: Logic                                     10: PL1        |\n");
        printf("\t\t |       11: DB 1                                      12: DS         |\n");
        printf("\t\t |       13: Management                                14: Pl2        |\n");
        printf("\t\t |       15: Ethics                                    16: SW1        |\n");
        printf("\t\t |       17: Stat1                                     18: DC         |\n");
        printf("\t\t |       19: Negotiation                               20:OR          |\n");
        printf("\t\t |       21: OS                                        22: stat2      |\n");
        printf("\t\t |                           23: Compiler                             |\n");
        printf("\t\t |                                                                    |\n");
        printf("\t\t-|======================     *End Courses*      ======================|-\n");
        printf("\t\t#                                                                      #\n\n");

            for(j=0;j<SizeOfCourses;j++){
                    printf("\t\tyour Choice: ");
                    scanf("%d",&P[m].Cdeg[j].cName);
                    printf("\n\n\n\t\t#                                                              #\n");
                    printf("\t\t-|==================        Press Info      ==================|-\n");
                    printf("\t\t |                                                            |\n");
                    printf("\t\t |        Enter courseWork, practicalExam, finalExam          |\n");
                    printf("\t\t |                                                            |\n");
                    printf("\t\t-|==================        **********      ==================|-\n");
                    printf("\t\t#                                                              #\n\n\t\t>>> ");
                    scanf("%f%f%f",&P[m].Cdeg[j].courseWork,&P[m].Cdeg[j].practicalExam,&P[m].Cdeg[j].FinalExam);
                    P[m].Cdeg[j].total=P[m].Cdeg[j].courseWork + P[m].Cdeg[j].practicalExam + P[m].Cdeg[j].FinalExam ;
            } // End For

        printf("\n\n\n\t\t\t\t#                                      #\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t ||     Successful Operation ...     ||\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t#                                      #\n\n");


        SaveSystemData();
        }
    }
    else{
            printf("\n\n\n\t\t\t\t#                              #\n");
            printf("\t\t\t\t ||==========================||\n");
            printf("\t\t\t\t ||       Invalid ID ...     ||\n");
            printf("\t\t\t\t ||==========================||\n");
            printf("\t\t\t\t#                              #\n\n");
    }

    printf("\n\n\n\t\t     press 1 To Search again & Update OR 0 To exit & return to Main Menu !! \n ");
    printf("\t\t===============================================================================\n\n\t\tCh: ");

    scanf("%d",&ch);
        if(ch==1)
            UpdateRow();
        else
            MainMenu();

}



int LocationByID()
{
    int key,i;
    printf("Please , Press ID OF Student: ");
    scanf("%d",&key);
    for(i=0;i<indexPro;i++){
        if(key==P[i].id){
            return i;
        }
    }
    return -1;

}


int LocationByName()
{
    char key[50];
    int i;
    printf("\n\t\tPlease , Press Name OF Student: ");
    scanf("%s",key);
    for(i=0;i<indexPro;i++)
        if(strcmp(key,P[i].name)==0)
            return i;
    return -1;
}



void DeleteInfo()
{
    int ch;
    char c;
    int m=LocationByID();
    if(m!=-1){
        Display(P[m]);

        printf("\n\t\t\t\t#                                                #\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t ||     Are you wanna Delete Student ?  (y/n)  ||\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t#                                                #\n\n\n\t\t\tCh: ");
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y'){
            int i;
            for(i=m;i<indexPro;i++){
                P[i]=P[i+1];
            }
            indexPro--;
        printf("\n\n\n\t\t\t\t#                                      #\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t ||     Successful Operation ...     ||\n");
		printf("\t\t\t\t ||==================================||\n");
		printf("\t\t\t\t#                                      #\n\n");

        SaveSystemData();
        }
    }
    else
        printf("\n\tInvalid ID ...\n\n");

    printf("\n\n\n\t\t     press 1 To Delete Info. again & Update OR 0 To exit & return to Main Menu !! \n ");
    printf("\t\t======================================================================================\n\n\t\tCh: ");

    scanf("%d",&ch);
    if(ch==1)
        DeleteInfo();
    else if(ch==0)
        MainMenu();
    else{
            printf("\n\n\n\t\t\t\t#                                  #\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t ||       Invalid Choice ...     ||\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t#                                  #\n\n");
    }
}


void clearFile()
{
    int ch;
    char c;

    printf("\n\n\n\t\t\t\t#                                                   #\n");
		printf("\t\t\t\t ||===============================================||\n");
		printf("\t\t\t\t ||     Are you Sure To Wanna Clear File ? (y/n)  ||\n");
		printf("\t\t\t\t ||===============================================||\n");
		printf("\t\t\t\t#                                                   #\n\n\n\t\t\tCh: ");

    getchar();
    scanf("%c",&c);
    if((c=='Y')||(c=='y')){
        if(CheckEnter()){
                indexPro=0 ;
                printf("\nPlease Wait .... \nData are formated \n\n");
                printf("\n\n\n\t\t\t\t#                                      #\n");
                printf("\t\t\t\t ||==================================||\n");
                printf("\t\t\t\t ||     Successful Operation ...     ||\n");
                printf("\t\t\t\t ||==================================||\n");
                printf("\t\t\t\t#                                      #\n\n");

                SaveSystemData();

            }
        else{
        printf("\n\n\n\t\t\t\t#                                                #\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t ||     you Can't access To function ...       ||\n");
		printf("\t\t\t\t ||============================================||\n");
		printf("\t\t\t\t#                                                #\n");

            printf("\n\n\t\t     press 1 To Try To Clear File Again & Update OR 0 To exit & return to Main Menu !! \n ");
            printf("\t\t===================================================================================================\n\n\t\tCh: ");

            scanf("%d",&ch);
            if(ch==1)
                clearFile();
            else if(ch==0)
                MainMenu();
            else{

                printf("\n\n\n\t\t\t\t#                                  #\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t ||       Invalid Choice ...     ||\n");
            printf("\t\t\t\t ||==============================||\n");
            printf("\t\t\t\t#                                  #\n\n");
            }
                }
    }

    MainMenu();

}



void UpdateElement()
{
    bool active = true; // false By Default
    char c;
    int i,j,select;
    int arr[SizeOfCourses];
    int m=LocationByID(),ch;
    if(m!=-1){
        Display(P[m]);

        printf("\n\n\n\t\t\t\t#                                                               #\n");
		printf("\t\t\t\t ||===========================================================||\n");
		printf("\t\t\t\t ||     Are you wanna Update Info. From This Student ? (y/n)  ||\n");
		printf("\t\t\t\t ||===========================================================||\n");
		printf("\t\t\t\t#                                                               #\n\n\n\t\t\tCh: ");

        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y'){

        printf("\n\n\n\t\t#                                                                                  #\n");
        printf("\t\t-|======================        Press Number to Edit        ======================|-\n");
        printf("\t\t |                                                                                |\n");
        printf("\t\t |        1: ID                                         2: Name                   |\n");
        printf("\t\t |        3: Register in Course                         4: degree in Course Work  |\n");
        printf("\t\t |        5: degree in practicalExam                    6:degree in FinalExam     |\n");
        printf("\t\t |                                                                                |\n");
        printf("\t\t-|======================            *End Main*              ======================|-\n");
        printf("\t\t#                                                                                  #\n\n\t\tCh: ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("\nEnter New ID: ");
                scanf("%d",&P[m].id);
                break;
            case 2:
                printf("Enter New Name: ");
                scanf("%s",P[m].name);
                break;

            case 3:

                //  *********************

                printf("\n\n\n\n\n");
                printf("\n\n\n\t\t\t\t#                                                                        #\n");
                printf("\t\t\t\t ||====================================================================||\n");
                printf("\t\t\t\t ||     please Choice your Course To Edit To Another Course ...        ||\n");
                printf("\t\t\t\t ||====================================================================||\n");
                printf("\t\t\t\t#                                                                        #\n\n ");


                while(active){
                printf("\n\n Courses you are Register ... \n\n");
                for(i=0;i<SizeOfCourses;i++)
                    arr[i]=P[m].Cdeg[i].cName;

                for(i=0;i<SizeOfCourses;i++){

                    switch(arr[i])
                    {
                    case 1:
                        printf("%d: CS\n",i);
                        break;
                    case 2:
                        printf("%d: IS\n",i);
                        break;
                    case 3:
                        printf("%d: English 1\n",i);
                        break;
                    case 4:
                        printf("%d: English 2\n",i);
                        break;
                    case 5:
                        printf("%d: HR\n",i);
                        break;
                    case 6:
                        printf("%d: IT\n",i);
                        break;
                    case 7:
                        printf("%d: Math 1\n",i);
                        break;
                    case 8:
                        printf("%d: Math 2\n",i);
                        break;
                    case 9:
                        printf("%d: Logic\n",i);
                        break;
                    case 10:
                        printf("%d: PL1\n",i);
                        break;
                    case 11:
                        printf("%d: Data Base 1\n",i);
                        break;
                    case 12:
                        printf("%d: DS\n",i);
                        break;
                    case 13:
                        printf("%d: Management\n",i);
                        break;
                    case 14:
                        printf("%d: PL2\n",i);
                        break;
                    case 15:
                        printf("%d: Ethics\n",i);
                        break;
                    case 16:
                        printf("%d: SW1\n",i);
                        break;
                    case 17:
                        printf("%d: Stat1\n",i);
                        break;
                    case 18:
                        printf("%d: DC\n",i);
                        break;
                    case 19:
                        printf("%d: Negotiation\n",i);
                        break;
                    case 20:
                        printf("%d: OR\n",i);
                        break;
                    case 21:
                        printf("%d: OS\n",i);
                        break;
                    case 22:
                        printf("%d: stat2\n",i);
                        break;
                    case 23:
                        printf("%d: Compiler\n",i);
                        break;
                    default:
                        printf("Not Register \n");
                    } // End cases

                }// End For

                /*
                    l7d hna kdh 3rd el mwad el student msglha
                    elly hma 7 b array pointed by pointer ptr

                */



                    printf("your Choice: ");
                    scanf("%d",&ch);
                    printf("Enter The ID Of Course (IOC): ");
                    scanf("%d",&P[m].Cdeg[arr[ch]].cName);
                    printf( "Enter courseWork, practicalExam, finalExam\n\t" );
                    scanf( "%f%f%f" , &P[m].Cdeg[arr[ch]].courseWork , &P[m].Cdeg[arr[ch]].practicalExam , &P[m].Cdeg[arr[ch]].FinalExam );
                    P[m].Cdeg[arr[ch]].total = P[m].Cdeg[arr[ch]].courseWork + P[m].Cdeg[arr[ch]].practicalExam + P[m].Cdeg[arr[ch]].FinalExam ;

                    printf("\n\n\n\t\t\t\t#                                      #\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t ||     Successful Operation ...     ||\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t#                                      #\n\n");


                    active = false ;
                    printf("Are you wanna edit specific Course ? \n IF you wanna press 1 else press 0\n");
                    getchar();
                    scanf("%d",&ch);
                    if(ch==1)
                        active = true;
                    SaveSystemData();

                } // End While



        // **********************

                break; // End Case 3 >>>>>>>>>>>>>>>>

            case 4:

                while(active){
                    printf("\n\n Course you are Register... \n\n");
                    for(i=0;i<SizeOfCourses;i++)
                        arr[i]=P[m].Cdeg[i].cName;

                    for(i=0;i<SizeOfCourses;i++){

                        switch(arr[i])
                        {
                        case 1:
                            printf("%d: CS\n",i);
                            break;
                        case 2:
                            printf("%d: IS\n",i);
                            break;
                        case 3:
                            printf("%d: English 1\n",i);
                            break;
                        case 4:
                            printf("%d: English 2\n",i);
                            break;
                        case 5:
                            printf("%d: HR\n",i);
                            break;
                        case 6:
                            printf("%d: IT\n",i);
                            break;
                        case 7:
                            printf("%d: Math 1\n",i);
                            break;
                        case 8:
                            printf("%d: Math 2\n",i);
                            break;
                        case 9:
                            printf("%d: Logic\n",i);
                            break;
                        case 10:
                            printf("%d: PL1\n",i);
                            break;
                        case 11:
                            printf("%d: Data Base 1\n",i);
                            break;
                        case 12:
                            printf("%d: DS\n",i);
                            break;
                        case 13:
                            printf("%d: Management\n",i);
                            break;
                        case 14:
                            printf("%d: PL2\n",i);
                            break;
                        case 15:
                            printf("%d: Ethics\n",i);
                            break;
                        case 16:
                            printf("%d: SW1\n",i);
                            break;
                        case 17:
                            printf("%d: Stat1\n",i);
                            break;
                        case 18:
                            printf("%d: DC\n",i);
                            break;
                        case 19:
                            printf("%d: Negotiation\n",i);
                            break;
                        case 20:
                            printf("%d: OR\n",i);
                            break;
                        case 21:
                            printf("%d: OS\n",i);
                            break;
                        case 22:
                            printf("%d: stat2\n",i);
                            break;
                        case 23:
                            printf("%d: Compiler\n",i);
                            break;
                        default:
                            printf("Not Register \n");
                        } // End cases

                    }// End For




                    //*******************
                    printf("Choice Course: ");
                    scanf("%d",&ch);
                    printf("\n\nEnter New Degree in Course Work: ");
                    scanf("%f",&P[m].Cdeg[arr[ch-1]].courseWork);
                    printf("\n\n\n\t\t\t\t#                                      #\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t ||     Successful Operation ...     ||\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t#                                      #\n\n");


                    active = false ;
                    printf("\t\tAre you wanna edit specific Course ? ( Course Work ) \n\t\tIF you want press 1 else press 0\n\n\t\tCh: ");
                    getchar();
                    scanf("%d",&ch);
                    if(ch==1)
                        active = true;
                    SaveSystemData();
                }// End While
                break;


            case 5:
                while(active){
                printf("\n\n Course you are Register ... \n\n");
                for(i=0;i<SizeOfCourses;i++)
                    arr[i]=P[m].Cdeg[i].cName;

                for(i=0;i<SizeOfCourses;i++){

                    switch(arr[i])
                    {
                    case 1:
                        printf("%d: CS\n",i);
                        break;
                    case 2:
                        printf("%d: IS\n",i);
                        break;
                    case 3:
                        printf("%d: English 1\n",i);
                        break;
                    case 4:
                        printf("%d: English 2\n",i);
                        break;
                    case 5:
                        printf("%d: HR\n",i);
                        break;
                    case 6:
                        printf("%d: IT\n",i);
                        break;
                    case 7:
                        printf("%d: Math 1\n",i);
                        break;
                    case 8:
                        printf("%d: Math 2\n",i);
                        break;
                    case 9:
                        printf("%d: Logic\n",i);
                        break;
                    case 10:
                        printf("%d: PL1\n",i);
                        break;
                    case 11:
                        printf("%d: Data Base 1\n",i);
                        break;
                    case 12:
                        printf("%d: DS\n",i);
                        break;
                    case 13:
                        printf("%d: Management\n",i);
                        break;
                    case 14:
                        printf("%d: PL2\n",i);
                        break;
                    case 15:
                        printf("%d: Ethics\n",i);
                        break;
                    case 16:
                        printf("%d: SW1\n",i);
                        break;
                    case 17:
                        printf("%d: Stat1\n",i);
                        break;
                    case 18:
                        printf("%d: DC\n",i);
                        break;
                    case 19:
                        printf("%d: Negotiation\n",i);
                        break;
                    case 20:
                        printf("%d: OR\n",i);
                        break;
                    case 21:
                        printf("%d: OS\n",i);
                        break;
                    case 22:
                        printf("%d: stat2\n",i);
                        break;
                    case 23:
                        printf("%d: Compiler\n",i);
                        break;
                    default:
                        printf("Not Register \n");
                    } // End cases

                }// End For


                printf("Choice Course: ");
                scanf("%d",&ch);
                printf("Enter New Degree in practical Exam: ");
                scanf("%f",&P[m].Cdeg[arr[ch-1]].practicalExam);

                    printf("\n\n\n\t\t\t\t#                                      #\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t ||     Successful Operation ...     ||\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t#                                      #\n\n");

                    active = false ;
                    printf("\t\tAre you wanna edit specific Course ? ( practical Exam ) \n\t\tIF you want press 1 else press 0\n\n\t\tCh: ");
                    getchar();
                    scanf("%d",&ch);
                    if(ch==1)
                        active = true;
                    SaveSystemData();
                }// End While
                break;
            case 6:

                while(active){
                printf("\n\n Course you are Register ... \n\n");
                for(i=0;i<SizeOfCourses;i++)
                    arr[i]=P[m].Cdeg[i].cName;

                for(i=0;i<SizeOfCourses;i++){

                    switch(arr[i])
                    {
                    case 1:
                        printf("%d: CS\n",i);
                        break;
                    case 2:
                        printf("%d: IS\n",i);
                        break;
                    case 3:
                        printf("%d: English 1\n",i);
                        break;
                    case 4:
                        printf("%d: English 2\n",i);
                        break;
                    case 5:
                        printf("%d: HR\n",i);
                        break;
                    case 6:
                        printf("%d: IT\n",i);
                        break;
                    case 7:
                        printf("%d: Math 1\n",i);
                        break;
                    case 8:
                        printf("%d: Math 2\n",i);
                        break;
                    case 9:
                        printf("%d: Logic\n",i);
                        break;
                    case 10:
                        printf("%d: PL1\n",i);
                        break;
                    case 11:
                        printf("%d: Data Base 1\n",i);
                        break;
                    case 12:
                        printf("%d: DS\n",i);
                        break;
                    case 13:
                        printf("%d: Management\n",i);
                        break;
                    case 14:
                        printf("%d: PL2\n",i);
                        break;
                    case 15:
                        printf("%d: Ethics\n",i);
                        break;
                    case 16:
                        printf("%d: SW1\n",i);
                        break;
                    case 17:
                        printf("%d: Stat1\n",i);
                        break;
                    case 18:
                        printf("%d: DC\n",i);
                        break;
                    case 19:
                        printf("%d: Negotiation\n",i);
                        break;
                    case 20:
                        printf("%d: OR\n",i);
                        break;
                    case 21:
                        printf("%d: OS\n",i);
                        break;
                    case 22:
                        printf("%d: stat2\n",i);
                        break;
                    case 23:
                        printf("%d: Compiler\n",i);
                        break;
                    default:
                        printf("Not Register \n");
                    } // End cases

                }// End For


                printf("Choice Course: ");
                scanf("%d",&ch);
                printf("Enter New Degree in Final Exam: ");
                scanf("%f",&P[m].Cdeg[arr[ch-1]].FinalExam);

                    printf("\n\n\n\t\t\t\t#                                      #\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t ||     Successful Operation ...     ||\n");
                    printf("\t\t\t\t ||==================================||\n");
                    printf("\t\t\t\t#                                      #\n\n");

                    active = false ;
                    printf("\t\tAre you wanna edit specific Course ? ( Final Exam ) \n\t\tIF you want press 1 else press 0\n\n\t\tCh: ");
                    getchar();
                    scanf("%d",&ch);
                    if(ch==1)
                        active = true;
                        SaveSystemData();
                }// End While
                break;

            default:
                printf("Incorrect ");
                } // End Main Switch
            printf("\n\n\n\t\t\t\t#                                      #\n");
            printf("\t\t\t\t ||==================================||\n");
            printf("\t\t\t\t ||     Successful Operation ...     ||\n");
            printf("\t\t\t\t ||==================================||\n");
            printf("\t\t\t\t#                                      #\n\n");

            SaveSystemData();

        } // End If yes OR No

    } // End if m!=-1

    else{
        printf("\n\n\n\t\t\t\t#                              #\n");
            printf("\t\t\t\t ||==========================||\n");
            printf("\t\t\t\t ||       Invalid ID ...     ||\n");
            printf("\t\t\t\t ||==========================||\n");
            printf("\t\t\t\t#                              #\n\n");
    }

    printf("\n\n\n\t\t     press 1 To Search again & Update OR 0 To exit & return to Main Menu !! \n ");
    printf("\t\t==================================================================================\n\n\t\tCh: ");

    scanf("%d",&ch);
        if(ch==1)
            UpdateElement();
        else
            MainMenu();

}






#define affairs
#endif // affairs
