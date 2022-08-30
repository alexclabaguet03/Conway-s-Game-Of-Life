#include <iostream>
#include "conway.h"



Conwayboard::Conwayboard(int def_height, int def_width){
    height = def_height;
    width = def_width;
    pos_tab_live = new position [height*width];
    pos_tab_die= new position [height*width];
    pos_nb_live = pos_nb_die = 0;
    tab = new char [width*height];
    for (int i=0; i< height*width; i++){
        tab[i] = '-';
    }
}

Conwayboard::~Conwayboard(){
    delete [] tab;
    delete [] pos_tab_live;
    delete [] pos_tab_die;
}

void Conwayboard::add_live_cell_at_pos(int add_height, int add_width){
    if(add_height >= height || add_height < 0 || add_width >= width || add_width <0) add_height = add_width = 0;
    tab[add_height*width + add_width] = 'X';
}

void Conwayboard::add_dead_cell_at_pos(int add_height, int add_width){
    if(add_height >= height || add_height < 0 || add_width >= width || add_width <0) add_height = add_width = 0;
    tab[add_height*width + add_width] = '-';
}

void Conwayboard::display(){
    std::cout << std::endl;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            std::cout << tab[i*width+j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Conwayboard::will_survive_or_live(int check_height, int check_width){
    int count = 0;
    if(valid_pos(check_height, check_width-1) &&  tab[check_height*width + check_width-1] == 'X')count++;
    if(valid_pos(check_height, check_width+1) &&  tab[check_height*width + check_width+1] == 'X')count++;
    if(valid_pos(check_height-1, check_width) &&  tab[(check_height-1)*width + check_width] == 'X')count++;
    if(valid_pos(check_height-1, check_width-1) &&  tab[(check_height-1)*width + check_width-1] == 'X')count++;
    if(valid_pos(check_height-1, check_width+1) &&  tab[(check_height-1)*width + check_width+1] == 'X')count++;
    if(valid_pos(check_height+1, check_width) &&  tab[(check_height+1)*width + check_width] == 'X')count++;
    if(valid_pos(check_height+1, check_width-1) &&  tab[(check_height+1)*width + check_width-1] == 'X')count++;
    if(valid_pos(check_height+1, check_width+1) &&  tab[(check_height+1)*width + check_width+1] == 'X')count++;
    if(tab[check_height*width + check_width] == 'X' && (count == 2 || count == 3)) return 1;
    if(tab[check_height*width + check_width] == '-' && count == 3) return 1;
    return 0;
}

void Conwayboard::iterate(){
    for(int i=0; i< height; i++){
        for(int j=0; j<width; j++){
            if (will_survive_or_live(i,j)) {pos_tab_live[pos_nb_live].i=i; pos_tab_live[pos_nb_live++].j = j;}
            else {pos_tab_die[pos_nb_die].i=i; pos_tab_die[pos_nb_die++].j = j;}
        }
    }
    for(int k=0; k<pos_nb_live; k++){
        add_live_cell_at_pos(pos_tab_live[k].i, pos_tab_live[k].j);
    }
    for(int p=0; p<pos_nb_die; p++){
        add_dead_cell_at_pos(pos_tab_die[p].i, pos_tab_die[p].j);
    }
    delete [] pos_tab_live;
    delete [] pos_tab_die;
    pos_tab_live = new position [height*width];
    pos_tab_die = new position [height*width];
    pos_nb_live = pos_nb_die = 0;
}

int Conwayboard::valid_pos(int check_height, int check_width){
    if(check_height <0 || check_height >=height || check_width >= width || check_width < 0) return 0;
    return 1;
}