#ifndef CONWAY_H
#define CONWAY_H



class position{
    public:
    position(int a=0, int b=0): i(a), j(b) {}; 
    int i;
    int j;
};


class board{
    public:
    virtual void display() = 0;
};

class Conwayboard  : public board{
    public:
    Conwayboard(int=0, int=0);
    ~Conwayboard();
    void add_live_cell_at_pos(int=0,int=0);
    void add_dead_cell_at_pos(int=0,int=0);
    void display();
    int will_survive_or_live(int=0,int=0);
    void iterate();
    int valid_pos(int=0,int=0);
    private:
    char * tab;
    int height;
    int width;
    position * pos_tab_live;
    position * pos_tab_die;
    int pos_nb_live;
    int pos_nb_die;
};


#endif