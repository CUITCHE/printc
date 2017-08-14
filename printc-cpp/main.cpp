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
    // test printc method
    printc().write<red>("int").write(" main(").write<red>("int").write(" argc, ").write<red>("char ").write<purple>("*")
    .writeln("argv[]) {").write<navy>("    printf").write<bold, red>("\"Hello World!\"").writeln(");")
    .write<red>("    return ").write("0;\n}\n").writeln<obscure, purple>("\t\t\tby: printc");

    // test static method
    printc::print<Purple, white>("Once upon a time....");
    printc::println<Red, black>("Once upon a time");

    // test take method
    auto buf = printc().writeln<red>("take buffer test").takeAssembleBuffer();
    fputs(buf.c_str(), stderr);
    return 0;
}
