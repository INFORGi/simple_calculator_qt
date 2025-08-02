#include "calculator.h"
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QDebug>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(40);

    QGridLayout *gridLayout = new QGridLayout();
    QStringList buttons = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    int row = 0, col = 0;
    for (const QString &text : buttons) {
        QPushButton *button = new QPushButton(text);
        button->setFixedSize(50, 50);
        gridLayout->addWidget(button, row, col);
        connect(button, &QPushButton::clicked, this, [=]() {
            onButtonClick(text);
        });

        col++;
        if (col > 3) {
            col = 0;
            row++;
        }
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(display);
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
    setWindowTitle("Калькулятор");
    resize(250, 300);
}

void Calculator::onButtonClick(const QString &text) {
    if (text == "C") {
        display->clear();
    } else if (text == "=") {
        QString expression = display->text();
        double result = evaluateExpression(expression);
        display->setText(QString::number(result));
    } else {
        display->setText(display->text() + text);
    }
}

double Calculator::evaluateExpression(const QString &expr) {
    QStringList tokens;
    QString number;

    for (int i = 0; i < expr.length(); ++i) {
        QChar ch = expr[i];
        if (ch.isDigit() || ch == '.') {
            number += ch;
        } else {
            if (!number.isEmpty()) {
                tokens << number;
                number.clear();
            }
            tokens << ch;
        }
    }
    if (!number.isEmpty()) tokens << number;

    double result = tokens[0].toDouble();
    for (int i = 1; i < tokens.size(); i += 2) {
        QString op = tokens[i];
        double value = tokens[i + 1].toDouble();

        if (op == "+") result += value;
        else if (op == "-") result -= value;
        else if (op == "*") result *= value;
        else if (op == "/") result /= value;
    }

    return result;
}
