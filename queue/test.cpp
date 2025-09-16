#include <iostream>
using namespace std;

struct Player {
    string name;
    int health;

    void takeDamage(int amount) {
        health -= amount;
    }

};


int main() {

    Player* player = new Player{"Gandalf", 100};


    (*player).health = 90;


    player->health = 50



    return 0;
}