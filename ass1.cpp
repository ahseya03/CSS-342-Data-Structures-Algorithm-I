#include<iostream>
#include<cassert>
#include "library.h"
using namespace std;

// Main driver
void Test1() {
    std::cout << "+++ Test1 ++++++" << std::endl;
    Library libs("UWB" );
    libs.AddBook( "Don Quixote" );
    libs.AddBook( "In Search of Lost Time" );
    libs.AddBook( "Ulysses" );
    libs.AddBook( "The Odyssey" );
    libs.AddBook("Harry Potter");
    libs.ListAllBooks();

// should generate already in Library message and return true
std::cout << "+  IsInLibrary" << std::endl;
    bool result = libs.IsInLibrary( "The Odyssey" );
    assert (result);
// cannot add book twice, result should be false
    std::cout << "+ AddBook" << std::endl;
    result = libs.AddBook( "The Odyssey" );
    assert (!result);
    std::cout << "+ RemoveBook" << std::endl;
    result = libs.RemoveBook( "The Odyssey" );
    assert (result);
// not in Library, result should be false
    result = libs.IsInLibrary( "The Odyssey" );
    assert (!result);
// cannot remove twice, result should be false
    result = libs.RemoveBook( "The Odyssey" );
    assert (!result);
}


void Test2()
{
    std::cout << "+++ Test2 ++++++ use << overload" << std::endl;
    Library libs("UWB" );
    libs.AddBook( "Don Quixote" );
    libs.AddBook( "In Search of Lost Time" );
    libs.AddBook( "Ulysses" );
    libs.AddBook( "The Odyssey" );
    libs.RemoveBook("Don Quixote");
    std::cout << libs << std::endl;

    libs.RemoveBook("Unkown Book");
    libs.AddBook("Anna Karenina");
    std::cout << libs << std::endl;
}

void Test3()
{
    std::cout << "+++ Test3 ++++++  edge cases" << std::endl;

    // Test to exceed size.  Expect not to crash
    std::cout << "+ Exceed size. Expect no crash" << std::endl;
    Library lib2("BigLibrary" );
    for (int i = 0; i < 101; i++)
    {
        std::string bookName = "book" + std::to_string(i);

        lib2.AddBook(bookName);
    }

    // Test to remove from empty Library.  Expect not to crash, return false.
    std::cout << "+ Remove from empty lib. Expect no crash" << std::endl;
    Library lib3("EmptyLibrary");
    bool ret = lib3.RemoveBook("anybook");
    assert(!ret);
    //std::cout << "Remove from empty lib, expect false: " << ret << std::endl;
}
void TestAll() {
    Test1();
    Test2();
    Test3();
    std ::cout << "\nSuccessfully completed all tests." << std ::endl;
}

int main() {
    TestAll();
    return 0 ;
}