//
// Created by Maxim Mosalev on 12.10.2023.
//

#ifndef OOPLW2_CELLFORMULA_H
#define OOPLW2_CELLFORMULA_H

#include "cell.h"
#include <string>

class CellFormula : public Cell {
private:
    int x1, y1, x2, y2;
    string operation;
public:
    CellFormula();
    CellFormula(float ValueNumber, string ValueText, int x1, int y1, int x2, int y2, string operation);
    CellFormula(CellFormula &mn);

    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;
    string getResult(const Cell &c1, const Cell &c2);
    void setRange(int x1, int y1, int x2, int y2);
    string getOperation() const;
    void  setOperation(string operation);
    void setEmpty() override;
    void description() const override;
};

#endif //OOPLW2_CELLFORMULA_H
