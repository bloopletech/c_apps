#include "bet.h"


//this function returns a cstring description of b
char* betType(bet* b, char* input)
{
   int type = b->type;
   if(type >= BET_0 && type <= BET_18)
   {
      input = "single number";
   }
   else if(type >= BET_ROW3 && type <= BET_ROW18)
   {
      input = "row";
   }
   else if(type == BET_ODD)
   {
      input = "odd";
   }
   else if(type <= BET_EVEN)
   {
      input = "even";
   }
   else if(type == BET_1TO9)
   {
      input = "1 to 9";
   }
   else if(type <= BET_10TO18)
   {
      input = "10 to 18";
   }

   return input;
}

//this function returns the payoff for a bet b, given a bet of size amount.
float payoff(bet* b, float amount)
{
   int type = b->type;
   if(type >= BET_0 && type <= BET_18)
   {
      return BET_0_PAYOFF;
   }
   else if(type >= BET_ROW3 && type <= BET_ROW18)
   {
      return BET_ROW3_PAYOFF;
   }
   else if(type >= BET_ODD && type <= BET_EVEN)
   {
      return BET_ODD_PAYOFF;
   }
   else if(type >= BET_1TO9 && type <= BET_10TO18)
   {
      return BET_1TO9_PAYOFF;
   }
   else
   {
      return -1;
   }
}

//this function returns 1 if and only if the bet in b will return a payoff.
//hit is the value the ball landed on.
int didPayoff(bet* b, int hit)
{
   int type = b->type;
   switch(type)
   {
      case BET_0: return (hit == 0) ? 1 : 0; break;
      case BET_1: return (hit == 1) ? 1 : 0; break;
      case BET_2: return (hit == 2) ? 1 : 0; break;
      case BET_3: return (hit == 3) ? 1 : 0; break;
      case BET_4: return (hit == 4) ? 1 : 0; break;
      case BET_5: return (hit == 5) ? 1 : 0; break;
      case BET_6: return (hit == 6) ? 1 : 0; break;
      case BET_7: return (hit == 7) ? 1 : 0; break;
      case BET_8: return (hit == 8) ? 1 : 0; break;
      case BET_9: return (hit == 9) ? 1 : 0; break;
      case BET_10: return (hit == 10) ? 1 : 0; break;
      case BET_11: return (hit == 11) ? 1 : 0; break;
      case BET_12: return (hit == 12) ? 1 : 0; break;
      case BET_13: return (hit == 13) ? 1 : 0; break;
      case BET_14: return (hit == 14) ? 1 : 0; break;
      case BET_15: return (hit == 15) ? 1 : 0; break;
      case BET_16: return (hit == 16) ? 1 : 0; break;
      case BET_17: return (hit == 17) ? 1 : 0; break;
      case BET_18: return (hit == 18) ? 1 : 0; break;

      case BET_ROW3: return (hit >= 1 && hit <= 3) ? 1 : 0; break;
      case BET_ROW6: return (hit >= 4 && hit <= 6) ? 1 : 0; break;
      case BET_ROW9: return (hit >= 7 && hit <= 9) ? 1 : 0; break;
      case BET_ROW12: return (hit >= 10 && hit <= 12) ? 1 : 0; break;
      case BET_ROW15: return (hit >= 13 && hit <= 15) ? 1 : 0; break;
      case BET_ROW18: return (hit >= 16 && hit <= 18) ? 1 : 0; break;

      case BET_ODD: return ((hit != 0) && !divisible(hit, 2)) ? 1 : 0; break;
      case BET_EVEN: return ((hit != 0) && divisible(hit, 2)) ? 1 : 0; break;

      case BET_1TO9: return (hit >= 1 && hit <= 9) ? 1 : 0; break;
      case BET_10TO18: return (hit >= 10 && hit <= 18) ? 1 : 0; break;

      default: return 0;
   }
}


//this function returns 1 if and only if the bet in b will return a payoff.
//hit is the value the ball landed on.
float getPayoff(bet* b, int hit)
{
   int type = b->type;
   float amount = b->amount;
   switch(type)
   {
      case BET_0: return (hit == 0) ? amount * BET_0_PAYOFF : 0; break;
      case BET_1: return (hit == 1) ? amount * BET_1_PAYOFF : 0; break;
      case BET_2: return (hit == 2) ? amount * BET_2_PAYOFF : 0; break;
      case BET_3: return (hit == 3) ? amount * BET_3_PAYOFF : 0; break;
      case BET_4: return (hit == 4) ? amount * BET_4_PAYOFF : 0; break;
      case BET_5: return (hit == 5) ? amount * BET_5_PAYOFF : 0; break;
      case BET_6: return (hit == 6) ? amount * BET_6_PAYOFF : 0; break;
      case BET_7: return (hit == 7) ? amount * BET_7_PAYOFF : 0; break;
      case BET_8: return (hit == 8) ? amount * BET_8_PAYOFF : 0; break;
      case BET_9: return (hit == 9) ? amount * BET_9_PAYOFF : 0; break;
      case BET_10: return (hit == 10) ? amount * BET_10_PAYOFF : 0; break;
      case BET_11: return (hit == 11) ? amount * BET_11_PAYOFF : 0; break;
      case BET_12: return (hit == 12) ? amount * BET_12_PAYOFF : 0; break;
      case BET_13: return (hit == 13) ? amount * BET_13_PAYOFF : 0; break;
      case BET_14: return (hit == 14) ? amount * BET_14_PAYOFF : 0; break;
      case BET_15: return (hit == 15) ? amount * BET_15_PAYOFF : 0; break;
      case BET_16: return (hit == 16) ? amount * BET_16_PAYOFF : 0; break;
      case BET_17: return (hit == 17) ? amount * BET_17_PAYOFF : 0; break;
      case BET_18: return (hit == 18) ? amount * BET_18_PAYOFF : 0; break;

      case BET_ROW3: return (hit >= 1 && hit <= 3) ? amount * BET_ROW3_PAYOFF : 0; break;
      case BET_ROW6: return (hit >= 4 && hit <= 6) ? amount * BET_ROW6_PAYOFF : 0; break;
      case BET_ROW9: return (hit >= 7 && hit <= 9) ? amount * BET_ROW9_PAYOFF : 0; break;
      case BET_ROW12: return (hit >= 10 && hit <= 12) ? amount * BET_ROW12_PAYOFF : 0; break;
      case BET_ROW15: return (hit >= 13 && hit <= 15) ? amount * BET_ROW15_PAYOFF : 0; break;
      case BET_ROW18: return (hit >= 16 && hit <= 18) ? amount * BET_ROW18_PAYOFF : 0; break;

      case BET_ODD: return ((hit != 0) && !divisible(hit, 2)) ? amount * BET_ODD_PAYOFF : 0; break;
      case BET_EVEN: return ((hit != 0) && divisible(hit, 2)) ? amount * BET_EVEN_PAYOFF : 0; break;

      case BET_1TO9: return (hit >= 1 && hit <= 9) ? amount * BET_1TO9_PAYOFF : 0; break;
      case BET_10TO18: return (hit >= 10 && hit <= 18) ? amount * BET_10TO18_PAYOFF : 0; break;

      default: return 0;
   }
}

int divisible(int a, int b)
{
   while(a >= b)
   {
      a -= b;
   }
   return (a == 0);
}
