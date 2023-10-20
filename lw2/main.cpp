#include <iostream>
#include <assert.h>
#include <string>
#include "cell.h"
#include "CellFormula.h"
using namespace std;
int main(){
    float valueNumber = 10;
    string valueText = "hh";
    Cell c;
    c = Cell();
    assert(c.getValueNumber() == 0 &&
           c.getValueText() ==  " " &&
           c.getEmpty() == true);
    c = Cell(valueNumber, valueText);
    assert(c.getValueNumber() == valueNumber &&
           c.getValueText() ==  valueText &&
           c.getEmpty() == false);
    Cell cCopy;
    cCopy = Cell(c);
    assert(cCopy.getValueNumber() == valueNumber &&
           cCopy.getValueText() ==  valueText &&
           cCopy.getEmpty() == false);

    c = Cell();
    valueNumber = 11;
    valueText = " ";
    c.setValueNumber(valueNumber);
    c.setValueText(valueText);
    assert(c.getValueNumber() == valueNumber &&
           c.getValueText() ==  valueText &&
           c.getEmpty() == false);


    CellFormula cellForm;
    cellForm = CellFormula();
    assert(
            cellForm.getValueText() == " " &&
            cellForm.getValueNumber() == 0 &&
            cellForm.getEmpty() == true &&
            cellForm.getX1() == 0 &&
            cellForm.getY1() == 0 &&
            cellForm.getX1() == 0 &&
            cellForm.getY2() == 0 &&
            cellForm.getOperation() == " "
    );
    int x1, y1, x2, y2;
    string operation = "average";
    x1 = 1, y1 = 2, x2 = 1, y2 = 5;
    cellForm.setRange(x1, y1, x2, y2);
    cellForm.setOperation(operation);
    assert(
            cellForm.getX1() == x1 &&
            cellForm.getY1() == y1 &&
            cellForm.getX1() == x2 &&
            cellForm.getY2() == y2 &&
            cellForm.getOperation() == operation
            );
    cellForm.setEmpty();        //test overloaded function
    assert(
            cellForm.getValueNumber() == 0 &&
            cellForm.getValueText() ==  " " &&
            cellForm.getEmpty() == true &&
            cellForm.getX1() == 0 &&
            cellForm.getY1() == 0 &&
            cellForm.getX1() == 0 &&
            cellForm.getY2() == 0 &&
            cellForm.getOperation() == " "
            );
    cellForm = CellFormula(valueNumber, valueText, x1, y1, x2, y2, operation);
    assert(
            cellForm.getValueNumber() == valueNumber &&
            cellForm.getValueText() == valueText &&
            cellForm.getEmpty() == false &&
            cellForm.getX1() == x1 &&
            cellForm.getY1() == y1 &&
            cellForm.getX1() == x2 &&
            cellForm.getY2() == y2 &&
            cellForm.getOperation() == "average"
            );
    CellFormula cellFormCopy;
    cellFormCopy = CellFormula(cellForm);
    assert(cellFormCopy.getValueNumber() == cellForm.getValueNumber() &&
           cellFormCopy.getValueText() ==  cellForm.getValueText() &&
           cellFormCopy.getEmpty() == false &&
           cellFormCopy.getX1() == cellForm.getX1() &&
           cellFormCopy.getY1() == cellForm.getY1() &&
           cellFormCopy.getX1() == cellForm.getX2() &&
           cellFormCopy.getY2() == cellForm.getY2() &&
           cellFormCopy.getOperation() == cellForm.getOperation());
    Cell c1, c2;
    c1 = Cell(5, " ");
    c2 = Cell(2, " ");
    cellForm.setOperation("sum");
    assert(cellForm.getResult(c1, c2) == "7");
    c1.setEmpty();
    string v = "Error";
    cellForm.setValueText(v);
    assert(cellForm.getResult(c1, c2) == v);
    cout<<"All testes has completed successfully"<<endl;
    return 0;
}
