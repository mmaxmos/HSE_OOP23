#include "Book.h"
#include "Page.h"
Book::Book() {pages = std::vector<Page>();}
Book::Book(float width, float height):
PaperProduct(width, height) {pages = std::vector<Page>();}

std::vector<Page> Book::getPages() const {return pages;}
std::vector<float> Book::getSizes() const {
    std::vector<float> sizes;
    sizes.push_back(getWidth());
    sizes.push_back(getHeight());
    sizes.push_back(pages.size());
    return sizes;
}

void Book::addPage(int number, float width, float height) {
    bool f = true;
    for (int i = 0; i < pages.size() and f; i++){
        if (pages[i].getNumber() == number)
            f = false;
    }
    if (f){
        Page page = Page(width, height, number);
        pages.push_back(page);
    }
}

void Book::addBlock(int number, float x1, float y1, float x2, float y2, std::string blockName) {
    int j = -1, f = 1;
    for (int i = 0; i < pages.size(); i++){
        if (pages[i].getNumber() == number){
            j = i;
        }
    }
    if (j >= 0) {
        if (pages[j].checkName(blockName) and x2 < pages[j].getWidth() and y1 < pages[j].getHeight() and
                        x1 < x2 and y1 > y2) {
            if(!pages[j].getBlocks().empty()) {
                for (int i = 0; i < pages[j].getBlocks().size() and f == 1; i++) {
                    if (!(pages[j].getBlocks()[i].getY1() < y2 or pages[j].getBlocks()[i].getX1() > x2 or
                          pages[j].getBlocks()[i].getY2() > y1 or pages[j].getBlocks()[i].getX2() < x1)) {
                        f = 0;
                        std::cout << "Overlapping blocks" << std::endl;
                    }
                }
            }
            if (f) {
                Block block = Block(x1, y1, x2, y2, blockName);
                pages[j].addBlock(block);
            }
        } else {
            std::cout << "The name already exists or coordinates bigger than page's sizes" << std::endl;
        }
    }
}

void Book::addBlock(int number, std::string name, float x1, float y1, float x2, float y2, std::string blockName) {
    int j = -1, f = 1;
    for (int i = 0; i < pages.size(); i++){
        if (pages[i].getNumber() == number){
            j = i;
        }
    }
    if (j>=0) {
        if (pages[j].checkName(blockName) and x2 < pages[j].searchBlock(name).getX2() and y2 > pages[j].searchBlock(name).getY2() and
            x1 > pages[j].searchBlock(name).getX1() and y1 < pages[j].searchBlock(name).getY1() and x1 < x2 and y1 > y2) {
            for (int i = 0; i < pages[j].searchBlock(name).getBlocks().size() and f == 1; i++) {
                if (!(pages[j].searchBlock(name).getBlocks()[i].getY1() < y2 or pages[j].searchBlock(name).getBlocks()[i].getX1() > x2 or
                        pages[j].searchBlock(name).getBlocks()[i].getY2() > y1 or pages[j].searchBlock(name).getBlocks()[i].getX2() < x1)) {
                    f = 0;
                    std::cout << "Overlapping blocks" << std::endl;
                }
            }
            if (f) {
                Block block = Block(x1, y1, x2, y2, blockName);
                pages[j].searchBlock(name).addBlock(block);
            }
        } else {
            std::cout << "The name already exists or coordinates bigger than block's sizes" << std::endl;
        }
    }
}

Page Book::operator[](int number) const {
    for (int i = 0; i < pages.size(); i++){
        if (pages[i].getNumber() == number){
            return pages[i];
        }
    }
}

void Book::deletePage(int number) {
    int j;
    for (int i = 0; i < pages.size(); i++){
        if (pages[i].getNumber() == number){
            j = i;
        }
    }
    pages.erase(pages.begin() + j);
}