//
//  printc.swift
//  printc
//
//  Created by hejunqiu on 2017/7/17.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

import Foundation

public enum printc {
    public enum Mark {
        case closeAll, bold, obscure, italic, underline, flash, twinkle, exchangeFB, hidden

        public enum Ground: UInt {
            case fore = 30, back = 40
        }
        public enum Color: UInt {
            case black = 0, red, green, yellow, blue, purple, navy, white
        }
        case printColor(Color, Ground)

        public var rawVal: UInt {
            switch self {
            case .closeAll: return 0
            case .bold: return 1
            case .obscure: return 2
            case .italic: return 3
            case .underline: return 4
            case .flash: return 5
            case .twinkle: return 6
            case .exchangeFB: return 7
            case .hidden: return 8
            case let .printColor(color, ground): return color.rawValue + ground.rawValue
            }
        }
    }

    /// Print the text with marks
    ///
    /// - Parameters:
    ///   - text: The text will be modify some color or other mark by marks
    ///   - marks: see enum `Mark`
    public static func print(text: String, _ marks: Mark...) {
        if marks.count == 0 {
            printImpl(text, text.lengthOfBytes(using: .utf8), false)
            return
        }

        let buffer = assemble(text: text, with: marks)
        printImpl(buffer, buffer.lengthOfBytes(using: .utf8), true)
    }

    fileprivate static func assemble(text: String, with marks: [Mark]) -> String {
        var buffer = "";
        for m in marks {
            buffer.append("\(m.rawVal);")
        }
        buffer.remove(at: buffer.index(before: buffer.endIndex))
        buffer.append("m\(text)")
        return buffer
    }
}
