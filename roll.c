#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rrange(int, int);

int main(int argc, char** argv)
{
   srand(time(NULL));

   if(argc <= 1 || argc > 3)
   {
      printf("Roll rolls a specified numer of dice, and tells you the result.\n");
      printf("To use roll, type the command roll, followed by a string in this format:\n");
      printf("[<number of dice to roll>]d<maximum value of die>\n");
      printf("[<+, -, * or /><number to add, subtract, multiply or divide from value>]\n");
      printf("[<'<' or '>'><the current throw will succeed it the throw is 'larger than or\n");
      printf(" equal to', or 'less than or equal to', this number>]\n");
      printf("You may need to surround your command with inverted commas.\n");

      printf("\n");

      printf("Examples:\n");
      printf("roll \"2d6\"    This rolls 2 six-sided dice.\n");
      printf("roll \"d12+4\"  This rolls a twelve-sided die, and adds 4 to the result.\n");
      printf("roll \"3d12>7\" This rolls 3 12-sided dice, and for each throw, tells you that");
      printf(" throw succeeded if the result was larger or equal to 7.\n");
      printf("roll \"7d24*2>40\"    This rolls 7 24-sided dice, and multiplieseach result by");
      printf(" 2. Then roll tells you whether each result was larger than 40 or not.\n");

      printf("\n");
      printf("If you put a \"-n\" on the end of the command, then roll will make sure that");
      printf("you won't miss any of the dice rolls.\n");
      return 0;
   }

   int howMany = 0;
   int diceValue = 0;
   int whichSign = 0;
   int changeAmount = 0;
   char switchBy = 0;
   int throwSuccess = 0;
   float temp = 0;

   if(argv[1][0] == 'd')
   {
      howMany = 1;
      int tempCount = sscanf(argv[1], "d%i%c%i%c%i", &diceValue, &whichSign, &changeAmount, &switchBy, &throwSuccess);

      if(tempCount == EOF || tempCount == 0 || tempCount == 2 || tempCount ==  4 || tempCount > 5)
      {
         printf("Roll rolls a specified numer of dice, and tells you the result.\n");
         printf("To use roll, type the command roll, followed by a string in this format:\n");
         printf("[<number of dice to roll>]d<maximum value of die>\n");
         printf("[<+, -, * or /><number to add, subtract, multiply or divide from value>]\n");
         printf("[<'<' or '>'><the current throw will succeed it the throw is 'larger than or\n");
         printf(" equal to', or 'less than or equal to', this number>]\n");
         printf("You may need to surround your command with inverted commas.\n");

         printf("\n");

         printf("Examples:\n");
         printf("roll \"2d6\"    This rolls 2 six-sided dice.\n");
         printf("roll \"d12+4\"  This rolls a twelve-sided die, and adds 4 to the result.\n");
         printf("roll \"3d12>7\" This rolls 3 12-sided dice, and for each throw, tells you that");
         printf(" throw succeeded if the result was larger or equal to 7.\n");
         printf("roll \"7d24*2>40\"    This rolls 7 24-sided dice, and multiplieseach result by");
         printf(" 2. Then roll tells you whether each result was larger than 40 or not.\n");

         printf("\n");
         printf("If you put a \"-n\" on the end of the command, then roll will make sure that");
         printf("you won't miss any of the dice rolls.\n");
         return 0;
      }
      else if(tempCount == 1)
      {
         printf("Die rolled a %i.\n", rrange(1, diceValue));
      }
      else if(tempCount == 3)
      {
         temp = rrange(1, diceValue);
         switch(whichSign)
         {
            case '+': printf("Die rolled a %.0f+%i = %.0f.\n", temp, changeAmount, temp + changeAmount);
             temp += changeAmount; break;
            case '-': printf("Die rolled a %.0f-%i = %.0f.\n", temp, changeAmount, temp - changeAmount);
             temp -= changeAmount; break;
            case '*': printf("Die rolled a %.0f*%i = %.0f.\n", temp, changeAmount, temp * changeAmount);
             temp *= changeAmount; break;
            case '/': printf("Die rolled a %.0f/%i = %.2f.\n", temp, changeAmount, temp / (float)changeAmount);
             temp /= changeAmount; break;
            case '>': printf("Die rolled a %.0f: throw %s.\n",
             temp, (temp >= changeAmount) ? "succeeded" : "failed"); break;
            case '<': printf("Die rolled a %.0f: throw %s.\n",
             temp, (temp <= changeAmount) ? "succeeded" : "failed"); break;
         }
      }
      else if(tempCount == 5)
      {
         temp = rrange(1, diceValue);
         switch(whichSign)
         {
            case '+': printf("Die rolled a %.0f+%i = %.0f:", temp, changeAmount, temp + changeAmount);
             temp += changeAmount; break;
            case '-': printf("Die rolled a %.0f-%i = %.0f:", temp, changeAmount, temp - changeAmount);
             temp -= changeAmount; break;
            case '*': printf("Die rolled a %.0f*%i = %.0f:", temp, changeAmount, temp * changeAmount);
             temp *= changeAmount; break;
            case '/': printf("Die rolled a %.0f/%i = %.02:", temp, changeAmount, temp / (float)changeAmount);
             temp /= changeAmount; break;
         }
         switch(switchBy)
         {
            case '>': printf(" throw %s.\n", (temp >= throwSuccess) ? "succeeded" : "failed"); break;
            case '<': printf(" throw %s.\n", (temp <= throwSuccess) ? "succeeded" : "failed"); break;
         }
      }
   }
   else
   {
      int tempCount = sscanf(argv[1], "%id%i%c%i%c%i", &howMany, &diceValue, &whichSign, &changeAmount, &switchBy, &throwSuccess);

      if(tempCount == EOF || tempCount <= 1 || tempCount == 3 || tempCount ==  5 || tempCount > 6)
      {
         printf("Roll rolls a specified numer of dice, and tells you the result.\n");
         printf("To use roll, type the command roll, followed by a string in this format:\n");
         printf("[<number of dice to roll>]d<maximum value of die>\n");
         printf("[<+, -, * or /><number to add, subtract, multiply or divide from value>]\n");
         printf("[<'<' or '>'><the current throw will succeed it the throw is 'larger than or\n");
         printf(" equal to', or 'less than or equal to', this number>]\n");
         printf("You may need to surround your command with inverted commas.\n");

         printf("\n");

         printf("Examples:\n");
         printf("roll \"2d6\"    This rolls 2 six-sided dice.\n");
         printf("roll \"d12+4\"  This rolls a twelve-sided die, and adds 4 to the result.\n");
         printf("roll \"3d12>7\" This rolls 3 12-sided dice, and for each throw, tells you that");
         printf(" throw succeeded if the result was larger or equal to 7.\n");
         printf("roll \"7d24*2>40\"    This rolls 7 24-sided dice, and multiplies each result by");
         printf(" 2. Then roll tells you whether each result was larger than 40 or not.\n");

         printf("\n");
         printf("If you put a \"-n\" on the end of the command, then roll will make sure that");
         printf("you won't miss any of the dice rolls.\n");
         return 0;
      }
      else if(tempCount == 2)
      {
         for(int i = 0; i < howMany; i++)
         {
            printf("Die %i rolled a %i.\n", (i + 1), rrange(1, diceValue));
         }
      }
      else if(tempCount == 4)
      {
         for(int i = 0; i < howMany; i++)
         {
            temp = rrange(1, diceValue);
            switch(whichSign)
            {
               case '+': printf("Die rolled a %.0f+%i = %.0f.\n", temp, changeAmount, temp + changeAmount);
                temp += changeAmount; break;
               case '-': printf("Die rolled a %.0f-%i = %.0f.\n", temp, changeAmount, temp - changeAmount);
                temp -= changeAmount; break;
               case '*': printf("Die rolled a %.0f*%i = %.0f.\n", temp, changeAmount, temp * changeAmount);
                temp *= changeAmount; break;
               case '/': printf("Die rolled a %.0f/%i = %.02.\n", temp, changeAmount, temp / (float)changeAmount);
                temp /= changeAmount; break;
               case '>': printf("Die rolled a %.0f: throw %s.\n",
                temp, (temp >= changeAmount) ? "succeeded" : "failed"); break;
               case '<': printf("Die rolled a %.0f: throw %s.\n",
                temp, (temp <= changeAmount) ? "succeeded" : "failed"); break;
            }
         }
      }
      else if(tempCount == 6)
      {
         for(int i = 0; i < howMany; i++)
         {
            temp = rrange(1, diceValue);
            switch(whichSign)
            {
               case '+': printf("Die rolled a %.0f+%i = %.0f:", temp, changeAmount, temp + changeAmount);
                temp += changeAmount; break;
               case '-': printf("Die rolled a %.0f-%i = %.0f:", temp, changeAmount, temp - changeAmount);
                temp -= changeAmount; break;
               case '*': printf("Die rolled a %.0f*%i = %.0f:", temp, changeAmount, temp * changeAmount);
                temp *= changeAmount; break;
               case '/': printf("Die rolled a %.0f/%i = %.02:", temp, changeAmount, temp / (float)changeAmount);
                temp /= changeAmount; break;
            }
            switch(switchBy)
            {
               case '>': printf(" throw %s.\n", (temp >= throwSuccess) ? "succeeded" : "failed"); break;
               case '<': printf(" throw %s.\n", (temp <= throwSuccess) ? "succeeded" : "failed"); break;
            }
         }
      }
   }

   if(argc > 2)
   {
      if(strlen(argv[2]) == 2 && argv[2][0] == '-' && argv[2][1] == 'n')
      {
         printf("Press any key to quit... ");
         getchar();
         return 0;
      }
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
