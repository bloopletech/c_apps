#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

int rrange(int, int);

int main(int argc, char** argv)
{
   srand(time(NULL));

   float stack[32768];
   float* stackPointer = stack;

   char* temp = (char*)malloc(256);
   for(int i = 0; i < strlen(argv[1]); i++)
   {
      if(argv[1][i] == ':')
      {
         printf("%f", *(stackPointer));
         stackPointer--;
      }
      else if(argv[1][i] == ';')
      {
         printf("%c", (int)*(stackPointer));
         stackPointer--;
      }
      else if(argv[1][i] == '?')
      {
         scanf("%f", *(stackPointer));
         stackPointer++;
      }
      else if(argv[1][i] == ')')
      {
         scanf("%255s", temp);
         for(int i = 0; i < strlen(temp); i++)
         {
            *(stackPointer) = temp[i];
            stackPointer++;
         }
      }
      else if(argv[1][i] == '~')
      {
         if(*(stackPointer) == 0)
         {
            i -= *(stackPointer);
         }
      }
      else if(argv[1][i] == '!')
      {
         if(*(stackPointer) != 0)
         {
            i -= *(stackPointer);
         }
      }
      else if(argv[1][i] == '`')
      {
         *(stackPointer++) = rrange(*(stackPointer), *(stackPointer - 1));
      }
      else if(argv[1][i] == '+')
      {
         *(stackPointer + 1) = *(stackPointer) + *(stackPointer - 1);
         stackPointer++;
      }
      else if(argv[1][i] == '-')
      {
         *(stackPointer - 1) = *(stackPointer) - *(stackPointer - 1);
      }
      else if(argv[1][i] == '*')
      {
         *(stackPointer + 1) = *(stackPointer) * *(stackPointer - 1);
         stackPointer++;
      }
      else if(argv[1][i] == '/')
      {
         *(stackPointer + 1) = *(stackPointer) / *(stackPointer - 1);
         stackPointer++;
      }
      else if(argv[1][i] == '^')
      {
         *(stackPointer + 1) = sqrt(*(stackPointer));
         stackPointer++;
      }
      else
      {
         int tempc = 0;
         sscanf((argv[1] + i), "%255[0123456789@#$%&(_=qwertyuiop\\QWERTYUIOP{}|asdfghjkl'ASDFGHJKL\"zxcvbnm,.ZXCVBNM<>\20]%n", &temp, &tempc);
         printf("t0: %f", temp[0]);

         if(isdigit(temp[0]) || temp[0] == '-')
         {
            *(stackPointer) = (float)atof(temp);
         }
         else
         {
            *(stackPointer) = (float)temp[0];
         }

         i += (tempc - 1);
         printf("added: --%f--", *(stackPointer));
      }
   }
   for(int i = 0; i < 32768; i++)
   {
      putchar(stack[i]);
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

      
      