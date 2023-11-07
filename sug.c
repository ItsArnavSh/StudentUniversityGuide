#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif
#include <stdlib.h>
#include <string.h>
//For using Sleep in C
void introduction();
void cls();
void pause(int milliseconds);
int login();
int loginAdmin();
int loginFaculty();
int loginStudent();
void encrypt(char *str, int key);
void decrypt(char *str, int key);
int main()
{
    introduction();
    int access = login();
    // 1 access means Admin, 2 means faculty and 3 means student
    return 0;
}
void introduction()
{
    printf("Welcome to the Student University Guide");
    pause(1000);
    cls();
    printf("This is a guide for students to help them in their university life");
    pause(3000);
    cls();
    return;
}
void cls()
{
    system("cls");
}
void pause(int milliseconds)
{ // cross-platform sleep function
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    if (milliseconds >= 1000)
      sleep(milliseconds / 1000);
    usleep((milliseconds % 1000) * 1000);
#endif
}
int login()
{
    printf("Welcome to the login portal\n");
    printf("Press 1 if you are The Admin\n");
    printf("Press 2 if you are a Faculty\n");
    printf("Press 3 if you are a Student\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        return loginAdmin();
        break;
    case 2:
        return loginFaculty();
        break;
        /*
    case 3:
        return loginStudent();
        break;
        */
    default:
        printf("Invalid Choice\n");
        printf("Please Enter 1 2 or 3!");
        pause(2000);
        cls();
        login();
        break;
    }
}
int loginAdmin()
{
    printf("Welcome to admin login\n");
    printf("Please Enter the system password:");
    char password[20];
    scanf("%s",password);
    encrypt(password, 5);
    decrypt(password,5);
    if(strcmp(password,"admin")==0)
    {
        printf("Login Successful\n");
        cls();
        return 1;
    }
    else
    {
        printf("Login Failed\n");
        return 0;
    }
}
void encrypt(char *str, int key)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + key) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + key) % 26;
        }
    }
}

// Function to decrypt a string using a Caesar cipher
void decrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' - key + 26) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' - key + 26) % 26;
        }
    }
}
int loginFaculty()
{
    printf("Welcome to faculty login\n");
    printf("Please Enter your name: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    printf("Please Enter your password: ");
    char password[20];
    scanf("%s",password);
    char facName[20];
    int valid = 0;
    FILE *file = fopen("faculty.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(facName, sizeof(facName), file))
    {
        printf("-%s-",facName);
        if(valid == 2)
        {
            if(strcmp(password,facName)==0)
            {
                printf("Login Successful\n");
                return 1;
            }
            else
            {
                printf("Login Failed\n");
                return 0;
            }
        }
        if(valid == 1)
        {
            valid++;
        }
        if(strcmp(facName,name)==0)
            {
                valid=1;
            }
    }
    if(valid==0)
    {
        printf("Name not found\n");
        return 0;
    }

}
void toUpperCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
