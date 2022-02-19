#include <iostream>
#include "gtest/gtest.h"
#include "Header.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(int argc,char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);      
    RUN_ALL_TESTS();    	        
    //std::cout << "Hello World!\n";
}
