#pragma once

#include <TH1.h>
#include <TPad.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>

namespace htt_style {
/// define common styles
void SetStyle();
/// create a canveas in common style (default is square)
TCanvas* MakeCanvas(const char* name, const char* title, int dX=600, int dY=600);
/// define common style of pads
void InitSubPad(TPad* pad, int i);
/// define a histogram file (not yet including poly markers, which are used fro data)
void InitHist(TH1* hist, const char* xtit, const char* ytit="Number of Entries", int color=kBlack, int style=0);
/// define poly markers and line width for data
void InitData(TH1* hist);
/// define line style, width and color for signal sample
void InitSignal(TH1* hist);
/// define common legend style 
void SetLegendStyle(TLegend* leg);
/// add CMSPreliminary logo, lumi and channel
void CMSPrelim(const char* dataset, const char* channel, double lowX=0.4, double lowY=0.74);

inline void SetStyle()
{
  TStyle *HttStyle = new TStyle("Htt-Style","The Perfect Style for Plots ;-)");
  gStyle = HttStyle;

  // Canvas
  HttStyle->SetCanvasColor     (0);
  HttStyle->SetCanvasBorderSize(10);
  HttStyle->SetCanvasBorderMode(0);
  HttStyle->SetCanvasDefH      (700);
  HttStyle->SetCanvasDefW      (700);
  HttStyle->SetCanvasDefX      (100);
  HttStyle->SetCanvasDefY      (100);

  // color palette for 2D temperature plots
  HttStyle->SetPalette(1,0);

  // Pads
  HttStyle->SetPadColor       (0);
  HttStyle->SetPadBorderSize  (10);
  HttStyle->SetPadBorderMode  (0);
  HttStyle->SetPadBottomMargin(0.13f);
  HttStyle->SetPadTopMargin   (0.08f);
  HttStyle->SetPadLeftMargin  (0.15f);
  HttStyle->SetPadRightMargin (0.05f);
  HttStyle->SetPadGridX       (0);
  HttStyle->SetPadGridY       (0);
  HttStyle->SetPadTickX       (1);
  HttStyle->SetPadTickY       (1);

  // Frames
  HttStyle->SetLineWidth(3);
  HttStyle->SetFrameFillStyle ( 0);
  HttStyle->SetFrameFillColor ( 0);
  HttStyle->SetFrameLineColor ( 1);
  HttStyle->SetFrameLineStyle ( 0);
  HttStyle->SetFrameLineWidth ( 2);
  HttStyle->SetFrameBorderSize(10);
  HttStyle->SetFrameBorderMode( 0);

  // Histograms
  HttStyle->SetHistFillColor(2);
  HttStyle->SetHistFillStyle(0);
  HttStyle->SetHistLineColor(1);
  HttStyle->SetHistLineStyle(0);
  HttStyle->SetHistLineWidth(3);
  HttStyle->SetNdivisions(505, "X");

  // Functions
  HttStyle->SetFuncColor(1);
  HttStyle->SetFuncStyle(0);
  HttStyle->SetFuncWidth(2);

  // Various
  HttStyle->SetMarkerStyle(20);
  HttStyle->SetMarkerColor(kBlack);
  HttStyle->SetMarkerSize (1.1f);

  HttStyle->SetTitleBorderSize(0);
  HttStyle->SetTitleFillColor (0);
  HttStyle->SetTitleX         (0.2f);

  HttStyle->SetTitleSize  (0.055f,"X");
  HttStyle->SetTitleOffset(1.200f,"X");
  HttStyle->SetLabelOffset(0.005f,"X");
  HttStyle->SetLabelSize  (0.040f,"X");
  HttStyle->SetLabelFont  (42   ,"X");

  HttStyle->SetStripDecimals(kFALSE);
  HttStyle->SetLineStyleString(11,"20 10");

  HttStyle->SetTitleSize  (0.055f,"Y");
  HttStyle->SetTitleOffset(1.600f,"Y");
  HttStyle->SetLabelOffset(0.010f,"Y");
  HttStyle->SetLabelSize  (0.040f,"Y");
  HttStyle->SetLabelFont  (42   ,"Y");

  HttStyle->SetTextSize   (0.055f);
  HttStyle->SetTextFont   (42);

  HttStyle->SetStatFont   (42);
  HttStyle->SetTitleFont  (42);
  HttStyle->SetTitleFont  (42,"X");
  HttStyle->SetTitleFont  (42,"Y");

  HttStyle->SetOptStat    (0);
  return;
}

inline TCanvas* MakeCanvas(const char* name, const char *title, int dX, int dY)
{
  // Start with a canvas
  TCanvas *canvas = new TCanvas(name,title,0,0,dX,dY);
  // General overall stuff
  canvas->SetFillColor      (0);
  canvas->SetBorderMode     (0);
  canvas->SetBorderSize     (10);
  // Set margins to reasonable defaults
  canvas->SetLeftMargin     (0.18f);
  canvas->SetRightMargin    (0.05f);
  canvas->SetTopMargin      (0.08f);
  canvas->SetBottomMargin   (0.15f);
  // Setup a frame which makes sense
  canvas->SetFrameFillStyle (0);
  canvas->SetFrameLineStyle (0);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameBorderSize(10);
  canvas->SetFrameFillStyle (0);
  canvas->SetFrameLineStyle (0);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameBorderSize(10);

  return canvas;
}

inline void InitSubPad(TPad* pad, int i)
{
  pad->cd(i);
  TPad *tmpPad = dynamic_cast<TPad*>(pad->GetPad(i));
  tmpPad->SetLeftMargin  (0.18f);
  tmpPad->SetTopMargin   (0.05f);
  tmpPad->SetRightMargin (0.07f);
  tmpPad->SetBottomMargin(0.15f);
  return;
}

inline void InitSignal(TH1 *hist)
{
  hist->SetFillStyle(0.);
  hist->SetLineStyle(11);
  hist->SetLineWidth(3.);
  hist->SetLineColor(kBlue);
  //hist->SetLineColor(kBlue+3);
}

inline void InitHist(TH1 *hist, const char *xtit, const char *ytit, Color_t color, Style_t style)
{
  hist->SetXTitle(xtit);
  hist->SetYTitle(ytit);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(    3.);
  hist->SetFillColor(color );
  hist->SetFillStyle(style );
  hist->SetTitleSize  (0.055f,"Y");
  hist->SetTitleOffset(1.600f,"Y");
  hist->SetLabelOffset(0.014f,"Y");
  hist->SetLabelSize  (0.040f,"Y");
  hist->SetLabelFont  (42   ,"Y");
  hist->SetTitleSize  (0.055f,"X");
  hist->SetTitleOffset(1.300f,"X");
  hist->SetLabelOffset(0.014f,"X");
  hist->SetLabelSize  (0.040f,"X");
  hist->SetLabelFont  (42   ,"X");
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (0.6f);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetXaxis()->SetTitleFont(42);
  hist->SetTitle("");
  return;
}

inline void InitData(TH1* hist)
{
  hist->SetMarkerStyle(20.);
  hist->SetMarkerSize (1.3f);
  hist->SetLineWidth  ( 3.);
}

inline void SetLegendStyle(TLegend* leg)
{
  leg->SetFillStyle (0);
  leg->SetFillColor (0);
  leg->SetBorderSize(0);
}

inline void CMSPrelim(const char* dataset, const char* channel, double lowX, double lowY)
{
  /*
  TPaveText* cmsprel  = new TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC");
  cmsprel->SetBorderSize(   0 );
  cmsprel->SetFillStyle(    0 );
  cmsprel->SetTextAlign(   12 );
  cmsprel->SetTextSize ( 0.03 );
  cmsprel->SetTextColor(    1 );
  cmsprel->SetTextFont (   62 );
  cmsprel->AddText("CMS");
  cmsprel->Draw();

  TPaveText* lumi     = new TPaveText(lowX+0.08, lowY+0.061, lowX+0.45, lowY+0.161, "NDC");
  */

  TPaveText* lumi  = new TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC");
  lumi->SetBorderSize(   0 );
  lumi->SetFillStyle(    0 );
  lumi->SetTextAlign(   12 );
  lumi->SetTextSize ( 0.035f );
  lumi->SetTextColor(    1 );
  lumi->SetTextFont (   62 );
  lumi->AddText(dataset);
  lumi->Draw();

  TPaveText* chan     = new TPaveText(lowX+0.68, lowY+0.061, lowX+0.80, lowY+0.161, "NDC");
  chan->SetBorderSize(   0 );
  chan->SetFillStyle(    0 );
  chan->SetTextAlign(   12 );
  chan->SetTextSize ( 0.04f );
  chan->SetTextColor(    1 );
  chan->SetTextFont (   62 );
  chan->AddText(channel);
  chan->Draw();
}

} // namespace htt_style
