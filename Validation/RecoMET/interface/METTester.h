#ifndef METTESTER_H
#define METTESTER_H

// author: Mike Schmitt (The University of Florida)
// date: 8/24/2006
// modification: Bobby Scurlock 
// date: 03.11.2006
// note: added RMS(METx) vs SumET capability 
// modification: Rick Cavanaugh
// date: 05.11.2006 
// note: added configuration parameters 

#include <memory>
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
// user include files

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"

#include <vector>
#include <utility>
#include <ostream>
#include <string>
#include <algorithm>
#include <cmath>

//---ROOT
#include <TROOT.h>
#include <TSystem.h>
#include <TStyle.h>
#include <Cintex/Cintex.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1.h>
#include <TF1.h>
#include <TPaveStats.h>
#include <TPaveLabel.h>
//
// class declaration
//

class METTester : public edm::EDAnalyzer {
public:

  explicit METTester(const edm::ParameterSet&);
  ~METTester();

  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void beginJob(const edm::EventSetup&) ;
  virtual void endJob() ;
  void FillMETResHisto();

 private:

  DaqMonitorBEInterface* dbe_;
  string outputFile_;

  // CaloMET Quantities
  MonitorElement* meCaloMEx;
  MonitorElement* meCaloMEy;
  MonitorElement* meCaloMET;
  MonitorElement* meCaloEz;
  MonitorElement* meCaloMETSig;
  MonitorElement* meCaloMETPhi;
  MonitorElement* meCaloSumET;
  MonitorElement* meCaloMaxEtInEmTowers;
  MonitorElement* meCaloMaxEtInHadTowers;
  MonitorElement* meCaloEtFractionHadronic;
  MonitorElement* meCaloEmEtFraction;
  MonitorElement* meCaloHadEtInHB;
  MonitorElement* meCaloHadEtInHO;
  MonitorElement* meCaloHadEtInHE;
  MonitorElement* meCaloHadEtInHF;
  MonitorElement* meCaloEmEtInEB;
  MonitorElement* meCaloEmEtInEE;
  MonitorElement* meCaloEmEtInHF;

  // GenMET Quantities
  MonitorElement* meGenMEx;
  MonitorElement* meGenMEy;
  MonitorElement* meGenMET;
  MonitorElement* meGenMETPhi;
  MonitorElement* meGenEz;
  MonitorElement* meGenMETSig;
  MonitorElement* meGenSumET;
  MonitorElement* meGenEmEnergy;
  MonitorElement* meGenHadEnergy;
  MonitorElement* meGenInvisibleEnergy;
  MonitorElement* meGenAuxiliaryEnergy;

  // Sigma := fabs(CaloMET - GenMET)
  MonitorElement* meMETSigmaVsGenSumET;

  MonitorElement* meCaloMETvsCaloSumET;
  MonitorElement* meCaloMExvsCaloSumET;
  TH2F* h_CaloMExvsCaloSumET;
  float CaloMExResFitMin_;
  float CaloMExResFitMax_;
  int   CaloMExResHistoSumETNumBin_;
  double CaloMExResHistoLowSumET_;
  double CaloMExResHistoHighSumET_;
  int   CaloMExResHistoMExNumBin_;
  double CaloMExResHistoLowMEx_;
  double CaloMExResHistoHighMEx_;
  string InputGenMETLabel_;
  string InputCaloMETLabel_; 
};

#endif
