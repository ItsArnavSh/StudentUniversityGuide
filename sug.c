#include <windows.h>
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
void toUpperCase(char *str);
void addFaculty();
void addStudents();
void adminMenu();
void addNotice();
void studentMenu();
void viewNotice();
void viewFaculty();
void facultyMenu();
int access;
int main()
{
    introduction();
    access = login();
    // 1 access means Admin, 2 means faculty and 3 means student
    if(access == 1)
    {
        while(1==1)
        {
            cls();
            adminMenu();
        }
    if(access == 2)
    {
        while(1==1)
        {
            cls();
            facultyMenu();
        }
    }
    }
    if(access ==3)
    {
        while(1==1)
        {
            cls();
            studentMenu();
        }
    }
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
{ 
    Sleep(milliseconds);
}
int login()
{
    printf("Welcome to the login portal\n");
    printf("Press 1 if you are The Admin\n");
    printf("Press 2 if you are a Faculty\n");
    printf("Press 3 if you are a Student\n");
    int choice;
    scanf("%d", &choice);
    int access;
    switch (choice)
    {
    case 1:
        access =  1*loginAdmin();
        break;
    case 2:
        access =  2*loginFaculty();
        break;
    case 3:
        access =  3*loginStudent();
        break;
    default:
        printf("Invalid Choice\n");
        printf("Please Enter 1 2 or 3!");
        pause(2000);
        cls();
        login();
        break;
    }
    if(access == 0)
    {
        printf("Please try again\n");
        pause(2000);
        cls();
        login();
    }
    cls();
    return(access);
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
        pause(1000);
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
        *(facName+strlen(facName)-1) = '\0';
        //facname always is printed with an extra '\0'
        //So we remove that from the code above
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
int loginStudent()
{
    printf("Welcome to student login\n");
    printf("Please Enter your name: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    printf("Please Enter your password: ");
    char password[20];
    scanf("%s",password);
    char facName[20];
    int valid = 0;
    FILE *file = fopen("student.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(facName, sizeof(facName), file))
    {
        *(facName+strlen(facName)-1) = '\0';
        //facname always is printed with an extra '\0'
        //So we remove that from the code above
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
void addFaculty()
{
    if(access==1)
    {
    printf("New Faculty\n");
    printf("Please Enter the name of the faculty: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    printf("Please Enter the password of the faculty: ");
    char password[20];
    scanf("%s",password);
    printf("Please enter the Branch of the faculty: ");
    char branch[20];
    scanf("%s",branch);
    FILE *file = fopen("faculty.txt", "a");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", branch);
    fprintf(file, "%s\n", password);
    fclose(file);
    printf("Faculty added successfully\n");
    pause(2000);
    cls();
    return;
    }
}
void adminMenu()
{
    printf("Welcome to the admin menu: \n");
    printf("Press 1 to add a new faculty\n");
    printf("Press 2 to add a new student\n");
    printf("Press 3 to add a new notice");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        addFaculty();
        break;
    case 2:
        addStudents();
        break;
    case 3:
        addNotice();
        break;
    }
}
void addStudents()
{
    if(access==1)
    {
    printf("New Student\n");
    printf("Please Enter the name of the Student: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    printf("Please Enter the password of the Student: ");
    char password[20];
    scanf("%s",password);
    printf("Please enter the Branch of the Student: ");
    char branch[20];
    scanf("%s",branch);
    FILE *file = fopen("student.txt", "a");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", branch);
    fprintf(file, "%s\n", password);
    fclose(file);
    printf("Student added successfully\n");
    pause(2000);
    cls();
    return;
    }
}
void addNotice()
{
    if(access==1)
    {
    printf("New Notice\n");
    printf("Please Enter the notice: ");
    char notice[100]; // Declare a char array
    fgets(notice, sizeof(notice), stdin); // Read a line from the standard input
    FILE *file = fopen("notice.txt", "w");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", notice);
    fclose(file);
    printf("Notice added successfully\n");
    pause(2000);
    cls();
    return;
    }
}
void studentMenu()
{
    printf("Welcome to the student menu: \n");
    printf("Press 1 to view the notices\n");
    printf("Press 2 to view the faculty\n");
    printf("Press 3 to view the students");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        viewNotice();
        break;
    case 2:
        viewFaculty();
        break;
    }
}
void viewNotice()
{
    printf("The notices are: \n");
    char notice[1000];
    FILE *file = fopen("notice.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(notice, sizeof(notice), file))
    {
        printf("%s",notice);
    }
    fclose(file);
    pause(2000);
    cls();
    return;
}
void viewFaculty()
{
    printf("The faculty are: \n");
    char facName[20];
    FILE *file = fopen("faculty.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(facName, sizeof(facName), file))
    {
        printf("%s",facName);
    }
    fclose(file);
    pause(2000);
    cls();
    return;
}
void facultyMenu()
{
    printf("Welcome to the faculty menu: \n");
    printf("Press 1 to view the notices\n");
    printf("Press 2 to view the students");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        viewNotice();
        break;
    case 2:
        viewFaculty();
        break;
    }
}
void viewStudents()
{
    printf("The students are: \n");
    char studentName[20];
    FILE *file = fopen("students.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(studentName, sizeof(studentName), file))
    {
        printf("%s",studentName);
    }
    fclose(file);
    printf("Enter a number and press enter to continue: ");
    int a;
    scanf("%d",&a);
    cls();
    return;
}