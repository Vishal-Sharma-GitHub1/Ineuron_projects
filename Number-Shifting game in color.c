#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

int Left_shift(int a[], int b);
int Right_shift(int a[], int b);
int Up_shift(int a[], int b);
int Down_shift(int a[], int b);

// Function to shuffle the array
void randomize(int[]);
// Reads the user input character and return ASCII value of that
int readEnteredKey();
// Print the matrix
void printMatrix(int[]);
// Function, If pressed arrow key is not suitable to shift the number
void Not_applicable();

int main()
{
    // below command will help us to change the color
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    int a[16], Blank = 15, moves = 10, inner_flag, flag;


    // Yellow color
    SetConsoleTextAttribute(hc, 0x6);
    printf("Instruction manuals ::");

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\n\n\t-> You are going to play 'Number Shifting Game' ");
    printf("\n\t-> Requirement of this game is only one player");

    char name[20];

    // Yellow color
    SetConsoleTextAttribute(hc, 0x6);
    printf("\n\nHi Player, Please enter your name: ");

    // Green color
    SetConsoleTextAttribute(hc, 0x2);
    scanf("%[^\n]s", name);

    // To clear the console
    system("cls");

    printf("\n\t\t\t\t !! Welcome %s !!", name);

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\n\n\tSo Hi %s, Before playing this game, please know all the rules of this game once", name);
    printf("\n\tAll the rules given below --> ");

    // Red color
    SetConsoleTextAttribute(hc, 0x4);
    printf("\n\n\nRULES OF GAME ::");

    // Yellow color
    SetConsoleTextAttribute(hc, 0x6);
    printf("\n\n 1. You can move only 1 step at a time with the arrow key.");

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\n\tMove Up : by Up arrow key");
    printf("\n\tMove Down : by Down arrow key");
    printf("\n\tMove Left : by Left arrow key");
    printf("\n\tMove Right : by Right arrow key");

    // Yellow color
    SetConsoleTextAttribute(hc, 0x6);
    printf("\n 2. You can move numbers at an empty position only.");
    printf("\n 3. For each valid move : your total number of moves will decrease by 1.");
    printf("\n 4. You can exit the game at any time by pressing 'E' or 'e'.");

    // Red color
    SetConsoleTextAttribute(hc, 0x4);
    printf("\n\nWINNING SITUATION ::");

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\n\n\t-> We will give you a unsorted matrix of 4X4 size. And that matrix will contain first 15 natural numbers");
    printf("\n\t-> If you sort the matrix in order from 1 to 15 before your moves are over, you will win");
    printf("\n\n\tWinning situation given below -->");

    // Green color
    SetConsoleTextAttribute(hc, 0x2);
    printf("\n\n\t\t\t\t---------------------");
    printf("\n\t\t\t\t|  1 |  2 |  3 |  4 |");
    printf("\n\t\t\t\t|  5 |  6 |  7 |  8 |");
    printf("\n\t\t\t\t|  9 | 10 | 11 | 12 |");
    printf("\n\t\t\t\t| 13 | 14 | 15 |    |");
    printf("\n\t\t\t\t---------------------");

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\n\nBEST OF LUCK! Try to win in minimum number of moves");
    printf("\nPress any key to start the Game.....");
    readEnteredKey();

    // If user will want to play again the game, then control will come here
    Level:

    // Initializing array with simply first 15 natural numbers in ascending order
    for(int i=0; i<15; i++)
        a[i] = i+1;
    Blank = 15; moves = 10; inner_flag; flag;

    // call this function to shuffle the array elements
    randomize(a);
    // Filled space in last element
    a[15] = 32;

    // Outer main loop
    while(moves>=0)
    {
        // To clear the console
        system("cls");

        // This variable will help us to check array is sorted or not
        inner_flag = 1;
        for(int i=0; i<15; i++)
            if(a[i] != i+1)
            {
                inner_flag = 0;
                break;
            }

        // Winning condition
        if(inner_flag)
        {
            // Green color
            SetConsoleTextAttribute(hc, 0x2);
            printf("\n\nHurray! congratulations you have won the Game");
            break;
        }

        // lose condition
        if(moves == 0)
        {
            // Red color
            SetConsoleTextAttribute(hc, 0x4);
            printf("\n\n\t\tGAME OVER!");
            printf("\n\t\tYou Lose !!");
            break;
        }

        // If moves are less than 5 then we we'll print number of moves in red color otherwise in white color
        if(moves < 5)
        {
            // Red color
            SetConsoleTextAttribute(hc, 0x4);
            printf("\n\n  %s, Now you only have %d moves left", name, moves);
        }
        else
        {
            // White color
            SetConsoleTextAttribute(hc, 0x7);
            printf("\n\n  %s, you have %d moves left", name, moves);
        }

        // White color
        SetConsoleTextAttribute(hc, 0x7);
        printMatrix(a);

        printf("\n\nPress any arrow key: ");

        // if user enters any non arrow key then the 'flag' variable will remain 1, otherwise it will 0.
        flag = 1;
        // Inner loop
        while( flag )
        {
            int key = readEnteredKey();
            switch( key )
            {
                // User want to exit
                case 101: // ASCII of 'e'
                case 69:  // ASCII of 'E'
                    // Green color
                    SetConsoleTextAttribute(hc, 0x2);
                    printf("\n\n\t\t Thank you for playing! \n");
                    // White color
                    SetConsoleTextAttribute(hc, 0x7);
                    exit(0);

                // User has pressed up-shift key
                case 72 :
                    if(Up_shift(a, Blank))
                    {
                        moves--;
                        Blank += 4;
                        flag = 0;
                    }
                    else
                        // call this function if pressed arrow key is not applicable to shift the number
                        Not_applicable();
                    break;

                // User has pressed down-shift key
                case 80 :
                    if(Down_shift(a, Blank))
                    {
                        moves--;
                        Blank -= 4;
                        flag = 0;
                    }
                    else
                        // call this function if pressed arrow key is not applicable to shift the number
                        Not_applicable();
                    break;

                // User has pressed left-shift key
                case 75 :
                    if(Left_shift(a, Blank))
                    {
                        moves--;
                        Blank++;
                        flag = 0;
                    }
                    else
                        // call this function if pressed arrow key is not applicable to shift the number
                        Not_applicable();
                    break;

                // User has pressed right-shift key
                case 77 :
                    if(Right_shift(a, Blank))
                    {
                        moves--;
                        Blank--;
                        flag = 0;
                    }
                    else
                        // call this function if pressed arrow key is not applicable to shift the number
                        Not_applicable();
                    break;

                // User have not pressed any arrow key
                default:
                    // Yellow color
                    SetConsoleTextAttribute(hc, 0x6);
                    printf("\nWARNING -> ");
                    // White color
                    SetConsoleTextAttribute(hc, 0x7);
                    printf("Your character is not valid! \n\t   Press any arrow key: ");

                // End of switch-case
            }
        // End of inner while loop
        }
    // End of outer while loop
    }

    // Green color
    SetConsoleTextAttribute(hc, 0x2);
    printf("\n\nDo you want to play again ?");

    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("\nPress 'Y' to Yes and press any other key to No: ");
    char choice = readEnteredKey();

    if(choice == 'y' || choice == 'Y')
        goto Level;

    printf("\n\n");
    return 0;

// End of main function
}

int Left_shift(int a[], int b)
{
    if(b == 3 || b == 7 || b == 11 || b == 15)
        return 0;
    else
    {
        a[b] = a[b+1];
        a[b+1] = 32;
    }
    return 1;
}
int Right_shift(int a[], int b)
{
    if(b == 0 || b == 4 || b == 8 || b == 12)
        return 0;
    else
    {
        a[b] = a[b-1];
        a[b-1] = 32;
    }
    return 1;
}
int Up_shift(int a[], int b)
{
    if(b == 12 || b == 13 || b == 14 || b == 15)
        return 0;
    else
    {
        a[b] = a[b+4];
        a[b+4] = 32;
    }
    return 1;
}
int Down_shift(int a[], int b)
{
    if(b == 0 || b == 1 || b == 2 || b == 3)
        return 0;
    else
    {
        a[b] = a[b-4];
        a[b-4] = 32;
    }
    return 1;
}

void randomize(int arr[])
{
    int i,j,temp;

    srand(time(NULL));

    for(i=14; i>0; i--)
    {
        j = rand()%(i+1);

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int readEnteredKey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();

    return c;
}
void printMatrix(int a[])
{
    printf("\n\n---------------------");
    for(int i=0; i<16; i++)
    {
        if(i == 0 || i == 4 || i == 8 || i == 12)
            printf("\n|");

        if(a[i] == 32)
            printf(" %2c |", a[i]);
        else
            printf(" %2d |", a[i]);
    }
    printf("\n---------------------");
}
void Not_applicable()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    // Yellow color
    SetConsoleTextAttribute(hc, 0x6);
    printf("\nWARNING -> ");
    // White color
    SetConsoleTextAttribute(hc, 0x7);
    printf("According to your pressed arrow key, number can't shift");
    printf("\n\t   Please press a arrow key which is applicable to shift the number");
    printf("\n\t   Press any arrow key: ");
}
