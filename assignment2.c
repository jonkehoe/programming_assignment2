#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 6

int *enterNumbers(int *numbersEntered, int *fArray);
int *displayNumbers(int *display);
void sortNumber(int[]);
void compareArray(int[], int[]);
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

            // for (i = 0; i < 12; i++)
            // {
            //     printf("%d", *(frequency + i));
            //     // printf("%d",sortArray[i]);
            // }

        } // end else if
        // for (i = 0; i < 20; i++)
        // {
        //     sortArray[i] = *(frequency + i);
        // }

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

void compareArray(int a[], int b[])
{
    int c[10];
    int i, j;
    int k = 0;
    int x, count;
    int Length = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (a[i] == b[j])
            {
                count = 0;
                for (x = 0; x < k; x++)
                {
                    if (a[i] == c[x])
                        count++;
                }
                if (count == 0)
                {
                    c[k] = a[i];
                    k++;
                }
            }
        }
    }

    // printf("%d",k);

    if (k == 6)
    {
        printf("You won the Jackpot!\n");
    }
    else if (k == 5)
    {
        printf("You won a new Car\n");
    }
    else if (k == 4)
    {
        printf("You won a Weekend Away!\n");
    }
    else if (k == 3)
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
