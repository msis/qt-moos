#include <QApplication>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "qMOOSObject.h"

int main(int argc, char *argv[]) {
  using namespace std;

  QApplication app(argc, argv);

  MOOS::CommandLineParser P(argc, argv);
  std::string mission_file = P.GetFreeParameter(0, "mission.moos");
  std::string app_name = P.GetFreeParameter(1, "qMOOSObject_test");

  qMOOSObject mo;

  mo.startProcess(app_name, mission_file, argc, argv);

  return app.exec();
}
