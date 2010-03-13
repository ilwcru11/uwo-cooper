#ifndef ADDTASKVIEW_H
#define ADDTASKVIEW_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QMessageBox>

#include "lib/gui/modellistwidget.h"
#include "lib/gui/formlayoutptr.h"

#include "model/taskmodel.h"
#include "model/committeemodel.h"

class AddTaskView : public QDialog {
    Q_OBJECT
private:
    QLineEdit *name;
    QTextEdit *description;
    QRadioButton *pending_status;
    QDateEdit *deadline;
    CommitteeModel *committee;


public:
    AddTaskView(CommitteeModel *comm, QWidget *parent=0);
    ~AddTaskView(void);

public slots:
    void addTask(void);
    void cancelTask(void);

};

#endif // ADDTASKVIEW_H
