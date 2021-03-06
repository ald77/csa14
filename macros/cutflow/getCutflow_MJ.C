#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h> 
#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TChain.h"
#include "TTree.h"
#include "TCut.h"
#include "THStack.h"
#include "TLine.h"

using namespace std;

TChain* ttbar_;
TChain* qcd_;
TChain* znn_;
TChain* wjets_;
TChain* single_top_;
TChain* other_;

TChain* ttbar_ch;
TChain* qcd_ch;
TChain* znn_ch;
TChain* wjets_ch;
TChain* single_top_ch;
TChain* other_ch;

FILE * file;

float int_lumi(5000.);

void PrintLine(TCut cut, string description) {

 
  TH1F *h = new TH1F("h","",2,0,2);
  TCut weight = Form("weightppb*%f",int_lumi);
  float n_ttbar(0.), n_qcd(0.), n_znn(0.), n_wjets(0.), n_single_top(0.), n_other(0.), n_SM(0.);

  // Fill hist to get each weighted yield
  
  ttbar_ch->Project("h","1",cut*weight);
  n_ttbar=h->Integral();
  qcd_ch->Project("h","1",cut*weight);
  n_qcd=h->Integral();
  znn_ch->Project("h","1",cut*weight);
  n_znn=h->Integral();
  wjets_ch->Project("h","1",cut*weight);
  n_wjets=h->Integral();
  single_top_ch->Project("h","1",cut*weight);
  n_single_top=h->Integral();
  other_ch->Project("h","1",cut*weight);
  n_other=h->Integral();

  n_SM=n_qcd+n_ttbar+n_znn+n_wjets+n_single_top+n_other;

  printf("%s, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f\n", description.c_str(), n_qcd, n_ttbar, n_znn, n_wjets, n_single_top, n_other, n_SM);
  fprintf(file, "%s, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f\n", description.c_str(), n_qcd, n_ttbar, n_znn, n_wjets, n_single_top, n_other, n_SM);


  delete h;

}


void getCutflow_MJ(TString title, float lumi=5000.) {

  int_lumi=lumi;

  ttbar_ch = new TChain("reduced_tree");
  qcd_ch = new TChain("reduced_tree");
  znn_ch = new TChain("reduced_tree");
  wjets_ch = new TChain("reduced_tree");
  single_top_ch = new TChain("reduced_tree");
  other_ch = new TChain("reduced_tree");

  ttbar_ch->Add("reduced_trees/TTJets*PU20*v75*.root");
  qcd_ch->Add("reduced_trees/QCD_Pt-*v75*.root");
  //  qcd_ch->Add("reduced_trees/low-pt-qcd/QCD_Pt-*.root");
  znn_ch->Add("reduced_trees/ZJets*v75*.root");
  wjets_ch->Add("reduced_trees/WJets*v75*.root");
  single_top_ch->Add("reduced_trees/TTo*v75*.root");
  single_top_ch->Add("reduced_trees/TBarTo*v75*.root");
  single_top_ch->Add("reduced_trees/*tW*v75*.root");
  other_ch->Add("reduced_trees/*HToBB*v75*.root");
  other_ch->Add("reduced_trees/TTbarH*v75*.root");

  TCut start("met>400&&fatpT30_MJ>400");
  TCut baseline(start+"num_csvm_jets30>1&&min_delta_phi_met_N>4&&num_reco_veto_muons==0&&num_reco_veto_electrons==0&&num_jets_pt30>=6");

  file = fopen ("macros/cutflow/output/"+title+".txt", "w");
  fprintf(file,"Cut, QCD, ttbar, Znn, SM Total\n");

  PrintLine(start, "MET > 400 GeV & MJ > 400 GeV");
  PrintLine(start+"num_reco_veto_muons==0", "Muon veto");
  PrintLine(start+"num_reco_veto_muons==0&&num_reco_veto_electrons==0", "Electron veto");
  PrintLine(start+"num_reco_veto_muons==0&&num_reco_veto_electrons==0&&num_jets_pt30>=6", ">= 6 jets");
  PrintLine(start+"num_reco_veto_muons==0&&num_reco_veto_electrons==0&&num_jets_pt30>=6&&num_csvm_jets30>1", ">= 2 CSVM");
  PrintLine(baseline, "mdpN>4");
  //  PrintLine(start+"num_csvm_jets30>1&&jet2_pt>70&&jet3_pt>50&&met>250&&min_delta_phi_met_N>4.&&num_reco_veto_electrons==0&&num_reco_veto_muons==0&&num_iso_tracks==0", "IsoTk veto");
  fprintf(file,"******* b-tag bins *******\n");
  PrintLine(baseline+"num_csvm_jets30==2", "2 CSVM");
  PrintLine(baseline+"num_csvm_jets30==3", "3 CSVM");
  PrintLine(baseline+"num_csvm_jets30>3",">=4 CSVM");

  fclose(file);

}
