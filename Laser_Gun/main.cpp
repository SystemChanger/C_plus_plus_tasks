#include <iostream>

using namespace std;

int main()
{
    int numOfTroopers;
    int gun_X, gun_Y;

    cout << "Enter: \"number of troopers\", gun coordinates \"X\" \"Y\"...:" << endl;
    cin >> numOfTroopers >> gun_X >> gun_Y;


    int trooper[numOfTroopers][2];
    float valueToCompare[numOfTroopers];
    int comparison[numOfTroopers - 1];
    int comparison_X = 0;
    int comparison_Y = 0;
    int numOfComparisons = 0;
    float gunValueToCompare;

    if (gun_Y != 0)
        gunValueToCompare = (float)gun_X/(float)gun_Y;
    else
        gunValueToCompare = 123456789;
    if (gun_Y == 0 && gun_X == 0)
        gunValueToCompare = 1;



    for (int i = 0, X = 0, Y = 1; i < numOfTroopers; i++)
    {
        cout << "Enter trooper[" << i << "] coordinates \"X\" \"Y\"...:";
        cin >> trooper[i][X] >> trooper[i][Y];

        while (trooper[i][X] == gun_X && trooper[i][Y] == gun_Y)
        {
            cout << "Trooper can't have same coordinates as gun." << endl << "Please give correct coordinates \"X\" \"Y\"...:";
            cin >> trooper[i][X] >> trooper[i][Y];
        }


        if (trooper[i][Y] == 0 && gun_Y == 0)
            valueToCompare[i] = 123456789;
        else
            valueToCompare[i] = (float)trooper[i][X]/(float)trooper[i][Y];

        if (trooper[i][X] == gun_X)
            comparison_X++;
        if (trooper[i][Y] == gun_Y)
            comparison_Y++;

        comparison[i] = 0;
    }

    if (comparison_X > 0)
        comparison_X--;
    if (comparison_Y > 0)
        comparison_Y--;

    for (int a = 0; a < numOfTroopers; a++)
    {
            for (int b = a + 1; b < numOfTroopers; b++)
            {                
                if (valueToCompare[a] == gunValueToCompare)
                    if (valueToCompare[a] == valueToCompare[b] && valueToCompare[a] != valueToCompare[a - 1])
                        comparison[a]++;
            }
            numOfComparisons = numOfComparisons + comparison[a];
    }

    numOfComparisons = numOfComparisons + comparison_X + comparison_Y;
    int minShots = numOfTroopers - numOfComparisons;

    cout << "Min shots = " << minShots << endl;

    return 0;
}
