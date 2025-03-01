#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *StringToLower(char *s);
int main(void) {
  bool playing = true;
  double totalCash = 100;
  int bet = 0;
  int maxBet = 5000;
  int payout = 0;
  float payoutPercentageFirst = 1.75;
  float payoutPercentageFinal = 3;
  int rounds = 4;
  while (playing) {
    printf("new game");
    // kill player
    if (totalCash <= 0) {
      playing = false;
      printf("/n*Hovering over your barely concious body* Sorry but your time "
             "has run out, and we can't revive a broken soul without any "
             "money... goodbye.../n");
    }
    // See if the player is a bitch
    printf("/nAre you sure you wanna play? Yes or No?/n");
    char response[50];
    scanf("%s", response);
    // normalize input
    strcpy(response, StringToLower(response));

    // Player another round
    for (int i = 0; i < rounds; i++) {
      // Take bet
      if (i == 0) {
        bool betting = true;

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

      // Check if its special rounds
      if (i == 2) {
        // Final round or double down

      } else if (i == 3) {
        // final round triple or more payout

      } else {
        // Filler round
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

int *DetectYesOrNo(char *stc) {
  int len = strlen(stc);
  for (int i = 0; i < len - 3; i++) {
    if (stc[i] == 'y' && stc[i + 1] == 'e' && stc[i + 2] == 's') {
      return 1;
    }
  }
  return 0;
}