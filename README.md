Requirements:
Develop a program that will play the Lotto game. The program should allow a user to enter their 6 selected numbers and give them a set of options, each performing a specific requirement. You must store the 6 numbers in a 1-Dimensional array.
There are a number of requirements that your program must meet. Your program must be modularised (i.e., use functions) and each task should be dealt in a separate function. The program should display a simple menu to the user and each option in the menu will be implemented by calling a separate function. You must use pointer notation to access array elements – DO NOT use subscript notation.

The requirements are as follows (each implemented in a separate function):
1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Perform any necessary validation (error-checking) required (e.g., all numbers must be different, range 1–42, etc.).
2. Display the contents of the 1-D array containing your lotto numbers that you entered.
3. Sort the contents of the array in increasing order (i.e., 1st element = smallest number, 2nd element = 2nd smallest number, etc.). You may use any sorting algorithm of your choice.
4. Compare your chosen lotto numbers in the 1-D array with the following winning numbers: 1,3,5,7,9,11 (Winning numbers)

Depending on how many of your chosen numbers match the above winning numbers, your program should display one of the following messages:
Match 6 - Jackpot, Match 5 - New car, Match 4 - Weekend away, Match 3 - Cinema pass

5. Display the frequency of the numbers entered each time the user enters a new set of numbers (without exiting the program) on the screen. For example, it might display:
number 1 has been selected x times number 7 has been selected x times number 28 has been selected x times etc.,
6. Exit program



Extra:
• After a function has completed, your program should return to the main menu and allow the user to select another option.
• The user should only be allowed to select options 2, 3, 4 & 5 only if they have correctly entered their 6 valid chosen numbers, i.e., option 1. Display appropriate error messages to handle any errors.
