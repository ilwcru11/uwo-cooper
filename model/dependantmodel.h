#ifndef DEPENDANT_H
#define DEPENDANT_H

#include <ctime>

#include <QString>
#include <QDateTime>
#include <QSqlQuery>

#include "lib/imodel.h"

class DependantModel : public IModel<DependantModel, select_from_table_tag>
{
    MODEL_CLASS(DependantModel);

public:
    static const char *table_name;

    bool isUnderAge(void);
    QString getName(void);
    QDateTime getBday(void);
    QString toString(void);

    virtual bool save(void);
    virtual bool remove(void);

protected:
    static DependantModel *load(QSqlQuery &q, const int id);

private:
    DependantModel(const int id, QString name, QDateTime bday, const int mid);

    QString name;
    QDateTime bday_21;
    const int member_id;
};

#endif // DEPENDANT_H
