#ifndef SELECT_H
#define SELECT_H

#include <QDialog>


namespace Ui {
class select;
}

class select : public QDialog
{
    Q_OBJECT

public:
    explicit select(const QPixmap& Screen,QWidget *parent = nullptr);
    ~select();
private:
    virtual void	paintEvent(QPaintEvent *event);
    virtual void	mouseMoveEvent ( QMouseEvent * event );
    virtual void	mousePressEvent ( QMouseEvent * event );
    virtual void	mouseReleaseEvent ( QMouseEvent * event );

private:
    Ui::select *ui;
    QPixmap m_image;
    QPoint m_start;//分别设置起止点
    QPoint m_end;
    QPoint m_pos;
    bool m_dragging;
public:
    QRect selectsquare;

};

#endif // SELECT_H
