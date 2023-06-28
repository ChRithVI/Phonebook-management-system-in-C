/* Reg. number - itt1819011
   name        - I.G.C Bandara
   Project     - Phonebook management system */

#include <stdio.h>
#include<conio.h>
#include<string.h>

void First();
void add_contact_loop();
void add_contact ();
void list_record();
void search_contact();
void clear_db();
void condition_cleardb();
void menu();
void remove_contact();
void update_contact();
void take_input();

struct contact

{
    char name[40];
    char code[4];
    long int phone_num;
    char sex[10];
    char mail[100];
    char Home_t[35];
};
typedef struct contact contact;

/*CODE STARTS FROM HERE (THE MAIN FUNCTION)*/
int main()
{
    First();
    return 0;
}

/*MENU INPUT FUNCTION */
void First()
{
    int choice;
    while (1)
    {
        menu();
        scanf("%d", &choice);

        if (choice == 1)
        {
            add_contact_loop();
            getchar();
            First();
            break;
        }
        if (choice == 2)
        {
            getchar();
            list_record();
            getchar();
            First();
            break;
        }
        if (choice == 3)
        {
            getchar();
            search_contact();
            getchar();
            getchar();
            First();
            break;
        }
        if (choice == 4)
        {
            getchar();
            remove_contact();
            getchar();
            First();
            break;
        }
        if (choice == 5)
        {
            getchar();
            update_contact();
            getchar();
            First();
            break;
        }
        if (choice == 6)
        {
            getchar();
            condition_cleardb();
            getchar();
            First();
            break;
        }
        if (choice == 7)
        {
            system("cls");
            printf("************************** Good Bye **************************\n");
            exit(0);
        }
        else
        {
            system("cls");
            printf("Invalid choice try again : )\n\n");
            printf("press any key to go back : )\n\n");
            getchar();
            getchar();
            First();
        }
    }
}

/*THE PRINTING MENU*/
void menu()
{
    system("cls");
    system("color 0A");
    printf("\n\n\t\t\********************************************************************\n");
    printf("\t\t\|                                                                  |\n");
    printf("\t\t\|                  Welcome TO PHONE BOOK STSTEM                    |\n");
    printf("\t\t\|                                                                  |\n");
    printf("\t\t\********************************************************************\n\n");
    printf("\t\ ___________________________________\n");
    printf("\t\|                                   |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [1] Add contact                   |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [2] Show list                     |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [3] Search contact Details        |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [4] Remove contact a contact      |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [5] Update contact                |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [6] Delete all contacts           |\n");
    printf("\t\|                                   |\n");
    printf("\t\| [7] exit Phonebook                |\n");
    printf("\t\|                                   |\n");
    printf("\t\|                                   |\n");
    printf("\t\|___________________________________|_\n");

    printf("\n\t\t\ Enter your Choice >: ");

}
/*THIS FUNCTION IS FOR ADD CONTACT OPTION (FILE READ AND WRITE OPTION) IN THIS FUNCTION I CALL FOR ADD_contact_loop FUNCTION FOR REPEAT THE PROCESS*/
void add_contact()
{

    system("cls");
    system("color 0A");
    FILE *cf;
    cf = fopen("db_contact.txt", "ab+");

    contact p;
    take_input(&p);
    fwrite(&p, sizeof(p), 1, cf);
    fflush(stdin);
    fclose(cf);
    system("cls");
}

/*THIS IS FOR REPEAT THE PROCESS OF ADDING CONTACTS*/
void add_contact_loop()
{
    while (1)
    {
        add_contact();
        printf("------Successfully added-------\n");
        char m;
        printf("Are there anyone (y/n):");
        scanf("%s", &m);


        if (m== 'y')
        {
            continue;
        }
        if (m == 'n')
        {
            system("cls");
            printf("All contacts added added Successfully\n");
            printf("Press any key to continue ....\n");
            getchar();
            break;
        }
        else{
            system("cls");
            printf("invalid choice\n");
            printf("All contacts added added Successfully\n");
            printf("Press any key to go to main menu ....\n");
            getchar();
            break;
        }

    }
}

/*PRINT MENU OF TAKING INPUTS IN ADDING CONTACTS*/
void take_input(contact *p)
{

    system("cls");
    system("color 0A");
    printf("\n\t\t******************************************************************************\n");
    printf("\t\t|                             Contact Adding menu                            |\n");
    printf("\t\t******************************************************************************\n\n\n");
    getchar();

    printf("Enter name         : ");
    scanf("%[^\n]s", p->name);

    printf("Enter Home Town    : ");
    scanf("%s", p->Home_t);

    printf("Enter country code : ");
    scanf("%s", p->code);

    printf("Enter mobile no    : ");
    scanf("%ld", &p->phone_num);

    getchar();
    printf("Enter sex          : ");
    scanf("%s", p->sex);

    getchar();
    printf("Enter email        : ");
    scanf("%s", p->mail);
}

/*LIST RECORD FUNCTION*/
void list_record()
{
    system("cls");
    system("color 0A");

    FILE *cf;
    cf = fopen("db_contact.txt", "rb");
    if (cf == NULL)
    {
        printf("No contact available... Please add contacts info from main menu\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        contact p;
        printf("\n\t\t******************************************************************************\n");
        printf("\t\t|                             The List Of Records                            |\n");
        printf("\t\t******************************************************************************\n\n\n");

        while (fread(&p, sizeof(p), 1, cf) == 1)
        {

            printf("name         :%s", p.name);
            printf("\n");

            printf("Home Town    :%s", p.Home_t);
            printf("\n");

            printf("Country Code :%s", p.code);
            printf("\n");

            printf("Phone Number : %ld", p.phone_num);
            printf("\n");

            printf("Sex          : %s", p.sex);
            printf("\n");

            printf("Email Address: %s", p.mail);
            printf("\n");
            fflush(stdin);
            printf("_____________________________________________________________________________\n");
        }
        fflush(stdin);
        fclose(cf);
        printf("\n\nPress any key to continue....\n");
    }
}

/*SEARCH FUNCTION*/
void search_contact()
{
    system("cls");
    system("color 0A");
    printf("\n\t\t******************************************************************************\n");
    printf("\t\t|                             Searching Menu                                 |\n");
    printf("\t\t******************************************************************************\n\n\n");

    long int phone;
    printf("Enter Phone number for search : ");
    scanf("%ld", &phone);

    FILE *cf;
    cf = fopen("db_contact.txt", "rb");
    if (cf == NULL)
    {
        printf("No contact available");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int found = 0; /* This variable is for to check if the person is available in the text file. If available print the person's details and found will be 1*/
        contact p;
        while (fread(&p, sizeof(p), 1, cf) == 1)
        {
            if (p.phone_num == phone)
            {
                found = 1;

                printf("_____________________________________________________________________________\n");

                printf("name         :%s", p.name);
                printf("\n");

                printf("Home Town    :%s", p.Home_t);
                printf("\n");

                printf("Phone Number : %ld", p.phone_num);
                printf("\n");

                printf("Sex          : %s", p.sex);
                printf("\n");

                printf("Email Address: %s", p.mail);
                printf("\n");
                printf("_____________________________________________________________________________\n");

                break;
            }

        }
        if (found == 0)
        {
            system("cls");
            printf("contact is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(cf);
        printf("\n\nPress any key to continue....\n");
    }
}

/*REMOVE CONTACT MENU*/
void remove_contact()
{
    system("cls");
    system("color 40");
    printf("\n\t\t  ******************************************************************************\n");
    printf("\t\t  |                             Remove a Contact Menu                          |\n");
    printf("\t\t  ******************************************************************************\n\n\n");

    system("color 40");

    long int phone;
    printf("Enter Phone number of the contact for remove from phonebook : ");
    scanf("%ld", &phone);

    FILE *cf, *temp_db;
    cf = fopen("db_contact.txt", "rb");
    temp_db = fopen("temp_db", "wb+");
    if (cf == NULL)
    {
        system("color 0A");
        printf("No contacts available\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        contact p;
        int check = 0;
        while (fread(&p, sizeof(p), 1, cf) == 1)
        {
            if (p.phone_num == phone)
            {
                system("cls");
                printf("contact removed successfully\n");
                check = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp_db);
            fflush(stdin);
        }
        if (check == 0)
        {
            system("cls");
            system("color 0A");
            printf("No record found for %d number\n", phone);
        }
        fclose(cf);
        fclose(temp_db);
        remove("db_contact.txt");
        rename("temp_db", "db_contact.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

/*UPDATE CONTACT FUNCTION*/
void update_contact()
{
    system("cls");
    printf("\n\t\t  ******************************************************************************\n");
    printf("\t\t  |                             Updating Menu                                  |\n");
    printf("\t\t  ******************************************************************************\n\n\n");

    long int phone;
    printf("Enter Phone number of the contact you want to update details : ");
    scanf("%ld", &phone);

    FILE *cf, *temp_db;
    cf = fopen("db_contact.txt", "rb");
    temp_db = fopen("temp_db", "wb+");
    if (cf == NULL)
    {
        printf("Error try again!\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int check = 0;
        contact p;
        while (fread(&p, sizeof(p), 1, cf) == 1)
        {
            if (p.phone_num == phone)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp_db);
                system("cls");
                printf("Data updated successfully\n");
                check = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp_db);
            fflush(stdin);
        }
        if (check == 0)
        {
            system("cls");
            printf("No record found for %d number\n", phone);
        }
        fclose(cf);
        fclose(temp_db);
        remove("db_contact.txt");
        rename("temp_db", "db_contact.txt");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

/*CLEAR ALL FUNCTION*/
void clear_db()
{

    system("cls");
    remove("./db_contact.txt");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue ...");
    getchar();
    getchar();
}

/*USED TO CHECK CONDITION FOR BEFROR CLEAR FUNCTION*/
void condition_cleardb()
{
    system("cls");
    system("color 40");
    printf("\n\t\t  ******************************************************************************\n");
    printf("\t\t  |                             Clear All menu                                 |\n");
    printf("\t\t  ******************************************************************************\n\n\n");

    char c;
    printf("Are you sure to clear all input(y/n):");
    scanf("%s", &c);

    if (c == 'y')
    {
        system("color 0A");

        clear_db();
        First();
    }
    if (c == 'n')
    {
        system("cls");
        system("color 0A");
        printf("Nothing cleared.....\n");

        getchar();
        getchar();

        First();
    }
    else
    {
        system("cls");
        system("color 0A");
        printf("Invalid choice.. Going back to main menu... press any key to continue...\n");
        getchar();
        getchar();
        First();
    }
}
