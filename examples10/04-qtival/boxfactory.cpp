#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <iostream>
#include <memory>

using namespace std;

#include "qt_ival_box.h"
#include "text_ival_box.h"

unique_ptr<Ival_box> ivalBoxFactory()
{
    if (getenv("DISPLAY"))
        return make_unique<QT_ival_slider>();
    else
        return make_unique<Text_ival_box>();
}
