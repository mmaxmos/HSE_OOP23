//
// Created by Maxim Mosalev on 12.10.2023.
//

#ifndef OOPLW2_CELL_H
#define OOPLW2_CELL_H

#include <string>

using namespace std;

class Cell{
private:
    float valueNumber;
    string valueText;
    bool empty;

public:
    Cell();
    Cell(float valueNumber, string valueText);
    Cell(Cell &mn);

    void setValueNumber(int valueNumber);
    void setValueText(string &valueText);
    int getValueNumber() const;
    string getValueText() const;
    bool getEmpty() const;
    virtual void setEmpty();
    virtual void description() const;

};

#endif //OOPLW2_CELL_H
