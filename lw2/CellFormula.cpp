//
// Created by Maxim Mosalev on 12.10.2023.
//
#include <iostream>
#include "CellFormula.h"
CellFormula::CellFormula():
    Cell() {
    x1 = y1 = x2 = y2 = 0;
    operation = " ";
}
CellFormula::CellFormula(float ValueNumber, string ValueText,
                         int x1, int y1, int x2, int y2, std::string operation):
    Cell(ValueNumber, ValueText){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->operation = operation;
}
CellFormula::CellFormula(CellFormula &mn):
Cell((Cell&) mn){
    this->x1 = mn.x1;
    this->y1 = mn.y1;
    this->x2 = mn.x2;
    this->y2 = mn.y2;
    this->operation = mn.operation;
}
int CellFormula::getX1() const {return x1;};
int CellFormula::getY1() const {return y1;};
int CellFormula::getX2() const {return x2;};
int CellFormula::getY2() const {return y2;};
void CellFormula::setRange(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}
string CellFormula::getOperation() const {return operation;};
void CellFormula::setOperation(string operation) {this->operation = operation;}
string CellFormula::getResult(const Cell &c1, const Cell &c2){
    if (c1.getEmpty() == true or c2.getEmpty() == true)
    {   string v = "Error";
        setValueText(v);
        return getValueText();
    }
    else {
        if (getOperation() == "sum")
            setValueNumber(c1.getValueNumber() + c2.getValueNumber());
        if (getOperation() == "multiplication")
            setValueNumber(c1.getValueNumber() * c2.getValueNumber());
        if (getOperation() == "average")
            setValueNumber((c1.getValueNumber() + c2.getValueNumber())/2);
        return to_string(getValueNumber());
    }
}
void CellFormula::setEmpty() {
    Cell::setEmpty();
    x1 = y1 = x2 = y2 = 0;
    operation = " ";
}
void CellFormula::description() const {
    Cell::description();
    cout<<"Operation is " << getOperation() << endl;
    cout << "Range is (" << getX1() <<", " << getY1() <<") to ("
                        <<getX2() <<", " << getY2() << ")" << endl;
}