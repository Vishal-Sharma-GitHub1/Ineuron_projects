#include <stdio.h>
#include <windows.h>
#include <conio.h>

void withFriend();
void withComputer(int);
void printArray(); // To print the array
int readEnteredKey(); // Reads the user input character and return ASCII value of that
int isEmpty(char);
int isWin();
int isDraw();
void win_or_draw(int, int, int, char[], char[]);
void computerMove(int);
void maxChange(int, int, int, int*, int*, int*); // This function will help the computer to find his best move

char a[10] = {}; // Global character array

int main()
{
    printf("Instruction manuals ::");
    printf("\n\n\t-> You are going to play 'Tic Tac Toe Game' ");
    printf("\n\t-> Requirement of this game are two players, second player can be computer also");

    char choice, ch;

    Level:
        fflush(stdin);          // Clearing the buffer
        for(int i=0; i<9; i++)
            a[i] = i+49;        // Filling the array

        printf("\n\n\t\t\t ## Tic Tac Toe ##");

        printf("\n\n\nBelow four choice has been given, You can choose one of them ::");

        printf("\n\t 1. you want to play this game with your friend");
        printf("\n\t 2. you want to play this game with smart computer");
        printf("\n\t 3. you want to play this game with cheater computer");
        printf("\n\t 4. Exit");

        printf("\n\nPlease enter your selected choice: ");
        scanf("%c", &choice);

        switch(choice)
        {
            case '1':
                withFriend(); break;
            case '2':
            case '3':
                withComputer(choice); break;
            case '4':
                printf("\t Thank you! \n"); break;
            default:
                printf("\t Sorry! you have entered wrong choice. \n");
        }

        printf("\n\nDo you want to play again ?");
        printf("\nPress 'Y' to Yes and press any other key to No: ");
        ch = readEnteredKey();
        system("cls");

        if(ch == 'Y' || ch == 'y')
            goto Level;

    return 0;
}

void withFriend()
{
    system("cls");
    char s1[20], s2[20];
    printf("\n\nPlease enter your first player name --> ");
    scanf(" %[^\n]s", s1);
    printf("Please enter your second player name --> ");
    scanf(" %[^\n]s", s2);

    printf("\n Press any key to start the game..... ");
    readEnteredKey();
    system("cls");

    char ch;
    int flag=1, win=0, draw=0;

    while(1)
    {
        printArray();

        flag? printf("\n  %s, enter your marking place: ",s1) : printf("\n  %s, enter your marking place: ",s2);
        ch = readEnteredKey();

        if(isEmpty(ch))
            a[ch-49] = flag? 'x' : '+';

        system("cls");
        if(isWin())
        {
            win=1; break;
        }
        if(isDraw())
        {
            draw=1; break;
        }

        if(flag) flag=0;
        else flag =1;
    }
    printArray();
    win_or_draw(flag,win,draw,s1,s2);
}
void withComputer(int choice)
{
    system("cls");
    char s[20];
    printf("\n\nPlease enter your player name --> ");
    scanf(" %[^\n]s", s);

    printf("\n Press any key to start the game..... ");
    readEnteredKey();
    system("cls");

    char ch;
    int flag=1, win=0, draw=0;

    while(1)
    {
        printArray();

        if(flag)                // player turn
        {
            printf("\n  %s, enter your marking place: ",s);
            ch = readEnteredKey();
            if(isEmpty(ch))
                a[ch-49] = 'x';
        }
        system("cls");
        if(!flag)                   // Computer turn
            computerMove(choice);

        if(isWin())
        {
            win=1; break;
        }
        if(isDraw())
        {
            draw=1; break;
        }

        if(flag) flag=0;
        else flag =1;
    }
    printArray();
    win_or_draw(flag,win,draw,s,"Computer");
}
void printArray()
{
    printf("\n     |     |     \n");
    for(int i=0; i<9; i++)
    {
        if(i == 3 || i == 6)
        {
            printf("\n     |     |     ");
            printf("\n----- ----- -----");
            printf("\n     |     |     \n");
        }

        if(i==2 || i==5 || i==8)
            printf("  %c  ", a[i]);
        else
            printf("  %c  |", a[i]);
    }
    printf("\n     |     |     \n");
}
int readEnteredKey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();

    return c;
}
int isEmpty(char c)
{
    if(c >= '1' && c <= '9' && a[c-49] != 'x' && a[c-49] != '+')
        return 1;

    printf("\n\n  WARNING -> ");
    printf("Your entered place has been already occupied or invalid!");
    printf("\n\t     Press any key to resume the game...");
    readEnteredKey();
    return 0;
}
int isWin()
{
    int p=0, q=1, r=2,  x=0, y=3, z=6;

    for(int i=1; i<=3; i++)
    {
        if(a[p] == a[q] && a[q] == a[r] || a[x] == a[y] && a[y] == a[z])  // Check horizontal and vertical
            return 1;

        p += 3; q += 3; r += 3; // update the values
        x += 1; y += 1; z += 1; // update the values
    }

    int n=0,m=2;
    if(a[n] == a[n+4] && a[n+4] == a[n+8] || a[m] == a[m+2] && a[m+2] == a[m+4]) // Check diagonal
        return 1;

    return 0; // No winning condition exists
}
int isDraw()
{
    for(int i=0; i<9; i++)
        if(a[i] != 'x' && a[i] != '+')
            return 0;

    return 1; // Total places has been filled
}

void win_or_draw(int flag, int win, int draw, char s1[], char s2[])
{
    if(win && flag)  printf("\n\t   Congratulations, %s You won the game \n", s1);      // First player winning condition
    if(win && flag == 0)  printf("\n\t   Congratulations, %s You won the game \n", s2); // Second player winning condition
    if(draw)  printf("\n\t   Match has been draw! \n");                                 // Match draw condition
}

void computerMove(int choice)
{
    for(int i=0; i<9; i++)   // first we'll check computer is going to win or not
        if(a[i] != 'x' && a[i] != '+')
        {
            a[i] = '+';
            if(isWin())
                return;
            else
                a[i] = (char)i+49;
        }

    int flag = 0;
    for(int i=0; i<9; i++)   // Now we'll check player is going to win or not
    {
        if(a[i] != 'x' && a[i] != '+')
        {
            a[i] = 'x';
            if(isWin())
            {
                a[i] = '+';     // We are stopping the player from winning
                if(choice == '2')       // Smart computer
                    return ;
                else if(choice == '3')  // Cheater computer
                    flag ++;
            }
            else
                a[i] = (char)i+49;
        }
    }
    if(flag)
    {
        if(flag > 1)
            printf("Ha Ha Ha ....   I have blocked you on %d places \n", flag);
        return;
    }

    // Copying the current 1d character array into 2d integer array in the form of Player = 1, Empty = 2, Computer = 3
    int b[3][3], i=0,j=0,k=0;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++,k++)
        {
            if(a[k] == 'x')  b[i][j] = 1;
            else if(a[k] == '+')  b[i][j] = 3;
            else  b[i][j] = 2;
        }

    // Finding the maximum multiplication to our move
    int max_row = 0, max_col = 0, max_multi=0, multi=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(b[i][j] == 2)  // Checking in rows
            {
                multi = b[i][0]*b[i][1]*b[i][2];
                maxChange(multi, i, j, &max_multi, &max_row, &max_col);
            }
            if(b[j][i] == 2)  // Checking in columns
            {
                multi = b[0][i]*b[1][i]*b[2][i];
                maxChange(multi, j, i, &max_multi, &max_row, &max_col);
            }
            if(i == j && b[i][j] == 2)  // Checking in right diagonal
            {
                multi = b[0][0]*b[1][1]*b[2][2];
                maxChange(multi, i, j, &max_multi, &max_row, &max_col);
            }
            if(i+j == 2 && b[i][j] == 2)  // Checking in left diagonal
            {
                multi = b[0][2]*b[1][1]*b[2][0];
                maxChange(multi, i, j, &max_multi, &max_row, &max_col);
            }
        }

    int move = (3*max_row)+max_col;
    a[move] = '+';
}
void maxChange(int multi, int i, int j, int *max_multi, int *max_row, int *max_col)
{
    if(*max_multi < multi)
    {
        *max_multi = multi;
        *max_row = i;
        *max_col = j;
    }
}
