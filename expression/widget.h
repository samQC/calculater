#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include<iostream>

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QString line;
    QString item_0;//0
    QString item_1;//1
    QString item_2;//2
    QString item_3;//3
    QString item_4;//4
    QString item_5;//5
    QString item_6;//6
    QString item_7;//7
    QString item_8;//8
    QString item_9;//9
    QString item_point;//.
    QString item_left;//(
    QString item_right;//)
    QString item_add;//+
    QString item_sub;//-
    QString item_mul;//*
    QString item_div;//chu
    QString item_mod;//%

    //计算后的结果

protected slots:
    void item0();//0
    void item1();//1
    void item2();//2
    void item3();//3
    void item4();//4
    void item5();//5
    void item6();//6
    void item7();//7
    void item8();//8
    void item9();//9
    void i_left();//(
    void i_right();//)
    void mod();//取余
    void sub();//减号
    void div();//除号
    void mul();//乘号
    void cancel();//取消
    void delet();//尾剔除
    void add();//加号
    void equal();//等于号
    void point();//小数点

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
