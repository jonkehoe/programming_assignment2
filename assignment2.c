#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 6

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
    int num;
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

        } // end if
        else if (num == 2)
        {
            displaying = displayNumbers(numbers);

        } // end else if
        else if (num == 3)
        {
            sortNumber(numbers);

        } // end else if
        else if (num == 4)
        {
            compareArray(numbers, winningNumbers);

        } // end else if
        else if (num == 5)
        {

            frequencyNumbers(fArray);


        } // end else if
        

    } while (num != 6 && d != (num >= 'a' && num <= 'z'));
    printf("Ending game\n");

    return 0;

} // end main

int *enterNumbers(int *numbersEntered, int *fArray)
{
    int temp;
    int i;
    

    printf("Enter 6 numbers : ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &numbersEntered[i]);
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
    
    int i, j;
    int k = 0;
    int x, count;
    int Length = 0;

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


    // printf("%d",count);

    if (count == 6)
    {
        printf("You won the Jackpot!\n");
    }
    else if (count == 5)
    {
        printf("You won a new Car\n");
    }
    else if (count == 4)
    {
        printf("You won a Weekend Away!\n");
    }
    else if (count == 3)
    {
        printf("You won a Cinema Pass!\n");
    }
    else
    {
        printf("\nsorry you didnt win anything\n");
    }
}

void frequencyNumbers(int *fArray)
{
    int i;

    for (int i = 0; i < 43; i++)
    {
        if (*(fArray + i) != 0)//how many times a certain number has been inputted
        {
            printf("\nNumber %d has been selected %d times\n", i, *(fArray + i));
        } // end if

    } // end for
} // end function optionE
