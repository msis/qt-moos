#include <QApplication>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "qMOOSObject.h"
#include "window.h"

Q_DECLARE_METATYPE(std::string)

int main(int argc, char *argv[]) {
  using namespace std;

  QApplication app(argc, argv);

  MOOS::CommandLineParser P(argc, argv);
  std::string mission_file = P.GetFreeParameter(0, "mission.moos");
  std::string app_name = P.GetFreeParameter(1, "qMOOSObject_test");

  qMOOSObject mo;

  mo.startProcess(app_name, mission_file, argc, argv);

  Window W;
  W.show();

  qRegisterMetaType<std::string>();
  app.connect(&mo, SIGNAL(newMOOSmsg(std::string , double ,
                            std::string , std::string , double )),
              &W, SLOT(newMOOSmsg(std::string , double ,
                          std::string , std::string , double )));

  app.connect(&mo, SIGNAL(newMOOSmsg(std::string , std::string ,
                            std::string , std::string , double )),
              &W, SLOT(newMOOSmsg(std::string , std::string ,
                          std::string , std::string , double )));

  return app.exec();
}
