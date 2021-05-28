#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menuexit();
void login();
int verify();
void menu();
void view();
void add();
void edit();
void del();
void search();
void search_name();
void search_acc();
void transaction();
void chkblnc();
void deposit();
void withdrawl();
void transfer();
int chkacc();
void admin();
int m,r;

COORD coord={0,0};
char id[20],password[15];
struct record
{
    char name[25];
    int account;
    char phone[15];
    char address[25];
    char email[35];
    char citiz[20];
    double blnc;
    char UserID[10];
}rec;
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void design(int x,int y)
{
    for(int i=0;i<=x;i++)
    printf("%c",y);
}
void border()
{
    int i,j;
    for(i=0;i<108;i++)
    {
        gotoxy(i+6,2);
        printf("%c",223);
        gotoxy(i+6,26);
        printf("%c",220);
    }
    for(j=0;j<25;j++)
    {
        gotoxy(6,j+2);
        printf("%c",219);
        gotoxy(113,j+2);
        printf("%c",219);
    }
}

void main()
{

    system("color f4");
    gotoxy(26,4);
    design(15,177);
    printf(" WELCOME TO PULCHOWK BANKING SYSTEM ");
    design(15,177);
    border();
    gotoxy(50,8);
    printf("ACCOUNT TYPE");
    gotoxy(44,10);
    printf("[1] . ADMINISTRATOR ");
    gotoxy(44,11);
    printf("[2] . USER ");
    gotoxy(44,14);
    printf("Enter Your Choice .... ");
    scanf("%d",&m);
    if(m!=1 && m!=2)
    {
        system("cls");
        main();
    }
    system("CLS");
    admin();
}



void admin()
{
    system("color f4");
    gotoxy(26,4);
    design(15,177);
    printf(" WELCOME TO PULCHOWK BANKING SYSTEM ");
    design(15,177);
    border();
    login();
    if(verify()==1)
    {
        if(m==1)
            menu();
        else
            transaction();
    }
    else if(verify()==0)
    {
        system("CLS");
        gotoxy(35,17);
        design(48,196);
        gotoxy(43,16);
        printf("Incorrect Username / Password !!!!");
        admin();
    }
}

void login() //Takes the user-name and password .
{
    int i=0;
    gotoxy(15,10);
    printf("Enter The Username : ");
    scanf(" %[^\n]",id);
    gotoxy(15,12);
    printf("Enter The Password : ");
    while(password[i]!=13)
    {
        password[i]=getch();
        if(password[i]==13)
            break;
        printf("*");
        i++;
    }
    password[i]='\0';
}

int verify() //verifies the user-name and password .
{
    char a;
    if(m==1)
    {
    if( (strcmp(id,"admin")==0  &&  strcmp(password,"admin")==0))
    {
        gotoxy(35,17);
        design(48,196);
        gotoxy(38,16);
        printf("You Have Successfully Logged In : \" %s \" ",id);
        time_t t;
        time(&t);
        gotoxy(39,18);
        printf("Logged In Time : %s",ctime(&t));
        gotoxy(44,22);
        printf("Press any key to continue .... ");
        getch();
        return 1;
    }
     else
        return 0;
    }
    else if(m==2)
    {
    if(strcmp(id,"user")==0  &&  strcmp(password,"user")==0)
    {
        gotoxy(35,17);
        design(48,196);
        gotoxy(38,16);
        printf("You Have Successfully Logged In : \" %s \" ",id);
        time_t t;
        time(&t);
        gotoxy(39,18);
        printf("Logged In Time : %s",ctime(&t));
        gotoxy(44,22);
        printf("Press any key to continue .... ");
        getch();
        return 1;
    }
     else
        return 0;
    }
}

void menu() //displays the main user interface screen of program .
{
        system("CLS");
        gotoxy(28,4);
        design(20,177);
        printf(" WELCOME TO MAIN MENU ");
        design(20,177);
        border();
        gotoxy(44,8);
        printf("[1] . View Customer Accounts");
        gotoxy(44,9);
        printf("[2] . Customer Account Registration");
        gotoxy(44,10);
        printf("[3] . Edit Customer Account");
        gotoxy(44,11);
        printf("[4] . Delete Customer Account");
        gotoxy(44,12);
        printf("[5] . Search Customer Account");
        gotoxy(44,13);
        printf("[6] . Transaction");
        gotoxy(44,15);
        printf("[7] . Log Out !!! ");
        gotoxy(43,20);
        printf("Please Enter Your Choice [1-7] : ");
        option();
}

void option() // takes user choice and goes to desired function .
{
    int i;
    scanf("%d",&i);
    system("CLS");
    switch(i)
    {
    case 1 :
        view();
        break;
    case 2:
        add();
        break;
    case 3:
        edit();
        break;
    case 4:
        del();
        break;
    case 5:
        search();
        break;
    case 6:
        transaction();
        break;
    case 7:
        menuexit();
        break;
    default:
            menu();
    }
}

void view() // module for viewing account details
{
    int i=7;
    struct record rec;
    FILE *f;
    f = fopen("record.bin","rb" );
    gotoxy(25,3);
    design(25,177);
    printf(" CUSTOMERS LIST ");
    design(25,177);
    gotoxy(5,5);
    printf("A/C No.");
    gotoxy(13,5);
    printf("Account Name");
    gotoxy(34,5);
    printf("UserID");
    gotoxy(49,5);
    printf("Email Address");
    gotoxy(85,5);
    printf("Phone No.");
    gotoxy(99,5);
    printf("Balance");
    gotoxy(5,6);
    design(109,205);
    while (fread(&rec, sizeof(rec), 1, f))
    {
        gotoxy(7,i);
        printf("%d",rec.account);
        gotoxy(13,i);
        printf("%s",rec.name);
        gotoxy(34,i);
        for(r=0;r<10;r++)
        {
            printf("%d",rec.UserID[r]);
        }
        gotoxy(49,i);
        printf("%s",rec.email);
        gotoxy(85,i);
        printf("%s",rec.phone);
        gotoxy(99,i);
        printf("$%.2lf",rec.blnc);
        i++;
    }
    fclose(f);
    for(int k=0;k<113;k++)
    {
        gotoxy(k+3,1);
        printf("%c",223);
        gotoxy(k+3,i+2);
        printf("%c",220);
    }

    for(int j=0;j<i+2;j++)
    {
        gotoxy(3,j+1);
        printf("%c",219);
        gotoxy(116,j+1);
        printf("%c",219);
    }
    int x;
    gotoxy(42,i+5);
    printf("Press [Enter] to return back to main menu. ");
    x=getch();
    if(x==13)
    {
        menu();
    }
    else
        view();
}

void add() //module for adding accounts.
{
    char c;
    struct record rec;
    FILE *f;
    f = fopen("record.bin","ab");
    int i=0,x;
    do
    {   system("CLS");
        gotoxy(24,4);
        design(20,177);
        printf(" CUSTOMER ACCOUNT REGISTRATION ");
        design(20,177);
        border();
        gotoxy(36,8);
        printf("[1] . Enter Your Name           : ");
        scanf(" %[^\n]",rec.name);
        gotoxy(36,9);
        printf("[2] . Enter Your Account Number : ");
        scanf(" %d",&rec.account);
        gotoxy(36,10);
        printf("[3] . Enter Your Phone Number   : ");
        scanf(" %[^\n]",rec.phone);
        gotoxy(36,11);
        printf("[4] . Enter Your Address        : ");
        scanf(" %[^\n]",rec.address);
        gotoxy(36,12);
        printf("[5] . Enter Your E-mail         : ");
        scanf(" %[^\n]",rec.email);
        gotoxy(36,13);
        printf("[6] . Enter Your Citizenship No.: ");
        scanf(" %[^\n]",rec.citiz);
        gotoxy(36,14);
        printf("[7] . Enter Amount To Deposit   : $");
        scanf(" %lf",&rec.blnc);
        srand(time(0));
        for(r=0;r<10;r++)
        {
            rec.UserID[r]=rand()%10;
        }
        fwrite(&rec , sizeof(rec) , 1 ,f );
        gotoxy(38,17);
        printf("CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL");
        i++;
        gotoxy(36,19);
        printf("Do You Want To Add Another Record ? (Y/N) : ");
        scanf(" %c",&c);
    }while(c=='Y' || c=='y');
    fclose(f);
    gotoxy(40,22);
     printf("Press any key to return back to main menu. ");
    char z=getch();
    if(z==13)
    {
        menu();
    }
}

void edit() // module for editing details.
{
    FILE *x,*y;
    int a,c;
    re:
    gotoxy(23,4);
    design(25,177);
    printf(" EDIT CUSTOMER ACCOUNT ");
    design(25,177);
    border();
    gotoxy(43,7);
    printf("Enter Your Account Number To Edit : ");
    scanf("%d", &a);
    if(chkacc(a)==1)
    {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(&rec,sizeof(rec),1,x) )
        {
            if (rec.account!= a)
            fwrite(&rec,sizeof(rec),1,y);
            else if(rec.account==a)
        {
            gotoxy(41,20);
            design(42,196);
            gotoxy(52,21);
            printf("Account Number Matched");
            gotoxy(41,22);
            design(42,196);
            gotoxy(51,10);
            printf("Enter Your Details");
            gotoxy(28,11);
            design(65,205);
            gotoxy(31,12);
            printf("[1] . Enter Your Name           : ");
            scanf(" %[^\n]",rec.name);
            gotoxy(31,13);
            printf("[2] . Enter Your Account Number : ");
            scanf(" %d",&rec.account);
            gotoxy(31,14);
            printf("[3] . Enter Your Phone Number   : ");
            scanf(" %[^\n]",rec.phone);
            gotoxy(31,15);
            printf("[4] . Enter Your Address        : ");
            scanf(" %[^\n]",rec.address);
            gotoxy(31,16);
            printf("[5] . Enter Your E-mail         : ");
            scanf(" %[^\n]",rec.email);
            gotoxy(31,17);
            printf("[6] . Enter Your Citizenship No : ");
            scanf(" %[^\n]",rec.citiz);
            fwrite(&rec,sizeof(rec),1,y);
        }
    }
        fclose(x);
        fclose(y);
 }
    if (chkacc(a)== 0)
    {
        system("CLS");
        gotoxy(41,20);
        design(42,196);
        gotoxy(52,21);
        printf("Account Doesn't Exist. ");
        gotoxy(41,22);
        design(42,196);
        goto re;
    }
    remove("record.bin");
    rename("new.bin","record.bin");
    gotoxy(45,21);
    printf("CUSTOMER ACCOUNT UPDATE SUCCESSFULL");
    gotoxy(42,24);
    printf("Press any key to return back to main menu . ");
    getch();
    menu();
}

void del() //module for deleting account
{
    FILE *x,*y;
    int a,c;
    re:
    gotoxy(23,4);
    design(25,177);
    printf(" DELETE CUSTOMER ACCOUNT ");
    design(25,177);
    border();
    gotoxy(41,9);
    printf("Enter Your Account Number To Delete : ");
    scanf("%d",&a);
    if(chkacc(a)==1)
    {
        x = fopen("record.bin","rb");
        y = fopen("new.bin","wb");
        while(fread(&rec,sizeof(rec),1,x))
        {
            if(rec.account!=a)
            fwrite(&rec,sizeof(rec),1,y);
        }
        fclose(x);
        fclose(y);
        x = fopen("record.bin","wb");
        y = fopen("new.bin","rb");
        while(fread(&rec,sizeof(rec),1,y))
            fwrite(&rec,sizeof(rec),1,x);
        fclose(x);
        fclose(y);
    }
    else if (chkacc(a)== 0)
    {
        system("CLS");
        gotoxy(41,14);
        design(42,196);
        gotoxy(51,15);
        printf("Account Doesn't Exist");
        gotoxy(41,16);
        design(42,196);
        goto re;
    }
        gotoxy(41,14);
        design(42,196);
        gotoxy(44,15);
        printf("CUSTOMER ACCOUNT DELETED SUCCESSFULLY");
        gotoxy(41,16);
        design(42,196);
        gotoxy(42,18);
     printf("Press any key to return back to main menu. ");
     getch();
    menu();
}

void search()
{
    system("cls");
    int a;
    gotoxy(28,4);
    design(25,177);
    printf(" SEARCH MENU ");
    design(25,177);
    border();
    gotoxy(49,10);
    printf("[1] . Search By Account ");
    gotoxy(49,12);
    printf("[2] . Search By Name ");
    gotoxy(47,17);
    printf("Enter Your Choice [1-2] : ");
    scanf("%d",&a);
    system("cls");
    if(a==1)
    {
        search_acc();
    }
    else if(a==2)
    {
        search_name();
    }
    else
        menu();
}

void search_acc() //module for searching account
{
    FILE *f;
    int a,x;
    re:
    gotoxy(23,4);
    design(25,177);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    design(25,177);
    border();
    gotoxy(43,7);
    printf("Enter Your Account Number To Search : ");
    scanf("%d",&a);
    if(chkacc(a)==1)
    {
        f = fopen("record.bin","rb");
        while(fread(&rec,sizeof(rec),1,f))
        {
        if(rec.account==a)
        {
            gotoxy(41,20);
            design(42,196);
            gotoxy(52,21);
            printf("Account Number Matched");
            gotoxy(41,22);
            design(42,196);
            gotoxy(45,10);
            printf("Detail Information of %s",strupr(rec.name));
            gotoxy(28,11);
            design(65,205);
            gotoxy(37,12);
            printf("[1] . Account Number : %d",rec.account);
            gotoxy(37,13);
            printf("[2] . Name           : %s",rec.name);
            gotoxy(37,14);
            printf("[3] . UserID         : ");
            for(r=0;r<10;r++)
            {
                printf("%d",rec.UserID[r]);
            }
            gotoxy(37,15);
            printf("[4] . Phone Number   : %s",rec.phone);
            gotoxy(37,16);
            printf("[5] . Address        : %s",rec.address);
            gotoxy(37,17);
            printf("[6] . E-mail         : %s",rec.email);
            gotoxy(37,18);
            printf("[7] . Citizenship No : %s",rec.citiz);
            gotoxy(37,19);
            printf("[8] . Current Balance: $%.2lf",rec.blnc);
            break;
        }
    }
        fclose(f);
    }
    if (chkacc(a)== 0)
    {
        system("CLS");
        gotoxy(41,20);
        design(42,196);
        gotoxy(52,21);
        printf("Account Doesn't Exist. ");
        gotoxy(41,22);
        design(42,196);
        goto re;
    }
    gotoxy(42,24);
    printf("Press [ENTER] to return back to main menu. ");
    char z=getch();
    if(z==13)
        menu();
    else
        search();
}

void search_name()
{
    int i=0,b,x;
    char nam[30];
    gotoxy(23,4);
    design(25,177);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    design(25,177);
    border();
    gotoxy(43,7);
    printf("Enter Your Full Name To Search : ");
    scanf(" %[^\n]",nam);
    FILE *f;
    f=fopen("record.bin","rb");
    while(fread(&rec,sizeof(rec),1,f))
    {
        b=0;
        strupr(rec.name);
        strupr(nam);
        if(strcmp( rec.name , nam )==0)
        {
            gotoxy(41,20);
            design(42,196);
            gotoxy(52,21);
            printf("Account Number Matched");
            gotoxy(41,22);
            design(42,196);
            gotoxy(45,10);
            printf("Detail Information of %s",rec.name);
            gotoxy(28,11);
            design(65,205);
            gotoxy(37,12);
            printf("[1] . Account Number : %d",rec.account);
            gotoxy(37,13);
            printf("[2] . Name           : %s",rec.name);
            gotoxy(37,14);
            printf("[3] . UserID         : ");
            for(r=0;r<10;r++)
            {
                printf("%d",rec.UserID[r]);
            }
            gotoxy(37,15);
            printf("[4] . Phone Number   : %s",rec.phone);
            gotoxy(37,16);
            printf("[5] . Address        : %s",rec.address);
            gotoxy(37,17);
            printf("[6] . E-mail         : %s",rec.email);
            gotoxy(37,18);
            printf("[7] . Citizenship No : %s",rec.citiz);
            gotoxy(37,19);
            printf("[8] . Current Balance: $%.2lf",rec.blnc);
            break;
        }
        else
            b=1;
    }
    fclose(f);
    if(b==1)
    {
        system("cls");
        gotoxy(41,20);
        design(42,196);
        gotoxy(52,21);
        printf("Account Doesn't Exist. ");
        gotoxy(41,22);
        design(42,196);
        search_name();
    }
    gotoxy(42,24);
    printf("Press [ENTER] to return back to main menu. ");
    char z=getch();
    if(z==13)
        menu();
    else
        search();
}

void transaction() // displays screen for the transaction options and takes the user choice .
{
    system("CLS");
    gotoxy(25,4);
    design(25,177);
    printf(" TRANSACTION MENU ");
    design(25,177);
    border();
    gotoxy(49,9);
    printf("[1] . Balance Inquiry");
    gotoxy(49,10);
    printf("[2] . Cash Deposit");
    gotoxy(49,11);
    printf("[3] . Cash Withdrawal");
    gotoxy(49,12);
    printf("[4] . Fund Transfer");
    if(m==1)
    {
        gotoxy(49,13);
        printf("[5] . Main Menu");
    }
    else
    {
        gotoxy(49,13);
        printf("[5] . Exit");
    }
    gotoxy(45,17);
    printf("Please Enter Your Choice [1-5] : ");
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        system("cls");
        chkblnc();
        break;
    case 2:
        system("cls");
        deposit();
        break;
    case 3:
        system("cls");
        withdrawl();
        break;
    case 4:
        system("cls");
        transfer();
        break;
    case 5:
        if(m==1)
            menu();
        else
            menuexit();
        break;
    default :
        transaction();
    }
}

void chkblnc() // module for checking account balance and displaying it
{
    FILE *f;
    int a;
    gotoxy(27,4);
    design(25,177);
    printf(" BALANCE INQUIRY ");
    design(25,177);
    border();
    gotoxy(47,12);
    printf("Enter Your Account Number : ");
    scanf("%d",&a);
    if(chkacc(a)==1)
    {
        f=fopen("record.bin","rb");
        while(fread(&rec,sizeof(rec),1,f))
        {
            if(rec.account==a)
            {
                gotoxy(41,14);
                design(42,196);
                gotoxy(41,16);
                design(42,196);
                gotoxy(50,15);
                printf("Your Balance is : $%.2lf",rec.blnc);
            }
        }
        fclose(f);
    }
    if (chkacc(a)== 0)
    {
        system("cls");
        gotoxy(41,14);
        design(42,196);
        gotoxy(41,16);
        design(42,196);
        gotoxy(52,15);
        printf("Account Doesn't Exist.");
        chkblnc();
    }
    gotoxy(46,21);
    printf("Press any key to return back to main menu. ");
    getch();
    transaction();
}

void deposit() // module for adding amount to a account
{
    int a;
    double b;
    FILE *x,*y;
    gotoxy(29,4);
    design(25,177);
    printf(" CASH DEPOSIT ");
    design(25,177);
    border();
    gotoxy(47,10);
    printf("Enter Your Account Number : ");
    scanf("%d",&a);
    if(chkacc(a)==1)
    {
        x=fopen("record.bin","rb");
        y=fopen("new.bin","wb");
        while(fread(&rec,sizeof(rec),1,x))
        {
            if(rec.account!=a)
                fwrite(&rec,sizeof(rec),1,y);
            else if(rec.account==a)
            {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                gotoxy(45,13);
                printf("Enter The Amount To Deposit : $ ");
                scanf("%lf",&b);
                rec.blnc+=b;
                fwrite(&rec,sizeof(rec),1,y);
            }
        }
        fclose(x);
        fclose(y);
        x=fopen("record.bin","wb");
        y=fopen("new.bin","rb");
        while(fread(&rec,sizeof(rec),1,y))
            fwrite(&rec,sizeof(rec),1,x);
        fclose(x);
        fclose(y);
    }
      if (chkacc(a)== 0)
    {
        system("CLS");
        gotoxy(41,20);
        design(42,196);
        gotoxy(52,21);
        printf("Account Doesn't Exist. ");
        gotoxy(41,22);
        design(42,196);
        deposit();
    }
    gotoxy(41,20);
    design(42,196);
    gotoxy(41,22);
    design(42,196);
    gotoxy(52,15);
    gotoxy(52,21);
    printf("CASH DEPOSIT SUCCESSFULL");
    gotoxy(50,24);
    printf("Press any key to return back...");
    getch();
    transaction();
}

void withdrawl() // module to withdraw amount from account
{
    FILE *x,*y;
    int a;
    double b,z;
    gotoxy(25,4);
    design(25,177);
    printf(" CASH WITHDRAWAL ");
    design(25,177);
    border();
    gotoxy(45,10);
    printf("Enter Your Account Number : ");
    scanf("%d",&a);
    if(chkacc(a)==1)
    {
        x=fopen("record.bin","rb");
        y=fopen("new.bin","wb");
        gotoxy(42,13);
        printf("Enter The Amount To Withdraw : $ ");
        scanf("%lf",&b);
        while(fread(&rec,sizeof(rec),1,x))
        {
            if(rec.account!=a)
                fwrite(&rec,sizeof(rec),1,y);
            else if(rec.account==a)
            {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                z=rec.blnc;
                if(b<=rec.blnc)
                {

                    rec.blnc-=b;
                    gotoxy(39,20);
                    design(42,196);
                    gotoxy(39,22);
                    design(42,196);
                    gotoxy(44,21);
                    printf("    CASH WITHDRAWAL SUCCESSFULL     ");
                }
                fwrite(&rec,sizeof(rec),1,y);
            }
        }
        fclose(x);
        fclose(y);
        remove("record.bin");
        rename("new.bin","record.bin");
        if(z<b)
        {
            system("CLS");
            gotoxy(39,20);
            design(42,196);
            gotoxy(39,22);
            design(42,196);
            gotoxy(48,21);
            printf("Current Balance is $%.2lf",z);
            gotoxy(42,24);
            printf("Entered amount exceeds current balance");
            withdrawl();
        }
    }
    if (chkacc(a)== 0)
    {
        system("CLS");
        gotoxy(39,20);
        design(42,196);
        gotoxy(50,21);
        printf("Account Doesn't Exist.");
        gotoxy(39,22);
        design(42,196);
        withdrawl();
    }
    gotoxy(42,24);
    printf("     Press Any Key To Continue ....   ");
    getch();
    transaction();
}

void transfer(void) //module for transferring amount from one account to another account
{
    int a;
    double b,z;
    FILE *x,*y;
    x=fopen("record.bin","rb");
    y=fopen("new.bin","wb");
    gotoxy(27,4);
    design(25,177);
    printf(" CASH TRANSFER ");
    design(25,177);
    border();
    gotoxy(42,10);
    printf("Enter Your Account Number      : ");
    re:
    scanf("%d",&a);
    if(chkacc(a)==0)
    {
        system("CLS");
        gotoxy(38,20);
        design(42,196);
        gotoxy(50,21);
        printf("Account Doesn't Exist.");
        gotoxy(38,22);
        design(42,196);
        goto re;
    }
    else if(chkacc(a)==1)
    {
        gotoxy(42,13);
        printf("Enter The Amount To Transfer   : $ ");
        scanf("%lf",&b);
        while(fread(&rec,sizeof(rec),1,x))
        {
            if(rec.account!=a)
                fwrite(&rec,sizeof(rec),1,y);
            else if(rec.account==a)
            {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                if(b<rec.blnc)
                {
                    z=rec.blnc;
                    rec.blnc-=b;
                }
                fwrite(&rec,sizeof(rec),1,y);
            }
        }
    }
        fclose(x);
        fclose(y);
        remove("record.bin");
        rename("new.bin","record.bin");
        if(b>z)
        {
            gotoxy(38,20);
            design(42,196);
            gotoxy(38,22);
            design(42,196);
            gotoxy(44,21);
            printf("Current Balance is $%.2lf",z);
            gotoxy(41,24);
            printf("Entered amount exceeds current balance");
            main();
        }

    x=fopen("record.bin","rb");
    y=fopen("new.bin","wb");
    gotoxy(42,16);
    printf("Enter Recipient Account Number : ");
    scanf("%d",&a);
    if(chkacc(a)==0)
    {
        gotoxy(38,20);
        design(42,196);
        gotoxy(50,21);
        printf("Account Doesn't Exist.");
        gotoxy(38,22);
        design(42,196);
    }
    else if(chkacc(a)==1)
    {
        while(fread(&rec,sizeof(rec),1,x))
        {
            if(rec.account!=a)
                fwrite(&rec,sizeof(rec),1,y);
            else if(rec.account==a)
            {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                rec.blnc+=b;
                fwrite(&rec,sizeof(rec),1,y);
            }
        }
        fclose(x);
        fclose(y);
        remove("record.bin");
        rename("new.bin","record.bin");
    }
    gotoxy(38,20);
    design(42,196);
    gotoxy(38,22);
    design(42,196);
    gotoxy(40,21);
    printf("        CASH TRANSFER SUCCESSFULL        ");
    gotoxy(38,24);
    printf("        Press Any Key To Continue ....        ");
    getch();
    system("cls");
    transaction();
}


int chkacc(int a) //module to check whether the entered account is in the database or not
{
 FILE *f;
 f =fopen("record.bin", "rb");
 while(!feof(f))
 {
  fread(&rec, sizeof(rec), 1, f);

  if (a == rec.account)
  {
   fclose(f);
   return 1;
  }
 }
 fclose(f);
 return 0;
}

void menuexit() //module for logging out of the program.
{
    system("cls");
    gotoxy(30,4);
    design(25,177);
    printf(" THANK YOU ");
    design(25,177);
    border();
    gotoxy(42,12);
    printf("USER            :: %s",id);
    time_t t;
    time(&t);
    gotoxy(42,14);
    printf("Logged Out Time :: %s",ctime(&t));
    fflush(stdin);
    getch();
    gotoxy(0,26);
    exit(0);
}

