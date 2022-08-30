#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "conway.h"


main(){
    int height=0, width=0;
    std::cout << "Enter the size of the board (height & width):" << std::endl;
    std::cout << "height: ";
    std::cin >> height;
    std::cout << "width: ";
    std::cin >> width;
    Conwayboard game_tab(height,width);
    std::cout << "Let's input the live cell at t=0!" << std::endl;
    while(1){
        int i=0, j=0;
        char answer[1];
        std::cout << "height position: ";
        std::cin >> i;
        std::cout << "width position: ";
        std::cin >> j;
        game_tab.add_live_cell_at_pos(i,j);
        game_tab.display();
        std::cout << "Do you want to continue input live cells? ('Y' or 'y' for yes and 'N' or 'n' for no): ";
        std::cin >> answer[0];
        if (answer[0] == 'N' || answer[0] == 'n'){
            break;
        }
    }
    int nb_iteration = 0;
    std::cout << "How many iteration you want to do?: ";
    std::cin >> nb_iteration;
    int count = 0;
    while(count <=nb_iteration){
        Sleep(400);
        game_tab.iterate();
        game_tab.display();
        count++;
    }
}