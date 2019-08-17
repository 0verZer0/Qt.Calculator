#include "root.h"

using namespace Calculator;

Root::Root() {
    m_title = "Calculator";
    m_input = "";
    getOperators();
}

Q_INVOKABLE void Root::changeInput(QString newValue) {
    QString value = m_input;
    value.append(newValue);
    setInput(value);
}

Q_INVOKABLE void Root::calculateInput() {
    QString opr = getOperator();
    int pos = getOperatorPosition(opr);
    QString string1 = m_input.mid(0, pos);
    QString string2 = m_input.mid(pos + 1);

    double value1 = string1.toDouble();
    double value2 = string2.toDouble();
    double result = 0.0;    

    if (opr == "/")
        result = value1 / value2;
    else if (opr == "*")
        result = value1 * value2;
    else if (opr == "-")
        result = value1 - value2;
    else if (opr == "+")
        result = value1 + value2;

    setInput(QString::number(result));
}

Q_INVOKABLE void Root::clearInput() {
    setInput("");
}

QString Root::getTitle() {
    return  m_title;
}

QString Root::getInput() {
    return  m_input;
}

void Root::setInput(const QString value) {
    if (m_input != value) {
        m_input = value;
        emit onInputChanged();
    }
}

void Root::getOperators() {
    operators.append("/");
    operators.append("*");
    operators.append("-");
    operators.append("+");
}

QString Root::getOperator() {
    for (int i = 0; i < operators.length(); i++)
        if (m_input.contains(operators[i]))
            return operators[i];

    return "";
}

int Root::getOperatorPosition(QString opr) {
    return m_input.indexOf(opr);
}
