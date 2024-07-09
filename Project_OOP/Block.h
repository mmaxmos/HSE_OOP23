#ifndef PROJECT_OOP_BLOCK_H
#define PROJECT_OOP_BLOCK_H
#include <iostream>
#include <vector>

class Block {
private:
    float x1, y1, x2, y2;
    std::string name;
    std::vector<Block> blocks;
public:
    Block();
    Block(float x1, float y1, float x2, float y2, std::string name);
    Block(Block const &bl);
    ~Block() = default;
    float getX1() const;
    float getY1() const;
    float getX2() const;
    float getY2() const;
    std::vector<Block> getBlocks() const;
    std::string getName() const;
    void deleteInternalBlocks();
    void addBlock(Block block);
};


#endif //PROJECT_OOP_BLOCK_H
