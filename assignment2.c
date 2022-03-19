/*
    Title: Assignment 2
    Date: 14/03/2022
    Author : Jon Kehoe C21372766
    Program Description : This program is a lottory game that contains 5 differnt functions
    1. Takes in 6 numbers from the user
    2. Prints the numbers back to the user
    3. Sorts the numbers from lowest to highest
    4. Compares numbers with the winning numbers and see what the user won
    5. Shows all numbers that have been entered and their frequency
    6. Exits the game
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define SIZEA 43

int *enterNumbers(int *numbersEntered, int *fArray);
int *displayNumbers(int *display);
void sortNumber(int[]);
void compareArray(int *userArray, int *winningNumbers);
void frequencyNumbers(int *fArray);

int main()
{

    char d;
    int userArray[6];
    int winningNumbers[SIZE] = {1, 3, 5, 7, 9, 11};
    int *numbers;
    int *displaying, k, i;
    int *frequency;
    int fArray[43] = {0};
    int num, count = 0;
    int freqSum = 0;

    do
    {
        // Menu Options
        printf("1 - Enter Numbers\n");
        printf("2 - Show Numbers\n");
        printf("3 - Sorted Numbers\n");
        printf("4 - Winnings\n");
        printf("5 - Display frequency\n");
        printf("6 - Exit Game\n");
        scanf("%d", &num);
        d = getchar(); // checks to see if a charecter is input

        if (num == 1) // first option
        {
            // User inputs numbers
            numbers = enterNumbers(userArray, fArray);

            count++; // is used to check that number one is pressed first

        }                  // end if
        else if (num == 2) // second option
        {
            if (count > 0)
            {
                // Displaying the numbers the user input
                displaying = displayNumbers(userArray);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        }                  // end else if
        else if (num == 3) // third option
        {
            if (count > 0)
            {
                // Sorthing the numbers
                sortNumber(numbers);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        }                  // end else if
        else if (num == 4) // fourth option
        {
            if (count > 0)
            {
                // comapring the winning elements and the user input elements
                compareArray(numbers, winningNumbers);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        }                  // end else if
        else if (num == 5) // fifth option
        {
            if (count > 0)
            {
                // frequency of the numbers function
                frequencyNumbers(fArray);
            } // end if
            else
            {
                printf("Need to press option 1 first\n");
            } // end else

        } // end else if
        

    } while (num != 6 && d != (num >= 'a' && num <= 'z'));
    printf("Ending game\n");

    return 0;

} // end main

int *enterNumbers(int *numbersEntered, int *fArray)
{
    int i, k, temp;
    char d;

    printf("Enter %d numbers from 1 to %d and cant be the same number twice : ", SIZE, SIZEA);
    for (int i = 0; i < 6; i++)
    {

        scanf("%d", & *(numbersEntered + i));
        d = getchar(); // checks to see if a charecter is input

        if (*(numbersEntered + i) > 0 && *(numbersEntered + i) < 43)
        {
            for (int k = 0; k < i; k++)
            {
                // checks to see if number is input twice
                if (*(numbersEntered + i) == *(numbersEntered + k))
                {
                    printf("You cant enter the same number twice!!\n");
                    *(numbersEntered + i) = 0;
                    break;

                } // end if

            } // end loop for same number
            if (*(numbersEntered + i) == 0)
            {
                printf("");
                scanf("%d", & *(numbersEntered + i));
            } // end if
        }
        else
        {
            printf("Only enter number 1 to 43\n");
            *(numbersEntered + i) = 0;
        } // end else
        if (*(numbersEntered + i) == 0) // used to enter a new number after error
        {
            printf("");
            scanf("%d", & *(numbersEntered + i));
        } // end if

        temp = *(numbersEntered + i);            // used to place last rounds numbers into a temp variable
        *(fArray + temp) = *(fArray + temp) + 1; // stores temp variable in a array for all past elements input
    }                                            // end for
    return numbersEntered;
} // end enterNumber

int *displayNumbers(int *display)
{
    int i;
    
    printf("Numbers entered are : ");
    for (i = 0; i < SIZE; i++) // used to print numbers without a comma on the last element
    {
        printf("%d", *(display + i));
        if (i < 5)
        {
            printf(", ");
        } // end if
    }     // end for
    printf("\n");
    return 0;
} // end dispalyNumber

void sortNumber(int array4[])
{
    int i, j, temp;
    // Bubble Sort Algorithm
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (*(array4 + i) > *(array4 + j))
            {
                // temp variable is used to store element that is being swapped
                temp = *(array4 + i);
                *(array4 + i) = *(array4 + j);
                *(array4 + j) = temp;
            }// end if
        } // end for
    } // end for

    printf("Sorted elements : ");

    for (i = 0; i < SIZE; i++) // used to print numbers without a comma on the last element
    {
        printf("%d", *(array4 + i));
        if (i < 5)
        {
            printf(", ");
        } // end if
    } // end if
    printf("\n");
} // end sortNumber


void compareArray(int *userArray, int *winningNumbers)
{

    int matched = 0;
    int i,k;

    // looping throught both arrays for comparision of elements
    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < 6; k++)
        {
            if (*(winningNumbers + k) == *(userArray + i))
            {
                matched++;

            } // end if

        } // end for

    } // end out for

    // Used for Debug
    // printf("%d",matched);

    if (matched == 6)
    {
        printf("You won the Jackpot\n");
    } // end if
    else if (matched == 5)
    {
        printf("You won a new Car\n");
    } // end else if
    else if (matched == 4)
    {
        printf("You won a Weekend Away!\n");
    } // end else if
    else if (matched == 3)
    {
        printf("You won a Cinema Pass\n");
    } // end else if
    else
    {
        printf("\nSorry you didnt win anything\n\n");
    }//end else
    

} // end compareArray

void frequencyNumbers(int *fArray)
{
    int i;

    for (int i = 0; i < 43; i++) // Displaying frequency of all numbers entered
    {
        if (*(fArray + i) != 0)
        {
            printf("\nNumber %d ---- %d times\n", i, *(fArray + i));
        } // end if

    } // end for

} // end frequencyNumbers
