#include "widget.h"
#include "ui_widget.h"
#include "culcalate.cpp"
#include <QString>
#include <QDebug>
#include <stdlib.h>
#include <string.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接槽函数
    connect(ui->pushButton0,SIGNAL(clicked(bool)),this,SLOT(item0())); //0
    connect(ui->pushButton1,SIGNAL(clicked(bool)),this,SLOT(item1())); //1
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(item2())); //2
    connect(ui->pushButton3,SIGNAL(clicked(bool)),this,SLOT(item3())); //3
    connect(ui->pushButton4,SIGNAL(clicked(bool)),this,SLOT(item4())); //4
    connect(ui->pushButton5,SIGNAL(clicked(bool)),this,SLOT(item5())); //5
    connect(ui->pushButton6,SIGNAL(clicked(bool)),this,SLOT(item6())); //6
    connect(ui->pushButton7,SIGNAL(clicked(bool)),this,SLOT(item7())); //7
    connect(ui->pushButton8,SIGNAL(clicked(bool)),this,SLOT(item8())); //8
    connect(ui->pushButton9,SIGNAL(clicked(bool)),this,SLOT(item9())); //9

    connect(ui->pushButton_left,SIGNAL(clicked(bool)),this,SLOT(i_left())); //(
    connect(ui->pushButton_right,SIGNAL(clicked(bool)),this,SLOT(i_right()));//)

    connect(ui->pushButton_c,SIGNAL(clicked(bool)),this,SLOT(cancel()));//取消
    connect(ui->pushButton_add,SIGNAL(clicked(bool)),this,SLOT(add()));//加号
    connect(ui->pushButton_equal,SIGNAL(clicked(bool)),this,SLOT(equal()));//等于号
    connect(ui->pushButton_point,SIGNAL(clicked(bool)),this,SLOT(point()));//小数点
    connect(ui->pushButton_div,SIGNAL(clicked(bool)),this,SLOT(div()));//除号
    connect(ui->pushButton_sub,SIGNAL(clicked(bool)),this,SLOT(sub()));//减号
    connect(ui->pushButton_mul,SIGNAL(clicked(bool)),this,SLOT(mul()));//乘号
    connect(ui->pushButton_mod,SIGNAL(clicked(bool)),this,SLOT(mod()));//取余
    connect(ui->pushButton_delete,SIGNAL(clicked(bool)),this,SLOT(delet()));//尾剔除

    setStyleSheet(
                  //正常状态样式
                  "QPushButton{"
                  "background-color:rgba(100,225,100,100);"//背景色（也可以设置图片）
                  "border-style:outset;"                  //边框样式（inset/outset）
                  "border-width:4px;"                     //边框宽度像素
                  "border-radius:10px;"                   //边框圆角半径像素
                  "border-color:rgba(255,255,255,30);"    //边框颜色
                  "font:bold 15px;"                       //字体，字体大小
                  "color:rgba(0,0,0,130);"                //字体颜色
                  "padding:6px;"                          //填衬
                  "}"
                  //鼠标按下样式
                  "QPushButton:pressed{"
                  "background-color:rgba(100,255,100,200);"
                  "border-color:rgba(255,255,255,30);"
                  "border-style:inset;"
                  "color:rgba(0,0,0,100);"
                  "}"
                  //鼠标悬停样式
                  "QPushButton:hover{"
                  "background-color:rgba(100,255,100,100);"
                  "border-color:rgba(255,255,255,200);"
                  "color:rgba(0,0,0,200);"
                  "}"
                  "QLineEdit{"
                  "background-color:rgba(230, 230, 230,200);"
                  "border-style:outset;"                  //边框样式（inset/outset）
                  "border-width:4px;"                     //边框宽度像素
                  "border-radius:10px;"                   //边框圆角半径像素
                  "border-color:rgba(255,255,255,30);"    //边框颜色
                  "font:bold 22px;"                       //字体，字体大小
                  "color:rgba(0,0,0,130);"                //字体颜色
                  "padding:6px;"                          //填衬
                  "}"
                );
}


Widget::~Widget()
{
    delete ui;
}

void Widget::item0() //0
{
    item_0 = ui->pushButton0->text(); //获取按键中的字符"0"
    line += item_0;//每按一次按键就相加一次按键中的字符"0"
    ui->lineEdit->setText(line); //显示到输入条中
}

void Widget::item1() //1
{
    item_1 = ui->pushButton1->text();
    line += item_1;
    ui->lineEdit->setText(line);
}

void Widget::item2() //2
{
   item_2 = ui->pushButton2->text(); //获取按键中的字符"2"
   line += item_2; //每按一次按键就相加一次按键中的字符"2"
   ui->lineEdit->setText(line);
}

void Widget::item3() //3
{
   item_3 = ui->pushButton3->text(); //获取按键中的字符"3"
   line += item_3; //每按一次按键就相加一次按键中的字符"3"
   ui->lineEdit->setText(line);
}

void Widget::item4() //4
{
    item_4 = ui->pushButton4->text();
    line += item_4;
    ui->lineEdit->setText(line);
}

void Widget::item5() //5
{
    item_5 = ui->pushButton5->text();
    line += item_5;
    ui->lineEdit->setText(line);
}

void Widget::item6() //6
{
    item_6 = ui->pushButton6->text();
    line += item_6;
    ui->lineEdit->setText(line);
}

void Widget::item7() //7
{
    item_7 = ui->pushButton7->text();
    line += item_7;
    ui->lineEdit->setText(line);
}

void Widget::item8() //8
{
    item_8 = ui->pushButton8->text();
    line += item_8;
    ui->lineEdit->setText(line);
}

void Widget::item9() //9
{
    item_9 = ui->pushButton9->text();
    line += item_9;
    ui->lineEdit->setText(line);
}

void Widget::point() //小数点
{
    item_point = ui->pushButton_point->text();
    line += item_point;
    ui->lineEdit->setText(line);
}

void Widget::i_left()
{
    item_left = ui->pushButton_left->text();
    line += item_left;
    ui->lineEdit->setText(line);
}

void Widget::i_right()
{
    item_right = ui->pushButton_right->text();
    line += item_right;
    ui->lineEdit->setText(line);
}

void Widget::add() //相加
{
    item_add = ui->pushButton_add->text();
    line += item_add;
    ui->lineEdit->setText(line);
}

void Widget::sub() //相减
{
    item_sub = ui->pushButton_sub->text();
    line += item_sub;
    ui->lineEdit->setText(line);
}

void Widget::div()//除法
{
    item_div = ui->pushButton_div->text();
    line += item_div;
    ui->lineEdit->setText(line);
}

void Widget::mul()//乘法
{
    item_mul = ui->pushButton_mul->text();
    line += item_mul;
    ui->lineEdit->setText(line);
}

void Widget::mod()//取余
{
    item_mod = ui->pushButton_mod->text();
    line += item_mod;
    ui->lineEdit->setText(line);
}

void Widget::delet() //尾剔除
{
    line = ui->lineEdit->text(); //获取输入条中的字符
    line.chop(1); //倒位删除，即是从字符串后面开始按位删除
    ui->lineEdit->setText(line);
}

void Widget::cancel() //重新置零
{
   flag = 0;
   line.clear();
   t=0;
   //fin = "离谱";
   ui->lineEdit->setText(line);//输出空白
}

void Widget::equal() //得出结果
{
    line = ui->lineEdit->text();
    if(line.isEmpty()){
        ui->lineEdit->setText(line);
    }else{
        string sum = line.toStdString();
        //插入计算函数
        //QString::number(calculate(sum),'g',10);
        line = calculate(sum);
        ui->lineEdit->setText(line);
    }
}
