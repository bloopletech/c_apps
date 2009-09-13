#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rrange(int, int);
char convert(int);

int main()
{
   srand(time(NULL));
   int num1 = 0, num2 = 0, num3 = 0;
   int triple = 0;
   float money = 20.0;

   printf("Welcome to Jackpot! slot machine.\n");
   printf("If you get 2 of the same numbers/symbols next to eachother, you win $0.10.\n");
   printf("If you get 3 numbers/symbols the same, you get $2.\n");
   printf("If you get 3 numbers/symbols the same three times in a row, you win $20.!\n");
   printf("Each spin costs $0.10.\n");
   printf("====================================================\n");

   printf("You have $%.2f.\n", money);

   do
   {
      fflush(stdin);
      fflush(stdout);
      printf("Press q to quit, or anything else to spin: ");

      char what = 0;
      if(scanf("%c", &what) != EOF)
      {
         if(what == 'q')
         {
            printf("You leave with $%.2f.\n", money);
            return 0;
         }

         printf("\n\n");
         printf("Spinning... (press any key to stop)\n");

         money -= 0.1;

         int i = 0;
         while(i < 1)
         {
            num1 = rrange(0, 14);
            num2 = rrange(0, 14);
            num3 = rrange(0, 14);

            puts("");
            putchar(convert(num1));
            putchar(convert(num2));
            putchar(convert(num3));
            puts("");

            i++;
         }

         if((num1 == num2) && (num2 == num3))
         {
            if(triple == 3)
            {
               money += 20.0;
               printf("YOU WON $20!\n");

               triple = 0;
            }
            else
            {
               money += 5.0;
               printf("YOU WON $5!\n");

               triple++;
            }
         }
         else if((num1 == num2) || (num2 == num3))
         {
            money += 0.50;
            printf("YOU WON $0.50!\n");

            triple = 0;
         }

         printf("You have $%.2f.\n", money);
      }
      else
      {
         printf("Please enter correct input.\n");
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

char convert(int i)
{
   switch(i)
   {
      case 0: return '0'; break;
      case 1: return '1'; break;
      case 2: return '2'; break;
      case 3: return '3'; break;
      case 4: return '4'; break;
      case 5: return '5'; break;
      case 6: return '6'; break;
      case 7: return '7'; break;
      case 8: return '8'; break;
      case 9: return '9'; break;
      case 10: return '\2'; break;
      case 11: return '\3'; break;
      case 12: return '\4'; break;
      case 13: return '\5'; break;
      case 14: return '\6'; break;
   }
   return -1;
}
