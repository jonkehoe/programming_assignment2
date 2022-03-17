#include <stdio.h>
#include <time.h>
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
    int *displaying, k,i;
    int *frequency;
    int freq2;
    int fArray[43] = {0};
    int num, count = 0;
    int freqSum = 0;
    int sortArray[12];

    do
    {
        // Menu Options
        printf("1 - Enter Numbers\n");
        printf("2 - Show Numbers\n");
        printf("3 - Sorted Numbers\n");
        printf("4 - Winnings\n");
        printf("5 - Display frequency\n");
        scanf("%d", &num);
        d = getchar();

        if (num == 1)
        {
            k = 0;

            numbers = enterNumbers(userArray, fArray);
            count++;
            

        } // end if
        else if (num == 2)
        {
            if (count > 0)
            {
                displaying = displayNumbers(numbers);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }
        
        } // end else if
        else if (num == 3)
        {
            if (count > 0)
            {
                sortNumber(numbers);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        } // end else if
        else if (num == 4)
        {
            if (count > 0)
            {
                compareArray(numbers, winningNumbers);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        } // end else if
        else if (num == 5)
        {
            if (count > 0)
            {
                frequencyNumbers(fArray);
            }
            else
            {
                printf("Need to press option 1 first\n");
            }

        } // end else if
        else
        {
            printf("Input error try again, Only numbers allowed\n");
        }
        

    } while (num != 6 && d != (num >= 'a' && num <= 'z'));
    printf("Ending game\n");

    return 0;

} // end main

int *enterNumbers(int *numbersEntered, int *fArray)
{
    int temp;
    int i,k;
    

    printf("Enter 6 numbers from 1 to 42 and cant be the same number twice : ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &numbersEntered[i]);

        if (*(numbersEntered + i) > 0 && *(numbersEntered + i) < 43)
        {
            for (k = 0; k < i; k++)
            {
                if (*(numbersEntered + i) == *(numbersEntered + k))
                {
                    printf("You cant enter the same number twice\n");
                    break;
                    
                } // end if

            } // end loop for same number
        }
        else
        {
            printf("Numbers must be greater than 1 and less than 42\n");
            printf("Returning to menu\n");
            break;
        } // end else
        
        temp = *(numbersEntered + i);

        *(fArray + temp) = *(fArray + temp) + 1;
    }
    return numbersEntered;
}

int *displayNumbers(int *display)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", display[i]);
    }

    return 0;
}

void sortNumber(int array4[])
{
    int i;
    int j;
    int temp;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array4[i] > array4[j])
            {
                temp = array4[i];
                array4[i] = array4[j];
                array4[j] = temp;
            }
        }
    }

    printf("Sorted numbers are : ");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d", array4[i]);
        if (i < 5)
        {
            printf(", ");
        }
    }
    printf("\n");
}

void compareArray(int *userArray, int *winningNumbers)
{
    
    int i, k, x, count;
    int Length = 0;

    // Bubble Sort Algorithm
    for (i = 0; i < 6; i++)
    {
        for (k = 0; k < 6; k++)
        {
            if (*(winningNumbers + k) == *(userArray + i))
            {
                count++;
            } // end if

        } // end for

    } // end out for

    // Used for Debug
    // printf("%d",count);

    if (count == 6)
    {
        printf("You won the Jackpot!\n");
    } // end if
    else if (count == 5)
    {
        printf("You won a new Car\n");
    } // end else if
    else if (count == 4)
    {
        printf("You won a Weekend Away!\n");
    } // end else if
    else if (count == 3)
    {
        printf("You won a Cinema Pass!\n");
    } // end else if
    else
    {
        printf("\nsorry you didnt win anything\n\n");
    } // end else 

} // end compareArray

void frequencyNumbers(int *fArray)
{
    int i;

    for (int i = 0; i < 43; i++)
    {
        if (*(fArray + i) != 0)
        {
            printf("\nNumber %d ---- %d times\n", i, *(fArray + i));
        } // end if

    } // end for

} // end frequencyNumbers
