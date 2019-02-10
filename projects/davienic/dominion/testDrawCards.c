#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("TESTING drawCards():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
#if (NOISY_TEST == 1)
            printf("Test player %d with %d card(s).\n", p, handCount);
#endif
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

            for(int i = 0; i < numPlayer; i++)
            {
                G.handCount[i] = handCount;
            }

            memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
            drawCards(&G, p, handCount);

#if (NOISY_TEST == 1)
            printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], handCount + handCount);
#endif
            for(int i = 0; i < numPlayer; i++)
            {
                if (p == i)
                {
                    assert(G.handCount[p] == handCount + handCount);
                }
                else
                {
                    assert(G.handCount[i] == handCount);
                }
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}
