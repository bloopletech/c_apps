#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int rrange(int, int);

int main()
{
   srand(time(NULL));
   int guess = 1;
   int num = rrange(2, 500);

   printf("Welcome to the guessing game!\n");
   printf("In this game, you have 7 guesses to try and figure out what number I'm");
   printf("thinking of.\n");
   printf("The number will be between 2 and 500.\n");
   printf("====================================================\n");

   printf("What number am I thinking of?\n");

   do
   {
      int input = 0;
      do
      {
          printf("Please enter guess %i: ", guess);
   
          if(scanf("%i", &input) != EOF) break;

          printf("Please enter a number.\n");
       }
       while(1);

       if(input < num)
       {
          printf("You'll have to guess higher!\n");
       }
       else if(input > num)
       {
          printf("You'll have to guess lower!\n");
       }
       else if(input == num)
       {
          printf("You got it!\n");
          return 0;
       }

       guess++;
    }
    while(guess <= 7);

    printf("You lost.\n");
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
