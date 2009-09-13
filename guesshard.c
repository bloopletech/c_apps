#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int rrange(int, int);
float to1place(float);

int main()
{
   srand(time(NULL));
   int guess = 1;
   int num = rrange(2, 500);
   float root = to1place(sqrt(num));

   printf("Welcome to the guessing game!\n");
   printf("In this game, you have 12 guesses to try and figure out the quare root of");
   printf("a given number.\n");
   printf("If you enter a square root that's correct to at least one decimal place,\n");
   printf("you'll win.\n");
   printf("====================================================\n");

   printf("What is the square root of %i?\n", num);

   do
   {
      float sr = 0;
      do
      {
          printf("Please enter guess %i: ", guess);
   
          if(scanf("%f", &sr) != EOF) break;

          printf("Please enter a number.\n");
       }
       while(1);

       float temp = to1place(sr);

       if(sr < root)
       {
          printf("You'll have to guess higher!\n");
       }
       else if(sr > root)
       {
          printf("You'll have to guess lower!\n");
       }
       else if(root == sr)
       {
          printf("You got it!\n");
          return 0;
       }

       guess++;
    }
    while(guess <= 12);

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

float to1place(float a)
{
   char* temp = (char*)malloc(20);
   float temp2;
   sprintf(temp, "%.1f", a);
   sscanf(temp, "%f", &temp2);

   return temp2;
}
