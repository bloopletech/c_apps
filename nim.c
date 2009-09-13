#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rrange(int, int);
int min(int, int);

int main()
{
   srand(time(NULL));
   int pile = rrange(10, 100);
   int turn = rrange(0, 1);
   int allowedToTake = rrange(1, pile / 3);
   int firstTurn = 1;

   printf("Welcome to the game of Nim (version A).\n");
   printf("In this game, two players alternatley take marbles from a pile.\n");
   printf("In each move, a player chooses how many marbles to take.\n");
   printf("The player must take at least one and at most %i marbles.\n", allowedToTake);
   printf("Then the other player takes a turn.\n");
   printf("The player who takes the last marble wins.\n");
   printf("====================================================\n");

   printf("There are %i marbles on the pile.\n", pile);

   do
   {
      if(turn == 0) turn = 1;
      else turn = 0;

      if(turn == 0)
      {
         if(firstTurn == 1) printf("You have the first turn.\n");
         else printf("It is your turn.\n");

         do
         {
            printf("Please enter how many marbles you would like to remove from the pile: ");
   
            int howMany = 0;
            if(scanf("%i", &howMany) != EOF)
            {
               if(pile == 1)
               {
                  if(howMany == 1)
                  {
                     pile = 0;
                     printf("There are now %i marbles on the pile.\n", pile);
                     break;
                  }
                  else
                  {
                     printf("Please enter a valid number.\n");
                     printf("You must take at least one but at most %i marbles.\n", min(allowedToTake, pile));
                  }
               }
               else if((howMany >= 1) && (howMany <= min(allowedToTake, pile)))
               {
                  pile -= howMany;
                  printf("There are now %i marbles on the pile.\n", pile);
                  break;
               }
               else
               {
                  printf("Please enter a valid number.\n");
                  printf("You must take at least one but at most %i marbles.\n", min(allowedToTake, pile));
               }
            }
            else
            {
               printf("Please enter a number.\n");
            }
         }
         while(1);
      }
      else
      {
         if(firstTurn == 1) printf("The computer has the first turn.\n");
         else printf("It is the computers turn.\n");
   
         int temp = rrange(1, allowedToTake);
         while(temp > pile)
         {
            temp = rrange(1, allowedToTake);
         }

         pile = pile - temp;

         printf("There are now %i marbles on the pile.\n", pile);
      }

      firstTurn = 0;
   }
   while(pile != 0);

   if(turn == 0)
   {
      printf("The computer has won.\n");
   }
   else
   {
      printf("You have won.\n");
   }
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
