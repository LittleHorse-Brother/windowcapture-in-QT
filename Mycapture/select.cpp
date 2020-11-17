#include "select.h"
#include "ui_select.h"
#include <QtGui>

select::select(const QPixmap& Screen,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select),m_image(Screen)
{
    ui->setupUi(this);
    showFullScreen();


}


select::~select()
{
    delete ui;
}

void select::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    int w = width(), h = height();
    QPainter painter(this);
    //全屏展示窗口
    QRectF target(0,0, w,h);
    QRectF source(0,0, m_image.width(), m_image.height());
    painter.drawPixmap(target, m_image, source);
    //绘制

    int x = m_pos.x(), y = m_pos.y();
    //x -= 1; y -= 1;
    x += 1; y += 1;
    painter.setPen(QColor(250,200,0));
    painter.drawLine(0, y, w, y);
    painter.drawLine(x, 0, x, h);

    if(m_dragging)
    {
        QRect selected(m_start, m_pos);
        painter.setPen(QColor(250,30,30));
        painter.drawRect(selected);
//        QRect textRect(0,0, 50, 16);
//        textRect.moveCenter(selected.center());

//        painter.setBrush(QColor(30,30,30));
//        painter.drawRect(textRect);
//        painter.setPen(QColor(255,255,255));
//        char text[32];
//        sprintf(text, "%dx%d", selected.width(), selected.height());
//        painter.drawText(textRect, Qt::AlignCenter, text);
    }
}

void select::mouseMoveEvent(QMouseEvent *event)
{
    m_pos=event->pos();
    update();
}

void select::mousePressEvent(QMouseEvent *event)
{
    m_dragging=true;
    m_start=event->pos();
}

void select::mouseReleaseEvent(QMouseEvent *event)
{
    m_dragging=false;
    m_end=event->pos();
    selectsquare=QRect(m_start,m_end);
    accept();
}

