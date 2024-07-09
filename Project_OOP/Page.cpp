#include "Page.h"

Page::Page(float width, float height, int number):
        PaperProduct(width, height){
    this->number = number;
    blocks = std::vector<Block>();
}
Page::Page(Page const &pg) {
    this->number = pg.number;
    setWidth(pg.getWidth());
    setHeight(pg.getHeight());
    for (int i = 0; i<pg.blocks.size(); i++){
        this->blocks.push_back(pg.blocks[i]);
    }
}

int Page::getNumber() const {return number;}
std::vector<Block> Page::getBlocks() {return blocks;}

void Page::check(std::string name, std::vector<Block> blocks, std::vector<bool>& b) const{
    for (int i = 0; i < blocks.size(); i++){
        if (blocks[i].getName() == name) {b.push_back(false);}
        if (!blocks[i].getBlocks().empty()){
            check(name, blocks[i].getBlocks(), b);
        }
    }
}
bool Page::checkName(std::string name) const {
    std::vector<bool> b = std::vector<bool>();
    check(name, blocks, b);
    if (b.empty()){return true;}
    else{
        return false;
    }
}

void Page::search(std::string name, std::vector<Block> blocks, std::vector<Block>& bl) const{
    for (int i = 0; i < blocks.size(); i++){
        if (blocks[i].getName() == name) {bl.push_back(blocks[i]);}
        if (!blocks[i].getBlocks().empty()){
            search(name, blocks[i].getBlocks(), bl);
        }
    }
}

Block Page::searchBlock(std::string name) {
    std::vector<Block> bl = std::vector<Block>();
    search(name, blocks, bl);
    if (bl.empty()){
        std::cout << "Wrong name" << std::endl;
    }
    else{
        return bl[0];
    }
}


void Page::deleteAllBlocks() {
    blocks.clear();
}

void Page::addBlock(Block block) {blocks.push_back(block);}