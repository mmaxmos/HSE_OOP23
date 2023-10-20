//
// Created by Maxim Mosalev on 12.10.2023.
//
#include <iostream>
#include "cell.h"
#include <string>
Cell::Cell(){
    valueNumber = 0;
    valueText = " ";
    empty = true;
}
Cell::Cell(float valueNumber, string valueText){
    this->valueNumber = valueNumber;
    this->valueText = valueText;
    empty = false;
}
Cell::Cell(Cell &mn){
    this->valueNumber = mn.valueNumber;
    this->valueText = mn.valueText;
    this->empty = mn.empty;
}

void Cell::setValueNumber(int valueNumber){
    this->valueNumber = valueNumber;
    valueText = " ";
    empty = false;
}
void Cell::setValueText(string &valueText){
    this->valueText = valueText;
    empty = false;
}
void Cell::setEmpty(){
    empty = true;
    valueNumber = 0;
    valueText = " ";
}

int Cell::getValueNumber() const {return valueNumber;}
string Cell::getValueText() const {return valueText;}
bool Cell::getEmpty() const{return empty;}
void Cell::description() const{
    if (getEmpty() == true)
        std::cout<<"Meaning of cell is empty."<<std::endl;
    else
        if (getValueText() == " ")
            std::cout << "Number = " << getValueNumber() << std::endl;
        else
            std::cout << "Text = " << getValueText() << std::endl;
}
