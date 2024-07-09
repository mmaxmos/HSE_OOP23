#include <iostream>
#include <assert.h>
#include "Book.h"
int main() {
    PaperProduct pp;
    pp = PaperProduct();
    assert(pp.getHeight() == 0 and pp.getWidth()==0);
    Book book;
    book = Book();
    assert(book.getPages().empty());
    Page page;
    page = Page();
    assert(page.getNumber() == 0 and page.getBlocks().empty());
    Block block;
    block = Block();
    assert(block.getName()=="" and block.getBlocks().empty() and
            block.getX1() == 0 and block.getY1() == 0 and
            block.getX2() == 0 and block.getY2() == 0);
    book = Book(7, 10);
    book.addPage(1, 20, 40);
    assert(book.getPages().size() == 1);
    assert(book[1].getNumber() == 1);

    book.addPage(2, 20, 40);
    assert(book.getPages().size() == 2);
    book.addBlock(1, 1, 4, 5, 1, "Text");
    assert(book[1].getBlocks()[0].getName() == "Text");
    book.addBlock(1, 9, 4, 12, 1, "TextWithPicture2");
    book.addPage(1, 20, 40);
    book.addBlock(2, 10, 4, 12, 1, "Text3");
    book.addBlock(1, 0.5, 4, 6, 1, "Text");

    book.addBlock(1, "Text", 2, 3, 4, 2, "TextWitPicture2");
    book.addBlock(1, 10, 4, 12, 1, "Text4");
    assert(book[1].getBlocks()[1].getName() == "TextWithPicture2");

    book.deletePage(1);
    book.deletePage(2);
    assert(book.getPages().size() == 0);

    std::cout << "All tests are passed successfully" << std::endl;
    return 0;
}
