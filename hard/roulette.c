#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bet.h"

#define BETS_SIZE 100

float doBets(bet**, int, int, float);
int dobet(bet**, int, int, float);
int random(int, int);

int main()
{
   srand(time(NULL));

   bet* bets[BETS_SIZE];
   int betcount = 0;
   int hit = 0;
   float money = 350.0;


   printf("Welcome to the Casa de la Muerto Casino!\n");
   printf("Right now, we're playing 3 Dice Roulette.\n");
   printf("To learn how to play, go to http://en.wikipedia.org/wiki/Roulette\n");
   printf("====================================================\n");

   printf("You start with $%.2f.\n", money);

   do
   {
      int select = 0;
      int stop = 0;
      do
      {
         fflush(stdout);
         fflush(stdin);

         printf("====================================================\n");
         printf("You can:\n");
         printf("1. Place a bet on a single number.\n");
         printf("2. Place a bet on row 3, 6, 9, ...\n");
         printf("3. Place a bet on column 1, 2, or 3.\n");
         printf("4. Place a bet on the first, middle, or last 12.\n");
         printf("5. Place a bet on odd.\n");
         printf("6. Place a bet on even.\n");
         printf("7. Place a bet on red.\n");
         printf("8. Place a bet on black.\n");
         printf("9. Place a bet on 1 to 18.\n");
         printf("10. Place a bet on 19 to 36.\n");
         printf("11. Place a 4 number bet.\n");
         printf("12. Spin the wheel.\n");
         printf("13. Walk away from the table.\n");

         printf("Please select what you would like to do (enter a number from 1 - 13): ");

         int temp = scanf("%i", &select);
         if(temp == EOF)
         {
            printf("Please enter a number.\n");
         }
         else if(select < 1 || select > 13)
         {
            printf("Please enter a valid number between one and thirteen.\n");
         }
         else
         {
            printf("\n\n");
            switch(select)
            {
               case 1: betcount = dobet(bets, betcount, BET_SINGLE, money); break;
               case 2: betcount = dobet(bets, betcount, BET_ROWS, money); break;
               case 3: betocunt = dobet(bets, betcount, BET_COLUMNS, money); break;
               case 4: betcount = dobet(bets, betcount, BET_12S, money); break;
               case 5: betcount = dobet(bets, betcount, BET_ODD, money); break;
               case 6: betcount = dobet(bets, betcount, BET_EVEN, money); break;
               case 7: betcount = dobet(bets, betcount, BET_RED, money); break;
               case 8: betcount = dobet(bets, betcount, BET_BLACK, money); break;
               case 9: betcount = dobet(bets, betcount, BET_1TO9, money); break;
               case 10: betcount = dobet(bets, betcount, BET_10TO18, money); break;
               case 11: betcount = dobet(bets, betcount, BET_4NUM, money); break;
               case 12: printf("No more bets!\n"); stop = 1; break;
               case 13: printf("You leave with $%.2f.\n", money);
                        if(money > 500.0) printf("You won $%.2f.\n", money - 500);
                        else if(money < 500.0) printf("You lost $%.2f.\n", 500 - money);
                        else printf("You made no money on what you orginally had.\n");
                        return 0;
            }
            fflush(stdout);
            fflush(stdin);
         }
      }
      while(stop == 0);

      printf("\n\n");
      printf("Throwing the dice...\n");
      hit = random(0, 18);
      printf("The dice came up %i.\n", hit);

      money = doBets(bets, betcount, hit, money);

      betcount = 0;
   }
   while(1);
}


float doBets(bet** bets, int betcount, int hit, float money)
{
   for(int i = 0; i < betcount; i++)
   {
      bet* b = bets[i];
      if(didPayoff(b, hit) == 1)
      {
         float won = getPayoff(b, hit);
         money += won;
         printf("You won $%.2f!\n", won);
      }
      else
      {
         money -= b->amount;
         printf("You lost $%.2f!\n", b->amount);
      }
      

      printf("You now have $%.2f.\n", money);
   }
   fflush(stdout);
   fflush(stdin);

   return money;
}


int dobet(bet** bets, int betcount, int type, float money)
{
   bet* bet1 = (bet*)malloc(sizeof(bet));

   if(type == BET_SINGLE)
   {
      int whichOne = 0;
      do
      {
         fflush(stdout);
         fflush(stdin);

         printf("What number do you want to place your bet on (0 - 36)? ");

         int temp = scanf("%i", &whichOne);

         if(temp == EOF)
         {
            printf("Please enter a number.\n");
         }
         else if(temp < 0 || temp > 36)
         {
            printf("Please enter a valid number between zero and thirty-six.\n");
         }
         else
         {
            float amount = 0.0;
            do
            {
               fflush(stdout);
               fflush(stdin);

               printf("How much do you want to bet? ");
               
               int temp = scanf("%f", &amount);

               if(temp == EOF)
               {
                  printf("Please enter a number.\n");
               }
               else if(temp < 0.0)
               {
                  printf("You can't bet less than nothing!\n");
               }
               else if(temp > money)
               {
                  printf("You can't bet more money than you have!\n");
               }
               else
               {
                  bet1->type = whichOne;
                  bet1->amount = amount;
                  break;
               }
            }
            while(1);
            break;
         }
      }
      while(1);
   }
   else if(type == BET_ROWS)
   {
      int whichOne = 0;
      do
      {
         fflush(stdout);
         fflush(stdin);

         printf("Which row do you want to place your bet on (3, 6, 9, ..., 36)? ");

         int temp = scanf("%i", &whichOne);

         if(temp == EOF)
         {
            printf("Please enter a number.\n");
         }
         else if(whichOne != 3 && whichOne != 6 && whichOne != 9 && whichOne != 12
          && whichOne != 15 && whichOne != 18 && whichOne != 21 && whichOne != 24
           && whichOne != 27 && whichOne != 30 && whichOne != 33, && whichOne != 36)
         {
            printf("Please enter a valid number: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, or 36.\n");
         }
         else
         {
            float amount = 0.0;
            do
            {
               fflush(stdout);
               fflush(stdin);

               printf("How much do you want to bet? ");
               
               int temp = scanf("%f", &amount);

               if(temp == EOF)
               {
                  printf("Please enter a number.\n");
               }
               else if(temp < 0.0)
               {
                  printf("You can't bet less than nothing!\n");
               }
               else if(temp > money)
               {
                  printf("You can't bet more money than you have!\n");
               }
               else
               {
                  switch(whichOne)
                  {
                     case 3: bet1->type = BET_ROW3; break;
                     case 6: bet1->type = BET_ROW6; break;
                     case 9: bet1->type = BET_ROW9; break;
                     case 12: bet1->type = BET_ROW12; break;
                     case 15: bet1->type = BET_ROW15; break;
                     case 18: bet1->type = BET_ROW18; break;
                     case 21: bet1->type = BET_ROW21; break;
                     case 24: bet1->type = BET_ROW24; break;
                     case 27: bet1->type = BET_ROW27; break;
                     case 30: bet1->type = BET_ROW30; break;
                     case 33: bet1->type = BET_ROW33; break;
                     case 36: bet1->type = BET_ROW36; break;
                  }

                  bet1->amount = amount;
                  break;
               }
            }
            while(1);
            break;
         }
      }
      while(1);
   }
   else if(type == BET_COLUMN1 || type == BET_COLUMN2 || type == BET_COLUMN3)
   {
      
   else if(type == BET_ODD || type == BET_EVEN || type == BET_1TO18 || type == BET_19TO36)
   {
      int whichOne = 0;
      float amount = 0.0;
      do
      {
         fflush(stdout);
         fflush(stdin);

         printf("How much do you want to bet? ");
         
         int temp = scanf("%f", &amount);

         if(temp == EOF)
         {
            printf("Please enter a number.\n");
         }
         else if(temp < 0.0)
         {
            printf("You can't bet less than nothing!\n");
         }
         else if(temp > money)
         {
            printf("You can't bet more money than you have!\n");
         }
         else
         {
            bet1->type = type;
            bet1->amount = amount;
            break;
         }
      }
      while(1);    
   }

   
   if(betcount > BETS_SIZE)
   {
      printf("Sorry, too many bets made.\n");
      return -1;
   }

   fflush(stdout);
   fflush(stdin);

   bets[betcount++] = bet1;
   return betcount;
}


int random(int a, int b)
{
   int temp = rand();
   while(temp < a || temp > b)
   {
      temp = rand();
   }

   return temp;
}




int main()
{
   bet* bets[200];
   int betcount = 0;
   int hit = 0;
   float money = 500.0;


   printf("Welcome to the Casa de la Muerto Casino!\n");
   printf("Right now, we're playing Roulette.\n");
   printf("To learn how to play, go to http://en.wikipedia.org/wiki/Roulette\n");
   printf("====================================================\n");

   printf("You start with $.2f.\n", money);

   do
   {
      int select = 0;
      do
      {
         printf("You can:\n");
         printf("1. Place a bet on a single number.\n");
         printf("2. Place a bet on row 3, 6, 9, ...\n");
         printf("3. Place a bet on column 1, 2, or 3.\n");
         printf("4. Place a bet on the first, middle, or last 12.\n");
         printf("5. Place a bet on odd.\n");
         printf("6. Place a bet on even.\n");
         printf("7. Place a bet on red.\n");
         printf("8. Place a bet on black.\n");
         printf("9. Place a bet on 1 to 18.\n");
         printf("10. Place a bet on 19 to 36.\n");
         printf("11. Place a 4 number bet.\n");
         printf("12. Spin the wheel.\n");
         printf("13. Walk away from the table.\n");

         printf("Please select what you would like to do (enter a number from 1 - 13): ");

         scanf("%i", &select);
         if(scanf("%i", &select) == EOF)
         {
            printf("Please enter a number.\n");
         }
         else if(select < 1 || select > 13)
         {
            printf("Please enter a valid number between one and five.\n");
         }
         else
         {
            switch(select)
            {
               case 1: dobet(bets, BET_SINGLE); break;
               case 2: dobet(bets, BET_ROWS); break;
               case 3: dobet(bets, BET_COLUMNS); break;
               case 4: dobet(bets, BET_12S); break;
               case 5: dobet(bets, BET_ODD); break;
               case 6: dobet(bets, BET_EVEN); break;
               case 7: dobet(bets, BET_RED); break;
               case 8: dobet(bets, BET_BLACK); break;
               case 9: dobet(bets, BET_1TO18); break;
               case 10: dobet(bets, BET_19TO36); break;
               case 11: dobet(bets, BET_5NUM); break;
               case 12: printf("No more bets!\n"); stop = 1; break;
               case 13: printf("You leave with $%.2f.\n", money);
                        if(money > 500.0) printf("You won $%.2f.\n", money - 500);
                        else if(money < 500.0) printf("You lost $%.2f.\n", 500 - money);
                        else printf("You made no money on what you orginally had.\n");
                        return 0;
            }
         }
      }
      while(stop == 0);

      printf("Spinning the wheel...\n");
      hit = random(0, 36);

   
   
   
   
   
   
}


float doBets(bet* bets, int betcount, float money)
{
   for(int i = 0; i < betcount; i++)
   {
      bet* b = bets[i];
      if(didPayoff(b, hit) == 1)
      {
         money += getPayoff(b);
         printf("You won $%.2f!\n", getPayoff(b));
      }
      else
      {
         money -= b->amount;
         printf("You lost $%.2f!\n", b->amount;
      }
      

      printf("You now have $%.2f.\n", money);
   }

   return money;
}