#include <stdio.h>
#include <ctype.h>

void customerInfo();
void additionalInformation();
void buyTrainingPlan();
void list();
void update();
int totalPriceCustomer = 0;
int packageCode;
int saunaSessionCode;
int trainerHourCode;
int swimmingSessionCode;

int main()
{

    while (1)
    {
        int userOption;
        printf("***Welcome to the menu***\n");
        printf("***Please select an option***\n");
        printf("1. View the training plan\n");
        printf("2. Create an account\n");
        printf("3. Update your account\n");
        printf("4. Book Additional\n");
        printf("5. View List \n");
        printf("6. Exit the application\n");
        if (scanf("%d", &userOption) != 1)
        {
            printf("Please enter a valid integer option\n");
            while (getchar() != '\n');
                     // Consume the invalid input
            continue; // Continue to the next iteration of the loop
        }

        if (userOption >= 1 && userOption <= 6)
        {
            switch (userOption)
            {
            case 1:
                printf("Viewing the training plan...\n");
                additionalInformation();
                break;
            case 2:
                printf("Creating an account...\n");
                customerInfo();
                break;
            case 3:
                printf("Updating your account...\n");
                update();
                break;
            case 4:
                printf("Booking Additional...\n");
                buyTrainingPlan();
                break;

            case 5:
                printf("Viewing list");
                list();
                break;
            case 6:
                printf("Exiting the application...\n");
                return 0;
            }
        }
        else
        {
            printf("Please enter a valid option between 1 and 5\n");
        }
    }

    return 0;
}

void customerInfo()
{
    char firstName[50];   // stores firstname
    char checkMiddleName; // check whether the customer has a middle name or not
    char middleName[50];  // stores the middle name of the customer
    char lastName[50];    // stores the last name of the customer
    float weight;         // stores the weight of th customer
    char targetWeight;    // stores whether the customer has an target weight or not
    int userTrainingPlan; // stores user training plan preference

    printf("Enter your first name: ");
    scanf(" %s", firstName); // Added space before %s to consume any leading whitespace characters

    printf("Do you have a middle name? (y or n): ");
    scanf(" %c", &checkMiddleName); // Added & before checkMiddleName

    if (checkMiddleName == 'y' || checkMiddleName == 'Y')
    {
        printf("Enter your middle name: ");
        scanf(" %s", middleName);

        printf("Enter your last name: ");
        scanf(" %s", lastName);
    }
    else
    {   
        printf("Enter your last name: ");
        scanf(" %s", lastName);
    }

    printf("Enter your weight in kg: ");
    scanf(" %f", &weight);

    printf("Enter your target weight: ");
    scanf(" %c", &targetWeight);

    printf("Thank you for the information\n");
    printf("Enter 1: View training plan\n");
    printf("Enter 2: Buy training plan\n");
    printf("Enter 3: Return to main menu");
    scanf("%d", &userTrainingPlan);

    while (1)
    {
        if (userTrainingPlan == 1)
        {
            additionalInformation();
            break;
        }
        else if (userTrainingPlan == 2)
        {
            buyTrainingPlan();
            break;
        }
        else if (userTrainingPlan == 3)
        {
            break;
        }
        else
        {
            printf("Invalid input");
            break;
        }
    }
}

void additionalInformation()
{
    printf("Training plans and prices (in NPR):\n\n");
    printf("%-40s %s\n", "Training Plan", "Weekly Fee");
    printf("%-40s %s\n", "Beginner (2 sessions per week)", "1000");
    printf("%-40s %s\n", "Intermediate (3 sessions per week)", "2000");
    printf("%-40s %s\n", "Elite (more than 5 sessions per week)", "3000");
    printf("\nAdditional Services:\n");
    printf("%-40s %s\n", "Private Trainer (per hour)", "500");
    printf("%-40s %s\n", "Sauna (per session)", "1500");
    printf("%-40s %s\n", "Swimming (per session)", "500");

    printf("\n\n");
}

void buyTrainingPlan()
{
    // Printing the menu and prices
    printf("Training plans and prices (in NPR):\n\n");
    printf("%-40s %s\n", "Training Plan", "Weekly Fee");
    printf("%-40s %s\n", "Beginner (2 sessions per week)", "1000");
    printf("%-40s %s\n", "Intermediate (3 sessions per week)", "2000");
    printf("%-40s %s\n", "Elite (more than 5 sessions per week)", "3000");
    printf("\nAdditional Services:\n");
    printf("%-40s %s\n", "Private Trainer (per hour)", "500");
    printf("%-40s %s\n", "Sauna (per session)", "1500");
    printf("%-40s %s\n", "Swimming (per session)", "500");

    // Variables for storing user choices and service quantities
    char package;
    int privateTrainer = 0;
    int sauna = 0;
    int swimming = 0;
    char userChoiceTrainer;
    char userChoiceSauna;
    char userChoiceSwimming;

    printf("Enter b for beginner, i for intermediate, or e for elite package: ");
    scanf(" %c", &package);
    package = tolower(package);

    // Check the package type and update total price
    if (package == 'b')
    {
        printf("You chose beginner package\n");
        totalPriceCustomer += 1000 * 4;
        packageCode = 1;
    }
    else if (package == 'i')
    {
        printf("You chose the intermediate package.\n");
        totalPriceCustomer += 2000 * 4;
        packageCode = 2;
    }
    else if (package == 'e')
    {
        printf("You chose the elite package.\n");
        totalPriceCustomer += 3000 * 4;
        packageCode = 3;
    }
    else
    {
        printf("Invalid package. Please try again.\n");
        return; // Exit the function if the package is invalid
    }

    while (1)
    {
        printf("Do you want a private trainer? (y or n): ");
        scanf(" %c", &userChoiceTrainer);
        userChoiceTrainer = tolower(userChoiceTrainer);
        if (userChoiceTrainer == 'y')
        {
            printf("How many hours do you want the private trainer for? ");
            scanf("%d", &privateTrainer);
            totalPriceCustomer += privateTrainer * 500;
            trainerHourCode = privateTrainer;
            break;
        }
        else if (userChoiceTrainer == 'n')
        {
            printf("Thank you for your response.\n");
            break;
        }
        else
        {
            printf("Invalid command. Please enter 'y' or 'n'.\n");
        }
    }

    while (1)
    {
        printf("Do you want a sauna? (y or n): ");
        scanf(" %c", &userChoiceSauna);
        userChoiceSauna = tolower(userChoiceSauna);
        if (userChoiceSauna == 'y')
        {
            printf("How many sessions do you want the sauna for? ");
            scanf("%d", &sauna);
            totalPriceCustomer += sauna * 1500;
            saunaSessionCode = sauna;
            break;
        }
        else if (userChoiceSauna == 'n')
        {
            printf("Thank you for your response.\n");
            break;
        }
        else
        {
            printf("Invalid command. Please enter 'y' or 'n'.\n");
        }
    }

    while (1)
    {
        printf("Do you want to book swimming sessions? (y or n): ");
        scanf(" %c", &userChoiceSwimming);
        userChoiceSwimming = tolower(userChoiceSwimming);
        if (userChoiceSwimming == 'y')
        {
            printf("How many swimming sessions do you want? ");
            scanf("%d", &swimming);
            totalPriceCustomer += swimming * 500;
            swimmingSessionCode = swimming;
            break;
        }
        else if (userChoiceSwimming == 'n')
        {
            printf("Thank you for your response.\n");
            break;
        }
        else
        {
            printf("Invalid command. Please enter 'y' or 'n'.\n");
        }
    }

    // Displaying total price
    printf("Your total price for the month is:  %d\n", totalPriceCustomer);
}

void list()
{
    printf("Itemized list of services bought:\n");

    switch (packageCode)
    {
    case 1:
        printf("Package: Beginner (2 sessions per week)\n");
        break;
    case 2:
        printf("Package: Intermediate (3 sessions per week)\n");
        break;
    case 3:
        printf("Package: Elite (more than 5 sessions per week)\n");
        break;
    default:
        printf("Package: Unknown\n");
    }

    printf("You chose %d hour(s) of personal training\n", trainerHourCode);
    printf("You chose %d session(s) of sauna\n", saunaSessionCode);
    printf("You chose %d session(s) of swimming\n", swimmingSessionCode);

    printf("Your total price for the month is:  %d\n", totalPriceCustomer);
}

// int saunaSessionCode;
// int trainerHourCode;
// int swimmingSessionCode;

void update(){
 customerInfo();
}