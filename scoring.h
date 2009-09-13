#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUMAN 0
#define COMPUTER 100


typedef struct {
   int type;
   int score;
} player;


player* makePlayer(int type)
{
   player* output = (player*)malloc(sizeof(player));

   output->type = type;
   output->score = 0;

   return output;
}

player* freePlayer(player* input)
{
   free(input);
}
