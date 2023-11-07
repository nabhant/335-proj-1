#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

int main(){



    int imgData[80] = {20};


    PointCard card1;
    card1.setType(POINT_CARD);
    card1.setInstruction("20");
    card1.setImageData(imgData);
    card1.Print();
}