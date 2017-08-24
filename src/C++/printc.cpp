//
//  printc.cpp
//  printc
//
//  Created by hejunqiu on 2017/8/24.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

#include "printc.hpp"
#include <sys/ioctl.h>
#include <unistd.h>
#include <mutex>
#include <functional>

using namespace std;

namespace printcolor {

    template<class _Tp>
    class Array: public vector<_Tp> { };

    template<>
    class Array<string>: public vector<string> {
    public:
        string joined(const char *separator = "") {
            if (this->size() == 0) {
                return "";
            }
            string str = this->front();
            auto begin = this->begin();
            auto end = this->end();
            while (++begin < end) {
                str.append(separator).append(*begin);
            }
            return str;
        }
    };

    template<class Bound>
    struct CountableRange {
        using Element = Bound;
        Bound lowerBound;
        Bound upperBound;

        template<class T>
        Array<T> map(const function<T(Bound)> &transform) {
            Bound tmp = lowerBound - 1;
            Array<T> array;
            while (++tmp < upperBound) {
                array.push_back(transform(tmp));
            }
            return array;
        }
        
    };

    struct ProgressBar {
        static ProgressBar *progressBar;
        const bool drawInMultiThread;
        const char symbol = '#';
        const int columns;
        mutex mtx;

        ProgressBar(bool drawInMultiThread = true)
        :columns(_columns())
        ,drawInMultiThread(drawInMultiThread) { printc::console::hideCursor(true); }

        ~ProgressBar() {
            printc::console::hideCursor(false);
        }

        void draw(int progress) {
            if (columns > 10) {
                string progressString = to_string(progress).append(1, '%');
                size_t rest = columns - progressString.size();
                float rate = progress / 100.0;
                int done = rest * rate;
                lock_guard<mutex> lock(mtx);
                printc::print("\r");
                // print done
                printc::print(CountableRange<int>{0, done}.map<string>([](int bound) { return "#"; }).joined().c_str());
                printc::print(CountableRange<int>{0, static_cast<int>((rest - done))}.map<string>([](int bound) { return " "; }).joined().append(progressString).c_str());
                if (progress >= 100) {
                    delete progressBar;
                    progressBar = nullptr;
                }
            }
        }

    private:
        static int _columns() {
            int c = printc::console::colunms();
            if (c > 80) c = 80;
            return c;
        }
    };
    ProgressBar *ProgressBar::progressBar = nullptr;
    static mutex initializeMutex;
}

FILE *printcolor::printc::console::IORedirector = stderr;

void printcolor::printc::console::hideCursor(bool hide)
{
    hide ? fputs("\033[?25l", console::IORedirector) : fputs("\033[?25h", console::IORedirector);
}

int printcolor::printc::console::colunms()
{
    winsize size;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) >= 0) {
        return size.ws_col;
    }
    return 0;
}

int printcolor::printc::console::rows()
{
    winsize size;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) >= 0) {
        return size.ws_row;
    }
    return 0;
}

void printcolor::printc::console::drawProgressBar(int progress, bool drawInMultiThread/* = false*/)
{
    if (ProgressBar::progressBar == nullptr) {
        if (drawInMultiThread) {
            lock_guard<mutex> lock(initializeMutex);
            if (ProgressBar::progressBar == nullptr) {
                ProgressBar::progressBar = new ProgressBar(true);
            }
        } else {
            ProgressBar::progressBar = new ProgressBar(false);
        }
    }
    ProgressBar::progressBar->draw(progress);
}
