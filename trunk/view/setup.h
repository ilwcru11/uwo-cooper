/*
 * setup.h
 *
 *  Created on: Mar 5, 2010
 *      Author: petergoodman
 *     Version: $Id$
 */

#ifndef SETUP_H_
#define SETUP_H_

#include <QWizard>
#include <QWizardPage>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

#include "datatype/coordinator.h"
#include "controller/setupcontroller.h"
#include "controller/usercontroller.h"

/**
 * A Wizard to go through and initialize the system.
 */
class Setup : public QWizard {
    Q_OBJECT
public:

    Setup(QWidget *parent = 0);
    ~Setup();

    virtual bool validateCurrentPage(void);

protected:
    void coordinator(void);
    void units(void);

private:
    QLineEdit *coord_pass;
    QLineEdit *file_name;

    QWizardPage *page1;
    QWizardPage *page2;

private slots:
    void browseDataFile();
};

#endif /* SETUP_H_ */
