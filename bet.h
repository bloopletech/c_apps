
#define BET_SINGLE 0
#define BET_0 0
#define BET_0_PAYOFF 5
#define BET_1 1
#define BET_1_PAYOFF 5
#define BET_2 2
#define BET_2_PAYOFF 5
#define BET_3 3
#define BET_3_PAYOFF 5
#define BET_4 4
#define BET_4_PAYOFF 5
#define BET_5 5
#define BET_5_PAYOFF 5
#define BET_6 6
#define BET_6_PAYOFF 5
#define BET_7 7
#define BET_7_PAYOFF 5
#define BET_8 8
#define BET_8_PAYOFF 5
#define BET_9 9
#define BET_9_PAYOFF 5
#define BET_10 10
#define BET_10_PAYOFF 5
#define BET_11 11
#define BET_11_PAYOFF 5
#define BET_12 12
#define BET_12_PAYOFF 5
#define BET_13 13
#define BET_13_PAYOFF 5
#define BET_14 14
#define BET_14_PAYOFF 5
#define BET_15 15
#define BET_15_PAYOFF 5
#define BET_16 16
#define BET_16_PAYOFF 5
#define BET_17 17
#define BET_17_PAYOFF 5
#define BET_18 18
#define BET_18_PAYOFF 5


#define BET_ROWS 40
#define BET_ROW3 40
#define BET_ROW3_PAYOFF 3
#define BET_ROW6 41
#define BET_ROW6_PAYOFF 3
#define BET_ROW9 42
#define BET_ROW9_PAYOFF 3
#define BET_ROW12 43 
#define BET_ROW12_PAYOFF 3
#define BET_ROW15 44 
#define BET_ROW15_PAYOFF 3
#define BET_ROW18 45 
#define BET_ROW18_PAYOFF 3

#define BET_ODD 80
#define BET_ODD_PAYOFF 1
#define BET_EVEN 81
#define BET_EVEN_PAYOFF 1

#define BET_1TO9 100
#define BET_1TO9_PAYOFF 2
#define BET_10TO18 101
#define BET_10TO18_PAYOFF 2

typedef struct
{
   int type;
   float amount;
} bet;


float payoff(bet*, float);
int didPayoff(bet*, int);
float getPayoff(bet*, int);
int divisible(int, int);
char* betType(bet*, char*);
