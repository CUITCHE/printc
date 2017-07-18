# printc
Print text with color on command console. (Only support UNIX-like platform)

# Usage

1. Prints a single text by static function: `printc.print(text:marks:)`.

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

2. Save text and print it before printc object destroying.
```swift
printc.write("int ", .red)._("main(")._("int", .red)._(" argc, ")
._("char ", .red)._("*", .purple)._("argv[]) {\n")._("    printf", .navy)
._("(")._("\"Hello World!\"", .bold, .red)._(");\n")._("    return ", .red)
._("0;\n}\n")._("\t\t\tby: printc\n", .obscure, .purple)
```
Looks like:

<font color=red>int</font> main(<font color=red>int</font> argc, <font color=red>char</font> <font color=purple>*</font>argv[]) {</br>
&nbsp;&nbsp;&nbsp;&nbsp;<font color=navy>printf</font>(<b><font color=red>"Hello World!"</font></b>);</br>
&nbsp;&nbsp;&nbsp;&nbsp;<font color=red>return</font> 0;</br>
}</br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color=purple>by: printc</font>

# LICENSE

The MIT LICENSE.