#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");
    hello.resize(100, 30);
    hello.setFont(QFont("Arial", 18, QFont::Bold));
    hello.setGeometry(400, 200, 180, 40);

    hello.show();
    return app.exec();
}
