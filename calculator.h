#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onButtonClick(const QString &text);

private:
    QLineEdit *display;
    double evaluateExpression(const QString &expr);
};

#endif
