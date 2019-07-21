#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int gloValue = 0;

void matrixOutput(int *game)
{
    cout << game[0] << " " << game[1] << " " << game[2] << endl;
    cout << game[3] << " " << game[4] << " " << game[5] << endl;
    cout << game[6] << " " << game[7] << " " << game[8] << endl;
    cout << endl;
}

bool cellsLeft(int *game)
{
    for(int i=0; i<9; i++)
    {
        if(game[i] < 1)
        {
            return true;
        }
    }
    return false;
}

int deciderScore(int *game, int meAI)
{
    matrixOutput(game);
    if (game[0] == game[1] && game[1] == game[2])
    {
        if(meAI == game[0])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[0] == game[3] && game[3] == game[6])
    {
        if(meAI == game[0])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[1] == game[4] && game[4] == game[7])
    {
        if(meAI == game[1])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[2] == game[5] && game[5] == game[8])
    {
        if(meAI == game[2])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[3] == game[4] && game[4] == game[5])
    {
        if(meAI == game[3])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[6] == game[7] && game[7] == game[8])
    {
        if(meAI == game[6])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[0] == game[4] && game[4] == game[8])
    {
        if(meAI == game[0])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    if(game[2] == game[4] && game[4] == game[6])
    {
        if(meAI == game[2])
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    return 0;
}

int minmaxAlgorithm(int *game, int meAI, bool isX, int depth)
{

    if (deciderScore(game, meAI) == 10)
    {
        return 10;
    }
    if (deciderScore(game, meAI) == -10)
    {
        return -10;
    }
    if(!cellsLeft(game))
    {
        return 0;
    }
    for(int i=0;i<9;i++){
        if(game[i] < 1){
            if(isX){
                int temp = game[i];
                game[i] = 1;
                cout<< "bb X" << endl;
                int value = minmaxAlgorithm(game, meAI, !isX, depth+1);
                cout << value << endl;
                matrixOutput(game);
                game[i] = temp;
                return value;
            }else{
                int temp = game[i];
                game[i] = 2;
                cout<< "bb O" << endl;
                int value = minmaxAlgorithm(game, meAI, !isX, depth+1);
                cout << value << endl;
                matrixOutput(game);
                game[i] = temp;
                return value;
            }
        }
    }
    return 0;
}

int aiTurnPro(int *game, int meAI)
{
    int pos;
    int bestValue = -1000;
    for (int i=0; i<9; i++)
    {
        if(game[i] < 1)
        {
            bool aicc = false;
            int temp = game[i];
            game[i] = meAI;
            //cout << "cc" <<endl;
            //matrixOutput(game);
            if(meAI == 1){
                aicc = false;
            }else{
                aicc = true;
            }
            int best = minmaxAlgorithm(game, meAI, aicc, 0);
            cout << "best score: " <<best << endl;
            //matrixOutput(game);
            if(best > bestValue)
            {
                bestValue = best;
                pos = i;
            }
            gloValue = 0;
            game[i] = temp;
        }
    }
    return pos;
}

int aiTurnEasy(int *game)
{
    srand (time(NULL));
    int r = rand() % 10;
    while (true)
    {
        if (game[r] < 1)
        {
            break;
        }
        else
        {
            r = rand() % 10;
        }
    }
    return r;
}

int matchDecider(int *game)
{
    if (game[0] == game[1] && game[1] == game[2])
    {
        return game[0];
    }
    else if(game[0] == game[3] && game[3] == game[6])
    {
        return game[0];
    }
    else if(game[1] == game[4] && game[4] == game[7])
    {
        return game[1];
    }
    else if(game[2] == game[5] && game[5] == game[8])
    {
        return game[2];
    }
    else if(game[3] == game[4] && game[4] == game[5])
    {
        return game[3];
    }
    else if(game[6] == game[7] && game[7] == game[8])
    {
        return game[6];
    }
    else if(game[0] == game[4] && game[4] == game[8])
    {
        return game[0];
    }
    else if(game[2] == game[4] && game[4] == game[6])
    {
        return game[2];
    }
    else
    {
        return 0;
    }
}

int main()
{
    int choice;
    int opponent;
    //int game[9] = {1, 2, 1,2, 2, -6,-7, -8, -9};
    //int game[9] = {1, 2, -3, 1, 2, -6, -7, -8, -9};
    int game[9] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int pos;
    cout << "Tic-Tac-Toe" << endl;
    cout << "Play as 1(X) or 2(O)" << endl;
    cin >> choice;
    while(cellsLeft(game))
    {
        matrixOutput(game);
        cout << "Enter the position to play" <<endl;
        cin >> pos;
        pos = pos - 1;
        game[pos] = choice;
        if (choice == 1)
        {
            opponent = 2;
        }
        else
        {
            opponent = 1;
        }
        //pos = aiTurnEasy(game);
        pos = aiTurnPro(game, opponent);
        cout << pos + 1 <<endl;
        game[pos] = opponent;
        if(matchDecider(game) == 1)
        {
            if (choice == 1)
            {
                cout << "You win";
            }
            else
            {
                cout << "You lose";
            }
            break;
        }
        else if(matchDecider(game) == 2)
        {
            if (choice == 2)
            {
                cout << "You win";
            }
            else
            {
                cout << "You lose";
            }
            break;
        }
        else
        {
            cout << "Draw" << endl;
        }
    }

    return 0;
}
