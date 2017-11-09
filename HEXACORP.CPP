#include<iostream.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include"mynhead.h"
#include"mainhead.h"
#include"NEWW.h"

int ok=0;
void access();
void submenu();
void disp();

//MAIN CONTROL FOR DBMS


 char subch;
 int ch;
 char bch;
 int ech;

void recent::recent_feed()
{
 ofstream r;
 r.open("recent.dat",ios::binary|ios::out|ios::app);
 {
   cout<<"\nDATE: ";
   gets(re.date);
   //r<<"\nDATE: "<<re.date;
   cout<<"\nNEWS: ";
   gets(re.strrecent);
  // r<<"\nNEWS: "<<re.strrecent;
   r.write((char*)&re,sizeof(recent));
 }

 r.close();
}

void recent::recent_view()
{
 ifstream r;
  r.open("recent.dat",ios::in|ios::binary);


  r.read((char*)&re,sizeof(re));

 while(r)
 { cout<<"\nDATE: "<<re.date<<"\nNEWS: "<<re.strrecent;
   r.read((char *)&re,sizeof(re));
 }


 r.close();
}

void device::devices_feed()
{
 fstream d;
 d.open("devices.dat",ios::out|ios::binary|ios::app);
 {
   cout<<"\nEnter Device Name: ";
   gets(de.device);
  // d<<"\nDEVICE: "<<device;
   cout<<"\nEnter Device Details: ";
   gets(de.devices_details);
   d.write((char*)&de,sizeof(de));
   //d<<"\nDEVICE DETAILS: "<<de.device_details;
 }
 d.seekg(0);
 d.close();
}

void device::devices_view()
{
 fstream d;
 d.open("devices.dat",ios::in|ios::binary);
 d.read((char*)&de,sizeof(de));
 while(d)
 {
   cout<<"\nDEVICE: "<<de.device<<"\nDEVICE DETAILS: "<<de.devices_details;
   d.read((char*)&de,sizeof(de));
 }
 d.close();
}

void os::os_feed()
{
 fstream o;
 o.open("os.dat",ios::out|ios::in|ios::app|ios::binary);
 {
  cout<<"\nEnter OS publishing date:";
  gets(os.dateos);
  //os<<"\nOS PUBLISH DATE: "<<dateos;
  cout<<"\nEnter OS Name: ";
  gets(os.newos);
  //os<<"\nOS: "<<newos;
  cout<<"\nEnter OS Details: ";
  gets(os.whatsnewos);
  o.write((char*)&os,sizeof(os));
  //os<<"\nOS DETAILS: "<<whatsnewos;
 }

 o.close();
}

void os::os_view()
{
 fstream o;
 o.open("os.dat",ios::in|ios::binary);
 o.read((char*)&os,sizeof(os));
 while(o)
 {
     cout<<"\nOS PUBLISH DATE: "<<os.dateos;
     cout<<"\nOS NAME: "<<os.newos;
     cout<<"\nOS DETAILS: "<<os.whatsnewos;
     o.read((char*)&os,sizeof(os));
 }
 o.close();
}

void dloads::dloads_feed()
{
 fstream dload;
 dload.open("dload.dat",ios::in|ios::out|ios::app|ios::binary);

  cout<<"\nEnter New Download Publishing Date: ";
  gets(dl.datedload);
  //dload<<"\nNEW DOWNLOAD PUBLISHING DATE: "<<datedload;
  cout<<"\nEnter Download Title: ";
  gets(dl.newdload);
  //dload<<"\nDOWNLOAD: "<<newdload;
  cout<<"\nEnter Download Details: ";
  gets(dl.whatsnewdload);
  //dload<<"\nDOWNLOAD DETAILS: "<<whatsnewdload;
  dload.write((char*)&dl,sizeof(dl));

 dload.seekg(0);
 dload.close();
}

void dloads::dloads_view()
{
 fstream dload;
 dload.open("dload.dat",ios::in|ios::binary);
 dload.read((char*)&dl,sizeof(dl));
 while(dload)
 {

   cout<<"\nDATE: "<<dl.datedload;
   cout<<"\nDOWNLOAD: "<<dl.newdload;
   cout<<"\nDETAILS: "<<dl.whatsnewdload;
  dload.read((char*)&dl,sizeof(dl));
 }
 dload.close();
}

void jobs::jobs_feed()
{
 fstream j;
 j.open("jobs.dat",ios::out|ios::in|ios::app|ios::binary);
 {
  cout<<"\nEnter available position: ";
  gets(jo.avail);
  cout<<"\nEnter details regarding position : ";
  gets(jo.details);
  //j<<"\nAVAILABLE POSITION: "<<avail;
  //j<<"\nPOSITION DETAILS: "<<details;
  j.write((char*)&jo,sizeof(jo));
  j.seekg(0);
 }
 j.close();
}

void jobs::jobs_view()
{
 fstream j;
 j.open("jobs.dat",ios::in|ios::binary);
 j.read((char*)&jo,sizeof(jo));
 while(j)
 {


   cout<<"\nAVAILABLE POSITION: "<<jo.avail;
   cout<<"\nPOSITION DETAILS: "<<jo.details;
   j.read((char*)&jo,sizeof(jo));

 }
 j.close();
}

void submenu()
{
 cout<<"\nA> FEED";
 cout<<"\nB> VIEW";
 cout<<"\nEnter : ";
 cin>>subch;
}

void guest()
{
 system("cls");
 cout<<"\nLOGGED IN VIA GUEST ACCOUNT";
 do {
 cout<<"\n\t\t\t   ";
 cout<<"1* Recent News ";
 cout<<"\n\t\t\t   ";
 cout<<"2* Devices ";
 cout<<"\n\t\t\t   ";
 cout<<"3* Operating Systems ";
 cout<<"\n\t\t\t   ";
 cout<<"4* Downloads ";
 cout<<"\n\t\t\t   ";
 cout<<"5* About HEXA-CORP. ";
 cout<<"\n\t\t\t   ";
 cout<<"6* Contact Us ";
 cout<<"\n\t\t\t   ";
 cout<<"7* Jobs";
 cout<<"\n\t\t\t   ";
 cout<<"8* Sign Out";
 cout<<"\n\t\t\t   ";
 cout<<"9* EXIT";
 cout<<"\nYour Entry : ";    //Input at the Menu
 cin>>ch;

 switch(ch)                    //CONTROLS ONLY AVAILABLE TO ADMIN(S)
   {
     case 1 : re.recent_view();
	      getch();
	      clrscr();
	      break;
     case 2 : de.devices_view();
	      getch();
	      clrscr();
	      break;
     case 3 : os.os_view();
	      getch();
	      clrscr();
	      break;
     case 4 : dl.dloads_view();
	      getch();
	      clrscr();
	      break;
     case 5 : cout<<"\nHexagon Corporation or HEXA-CORP "
		  <<"was founded in the year 2014 "
		  <<"by Sumit Saha and Priyankar Jain "
		  <<"while they were in their Secondary School. "
		  <<"The company started   off with C based computer software "
		  <<"for windows development. "
		  <<"Later they emerged  as a major software and hardware company "
		  <<"The company has now been fully \nestablished.... ";
	      getch();
	      clrscr();
	      break;
     case 6 : cout<<"\nSumit Saha * 8447031665";
	      cout<<"\nPriyankar Jain * 8510860516";
	      cout<<"\nHeadQuarters * New Delhi * 011-26866379";
	      getch();
	      clrscr();
	      break;
     case 7 : jo.jobs_view();
	      getch();
	      clrscr();
	      break;
     case 8 : disp();
     case 9 : exit(0);
     default: cout<<"\nUNAVAILABLE CHOICE.";
	      break;
   }
 cout<<"\n\n\t\t\t      Browse Further ? ";
 cin>>bch;
   }while(bch=='y'||bch=='Y');
 if(ch!='y'||ch!='Y')
 exit(0);
 getch();
}

void email::email_feed()
{
 emailstart_feed:
 {
  system("cls");
  cout<<" --------------------\n";
  cout<<"|INTER e-MAIL KONNECT|\n";
  cout<<" --------------------";
  cout<<"\nSend an e-mail to : ";
  cout<<"\n1> priyankarjain13@gmail.com";
  cout<<"\n2> sumit.saha666@gmail.com";
  cout<<"\n3> resourcecentre@hexagon.com";
  cout<<"\n4> businessdepartment@haxagon.com";
  cout<<"\nEnter choice : ";
  cin>>ech;
  if(ech==1)
  {
   fstream pj;
   pj.open("pjemail.dat",ios::binary|ios::out|ios::in|ios::app);
   cout<<"\nSUBJECT: ";
   gets(em.emailsub);
   cout<<"\nCONTENT: ";
   gets(em.emailcontent);
   pj.write((char*)&em,sizeof(em));
  /* pj<<"\nSUBJECT: "<<emailsub;
   pj<<"\nCONTENT: "<<emailcontent;*/
   pj.seekg(0);
   pj.close();
  }
  else if(ech==2)
  {
   fstream ss;
   ss.open("ssemail.dat",ios::out|ios::in|ios::app);
   cout<<"\nSUBJECT: ";
   gets(em.emailsub);
   cout<<"\nCONTENT: ";
   gets(em.emailcontent);
   //ss<<"\nSUBJECT: "<<emailsub;
   //ss<<"\nCONTENT: "<<emailcontent;
   ss.write((char*)&em,sizeof(em));
   ss.seekg(0);
   ss.close();
  }
  else if(ech==3)
  {
   fstream rc;
   rc.open("rcemail.dat",ios::out|ios::in|ios::app);
   cout<<"\nSUBJECT: ";
   gets(em.emailsub);
   cout<<"\nCONTENT: ";
   gets(em.emailcontent);
   rc.write((char*)&em,sizeof(em));
   //rc<<"\nSUBJECT: "<<em.emailsub;
   //rc<<"\nCONTENT: "<<em.emailcontent;
   rc.seekg(0);
   rc.close();
  }
  else if(ech==4)
  {
   fstream bd;
   bd.open("bdemail.dat",ios::out|ios::in|ios::app);
   cout<<"\nSUBJECT: ";
   gets(em.emailsub);
   cout<<"\nCONTENT: ";
   gets(em.emailcontent);
   bd.write((char*)&em,sizeof(em));
   //bd<<"\nSUBJECT: "<<emailsub;
   //bd<<"\nCONTENT: "<<emailcontent;
   bd.seekg(0);
   bd.close();
  }
 else
  {
   cout<<"\nWrong choice ";
   goto emailstart_feed;
  }
 }
}

void email::email_view()
{
 emailstart_view:
 system("cls");
 cout<<" --------------------\n";
 cout<<"|INTER e-MAIL KONNECT|\n";
 cout<<" --------------------";
 cout<<"\nView e-mail of : ";
 cout<<"\n1> priyankarjain13@gmail.com";
 cout<<"\n2> sumit.saha666@gmail.com";
 cout<<"\n3> resourcecentre@hexagon.com";
 cout<<"\n4> businessdepartment@haxagon.com";
 cout<<"\nEnter choice : ";
 cin>>ech;
 if(ech==1)
 {
  fstream pj;
  pj.open("pjemail.dat",ios::in,ios::binary|ios::app);
  pj.read((char *)&em,sizeof(em));
  while(pj)
  {
  cout<<"\nSUBJECT: "<<em.emailsub;
  cout<<"\nCONTENT: "<<em.emailcontent;
  pj.read((char *)&em,sizeof(em));
  }
  pj.close();
 }
 else if(ech==2)
 {
  fstream ss;
  ss.open("ssemail.dat",ios::out|ios::in|ios::app|ios::binary);
  ss.read((char *)&em,sizeof(em));
  while(ss)
  {
  cout<<"\nSUBJECT: "<<em.emailsub;
  cout<<"\nCONTENT: "<<em.emailcontent;
  ss.read((char *)&em,sizeof(em));
  }
  ss.close();
 }
 else if(ech==3)
 {
  fstream rc;
  rc.open("rcemail.dat",ios::out|ios::in|ios::app|ios::binary);
  rc.read((char*)&em,sizeof(em));
  while(rc)
  {
  cout<<"\nSUBJECT: "<<em.emailsub;
  cout<<"\nCONTENT: "<<em.emailcontent;
  rc.read((char*)&em,sizeof(em));
  }
  rc.close();
 }
 else if(ech==4)
 {
  fstream bd;
  bd.open("bdemail.dat",ios::out|ios::in|ios::app|ios::binary);
  bd.read((char *)&em,sizeof(em));
  while(bd)
  {
  cout<<"\nSUBJECT: "<<em.emailsub;
  cout<<"\nCONTENT: "<<em.emailcontent;
  bd.read((char *)&em,sizeof(em));
  }
  bd.close();

 }
 else
 {
  cout<<"\nWrong choice ";
  goto emailstart_view;
 }
}



void mail::usernew()
{ ofstream outfile;
  outfile.open("password.dat",ios::app,ios::binary);
  int k;
  char c;

      outtextxy(170,190,"USERNAME: ");
      //INPUT BOX FOR USERNAME
      moveto(250,180);
      lineto(250,210); //vertical_left
      moveto(450,180);
      lineto(450,210); //vertical_right
      moveto(250,180);
      lineto(450,180); //horizontal_up
      moveto(250,210);
      lineto(450,210); //horizontal_down

      outtextxy(170,240,"PASSWORD: ");
      /*INPUT BOX FOR PASSWORD */
      moveto(250,230);
      lineto(450,230); //horizontal_up
      moveto(250,260);
      lineto(450,260); //horizontal_down
      moveto(250,230);
      lineto(250,260); //vertical_left
      moveto(450,230);
      lineto(450,260); //vertical_right

      /*CODE FOR PYRO TAG */
      moveto(500,180);
      lineto(550,180);
      moveto(500,180);
      lineto(475,215);
      moveto(475,215);
      lineto(500,250);
      moveto(500,250);
      lineto(550,250);
      moveto(550,250);
      lineto(575,215);
      moveto(575,215);
      lineto(550,180);
      outtextxy(497,200,"HEXAGON");
      outtextxy(510,215,"PyRo");
      outtextxy(510,225,"2014");

      /*CODE FOR SECURE TAG*/
      outtextxy(520,450,"HEXASECURED");
      /*CODE FOR TYPE */
      outtextxy(20,450,"OFFLINE DBMS");
      outtextxy(240,191,">");// ( > ) the sign represents CURRENT INPUT BOX
      gotoxy(33,13);


      outtextxy(240,241,">");
      gotoxy(33,13);



  gets(user.name);

  gotoxy(33,16);
  for(k=0; ; k++)
    { c=getch();

      if((c!=8) && (c!=13))
       { user.pass[k]=c;
	cout<< "*";
       }

      if(c==8)
	{ if(k>0)
	    {
	      k-=2;
	      user.pass[k+1]='\0';
	     cout<<'\b'<<' '<<'\b';
	    }
	}

     if(c==13)
     { break;}


    }



  outfile.write((char*)&user,sizeof(user));

  outfile.close();
  char ans;
  outtextxy(120,280,"\n DO YOU NOW WANT TO LOGIN: ");
  gotoxy(45,18);
  cin>>ans;
  getch();
  if(ans=='y'||ans=='Y')
  { disp();}
  else{exit(0);}

}

void mail::exist()
{   int i;
    char c;

  ifstream infile("password.dat",ios::binary);


  cout<<"\n ENTER USER NAME: ";
  cin>>nuser.username;
  cout<<"\n ENTER PASS : ";
  for(i=0; ; i++)
    { c=getch();

      if((c!=8)&&(c!=13))
     { nuser.userpass[i]=c;
       cout<<"*";
     }

      else if(c==8)
	{ i-=2;
	  nuser.userpass[i+1]='\0';
	  cout<<'\b'<<' '<<'\b';}

      else if(c==13)
      break;
    }

     clrscr();
     int gdriver = EGA, gmode = EGAHI, errorcode;
     initgraph(&gdriver,&gmode,"");
  setbkcolor(5);
      cout<<"\n AUTHENTICATING";
      for(int p=0; p<6; p++)
      { delay(250);
     cout<<".";
     }
     delay(1000);
     int flag=0;
     while(!infile.eof())
     {
	infile.read((char*)&s1,sizeof(s1));
	if(!strcmp(s1.name,nuser.username))
	{

	  if(!strcmp(s1.pass,nuser.userpass))
	    { flag=1;
	    }
	}

      }
    if(flag==1)
    {cout<<"\n\a ACCESS GRANTED";
    disp();}
    else
    { cout<<"\n\a !!!!!ACCESS DENIED";
	   cout<<"\n EITHER NAME OR PASSWORD IS INCORRECT\n\n"; }
  infile.close();

  getch();

  clrscr();
}

void disp()
 {
   clrscr();
    start:
   char firstname[80];
   char lastname[80];
   char peruser[80];
   char perpass[80];
   char confirmperpass[80];
   int ch,flag=0;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   char msg[80];

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

    /* code for the welcome border line segments */
     moveto(10, 10);
     lineto(10, 470); //vertical_left
     moveto(630,10);
     lineto(630,470); //vertical_right
     moveto(10,470);
     lineto(630,470); //horizontal_down
     moveto(10,10);
     lineto(630,10);  //horizontal_up

     outtextxy(250,100,"HEXAGON INCORPORATED");
     outtextxy(250,106,"------- ------------");

     char input;
     outtextxy(60,120,"===========");
     outtextxy(60,130,"|NEW USER?|");
     outtextxy(60,140,"===========");
     gotoxy(20,9);
     cin>>input;

     //FIRST CHOICE OF INPUT FOR ( NO ) !

     if(input=='n'||input=='N')
     {
      outtextxy(170,190,"USERNAME: ");
      //INPUT BOX FOR USERNAME
      moveto(250,180);
      lineto(250,210); //vertical_left
      moveto(450,180);
      lineto(450,210); //vertical_right
      moveto(250,180);
      lineto(450,180); //horizontal_up
      moveto(250,210);
      lineto(450,210); //horizontal_down

      outtextxy(170,240,"PASSWORD: ");
      /*INPUT BOX FOR PASSWORD */
      moveto(250,230);
      lineto(450,230); //horizontal_up
      moveto(250,260);
      lineto(450,260); //horizontal_down
      moveto(250,230);
      lineto(250,260); //vertical_left
      moveto(450,230);
      lineto(450,260); //vertical_right

      /*CODE FOR PYRO TAG */
      moveto(500,180);
      lineto(550,180);
      moveto(500,180);
      lineto(475,215);
      moveto(475,215);
      lineto(500,250);
      moveto(500,250);
      lineto(550,250);
      moveto(550,250);
      lineto(575,215);
      moveto(575,215);
      lineto(550,180);
      outtextxy(497,200,"HEXAGON");
      outtextxy(510,215,"PyRo");
      outtextxy(510,225,"2014");

      /*CODE FOR SECURE TAG*/
      outtextxy(520,450,"HEXASECURED");
      /*CODE FOR TYPE */
      outtextxy(20,450,"OFFLINE DBMS");

      int k;
      char c;

      outtextxy(240,191,">");// ( > ) the sign represents CURRENT INPUT BOX
      gotoxy(33,13);
      gets(nuser.username);
      if(strlen(nuser.username)==0)
      outtextxy(340,191,"!");//( ! ) the sign represents LEFT BLANK

      outtextxy(240,241,">");
      gotoxy(33,16);
      int i;
      for(i=0; ; i++)
    { c=getch();

      if((c!=8)&&(c!=13))
     { nuser.userpass[i]=c;
       cout<<"*";
     }

      else if(c==8)
	{ i-=2;
	  nuser.userpass[i+1]='\0';
	  cout<<'\b'<<' '<<'\b';}

      else if(c==13)
      break;
    }
      if((strlen(nuser.username)==0)&&(strlen(nuser.userpass)==0))
      {
       guest();
      }

     ifstream infile;
   infile.open("password.dat",ios::binary);

      while(!infile.eof())
     {
	infile.read((char*)&s1,sizeof(s1));
	if(!strcmp(s1.name,nuser.username))
	{
	  if(!strcmp(s1.pass,nuser.userpass))
	    { flag=1;
	    }
	}

      }

    infile.close();

    outtextxy(310,280,"Verifying...");
    for(int a=360;a>0;a--)
    {
     delay(5);
     arc(340,310,a,a+1,15);
    }
    if(flag==1)
    {
     outtextxy(320,340,"ACCESS!");
     outtextxy(225,353,"PRESS CARRIAGE RETURN TO PROCEED");
     getch();
     access();
    }
    else if(flag==0||flag==2)
    {
     outtextxy(320,340,"DENIED");
     outtextxy(225,353,"PRESS CARRIAGE RETURN TO EXIT");
     getch();
     exit(0);
    }
    getch();
  } //INPUT OF FIRST CHOICE FOR ( N0 ) END

   //INPUT OF SECOND CHOICE FOR ( YES ) START

 else if(input=='y'||input=='Y')
   { user.usernew();
   }

     getch();
   }
 // disp() end




void access()
{
 int ch;
 char bch;
 int gdriver = DETECT, gmode, errorcode;
 /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
					     //MENU DRIVEN DBMS
do {
 system("cls");
 cout<<"\n\t\t\t   ";
 cout<<"HEXAGON DATABASE CENTRAL";
 cout<<"\n";
 /*MENU*/
 cout<<"\n\t\t\t   ";
 cout<<"1* Recent News ";
 cout<<"\n\t\t\t   ";
 cout<<"2* Devices ";
 cout<<"\n\t\t\t   ";
 cout<<"3* Operating Systems ";
 cout<<"\n\t\t\t   ";
 cout<<"4* Downloads ";
 cout<<"\n\t\t\t   ";
 cout<<"5* About HEXA-CORP. ";
 cout<<"\n\t\t\t   ";
 cout<<"6* Contact Us ";
 cout<<"\n\t\t\t   ";
 cout<<"7* Jobs";
 cout<<"\n\t\t\t   ";
 cout<<"8* Inter e-Mail KONNECT";
 cout<<"\n\t\t\t   ";
 cout<<"9* Sign Out";
 cout<<"\n\t\t\t   ";
 cout<<"10* EXIT";
 cout<<"\nYour Entry : ";    //Input at the Menu
 cin>>ch;

 switch(ch)                    //CONTROLS ONLY AVAILABLE TO ADMIN(S)
 {
    case 1 : submenu();
	     if(subch=='A'||subch=='a')
	     re.recent_feed();
	     else if(subch=='B'||subch=='b')
	     re.recent_view();
	     break;

    case 2 : submenu();
	     if(subch=='A'||subch=='a')
	     de.devices_feed();
	     else if(subch=='B'||subch=='b')
	     de.devices_view();
	     break;
    case 3 : submenu();
	     if(subch=='A'||subch=='a')
	     os.os_feed();
	     else if(subch=='B'||subch=='b')
	     os.os_view();
	     break;
    case 4 : submenu();
	     if(subch=='A'||subch=='a')
	     dl.dloads_feed();
	     else if(subch=='B'||subch=='b')
	     dl.dloads_view();
	     break;
    case 5 : cout<<"\nHexagon Corporation or HEXA-CORP "
		 <<"was founded in the year 2014 "
		 <<"by Sumit Saha and Priyankar Jain "
		 <<"while they were in their Secondary School. "
		 <<"The company started   off with C based computer software "
		 <<"for windows development. "
		 <<"Later they emerged  as a major software and hardware company "
		 <<"The company has now been fully \nestablished.... ";
	     break;
    case 6 : cout<<"\nSumit Saha * 8447031665";
	     cout<<"\nPriyankar Jain * 8510860516";
	     cout<<"\nHeadQuarters * New Delhi * 011-26866379";
	     break;
    case 7 : submenu();
	     if(subch=='A'||subch=='a')
	     jo.jobs_feed();
	     else if(subch=='B'||subch=='b')
	     jo.jobs_view();
	     break;
    case 8 : submenu();
	     if(subch=='A'||subch=='a')
	     em.email_feed();
	     else if(subch=='B'||subch=='b')
	     em.email_view();
	     break;
    case 9 : disp();
    case 10 : exit(0);
    default: cout<<"\nUNAVAILABLE CHOICE.";
	     break;
 }
cout<<"\n\n\t\t\t      Browse Further ? ";
cin>>bch;
}while(bch=='y'||bch=='Y');
if(ch!='y'||ch!='Y')
exit(0);
getch();
}

int main()
{
 disp();
 return 0;
}

