#ifndef ROOT_H
#define ROOT_H

#include <QObject>

namespace Calculator {
    class Root : public QObject {
        Q_OBJECT
        Q_PROPERTY(QString title READ getTitle)
        Q_PROPERTY(QString input READ getInput WRITE setInput NOTIFY onInputChanged)

    public:
        Q_INVOKABLE void changeInput(QString newValue);
        Q_INVOKABLE void calculateInput();
        Q_INVOKABLE void clearInput();

    signals:
        void onInputChanged();

    private:
        QString m_title;
        QString m_input;
        QList<QString> operators;

    public:
        Root();
        QString getTitle();
        QString getInput();
        void setInput(const QString value);

    private:
        void getOperators();
        QString getOperator();
        int getOperatorPosition(QString opr);
    };
}
#endif // ROOT_H
