#ifndef PROJECT_OOP_PAGE_H
#define PROJECT_OOP_PAGE_H
#include "Block.h"
#include "PaperProduct.h"


class Page final : public PaperProduct{
private:
    int number;
    std::vector<Block> blocks;
    void check(std::string name, std::vector<Block> blocks, std::vector<bool>& b) const;
    void search(std::string name, std::vector<Block> blocks, std::vector<Block>& bl) const;
public:
    Page() = default;
    Page(float width, float height, int number);
    Page(Page const &pg);
    ~Page() = default;
    int getNumber() const;
    std::vector<Block> getBlocks();
    bool checkName(std::string name) const;
    Block searchBlock(std::string name);
    void deleteAllBlocks();
    void addBlock(Block block);
};

#endif //PROJECT_OOP_PAGE_H
