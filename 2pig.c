#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "scoring.h"

int rrange(int, int);
int min(int, int);

void doPlayerTurn(player*);
void doComputerTurn(player*);

char getInput(char*);

int main()
{
   srand(time(NULL));
   player* player1 = makePlayer(HUMAN);
   //player* player2 = makePlayer(COMPUTER);
   player* player2 = makePlayer(HUMAN);
   int turn = rrange(0, 1);

   printf("Welcome to Two-Dice Pig!\n");
   printf("In this game, two players alternatley throw 2 standard dice.\n");
   printf("If neither dice show a 1, the sum of the dice are added to the player's total.\n");
   printf("If one of the dice shows a one, the player's turn ends.\n");
   printf("If two ones are thrown, the player loses their entire score, and that player's turn ends.\n");
   printf("The first player to reach 100 points wins.\n");

   do
   {
      if(turn == 0) turn = 1;
      else turn = 0;

      if(turn == 0)
      {
         printf("====================================================\n");
         //printf("It's your turn.\n");
         printf("It's player 1's turn.\n");
         printf("\n");
         doPlayerTurn(player1);
      }
      else
      {
         printf("====================================================\n");
         //printf("It's the computer's turn.\n");
         printf("It's player 2's turn.\n");
         printf("\n");
         //doComputerTurn(player2);
         doPlayerTurn(player2);
      }

      printf("\n");
      printf("====================================================\n");
      printf("Press any key to continue play to the next player: " );
      getchar();

      fflush(stdin);
      fflush(stdout);
   }
   while(player1->score < 100 && player2->score < 100);


   if(player1->score >= 100)
   {
      //printf("You won, with a grand total of %i points.\n", player1->score);
      printf("Player 1 won, with a grand total of %i points.\n", player1->score);
   }
   else
   {
      //printf("The computer won, with a grand total of %i points.\n", player2->score);
      printf("Player 2 won, with a grand total of %i points.\n", player2->score);
   }

   freePlayer(player1);
   freePlayer(player2);
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

int min(int a, int b)
{
   return (a < b ? a : b);
}


void doPlayerTurn(player* player1)
{
   char input = '0';
   int turnT = 0;

   do
   {
      input = getInput("Do you want to throw the dice, or pass to the next player (t or p)? ");
      printf("\n");

      if(input == 'p')
      {
         break;
      }

      printf("Throwing Dice...\n");

      int d1 = rrange(1, 6);
      int d2 = rrange(1, 6);

      printf("Rolled a %i and a %i.\n", d1, d2);

      if(d1 == 1 && d2 == 1)
      {
         printf("You lose this turn, and you lose all your points.\n");
         printf("\n");

         turnT = 0;

         player1->score = 0;
         break;
      }
      else if(d1 == 1 || d2 == 1)
      {
         printf("You lose this turn, and the points you've gained this turn have been lost.\n");
         printf("\n");

         turnT = 0;

         break;
      }
      else
      {
         printf("%i has been added to your score for this turn.\n", d1 + d2);
         turnT += d1 + d2;
      }

      printf("\n");
   }
   while(1);

   player1->score = player1->score + turnT;
   printf("You gained %i points on this turn. You now have %i points total.\n", turnT, player1->score);

   fflush(stdin);
   fflush(stdout);
}


void doComputerTurn(player* player2)
{
   if(rrange(0, 5) == 1)
   {
      player2->score = player2->score - rrange(5, 15);
   }
   else
   {
      player2->score = player2->score + rrange(5, 15);
   }

   printf("The computer got %i.\n", player2->score);

   fflush(stdin);
   fflush(stdout);
}


char getInput(char* input)
{
   do
   {
      fflush(stdin);
      fflush(stdout);

      printf(input);

      int temp = 0;
      int err = scanf("%c", &temp);

      if(err == EOF)
      {
         printf("Please enter valid input.\n");
      }
      else
      {
         return temp;
      }
   }
   while(1);
}

