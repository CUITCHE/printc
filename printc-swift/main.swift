//
//  main.swift
//  printc-swift
//
//  Created by hejunqiu on 2017/7/17.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

import Foundation

// test printc method
printc.write("int ", .red).write("main(").write("int", .red).write(" argc, ").write("char ", .red).write("*", .purple)
.writeln("argv[]) {").write("    printf", .navy).write("(").write("\"Hello World!\"", .bold, .red).writeln(");").write("    return ", .red)
.write("0;\n}\n").writeln("\t\t\tby: printc", .obscure, .purple)

// test static method
printc.print(text: "Once upon a time....", marks: .white, .Purple)
printc.println(text: "Once upon a time", marks: .black, .Red)

// test take method
let buf = printc().writeln("take buffer test", .red).takeAssembleBuffer()
fputs(buf, stderr)
