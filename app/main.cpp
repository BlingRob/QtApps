#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};

    QWidget w;
    w.show();

    connect(&w, QWidget::
            &app, QApplication::exit);
    
    return app.exec();
}
