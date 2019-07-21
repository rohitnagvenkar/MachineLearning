            #include <iostream>
            #include <stdlib.h>
            \
            using namespace std;

            // 0 is NaN
            // 1 is X wins
            // 2 is O wins
            // 3 is draw
            int player,opponent;

            bool cellsLeft(int *game){
                for(int i=0; i<9;i++){
                    if(game[i] < 0){
                        return true;
                    }
                }
                return false;
            }

            int decider(int *game){
                if (game[0] == game[1] && game[1] == game[2]){
                    return game[0];
                }else if(game[0] == game[3] && game[3] == game[6]){
                    return game[0];
                }else if(game[1] == game[4] && game[4] == game[7]){
                    return game[1];
                }else if(game[2] == game[5] && game[5] == game[8]){
                    return game[2];
                }else if(game[3] == game[4] && game[4] == game[5]){
                    return game[3];
                }else if(game[6] == game[7] && game[7] == game[8]){
                    return game[6];
                }else if(game[0] == game[4] && game[4] == game[8]){
                    return game[0];
                }else if(game[2] == game[4] && game[4] == game[8]){
                    return game[2];
                }else{
                    return 0;
                }
            }

            int deciderPro(int *game){
                if (game[0] == game[1] && game[1] == game[2]){
                    if(game[0] == player){
                        return 10;
                    }else if(game[0] == opponent){
                        return -10;
                    }
                }else if(game[0] == game[3] && game[3] == game[6]){
                    if(game[0] == player){
                        return 10;
                    }else if(game[0] == opponent){
                        return -10;
                    }
                }else if(game[1] == game[4] && game[4] == game[7]){
                    if(game[1] == player){
                        return 10;
                    }else if(game[1] == opponent){
                        return -10;
                    }
                }else if(game[2] == game[5] && game[5] == game[8]){
                    if(game[2] == player){
                        return 10;
                    }else if(game[2] == opponent){
                        return -10;
                    }
                }else if(game[3] == game[4] && game[4] == game[5]){
                    if(game[3] == player){
                        return 10;
                    }else if(game[3] == opponent){
                        return -10;
                    }
                }else if(game[6] == game[7] && game[7] == game[8]){
                    if(game[6] == player){
                        return 10;
                    }else if(game[6] == opponent){
                        return -10;
                    }
                }else if(game[0] == game[4] && game[4] == game[8]){
                    if(game[0] == player){
                        return 10;
                    }else if(game[0] == opponent){
                        return -10;
                    }
                }else if(game[2] == game[4] && game[4] == game[8]){
                    if(game[2] == player){
                        return 10;
                    }else if(game[2] == opponent){
                        return -10;
                    }
                }
                    return 0;
            }

            int minmaxAlgorithm(int *game, int depth, bool isMax){
                if (deciderPro(game) == 10){
                    return 10;
                }
                if (deciderPro(game) == -10){
                    return -10;
                }
                if (!cellsLeft(game)){
                    return 0;
                }

                    if (isMax){
                        int best = -1000;
                        for(int i=0;i<9;i++){
                            if (game[i] < 0){
                                int tmp = game[i];
                                game[i] = player;
                                best = max(best, minmaxAlgorithm(game, depth+1, !isMax));
                                game[i] = tmp;
                            }
                        }
                        return best;
                    }else{
                        int best = 1000;
                        for(int i=0;i<9;i++){
                            if (game[i] < 0){
                                int tmp = game[i];
                                game[i] = opponent;
                                best = min(best, minmaxAlgorithm(game, depth+1, !isMax));
                                game[i] = tmp;
                            }
                        }
                        return best;
                        }
                    }

            int aiTurnPro(int *game, int opponent){
                int bestValue = -1000;
                int position = 0;
                for(int i=0;i<9;i++){
                    if(game[i] < 0){
                        game[i] = opponent;
                        /*
                        cout << game[0] << " " << game[1] << " " << game[2] << endl;
                        cout << game[3] << " " << game[4] << " " << game[5] << endl;
                        cout << game[6] << " " << game[7] << " " << game[8] << endl;
                        cout << endl;
                        */
                        int topValue = minmaxAlgorithm(game, 0, false);
                        cout << topValue << " " << i << endl;
                        game[i] = -6;
                        if (topValue >= bestValue){
                            cout << topValue << " " << i << endl;
                            bestValue = topValue;
                            position = i;
                        }
                    }
                }
                return position;
            }


            int aiTurnEasy(int *game){
                srand (time(NULL));
                int r = rand() % 10;
                while (true){
                    if (game[r] < 0){
                        break;
                    }else{
                        r = rand() % 10;
                    }
                }
                return r;
            }

            string decideEnd(int *game, int choice){
                if (decider(game) == 1){
                    if (choice == 1){
                        return "You win";
                    }else{
                        return "You lose";
                    }
                }else if(decider(game) == 2){
                    if (choice == 2){
                        return "You win";
                    }else{
                        return "You lose";
                    }
                }else{
                    return "Draw";
                }
            }

            int main()
            {
                //int game[9] = {1, 2, 1,2, 2, 1,-7, -8, -9};
                int game[9] = {-1, -2, -3,-4, -5, -6,-7, -8, -9};
                int choice;
                int opponent;
                int pos;
                int turns = 0;
                cout << "Type 1 for X or 2 for O to play as follows: " << endl;
                //cout << aiTurnPro(game);
                cin >> choice;
                player = choice;
                cout << "Playing as " << choice  << endl;
                if(choice == 1){
                    opponent = 2;
                }else{
                    opponent = 1;
                }
                while (cellsLeft(game)){
                    cout << game[0] << " " << game[1] << " " << game[2] << endl;
                    cout << game[3] << " " << game[4] << " " << game[5] << endl;
                    cout << game[6] << " " << game[7] << " " << game[8] << endl;
                    cout << endl;
                    cout << "Enter position" << endl;
                    cin >> pos;
                    game[pos] = choice;
                    turns++;
                    if (cellsLeft(game)){
                        pos = aiTurnPro(game, opponent);
                        cout << pos << endl;
                        game[pos] = opponent;
                        if(decideEnd(game, choice) == "You win" || decideEnd(game, choice) == "You lose"){
                            cout << game[0] << " " << game[1] << " " << game[2] << endl;
                            cout << game[3] << " " << game[4] << " " << game[5] << endl;
                            cout << game[6] << " " << game[7] << " " << game[8] << endl;
                            cout << endl;
                            cout << decideEnd(game, choice);
                            break;
                        }else{
                            turns++;
                        }
                    }
                }
                return 0;
            }
