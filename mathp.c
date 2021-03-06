#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define DOUBLE_MAXLENGTH 30
#define OPERATORS_MAXNUM 1024

double parse(char**, int, int, int);
int tokenize(char*, char**);
int readDouble(char*, char*);
char* dtos(double);
int findParen(char**, int, int, int);

int main(int argc, char** argv)
{
   if(argc != 2)
   {
      printf("To use the Expression Parser, type the command \"mathp \",\n");
      printf("then the mathematical expression you want to evaluate, then press enter.\n");
      printf("You can use \"pi\" to represent the constant pi, \"e\" to represent e and\n");
      printf("\"sqrt( [expression] )\" to calculate the square root of a number\n");
      printf(" or a mathematical expression. You can use \"123.4567!\" to calculate the\n");
      printf("factorial of a number, or \"( [expression] )!\" to calculate the factorial\n");
      printf("of a mathematical expression. You may need to surround your mathematical\n");
      printf("expression with \" and \".\n");
      printf("Example: \n");
      printf("'mathp \"3.5 * 7 + 23 / pi\"'   this evaluates to (3.5 * 7) + (23 / 3.14159...).\n");

      return 0;
   }

   char** tokens = (char**)malloc(strlen(argv[1]) * sizeof(char*));
   int tokenIndex = tokenize(argv[1], tokens);



   double result = parse(tokens, 0, tokenIndex - 1, tokenIndex);
   printf("Result: %f\n", result);

   for(int i = 0; i < tokenIndex; i++)
   {
      free(tokens[i]);
   }
   free(tokens);
}






double parse(char** tokens, int start, int finish, int tokensSize)
{
   printf("parse called, start=%i, finish=%i.\n", start, finish);
   for(int i = 0; i < tokensSize; i++)
   {
      printf("%s, ", tokens[i]);
   }
   int lastValidToken = 0;
   int lastTok = 0;

   for(int i = start; i <= finish; i++)
   {
      if(strcmp(tokens[i], "(") == 0)
      {
         int j = findParen(tokens, start, finish, i);

         printf("j: %i\n", j);
         tokens[i] = dtos(parse(tokens, i + 1, j - 1, tokensSize));
         for(int k = i + 1; k <= j; k++) tokens[k] = " ";

         return parse(tokens, start, finish, tokensSize);
      }
   }



   for(int i = start; i <= finish; i++)
   {
      if((strcmp(tokens[i], "!") == 0) && ((i - 1) >= start))
      {
         double factorial = 1;
         double number = parse(tokens, lastValidToken, i - 1, tokensSize);
         for(int l = 1; l <= number; l++) factorial = factorial * l;

         tokens[lastValidToken] = dtos(factorial);
         tokens[i] = " ";

         return parse(tokens, start, finish, tokensSize);
      }
      else if(strcmp(tokens[i], "sqrt") == 0)
      {
         if(((i + 1) <= finish) && (tokens[i + 1][0] == '('))
         {
            tokens[i] = dtos(sqrt(parse(tokens, i + 1, i + 1, tokensSize)));
            tokens[i + 1] = " ";

            return parse(tokens, start, finish, tokensSize);
         }
      }
      else if(tokens[i][0] != ' ')
      {
         lastValidToken = i;
      }
   }


   int precedence = 0;
   int order = 0;
   lastValidToken = 0;
   lastTok = 0;
   
   for(int i = start; i <= finish; i++)
   {
      if(strcmp(tokens[i], "/") == 0)
      {
         if(10 >= order)
         {
            printf("adding a /.\n");
            order = 10;
            precedence = i;
            lastTok = lastValidToken;
         }
      }
      else if(strcmp(tokens[i], "*") == 0)
      {
         if(9 >= order)
         {
            printf("adding a *.\n");
            order = 9;
            precedence = i;
            lastTok = lastValidToken;
         }
      }
      else if(strcmp(tokens[i], "-") == 0)
      {
         if(8 >= order)
         {
            printf("adding a -.\n");
            order = 8;
            precedence = i;
            lastTok = lastValidToken;
         }
      }
      else if(strcmp(tokens[i], "+") == 0)
      {
         if(7 >= order)
         {
            printf("adding a +.\n");
            order = 7;
            precedence = i;
            lastTok = lastValidToken;
         }
      }
      else if(tokens[i][0] != ' ')
      {
         lastValidToken = i;
      }
   }

   double result = 0;

   if(order == 10) result = parse(tokens, lastTok, precedence - 1, tokensSize) / parse(tokens, precedence + 1, precedence + 1, tokensSize);
   else if(order == 9) result = parse(tokens, lastTok, precedence - 1, tokensSize) * parse(tokens, precedence + 1, precedence + 1, tokensSize);
   else if(order == 8) result = parse(tokens, lastTok, precedence - 1, tokensSize) - parse(tokens, precedence + 1, precedence + 1, tokensSize);
   else if(order == 7) result = parse(tokens, lastTok, precedence - 1, tokensSize) + parse(tokens, precedence + 1, precedence + 1, tokensSize);
   else
   {
      printf("parsed a constant. %f\n", atof(tokens[start]));
      if(strcmp(tokens[start], "pi") == 0) return 3.141592653589793;
      else if(strcmp(tokens[start], "e") == 0) return 2.718281828459045;
      else return atof(tokens[start]);
   }

   int copy = lastTok;
   for(int i = start; i < copy; i++)
   {
      if((tokens[i][0] != ' ') && (isdigit(tokens[i][0]) || tokens[i][0] == '-')) lastTok = i;
   }
   printf("lastTok: %i\n", lastTok);
   if(lastTok > 0 && result < 0)
   {
      tokens[lastTok - 1] = "-";
      tokens[lastTok] = dtos(-(result));
   }
   else if(lastTok > 0)
   {
      tokens[lastTok - 1] = dtos(result);
      tokens[lastTok] = " ";
   }
   else
   {
      tokens[lastTok - 1] = dtos(result);
      tokens[lastTok] = " ";
   }

   for(int i = lastTok; i < (precedence - 1); i++) tokens[i] = " ";

   return parse(tokens, start, finish, tokensSize);
}











int tokenize(char* string, char** tokens)
{
   char* currentToken = (char*)malloc(DOUBLE_MAXLENGTH + 1);
   currentToken = memset(currentToken, '\0', strlen(string));

   int j = 0;
   for(int i = 0; i < strlen(string); i++)
   {
      if(isdigit(string[i]))
      {
         int howMany = readDouble(currentToken, string + i);

         tokens[j] = (char*)malloc(DOUBLE_MAXLENGTH + 1);
         strcpy(tokens[j], currentToken);

         j++;
         i += (howMany > 1) ? howMany - 1: 0;
      }
      else if((i > 0) && string[i] == '-' && tokens[j - 1][0] != ')' && tokens[j - 1][0] != '!' && !isdigit(tokens[j - 1][0]))
      {
         int howMany = readDouble(currentToken, string + i);

         tokens[j] = (char*)malloc(DOUBLE_MAXLENGTH + 1);
         strcpy(tokens[j], currentToken);

         j++;
         i += (howMany > 1) ? howMany - 1: 0;
      }
      else if(strncmp(string + i, "pi", 2) == 0)
      {
         tokens[j] = "pi";
         j++;
         i++;
      }
      else if(strncmp(string + i, "sqrt", 4) == 0)
      {
         tokens[j] = "sqrt";
         j++;
         i += 3;
      }
      switch(string[i])
      {
         case 'e': tokens[j] = "e"; j++; break;
         case '+': tokens[j] = "+"; j++; break;
         case '-': tokens[j] = "-"; j++; break;
         case '*': tokens[j] = "*"; j++; break;
         case '/': tokens[j] = "/"; j++; break;
         case '(': tokens[j] = "("; j++; break;
         case ')': tokens[j] = ")"; j++; break;
         case '!': tokens[j] = "!"; j++; break;
      }
   }

   free(currentToken);

   return j;
}

int readDouble(char* to, char* from)
{
   int i = 0, k = 0;
   if(from[0] == '-')
   {
      i++;
      k++;
      to[0] = from[0];
   }

   for(; i < DOUBLE_MAXLENGTH; i++)
   {
      if(from[i] != '.' && !isdigit(from[i])) break;

      to[k] = from[i];
      k++;
   }
   to[k] = '\0';

   return k;
}

char* dtos(double input)
{
   char* temp2 = (char*)malloc(DOUBLE_MAXLENGTH);
   temp2 = memset(temp2, '\0', DOUBLE_MAXLENGTH);
   sprintf(temp2, "%f", input);

   return temp2;
}

int findParen(char** tokens, int start, int finish, int firstParenLocation)
{
   int parenCount = 0, j = 0;
   for(j = firstParenLocation; j < finish; j++)
   {
      if(strcmp(tokens[j], "(") == 0) parenCount++;
      else if(strcmp(tokens[j], ")") == 0) parenCount--;
      if(parenCount == 0 && j != start) break;
   }

   return j;
}
