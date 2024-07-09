#ifndef PROJECT_OOP_PAPERPRODUCT_H
#define PROJECT_OOP_PAPERPRODUCT_H
#include <vector>

class PaperProduct {
private:
    float width, height;
public:
    PaperProduct();
    PaperProduct(float width, float height);
    PaperProduct(PaperProduct &) = default;
    virtual ~PaperProduct() = default;
    float getWidth() const;
    float getHeight() const;
    void setWidth(float width);
    void setHeight(float height);
    virtual std::vector<float> getSizes() const;
};


#endif //PROJECT_OOP_PAPERPRODUCT_H
