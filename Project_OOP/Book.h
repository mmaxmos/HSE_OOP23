#ifndef PROJECT_OOP_BOOK_H
#define PROJECT_OOP_BOOK_H
#include "PaperProduct.h"
#include "Page.h"

class Book final : public PaperProduct {
private:
    std::vector<Page> pages;
public:
    Book();
    Book(float width, float height);
    ~Book() = default;
    void addBlock(int number, float x1, float y1, float x2, float y2, std::string blockName);
    void addBlock(int number, std::string name, float x1, float y1, float x2, float y2, std::string blockName);
    void addPage(int number, float width, float height);
    std::vector<float> getSizes() const override;
    std::vector<Page> getPages() const;
    Page operator[](int number) const;
    void deletePage(int number);
};


#endif //PROJECT_OOP_BOOK_H
