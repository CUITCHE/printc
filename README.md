# printc
Print text with color on command console. (Only support UNIX-like platform)

Provide two program language version: Swift and C++.

# Usage

1. Prints a single text by static function: `printc.print(text:marks:)` in Swift.

```swift
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
```
 Or `printcolor::printc::print<marks...>(text)` in C++.

```c++
printcolor::printc::print<red, Navy>("Print color in C++");
```

2. Assemble texts and print them before printc object destroying.
```swift
printc.write("int ", .red)._("main(")._("int", .red)._(" argc, ")
._("char ", .red)._("*", .purple)._("argv[]) {\n")._("    printf", .navy)
._("(")._("\"Hello World!\"", .bold, .red)._(");\n")._("    return ", .red)
._("0;\n}\n")._("\t\t\tby: printc\n", .obscure, .purple)
```
Or `printcolor::printc().write<marks...>(text)` in C++.

```c++
printcolor::printc().write<red>("int").write(" main(").write<red>("int")
.write(" argc, ").write<red>("char ").write<purple>("*").write("argv[]) {\n")
.write<navy>("    printf").write<bold, red>("\"Hello World!\"").write(");\n")
.write<red>("    return ").write("0;\n}\n").write<obscure, purple>("\t\t\tby: printc\n");
```



Looks like:

![prints](img/prints.png)

# LICENSE

The MIT LICENSE.
