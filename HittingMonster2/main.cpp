#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int HP_Y, ATK_Y, DEF_Y;
    int HP_M, ATK_M, DEF_M;
    int HP_cost, ATK_cost, DEF_cost;
    float HP_priority = 1, ATK_priority = 1, DEF_priority = 1;

    cout << "Enter HP_Y, ATK_Y, DEF_Y...:";
    cin >> HP_Y >> ATK_Y >> DEF_Y;

    cout << "Enter HP_M, ATK_M, DEF_M...:";
    cin >> HP_M >> ATK_M >> DEF_M;

    cout << "Enter HP_cost, ATK_cost, DEF_cost...:";
    cin >> HP_cost >> ATK_cost >> DEF_cost;

    int roundsToKillM = ceil( float(HP_M) / (float(ATK_Y - DEF_M)) );
    int roundsToKillY = ceil( float(HP_Y) / (float(ATK_M - DEF_Y)) );

    if (ATK_Y - DEF_M <= 0)
        roundsToKillM = 999;
    if (ATK_M - DEF_Y == 0)
        roundsToKillY = 999;

    int minBitcoinstToSpent = 0;

    while (roundsToKillM >= roundsToKillY)
    {
        HP_priority = float(HP_cost) / float(roundsToKillM);

        DEF_priority = float(roundsToKillM) / float(DEF_cost);

        ATK_priority = float(roundsToKillY) / float(ATK_cost);
        if ( (DEF_M - ATK_Y) >= 0 )
            ATK_priority = DEF_priority + HP_priority + 1;


        if (HP_priority > DEF_priority && HP_priority > ATK_priority)
        {
            minBitcoinstToSpent = minBitcoinstToSpent + HP_cost;
            HP_Y++;
        }

        if (DEF_priority > HP_priority && DEF_priority > ATK_priority)
        {
            minBitcoinstToSpent = minBitcoinstToSpent + DEF_cost;
            DEF_Y++;
        }

        if (ATK_priority > DEF_priority && ATK_priority > HP_priority)
        {
            minBitcoinstToSpent = minBitcoinstToSpent + ATK_cost;
            ATK_Y++;
        }

        roundsToKillM = ceil( float(HP_M) / (float(ATK_Y - DEF_M)) );
        roundsToKillY = ceil( float(HP_Y) / (float(ATK_M - DEF_Y)) );

        if (ATK_Y - DEF_M <= 0)
            roundsToKillM = 999;
        if (ATK_M - DEF_Y <= 0)
            roundsToKillY = 999;
    }



    cout << "minimum bitcoins to spent = " << minBitcoinstToSpent << endl;
    return 0;
}

