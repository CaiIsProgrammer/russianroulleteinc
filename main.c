
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *StringToLower(char *s);
int DetectYesOrNo(char *stc);
int AskYesOrNo();
int main(void) {

  srand(time(0));

  bool playing = true;
  double totalCash = 100;
  int maxBet = 5000;
  float payoutPercentageFirst = 1.75;
  float payoutPercentageFinal = 3;
  int rounds = 4;
  while (playing) {
    int bet = 0;

    int payout = 0;

    // kill player
    if (totalCash <= 0) {
      playing = false;
      printf("\n*Hovering over your barely concious body* Sorry but your time "
             "has run out, and we can't revive a broken soul without any "
             "money... goodbye...\n");
    }

    if (true) {
      // See if the player is a bitch
      printf("\nAre you sure you wanna play? Yes or No?\n");
      int checkResponse = AskYesOrNo();
      if (checkResponse == 0) {
        playing = false;
      }
      if (checkResponse == -1) {
        printf("\nPlease retry your response, yes or no\n");
      }
    }
    if (!playing) {
      printf("Here is your final balance: %lf", totalCash);
      break;
    }
    // Player another round
    for (int i = 0; i < rounds; i++) {
      bool dead = false;
      // Take bet
      if (i == 0) {
        bool betting = true;
        system("clear");
        printf("\nWelcome back to russian roulette, You have %.2lf, Enter your "
               "Bet: \n",
               totalCash);
        // Keep asking until a proper bet is provided
        while (betting) {
          scanf("%d", &bet);
          if (bet > 0 && bet <= maxBet) {
            // check if bet is less than or equal to what they have
            if (bet <= totalCash) {
              betting = false;
              printf("\nAlright you are risking %d against your life\n", bet);
            } else {
              // fucker tried paying more than what they have
              printf("Sly and sneaky are we? you can't bet more than what "
                     "you have, So I'll set you to your total cash");
              betting = false;
              bet = totalCash;
            }
          } else {
            // Tell the player they are fucking dumbasses
            printf("\nPlease enter more than 0 and less than %d\n", maxBet);
          }
        }
      }
      // roll dice and play game. 1 less die for each round
      int dealerDiceRoll = (rand() % (6 - (i + 1))) + 1;
      int playerDiceRoll = (rand() % (6 - (i + 1))) + 1;
      //printf("Dealer roll: %d Player roll: %d", dealerDiceRoll, playerDiceRoll);
      printf("\nNext Bullet Ready? Yes or No?\n");
      printf("\nBullets loaded: %d \n", i + 1);
      AskYesOrNo();

      if (playerDiceRoll == dealerDiceRoll) {
        printf("\n*Bang*\n");
        printf("\n*Hovering over your barely concious body* Sorry but your time "
           "has run out, oh well heyyy... I still see money in your pocket, let's revive you!\n");
        totalCash = totalCash - (double)bet;
        i = rounds;
        dead = true;
      } else {
        printf("*click*");
      }

      if (!dead) {
        // Check if its special rounds
        if (i == 2) {
          // Final round or double down
          printf("\nYou lived, Well, Do you want to double down and take one "
                 "final "
                 "chance with a 3x payout or take the 1.75x payout and run.\n");
          int response = AskYesOrNo();

          if (response == 1) {
            printf("\nEY! I like you, Lets go again.\n");
          }
          if (response == 0) {
            payout = bet * payoutPercentageFirst;
            totalCash = totalCash + (double)payout;
            printf("\nAlright pussy here is your payout: $%d\n", payout);
            i = rounds;
          }
        } else if (i == 3) {
          // final round triple or more payout
          payout = bet * payoutPercentageFinal;
          totalCash = totalCash + (double)payout;
          i = rounds;
          printf("\nYou lived all the way through, Here is your winnings Stud "
                 "%d\n",
                 payout);
        }
      }
    }
  }

  return 0;
}

char *StringToLower(char *s) {
  for (char *p = s; *p; p++)
    *p = tolower(*p);
  return s;
}

int DetectYesOrNo(char *stc) {

  int len = strlen(stc);
  for (int i = 0; i < len; i++) {

    if (stc[i] == 'n' && stc[i + 1] == 'o') {
      return 0;
    }
    if (stc[i + 1] == 'n' && stc[i + 2] == 'o') {
      return 0;
    }
    if (stc[i] == 'y' && stc[i + 1] == 'e' && stc[i + 2] == 's') {
      return 1;
    }
  }
  return -1;
}
int AskYesOrNo() {

  char response[50];
  scanf("%s", response);
  // normalize input
  strcpy(response, StringToLower(response));
  int checkResponse = DetectYesOrNo(response);
  if (checkResponse == 1) {

    return 1;
  }
  if (checkResponse == 0) {
    return 0;
  }
  if (checkResponse == -1) {
    printf("\nPlease retry your response, yes or no\n");
    return AskYesOrNo();
  }
}
