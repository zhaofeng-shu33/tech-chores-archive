#ifndef __H_XML_MANAGER__
#define __H_XML_MANAGER__


#include <QStringList>

class QStandardItemModel;


class XmlManager
{
public:
    XmlManager();
    virtual ~XmlManager();

    void saveToXml(QStandardItemModel* model);
    QStandardItemModel* readFromXml(QStandardItemModel* model);
    QStringList getSetList();
    QStringList getLanguageList();

protected:
    QStandardItemModel* m_pModel;
};


#endif // __H_XML_MANAGER__
