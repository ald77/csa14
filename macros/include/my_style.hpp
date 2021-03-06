#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPave.h"
#include "TLatex.h"
#include "TString.h"
#include "TH1.h"
#include "TLine.h"
#include "TColor.h"

TColor uscb_blue(1000, 1/255.,57/255.,166/255.);
TColor uscb_gold(1001, 255/255.,200/255.,47/255);
TColor penn_red(1002, 149/255.,0/255.,26/255.);
TColor pantone(1003, 255/255.,88/255.,0/255.);
TColor uo_green(1004, 0/255.,79/255.,39/255.);
TColor tcu_purple(1005, 52/255.,42/255.,123/255.);
TColor tar_heel_blue(1006, 86/255.,160/255.,211/255.);

void set_style(TH1 * h, const TString& p) {


  if (p.Contains("t1bbbb")) {
    h->SetFillColor (2);
    h->SetMarkerColor(2);
  } else if(p.Contains("t1tttt")) {
    h->SetFillColor(6);
    h->SetMarkerColor(6);
  }  else if (p == "data_obs") {
    h->SetMarkerSize(0.8);
    h->SetMarkerStyle(20);
  } else {
    h->SetLineColor(kBlack);
    if (p == "znn") {
      h->SetFillColor(1002);
      h->SetMarkerColor(1002);
    } else if (p == "qcd") {
      h->SetFillColor (1001);
      h->SetMarkerColor(1001);
    } else if (p == "ttbar") {
      h->SetFillColor(1000);
      h->SetMarkerColor(1000);
    } else if (p == "wjets") {
      h->SetFillColor (1004);
      h->SetMarkerColor(1004);
    } else if (p == "single_top") {
      h->SetFillColor (1005);
      h->SetMarkerColor(1005);
    } else if (p == "other") {
      h->SetFillColor (1003);
      h->SetMarkerColor(1003);
    } else if (p== "bg") {
      h->SetFillColor(kAzure+1);
      h->SetMarkerColor(kAzure+1);
    }
  }
  return;
}

void set_style(TLegend* leg, float text_size=0.045, bool transparent=false) {
  if (transparent) leg->SetFillStyle(0);
  leg->SetFillStyle(0);
  leg->SetLineColor(0);
  leg->SetShadowColor(0);
  leg->SetTextFont(62);
  leg->SetTextSize(text_size);
  leg->SetBorderSize(1);
  return;
}

void set_style(TLine* line) {
  line->SetLineColor(kGray+3);
  line->SetLineWidth(4);
  line->SetLineStyle(7);
}

void setTDRStyle(TStyle* tdrStyle) {

  // TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(2);

  // For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(3); // Jack;
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(1);
  //GHM  tdrStyle->SetEndErrorSize(2);
  //tdrStyle->SetErrorMarker(20);
  //tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.15);
  tdrStyle->SetPadRightMargin(0.03);

  // For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.25);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  // Jack
  tdrStyle->cd();

}
