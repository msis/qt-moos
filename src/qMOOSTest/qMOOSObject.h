#ifndef QMOOSOBJECT_H
#define QMOOSOBJECT_H

#include <QMutex>
#include <QThread>
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class qMOOSObject : public QThread, AppCastingMOOSApp
{

  Q_OBJECT

public:
  qMOOSObject (QObject *parent = 0);
  ~qMOOSObject ();

  void startProcess(const std::string &, const std::string &,
    int argc, char* argv[]);

// MOOSApp related
public:
  bool OnStartUp();
  void OnPrintHelpAndExit();
  void OnPrintExampleAndExit();
  bool OnConnectToServer();
  bool OnNewMail(MOOSMSG_LIST &);
  bool Iterate();
  bool RegisterVars();

// QObject related
public slots:
  void stopProcess();
signals:
  void newMOOSmsg(std::string key, double dVal,
                std::string src, std::string community, double timestamp);
  void newMOOSmsg(std::string key, std::string sVal,
                std::string src, std::string community, double timestamp);


// QThread related
protected:
  void run();

// AppCastingMOOSApp related
protected:
  bool buildReport();

private:
  QMutex mutex;
  bool m_running;
  int m_iter;

  std::string m_moosAppName;
  std::string m_moosMissionFile;

  void emitMOOSMsgAsSignal(const CMOOSMsg&);

};

#endif
