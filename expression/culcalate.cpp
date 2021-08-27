#include <iostream>
#include <cmath>
#include <string>
#include"widget.h"

using namespace std;

#define OVERFLOW 1
#define OK 0
#define MAXSIZE 100
#define ERROR 2
QString fin;
bool flag = false;

struct SqStack {
    char *top;
    char *base;
    int size;
};

struct SqStackN {
    double *top;
    double *base;
    int size;
};

int InitStack(SqStack &S) {
    //构造一个空栈S
    S.base = new char[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    if (!S.base)
        exit(OVERFLOW); //存储分配失败
    S.top = S.base; //top初始为base，空栈
    S.size = MAXSIZE; //size置为栈的最大容量MAXSIZE
    return OK;
}

//数栈初始化
int InitStack(SqStackN &S) {
    //构造一个空栈S
    S.base = new double[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    if (!S.base)
        exit(OVERFLOW); //存储分配失败
    S.top = S.base; //top初始为base，空栈
    S.size = MAXSIZE; //size置为栈的最大容量MAXSIZE
    return OK;
}

//入栈
double Push(SqStack &S, char e) {
    // 插入元素e为新的栈顶元素
    if (S.top - S.base == S.size)
        return ERROR; //栈满
    *(S.top++) = e; //元素e压入栈顶，栈顶指针加1
    return OK;
}

//符号入栈
double Push(SqStackN &S, double e) {
    // 插入元素e为新的栈顶元素
    if (S.top - S.base == S.size)
        return ERROR; //栈满
    *(S.top++) = e; //元素e压入栈顶，栈顶指针加1
    return OK;
}

//出栈
double Pop(SqStack &S) {
    if (S.base == S.top)
        return ERROR;//栈空
    --S.top;
    return OK;
}

//数值出栈
double Pop(SqStackN &S) {
    if (S.base == S.top)
        return ERROR;//栈空
    --S.top; //栈顶指针减1，将栈顶元素赋给e
    return OK;
}


//取栈顶元素
char GetTop(SqStack S) {//返回S的栈顶元素，不修改栈顶指针
    if (S.top != S.base) //栈非空
        return *(S.top - 1);//返回栈顶元素的值，栈顶指针不变
}

int Empty(SqStack S) {
    if (S.top == S.base) //栈非空
        return 1;
    else
        return 0;
}

double GetTop(SqStackN S) {//返回S的栈顶元素，不修改栈顶指针
    if (S.top != S.base) //栈非空
        return *(S.top - 1);//返回栈顶元素的值，栈顶指针不变
}


int right(char c) {//检查非法输入  T->N,)     N->T    (->T   )->N
    if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '.')
        return 1;
    else {
        if (c >= '0' && c <= '9')
            return 2;
        else
            //cout << "请输入正确的运算符或数字哦！" << endl;
            fin = "请输入正确的运算符或数字哦！";
        return 0;
    }
}



int first(string &a) {//第一位是否合法
    if (a[0] == ')' || a[0] == '*' || a[0] == '/' || a[0] == '%'||a[0]=='+') {
        //cout << "请不要把运算符放在首位哦！" << endl;
        fin = "请不要把运算符放在首位哦！";
        return 0;
    } else return 1;
}

int end(string &a) {
    int x = a.size() - 1;
    if (a[x] == '+' || a[x] == '-' || a[x] == '*' || a[x] == '/' || a[x] == '%' || a[x] == '.') {
        //cout << "表达看不懂哦！" << endl;
        fin = "表达式看不懂哦！";
        return 0;
    }
    else return 1;
}

int order(string& a, int i) {//符号顺序是否合法
    switch (a[i+1])
    {
    case '+':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.') {
            //cout << "请不要输入连续的运算符哦！" << endl;
            fin = "请不要输入连续的运算符哦！";
            return 0;
        }
        else if (a[i] == '(') {
            //cout << "左括号后不能接加号哦！" << endl;
            fin = "左括号后不能接加号哦！";
            return 0;
        }
        else return 1;
        break;
    case '-':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.') {
            //cout << "请不要输入连续的运算符哦！" << endl;
            fin = "请不要输入连续的运算符哦！";
            return 0;
        }
        else return 1;
        break;
    case '*':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.') {
            //cout << "请不要输入连续的运算符哦！" << endl;
            fin = "请不要输入连续的运算符哦！";
            return 0;
        }
        else if (a[i] == '(') {
            //cout << "左括号后不能接乘号哦！" << endl;
            fin = "左括号后不能接乘号哦！";
            return 0;
        }
        else return 1;
        break;
    case '/':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.') {
            //cout << "请不要输入连续的运算符哦！" << endl;
            fin = "请不要输入连续的运算符哦！";
            return 0;
        }
        else if (a[i] == '(') {
            //cout << "左括号后不能接除号哦！" << endl;
            fin = "左括号后不能接除号哦！";
            return 0;
        }
        else return 1;
        break;
    case '%':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.') {
            //cout << "请不要输入连续的运算符哦！" << endl;
            fin = "请不要输入连续的运算符哦！";
            return 0;
        }
        else if (a[i] == '(') {
            //cout << "左括号后不能接取余号哦！" << endl;
            fin = "左括号后不能接取余号哦！";
            return 0;
        }
        else return 1;
        break;
    case '(':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' ) {
            return 1;
        }
        else {//cout << "表达看不懂哦！" << endl;
            fin = "表达式看不懂哦！";
            return 0;}
        break;
    case ')':
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '.' || a[i] == '(') {
            //cout << "表达看不懂哦！" << endl;
            fin = "表达式看不懂哦！";
            return 0;
        }
        else return 1;
        break;
    case '.':
        if (a[i] == ')' || a[i] == '.'){
            //cout << "表达看不懂哦！" << endl;
            fin = "表达式看不懂哦！";
            return 0;
        }
        else return 1;
        break;
    }
}

void format(string &a) {
    //cin >> a;
    int m = 0, n = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '(') m++;
        if (a[i] == ')') n++;
        if (right(a[i]) && first(a) && order(a, i) && end(a)) {//检测输入合法性
            if (a[i] == '-') {
                if (i == 0) {
                    a.insert(0, 1, '0');
                } else if (a[i - 1] == '(') {
                    a.insert(i, 1, '0');
                }
            }
            if (a[i] == '.') {
                if (i == 0) {
                    a.insert(0, 1, '0');
                } else if (a[i - 1] == '+' || a[i - 1] == '-' || a[i - 1] == '*' || a[i - 1] == '/' ||
                           a[i - 1] == '%' || a[i - 1] == '(') {
                    a.insert(i, 1, '0');
                }
            }
        } else {
            flag = true;
            break;
        }
    }

    if (m != n) {
        //cout << "你输入的括号有误哦！" << endl;
        fin = "表达式看不懂哦！";
        flag = true;
    }

}

int prior(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    } else {
        return 0;
    }
}

int t = 0;
string b[100];

string *RPN(string &a) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < a.size(); ++i) {
        string tmp = "";
        switch (a[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                if (Empty(S) || GetTop(S) == '(') {
                    Push(S, a[i]);
                } else {
                    while (!Empty(S) && prior(GetTop(S)) >= prior(a[i])) {
                        tmp += GetTop(S);
                        b[t] = tmp;
                        t += 1;
                        Pop(S);
                        tmp = "";
                    }
                    Push(S, a[i]);
                }
                break;
            case '(':
                Push(S, a[i]);
                break;
            case ')':
                while (GetTop(S) != '(') {
                    tmp += GetTop(S);
                    b[t] = tmp;
                    t += 1;
                    Pop(S);
                    tmp = "";
                }
                Pop(S);
                break;
            default:
                if ((a[i] >= '0' && a[i] <= '9')) {
                    tmp += a[i];
                    while (i + 1 < a.size() && a[i + 1] >= '0' && a[i + 1] <= '9' || a[i + 1] == '.') {
                        tmp += a[i + 1];//若是连续数字
                        ++i;
                    }
                    b[t] = tmp;
                    t += 1;
                }
        }
    }
    while (!Empty(S)) {
        string tmp = "";
        tmp += GetTop(S);
        b[t] = tmp;
        t += 1;
        Pop(S);
    }
    return b;
}

double calculation(string *a) {
    SqStackN N;
    InitStack(N);
    double x, y;
    double num;
    for (int i = 0; i < t; ++i) {
        if (a[i][0] >= '0' && a[i][0] <= '9') {
            num = atof(a[i].c_str());
            Push(N, num);
            } else {
            if (a[i] == "+") {
                y = GetTop(N);
                Pop(N);
                x = GetTop(N);
                Pop(N);
                Push(N, x + y);
            } else if (a[i] == "-") {
                y = GetTop(N);
                Pop(N);
                x = GetTop(N);
                Pop(N);
                Push(N, x - y);
            } else if (a[i] == "*") {
                y = GetTop(N);
                Pop(N);
                x = GetTop(N);
                Pop(N);
                Push(N, x * y);
            } else if (a[i] == "/") {
                y = GetTop(N);
                Pop(N);
                x = GetTop(N);
                Pop(N);
                if(y==0){
                    //cout<<"请检查表达式，分母不能为0哦！";
                    fin = "请检查表达式，分母不能为0哦!";
                    flag = 1;
                    return 0;
                }
                Push(N, x / y);
            } else if (a[i] == "%") {
                y = GetTop(N);
                Pop(N);
                x = GetTop(N);
                Pop(N);
                if(y==0){
                    //cout<<"请检查表达式，分母不能为0哦！";
                    fin = "请检查表达式，分母不能为0哦!";
                    flag = 1;
                    return 0;
                }
                Push(N, fmod(x, y));
            }
        }//else
    }
    //cout << GetTop(N);
    return GetTop(N);
}


QString calculate(string a) {
    //QString fin;
    format(a);

    if(flag)
    {
       return fin;
    }

    string *c = RPN(a);
    double cc = calculation(c);

    if(flag)
    {
       return fin;
    }

    return QString::number(cc,'g',10);
}
