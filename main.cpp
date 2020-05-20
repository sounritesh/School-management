#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<amp_graphics.h>
using namespace std;
class teacher
{
private:
    int tid;
    char tname[30];
    int tnofsub;
    char tsub[2][7];
    int ttt[6][8];
    int tnofclasses;
    char tclasses[6][6];
public:
    teacher()
    {
        strcpy(tclasses[0]," ");
    }
    void tgetdata(int &id);
    void tshowdata();
    void tmodidata();
    void treport(int r);
    void tgen_table(int tab[6][8]);
    void ret_ttt(int tab[6][8]);
    char *ret_tname()
    {
        return tname;
    }
    int ret_tid()
    {
        return tid;
    }
};
void teacher::ret_ttt(int tab[6][8])
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<8;j++)
            tab[i][j]=ttt[i][j];
    }
}
void teacher::tgetdata(int &id)
{
    gotoxy(10,6);
    cout<<"Teacher id generated: "<<id;
    tid=id;
    cin.ignore();
    gotoxy(10,7);
    cout<<"Enter teacher name: ";
    cin.getline(tname,30);
    gotoxy(10,8);
    cout<<"Enter no. of subjects: ";
    cin>>tnofsub;
    gotoxy(10,9);
    cout<<"Enter subjects: ";
    for(int i=0;i<tnofsub;i++)
    {
        gotoxy(26,9+i);
        cout<<i+1<<") ";
        cin>>tsub[i];
    }
    gotoxy(10,9+i);
    cout<<"Enter no. of classes: ";
    cin>>tnofclasses;
    i++;
    gotoxy(10,9+i);
    cout<<"Enter classes: ";
    for(int j=1;j<=tnofclasses;j++)
    {
        gotoxy(25,9+i);
        cout<<j<<") ";
        cin>>tclasses[j];
        i++;
    }
    tgen_table(ttt);
}
void teacher::tshowdata()
{
    gotoxy(10,3);
    cout<<"Teacher id: "<<tid;
    gotoxy(10,4);
    cout<<"Teacher name: "<<tname;
    gotoxy(10,5);
    cout<<"No. of subjects: "<<tnofsub;
    gotoxy(10,6);
    cout<<"Subjects: ";
    for(int i=0;i<tnofsub;i++)
        cout<<tsub[i]<<", ";
    gotoxy(10,7);
    cout<<"No. of classes: "<<tnofclasses;
    gotoxy(10,8);
    cout<<"Classes: ";
    for(i=1;i<=tnofclasses;i++)
        cout<<tclasses[i]<<", ";
    gotoxy(34,10);
    cout<<"TIME TABLE: ";
    int p=14;
    for(i=0;i<6;i++)
    {
        int m=9;
        gotoxy(3,12);
        cout<<"PNO";
        gotoxy(3,p);
        if(i==0)
            cout<<"MON";
        else if(i==1)
            cout<<"TUE";
        else if(i==2)
            cout<<"WED";
        else if(i==3)
            cout<<"THU";
        else if(i==4)
            cout<<"FRI";
        else
            cout<<"SAT";
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<=tnofclasses;k++)
            {
                if(ttt[i][j]==k)
                {
                    gotoxy(m+2,12);
                    cout<<j+1;
                    gotoxy(m,p);
                    cout<<tclasses[k];
                    m+=9;
                }
            }
        }
        p+=2;
    }
    for(i=11;i<=25;i+=2)
    {
        for(int j=2;j<=78;j++)
        {
            gotoxy(j,i);
            cout<<char(196);
        }
    }
    for(i=12;i<=24;i++)
    {
        gotoxy(1,i);
        cout<<char(179);
    }
    for(i=7;i<=81;i+=9)
    {
        for(int j=12;j<=24;j++)
        {
            gotoxy(i,j);
            cout<<char(179);
        }
    }
    gotoxy(1,11);
    cout<<char(218);
    gotoxy(1,25);
    cout<<char(192);
    gotoxy(79,25);
    cout<<char(217);
    gotoxy(79,11);
    cout<<char(191);
}
void teacher::tmodidata()
{
    gotoxy(10,6);
    cout<<"Teacher id: "<<tid;
    cin.ignore();
    gotoxy(10,7);
    cout<<"Enter teacher name: ";
    cin.getline(tname,30);
    gotoxy(10,8);
    cout<<"Enter no. of subjects: ";
    cin>>tnofsub;
    gotoxy(10,9);
    cout<<"Enter subjects: ";
    for(int i=0;i<tnofsub;i++)
    {
        gotoxy(26,9+i);
        cout<<i+1<<") ";
        cin>>tsub[i];
    }
    gotoxy(10,9+i);
    cout<<"Enter no. of classes: ";
    cin>>tnofclasses;
    i++;
    gotoxy(10,9+i);
    cout<<"Enter classes: ";
    for(int j=1;j<=tnofclasses;j++)
    {
        gotoxy(25,9+i);
        cout<<j<<") ";
        cin>>tclasses[j];
        i++;
    }
    tgen_table(ttt);
}
void teacher::treport(int r)
{
    gotoxy(5,r);
    cout<<tid;
    gotoxy(10,r);
    cout<<tname;
    gotoxy(33,r);
    for(int i=0;i<tnofsub;i++)
        cout<<tsub[i]<<", ";
    gotoxy(51,r);
    for(i=1;i<=tnofclasses;i++)
        cout<<tclasses[i]<<", ";
}
void teacher::tgen_table(int tab[6][8])
{
    int c[20],a;
    randomize();
    for(int i=0;i<6;)
    {
        int flag=1;
        for(int k=0;k<=tnofclasses;k++)
            c[k]=0;
        for(int j=0;j<8;j++)
        {
            do
            {
                a=random(tnofclasses+1);
            }while(c[a]>=2);
            tab[i][j]=a;
            c[a]++;
        }
        for(int m=0;m<=tnofclasses;m++)
        {
            if(c[m]==0 || c[0]<2)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            i++;
    }
}
class classes
{
private:
    char cclass[6];
    char classteacher[30];
    int cstrength;
    int ctt[6][8];
    int cnofsub;
    char csub[8][7];
public:
    classes()
    {
        strcpy(csub[0],"Games");
    }
    void cgetdata();
    void cshowdata();
    void cgen_table(int tab[6][8]);
    void add_games(int tab[6][8]);
    char *ret_cclass()
    {
        return cclass;
    }
};
void classes::cgetdata()
{
    gotoxy(10,6);
    cout<<"Enter class: ";
    cin>>cclass;
    gotoxy(10,7);
    cin.ignore();
    cout<<"Enter class teacher name: ";
    cin.getline(classteacher,30);
    gotoxy(10,8);
    cout<<"Enter class strength: ";
    cin>>cstrength;
    gotoxy(10,9);
    cout<<"Enter no. of subjects: ";
    cin>>cnofsub;
    gotoxy(10,10);
    cout<<"Enter subjects: ";
    for(int i=1;i<=cnofsub;i++)
    {
        gotoxy(26,9+i);
        cout<<i<<") ";
        cin>>csub[i];
    }
    cgen_table(ctt);
}
void classes::cshowdata()
{
    gotoxy(10,3);
    cout<<"Class: "<<cclass;
    gotoxy(10,4);
    cout<<"Class teacher: "<<classteacher;
    gotoxy(10,5);
    cout<<"Class strength: "<<cstrength;
    gotoxy(34,7);
    cout<<"TIME TABLE: ";
    int p=12;
    for(int i=0;i<6;i++)
    {
        int m=9;
        gotoxy(3,10);
        cout<<"PNO";
        gotoxy(3,p);
        if(i==0)
            cout<<"MON";
        else if(i==1)
            cout<<"TUE";
        else if(i==2)
            cout<<"WED";
        else if(i==3)
            cout<<"THU";
        else if(i==4)
            cout<<"FRI";
        else
            cout<<"SAT";
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<=cnofsub;k++)
            {
                if(ctt[i][j]==k)
                {
                    gotoxy(m+2,10);
                    cout<<j+1;
                    gotoxy(m,p);
                    cout<<csub[k];
                    m+=9;
                }
            }
        }
        p+=2;
    }
    for(i=9;i<=24;i+=2)
    {
        for(int j=2;j<=78;j++)
        {
            gotoxy(j,i);
            cout<<char(196);
        }
    }
    for(i=10;i<=22;i++)
    {
        gotoxy(1,i);
        cout<<char(179);
    }
    for(i=7;i<=81;i+=9)
    {
        for(int j=10;j<=22;j++)
        {
            gotoxy(i,j);
            cout<<char(179);
        }
    }
    gotoxy(1,9);
    cout<<char(218);
    gotoxy(1,23);
    cout<<char(192);
    gotoxy(79,23);
    cout<<char(217);
    gotoxy(79,9);
    cout<<char(191);
}
void classes::cgen_table(int tab[6][8])
{
    int c[8],a;
    randomize();
    for(int i=0;i<6;)
    {
        int flag=1;
        for(int k=0;k<cnofsub;k++)
            c[k]=0;
        for(int j=0;j<8;j++)
        {
            do
            {
                a=random(cnofsub)+1;
            }while(c[a-1]>=2);
            tab[i][j]=a;
            c[a-1]++;
        }
        for(int m=0;m<cnofsub;m++)
        {
            if(c[m]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            i++;
    }
    add_games(tab);
}
void classes::add_games(int tab[6][8])
{
    int a,b,c[8],temp;
    randomize();
    for(int i=1;i<=2;)
    {
        int flag=1;
        a=random(6);
        b=random(6)+2;
        temp=tab[a][b];
        tab[a][b]=0;
        for(int m=0;m<=cnofsub;m++)
            c[m]=0;
        for(int q=0;q<8;q++)
            c[tab[a][q]]++;
        for(int p=0;p<=cnofsub;p++)
        {
            if(c[p]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            i++;
        else
            tab[a][b]=temp;
    }
}
class arrangement
{
private:
    char date[9];
    char day[10];
    int d_code;
    int period;
    int tid;
    char tname[30];
    char cls[6];
    char val;
public:
    arrangement()
    {
        val='y';
    }
    void agetdata();
    void ashowdata();
    void areport(int r);
    void t_find();
    void ret_ttt(int tab[6][8]);
    char *ret_date()
    {
        return date;
    }
    char ret_val()
    {
        return val;
    }
};
void arrangement::agetdata()
{
    int flag=0,tab[6][8];
    teacher t;
    fstream f;
    gotoxy(10,6);
    cout<<"Enter date(dd/mm/yy): ";
    cin>>date;
    gotoxy(10,7);
    cout<<"Enter day: ";
    cin>>day;
    if(strcmpi("monday",day)==0)
        d_code=0;
    else if(strcmpi("tuesday",day)==0)
        d_code=1;
    else if(strcmpi("wednesday",day)==0)
        d_code=2;
    else if(strcmpi("thursday",day)==0)
        d_code=3;
    else if(strcmpi("friday",day)==0)
        d_code=4;
    else if(strcmpi("saturday",day)==0)
        d_code=5;
    gotoxy(10,8);
    cout<<"Enter class: ";
    cin>>cls;
    gotoxy(10,9);
    cout<<"Enter period: ";
    cin>>period;
    f.open("t.dat",ios::in|ios::binary);
    while(f.read((char*)&t,sizeof(t)))
    {
        t.ret_ttt(tab);
        if(tab[d_code][period-1]==0)
        {
            flag=1;
            break;
        }
    }
    f.close();
    if(flag==1)
        t_find();
    else
    {
        gotoxy(10,20);
        cout<<"finding substitute...";
        delay(1500);
        gotoxy(10,20);
        cout<<"No teacher available.";
        val='n';
        getch();
    }
}
void arrangement::ashowdata()
{
    gotoxy(10,6);
    cout<<"Date: "<<date;
    gotoxy(10,7);
    cout<<"Day: "<<day;
    gotoxy(10,8);
    cout<<"Period: "<<period;
    gotoxy(10,9);
    cout<<"Class: "<<cls;
    gotoxy(10,10);
    cout<<"Substitute teacher: "<<tname;
}
void arrangement::areport(int r)
{
    gotoxy(5,r);
    cout<<date;
    gotoxy(19,r);
    cout<<day;
    gotoxy(35,r);
    cout<<period;
    gotoxy(45,r);
    cout<<cls;
    gotoxy(55,r);
    cout<<tname;
}
void arrangement::t_find()
{
    int c=0,a;
    fstream f;
    teacher t;
    f.open("t.dat",ios::in|ios::binary);
    while(f.read((char*)&t,sizeof(t)))
        c++;
    f.close();
    randomize();
    for(int i=1;i<2;)
    {
        int flag=1;
        int tab[6][8];
        a=random(c)+1;
        f.open("t.dat",ios::in|ios::binary);
        while(f.read((char*)&t,sizeof(t)))
        {
            if(a==t.ret_tid())
            {
                t.ret_ttt(tab);
                if(tab[d_code][period-1]!=0)
                    flag=0;
            }
        }
        f.close();
        if(flag==1)
            i++;
    }
    tid=a;
    f.open("t.dat",ios::in|ios::binary);
    f.seekg(a*sizeof(t)-sizeof(t));
    f.read((char*)&t,sizeof(t));
    strcpy(tname,t.ret_tname());
    f.close();
}
fstream f;
int i,j;
teacher t;
classes c;
arrangement a;
void password()
{
    char pass[8],ch;
    gotoxy(25,10);
    cout<<"Enter the password: ";
    for(int i=0;i<7;i++)
    {
        ch=getch();
        pass[i]=ch;
        ch='*';
        cout<<ch;
    }
    pass[i]='\0';
    if(strcmp(pass,"mira123")!=0)
    {
        gotoxy(25,20);
        cout<<"Better luck next time!";
        delay(1000);
        exit(0);
    }
}
void load()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    password();
    int x=315,y=292;
    float v=0;
    int num=0,v2;
    while(1)
    {
        cleardevice();
        gotoxy(39,19);
        cout<<num<<"%";
        gotoxy(33,10);
        cout<<"L O A D I N G...";
        setlinestyle(0,0,1);
        setcolor(WHITE);
        circle(x,y,50);
        setlinestyle(0,0,3);
        setcolor(GREEN);
        arc(x,y,0,1+v,50);
        setcolor(RED);
        arc(x,y,120+v2,150+v2,58);
        setcolor(CYAN);
        arc(x,y,140-v2,180-v2,66);
        setcolor(RED);
        arc(x,y,200+v2,250+v2,74);
        setcolor(CYAN);
        arc(x,y,270-v2,330-v2,82);
        setcolor(RED);
        arc(x,y,290+v2,360+v2,90);
        if(num>=100)
        {
            num+=0;
            delay(500);
            cleardevice();
            gotoxy(33,12);
            cout<<"Loading Completed";
            delay(500);
            gotoxy(28,19);
            cout<<"Press any key to continue...";
            break;
        }
        v+=3.6;
        v2+=10;
        num=num+1;
        delay(50);
    }
    getch();
    closegraph();
}
void tadd()
{
    clrscr();
    f.open("t.dat",ios::ate|ios::out|ios::binary);
    int x=f.tellp()/sizeof(t);
    x++;
    t.tgetdata(x);
    f.write((char*)&t,sizeof(t));
    f.close();
    gotoxy(10,20);
    cout<<"adding teacher...";
    delay(1000);
    gotoxy(10,20);
    cout<<"generating time table...";
    delay(1000);
    gotoxy(10,20);
    cout<<"Teacher added and time table generated succesfully.";
    getch();
}
void tshow()
{
    clrscr();
    int c=0;
    gotoxy(4,3);
    cout<<"TID";
    gotoxy(14,3);
    cout<<"Teacher Name";
    gotoxy(36,3);
    cout<<"Subjects";
    gotoxy(61,3);
    cout<<"Classes";
    f.open("t.dat",ios::in|ios::binary);
    i=5;
    while(f.read((char*)&t,sizeof(t)))
    {
        t.treport(i++);
        c++;
    }
    f.close();
    for(j=5;j<=5+c;j++)
    {
        gotoxy(2,j);
        cout<<char(179);
        gotoxy(8,j);
        cout<<char(179);
        gotoxy(31,j);
        cout<<char(179);
        gotoxy(49,j);
        cout<<char(179);
        gotoxy(80,j);
        cout<<char(179);
    }
    for(j=2;j<=4;j+=2)
    {
        for(int k=3;k<=79;k++)
        {
            gotoxy(k,j);
            cout<<char(196);
        }
    }
    for(j=3;j<=4;j++)
    {
        gotoxy(2,j);
        cout<<char(179);
        gotoxy(8,j);
        cout<<char(179);
        gotoxy(31,j);
        cout<<char(179);
        gotoxy(49,j);
        cout<<char(179);
        gotoxy(80,j);
        cout<<char(179);
    }
    gotoxy(2,2);
    cout<<char(218);
    gotoxy(2,4);
    cout<<char(192);
    gotoxy(80,4);
    cout<<char(217);
    gotoxy(80,2);
    cout<<char(191);
    getch();
}
void tsearch()
{
    int flag,opt;
    do
    {
        clrscr();
        gotoxy(30,10);
        cout<<"Search Teacher";
        gotoxy(30,11);
        cout<<"--------------";
        gotoxy(20,13);
        cout<<"1. Search by Name";
        gotoxy(20,14);
        cout<<"2. Search by TID";
        gotoxy(20,15);
        cout<<"3. Back to previous menu";
        gotoxy(20,18);
        cout<<"Choose an option: ";
        cin>>opt;
        switch(opt)
        {
            case 1: clrscr();
                char name[30];
                flag=0;
                cin.ignore();
                gotoxy(10,5);
                cout<<"Enter teacher name to search for: ";
                cin.getline(name,30);
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(strcmpi(t.ret_tname(),name)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher name does not exist.";
                }
                else
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    t.tshowdata();
                }
                getch();
                break;
            case 2: clrscr();
                int id;
                flag=0;
                gotoxy(10,5);
                cout<<"Enter teacher ID to search for: ";
                cin>>id;
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(t.ret_tid()==id)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher ID does not exist.";
                }
                else
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    t.tshowdata();
                }
                getch();
                break;
            case 3:	return;
            default:gotoxy(20,17);
                cout<<"Invalid choice";
        }
    }while(1);
}
void tdelete()
{
    int flag,opt;
    do
    {
        clrscr();
        gotoxy(30,10);
        cout<<"Delete Teacher";
        gotoxy(30,11);
        cout<<"--------------";
        gotoxy(20,13);
        cout<<"1. Search by Name";
        gotoxy(20,14);
        cout<<"2. Search by TID";
        gotoxy(20,15);
        cout<<"3. Back to previous menu";
        gotoxy(20,18);
        cout<<"Choose an option: ";
        cin>>opt;
        switch(opt)
        {
            case 1: clrscr();
                char name[30];
                flag=0;
                cin.ignore();
                gotoxy(10,5);
                cout<<"Enter teacher name to delete: ";
                cin.getline(name,30);
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(strcmpi(t.ret_tname(),name)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher name does not exist.";
                }
                else
                {
                    f.open("t.dat",ios::in|ios::binary);
                    ofstream f1("temp.dat",ios::binary);
                    while(f.read((char*)&t,sizeof(t)))
                    {
                        if(strcmpi(t.ret_tname(),name)!=0)
                            f1.write((char*)&t,sizeof(t));
                    }
                    f.close();
                    f1.close();
                    remove("t.dat");
                    rename("temp.dat","t.dat");
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"deleting...";
                    delay(1000);
                    gotoxy(10,10);
                    cout<<"Deleted succesfully.";
                }
                getch();
                break;
            case 2: clrscr();
                int id;
                flag=0;
                gotoxy(10,5);
                cout<<"Enter teacher ID to delete: ";
                cin>>id;
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(t.ret_tid()==id)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher ID does not exist.";
                }
                else
                {
                    f.open("t.dat",ios::in|ios::binary);
                    ofstream f1("temp.dat",ios::binary);
                    while(f.read((char*)&t,sizeof(t)))
                    {
                        if(t.ret_tid()!=id)
                            f1.write((char*)&t,sizeof(t));
                    }
                    f.close();
                    f1.close();
                    remove("t.dat");
                    rename("temp.dat","t.dat");
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"deleting...";
                    delay(1000);
                    gotoxy(10,10);
                    cout<<"Deleted succesfully.";
                }
                getch();
                break;
            case 3:	return;
            default:gotoxy(20,17);
                cout<<"Invalid choice";
        }
    }while(1);
}
void tmodify()
{
    int flag,opt;
    do
    {
        clrscr();
        gotoxy(30,10);
        cout<<"Modify Teacher";
        gotoxy(30,11);
        cout<<"--------------";
        gotoxy(20,13);
        cout<<"1. Search by Name";
        gotoxy(20,14);
        cout<<"2. Search by TID";
        gotoxy(20,15);
        cout<<"3. Back to previous menu";
        gotoxy(20,18);
        cout<<"Choose an option: ";
        cin>>opt;
        switch(opt)
        {
            case 1: clrscr();
                char name[30];
                flag=0;
                cin.ignore();
                gotoxy(10,5);
                cout<<"Enter teacher name to modify: ";
                cin.getline(name,30);
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(strcmpi(t.ret_tname(),name)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher name does not exist.";
                }
                else
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    f.open("t.dat",ios::in|ios::out|ios::binary);
                    while(f.read((char*)&t,sizeof(t)))
                    {
                        if(strcmpi(t.ret_tname(),name)==0)
                        {
                            f.seekp(f.tellg()-sizeof(t),ios::beg);
                            clrscr();
                            t.tmodidata();
                            f.write((char*)&t,sizeof(t));
                            break;
                        }
                    }
                    f.close();
                    gotoxy(10,20);
                    cout<<"modifying...";
                    delay(1000);
                    gotoxy(10,20);
                    cout<<"Modified succesfully.";
                }
                getch();
                break;
            case 2: clrscr();
                int id;
                flag=0;
                gotoxy(10,5);
                cout<<"Enter teacher ID to modify: ";
                cin>>id;
                f.open("t.dat",ios::in|ios::binary);
                while(f.read((char*)&t,sizeof(t)))
                {
                    if(t.ret_tid()==id)
                    {
                        flag=1;
                        break;
                    }
                }
                f.close();
                if(flag==0)
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    clrscr();
                    gotoxy(10,10);
                    cout<<"Teacher ID does not exist.";
                }
                else
                {
                    clrscr();
                    gotoxy(10,5);
                    cout<<"searching...";
                    delay(1000);
                    f.open("t.dat",ios::in|ios::out|ios::binary);
                    while(f.read((char*)&t,sizeof(t)))
                    {
                        if(t.ret_tid()==id)
                        {
                            f.seekp(f.tellg()-sizeof(t),ios::beg);
                            clrscr();
                            t.tmodidata();
                            f.write((char*)&t,sizeof(t));
                            break;
                        }
                    }
                    f.close();
                    gotoxy(10,20);
                    cout<<"modifying...";
                    delay(1000);
                    gotoxy(10,20);
                    cout<<"Modified succesfully.";
                }
                getch();
                break;
            case 3:	return;
            default:gotoxy(20,17);
                cout<<"Invalid choice";
        }
    }while(1);
}
void cadd()
{
    f.open("c.dat",ios::ate|ios::out|ios::binary);
    clrscr();
    c.cgetdata();
    f.write((char*)&c,sizeof(c));
    f.close();
    gotoxy(10,20);
    cout<<"adding class...";
    delay(1000);
    gotoxy(10,20);
    cout<<"generating time table...";
    delay(1000);
    gotoxy(10,20);
    cout<<"Class added and time table generated succesfully.";
    getch();
}
void cshow()
{
    f.open("c.dat",ios::in|ios::binary);
    clrscr();
    while(f.read((char*)&c,sizeof(c)))
    {
        clrscr();
        c.cshowdata();
        getch();
    }
    f.close();
}
void csearch()
{
    f.open("c.dat",ios::in|ios::binary);
    int flag=0;
    char clas[6];
    clrscr();
    gotoxy(10,5);
    cout<<"Enter the class to search : ";
    cin>>clas;
    while(f.read((char*)&c,sizeof(c)))
    {
        if(strcmpi(c.ret_cclass(),clas)==0)
        {
            flag=1;
            break;
        }
    }
    f.close();
    if(flag==0)
    {
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        clrscr();
        gotoxy(10,10);
        cout<<"Class does not exist.";
    }
    else
    {
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        clrscr();
        c.cshowdata();
    }
    getch();
}
void cdelete()
{
    f.open("c.dat",ios::in|ios::binary);
    int flag=0;
    char clas[6];
    clrscr();
    gotoxy(10,5);
    cout<<"Enter the class to delete : ";
    cin>>clas;
    while(f.read((char*)&c,sizeof(c)))
    {
        if(strcmpi(c.ret_cclass(),clas)==0)
        {
            flag=1;
            break;
        }
    }
    f.close();
    if(flag==0)
    {
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        clrscr();
        gotoxy(10,10);
        cout<<"Class does not exist.";
    }
    else
    {
        f.open("c.dat",ios::in|ios::binary);
        ofstream f1("temp.dat",ios::binary);
        while(f.read((char*)&c,sizeof(c)))
        {
            if(strcmpi(c.ret_cclass(),clas)!=0)
                f1.write((char*)&c,sizeof(c));
        }
        f.close();
        f1.close();
        remove("c.dat");
        rename("temp.dat","c.dat");
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        clrscr();
        gotoxy(10,10);
        cout<<"deleting...";
        delay(1000);
        gotoxy(10,10);
        cout<<"Deleted succesfully.";
    }
    getch();
}
void aadd()
{
    clrscr();
    a.agetdata();
    if(a.ret_val()=='y')
    {
        f.open("a.dat",ios::ate|ios::out|ios::binary);
        f.write((char*)&a,sizeof(a));
        f.close();
        gotoxy(10,20);
        cout<<"finding substitute...";
        delay(1500);
        gotoxy(10,20);
        cout<<"Substitute alotted succesfully.";
        getch();
    }
}
void ashow()
{
    clrscr();
    int c=0;
    gotoxy(7,3);
    cout<<"DATE";
    gotoxy(22,3);
    cout<<"DAY";
    gotoxy(32,3);
    cout<<"PERIOD";
    gotoxy(44,3);
    cout<<"CLASS";
    gotoxy(56,3);
    cout<<"SUBSTITUTE TEACHER";
    f.open("a.dat",ios::in|ios::binary);
    i=5;
    while(f.read((char*)&a,sizeof(a)))
    {
        a.areport(i++);
        c++;
    }
    f.close();
    for(j=5;j<=5+c;j++)
    {
        gotoxy(2,j);
        cout<<char(179);
        gotoxy(16,j);
        cout<<char(179);
        gotoxy(29,j);
        cout<<char(179);
        gotoxy(40,j);
        cout<<char(179);
        gotoxy(52,j);
        cout<<char(179);
        gotoxy(80,j);
        cout<<char(179);
    }
    for(j=2;j<=4;j+=2)
    {
        for(int k=3;k<=80;k++)
        {
            gotoxy(k,j);
            cout<<char(196);
        }
    }
    for(j=3;j<=4;j++)
    {
        gotoxy(2,j);
        cout<<char(179);
        gotoxy(16,j);
        cout<<char(179);
        gotoxy(29,j);
        cout<<char(179);
        gotoxy(40,j);
        cout<<char(179);
        gotoxy(52,j);
        cout<<char(179);
        gotoxy(80,j);
        cout<<char(179);
    }
    gotoxy(2,2);
    cout<<char(218);
    gotoxy(2,4);
    cout<<char(192);
    gotoxy(80,4);
    cout<<char(217);
    gotoxy(80,2);
    cout<<char(191);
    getch();
}
void asearch()
{
    clrscr();
    char date[9];
    int flag=0;
    gotoxy(10,5);
    cout<<"Enter date(dd/mm/yy): ";
    cin>>date;
    ifstream f("a.dat",ios::binary);
    while(f.read((char*)&a,sizeof(a)))
    {
        if(strcmp(a.ret_date(),date)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        clrscr();
        gotoxy(10,10);
        cout<<"No arrangements for "<<date<<".";
        getch();
    }
    else
    {
        clrscr();
        gotoxy(10,5);
        cout<<"searching...";
        delay(1000);
        f.seekg(0,ios::beg);
        while(f.read((char*)&a,sizeof(a)))
        {
            if(strcmp(a.ret_date(),date)==0)
            {
                clrscr();
                a.ashowdata();
                getch();
            }
        }
    }
}
void dbo()
{
    int opt;
    do
    {
        clrscr();
        gotoxy(25,7);
        cout<<"Teacher Database Operations";
        gotoxy(25,8);
        cout<<"---------------------------";
        gotoxy(20,10);
        cout<<"1. Add a teacher";
        gotoxy(20,11);
        cout<<"2. Show teachers";
        gotoxy(20,12);
        cout<<"3. Search a teacher";
        gotoxy(20,13);
        cout<<"4. Delete a teacher";
        gotoxy(20,14);
        cout<<"5. Modify a teacher";
        gotoxy(20,15);
        cout<<"6. Return back to main menu";
        gotoxy(20,18);
        cout<<"Enter your choice: ";
        cin>>opt;
        switch(opt)
        {
            case 1: tadd();
                break;
            case 2:	tshow();
                break;
            case 3: tsearch();
                break;
            case 4:	tdelete();
                break;
            case 5: tmodify();
                break;
            case 6:	return;
            default:gotoxy(20,18);
                cout<<"Invalid choice";
        }
    }while(1);
}
void cop()
{
    int opt;
    do
    {
        clrscr();
        gotoxy(31,7);
        cout<<"Class Operations";
        gotoxy(31,8);
        cout<<"----------------";
        gotoxy(20,10);
        cout<<"1. Add a class";
        gotoxy(20,11);
        cout<<"2. Show classes";
        gotoxy(20,12);
        cout<<"3. Search a class";
        gotoxy(20,13);
        cout<<"4. Delete a class";
        gotoxy(20,14);
        cout<<"5. Return back to main menu";
        gotoxy(20,17);
        cout<<"Choose your option:";
        cin>>opt;
        switch(opt)
        {
            case 1:	cadd();
                break;
            case 2:	cshow();
                break;
            case 3:	csearch();
                break;
            case 4:	cdelete();
                break;
            case 5: return;
            default:gotoxy(20,17);
                cout<<"Invalid choice";
        }
    }while(1);
}
void arr()
{
    int opt;
    do
    {
        clrscr();
        gotoxy(35,7);
        cout<<"Arrangements";
        gotoxy(35,8);
        cout<<"------------";
        gotoxy(20,10);
        cout<<"1. Find substitute";
        gotoxy(20,11);
        cout<<"2. Show arrangements";
        gotoxy(20,12);
        cout<<"3. Search arrangements";
        gotoxy(20,13);
        cout<<"4. Return back to main menu";
        gotoxy(20,16);
        cout<<"Choose your option:";
        cin>>opt;
        switch(opt)
        {
            case 1:	aadd();
                break;
            case 2:	ashow();
                break;
            case 3:	asearch();
                break;
            case 4: return;
            default:gotoxy(20,18);
                cout<<"Invalid choice";
        }
    }while(1);
}
void main()
{
    clrscr();
    load();
    int opt;
    do
    {
        clrscr();
        gotoxy(28,7);
        cout<<"SCHOOL SCHEDULING SYSTEM";
        gotoxy(28,8);
        cout<<"------------------------";
        gotoxy(20,10);
        cout<<"1. Teacher Database Operations";
        gotoxy(20,11);
        cout<<"2. Class Operations";
        gotoxy(20,12);
        cout<<"3. Arrangements";
        gotoxy(20,13);
        cout<<"4. Exit";
        gotoxy(20,16);
        cout<<"Enter your choice: ";
        cin>>opt;
        switch(opt)
        {
            case 1: dbo();
                break;
            case 2:	cop();
                break;
            case 3:	arr();
                break;
            case 4: exit(0);
            default:gotoxy(20,17);
                cout<<"Invalid choice";
        }
    }while(1);
}









