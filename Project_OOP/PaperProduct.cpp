#include "PaperProduct.h"

PaperProduct::PaperProduct() {
    width = 0;
    height = 0;
}
PaperProduct::PaperProduct(float width, float height) {
    this->width = width;
    this->height = height;
}


float PaperProduct::getWidth() const {return width;}
float PaperProduct::getHeight() const {return height;}
void PaperProduct::setWidth(float width) {this->width = width;}
void PaperProduct::setHeight(float height) {this->height = height;}

std::vector<float> PaperProduct::getSizes() const {
    std::vector<float> sizes;
    sizes.push_back(getWidth());
    sizes.push_back(getHeight());
    return sizes;
}