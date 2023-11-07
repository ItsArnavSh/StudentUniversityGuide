//University Management System
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//All the definitions of user defined functions are given below:-
void introduction();
void pressEnterToContinue();
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
void viewStudents();
void allotFaculty(char* name,char* branch);
void placementModule();
void viewPlacementDetails();
void allot(char* name,char* branch);
int randint(int min_num, int max_num);
void classroomLocation();
void studentDetails();
void viewReviews();
void complaintBox();
void clearComplaintBox();
void facultyReview();
void logout();
void facultyReviewView();
void clearFacultyReview();
void GroupAllocation();
void walkthrough();
void viewComplaintBox();
void adminWalkthrough();
void facultyWalkthrough();
void studentWalkthrough();
int accs;
char userName[20];
int main()
{
    introduction();
    accs = login();
    walkthrough();
    // 1 accs means Admin, 2 means faculty and 3 means student
    if(accs == 1)
    {
        while(1==1)
        {
            adminMenu();
        }
    }
    if(accs == 2)
    {
        while(1==1)
        {
            facultyMenu();
        }
    }
    if(accs ==3)
    {
        while(1==1)
        {

            studentMenu();
        }
    }
    return 0;
}
//Introduction is used to welcome the user
void introduction()
{
    printf("Welcome to the Student University Guide");
    printf("\n");
    printf("This is a guide for students to help them in their university life");
    pressEnterToContinue();

    return;
}
//To give a general overview of all the functions to the user
void walkthrough()
{
    printf("press 1 for walkthrough\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            if(accs==1)
            {
                adminWalkthrough();
            }
            if(accs==2)
            {
                facultyWalkthrough();
            }
            if(accs==3)
            {
                studentWalkthrough();
            }
            break;
    }
}
//This function is used for timing purposes
//The code wil move ahead only when the user presses enter
void pressEnterToContinue()
{
    printf("\nPress Enter to Continue...");
    while(getchar()!='\n');
    getchar();
}
//This redirects the user to loginAdmin, loginFaculty and loginStudent
int login()
{
    printf("Welcome to the login portal\n");
    printf("Press 1 if you are The Admin\n");
    printf("Press 2 if you are a Faculty\n");
    printf("Press 3 if you are a Student\n");
    int choice;
    scanf("%d", &choice);
    int acc=0;
    switch (choice)
    {
    case 1:
        acc =  1*loginAdmin();
        break;
    case 2:
        acc =  2*loginFaculty();
        break;
    case 3:
        acc =  3*loginStudent();
        break;
    default:
        printf("Invalid Choice\n");
        printf("Please Enter 1 2 or 3!");
        pressEnterToContinue();

        login();
        break;
    }
    if(acc == 0)
    {
        printf("Please try again\n");
        pressEnterToContinue();

        login();
    }

    return(acc);
}
//Logs in the admin of the database
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
        pressEnterToContinue();

        return 1;
    }
    else
    {
        printf("Login Failed\n");
        return 0;
    }
}
//This is used to encrypt the string using Caesar Cipher
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
//Meaning of Caesar Cipher
//The every character is added by a key
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

//Asks for name and password
//First checks if name exists in the list
//If it does, it matches the password
//If everything matches up, the user is given access
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
                strcpy(userName,facName);
                valid=1;
            }
    }
    if(valid==0)
    {
        printf("Name not found\n");
        return 0;
    }
    return 0;
}
//To convert to UPPERCASE
void toUpperCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
//Asks for name and password
//First checks if name exists in the list
//If it does, it matches the password
//If everything matches up, the user is given access
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
                strcpy(userName,facName);
            }
    }
    if(valid==0)
    {
        printf("Name not found\n");
        return 0;
    }
    return 0;
}
//Admin level function, to add new faculty
void addFaculty()
{
    if(accs==1)
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
    pressEnterToContinue();
    allotFaculty(name,branch);
    return;
    }
}
void adminMenu()
{
    printf("Welcome to the admin menu: \n");
    printf("Press 1 to add a new faculty\n");
    printf("Press 2 to add a new student\n");
    printf("Press 3 to add a new notice\n");
    printf("Press 4 to add placements of Alumini\n");
    printf("Press 5 to view placement details\n");
    printf("Press 6 to view faculty reviews\n");
    printf("Press 7 to view the complaint box\n");
    printf("Press 8 to logout and go back to login page\n");
    //Ask all the inputs
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
    case 4:
        placementModule();
        break;
    case 5:
        viewPlacementDetails();
        break;
    case 6:
        viewReviews();
        break;
    case 7:
        viewComplaintBox();
        //To clear the complaint box
        printf("Do you want to clear the complaint box?");
        printf("Press 1 to clear the complaint box\n");
        printf("Press 2 to not clear the complaint box\n");
        int choice2;
        scanf("%d",&choice2);
        switch (choice2)
        {
        case 1:
            clearComplaintBox();
            break;
        case 2:
        //do nothing
            break;
        default:
            printf("Invalid input! Please enter again.");
        }
        break;
    case 8:
        logout();
        break;
    default:
        printf("ERROR\n");
        break;
    }
}
void addStudents()
{
    if(accs==1)
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
    pressEnterToContinue();
    allot(name,branch);
    return;
    }
}
//Admin level access to display notice
void addNotice()
{
    if(accs==1)
    {
    printf("New Notice\n");
    printf("Please Enter the notice: ");
    char notice[100]; // Declare a char array
    scanf("%s",notice); // Read a line from the standard input
    FILE *file = fopen("notice.txt", "w");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", notice);
    fclose(file);
    printf("Notice added successfully\n");
    pressEnterToContinue();

    return;
    }
}
//Menu for students
void studentMenu()
{
    printf("Welcome to the student menu: \n");
    printf("Press 1 to view the notices\n");
    printf("Press 2 to view the faculty\n");
    printf("Press 3 to view the classroom location\n");
    printf("Press 4 to see your personal info\n");
    printf("Press 5 for faculty review\n");
    printf("Press 6 to view the placements\n");
    printf("Press 7 for adding complaints");
    printf("Press 8 to log out\n");
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
    case 3:
        classroomLocation();
        break;
    case 4:
        studentDetails();
        break;
    case 5:
        facultyReview();
        break;
    case 6:
        viewPlacementDetails();
        break;
    case 7:
        complaintBox();
        break;
    case 8:
        logout();
        break;
    default:
        printf("ERROR\n");
        break;
    }
}
//Student and teacher access to notice board
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
    pressEnterToContinue();

    return;
}
//Prints the list of the entire faculty
void viewFaculty()
{
    printf("The faculty are: \n");
    char facName[20];
    FILE *file = fopen("faculty.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    int i=0;
    while(fgets(facName, sizeof(facName), file))
    {
        //To remove the last character from the string
        //And replace it with '\0'
        *(facName+strlen(facName)-1) = '\0';
        i++;
        if(i%3==1)
        {
            printf("%s\t",facName);
        }
        if(i%3==2)
        {
            printf("%s\n",facName);
        }
    }
    fclose(file);
    pressEnterToContinue();
    return;
}
void facultyMenu()
{
    printf("Welcome to the faculty menu: \n");
    printf("Press 1 to view the notices\n");
    printf("Press 2 to view the students\n");
    printf("Press 3 to view your review.\n");
    printf("Press 4 to allocate a group\n");
    printf("Press 5 to log out\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        viewNotice();
        break;
    case 2:
        viewStudents();
        break;
    case 3:
        facultyReviewView();
        printf("Do you want to clear the reviews?");
        printf("Press 1 to clear the reviews\n");
        printf("Press 2 to not clear the reviews\n");
        int choice2;
        scanf("%d",&choice2);
        switch (choice2)
        {
        case 1:
            clearFacultyReview();
            break;
        case 2:
        //do nothing
            break;
        default:
            printf("Invalid input! Please enter again.");
        }
        break;
    case 4:
        GroupAllocation();
        break;
    case 5:
        logout();
        break;
    default:
        printf("ERROR\n");
        break;
    }
}
void viewStudents()
{
    printf("The students are: \n");
    char studentName[20];
    FILE *file = fopen("student.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
        return;
    }
    int i=0;
    while(fgets(studentName, sizeof(studentName), file))
    {
        //To remove the last character from the string
        //And replace it with '\0'
        *(studentName+strlen(studentName)-1) = '\0';
        i++;
        if(i%3==1)
        {
            printf("%s\t",studentName);
        }
        if(i%3==2)
        {
            printf("%s\n",studentName);
        }
    }
    fclose(file);
    printf("Enter a number and press enter to continue: ");
    int a;
    scanf("%d",&a);
    return;
}
void allot(char* name,char* branch)
{
    strcat(name, ".txt");
    char location[20];
    strcpy(location,"students/");
    strcat(location,name);
    FILE *file = fopen(location, "w");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    for(int i=0;i<strlen(name);i++)
    {
        if(*(name+i)=='.')
        {
            *(name+i)='\0';
        }
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", branch);
    int room = randint(1,400);

    printf("The room number allotted is %d\n",room);
    fprintf(file,"%d\n",room);
    //More work here
    fclose(file);

    return;
}
//Generate a random integer from the min index to max index
int randint(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
        // include max_num in output
    }
    else
    {
        low_num = max_num + 1;
        // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
//This is like a classroom map
void classroomLocation()
{
    printf("Welcome to the classroom navigation system for JIIT\n");
    printf("Please enter which class do you want to go to?: ");
    char classroom[5];
    scanf("%s",classroom);
    if(*classroom=='G')
    {
        printf("This classroom is in the ground floor of ABB1\n");
    }
    else if(*classroom=='F' && *(classroom+1)=='F')
    {
        printf("The classroom is in the First Floor of ABB1\n");
    }
    else if(*classroom=='T' && *(classroom+1)=='S')
    {
        printf("The classroom is on the top floor of ABB1\n");
    }
    else if(strcmp(classroom,"JBS")==0)
    {
        printf("The classroom is in Jaypee Business School Building\n");
    }
    else
    {
        printf("It is probably not in the college!");
    }
    pressEnterToContinue();
}
//Prints name, branch, room allotted of the student
void studentDetails()
{
    char location[20];
    strcpy(location,"students/");
    strcat(location,userName);
    strcat(location,".txt");
    FILE *file = fopen(location, "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    char name[20];
    char branch[20];
    int room;
    fgets(name, sizeof(name), file);
    fgets(branch, sizeof(branch), file);
    fscanf(file,"%d",&room);
    printf("Your name is %s\n",name);
    printf("Your branch is %s\n",branch);
    printf("Your room number is %d\n",room);
    pressEnterToContinue();
}
//Make a file for faculty
void allotFaculty(char* name,char* branch)
{
    strcat(name, ".txt");
    char location[20];
    strcpy(location,"faculty/");
    strcat(location,name);
    FILE *file = fopen(location, "w");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    for(int i=0;i<strlen(name);i++)
    {
        if(*(name+i)=='.')
        {
            *(name+i)='\0';
        }
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", branch);
    fclose(file);
    return;
}
//Admin level, used to add students to placement section
void placementModule()
{
    printf("Enter name of the Student");
    char name[20];
    scanf("%s",name);
    printf("Enter the company in which he/she got selected");
    char company[20];
    scanf("%s",company);
    printf("Enter the package he/she got");
    int package;
    scanf("%d",&package);
    //Opening a file in called placement.txt in append mode and adding all this data to it
    FILE *file = fopen("placement.txt", "a");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", company);
    fprintf(file, "%d\n", package);
    fclose(file);
    printf("Placement details added successfully\n");
    pressEnterToContinue();
    return;
}
//Display the placement stats
void viewPlacementDetails()
{
    printf("The placement details are: \n");
    char name[20];
    char company[20];
    int package;
    FILE *file = fopen("placement.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    int i=0;
    while(fgets(name, sizeof(name), file))
    {
        i++;
        *(name+strlen(name)-1) = '\0';
        if(i%3==1)
        {
            printf("%s has been placed at ",name);
        
        }
        if(i%3==2)
        {
            printf("%s with a package of ",name);
        }
        if(i%3==0)
        {
            printf("%s lpa\n",name);
        }
    }
    printf("-----------------------------------------\n");
    fclose(file);
    pressEnterToContinue();
    return;
}
//For faculty to see their review
void viewReviews()
{
    if(accs==1)
    {
    printf("Enter the name of the faculty: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    //To check if the faculty exists
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
            if(strcmp(name,facName)==0)
            {
                printf("Faculty found\n");
                valid=1;
            }
    }
    if(valid==0)
    {
        printf("Faculty not found\n");
        return;
    }
    if(valid==1)
    {
        strcat(name, ".txt");
        char location[20];
        strcpy(location,"faculty/");
        strcat(location,name);
        FILE *file = fopen(location, "r");
        if(file == NULL)
        {
            printf("Could not open file!");
        }
        char review[100];
        while(fgets(review, sizeof(review), file))
        {
            printf("%s\n",review);
        }
        fclose(file);
        pressEnterToContinue();
        return;
    }
    }
}
void complaintBox()
{
    printf("Welcome to the complaint box\n");
    printf("Please describe your issue: ");
    char issue[100];
    scanf("%s",issue);
    FILE *file = fopen("complaint.txt", "a");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    fprintf(file, "%s\n", issue);
    fclose(file);
    printf("Complaint added successfully\n");
    pressEnterToContinue();
}
void clearComplaintBox()
{
    printf("Enter 'confirm' to clear the Complaint Box.\n");
    char confirm[10];
    scanf("%s",confirm);
    if(strcmp(confirm,"confirm")==0)
    {
        FILE *file = fopen("complaint.txt", "w");
        if(file == NULL)
        {
            printf("Could not open file!");
        }
        fclose(file);
        printf("Complaint Box cleared successfully\n");
        pressEnterToContinue();
    }
    else
    {
        printf("Complaint Box not cleared\n");
        pressEnterToContinue();
    }
}
//Complaint box collects all the complains registered by the students
void viewComplaintBox()
{
    printf("The complaints are: \n");
    char complaint[100];
    FILE *file = fopen("complaint.txt", "r");
    if(file == NULL)
    {
        printf("Could not open file!");
    }
    while(fgets(complaint, sizeof(complaint), file))
    {
        printf("%s",complaint);
    }
    fclose(file);
    pressEnterToContinue();

    return;
}
void facultyReview()
{
    printf("Enter the name of the faculty: ");
    char name[20];
    scanf("%s",name);
    toUpperCase(name);
    //To check if the faculty exists
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
            if(strcmp(name,facName)==0)
            {
                printf("Faculty found\n");
                valid=1;
            }
    }
    if(valid==0)
    {
        printf("Faculty not found\n");
        return;
    }
    if(valid==1)
    {
        printf("Enter the review: ");
        char review[100];
        scanf("%s",review);
        strcat(name, ".txt");
        char location[20];
        strcpy(location,"faculty/");
        strcat(location,name);
        FILE *file = fopen(location, "a");
        if(file == NULL)
        {
            printf("Could not open file!");
        }
        fprintf(file, "%s\n", review);
        fclose(file);
        printf("Review added successfully\n");
        pressEnterToContinue();
        return;
    }
}
void facultyReviewView()
{
    char name[30];
    strcpy(name,userName);
    //To check if the faculty exists
    char facName[20];
    int valid = 0;
    //valid is there to check if the name is there or not
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
            if(strcmp(name,facName)==0)
            {
                printf("Faculty found\n");
                valid=1;
            }
    }
    if(valid==0)
    {
        printf("Faculty not found\n");
        return;
    }
    if(valid==1)
    {
        strcat(name, ".txt");
        char location[20];
        strcpy(location,"faculty/");
        strcat(location,name);
        FILE *file = fopen(location, "r");
        if(file == NULL)
        {
            printf("Could not open file!");
        }
        char review[100];
        while(fgets(review, sizeof(review), file))
        {
            printf("%s\n",review);
        }
        fclose(file);
        pressEnterToContinue();
        return;
    }

}
//To clear faculty reviews
void clearFacultyReview()
{
    printf("Enter 'confirm' to clear the Faculty Review.\n");
    char confirm[10];
    scanf("%s",confirm);
    if(strcmp(confirm,"confirm")==0)
    {
        char name[30];
        strcpy(name,userName);
        strcat(name, ".txt");
        char location[20];
        strcpy(location,"faculty/");
        strcat(location,name);
        FILE *file = fopen(location, "w");
        if(file == NULL)
        {
            printf("Could not open file!");
        }
        fclose(file);
        printf("Faculty Review cleared successfully\n");
        pressEnterToContinue();
    }
    else
    {
        printf("Faculty Review not cleared\n");
        pressEnterToContinue();
    }
}
//To allocate groups of students
void GroupAllocation()
{
    //Tyhe purpose of this function is to allot groups for events
    printf("How many max members do you want in the same group?");
    int max;
    scanf("%d",&max);
    FILE *file = fopen("student.txt","r");
    if(file==NULL)
    {
        printf("Could not open file!");
    }
    //To find the number of entries in the txt
    int entries=0;
    char name[20];
    while(fgets(name, sizeof(name), file))
    {
        entries++;
    }
    fclose(file);
    int numberOfStudents = entries/3;
    int numberOfGroups = numberOfStudents/max;
    printf("There are %d groups possible.\n",numberOfGroups);
    printf("The groups are: \n");
    int groupNumber=1;
    //Making an array of all the students in students.txt file
    char students[numberOfStudents][20];
    int i=0;
    FILE *file2 = fopen("student.txt","r");
    if(file2==NULL)
    {
        printf("Could not open file!");
    }
    int n=0;
    while(fgets(name, sizeof(name), file2))
    {
        *(name+strlen(name)-1) = '\0';
        if(i%3==0)
        {
            strcpy(students[n],name);
            n++;
        }
        i++;
    }
    fclose(file2);
    int gno = 1;
    for(int i=0;i<numberOfStudents;i++)
    {
        if(i%max==0)
        {
            printf("\nGroup %d:\n ",gno);
            gno++;
        }
        printf("%s\n ",students[i]);
    }
}
//Logout and restart the code
void logout()
{
    printf("Logging out\n");
    pressEnterToContinue();
    //Rest all the parameters
    *userName = '\0';
    accs = 0;
    main();
}
//All the walkthroughs
void adminWalkthrough()
{
    printf("Welcome to the walkthrough for the admin menu\n");
    printf("\nOption 1: Adding a new faculty allows you to add a new faculty member to the system.\n");
    printf("Option 2: Adding a new student allows you to add a new student to the system.\n");
    printf("Option 3: Adding a new notice allows you to add a new notice to the system.\n");
    printf("Option 4: Adding placements of Alumini allows you to add placement details of Alumini to the system.\n");
    printf("Option 5: Viewing placement details allows you to view the placement details of students.\n");
    printf("Option 6: Viewing faculty reviews allows you to view the reviews of faculty members.\n");
    printf("Option 7: Viewing the complaint box allows you to view the complaints submitted by students.\n");
    printf("Option 8: Clearing the complaint box allows you to clear the complaints submitted by students.\n");
    printf("\n");
}
void facultyWalkthrough()
{
    printf("Welcome to the walkthrough of the faculty menu\n");
    printf("\nOption 1: Viewing the notices allows you to view the notices.\n");
    printf("Option 2: Viewing the students allows you to view the students.\n");
    printf("Option 3: Viewing your review allows you to view the reviews of students.\n");
    printf("Option 4: Allocating a group allows you to allocate groups to students.\n");
    printf("\n");
}
void studentWalkthrough()
{
    printf("Welcome to the walkthrough of the student menu\n");
    printf("\nOption 1: Viewing the notices allows you to view the notices.\n");
    printf("Option 2: Viewing the faculty allows you to view the faculty.\n");
    printf("Option 3: Viewing the classroom location allows you to view the location of the classroom.\n");
    printf("Option 4: Viewing your personal info allows you to view your personal info.\n");
    printf("Option 5: Faculty review allows you to review the faculty.\n");
    printf("Option 6: Viewing the placements allows you to view the placements.\n");
    printf("Option 7: Adding complaints allows you to add complaints.\n");
    printf("\n");
}