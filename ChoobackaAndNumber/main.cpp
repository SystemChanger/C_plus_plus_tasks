#include <iostream>
#include <string>

using namespace std;

int main()
{
    string numForChoo;
    cout << "Choobacka wants number...:";
    cin >> numForChoo;
    if (numForChoo[0] == '0')
    {
        cout << "Please, enter number without leading zeroes...:" << endl;
        cin >> numForChoo;
    }

   for (int i = 0; i < numForChoo.size(); i++)
       if (numForChoo[i] - '0' > 9 - (numForChoo[i] - '0'))
            numForChoo[i] = 9 - (numForChoo[i] - '0') + '0';

    cout << "Choobacka returned you: " << numForChoo;
    return 0;
}
