#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QTableWidget>
#include "qMOOSObject.h"

class Window : public QWidget
{
  Q_OBJECT

private:
  QTableWidget *m_table_widget;
  QStringList m_table_headers;

public:
  Window (QWidget *parent = 0);

public slots:
  void newMOOSmsg(std::string key, double dVal,
                std::string src, std::string community, double timestamp);
  void newMOOSmsg(std::string key, std::string sVal,
                std::string src, std::string community, double timestamp);


};


#endif
