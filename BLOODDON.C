////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**BLOOD DONOR DATABASE**/

#include "stdio.h"
#include "conio.h"
#include <string.h>
#include <graphics.h>
#include <dos.h>
#define amt 300
/////////////////////////////////////////////////////////////////////////////////

FILE *fp;
long int size;
struct donor
{
char name[25];
int age;
char address1[30];
char address2[30];
char city[20];
char phn[11];
char bloodgrp[4];
char email[40];
int id;
};
struct donor b; //Declaration of Structures

///////////////////////////////////////////////////////////////////////////////

void putdonor();   //Store the Data in File
void getdonor();   //Display Data
void donorbyid();
void donorbycity();
void calamt();     //Calculate Sum to be paid to Donor
void menu();       //Display Menu
void creden();     //Display Credentials

////////////////////////////////////////////////////////////////////////////////////////

void main()
{
int i;
i=1;
size=sizeof(b);     //Finding the size of strucutre

clrscr();
while(i<=7)
{
printf("\n\n\n\n\n\n\n\n\t\t\t\t Initializing");
if(i<7)
{
delay(500);
clrscr();
delay(450);
 }
 i++;
 }
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);

clrscr();
menu();
getch();

}

////////////////////////////////////////////////////////////////////////////////////////////

void putdonor()
{
char a;
clrscr();
fp=fopen("BDONOR.DAT","wb+");    //Opening a Binary File
if(fp==NULL)
{
puts("Cannot Open File");
exit(0);
}
fseek(fp,0,SEEK_END);       //Putting the Pointer at the end of the File
do
{
clrscr();
fflush(stdin);
printf("\n\t Enter Name :- ");
gets(b.name);
printf("\n\tEnter Your Age :- ");
scanf("%d",&b.age);
fflush(stdin);
printf("\n\t Enter Ur Donor Id :- ");
scanf("%d",&b.id);
printf("\n\t Enter address line 1 :- ");
fflush(stdin);
gets(b.address1);
printf("\n\t Enter address line 2 :- ");
gets(b.address2);
printf("\n\t Enter city :- ");
gets(b.city);
printf("\n\t Enter Blood group :- ");
gets(b.bloodgrp);
printf("\n\t Enter your 10 Digit Mobile Number :- ");
scanf("%s",b.phn);
fflush(stdin);
printf("\n\t Enter your Email id :-");
scanf("%s",b.email);
fwrite(&b,size,1,fp);

printf("\n\tDo You want to add another data\n Enter (Y \\ N)");
fflush(stdin);
scanf("%c",&a);
}while(a=='Y'||a=='y');
fclose(fp);		 //Closing the File
clrscr();
menu();
}

///////////////////////////////////////////////////////////////////////////////////////////

void getdonor()
{
char bld[4];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the Blood Group ");
scanf("%s",bld);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(strcmp(b.bloodgrp,bld)==0)      //Mathching the Bloodgroup required with the one's present in Database
{
clrscr();
printf("\n\tName: %s \n\tDonor Id: %d \n\tAge: %d \n\tAddress Line 1: %s \n\tAddress Line 2: %s \n\tCity: %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s \n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}

////////////////////////////////////////////////////////////////////////////////////////////////

void menu()
{
int choice;
clrscr();
printf("\n\n\t\t\t\tBLOOD DONOR DATABASE \n\n\n");
printf("\t1 Add a new entry\n\n");
printf("\t2 Search by Blood Group \n\n");
printf("\t3 Search by Donor Id \n\n");
printf("\t4 Search by City \n\n");
printf("\t5 Calculate the amount to be paid to Donor\n\n");
printf("\t6 Credentials\n\n");
printf("\t7 Exit the program \n\n");
printf("\tYour Choice: ");



scanf("%d",&choice);
switch(choice)
{
case 1 : putdonor();
	 break;

case 2:  getdonor();
	 break;

case 3:  donorbyid();
	 break;

case 4:  donorbycity();
	 break;

case 5:  calamt();
	 break;

case 6:  creden();
	 break;

case 7:  exit();

default: clrscr();
	 printf("\n\n\t\tYou have entered wrong choice.....!!!");
	 delay(4000);
	 menu();

}
}

//////////////////////////////////////////////////////////////////////////////////////////////

void calamt()
{
float unit,sum;
clrscr();
printf("\n\n\tEnter the unit donated ");
scanf("%f",&unit);
sum= unit*amt;            //Calculating the Amount to be paid
printf("\n\tAmount paid per Unit = Rs.%d\n\n",amt);
printf("\n\tTotal Amount to be paid = Rs.%f\n",sum);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBack to Main Menu in 7 seconds");
delay(7000);
clrscr();
menu();

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void creden()
{
clrscr();
printf("\n\n\t\t\t\tBLOOD DONOR DATABASE \n\n\n");
printf("\t\t\tTeacher Incharge:- Rachna Agarwal\n");
printf("\n\n\t\t\tTeam Lead:- Aman Modi\n");
printf("\n\n\t\t\tTeam Members:-\n");
printf("\n\t\t\tAiesha Mirza\n\t\t\tAkansha Harimurty\n\t\t\tAkash Bhardwaj\n");
printf("\t\t\tAman Kr. Singh\n\t\t\tAnshika Saxena\n\t\t\tChandan Kumar\n");
printf("\t\t\tDevansh Saxena\n\t\t\tPrerna Agarwal\n");
printf("\n\n\nBack to Main Menu in 10 seconds");
delay(10000);
clrscr();
menu();

}

//////////////////////////////////////////////////////////////////////////////////////////

void donorbyid()
{
int id;
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the Donor Id ");
scanf("%d",&id);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(b.id==id)      //Mathching the Bloodgroup required with the one's present in Database
{
printf("\n\tName: %s \n\tDonor Id: %d \n\tAge: %d \n\tAddress Line 1: %s \n\tAddress Line 2: %s \n\tCity: %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}


////////////////////////////////////////////////////////////////////////////////////////////////

void donorbycity()
{
char city[20];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the City ");
scanf("%s",city);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if((strcmp(b.city,city))==0)      //Mathching the Bloodgroup required with the one's present in Database
{
printf("\n\tName: %s \n\tDonor Id: %d \n\tAge: %d \n\tAddress Line 1: %s \n\tAddress Line 2: %s \n\tCity: %s \n\tPhone No:- %s \n\tEmail: %s \n\tBlood Group: %s\n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND.....!!!");
printf("\n\n Back to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////


//Floating Point Emulator
void linkfloat()
{
float a=0,*b;
b=&a;
a=*b;
}
