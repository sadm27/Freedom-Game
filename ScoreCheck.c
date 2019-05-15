#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

// initialize a 2d board (3,3) with asterisk 
void drawBoard(char board[10][10]);
bool inBounds(int row, int column);
bool adjacencyCheckX(int row, int column, int rowO, int columnO);
bool adjacencyCheckO(int row, int column, int rowX, int columnX);
bool isEmpty(char board[10][10], int row, int column);
void Xplacment(bool valid, char board[10][10], int row, int column, int rowX, int columnX);
void Oplacment(bool valid, char board[10][10], int row, int column, int rowO, int columnO);
bool XfullAdjacency(bool valid, char board[10][10], int row, int column, int rowO, int columnO);
bool OfullAdjacency(bool valid, char board[10][10], int row, int column, int rowX, int columnX);
int check_WinnerX(char board[10][10]);
int check_WinnerO(char board[10][10]);

int main(){
    char board[10][10]={
   /*1*/{'X','O','X','O','O','X','O','O','X','O'},
   /*2*/{'X','O','X','X','O','O','X','X','X','O'},
   /*3*/{'O','O','X','O','X','O','X','O','X','X'},
   /*4*/{'X','X','O','X','X','O','X','O','O','O'},
   /*5*/{'X','O','X','O','O','O','X','X','O','X'},
   /*6*/{'X','X','O','X','X','X','O','X','X','O'},
   /*7*/{'O','O','X','O','O','X','X','O','X','X'},
   /*8*/{'X','O','X','O','X','X','O','O','O','O'},
   /*9*/{'X','X','X','X','O','O','X','X','X','X'},
  /*10*/{'O','X','O','O','X','X','X','O','O','X'}};  //},}
       // 1   2   3   4   5   6   7   8   9   10 
    bool win = false;
    bool in_row = false;
    bool in_col = false;
    int row;
    int column;
    char tempBuffer[BUFFER_SIZE] = "";
    int scoreX;
    int scoreO;
    int rowX;
    int columnX;
    int rowO;
    int columnO;


/*
// run a loop:
    for (int i = 0; i < 50; ++i)
     
     {
    // Display the content of the board
        drawBoard(board);
        printf("Player 1's turn:\n");
    // Ask player one to chose a location (row, column)
        printf("What row do you want to go:?\n");
        fgets(tempBuffer, BUFFER_SIZE, stdin);
        row = tempBuffer[0] - '0';//atoi(tempBuffer);
        
        printf("What column do you want to go:?\n");
        fgets(tempBuffer, BUFFER_SIZE, stdin);
        column = tempBuffer[0] - '0';//atoi(tempBuffer);

    // check if move is valid

                    //check if location has astericks and its between 0 thru 2
                    bool valid = false;
                    while (!valid) 
                    {
                        //check if the move is within range.

                        if (inBounds(row, column)  
                            && isEmpty(board, row, column)
                            && XfullAdjacency(valid, board, row, column, rowO, columnO))
                        {
                                             
                           valid = true;
                           board[row-1][column-1] = 'X';
                           rowX = row;
                           columnX = column;

                        }else if (inBounds(row, column)  
                            && isEmpty(board, row, column)
                            && XfullAdjacency(valid, board, row, column, rowO, columnO))
                        {
                        
                           valid = true;
                           board[row-1][column-1] = 'X';
                           rowX = row;
                           columnX = column;

                        }else{

                           printf("What row do you want to go:?\n");
                           fgets(tempBuffer, BUFFER_SIZE, stdin);
                           row = atoi(tempBuffer);
                                                
                           printf("What column do you want to go:?\n");
                           fgets(tempBuffer, BUFFER_SIZE, stdin);
                           column = atoi(tempBuffer);
                           
                        }

                        
                    }
        
        drawBoard(board);
    // Check if someone won or  if there is a tie
        //check_WinnerX(board);
    // Ask player two to chose a location (row, column)
    printf("Player 2's turn:\n");

                printf("What row do you want to go:?\n");
                fgets(tempBuffer, BUFFER_SIZE, stdin);
                row = atoi(tempBuffer);
                
                printf("What column do you want to go:?\n");
                fgets(tempBuffer, BUFFER_SIZE, stdin);
                column = atoi(tempBuffer);
                
                // check if move is valid

                    valid = false;
                    while (!valid) 
                    {
                        //check if the move is within range.

                        if (inBounds(row, column)  
                            && isEmpty(board, row, column)
                            && OfullAdjacency(valid, board, row, column, rowX, columnX))
                        {
                                     
                           valid = true;
                           board[row-1][column-1] = 'O';
                           rowO = row;
                           columnO = column;

                        }else if (inBounds(row, column)  
                            && isEmpty(board, row, column)
                            && OfullAdjacency(valid, board, row, column, rowX, columnX))
                        {
                        
                           valid = true;
                           board[row-1][column-1] = 'O';
                           rowO = row;
                           columnO = column;

                        }else{

                           printf("What row do you want to go:?\n");
                           fgets(tempBuffer, BUFFER_SIZE, stdin);
                           row = atoi(tempBuffer);
                                                
                           printf("What column do you want to go:?\n");
                           fgets(tempBuffer, BUFFER_SIZE, stdin);
                           column = atoi(tempBuffer);
                           
                        }


                    }


                }
                */
        drawBoard(board);
    // Check if someone won or  if there is a tie
        //check_WinnerO(board);
    
    //X is black
    //O is white

    scoreX = check_WinnerX(board);
    printf("X: %d\n", scoreX);
    scoreO = check_WinnerO(board);
    printf("O: %d\n",scoreO);

    if (scoreX > scoreO)
    {
        printf("X is the winner:\n%d > %d\n", scoreX, scoreO);
    }else if (scoreX < scoreO)
    {
        printf("O is the winner:\n%d < %d\n", scoreX, scoreO);
    }else if (scoreX == scoreO)
    {
        printf("It is a TIE:\n%d = %d\n", scoreX, scoreO);
    }

    return 0;
}




bool inBounds(int row, int column){

    if(!(row <= 10 && row >= 1 && column <= 10 && column >= 1)){
       printf("Error: Either the row or column is not within range of the board.\n");
       // ask again (error: row in column not within range)

       return false;
       }else{
        return true;
       }
}


bool adjacencyCheckX(int row, int column, int rowO, int columnO){

    if((row != rowO - 2 && column != columnO - 2) 
      || (row != rowO - 1 && column != columnO - 2)           //last check 
      || (row != rowO && column != columnO - 2) 
      || (row != rowO - 2 && column != columnO - 1) 
      || (row != rowO && column != columnO - 1) 
      || (row != rowO - 2 && column != columnO) 
      || (row != rowO - 1 && column != columnO) 
      || (row != rowO && column != columnO))
      {

       printf("Error: You must place you X ajacent to the privious O i.e. (%d,%d).\n", rowO, columnO);
       return true;
       }else{
        return false;
       }
                        

}



bool adjacencyCheckO(int row, int column, int rowX, int columnX){

    printf("%d %d\t\t%d %d\n", row, column, rowX, columnX);

            printf("%d\t", (row == rowX - 2 && column == columnX - 2));
        printf("%d\t", (row == rowX - 1 && column == columnX - 2));
        printf("%d\t", (row == rowX && column == columnX - 2));
        printf("%d\t", (row == rowX - 2 && column == columnX - 1));
        printf("%d\t", (row == rowX && column == columnX - 1));
        printf("%d\t", (row == rowX - 2 && column == columnX));
        printf("%d\t", (row == rowX - 1 && column == columnX));
        printf("%d\t", (row == rowX && column == columnX));
    if((row == rowX - 2 && column == columnX - 2) 
      || (row == rowX - 1 && column == columnX - 2) 
      || (row == rowX && column == columnX - 2) 
      || (row == rowX - 2 && column == columnX - 1) 
      || (row == rowX && column == columnX - 1) 
      || (row == rowX - 2 && column == columnX) 
      || (row == rowX - 1 && column == columnX) 
      || (row == rowX && column == columnX))
      {




       return true;
       }else{
        printf("Error: You must place you O ajacent to the privious X i.e. (%d,%d).\n", rowX, columnX);
       return false;
       }

}



bool isEmpty(char board[10][10], int row, int column){

    if(board[row-1][column-1] != ' ')
        {
        printf("Error: The (%d,%d) is already occupied with a %c.\n", row, column, board[row-1][column-1]);
        return false;
        }else{
         return true;
        }

}


void Xplacment(bool valid, char board[10][10], int row, int column, int rowX, int columnX){

    valid = true;
    board[row-1][column-1] = 'X';
    rowX = row;
    columnX = column;
}


void Oplacment(bool valid, char board[10][10], int row, int column, int rowO, int columnO){

    valid = true;
    board[row-1][column-1] = 'O';
    rowO = row;
    columnO = column;

}


bool XfullAdjacency(bool valid, char board[10][10], int row, int column, int rowO, int columnO){

        if(board[rowO-2][columnO-2] != ' ' 
            && board[rowO-1][columnO-2] != ' ' 
            && board[rowO][columnO-2] != ' ' 
            && board[rowO-2][columnO-1] != ' ' 
            && board[rowO][columnO-1] != ' ' 
            && board[rowO-2][columnO] != ' ' 
            && board[rowO-1][columnO] != ' ' 
            && board[rowO][columnO] != ' ')
        {

                            //chekc without adjacency
            /*
            valid = false;
            while (!valid) 
            {
                if(inBounds(board, row, column)  
                    && isEmpty(board, row, column))
                {
                    return true;
                    valid = true;
                }

            }
            */
            return false;

        }else{
            return true;
        }

}



bool OfullAdjacency(bool valid, char board[10][10], int row, int column, int rowX, int columnX){

    if(board[rowX-2][columnX-2] != ' ' 
        && board[rowX-1][columnX-2] != ' ' 
        && board[rowX][columnX-2] != ' ' 
        && board[rowX-2][columnX-1] != ' ' 
        && board[rowX][columnX-1] != ' ' 
        && board[rowX-2][columnX] != ' ' 
        && board[rowX-1][columnX] != ' ' 
        && board[rowX][columnX] != ' ')
    {

    return false;

    }else{
    return true;
    }

}





//      X and O win checkerSSSSSSSSS
int check_WinnerX(char board[10][10]){
    int score = 0;
    char winner = 'T';

        //horizontal
        for (int y = 0; y < 10; y++) {
    // going to length-3 to avoid IndexOutOfBounds exception
            for (int x = 0; x < 10 - 3; x++) {
                if (board[y][x] == 'X' && board[y][x + 1] == 'X' && board[y][x + 2] == 'X' && board[y][x + 3] == 'X') 
                {
                    score = score + 1;
                }
            }
        }
        
        //vertical
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 0; x < 10; x++) {
                if (board[y][x] == 'X' && board[y + 1][x] == 'X' && board[y + 2][x] == 'X' && board[y + 3][x] == 'X')
                 {
                    score = score + 1;
                }
            }
        }

        //diagonal to left
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 0; x < 10 - 3; x++) {
                if (board[y][x] == 'X' && board[y + 1][x + 1] == 'X' && board[y + 2][x + 2] == 'X' && board[y + 3][x + 3] == 'X') 
                {
                    score = score + 1;
                }
            }
        }

        //diagonal to right
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 3; x < 10; x++) {
                if (board[y][x] == 'X' && board[y + 1][x - 1] == 'X' && board[y + 2][x - 2] == 'X' && board[y + 3][x - 3] == 'X') 
                {
                    score = score + 1;
                }
            }
    }
    return score;
}






int check_WinnerO(char board[10][10]){
    int score = 0;
    char winner = 'T';

        //horizontal
        for (int y = 0; y < 10; y++) {
    // going to length-3 to avoid IndexOutOfBounds exception
            for (int x = 0; x < 10 - 3; x++) {
                if (board[y][x] == 'O' && board[y][x + 1] == 'O' && board[y][x + 2] == 'O' && board[y][x + 3] == 'O') 
                {
                    score = score + 1;
                }
            }
        }
        
        //vertical
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 0; x < 10; x++) {
                if (board[y][x] == 'O' && board[y + 1][x] == 'O' && board[y + 2][x] == 'O' && board[y + 3][x] == 'O')
                 {
                    score = score + 1;
                }
            }
        }

        //diagonal to left
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 0; x < 10 - 3; x++) {
                if (board[y][x] == 'O' && board[y + 1][x + 1] == 'O' && board[y + 2][x + 2] == 'O' && board[y + 3][x + 3] == 'O') 
                {
                    score = score + 1;
                }
            }
        }

        //diagonal to right
        for (int y = 0; y < 10 - 3; y++) {
            for (int x = 3; x < 10; x++) {
                if (board[y][x] == 'O' && board[y + 1][x - 1] == 'O' && board[y + 2][x - 2] == 'O' && board[y + 3][x - 3] == 'O') 
                {
                    score = score + 1;
                }
            }
    }
    return score;
}






void drawBoard(char board[10][10])
{

    printf("     1   2   3   4   5   6   7   8   9   10\n");
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 1 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5],board[0][6], board[0][7], board[0][8], board[0][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 2 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5],board[1][6], board[1][7], board[1][8], board[1][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 3 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5],board[2][6], board[2][7], board[2][8], board[2][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 4 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5],board[3][6], board[3][7], board[3][8], board[3][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 5 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5],board[4][6], board[4][7], board[4][8], board[4][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 6 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5],board[5][6], board[5][7], board[5][8], board[5][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 7 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5],board[6][6], board[6][7], board[6][8], board[6][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 8 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5],board[7][6], board[7][7], board[7][8], board[7][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf(" 9 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5],board[8][6], board[8][7], board[8][8], board[8][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");

    printf("10 | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | \n", board[9][0], board[9][1], board[9][2], board[9][3], board[9][4], board[9][5],board[9][6], board[9][7], board[9][8], board[9][9]);
    printf("   +---+---+---+---+---+---+---+---+---+---+\n");
}
