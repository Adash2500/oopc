#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <iostream>

using namespace std;

#include "qt_ival_box.h"
#include "text_ival_box.h"

void fun();

int main(int argc, char* argv[])
{
    if (getenv("DISPLAY")) {
        QApplication q(argc, argv);
        fun();
    }
    else {
        fun();
    }
};
