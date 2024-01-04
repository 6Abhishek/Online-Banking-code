#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char name[50];
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};
int main()
{

    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50], name[50];
    int opt;
    char cont = 'y';
    int choice;
    float amount;

    printf("\nPlease select your choice");
    printf("\n\n1. Resistor account.");
    printf("\n2. Login to account.");
    usr.balance = 0;
    printf("\n\nYour Choice: ");
    scanf("%d", &opt);

    if (opt == 1)
    {

        system("cls");
        printf("Enter your name: ");
        fflush(stdin);
        gets(name);
        strcpy(usr.name, name);
        printf("Enter your account number: ");
        scanf("%s", usr.ac);
        printf("Enter your phone number: ");
        scanf("%s", usr.phone);
        printf("Enter your password: ");
        scanf("%s", usr.password);

        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "wb");
        fwrite(&usr, sizeof(struct user), 1, fp);
        fclose(fp);
        if (fwrite != 0)
        {

            printf("\nAccount succesfully registered.");
            printf("\nTHANK YOU :-)");
            printf("\n\n1. Login\n2. Exit");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                goto LOGIN;
            }
            else if (choice == 2)
            {
                exit(1);
            }
        }
        else
        {

            printf("\nSomething went wrong please try again.");
        }
    }

    else if (opt == 2)
    {
    LOGIN:
        system("cls");

        printf("\nPhone number: ");
        scanf("%s", &phone);
        printf("\nPassword: ");
        scanf("%s", &pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "rb");
        if (fp == NULL)
        {
            printf("\nAccount number not registered");
        }
        else
        {

            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {

                while (cont == 'y')
                {   
                   
                    system("cls");
                    printf("WELCOME, %s\n", usr.name);
                    printf("\nPress 1 to know balance");
                    printf("\npress 2 to deposit the amount");
                    printf("\nPress 3 to withdraw");
                    printf("\nPress 4 to online transfer money");
                    printf("\nPress 5 to cnange the password");
                    printf("\nPress 6 to Exit");
                    printf("\n\nEnter you choice: ");
                    scanf("%d", &choice);
                    switch (choice)
                    {

                    case 1:
                        printf("\nYour current balance is %.2f", usr.balance);
                        break;

                    case 2:
                        printf("\nEnter the amount: ");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "wb");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        fclose(fp);
                        if (fwrite != 0)
                        {

                            printf("\nAmount deposit succesfully");
                        }

                        break;

                    case 3:
                        printf("\nEnter the amount: ");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "wb");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != 0)
                        {
                            printf("\nYou withdrawn amount: %.2f", amount);
                        }
                        fclose(fp);
                        break;

                    case 4:
                        printf("\nEnter the Phone number to transfare the monery: ");
                        scanf("%s", &phone);

                        strcpy(filename, phone);
                        fp = fopen(strcat(filename, ".dat"), "rb");
                        if (fp == NULL)
                        {
                            printf("\nAccount number is not registered");                          
                        }                       
                        else
                        {
                            printf("\nEnter the amount: ");
                            scanf("%f", &amount);
                            fread(&usr1, sizeof(struct user), 1, fp);
                            fclose(fp);

                            if (amount > usr.balance)
                            {
                                printf("\nInsufficient balance");
                            }
                            else
                            {

                                fp = fopen(filename, "wb");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1, fp);
                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nYour amount transfered sucessfully Rs:%0.2f", amount);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "wb");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                        }
                        break;
                    case 5:
                        printf("\nPlease enter your new password: ");
                        scanf("%s", &pword);
                        fp = fopen(filename, "wb");
                        strcpy(usr.password, pword);
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nPassword succesfully changed");
                        fclose(fp);
                        break;
                    case 6:
                        exit(2);

                    default:
                        printf("\nInvalid choice");
                    }
                    printf("\nIf you want continue press \"y\" , else \"n\": ");
                    fflush(stdin);
                    scanf("%c", &cont);
                    
                }
            }
            else
            {
                printf("\nInvalid password");
            }
        }
    }
    return 0;
}