#include <iostream>
#include "gtest/gtest.h"
#include "Header.h"
#include "Prime.h"


int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(int argc,char *argv[])
{
    //::testing::InitGoogleTest(&argc, argv);      
    //RUN_ALL_TESTS();    	     
    Prime *p=new Prime();
    p->GetPowerSet();
    p->vivod();
}
