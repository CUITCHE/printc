//
//  main.swift
//  printc-swift
//
//  Created by hejunqiu on 2017/7/17.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

import Foundation

printc.print(text: "hello ", .bold, .printColor(.red, .back))
printc.print(text: "world!", .bold, .underline, .printColor(.navy, .fore))
printc.print(text: " original words.")
printc.print(text: " --printc\n", .obscure, .printColor(.purple, .fore))
