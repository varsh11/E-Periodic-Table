#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
void mainmenu(void);
struct period
{
	int an;
	char s[10];
	char name[50];
	float ar;
	float ip;
	float en;
};
void welcomescr()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(11);
	setcolor(1);
	settextstyle(1,0,8);
	outtextxy(130,8,"WELCOME");
	outtextxy(260,100,"TO");
	outtextxy(60,190,"E - PERIODIC");
	outtextxy(170,280,"TABLE");
	setcolor(2);
	settextstyle(1,0,1);
	outtextxy(380,450,"Press Any Key To Continue..");
}
void add()
{
	clrscr();
	period rec;
	cout<<"\t\t\t===Add Element===";
	int fl=0,an1;
	char ch;
		do
		{
			cout<<"\n\n\nEnter Atomic No: ";
			cin>>an1;
			fl=0;
			fstream f("pro.dat",ios::in|ios::binary);
			while(f.read((char *)&rec,sizeof(period)))
			{
				if(rec.an==an1)
				{
					fl=1;
					break;
				}
			}
			f.close();
			if(fl==0)
			{
				rec.an=an1;
				cout<<"\nSymbol: ";
				gets(rec.s);
				cout<<"\nEnter Name: ";
				gets(rec.name);
				cout<<"\nEnter Atomic Radius(in pm): ";
				cin>>rec.ar;
				cout<<"\nEnter 1st Ionisation Potential(in J): ";
				cin>>rec.ip;
				cout<<"\nEnter ElectroNegativity: ";
				cin>>rec.en;
				fstream f("pro.dat",ios::app|ios::binary);
				f.write((char *)&rec,sizeof(period));
				f.close();
			}
			else
			{
				cout<<"\nElement Already Exist.";
			}
			cout<<"\n\nDo You Want To Add More Elements.?(Y/N)  ";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
}
void conadd()
{
	clrscr();
	char ch;
	cout<<"\n\nAre you sure you want to ADD new ELEMENT.?(Y/N) ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	add();
	else
	mainmenu();
}
void searchan()
{
	clrscr();
	period rec;
	fstream f("pro.dat",ios::in|ios::binary);
	int fl=0,an1;
	cout<<"\n\n\n\tEnter Atomic Number Of The Element: ";
	cin>>an1;
	while(f.read((char *)&rec,sizeof(period)))
	{
		if(rec.an==an1)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
	{
		cout<<"\nAtomic Number: "<<rec.an;
		cout<<"\nSymbol: "<<rec.s;
		cout<<"\nName: "<<rec.name;
		cout<<"\nAtomic Radius(in pm): "<<rec.ar;
		printf("\n1st Ionisation Potential(in J): %4.2f",rec.ip);
		printf("\nElectroNegativity: %2.2f",rec.en);
		cout<<"\n===================================================";
	}
	else
		cout<<"\n\nElement Not Found :(";
	f.close();
}
void searchs()
{
	clrscr();
	period rec;
	fstream f("pro.dat",ios::in|ios::binary);
	int fl=0;
	char s1[10];
	cout<<"\n\n\n\tEnter Symbol Of The Element: ";
	gets(s1);
	while(f.read((char *)&rec,sizeof(period)))
	{
		if(strcmp(rec.s,s1)==0)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
	{
		cout<<"\nAtomic Number: "<<rec.an;
		cout<<"\nSymbol: "<<rec.s;
		cout<<"\nName: "<<rec.name;
		cout<<"\nAtomic Radius(in pm): "<<rec.ar;
		printf("\n1st Ionisation Potential(in J): %4.2f",rec.ip);
		printf("\nElectroNegativity: %2.2f",rec.en);
		cout<<"\n===================================================";
	}
	else
		cout<<"\n\nElement Not Found :(";
	f.close();
}
void searchn()
{
	clrscr();
	period rec;
	fstream f("pro.dat",ios::in|ios::binary);
	int fl=0;
	char nm[50];
	cout<<"\n\n\n\tEnter Name Of The Element: ";
	gets(nm);
	while(f.read((char *)&rec,sizeof(period)))
	{
		if(strcmp(rec.name,nm)==0)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
	{
		cout<<"\nAtomic Number: "<<rec.an;
		cout<<"\nSymbol: "<<rec.s;
		cout<<"\nName: "<<rec.name;
		cout<<"\nAtomic Radius(in pm): "<<rec.ar;
		printf("\n1st Ionisation Potential(in J): %4.2f",rec.ip);
		printf("\nElectroNegativity: %2.2f",rec.en);
		cout<<"\n===================================================";
	}
	else
		cout<<"\n\nElement Not Found :(";
	f.close();
}
void search()
{
	int s;
	while(1)
	{
		clrscr();
		cout<<"\t\t\t===Search Element===";
		cout<<"\n\n\t1. Search by Atomic Number.";
		cout<<"\n\n\n\t2. Search by Symbol.";
		cout<<"\n\n\n\t3. Search by Name.";
		cout<<"\n\n\n\t4. Exit to Main Menu.";
		cout<<"\n\n\n\tEnter your Choice: ";
		cin>>s;
		switch(s)
		{
		case 1: searchan();
			getch();
			break;
		case 2: searchs();
			getch();
			break;
		case 3: searchn();
			getch();
			break;
		case 4: mainmenu();

		}
	}
}
void modify()
{
	clrscr();
	period rec;
	fstream fin("pro.dat",ios::in|ios::binary);
	fstream fout("temp.dat",ios::out|ios::binary);
	int an1;
	cout<<"\t\t\t===Modify Element===";
	cout<<"\n\nEnter Element\'s Atomic Number To Modify: ";
	cin>>an1;
	int fl=0;
	while(fin.read((char *)&rec,sizeof(period)))
	{
		if(an1==rec.an)
		{
			fl=1;
			cout<<"\n\nOLD Records are====>";
			cout<<"\nAtomic Number: "<<rec.an;
			cout<<"\nSymbol: "<<rec.s;
			cout<<"\nName: "<<rec.name;
			cout<<"\nAtomic Radius(in pm): "<<rec.ar;
			printf("\n1st Ionisation Potential(in J): %4.2f",rec.ip);
			printf("\nElectroNegativity: %2.2f",rec.en);
			cout<<"\n\n===================================================";
			cout<<"\nModified Value...";
			cout<<"\nSymbol: ";
			gets(rec.s);
			cout<<"\nEnter Name: ";
			gets(rec.name);
			cout<<"\nEnter Atomic Radius(in pm): ";
			cin>>rec.ar;
			cout<<"\nEnter 1st Ionisation Potential(in J): ";
			cin>>rec.ip;
			cout<<"\nEnter ElectroNegativity: ";
			cin>>rec.en;
			fout.write((char *)&rec,sizeof(period));
		}
		else
		{
			fout.write((char *)&rec,sizeof(period));
		}
	}
	fin.close();
	fout.close();
	remove("pro.dat");
	rename("temp.dat","pro.dat");
	//remove("temp.dat");
	if(fl==0)
		cout<<"\n\n===>Element Doesn't Exist<===";
	else
		cout<<"\n\n===>Element Modification Complete<===";

}
int i,j,k;
void disp()
{
	clrscr();
	period rec;
	int i=0;
	fstream f("pro.dat",ios::in|ios::binary);
	cout<<"Atomic Number.\t|\tSymbol.\n\n";
	while(f.read((char *)&rec,sizeof(period)))
	{
		if(i<=20)
		{
			i++;
			cout<<rec.an<<"\t\t|\t"<<rec.s<<"\n";
		}
		else
		{
			i=0;
			cout<<"\n...Press Any Key To Display Next Elements.";
			getch();
			clrscr();
		}
	}
	f.close();
}
void display()
{
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
 settextstyle(8,0,1);
 setcolor(RED);
 outtextxy(200,10,"DIGITAL PERIODIC TABLE");
 gotoxy(1,1);
 cout<<"и";
 for(i=2;i<=79;i++)
  {
  gotoxy(i,1);
  cout<<"м";
  }
 cout<<"╩";
 for(i=2;i<=23;i++)
  {
  gotoxy(80,i);
  cout<<"╨";
  }
 gotoxy(80,24);
 cout<<"╪";
 for(i=2;i<=11;i++)
  {
  gotoxy(i,24);
  cout<<"м";
  }
 gotoxy(1,24);
 cout<<"х";
 for(i=2;i<=23;i++)
  {
  gotoxy(1,i);
  cout<<"╨";
  }
 gotoxy(12,4);
 cout<<"з"<<"д"<<"д"<<"©";
 gotoxy(63,4);
 cout<<"з"<<"д"<<"д"<<"©";
 gotoxy(12,5);cout<<"Ё";
 gotoxy(15,5);cout<<"Ё";
 gotoxy(63,5);cout<<"Ё";
 gotoxy(66,5);cout<<"Ё";
 gotoxy(12,6);cout<<"ц"<<"д"<<"д"<<"╢";
 gotoxy(48,6);cout<<"з";
 for(i=51;i<=60;i++)
  if(i%3==0)
   {
   gotoxy(i,6);
   cout<<char(194);
   }
 for(i=48;i<=66;i++)
  if(i%3!=0)
   {
   gotoxy(i,6);
   cout<<"д";
   }
 gotoxy(63,6);
 cout<<"е";
 for(i=48;i<=66;i++)
  if(i%3==0)
   {
   gotoxy(i,7);
   cout<<"Ё";
   }
 gotoxy(12,7);cout<<"Ё";
 gotoxy(12,8);cout<<"ц"<<"д"<<"д"<<"╢";
 gotoxy(12,9);cout<<"Ё";
 gotoxy(15,9);cout<<"Ё";
 gotoxy(15,6);cout<<"е"<<"д"<<"д"<<"©";
 gotoxy(15,8);cout<<"е"<<"д"<<"д"<<"╢";
 gotoxy(18,7);cout<<"Ё";
 gotoxy(18,9);cout<<"Ё";
 gotoxy(48,8);cout<<"ц";
 for(i=51;i<=63;i++)
  if(i%3==0)
   {
   gotoxy(i,8);
   cout<<"е";
   }
 for(i=48;i<=66;i++)
  if(i%3!=0)
   {
   gotoxy(i,8);
   cout<<"д";
   }
 for(i=48;i<=66;i++)
  if(i%3==0)
   {
   gotoxy(i,9);
   cout<<"Ё";
   }
 gotoxy(12,10);
 cout<<"ц";gotoxy(15,10);
 cout<<"е";
 for(i=13;i<=66;i++)
  if(i%3!=0)
     { 	gotoxy(i,10);
	cout<<"д";
      }for(i=18;i<=45;i++)
  if(i%3==0)
     { 	gotoxy(i,10);
	cout<<char(194);
      }for(i=46;i<=63;i++)
  if(i%3==0)
     { 	gotoxy(i,10);
	cout<<"е";
      }gotoxy(18,10);
cout<<"е";
for(i=12;i<=66;i++)
 if(i%3==0)
  for(j=10;j<=16;j++)
   if(j%2!=0)
    {  gotoxy(i,j);
      cout<<"Ё";
     }for(i=15;i<=63;i++)
 if(i%3==0)
  for(j=12;j<=14;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"е";
     }for(i=15;i<=63;i++)
 if(i%3==0)
  for(j=12;j<=14;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"е";
     }for(i=12;i<=66;i++)
 if(i%3==0)
  for(j=12;j<=66;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"д";
     }for(i=15;i<=42;i++)
 if(i%3==0)
  {gotoxy(i,16);
    cout<<"е";
   }for(i=45;i<=63;i++)
 if(i%3==0)
  { gotoxy(i,16);
    cout<<"а";
   }for(i=12;i<=42;i++)
 if(i%3==0)
  {  gotoxy(i,17);
    cout<<"Ё";
   } gotoxy(12,18);
cout<<"ю";
for(i=12;i<=42;i++)
 if(i%3!=0)
  {  gotoxy(i,18);
   cout<<"д";
  }  cout<<"ы";
for(i=15;i<=40;i++)
 if(i%3==0)
  {  gotoxy(i,18);
   cout<<"а";
   } for(i=6;i<=16;i++)
 if(i%2==0)
  {   gotoxy(12,i);
   cout<<"ц";
  } for(i=6;i<=14;i++)
 if(i%2==0)
  { gotoxy(66,i);
   cout<<"╢";
   }gotoxy(66,16);
cout<<"ы";
gotoxy(12,20);
cout<<"з";
for(i=13;i<=23;i++)
 {gotoxy(i,20);
   cout<<"д";
 }for(i=24;i<=63;i++)
 if(i%3==0)
  {gotoxy(i,20);
   cout<<char(194);
  }for(i=24;i<=66;i++)
 if(i%3!=0)
  { gotoxy(i,20);
   cout<<"д";
   cout<<"©";
    gotoxy(12,21);
cout<<"Ё";
 }
 for(i=24;i<=66;i++)
{ if(i%3==0)
  { gotoxy(i,21);
    cout<<"Ё";
   }
}
  for(i=24;i<=66;i++)
{ if(i%3==0)
  { gotoxy(i,20);
   cout<<"д";
  }cout<<"©";
  gotoxy(i,21);
cout<<"Ё";
}
for(i=24;i<=66;i++)
{ if(i%3==0)
  {gotoxy(i,21);
   cout<<"Ё";
  }gotoxy(i,22);
cout<<"ц";
}
for(i=13;i<=23;i++)
  { gotoxy(i,22);
   cout<<"д";
  }
  for(i=24;i<=63;i++)
{ if(i%3==0)
  { gotoxy(i,22);
   cout<<"е";
  }
  }
  for(i=24;i<=66;i++)
{ if(i%3!=0)
  {  gotoxy(i,22);
   cout<<"д";
  }  cout<<"╢";
      gotoxy(12,23);
cout<<"Ё";}
for(i=24;i<=66;i++)
  if(i%3==0)
   {  gotoxy(i,23);
     cout<<"Ё";
  }   gotoxy(12,24);
cout<<"ю";
for(i=13;i<=23;i++)
  {    gotoxy(i,24);
    cout<<"ю";
  }    for(i=24;i<=63;i++)
 if(i%3==0)
   {  gotoxy(i,24);
     cout<<"а";
   } for(i=24;i<=66;i++)
  if(i%3!=0)
    { gotoxy(i,24);
      cout<<"д";
    }cout<<"ы";
gotoxy(11,25);
cout<<"\n\tPRESS ANY KEY FOR MAIN MENU.";
settextstyle(3,0,1);
setcolor(9);
outtextxy(97,60,"H");
setcolor(6);
outtextxy(97,90,"Li");
//cout<<"Li";
outtextxy(95,125,"Na");
//cout<<"Na";
outtextxy(97,153,"K");
//cout<<"K";

gotoxy(15,7); cout<<"Ё";
for (i=13;i<66;i++)
 {
 gotoxy(i,14);cout<<"д";
 gotoxy(i,12);cout<<"д";
 gotoxy(i,16);cout<<"д";
 if(i>42) {gotoxy(i,18);cout<<"  ";}
 if(i%3==0)
  {
  gotoxy(i,14);cout<<"е";
  gotoxy(i,12);cout<<"е";
  gotoxy(i,16);cout<<"е";
  if(i>42) gotoxy(i,16);cout<<"а";
  }
 }

for (i=23;i<66;i++)
 {
 gotoxy(i,20);cout<<"д";
 gotoxy(i,22);cout<<"д";
 gotoxy(i-11,24);cout<<"д";
 gotoxy(i,24);cout<<"д";
 if(i%3==0)
  {
  gotoxy(i,20);cout<<"б";
  gotoxy(i,22);cout<<"е";
  gotoxy(i,24);cout<<"а";
  }
 }
 for (i=23;i<66;i++)
 {
 if(i%3==0)
  if(i>10)
   {
   gotoxy(i,24);
   cout<<"а";
   }
 }

for(i=67;i<=80;i++) {gotoxy(i,24);cout<<"м";}
for(i=0;i<=10;i++) {gotoxy(i,25);cout<<" ";}
for(i=19;i<=47;i++) {gotoxy(i,9);cout<<" ";}
for(i=2;i<=5;i++) {gotoxy(61,i);cout<<" ";}

gotoxy(12,22);cout<<"ц";
gotoxy(66,20);cout<<"© ";
gotoxy(12,24);cout<<"юд";
gotoxy(80,24);cout<<"╪";
gotoxy(59,9);cout<<" ";
gotoxy(56,9);cout<<" ";
outtextxy(95,187,"Rb");
outtextxy(95,220,"Cs");
outtextxy(97,250,"Fr");
outtextxy(119,90,"Be");
outtextxy(118,125,"Mg");
outtextxy(118,153,"Ca");
outtextxy(121,187,"Sr");
outtextxy(120,220,"Ba");
outtextxy(120,250,"Ra");
setcolor(3);
outtextxy(143,153,"Sc");
outtextxy(145,187,"Y");
setcolor(GREEN);
outtextxy(143,220,"La");
outtextxy(143,250,"Ac");
setcolor(3);
outtextxy(170,153,"Ti");
outtextxy(167,187,"Zr");
outtextxy(167,220,"Hf");
outtextxy(167,250,"Rf");
outtextxy(195,153,"V");
outtextxy(190,187,"Nb");
outtextxy(190,220,"Ta");
outtextxy(190,250,"Ha");
outtextxy(215,153,"Cr");
outtextxy(214,187,"Mo");
outtextxy(215,220,"W");
outtextxy(215,250,"Sg");
outtextxy(238,153,"Mn");
outtextxy(238,187,"Tc");
outtextxy(238,220,"Re");
outtextxy(238,250,"Bh");
outtextxy(263,153,"Fe");
outtextxy(263,187,"Ru");
outtextxy(263,220,"Os");
outtextxy(263,250,"Hs");
outtextxy(286,153,"Co");
outtextxy(286,187,"Rh");
outtextxy(292,220,"Ir");
outtextxy(288,250,"Mt");
outtextxy(313,153,"Ni");
outtextxy(311,187,"Pd");
outtextxy(311,220,"Pt");
outtextxy(311,250,"Ds");
outtextxy(334,153,"Cu");
outtextxy(334,187,"Ag");
outtextxy(334,220,"Au");
outtextxy(358,153,"Zn");
outtextxy(358,187,"Cd");
outtextxy(358,220,"Hg");
setcolor(10);
outtextxy(388,90,"B");
setcolor(12);
outtextxy(385,125,"Al");
outtextxy(382,153,"Ga");
outtextxy(385,187,"In");
outtextxy(385,220,"Tl");
setcolor(9);
outtextxy(410,90,"C");
setcolor(GREEN);
outtextxy(408,125,"Si");
outtextxy(406,153,"Ge");
setcolor(12);
outtextxy(406,187,"Sn");
outtextxy(407,220,"Pb");
setcolor(9);
outtextxy(435,90,"N");
outtextxy(435,125,"P");
setcolor(GREEN);
outtextxy(430,153,"As");
outtextxy(430,187,"Sb");
setcolor(12);
outtextxy(433,220,"Bi");
setcolor(9);
outtextxy(458,90,"O");
outtextxy(455,125,"S");
outtextxy(455,153,"Se");
setcolor(GREEN);
outtextxy(455,187,"Te");
outtextxy(455,220,"Po");
setcolor(YELLOW);
outtextxy(484,90,"F");
outtextxy(480,125,"Cl");
outtextxy(480,153,"Br");
outtextxy(484,187,"I");
outtextxy(480,220,"At");
outtextxy(503,60,"He");
outtextxy(503,90,"Ne");
outtextxy(503,125,"Ar");
outtextxy(503,153,"Kr");
outtextxy(503,187,"Xe");
outtextxy(503,220,"Rn");
settextstyle(3,0,1);
setcolor(GREEN);
outtextxy(95,318,"Lanthanide");
gotoxy(25,21);
cout<<"Ce";
gotoxy(28,21);
cout<<"Pr";
gotoxy(31,21);
cout<<"Nd";
gotoxy(34,21);
cout<<"Pm";
gotoxy(37,21);
cout<<"Sm";
gotoxy(40,21);
cout<<"Eu";
gotoxy(43,21);
cout<<"Gd";
gotoxy(46,21);
cout<<"Tb";
gotoxy(49,21);
cout<<"Dy";
gotoxy(52,21);
cout<<"Ho";
gotoxy(55,21);
cout<<"Er";
gotoxy(58,21);
cout<<"Tm";
gotoxy(61,21);
cout<<"Yb";
gotoxy(64,21);
cout<<"Lu";
settextstyle(3,0,1);
setcolor(GREEN);
outtextxy(108,348,"Actinides");
gotoxy(25,23);
cout<<"Th";
gotoxy(28,23);
cout<<"Pa";
gotoxy(31,23);
cout<<"U";
gotoxy(34,23);
cout<<"Np";
gotoxy(37,23);
cout<<"Pu";
gotoxy(40,23);
cout<<"Am";
gotoxy(43,23);
cout<<"Cm";
gotoxy(46,23);
cout<<"Bk";
gotoxy(49,23);
cout<<"Cf";
gotoxy(52,23);
cout<<"Ea";
gotoxy(55,23);
cout<<"Fm";
gotoxy(58,23);
cout<<"Md";
gotoxy(61,23);
cout<<"No";
gotoxy(64,23);
cout<<"Lr";
}
void lab()
{
	clrscr();
	period rec;
	fstream f("pro.dat",ios::in|ios::binary);
	int fl=0,an1;
	printf("\n\t\t\t===Welcome To Laboratary===");
	cout<<"\n\n\n\tEnter Atomic Number Of The Element For Reactions: ";
	cin>>an1;
	while(f.read((char *)&rec,sizeof(period)))
	{
		if(rec.an==an1)
		{
			fl=rec.an;
			break;
		}
	}
	if(fl==1)
	{
		cout<<"\n\n-->Hydrogen with air: ";
		cout<<"\n\t\t2H2(g) + O2(g) -> 2H2O(l)";
		cout<<"\n\n-->Hydrogen with water: ";
		cout<<"\n\t\tHydrogen does not react with water.";
		cout<<"\n\n-->Hydrogen with halogens: ";
		cout<<"\n\t\t2H2(g) + O2(g) -> 2H2O(l)";
		cout<<"\n\n-->Hydrogen with acids: ";
		cout<<"\n\t\tHydrogen does not react with dilute acids.";
		cout<<"\n\n-->Hydrogen with bases: ";
		cout<<"\n\t\tHydrogen does not react with dilute bases.";

	}
	if(fl==2)
	{
		cout<<"\n\n-->Helium with air: ";
		cout<<"\n\t\tHelium does not react with air, even under extreme conditions.";
		cout<<"\n\n-->Helium with water: ";
		cout<<"\n\t\tHelium does not react with water. ";
		cout<<"\n\n-->Helium with halogens: ";
		cout<<"\n\t\tHelium does not react with any of the halogens.";
		cout<<"\n\n-->Helium with acids: ";
		cout<<"\n\t\tHelium does not react with acids.";
		cout<<"\n\n-->Helium with bases: ";
		cout<<"\n\t\tHelium does not react with any bases.";
	}
	if(fl==3)
	{
		cout<<"\n\n-->Lithium with air: ";
		cout<<"\n\t\t2Li(s) + O2(g) -> 2LI2O2(s)";
		cout<<"\n\n-->Lithium with water: ";
		cout<<"\n\t\t2Li(s) + 2H2O -> 2LiOH(aq) + H2(g)";
		cout<<"\n\n-->Lithium with halogens: ";
		cout<<"\n\t\t2Li(s) + F2(g) -> LiF(s)\n\t\t2Li(s) + CL2(g) -> LiCl(s)";
		cout<<"\n\n-->Lithium with acids: ";
		cout<<"\n\t\t2Li(s) + H2SO4(aq) -> 2Li+(aq) + SO42-(aq) + H2(g)";
		cout<<"\n\n-->Lithium with bases: ";
		cout<<"\n\t\t2Li(s) + 2H2O -> 2LiOH(aq) + H2(g)";
	}
	if(fl==4)
	{
		cout<<"\n\n-->Beryllium with air: ";
		cout<<"\n\t\t2Be(s) + O2(g) -> 2BeO(s)\n\t\t3Be(s) + N2(g) -> Be3N2(s)";
		cout<<"\n\n-->Beryllium with water: ";
		cout<<"\n\t\tBeryllium metal does not react with water or steam, even if the metal is heated to red heat.";
		cout<<"\n\n-->Beryllium with halogens: ";
		cout<<"\n\t\tBe(s) + Cl2(g) -> BeCl2(s)\n\t\tBe(s) + Br2(g) -> BeBr2(s)";
		cout<<"\n\n-->Beryllium with acids: ";
		cout<<"\n\t\tBe(s) + H2SO4(aq) -> Be2+(aq) + SO42-(aq) + H2(g)";
		cout<<"\n\n-->Beryllium with bases: ";
		cout<<"\n\t\tBeryllium metal dissolves readily in dilute aquesous base solutions.";
	}
	if(fl==5)
	{
		cout<<"\n\n-->Boron with air: ";
		cout<<"\n\t\t4B + 3O2(g) -> 2B2O3(s)";
		cout<<"\n\n-->Boron with water: ";
		cout<<"\n\t\tBoron does not react with water under normal conditions.";
		cout<<"\n\n-->Boron with halogens: ";
		cout<<"\n\t\t2B(s) + 3F2(g) -> 2BF3(g)\n\t\t2B(s) + 3Cl2(g) -> 2BCl3(g)\n\t\t2B(s) + 3Br2(g) -> 2BF3(l)";
		cout<<"\n\n-->Boron with acids: ";
		cout<<"\n\t\tCrystalline boron does not react with boiling hydrochloric acid";
		cout<<"\n\n-->Boron with bases: ";
		cout<<"\n\t\tBoron does not react with any bases.";
	}
	if(fl==6)
	{
		cout<<"\n\n-->Carbon with air: ";
		cout<<"\n\t\tC(s) + O2(g) -> CO2(g)";
		cout<<"\n\n-->Carbon with water: ";
		cout<<"\n\t\tC + H2O -> CO + H2";
		cout<<"\n\n-->Carbon with halogens: ";
		cout<<"\n\t\tC(s) + excess F2(g) -> CF4(g) + C2F6 + C5F12";
		cout<<"\n\n-->Carbon with acids: ";
		cout<<"\n\t\tGraphite reacts with the oxidizing acid hot concentrated nitric acid to form mellitic acid.";
		cout<<"\n\n-->Carbon with bases: ";
		cout<<"\n\t\tCarbon does not react with any bases.";
	}
	if(fl==7)
	{
		cout<<"\n\n-->Nitrogen with air: ";
		cout<<"\n\t\tNitrogen gas does not react with air under normal conditions.";
		cout<<"\n\n-->Nitrogen with water: ";
		cout<<"\n\t\tNitrogen gas does not react with water.";
		cout<<"\n\n-->Nitrogen with halogens: ";
		cout<<"\n\t\tNitrogen gas appears not to react with ha;ogens under normal conditions.";
		cout<<"\n\n-->Nitrogen with acids: ";
		cout<<"\n\t\tNitrogen gas does not react with acids under normal conditions.";
		cout<<"\n\n-->Nitrogen with bases: ";
		cout<<"\n\t\tNitrogen gas does not react with bases under normal conditions.";
	}
	if(fl==8)
	{
		cout<<"\n\n-->Oxygen with air: ";
		cout<<"\n\t\tOxygen gas does not react with itself or nitrogen under normal conditions.";
		cout<<"\n\n-->Oxygen with water: ";
		cout<<"\n\t\tOxygen gas does not react with water.";
		cout<<"\n\n-->Oxygen with halogens: ";
		cout<<"\n\t\tO2(g) + F2(g) -> F2O2(g)";
		cout<<"\n\n-->Oxygen with acids: ";
		cout<<"\n\t\tOxygen gas does not react with most acids under normal conditions.";
		cout<<"\n\n-->Oxygen with bases: ";
		cout<<"\n\t\tOxygen gas does not react with most bases under normal conditions.";
	}
	if(fl==9)
	{
		cout<<"\n\n-->fluorine with air: ";
		cout<<"\n\t\t2F2(g) + 2H2O(g) -> O2(g) + 4HF(g)";
		cout<<"\n\n-->fluorine with water: ";
		cout<<"\n\t\t3F2(g) + 3H2O(l) -> O3(g) + 6HF(aq)";
		cout<<"\n\n-->fluorine with halogens: ";
		cout<<"\n\t\tCl2(g) + F2(g) -> 2ClF(g)\n\t\tCl2(g) + 3F2(g) -> 2ClF3(g)\n\t\tCl2(g) + 5F2(g) -> 2ClF5(g)";
		cout<<"\n\n-->fluorine with acids: ";
		cout<<"\n\t\t2F2(g) + 2H2O(l) -> O2(g) + 4HF(aq)\n\t\t3F2(g) + 3H2O(l) -> O3(g) + 6HF(aq)";
		cout<<"\n\n-->fluorine with bases: ";
		cout<<"\n\t\t2F2(g) + 2OH-(aq) -> OF2(g) + 2F-(aq) + H2O(l)";
	}
	if(fl==10)
	{
		cout<<"\n\n-->Neon with air: ";
		cout<<"\n\t\tNeon does not react with air, even under extreme conditions.";
		cout<<"\n\n-->Neon with water: ";
		cout<<"\n\t\tNeon does not react with water.";
		cout<<"\n\n-->Neon with halogens: ";
		cout<<"\n\t\tNeon does not react with any of the halogens.";
		cout<<"\n\n-->Neon with acids: ";
		cout<<"\n\t\tNeon does not react with any acids.";
		cout<<"\n\n-->Neon with bases: ";
		cout<<"\n\t\tNeon does not react with any bases.";
	}
	if(an1>10)
		cout<<"\n\nElement Reactions Are In Process.\n\n\t\t\t===Please Visit Later===";
	f.close();
}
void exit1()
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t======Thanks For Using E-Periodic Table=======";
	getch();
	exit(0);
}
void mainmenu()
{
	int c;
	while(1)
	{
		clrscr();
		cout<<"\t\t\t========MAIN MENU========";
		cout<<"\n\n\t1: Search Element.";
		cout<<"\n\n\n\t2: Add Element.";
		cout<<"\n\n\n\t3: Modify Element.";
		cout<<"\n\n\n\t4. Display Atomic No/Symbol.";
		cout<<"\n\n\n\t5: Display Periodic Table Graphically.";
		cout<<"\n\n\n\t6. Enter The Lab.";
		cout<<"\n\n\n\t7: Exit";
		cout<<"\n\n\n\tEnter Your Choice: ";
		cin>>c;
		switch(c)
		{
			case 1: search();
				getch();
				break;
			case 2: clrscr();
				char pass[13];
				char ch;
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Password: ";
				int i=0;
				while(1)
				{
					ch=getch();
					if(ch==13)
					{
						pass[i]='\0';
						break;
					}
					else
					{
						pass[i++]=ch;
						cout<<"*";
					}
				}
				if(strcmp(pass,"private")==0)
				{
					conadd();
				}
				else
					cout<<"\n\n\t\t\tAccess Denied.";
				getch();
				break;
			case 3: clrscr();
				char passm[13];
				char ch1;
				cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Password: ";
				int j=0;
				while(1)
				{
					ch1=getch();
					if(ch1==13)
					{
						passm[j]='\0';
						break;
					}
					else
					{
						passm[j++]=ch1;
						cout<<"*";
					}
				}
				if(strcmp(passm,"private")==0)
				{
					modify();
				}
				else
					cout<<"\n\n\t\t\tAccess Denied.";
				getch();
				break;
			case 4: disp();
				getch();
				break;

			case 5:	display();
				getch();
				closegraph();
				break;
			case 6:
				lab();
				getch();
				break;

			case 7: exit1();
		}
	}
}
void main()
{
	welcomescr();
	getch();
	closegraph();
	mainmenu();
	getch();
}