#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ORDER 3

int rrange(int, int);

int main()
{
   srand(time(NULL));
   int addTo = rrange(10, 200);
   int square[ORDER][ORDER];
   
   for(int i = 0; i < ORDER; i++)
   {
      for(int j = 0; j < ORDER; j++)
      {
         square[i][j] = 0;
      }
   }

   int solved = 1;

   printf("Welcome to the magic square game.the game of Nim.\n");
   printf("You must fill the following grid of numbers, so that\n");
   printf("each row, column and diagonal adds up to %i.\n", addTo);
   printf("To enter a number in the grid, type the column, followed\n");
   printf("by a comma, followed by the row, then another comma, then the\n");
   printf("number to put into that square. For example: \n");
   printf("2,3,14 would put the number 14 into the square in the second\n");
   printf("column, third row.\n");
   printf("====================================================\n");

   do
   {
      printf("Column number:   1  2  3\n");
      printf("              +---+---+---+\n");
      printf("Row 1         |%3i|%3i|%3i|\n", square[0][0], square[1][0], square[2][0]);
      printf("              +---+---+---+\n");
      printf("Row 2         |%3i|%3i|%3i|\n", square[0][1], square[1][1], square[2][1]);
      printf("              +---+---+---+\n");
      printf("Row 3         |%3i|%3i|%3i|\n", square[0][2], square[1][2], square[2][2]);
      printf("              +---+---+---+\n");

      if(solved == 0)
      {
         printf("You solved the magic square!\n");
         return 0;
      }

      printf("Please enter a column, row and number to put into the square (or type -1,-1,-1 to quit): ");

      int row = 0, column = 0, num = 0;
      int temp = scanf("%i,%i,%i", &column, &row, &num);

      if(temp == EOF)
      {
         printf("Please enter a valid input, according to the instructions\n");
         printf("defined at the beginning of this game.\n");
      }
      else if(row == -1 && column == -1 && num == -1)
      {
         return 0;
      }
      else if(column < 0 || column > ORDER)
      {
         printf("Please enter a column number between 0 and 3.\n");
      }
      else if(row < 0 || row > ORDER)
      {
         printf("Please enter a row number between 0 and 3.\n");
      }
      else if(num < 0 || num > addTo)
      {
         printf("Please enter a number at least 0, and not more than %i.\n", addTo);
      }
      else
      {
         square[column - 1][row - 1] = num;

         if((square[0][0] + square[1][0] + square[2][0]) != addTo) solved = 0;
         if((square[0][1] + square[1][1] + square[2][1]) != addTo) solved = 0;
         if((square[0][2] + square[1][2] + square[2][2]) != addTo) solved = 0;
         if((square[0][0] + square[0][1] + square[0][2]) != addTo) solved = 0;
         if((square[1][0] + square[1][1] + square[1][2]) != addTo) solved = 0;
         if((square[2][0] + square[2][1] + square[2][2]) != addTo) solved = 0;
         if((square[0][0] + square[1][1] + square[2][2]) != addTo) solved = 0;
         if((square[0][2] + square[1][1] + square[2][0]) != addTo) solved = 0;
      }
   }
   while(1);
}

int rrange(int a, int b)
{
   int temp = rand();
   while(temp < a || temp > b)
   {
      temp = rand();
   }

   return temp;
}
