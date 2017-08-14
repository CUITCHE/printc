//
//  printc.hpp
//  printc
//
//  Created by hejunqiu on 2017/8/8.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

#ifndef PRINTC_HPP
#define PRINTC_HPP

#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <array>

namespace printcolor {

    enum Mark: int {
        /// All attributes off
        closeAll = 0,
        /// Bold on
        bold,
        /// Blur the text. May be not available.
        obscure,
        /// Italic font. May be not available.
        italic,
        /// Underscore (on monochrome display adapter only)
        underline,
        /// Blink on
        flash,
        /// Blink on quickly. May be not available.
        twinkle,
        /// Reverse video on
        exchangeFB,
        /// Concealed on
        hidden,

        /// Foreground colors
        black = 30, red, green, yellow, blue, purple, navy, white,
        /// Background colors
        Black = 40, Red, Green, Yellow, Blue, Purple, Navy, White
    };

    static inline const char *mark2str(Mark mark) {
        switch (mark) {
            case closeAll:   return "0;";
            case bold:       return "1;";
            case obscure:    return "2;";
            case italic:     return "3;";
            case underline:  return "4;";
            case flash:      return "5;";
            case twinkle:    return "6;";
            case exchangeFB: return "7;";
            case hidden:     return "8;";

            case black:  return "30;";
            case red:    return "31;";
            case green:  return "32;";
            case yellow: return "33;";
            case blue:   return "34;";
            case purple: return "35;";
            case navy:   return "36;";
            case white:  return "37;";

            case Black:  return "40;";
            case Red:    return "41;";
            case Green:  return "42;";
            case Yellow: return "43;";
            case Blue:   return "44;";
            case Purple: return "45;";
            case Navy:   return "46;";
            case White:  return "47;";
            default:    return "";
        }
    }

    struct printc {
        std::string buf;
    public:
        ~printc() { if (buf.size() != 0) fputs(buf.c_str(), stderr); }

        template<Mark ...marks>
        inline printc& write(const char *text);

        template<Mark ...marks>
        inline printc& writeln(const char *text);

        template<typename... Args>
        inline printc& write(Args&& ...args);

        template<Mark ...marks>
        static inline void print(const char *text);

        template<Mark ...marks>
        static inline void println(const char *text);

        std::string takeAssembleBuffer() { auto buf = this->buf; this->buf.clear(); return buf; }

    private:
        template<size_t arraySize>
        static void assemble(const char *text, std::string &buf, const std::array<Mark, arraySize> &marks, bool appendNewline = false);
    };

    template<Mark ...marks>
    inline printc& printc::write(const char *text)
    {
        printc::assemble<sizeof...(marks)>(text, this->buf, { std::forward<Mark>(marks)... });
        return *this;
    }

    template<Mark ...marks>
    inline printc& printc::writeln(const char *text)
    {
        printc::assemble<sizeof...(marks)>(text, this->buf, { std::forward<Mark>(marks)... }, true);
        return *this;
    }

    template<typename... Args>
    inline printc& printc::write(Args&& ...args)
    {
        for (auto text: { std::forward<Args>(args)... }) {
            buf.append(text);
        }
        return *this;
    }

    template<Mark ...marks>
    inline void printc::print(const char *text)
    {
        std::string buffer;
        assemble<sizeof...(marks)>(text, buffer, { std::forward<Mark>(marks)... });
        fputs(buffer.c_str(), stderr);
    }

    template<Mark ...marks>
    inline void printc::println(const char *text)
    {
        std::string buffer;
        assemble<sizeof...(marks)>(text, buffer, { std::forward<Mark>(marks)... }, true);
        fputs(buffer.c_str(), stderr);
    }
    
    template<size_t arraySize>
    void printc::assemble(const char *text ,std::string &buf, const std::array<Mark, arraySize> &marks, bool appendNewline/* = false*/)
    {
        if (arraySize == 0) {
            appendNewline ? buf.append(text).append(1, '\n') : buf.append(text);
            return;
        }
        buf.append("\033[");
        for (auto mark: marks) {
            buf.append(mark2str(mark));
        }
        buf.pop_back();
        buf.append(1, 'm').append(text);
        appendNewline ? buf.append("\033[0m\n") : buf.append("\033[0m");
    }
    
}
#endif /* printc_hpp */
