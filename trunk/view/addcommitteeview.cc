#include "addcommitteeview.h"

AddCommitteeView::AddCommitteeView(QWidget *parent) : QDialog(parent) {
    FormLayoutPtr layout(this);

    //Make yes/no for can delete
    QButtonGroup *canDeleteGroup(new QButtonGroup);
    QRadioButton *cantDelete(new QRadioButton("No"));
    canDelete = new QRadioButton("Yes");
    canDeleteGroup->addButton(canDelete);
    canDeleteGroup->addButton(cantDelete);


    //layout
    committeeName = layout << "Committee Name: " |= new QLineEdit;
    layout << "Is this Committee deleteable?" |= canDeleteGroup;
    selectChair << layout << "Select a Chair" |= new ModelListWidget<MemberModel>;
    selectSecretary << layout << "Select a Secretary" |= new ModelListWidget<MemberModel>;

    //Add / cancel buttons
    QPushButton *addButton = new QPushButton("Add Committee");
    QPushButton *cancelButton = new QPushButton("Cancel");

    layout << addButton | cancelButton;

    //misc
    canDelete->setChecked(true);
    setModal(true);
    setWindowTitle("Add Committee");

    //Connect slots/signals
    connect(addButton, SIGNAL(clicked()), this, SLOT(addCommittee()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelCommittee()));

}

AddCommitteeView::~AddCommitteeView(){}

AddCommitteeView::addCommittee()
{
    if(!committeeName->isModified()) {
        QMessageBox::information(
            this, "Empty Field",
            "Please enter a surname (family name)."
        );
        return;
    }
    done(QDialog::Accepted);
}

AddCommitteeView::cancelCommittee()
{
    done(QDialog::Rejected);
}


