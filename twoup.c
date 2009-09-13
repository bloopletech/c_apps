#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bet
{
   int type = 0;
   float amount = 0.0;
   int turnsAgo = 0;
} bet;

int rrange(int, int);
bet* getbet(int, int)

int main()
{
   srand(time(NULL));
   int money = 10;
   int firstTurn = 1;

   printf("Welcome to two-up!\n");
   printf("====================================================\n");

   printf("You start out with $10.\n");

   do
   {
      int stop = 0;
      do
      {
         printf("You can:\n");
         printf("1: bet that the next throw will be both heads.\n");
         printf("2: bet that the next throw will be both tails.\n");
         printf("3: bet that the next 5 throws will be all hads, tails.\n");
         printf("4: walk away.\n");
         printf("5: do the toss.\n");
         int select = 0;
         do
         {
            printf("Please select what you would like to do (enter a number from 1 - 5): ");

            scanf("%i", &select);
            if(scanf("%i", &select) == EOF)
            {
               printf("Please enter a number.\n");
            }
            else if(select < 1 || select > 5)
            {
               printf("Please enter a valid number between one and five.\n");
            }
            else
            {
               switch(select)
               {
                  case 1: bets[l] = getbet(BET_BOTHHEADS); break;
                  case 2: bets[l] = getbet(BET_BOTHTAILS); break;
                  case 3: bets[l] = getbet(BET_NEXT5HT); break;
                  case 4: printf("You leave with $%.2f.\n", money); return 0;
                  case 5: stop = 1;
               }
            }
         }
         while(stop == 0);

         printf("Tossing...\n");
         printf("Two-up! ");
         int penny1 = rrange(0, 1);
         int penny2 = rrange(0, 1);
         printf("The result was %s, %s.\n", (penny1 == HEADS ? "heads" : "tails"), (penny2 == HEADS ? "heads" : "tails"));
         if(penny1 == HEADS && penny2 == HEADS)
         {
            for(int i = 0; i < l; i++)
            {
               if(bets[l]->type == BET_BOTHHEADS)
               {
            {
               money = money + bets[l]->amount;
               printf("You won $%.2f!", bets[l]->amount);
               printf(" You now have $%.2f.\n", money);
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

bet* getbet(int type, int money)
{
   bet* temp = (bet)malloc(sizeof(bet);
   temp->type = type;

   int bett = 0;
   do
   {
      printf("How much do you want to bet? ");

      scanf("%f", &bett);
      if(scanf("%i", &bett) == EOF)
      {
         printf("Please enter a number.\n");
      }
      else if(bett < 0.01)
      {
         printf("You can't bet less than $0.01!\n");
      }
      else if(bett > money)
      {
         printf("You can't bet more money than you have.\n");
      }
      else
      {
         temp->amount = bett;
         break;
      }
   }
   while(1);

   return temp;
}