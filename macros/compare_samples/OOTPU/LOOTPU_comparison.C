#include "TH1.h"
#include "TFile.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TMath.h"
#include "TLegend.h"
#include "TCut.h"

void ootpu_comparison(TString files, TString var, TString title, int nbins, float low, float high, TString comments="") {

  TChain* chain = new TChain("reduced_tree");
  chain->Add(files);

  TH1F* h5to15 = new TH1F("h5to15",title, nbins, low, high);
  TH1F* h15to20 = new TH1F("h15to20",title, nbins, low, high);
  TH1F* h20to25 = new TH1F("h20to25",title, nbins, low, high);
  TH1F* h25to35 = new TH1F("h25to35",title, nbins, low, high);
  h5to15->SetStats(0);
  h5to15->GetYaxis()->SetLabelSize(0.04);
  //h5to15->GetYaxis()->SetTitleOffset(1.3);
  h5to15->GetXaxis()->SetTitleOffset(1.1);
  h5to15->GetXaxis()->SetTitleFont(132);
  h5to15->GetXaxis()->SetTitleSize(0.042);
  h5to15->GetXaxis()->SetLabelSize(0.04);
  h5to15->SetLineWidth(2);

  TCut mu("num_gen_muons==1&&muon_reco_match>=0");
  chain->Project("h5to15", var, mu+"loot_pu>=5&&loot_pu<15");
  chain->Project("h15to20", var, mu+"loot_pu>=15&&loot_pu<20");
  chain->Project("h20to25", var, mu+"loot_pu>=20&&loot_pu<25");
  chain->Project("h25to35", var, mu+"loot_pu>=25&&loot_pu<35");

  float avg1(h5to15->GetMean());
  float avg2(h15to20->GetMean());
  float avg3(h20to25->GetMean());
  float avg4(h25to35->GetMean());

  h5to15->Scale(1/h5to15->Integral());
  h15to20->Scale(1/h15to20->Integral());
  h20to25->Scale(1/h20to25->Integral());
  h25to35->Scale(1/h25to35->Integral());

  h5to15->SetLineColor(1);
  h15to20->SetLineColor(2);
  h20to25->SetLineColor(3);
  h25to35->SetLineColor(4);

  h5to15->SetLineWidth(2);
  h15to20->SetLineWidth(2);
  h20to25->SetLineWidth(2);
  h25to35->SetLineWidth(2);

  TCanvas* c1 = new TCanvas();
  float max = TMath::Max(h5to15->GetMaximum(), h15to20->GetMaximum());
  if (h20to25->GetMaximum()>max) max = h20to25->GetMaximum();
  if (h25to35->GetMaximum()>max) max = h25to35->GetMaximum();

  h5to15->SetMaximum(max*1.1);
  h5to15->Draw("hist");
  h15to20->Draw("hist,same");
  h20to25->Draw("hist,same");
  h25to35->Draw("hist,same");

  TLegend* leg = new TLegend(0.45,0.6,0.9,0.9);
  char label[1000];
  sprintf(label,"5#leqLate OOTPU<15 (#mu=%3.3f)",avg1);
  leg->AddEntry(h5to15,label,"lp");
  sprintf(label,"15#leqLate OOTPU<20 (#mu=%3.3f)",avg2);
  leg->AddEntry(h15to20,label,"lp");
  sprintf(label,"20#leqLate OOTPU<25 (#mu=%3.3f)",avg3);
  leg->AddEntry(h20to25,label,"lp");
  sprintf(label,"25#leqLate OOTPU<35 (#mu=%3.3f)",avg4);
  leg->AddEntry(h25to35,label,"lp");
  leg->Draw();

  TString plotTitle ="relIso_vs_LOOTPU_"+var+comments+".pdf";
  c1->Print(plotTitle);
}