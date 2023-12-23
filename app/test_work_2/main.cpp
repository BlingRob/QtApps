#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QObject>
#include <QRandomGenerator>

#include <QPoint>
#include <QMouseEvent>

#include <list>

class PointerRandomizer : public QWidget
{
    Q_OBJECT
    signals:
    void mousePressed( const QPoint& );

    public:

    PointerRandomizer(QWidget *parent = nullptr);

    protected:

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    private:

    std::list<QPoint> points_;

    const size_t maxSize_ = 800;
    const size_t maxPoints_ = 50;
};

PointerRandomizer::PointerRandomizer(QWidget *parent)
{
    setWindowTitle(tr("Pointer randomizer"));

    resize(maxSize_, maxSize_);

    //QRandomGenerator generator(0, maxSize_);

    for(size_t i = 0; i < maxPoints_; ++i)
    {
        points_.push_back({static_cast<int>(QRandomGenerator::global()->bounded(maxSize_)), static_cast<int>(QRandomGenerator::global()->bounded(maxSize_))});
    }
}

void PointerRandomizer::mousePressEvent(QMouseEvent *event)
{
    points_.push_back(event->pos());
    emit mousePressed( points_.back() );
    this->repaint();
}

void PointerRandomizer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(const auto& point: points_)
    {
        painter.drawEllipse(point, 16, 16);
    }
}

#include "main.moc"

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};

    PointerRandomizer randomizer;
    randomizer.show();

    return app.exec();
}
