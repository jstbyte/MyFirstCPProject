#include<stdio.h>
#include <iostream>
#include <Windows.h>
#include<conio.h>
using namespace std;
void namem();
int BCv();
void About();
void addname();
void BC();
void more();
char bb[30],path[34];
main()
{
    int pr;
    FILE *cl,*f;
    do{
    int a,s,t=0,q=0;
            system("cls");
    printf("A Clint Manegenment Softwere By- 29sTech, Coded By - ZAHIDUL ISLAM.\n----------------------------------------------------------------------\n1. Clint List.\n2. Add Clint Name.\n3. Total B.C.\n4. About\n5. Exit\n\n:");
    scanf("%d",&pr);
    fflush(stdin);
    if(pr==1)
    {       /* Tart Main */
system("cls");
printf(".............Clint List ...........\n\n");
        cl=fopen("Clint List.txt","r");
    for(a=1;feof(cl)==0;a++)
    {
    fscanf(cl,"%s",&bb);
    printf("%d. %s\n",a,bb);
    q++;
}
printf("\nEnter Your Choice  ");
scanf("%d",&s);
fclose(cl);
cl=fopen("Clint List.txt","r");
if(q>=s)
{
while(s!=t)
{
    fscanf(cl,"%s",&bb);
    t++;
}
}
fclose(cl);
f=fopen("temp.txt","w+");
fprintf(f,"%s.txt",bb);
fclose(f);
f=fopen("temp.txt","r");
fscanf(f,"%s",&path);
namem();

    }/* Main Fn */





    if(pr==2)addname();
    if(pr==3)more();
    if(pr==4)About();
    if(pr==5)exit(1);
    }while(pr!=4);
}


// Other Program//

 void namem() // Balance Entry Funtion //
{
    system("cls");
    int price=0,e,tb;
    FILE *fp;
    FILE *tfp;
    SYSTEMTIME str_t;
	GetSystemTime(&str_t);
    do
    {
    system("cls");
    tb=BCv();
    tfp=fopen("Total","ab");
    fp=fopen(path,"a");
    printf("Name: %s.   Total Balance:  %d.00 INR Only.    ",bb,tb);
    cout<<"0. Main Menu\n--------------------------------------------------------------------------------\nEnter Deposite Amount :  ";
    fflush(stdin);
    scanf("%d",&price);
    if(price!=0)
    {
system("cls");
    cout<<bb<<"   "<<str_t.wDay<<'-'<<str_t.wMonth<<'-'<<str_t.wYear<<"    = "<<price<<".00 Rupees.\n\nEnter 1. To Save :  ";
    scanf("%d",&e);
    fflush(stdin);
    if(e!=1){system("cls"); printf("Entry Of : %d.00 Is Not Saved",price);BC();}
        else
        {
        fprintf(fp,"%d-%d-%d   :   ",str_t.wDay,str_t.wMonth,str_t.wYear);
            fprintf(fp," %d.00 \n",price);
            fprintf(tfp,"\n%d",price);
            fclose(tfp);
    fclose(fp);
    fp=fopen(bb,"ab");
    fprintf(fp,"\n%d",price);
    fclose(fp);}}
}while(price!=0);
}
void BC()
{
    printf("\n%s  :\n",bb);
    int a,b=0,c;
    FILE *pp;
    pp=fopen(bb,"rb");
    if(pp==NULL){printf("\n\nNodata Fount For %s\n\n",bb);scanf("%d"); exit(1);}
    while(feof(pp)==0)
    {
    fscanf(pp,"%d",&a);
    b=a+b;
    }
    fclose(pp);
    printf("***************************************************\n***                                            ****\n***  Total Balance In Account Is   %d.00      *\n***                                            ****\n***************************************************\n\n\nEnter 1 To Save In Main Text FIle.\n     :",b);
    scanf("%d",&c);
    if(c==1){
    pp=fopen(path,"a");
    fprintf(pp,"----------------------------\nTotal       :    %d\n",b);
    }

}
int BCv()
{
    FILE *bcvfp;
    int a,b=0;
 bcvfp=fopen(bb,"rb");
    if(bcvfp==NULL)b=0;
    else
    {
    while(feof(bcvfp)==0)
    {
    fscanf(bcvfp,"%d",&a);
    b=a+b;
    }
    }
    fclose(bcvfp);
    return(b);
}

void addname()
    {
        int g;
        FILE *ad;
        char nm[30];
        do
        {
            system("cls");
            printf("Enter Clint Name:- ");
        scanf("%s",&nm);
        printf("\n0. Don't Save:- %s  & Goto Main Menu.\n1. Save:-       %s  & Add More Name.\n2. Save:-       %s  & Go To Main Menu.\n       :-  ",nm,nm,nm);
        scanf("%d",&g);
        if(g==1)
        {
        ad=fopen("Clint List.txt","a");
        fprintf(ad,"\n%s",nm);
        fclose(ad);
        }
        if(g==2)
        {
            ad=fopen("Clint List.txt","a");
        fprintf(ad,"\n%s",nm);
        fclose(ad);
        break;
        }
        }while(g!=0);
    }

    void About()
    {
        system("cls");
        printf("ZAHIDUL ISLAM\n-------------\n\nThis Softwere Is Coded By : Zahidul Islam\nAlso Known As 29\nBrand Name 29sTech\nFacebook.com\\29sTech\nAddress:- Ambari Bazeer, P.0- Nakhuti Bazer, Hojai(Assam),India \n\nCoded By C And C++\n\nYoutube Channel Name: 29sTech\n\nSearch My Store On GoogleMap : Z.ENTERPRISE\n\nThank You For Using This Softwere.");
        getch();

    }

    void more()
    {
     int a,b=0,c;
    FILE *pp;
    pp=fopen("Total","rb");
    if(pp==NULL){printf("xxxxxxxxxxxxxxxxxxxxxxx\nNo Balance At This Time.....");}
    else {
    while(feof(pp)==0)
    {
    fscanf(pp,"%d",&a);
    b=a+b;
    }
    printf("..........................\nTotal Balance : %d\n\nEnter Any key To Main ",b);
    }
    fclose(pp);
    getch();
    }
