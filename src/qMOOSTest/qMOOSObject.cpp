#include "qMOOSObject.h"
#include <iostream>

using namespace std;

qMOOSObject::qMOOSObject(QObject *parent) :
  QThread(parent)
{
  m_running = false;
  m_iter = 0;
}

qMOOSObject::~qMOOSObject()
{
  mutex.lock();
  m_running = false;
  mutex.unlock();

  wait();
}

void qMOOSObject::startProcess(const std::string &  sName,
  const std::string & sMissionFile,
  int argc,  char * argv[])
{
  SetCommandLineParameters(argc,argv);

  m_moosAppName = sName;
  m_moosMissionFile = sMissionFile;

  start();
}

void qMOOSObject::run()
{
  Run(m_moosAppName, m_moosMissionFile);
}

void qMOOSObject::stopProcess()
{
  mutex.lock();
  m_running = false;
  mutex.unlock();
}

// MOOS stuff
bool qMOOSObject::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  return true;
}

void qMOOSObject::OnPrintHelpAndExit()
{

}

void qMOOSObject::OnPrintExampleAndExit()
{

}

bool qMOOSObject::OnConnectToServer()
{
  return RegisterVars();
}

bool qMOOSObject::RegisterVars()
{
  AppCastingMOOSApp::RegisterVariables();

  Register("QMT_ITER");

  return true;
}

bool qMOOSObject::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;

    string key = msg.GetKey();

    bool handled = false;
    if (key == "QMT_ITER") {
      std::cout << key << " received w/ " << msg.GetDouble() << std::endl;
      handled = true;
    }

    if (!handled) {
      reportRunWarning("Unhandled Mail: " + key);
    }
  }

  return true;
}

void qMOOSObject::emitMOOSMsgAsSignal(const CMOOSMsg& msg) {
  if(msg.IsDouble())
    emit newMOOSmsg(msg.GetKey(), msg.GetDouble(),
                  msg.GetSource(), msg.GetCommunity(), msg.GetTime());
  if (msg.IsString())
    emit newMOOSmsg(msg.GetKey(), msg.GetString(),
                  msg.GetSource(), msg.GetCommunity(), msg.GetTime());
}

bool qMOOSObject::Iterate()
{
  AppCastingMOOSApp::Iterate();

  m_iter ++;
  Notify("QMT_ITER", m_iter);

  AppCastingMOOSApp::PostReport();
  return true;
}

bool qMOOSObject::buildReport()
{
  m_msgs << "qMOOSObject" << endl;

  return true;
}
