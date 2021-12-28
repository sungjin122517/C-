#include <iostream>
#include <cstdlib>
#include <time.h>  
using namespace std;

int main() 
{
    srand( time(NULL) );
    //Codemaker's choice of a random 4-color combination among six colors 
    // 1 Yellow, 2 Orange, 3 black, 4 Green, 5 Blue, 6 Purple
    int p0 = rand() % 6 + 1; // 1 to 6
    int p1 = rand() % 6 + 1; // 1 to 6
    int p2 = rand() % 6 + 1; // 1 to 6
    int p3 = rand() % 6 + 1; // 1 to 6


    bool debug = true;

    cout << "==============================" << endl;
    cout << "Welcome to the Mastermind Game" << endl;
    cout << "==============================" << endl;

    if (debug){
        cout << "Coder maker's colors:" << endl;
        cout << "p0=" << p0 << "\tp1=" << p1 << "\tp2=" << p2 << "\tp3=" << p3 << endl << endl;
    }

    cout << "Code maker has made his choice." << endl;
    cout << "Code breaker, you have 12 attempts to crack his code." << endl;
    cout << "Game starts!" << endl << endl;

    
    // variable for code breaker's guess
    // variable for codemaker's response
    // red: correct color and correct position
    // white: correct color but wrong position
    // red overrides white

    int total_attempt = 12;
    int x0, x1, x2, x3;
    int redpin = 0, whitepin = 0;
    bool x0used = 0, x1used = 0, x2used = 0, x3used = 0;    // 아직 카운트 안 돼서 false
    bool p0used = 0, p1used = 0, p2used = 0, p3used = 0;    // 여기도 똑같이

    
    // Write your code below this section:

    for (int i = 1; i <= total_attempt; i++)
    {
        cout << "Attempt " << i << endl;
        cout << "Please input your guess: " << endl;
        cin >> x0 >> x1 >> x2 >> x3;

        if (p0==x0) {redpin += 1; x0used = true; p0used = true;}    // red로 카운트 되었기 때문에 used변수들은 true가 된다.
        if (p1==x1) {redpin += 1; x1used = true; p1used = true;}
        if (p2==x2) {redpin += 1; x2used = true; p2used = true;}
        if (p3==x3) {redpin += 1; x3used = true; p3used = true;}

        if (!x0used && !p1used && x0==p1)
        {
            whitepin += 1;
            x0used = true;
            p1used = true;
        }

        if (!x0used && !p2used && x0==p2)
        {
            whitepin += 1;
            x0used = true;
            p2used = true;
        }

        if (!x0used && !p3used && x0==p3)
        {
            whitepin += 1;
            x0used = true;
            p3used = true;
        }

        if (!x1used && !p0used && x1==p0)
        {
            whitepin += 1;
            x1used = true;
            p0used = true;
        }

        if (!x1used && !p2used && x1==p2)
        {
            whitepin += 1;
            x1used = true;
            p2used = true;
        }

        if (!x1used && !p3used && x1==p3)
        {
            whitepin += 1;
            x1used = true;
            p3used = true;
        }

        if (!x2used && !p0used && x2==p0)
        {
            whitepin += 1;
            x2used = true;
            p0used = true;
        }

        if (!x2used && !p1used && x2==p1)
        {
            whitepin += 1;
            x2used = true;
            p1used = true;
        }

        if (!x2used && !p3used && x2==p3)
        {
            whitepin += 1;
            x2used = true;
            p3used = true;
        }

        if (!x3used && !p0used && x3==p0)
        {
            whitepin += 1;
            x3used = true;
            p0used = true;
        }

        if (!x3used && !p1used && x3==p1)
        {
            whitepin += 1;
            x3used = true;
            p1used = true;
        }

        if (!x3used && !p2used && x3==p2)
        {
            whitepin += 1;
            x3used = true;
            p2used = true;
        }

        // if (!x2used)
        //     if (x2==p0 || x2==p1 || x2==p3)
        //         whitepin += 1;
        
        // if (!x3used)
        //     if (x3==p0 || x3==p1 || x3==p2)
        //         whitepin += 1;


        cout << "red: " << redpin << ", white: " << whitepin << endl << endl;
        
        if (redpin == 4)
        {
            cout << "Congratulations!\nCoder maker's colors:\n";
            cout << "p0= " << p0 << "\tp1= " << p1 
            << "\tp2= " << p2 << "\tp3= " << p3 << endl;
            cout << "You cracked the code with " << i << " attempts" << endl;
            break;
        }

        if (i == total_attempt)
        cout << "Sorry, you ran out of turns :( "<< endl;

        redpin -= redpin; whitepin -= whitepin;
        x0used = 0; x1used = 0; x2used = 0; x3used = 0;    
        p0used = 0; p1used = 0; p2used = 0; p3used = 0;    

    
    }   

    return 0;

}