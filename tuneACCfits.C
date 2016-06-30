#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "ana_idv2.h"
#include "Style.h"
//#include "../tunefits/Run8dA_pid.h"
#include "Run8dA_pid.h"
#include "ana_idv2.h"
#include "threegaus.C"
#include "fitInit.C"
#include "graphStyles.h"
#include "Run8dA_pidACC.C"
//#include "configACCfits.C"

TH2F *h_m2accTru[6];
TH2F *h_m2accFls[6];
TH2F *h_m2tofRaw[6];
TH2F *h_nphotvsm2[5][6][40];

TCanvas *c_accthresh[6];
TCanvas *c_m2[6];

float pionmass = 0.013;
float kaonmass = 0.225;
float protmass = 0.873;

TLine *l_pion;
TLine *l_kaon;
TLine *l_prot;
TLine *l_accthresh;



void tuneACCfits()
{
  fitInit(itof,icent,ich,ptbin);
  importfromStruct(fitTuning);
  if(ptbin< 12) { float ptrange[2] = {0.5+ptbin*0.2,0.5+(ptbin+1)*0.2};        }
  if(ptbin>=12) { float ptrange[2] = {3.0+(ptbin-12)*0.5,3.0+(ptbin-11)*0.5};  }
  char titlestring[128];
  if(fireACC == 0) {
    sprintf(titlestring,"chkparams/parbkup/v2Par_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
    ofstream parfile(titlestring);
  }
  if(fireACC == 1) {  
    sprintf(titlestring,"chkparams/parbkup/v2Par_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof+1,icent,ich,ptrange[0]*10,ptrange[1]*10);
    ofstream parfile(titlestring);
  }
  cout << "Writing v2 and fit parameters to: " << titlestring << endl;
  //ptrange[0] = ptbin*0.2;
  //ptrange[1] = (ptbin+1)*0.2;

  for(int idphi=0;idphi<=5;idphi++) {
    sprintf(titlestring,"c_accthresh%i",idphi);
    c_accthresh[idphi] = new TCanvas(titlestring,titlestring,600,600);
    sprintf(titlestring,"c_m2%i",idphi);
    c_m2[idphi] = new TCanvas(titlestring,titlestring,2000,2000);
    setupIndiv(itof+fireACC,icent,ich,idphi);
  }

  l_pion = new TLine(pionmass,0,pionmass,100000000000000000000000000000000000000000000);
  l_kaon = new TLine(kaonmass,0,kaonmass,100000000000000000000000000000000000000000000);
  l_prot = new TLine(protmass,0,protmass,100000000000000000000000000000000000000000000);
  l_pion->SetLineStyle(9); l_pion->SetLineWidth(3); 
  l_kaon->SetLineStyle(9); l_kaon->SetLineWidth(3); 
  l_prot->SetLineStyle(9); l_prot->SetLineWidth(3); 
  TFile inFile("anaacctree7498.root");
  TList *rawlist = new TList; 
  TList *flslist = new TList; 
  TList *trulist = new TList; 
 
  char getHistName[256];
  
  c_nphot = new TCanvas("c_nphot","c_nphot",3000,2000);
  c_nphot->Divide(3,2);
  c_compare = new TCanvas("c_compare","c_compare",6000,3000);
  c_compare->Divide(6,1);
  

  char titlestring[128];
  for(int idphi=0; idphi<=5;idphi++) {
    float accthresh = setACCthresh(ptbin);
    sprintf(getHistName,"h_m2tofvsacc_icent%i_ich%i_idphi%i_pt%i",icent,ich,idphi,ptbin);
    cout << "getting histogram: " << getHistName << endl;
    h_nphotvsm2[icent][idphi][ptbin] = (TH2F*)inFile.Get(getHistName);

    //c_nphot->cd(ptbin+1);
    //h_nphotvsm2[icent][idphi][ptbin]->Draw();
    TCanvas *cstore = (TCanvas*)trackSorter(h_nphotvsm2[icent][idphi][ptbin],accthresh,ptrange,ich,idphi)->Clone();
    c_compare->cd(idphi+1);
    cstore->DrawClonePad();    
  }
  sprintf(titlestring,"PSgifs/acccompare_cent%i_ich%i_accfire%i_ptbin%i.gif",icent,ich,fireACC,ptbin);
  c_compare->SaveAs(titlestring);
  //sprintf(titlestring,"PSgifs/nphotvsm2_cent%i_ptbin%i.gif",icent,ptbin);  
  //c_nphot->SaveAs(titlestring);
  if(fireACC == 0) CheckFitsEP(itof, icent, ich, ptrange);
  if(fireACC == 1) CheckFitsEP(itof+1, icent, ich, ptrange);

  TCanvas *c_PS = new TCanvas("c_PS","c_PS",6000,4000);
  c_PS->Divide(3,2);
  for(int i=1;i<=6;i++) {
    c_PS->cd(i);
    c_accthresh[i-1]->DrawClonePad();
  }
  sprintf(titlestring,"2x3/PSaccthreshold_cent%i_ich%i_accfire%i_ptbin%i.jpg",icent,ich,fireACC,ptbin);
  c_PS->SaveAs(titlestring);

  for(int i=1;i<=6;i++) {
    c_PS->cd(i);
    gPad->Clear();
    c_m2[i-1]->DrawClonePad();
  }
  sprintf(titlestring,"2x3/PSm2_cent%i_ich%i_accfire%i_ptbin%i.jpg",icent,ich,fireACC,ptbin);
  c_PS->SaveAs(titlestring);

return;

}


TCanvas * trackSorter(TH2F *h2in, int accthreshold, float ptrange[], int ich, int idphi)
{
  gStyle->SetOptStat(10);
  h2in->SetStats(0);
  cout << "sorting tracks" << endl;

  if(ptbin>12) h2in->RebinX(2);

  float binwidth = 0.2;
  
  char titlestring[128];
  int maxbin = h2in->GetNbinsY();
  int midbin = h2in->GetYaxis()->FindBin(accthreshold);
  //int midbin = 10+accthreshold;
  int lowbin = 0; 
  cout << "plotting accthresholds: " << lowbin << " to " << midbin << " to " << maxbin << endl;
  
  if(h2in->GetNbinsX() % Nrebin != 0) { 
    cout << "I can't rebin this, " << h2in->GetNbinsX() << " not divisible by " << Nrebin << "!!!" << endl;
    return;
  }

  h2in = (TH2F *) h2in->RebinX(Nrebin,"h2in");
  h2in->GetXaxis()->SetRangeUser(-0.5,1.5);
  TH1D * hfire = h2in->ProjectionX("hfire",midbin,maxbin);
  TH1D * hveto = h2in->ProjectionX("hveto",lowbin,midbin-1);
  TH1D * hboth = h2in->ProjectionX("hboth",lowbin,maxbin);

  hfire->GetXaxis()->SetRangeUser(-0.5,1.5);

  c_acccompare = new TCanvas("c_acccompare","c_acccompare",2000,500);
  c_acccompare->Divide(1,3);
  c_accthresh[idphi]->cd();
  sprintf(titlestring,"N photoelectrons vs m^{2}_{tof}, %g < pT < %g, dphi:%i; m^{2}_{tof} (GeV/c^{2}); N p.e.",ptrange[0],ptrange[1],idphi);
  l_accthresh = new TLine(-1,accthreshold+1,5,accthreshold+1);
  l_accthresh->SetLineStyle(9); l_accthresh->SetLineWidth(3); 
  gPad->SetLogz();
  gPad->SetLogy();
  gStyle->SetTitleFontSize(0.6);   gStyle->SetTitleY(1.35);
  gStyle->SetOptStat(10);
  //gStyle->SetStatX(0.5);
  //gStyle->SetStatY(0.5);
  h2in->SetTitle(titlestring);
  h2in->Draw("colz");
  l_pion->Draw("same");
  l_kaon->Draw("same");
  l_prot->Draw("same");
  l_accthresh->Draw("same");

  c_acccompare->cd(1);
  c_accthresh[idphi]->DrawClonePad();
  c_accthresh[idphi]->SaveAs("test.jpg");

  c_acccompare->cd(2);
  //gPad->SetLogy(kUseLogLowBins);
  sprintf(titlestring,"m^{2}_{TOF}, %g<pT<%g GeV/c; m^{2}_{TOF} (GeV/c^{2}); N",ptrange[0],ptrange[1]);
  hboth->SetTitle(titlestring);
  cout << "pT bin: " << ptbin << " writing: " <<titlestring << endl;
  hboth->GetXaxis()->SetRangeUser(-0.5,1.5);
  hboth->Draw();
  //hboth->SetTitleSize(0.7,"a");
  hboth->SetLineColor(kBlack);
  //hboth->SetTitle(titlestring);

  if(fireACC == 0) {
    if(useKProtfit == 0) TCanvas *ctemp = (TCanvas*)fit_m2_2gaus(hveto, 2, icent, ich, idphi, ptrange)->Clone(); //TH1D * h, int whichtof, int centbin, int charge, int idphi, float ptrange[]
    if(useKProtfit == 1) TCanvas *ctemp = (TCanvas*)fit_m2_kprot(hveto, 2, icent, ich, idphi, ptrange)->Clone(); //TH1D * h, int whichtof, int centbin, int charge, int idphi, float ptrange[]
    cout << "done fitting" << endl;
    //writeFitTuning(2, icent, ich, ptrange); 
    ctemp->cd();
    sprintf(titlestring,"m^{2}_{TOF} ACC veto, %g<pT<%g GeV/c, idphi:%i; m^{2}_{TOF} (GeV/c^{2}); N",ptrange[0],ptrange[1],idphi);
    hveto->SetTitle(titlestring);
    gStyle->SetTitleFontSize(0.6);   //hveto->SetTitleY(1);
    hveto->Draw("same");
    hveto->SetLineColor(kRed);
    hveto->GetXaxis()->SetRangeUser(-0.5,1.5);
    l_pion->Draw("same");
    l_kaon->Draw("same");
    l_prot->Draw("same");
    c_m2[idphi]->cd();
    ctemp->DrawClonePad();
    c_acccompare->cd(3);
    ctemp->DrawClonePad();
  }

  if(fireACC == 1) {
    TCanvas *ctemp = (TCanvas*)fit_m2_2gaus(hfire, 3, icent, ich, idphi, ptrange)->Clone(); //TH1D * h, int whichtof, int centbin, int charge, int idphi, float ptrange[]
    //writeFitTuning(3, icent, ich, ptrange);
    ctemp->cd();
    sprintf(titlestring,"m^{2}_{TOF} ACC fire, %g<pT<%g GeV/c; m^{2}_{TOF} (GeV/c^2); N",ptrange[0],ptrange[1]);
    hfire->SetTitle(titlestring);
    hfire->Draw("same");
    gPad->SetLogy(kUseLogLowBins);
    hfire->SetLineColor(kBlue);

    hboth->SetLineWidth(2);
    hveto->SetLineWidth(2);
    hfire->SetLineWidth(2);

    l_pion->Draw("same");
    gPad->Update();
    c_m2[idphi]->cd();
    ctemp->DrawClonePad();
    c_acccompare->cd(3);
    ctemp->DrawClonePad();
    //l_kaon->Draw("same");
    //l_prot->Draw("same");
  }

  //c_acccompare->SaveAs("acccompare.jpg");
  return c_acccompare;
}

float setACCthresh(int ptbin)
{
  float thresh=0;
  if(ich == 1 && ptbin>=6)  thresh=3;
  if(ich == 1 && ptbin>=8)  thresh=2;
  if(ich == 1 && ptbin==9)  thresh=3;
  if(ich == 1 && ptbin==10)  thresh=2;
  if(ich == 1 && ptbin==11)  thresh=3;
  if(ich == 1 && ptbin>=12)  thresh=3;
  if(ich == 1 && ptbin>=13)  thresh=5;
  if(ich == 1 && ptbin>=16)  thresh=2;  

  if(ich == 0 && ptbin>=6)  thresh=3;
  if(ich == 0 && ptbin>=8)  thresh=2;
  if(ich == 0 && ptbin==9)  thresh=3;
  if(ich == 0 && ptbin==10)  thresh=2;
  if(ich == 0 && ptbin==11)  thresh=3;
  if(ich == 0 && ptbin==12)  thresh=2;
  if(ich == 0 && ptbin>=13)  thresh=5;
  if(ich == 0 && ptbin>=16)  thresh=2;

  return thresh;
}

float rawHitCountACC(TH2F *h2in, int accrange[]) {
  float binwidth = 0.2;
  
  char titlestring[128];
  int maxbin = h2in->GetYaxis()->FindBin(accrange[0]);
  int lowbin = h2in->GetYaxis()->FindBin(accrange[1]);

  cout << "counting n tracks within the ACC N photon range: " << lowbin << " to " << maxbin << endl;
  
  if(h2in->GetNbinsX() % Nrebin != 0) { 
    cout << "I can't rebin this, " << h2in->GetNbinsX() << " not divisible by " << Nrebin << "!!!" << endl;
    return;
  }

  TH1D * htemp = h2in->ProjectionX("htemp",lowbin,maxbin);
  return htemp->GetEntries();

}