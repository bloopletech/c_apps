#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rrange(int, int);

int main()
{
   srand(time(NULL));
   int pile = rrange(10, 100);
   int turn = rrange(0, 1);
   int firstTurn = 1;

   printf("Welcome to the game of Nim (version B).\n");
   printf("In this game, two players alternatley take marbles from a pile.\n");
   printf("In each move, a player chooses how many marbles to take.\n");
   printf("The player must take at least one but at most half of the marbles.\n");
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
                     printf("You must take at least one but at most half of the marbles.\n");
                  }
               }
               else if((howMany >= 1) && (howMany <= (pile / 2)))
               {
                  pile -= howMany;
                  printf("There are now %i marbles on the pile.\n", pile);
                  break;
               }
               else
               {
                  printf("Please enter a valid number.\n");
                  printf("You must take at least one but at most half of the marbles.\n");
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
   
         if(pile == 63 || pile == 31 || pile == 15 || pile == 7 || pile == 3) pile = pile - rrange(1, pile / 2);
         else if(pile > 63) pile = 63;
         else if(pile > 31) pile = 31;
         else if(pile > 15) pile = 15;
         else if(pile > 7) pile = 7;
         else if(pile > 3) pile = 3;
         else if(pile == 2) pile = 1;
         else if(pile == 1) pile = 0;

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
