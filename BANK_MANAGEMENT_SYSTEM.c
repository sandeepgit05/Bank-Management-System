#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
typedef struct bankacc
{
    int date, dob, age, z, cnum, phone_num;
    char name[20], address[50], choice[20];
    int num;
    int amount;

} acc;
void delay();
float intrest(float, float, float);
void mainmenu(void);
void gotoxy(int, int);
void home(void);
void newaccount(void);
void updateinfo(void);
void transactions(void);
void detailsAcc(void);
void removeAcc(void);
int customerlist(void);
void atm(void);
void atmmenu(void);
void checkbalance(float);
float withdraw(float);
float deposit(float);

int main()
{
    home();
    getch();

    return (0);
}
void delay(void)
{
    for (long double i = 0; i < 100000000; i++);
}
float intrest(float amount, float rate, float time)
{
    float SI;
    SI = ((amount * rate * time) / 100);
    return (SI);
}
void checkbalance(float balance)
{
    printf("You choose to see your balance\n");
    printf("Your Available balance is: $%.2f", balance);
}
float withdraw(float balance)
{
    system("cls");
    float a;
    printf("You choose to withdraw money\n");
    printf("Available balance is $%.2f\n", balance);
    printf("\n");
    printf("Enter the amount you wanna withdraw:$");
    scanf("%f", &a);
    if (a <= balance)
    {
        printf("Your withdrawing money is $%.2f\n", a);
        balance -= a;
        printf("Your balance is $%.2f\n", balance);
    }
    else
    {
        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("Available balance is $%.2f\n", balance);
    }
    return balance;
}
float deposit(float balance)
{
    system("cls");
    float b;
    printf("You choose to deposit money\n");
    printf("Available Balance is $%.2f\n", balance);
    printf("\n");
    printf("Enter the amount you want to deposit:$");
    scanf("%f", &b);
    printf("You deposit $%f amount\n", b);
    balance += b;
    printf("Now Available balance is $%.2f\n", balance);
    return balance;
}
void atmmenu(void)
{
    system("cls");
    gotoxy(13, 2);
    printf("========Welcome to ATM Feature========");
    gotoxy(13, 5);
    printf("--- Please Choose one of the given functions---");
    gotoxy(13, 7);
    printf("<1> Check Balance");
    gotoxy(13, 9);
    printf("<2> Deposit");
    gotoxy(13, 11);
    printf("<3> Withdraw");
    gotoxy(13, 13);
    printf("<4> Exit");
    gotoxy(1, 15);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
void atm(void)
{
    system("cls");
    int f = 1, option;
    float balance = 15000;
    // float balance;
    atmmenu();
    // switch (option){
    // case1: checkbalance(balance);
    // break;
    // case2: balance=deposit(balance);
    // break;
    // case3: balance=withdraw(balance);
    // break;
    // case4: exit(0);
    // break;
    // default: printf("You entered wrong number\n");
    // }
    while (f)
    {
        printf("Your Selection");
        scanf("%d", &option);
        system("cls");
        if (option == 1)
        {
            int a;
            checkbalance(balance);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Would you like to do another transaction:\n");
            printf("1.YES\n");
            printf("2.NO\n");
            scanf("%d", &a);
            if (a == 1)
            {
                atmmenu();
            }
            else
            {
                f = 0;
                exit(0);
            }
            // getch();
        }
        else if (option == 2)
        {
            int a;
            balance = deposit(balance);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Would you like to do another transaction:\n");
            printf("1.YES\n");
            printf("2.NO\n");
            scanf("%d", &a);
            if (a == 1)
            {
                atmmenu();
            }
            else
            {
                f = 0;
                exit(0);
            }
            //  getch();
        }
        else if (option == 3)
        {
            int a;
            balance = withdraw(balance);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Would you like to do another transaction:\n");
            printf("1.YES\n");
            printf("2.NO\n");
            scanf("%d", &a);
            if (a == 1)
            {
                atmmenu();
            }
            else
            {
                f = 0;
                exit(0);
            }
            // getch();
        }
        else if (option == 4)
        {
            exit(0);
            f = 0;
        }
        else
        {
            printf("You entered wrong number\n");
            getch();
            f = 0;
            exit(0);
        }
    }
}
void newaccount(void)
{
    // date d1;
    // date d2;
    system("cls");
    int z;
    acc A;
    FILE *ptr;
    ptr = fopen("record.txt", "a+");
    gotoxy(30, 2);
    {
        printf("==== ADD RECORD ====\n");
    }
    fflush(stdin);
    printf("Enter today's date (mm/dd/yyyy):");
    // scanf("%d/%d/%d\n",&d1.month,&d1.day,&d1.year);
    scanf("%d", &A.date);
    //getch();
    fflush(stdin);
    printf("Enter the account number:");
    scanf("%d", &A.num);
    // getch();
    fflush(stdin);
    printf("Enter the Name :");
    gets(A.name); // used here for multiple characters and also a space between them.
    //getch();
    fflush(stdin);
    printf("Enter the Date of Birth(mm/dd/yyyy):");
    // scanf("%d/%d/%d",&d2.month,&d2.day,&d2.year);
    scanf("%d", &A.dob);
    //getch();
    fflush(stdin);
    printf("Enter the age:");
    scanf("%d", &A.age);
    //getch();
    fflush(stdin);
    printf("Enter the Address:");
    gets(A.address);
    //getch();
    fflush(stdin);
    printf("Enter the citizenship number:");
    scanf("%d", &A.cnum);
    fflush(stdin);
    printf("Enter the Phone Number:");
    scanf("%d", &A.phone_num);
    //getch();
    fflush(stdin);
    printf("Enter the amount to deposit=$");
    scanf("%d", &A.amount);
    fflush(stdin);
    printf("Type of Account:\n");
    // gotoxy(6,14);
    {
        printf("#saving\n");
    }
    // gotoxy(6,15);
    {
        printf("#current\n");
    }
    // gotoxy(6,16);
    {
        printf("#fixed1(for 1 year)\n");
    }
    // gotoxy(6,17);
    {
        printf("#fixed2(for 2 year)\n");
    }
    // gotoxy(6,18);
    {
        printf("#fixed3(for 3 year)\n");
    }
    // gotoxy(6,20);
    {
        printf("Enter your choice:");
    }
    gets(A.choice); // here & not used because choice is also a address (since its an array so it denotes its base address)
    fflush(stdin);
    gotoxy(2, 22);
    {
        printf("Account Created successfully!");
    }
    fprintf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, A.phone_num, A.amount, A.choice);
    fclose(ptr);
    gotoxy(11, 24);
    {
        printf("Enter 1 to go main menu and 0 to exit");
    }
    scanf("%d", &z);
    if (z == 1 || z == 0)
    {
        if (z == 1)
        {
            mainmenu();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        system("cls");
        printf("Invalid!\n");
        Beep(500, 1000);
        gotoxy(10, 4);
        {
            printf("Enter 1 to go main menu and 0 to exit");
        }
        if (z == 1 || z == 0)
        {
            if (z == 1)
            {
                mainmenu();
            }
            else
            {
                exit(0);
            }
        }
        else
        {
            printf("Too Many Attempsts done!");
            getch();
            exit(0);
        }
    };
}
void updateinfo(void)
{
    system("cls");
    FILE *ptr;
    FILE *ptr1;
    int a, b, c;
    acc A;
    char add[50];
    // system("cls");
    ptr = fopen("record.txt", "r");
    ptr1 = fopen("record1.txt", "w");
    gotoxy(2, 2);
    {
        printf("Enter the account no. of the customer whose info you want to change:\n");
    }
    scanf("%d", &a);
    while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice)==10)
    {
        if (A.num == a)
        {

            gotoxy(2, 4);
            {
                printf("Which information do you want to change:\n");
            }
            printf("1.Address\n");
            printf("2.Phone Number\n");
            gotoxy(2, 8);
            {
                printf("Enter your choice (1 for address 2 for phone)\n");
            }
            scanf("%d", &b);
            if (b == 1 || b == 2)
            {
                if (b == 1)
                {
                    fflush(stdin);
                    printf("Enter your new Address:");
                    gets(add);
                    strcpy(A.address, add);
                    fprintf(ptr1, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, A.phone_num, A.amount, A.choice);
                    printf("Updated Successfully!");
                    getch();
                }
                else
                {
                    fflush(stdin);
                    printf("Enter new Phone number:");
                    scanf("%d", &c);
                    // strcpy(A.phone_num,c);
                    fprintf(ptr1, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, c, A.amount, A.choice);
                    printf("Updated Successfully!");
                    getch();
                }
            }
            else
            {
                exit(0);
            }
        }
        else
        {
            printf("No such Account Found");
        }
    }
    fclose(ptr1);
    fclose(ptr);
    remove("record.txt");
    rename("record1.txt", "record.txt");
}
void transactions(void)
{
    system("cls");
    int a;
    float bal;
    FILE *ptr;
    FILE *ptr1;
    acc A;
    ptr1 = fopen("record1.txt", "w");
    ptr = fopen("record.txt", "r");
    printf("Enter the account no. of the customer:\n");
    scanf("%d", &a);
    while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice) ==10)
    {
        if (a == A.num)
        {
            printf("\n");
            printf("\n");
            // printf("\n");
            printf("Do you want to: \n");
            printf("1.Deposit\n");
            printf("2.Withdraw\n");
            printf("Enter your choice:");
            int z;
            scanf("%d", &z);
            if (z == 1)
            {
                bal = deposit(A.amount);
            }
            else if (z == 2)
            {
                bal = withdraw(A.amount);
            }
            else
            {
                printf("No Account found");
                getch();
                exit(0);
            }
            A.amount = bal;
            fprintf(ptr1, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, A.phone_num, A.amount, A.choice);
        }
        else
        {
            printf("No records Found!\n");
            printf("Enter 0 to try again,1 to return to main menu and 2 to exit:");
            int p;
            scanf("%d", &p);
            if (p == 0)
            {
                transactions();
            }
            else if (p == 1)
            {
                mainmenu();
            }
            else
            {
                exit(0);
            }
            fprintf(ptr1, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, A.phone_num, A.amount, A.choice);
        }
    }
    fclose(ptr1);
    fclose(ptr);
    remove("record.txt");
    rename("record1.txt", "record.txt");
    getch();
}
void detailsAcc(void)
{
    system("cls");
    acc A;
    int a, Acc, b;
    float r, t, intrst;
    FILE *ptr;
    ptr = fopen("record.txt", "r");
    printf("Do you want to check by :\n");
    printf("1.Account Number\n");
    printf("2.Name\n");
    printf("Enter your choice:");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("Enter your Account number:");
        scanf("%d", &Acc);
        fflush(stdin);
        while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice)==10)
        {
            if (Acc == A.num)
            {
                printf("Account number:%d\n", A.num);
                printf("Name:%s\n", A.name);
                printf("DOB:%d\n", A.dob);
                printf("Age:%d\n", A.age);
                printf("Address:%s\n", A.address);
                printf("Citizenship number:%d\n", A.cnum);
                printf("Phone number:%d\n", A.phone_num);
                printf("Type of Account:%s\n", A.choice);
                printf("Amount Deposited:$%d\n", A.amount);
                printf("Date of Deposit:%d\n", A.date);
                printf("\n");
                printf("\n");
                printf("\n");
                if (strcmp(A.choice, "saving") == 0)
                {
                    t = (1.0 / 12.0);
                    r = 8.0;
                    intrst = intrest(A.amount, r, t);
                    printf("You will get $%.2f on next month", intrst);
                }
                else if (strcmp(A.choice, "current") == 0)
                {
                    printf("You will not get any intrest");
                }
                else if (strcmp(A.choice, "fixed1") == 0)
                {
                    t = 1.0;
                    r = 9.0;
                    intrst = intrest(A.amount, r, t);
                    printf("you will get $%.2f intrest next year", intrst);
                }
                else if (strcmp(A.choice, "fixed2") == 0)
                {
                    t = 2.0;
                    r = 11.0;
                    intrst = intrest(A.amount, r, t);
                    printf("you will get $%.2f intrest after next two year", intrst);
                }
                else if (strcmp(A.choice, "fixed3") == 0)
                {
                    t = 3.0;
                    r = 13.0;
                    intrst = intrest(A.amount, r, t);
                    printf("you will get $%.2f intrest after next three year", intrst);
                }
            }
            else
            {
                printf("No Account found\n");
            }
        }
    }
    else if (a==2)
    {
        fflush(stdin);
        char name[20];
        printf("Enter your Name:");
        gets(name);
        while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice)==10)
        {
            if (strcmp(A.name, name) == 0)
            {
                printf("Account number:%d\n", A.num);
                printf("Name:%s\n", A.name);
                printf("DOB:%d\n", A.dob);
                printf("Age:%d\n", A.age);
                printf("Address:%s\n", A.address);
                printf("Citizenship number:%d\n", A.cnum);
                printf("Phone number:%d\n", A.phone_num);
                printf("Type of Account:%s\n", A.choice);
                printf("Amount Deposited:$%d\n", A.amount);
                printf("Date of Deposit:%d\n", A.date);
                printf("\n");
                printf("\n");
                printf("\n");
                if (strcmp(A.choice, "saving") == 0)
                {
                    t = (1.0 / 12.0);
                    r = 8.0;
                    intrst = intrest(A.amount, r, t);
                    printf("You will get $%.2f on next month", intrst);
                }
                else if (strcmp(A.choice, "current") == 0)
                {
                    printf("You will not get any intrest");
                }
                else if (strcmp(A.choice, "fixed1") == 0)
                {
                    t = 1.0;
                    r = 9.0;
                    intrst = intrest(A.amount, r, t);
                    printf("You will get $%.2f intrest next year", intrst);
                }
                else if (strcmp(A.choice, "fixed2") == 0)
                {
                    t = 2.0;
                    r = 11.0;
                    intrst = intrest(A.amount, r, t);
                    printf("You will get $%.2f intrest after next two year", intrst);
                }
                else if (strcmp(A.choice, "fixed3") == 0)
                {
                    t = 3.0;
                    r = 13.0;
                    intrst = intrest(A.amount, r, t);
                    printf("You will get $%.2f intrest after next three year", intrst);
                }
            }
            else 
            {
                printf("No Account found\n");
            }
        }
    }

    else
    {
        printf("No Record found!");
        printf("Enter 0 for try again,1 for main menu,2 for exit");
        scanf("%d", &b);
        if (b == 0)
        {
            detailsAcc();
        }
        else if (b == 1)
        {
            mainmenu();
        }
        else
        {
            exit(0);
        }
    }
    fclose(ptr);
    getch();
}
void removeAcc(void)
{
    system("cls");
    FILE *ptr;
    FILE *ptr1;
    acc A;
    int f = 0, Acc;

    ptr = fopen("record.txt", "r");
    ptr1 = fopen("record1.txt", "w");
    printf("Enter the account number :");
    scanf("%d", &Acc);
    while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s\n", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice)==10 )
    {
        if (A.num == Acc)
        {
            f = 1;
            printf("Removed Successfully");
            getch();
        }
        else
        {
            fprintf(ptr1, "%d %d %s %d %d %s %d %d %d %s\n", A.num, A.date, A.name, A.dob, A.age, A.address, A.cnum, A.phone_num, A.amount, A.choice);
        }
    }
    if (f == 0)
    {
        printf("No Account found");
        getch();
    }
    fclose(ptr);
    fclose(ptr1);
    remove("record.txt");
    rename("record1.txt", "record.txt");
}
int customerlist(void)
{
    system("cls");
    acc A;
    FILE *ptr;

    ptr = fopen("record.txt", "r");
    if(!ptr){
        printf("No file found");
        return 0;
    }
    
    printf("ACC. no. \t NAME \t ADDRESS \t PHONE \n");
    // scanf return number of objects read so here use 10
    while (fscanf(ptr, "%d %d %s %d %d %s %d %d %d %s", &A.num, &A.date, &A.name, &A.dob, &A.age, &A.address, &A.cnum, &A.phone_num, &A.amount, &A.choice)==10)
    {
        printf("%d \t %s \t %s \t %d \n", A.num, A.name, A.address, A.phone_num);
    }
    fclose(ptr);
    getch();
}

void mainmenu(void)
{
    int d;
    system("cls"); // used for cleanscreen not clrscr();
    gotoxy(45, 4);
    {
        printf("BANKING MANAGEMENT SYSTEM\n");
    }
    gotoxy(44, 7);
    {
        printf("***WELCOME TO THE MAIN MENU***\n");
    }
    gotoxy(40, 11);
    {
        printf("[1.] Create a new Account\n");
    }
    gotoxy(40, 12);
    {
        printf("[2.] Update information of existing Account\n");
    }
    gotoxy(40, 13);
    {
        printf("[3.] Transactions\n");
    }
    gotoxy(40, 14);
    {
        printf("[4.] Check the details of existing Account\n");
    }
    gotoxy(40, 15);
    {
        printf("[5.] Remove existing Account\n");
    }
    gotoxy(40, 16);
    {
        printf("[6.] See all Customer's List\n");
    }
    gotoxy(40, 17);
    {
        printf("[7.] ATM Feature\n");
    }
    gotoxy(40, 18);
    {
        printf("[8.] Exit\n");
    }
    gotoxy(40, 21);
    {
        printf("Enter your Choice:");
    }
    scanf("%d", &d);
    if (d == 1)
    {
        system("cls");
        newaccount();
    }
    if (d == 2)
    {
        updateinfo();
    }
    if (d == 3)
    {
        transactions();
    }
    if (d == 4)
    {
        detailsAcc();
    }
    if (d == 5)
    {
        removeAcc();
    }
    if (d == 6)
    {
        customerlist();
    }
    if (d == 7)
    {
        system("cls");
        int a;
        gotoxy(20, 3);
        printf("Enter the PIN no.");
        scanf("%d", &a);
        if (a == 1234)
        {
            printf("PIN matched\n");
            printf("Loading......\n");
            for(int i=0;i<=6;i++)
            {
                delay();
                printf("->");
            }
            // for (int r = 1; r <= 27; r++) // used for loading bar
            // {
            //     for (int q = 0; q <= 10000000; q++)
            //         ;
            //     printf("%c", 177);
            // }
            // getch();
            atm();
        }
        else
        {
            printf("Wrong PIN!!!");
            getch();
            exit(0);
        }
    }
    else
    {
        exit(0);
    }
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void home(void)
{
    int b, c;
    char a[4]; // here it is a string and \0 denotes its ending
               //  chara[]="word";            //this method is also used for string
    gotoxy(50, 4);
    {
        printf("BANK MANGEMENT SYSTEM\n");
    }
    gotoxy(55, 5);
    {
        printf("USER LOGIN\n");
    }
    gotoxy(48, 9);
    {
        printf("Enter the password to login:");
    }
    scanf("%s", a); //1
    if (a[0] == 'w' && a[1] == 'o' && a[2] == 'r' && a[3] == 'd')
    {
        gotoxy(1, 11);
        {
            printf("Password Match!\n");
        }
        gotoxy(1, 12);
        {
            printf("Loading");
        }
        for (int i = 0; i <= 6; i++)
        {
            delay(); // fordelay function used for waiting some time to compiler here 1000 (argument) is milisecond i.e. 1 sec.
            printf(".");
        }
        gotoxy(1, 13);
        {
            printf("Click any key to Continue. . .\n");
        }
        b = getch();
        if (b <= 255)
        {
            mainmenu();
        }
    }
    else
    {
        printf("Wrong Password!!!\n");
        Beep(500, 1000);                               //Beep(frequency,time in mili sec.) its defined in windows.h header file as cleanscrEen.
        printf("Enter 1 to try again or 0 for exit "); //  FROM HERE MISTAKE
        scanf("%d", &c);
        if (c == 1 || c == 0)
        {
            if (c == 1)
            {
                system("cls");
                home();
            }
            else
            {
                exit(0);
            }
        }
        else
        {
            system("cls");
            printf("Invalid!\n");
            Beep(500, 1000);
            printf("Enter 1 to try again or 0 for exit ");
            scanf("%d", &c);
            if (c == 1 || c == 0)
            {
                if (c == 1)
                {
                    system("cls");
                    home();
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                printf("Too much Attempts..");
                getch();
                exit(0);
            }
        }
    }
}