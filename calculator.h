#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include<vector>
#include<cmath>
#include<unistd.h>
QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();
    void equestring(QString);
    std::vector<QString> vec;
    void text();
    int exceptionsfind();
    struct Tree
    {
        QString key;
        std::vector<Tree*> child;
    };
    void equevec();
    void equeTree(Tree* root);
    QString eque(Tree* root);
private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_butonAc_clicked();

    void on_butonBc_clicked();

    void on_butonPoint_clicked();

    void on_bracketsLeft_clicked();

    void on_bracketsRight_clicked();

    void on_butonMultiply_clicked();

    void on_butonDivide_clicked();

    void on_butonLess_clicked();

    void on_butonPlus_clicked();

    void on_butonPow_clicked();

    void on_butonSqrt_clicked();

    void on_butonSin_clicked();

    void on_butonCos_clicked();

    void on_butonTan_clicked();

    void on_butonEque_clicked();

private:
    Ui::calculator *ui;


};
#endif // CALCULATOR_H
