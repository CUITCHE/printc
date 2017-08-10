//
//  main.cpp
//  printc-cpp
//
//  Created by hejunqiu on 2017/8/8.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

#include "printc.hpp"

using namespace printcolor;

int main(int argc, const char * argv[]) {
    printc().write<red>("int").write(" main(").write<red>("int").write(" argc, ").write<red>("char ").write<purple>("*")
    .write("argv[]) {\n").write<navy>("    printf").write<bold, red>("\"Hello World!\"").write(");\n")
    .write<red>("    return ").write("0;\n}\n").write<obscure, purple>("\t\t\tby: printc\n");
    return 0;
}
