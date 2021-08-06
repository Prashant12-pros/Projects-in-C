#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
int player, choice;
int returncheck;
char mark;


int checkforWin();
void displayBoard();
int boardmark(char mark);


int main()
{
    int gamestatus;

    char mark;

    player = 1;

    do{

        displayBoard();


        player = (player % 2) ? 1 : 2;

        printf("Player %d enter the place to mark: \n", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        boardmark(mark);

        gamestatus = checkforWin();

        player++;              //here, the player value gets incrimented by 1, so any number divided by 2 will get 1 or 2 as remainders.

    }while (gamestatus == -1);

    if(gamestatus == 1){
        printf("\tCongratulations, player %d has won\n", --player);
    }
    else
    {
        printf("\tGame Draw!!");
    }
    
    
    
    return 0;
}


int checkforWin()
{
    int returncheck = 0;

    if(board[1] == board[2] && board[2] == board[3])
        returncheck = 1;
    else if (board[4] == board[5] && board[5] == board[6])
        returncheck = 1;
    else if(board[7] == board[8] && board[8] == board[9])
        returncheck = 1;
    else if(board[1] == board[5] && board[5] == board[9])
        returncheck = 1;
    else if (board[3] == board[5] && board[5] == board[7])
        returncheck = 1;
    else if (board[1] == board[4] && board[4] == board[7])
        returncheck = 1;
    else if (board[2] == board[5] && board[5] == board[8])
        returncheck = 1;
    else if (board[3] == board[6] && board[6] == board[9])
        returncheck = 1;

    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && 
        board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && 
        board[8] != '8' && board[9] != '9')
        returncheck = 0;
    
    else
        returncheck = -1;

    return returncheck;
}


void displayBoard()
    {
        system("cls");
        printf("\tTIC TAC TOE\t\n");
        printf("PLAYER 1 has (x) \t PLAYER 2 has (o)\t \t \t\n ");

        printf("   |     |   \n");
        printf("%c   |  %c  |  %c  \n", board[1], board[2], board[3]);

        printf("____|_____|____\n");

        printf("    |     |   \n");
        printf("%c   |  %c  |  %c  \n", board[4], board[5], board[6]);

        printf("____|_____|____\n");

        printf("    |     |   \n");
        printf("%c   |  %c  |  %c  \n", board[7], board[8], board[9]);
        printf("    |     |   \n");
    }



int boardmark(char mark)
{
    if(choice == 1 && board[1] == '1')
        board[1] = mark;

    else if(choice == 2 && board[2] == '2')
        board[2] = mark;

    else if(choice == 3 && board[3] == '3')
        board[3] = mark;

    else if(choice == 4 && board[4] == '4')
        board[4] = mark;
    
    else if(choice == 5 && board[5] == '5')
        board[5] = mark;

    else if(choice == 6 && board[6] == '6')
        board[6] = mark;

    else if(choice == 7 && board[7] == '7')
        board[7] = mark;

    else if(choice == 8 && board[8] == '8')
        board[8] = mark;

    else if(choice == 9 && board[9] == '9')
        board[9] = mark;

    else{
        printf("\tInvalid marker!\n");

        player--;       //here, as the player has been incrimented even after the wrong attempt, it will decrement the value by 1, thus returning to the original player!
        getch();        //this requires the user to press enter for futher actions
    }


}