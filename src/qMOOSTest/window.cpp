#include "window.h"

Window::Window (QWidget *parent) :
      QWidget(parent)
{
  m_table_widget = new QTableWidget(this);
  m_table_widget->setRowCount(2);
  m_table_widget->setColumnCount(5);

  m_table_headers << "Variable" << "Value" << "Source" << "Community" << "Time";
  m_table_widget->setHorizontalHeaderLabels(m_table_headers);
  m_table_widget->verticalHeader()->setVisible(false);
  m_table_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);

  setWindowTitle("TestWindow");
  // resize(400,200);
}

void Window::newMOOSmsg(std::string key, double dVal,
              std::string src, std::string community, double timestamp) {
  m_table_widget->setItem(0,0, new QTableWidgetItem(QString(key.c_str())));
  m_table_widget->setItem(0,1, new QTableWidgetItem(QString().setNum(dVal)));
  m_table_widget->setItem(0,2, new QTableWidgetItem(QString(src.c_str())));
  m_table_widget->setItem(0,3, new QTableWidgetItem(QString(community.c_str())));
  m_table_widget->setItem(0,4, new QTableWidgetItem(QString().setNum(timestamp)));
}

void Window::newMOOSmsg(std::string key, std::string sVal,
              std::string src, std::string community, double timestamp) {
  m_table_widget->setItem(0,0, new QTableWidgetItem(QString(key.c_str())));
  m_table_widget->setItem(0,1, new QTableWidgetItem(QString(sVal.c_str())));
  m_table_widget->setItem(0,2, new QTableWidgetItem(QString(src.c_str())));
  m_table_widget->setItem(0,3, new QTableWidgetItem(QString(community.c_str())));
  m_table_widget->setItem(0,4, new QTableWidgetItem(QString().setNum(timestamp)));
}
