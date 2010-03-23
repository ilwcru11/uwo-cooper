#include "editcommitteeview.h"

EditCommitteeView::EditCommitteeView(CommitteeModel *selectedCommittee, 
                                     QWidget *parent) : QDialog(parent) {

    FormLayoutPtr layout(this);

    selCommittee = selectedCommittee;

    //Make yes/no for can delete
    QButtonGroup *canDeleteGroup(new QButtonGroup);
    QRadioButton *cantDelete(new QRadioButton("No"));
    canDelete = new QRadioButton("Yes");
    canDeleteGroup->addButton(canDelete);
    canDeleteGroup->addButton(cantDelete);



    //layout
    committeeName = layout << "Committee Name: " |= new QLineEdit(selCommittee->getName());
    layout << "Is this Committee deleteable?" | canDelete;
    layout << "" | cantDelete;
    selectChair = layout << "Select a Chair" |= new ModelListWidget<MemberModel>;
    selectSecretary = layout << "Select a Secretary" |= new ModelListWidget<MemberModel>;

 //    setUpPermissionButtons(&layout);
     memList = new PermListWidget(QString("Member Permissions"), selCommittee->getMemPerms());
     chairList = new PermListWidget(QString("Chair Permissions"), selCommittee->getChairPerms());

     QTabWidget *tabs = new QTabWidget;

     tabs->addTab(memList, "Member Permissions");
     tabs->addTab(chairList, "Chair Permissions");

     layout << "" | tabs;

    //Add / cancel buttons
    QPushButton *editButton = new QPushButton("Edit Committee");
    QPushButton *cancelButton = new QPushButton("Cancel");

    layout << editButton | cancelButton;

    //misc
    canDelete->setChecked(true);
    setModal(true);
    setWindowTitle("Edit Committee");
    selectChair->fill(&MemberModel::findAll);
    selectSecretary->fill(&MemberModel::findAll);

    //Connect slots/signals
    connect(editButton, SIGNAL(clicked()), this, SLOT(editCommittee()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelCommittee()));

}

EditCommitteeView::~EditCommitteeView(){}

void EditCommitteeView::editCommittee()
{

}

void EditCommitteeView::cancelCommittee()
{
    done(QDialog::Rejected);
}