#include "ival_box.h"

#include <iostream>
using namespace std;

#include <QtGui>

class QT_ival_slider : public Ival_box // interface
    ,
                       protected QDialog // implementation
{
  private:
    int lastval;
    QSlider* slider;

  public:
    QT_ival_slider(QWidget* parent = 0) : QDialog(parent), lastval(-1)
    {
        slider = new QSlider(Qt::Horizontal);
        slider->setRange(0, 99);
        slider->setValue(0);

        QPushButton* qb = new QPushButton("OK", this);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(slider);
        layout->addWidget(qb);
        setLayout(layout);
        QObject::connect(qb, SIGNAL(clicked()), this, SLOT(accept()));
    };

    virtual int get_value()
    {
        return slider->sliderPosition();
    };
    virtual void set_value(int i)
    {
        slider->setSliderPosition(i);
    };
    virtual void reset_value(int i)
    {
        slider->setSliderPosition(i);
        lastval = i;
    };
    virtual void prompt()
    {
        show();
        exec();
        hide();
    };
    virtual bool was_changed() const
    {
        return slider->sliderPosition() != lastval;
    };
    virtual ~QT_ival_slider(){};
};
