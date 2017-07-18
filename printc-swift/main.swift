//
//  main.swift
//  printc-swift
//
//  Created by hejunqiu on 2017/7/17.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

import Foundation

printc.print(text: "int ", marks: .red)
printc.print(text: "main(")
printc.print(text: "int", marks: .red)
printc.print(text: " argc, ")
printc.print(text: "char ", marks: .red)
printc.print(text: "*", marks: .purple)
printc.print(text: "argv[]) {\n")
printc.print(text: "    printf", marks: .navy)
printc.print(text: "(")
printc.print(text: "\"Hello World!\"", marks: .bold, .red)
printc.print(text: ");\n")
printc.print(text: "    return ", marks: .red)
printc.print(text: "0;\n}\n")
printc.print(text: "\t\t\tby:printc\n\n", marks: .obscure, .purple)

printc.write("int ", .red)._("main(")._("int", .red)._(" argc, ")._("char ", .red)._("*", .purple)
._("argv[]) {\n")._("    printf", .navy)._("(")._("\"Hello World!\"", .bold, .red)._(");\n")._("    return ", .red)
._("0;\n}\n")._("\t\t\tby: printc\n", .obscure, .purple)
