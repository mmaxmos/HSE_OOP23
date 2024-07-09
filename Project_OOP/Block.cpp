#include "Block.h"
Block::Block() {
    x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    name = "";
    blocks = std::vector<Block>();
}
Block::Block(float x1, float y1, float x2, float y2, std::string name) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->name = name;
    blocks = std::vector <Block>();
}
Block::Block(Block const &bl) {
    this->x1 = bl.x1;
    this->y1 = bl.y1;
    this->x2 = bl.x2;
    this->y2 = bl.y2;
    this->name = bl.name;
    for (int i = 0; i<bl.blocks.size(); i++){
        this->blocks.push_back(bl.blocks[i]);
    }
}

float Block::getX1() const {return x1;}
float Block::getY1() const {return y1;}
float Block::getX2() const {return x2;}
float Block::getY2() const {return y2;}

std::vector<Block> Block::getBlocks() const {return blocks;}
std::string Block::getName() const {return name;}
void Block::deleteInternalBlocks() {blocks.clear();}
void Block::addBlock(Block block) {blocks.push_back(block);}