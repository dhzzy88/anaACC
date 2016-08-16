#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../tunefits/ana_idv2.h"
#include "../tunefits/Style.h"
#include "Run8dA_pid.C"

TH2F *h_m2accTru[6];
TH2F *h_m2accFls[6];
TH2F *h_m2tofRaw[6];
TH2F *h_nphotvsm2[5][6][40];

float pionmass = 0.013;
float kaonmass = 0.225;
float protmass = 0.873;

TLine *l_pion;
TLine *l_kaon;
TLine *l_prot;
TLine *l_accthresh;


void idTofAcc()
{
  l_pion = new TLine(pionmass,0,pionmass,100000000000000000000000000000000000000000000);
  l_kaon = new TLine(kaonmass,0,kaonmass,100000000000000000000000000000000000000000000);
  l_prot = new TLine(protmass,0,protmass,100000000000000000000000000000000000000000000);
  l_pion->SetLineStyle(9); l_pion->SetLineWidth(3); 
  l_kaon->SetLineStyle(9); l_kaon->SetLineWidth(3); 
  l_prot->SetLineStyle(9); l_prot->SetLineWidth(3); 
  TFile inFile("accanatree7498.root");
  TList *rawlist = new TList; 
  TList *flslist = new TList; 
  TList *trulist = new TList; 

  char getHistName[256];
  
  c_nphot = new TCanvas("c_nphot","c_nphot",4000,4000);
  c_nphot->Divide(5,5);
  c_compare = new TCanvas("c_compare","c_compare",4000,4000);
  c_compare->Divide(5,5);
  

  char titlestring[128];
  for(int icent=0; icent<=4;icent++)
  {
    for(int idphi=0; idphi<=5;idphi++)
    {
      for(int ptbin=1; ptbin<=23;ptbin++)
      {
        float accthresh = setACCthresh(ptbin);
        sprintf(getHistName,"h_m2tofvsacc_icent%i_idphi%i_pt%i",icent,idphi,ptbin);
        h_nphotvsm2[icent][idphi][ptbin] = (TH2F*)inFile.Get(getHistName);

        c_nphot->cd(ptbin);
        gPad->SetLogz();
        gPad->SetLogy();
        if(ptbin>12) h_nphotvsm2[icent][idphi][ptbin]->RebinX(2);
        h_nphotvsm2[icent][idphi][ptbin]->GetXaxis()->SetRangeUser(-0.5,1.5);
        h_nphotvsm2[icent][idphi][ptbin]->Draw("colz");
        sprintf(titlestring,"N photoelectrons vs m2tof, %f < pT < %f; m2tof (GeV/c^2); N p.e.",ptbin*0.2+0.5,ptbin*0.2+0.2+0.5);
        l_accthresh = new TLine(-1,accthresh,5,accthresh);
        l_accthresh->SetLineStyle(9); l_accthresh->SetLineWidth(3); 
        l_pion->Draw("same");
        l_kaon->Draw("same");
        l_prot->Draw("same");
        l_accthresh->Draw("same");

        h_nphotvsm2[icent][idphi][ptbin]->SetTitle(titlestring);
        
        TCanvas *cstore = trackSorter(h_nphotvsm2[icent][idphi][ptbin],accthresh,ptbin)->Clone();
        c_compare->cd(ptbin);
        cstore->DrawClonePad();
      }


    sprintf(titlestring,"PSgifs/acccompare_cent%i_dphi%i.gif",icent,idphi);
    c_compare->SaveAs(titlestring);
    sprintf(titlestring,"PSgifs/nphotvsm2_cent%i_dphi%i.gif",icent,idphi);  
    c_nphot->SaveAs(titlestring);
    }
    
    TH2F *h_nphotvsm2all;
    TH2F *h_nphotvsm2all = ( TH2F *)h_nphotvsm2[0][0][17]->Clone("h_nphotvsm2all");
    h_nphotvsm2all->Add(h_nphotvsm2[0][1][17],1);
    h_nphotvsm2all->Add(h_nphotvsm2[0][2][17],1);
    h_nphotvsm2all->Add(h_nphotvsm2[0][3][17],1);
    h_nphotvsm2all->Add(h_nphotvsm2[0][4][17],1);
    h_nphotvsm2all->Add(h_nphotvsm2[0][5][17],1);
    c_all = new TCanvas("c_all", "c_all", 2000,2000);
    c_all->cd();
    h_nphotvsm2all->Draw("colz");
    c_all->SetLogy();
    c_all->SetLogz();
    c_all->SaveAs("nphotvsm2_cent0_all.gif");
  }

  for(int idphi=0 ; idphi<=5 ; idphi++) {
    //idphi[idphi] = idphi*M_PI / 6 + M_PI/12;

    parfile << "PIONS  | \t idphi: \t" << idphi << "\t mean:\t" << chkpionmean[idphi] << "\t mean err:\t" << chkpionmeanerr[idphi] << "\t width:\t" << chkpionwidth[idphi] << "\t width err: \t"<< chkpionwidtherr[idphi] << "\t yield:\t" << chkpionyield[idphi] << "\t yield err:\t" << chkpionyielderr[idphi] << endl;
    parfile << "KAONS  | \t idphi: \t" << idphi << "\t mean:\t" << chkkaonmean[idphi] << "\t mean err:\t" << chkkaonmeanerr[idphi] << "\t width:\t" << chkkaonwidth[idphi] << "\t width err: \t"<< chkkaonwidtherr[idphi] << "\t yield:\t" << chkkaonyield[idphi] << "\t yield err:\t" << chkkaonyielderr[idphi] << endl;
    parfile << "PROTONS| \t idphi: \t" << idphi << "\t mean:\t" << chkprotmean[idphi] << "\t mean err:\t" << chkprotmeanerr[idphi] << "\t width:\t" << chkprotwidth[idphi] << "\t width err: \t"<< chkprotwidtherr[idphi] << "\t yield:\t" << chkprotyield[idphi] << "\t yield err:\t" << chkprotyielderr[idphi] << endl;
    parfile << endl;
  }
  parfile << endl << endl << endl;

return;

  for(int centbin=1; centbin<=5;centbin++)
  {
    sprintf(getHistName,"h_m2tofwacc_cent%i",centbin);
    h_m2accTru[centbin] = (TH2F*)inFile.Get(getHistName);
    sprintf(getHistName,"h_m2tofnoacc_cent%i",centbin); 
    h_m2accFls[centbin] = (TH2F*)inFile.Get(getHistName);
    sprintf(getHistName,"h_m2tofraw_cent%i",centbin);
    h_m2tofRaw[centbin] = (TH2F*)inFile.Get(getHistName);

    rawlist->Add(h_m2tofRaw[centbin]);  
    flslist->Add(h_m2accFls[centbin]);  
    trulist->Add(h_m2accTru[centbin]);  
  }


  TH2F *h_Raw = new TH2F; 
  TH2F *h_Tru = new TH2F;
  TH2F *h_Fls = new TH2F;

  h_Raw = (TH2F*)h_m2tofRaw[1]->Clone("h_m2Raw"); cout << "raw" << endl;  
  h_Fls = (TH2F*)h_m2accFls[1]->Clone("h_m2Fls"); cout << "false" << endl;
  h_Tru = (TH2F*)h_m2accTru[1]->Clone("h_m2Tru"); cout << "true" << endl;

  h_Raw->Reset();
  h_Tru->Reset();
  h_Fls->Reset();

  h_Tru->Merge(trulist);
  h_Fls->Merge(flslist);
  h_Raw->Merge(rawlist);
  
  h_m2tofRaw[0] = *h_Raw;
  h_m2accFls[0] = *h_Fls;
  h_m2accTru[0] = *h_Tru;

  cPS = new TCanvas("cPS","cPS",4000,4000);
  cPS->Divide(1,2);
  cPS->cd(1);	 h_m2tofRaw[0]->Draw("colz");  gPad->SetLogz();
  cPS->cd(2);	 h_m2accTru[0]->Draw("colz");  gPad->SetLogz();
  cPS->SaveAs("check.gif");
  
  SlicetoPScompare(h_m2tofRaw[0],h_m2accFls[0],0.5,1.5,.2);



}

void SlicetoPScompare(TH2F *h2raw, TH2F *h2nop,float minpt, float maxpt, float binsize)
{
  int minptbin = minpt / binsize;	int maxptbin = maxpt / binsize;
  int nptbins = h2raw->GetNbinsY();
  float min_hist_pt = h2raw->GetYaxis()->GetBinCenter(0);   
  float max_hist_pt = h2raw->GetYaxis()->GetBinCenter(nptbins);
  float hist_binsize = max_hist_pt / nptbins;
  cSideBySide = new TCanvas("cSideBySide","cSideBySide",1200,800);
  c1 = new TCanvas;
  c2 = new TCanvas;
  cPS = new TCanvas("cPS","cPS",8000,4000);
  //cout << "busted" << endl;
  char gifname[64]; 
  cPS->Divide(5,4);
 
  char title[128];

  //cout << minptbin << "\t" << maxptbin << "\t" << maxptbin - minptbin <<  endl;
  char savename[64];
  for(int ipt=1; ipt<=20; ipt++)
  {
    cSideBySide->Divide(2,1);
    int jbin = ipt*2;
    
    cout << ipt << "\t" << jbin << "\t" << h2raw->GetYaxis()->GetBinCenter(jbin) << endl;
    htraw = (TH1D *) h2raw->ProjectionX("htraw",jbin-2,jbin);
    htnop = (TH1D *) h2nop->ProjectionX("htnop",jbin-2,jbin);
    //c1->cd();
    htnop->SetLineColor(2);   htnop->Rebin(5,"htnop");  //red
    htraw->SetLineColor(1);   htraw->Rebin(5,"htraw");  //black
    //sprintf(title,"m2, %f<pT<%f, N p.e. > 5",h2raw->GetYaxis()->GetBinCenter(jbin-5),h2raw->GetYaxis()->GetBinCenter(jbin));
    sprintf(title,"m2, %f<pT<%f, Raw TOF",h2raw->GetYaxis()->GetBinCenter(jbin-2),h2raw->GetYaxis()->GetBinCenter(jbin));
    htraw->SetTitle(title); 
    sprintf(title,"m2, %f<pT<%f, N p.e. < 5",h2raw->GetYaxis()->GetBinCenter(jbin-2),h2raw->GetYaxis()->GetBinCenter(jbin));
    htnop->SetTitle(title);

    //htraw->Draw();      htnop->Draw("same");
    c1 = fit_m2_2gaus(htraw,1,1,0,0,jbin);
    if( ipt % 2 )c1->SetFillColor(17);
    cSideBySide->cd(1);   c1->DrawClonePad();  
    c1->Clear();
    
    c2 = fit_m2_2gaus(htnop,1,1,0,0,jbin);
    if( ipt % 2 )c2->SetFillColor(17);
    cSideBySide->cd(2);   c2->DrawClonePad();  
    c2->Clear();
    //gPad->Update();
    cPS->cd(ipt);
    if( ipt % 2 ) cSideBySide->SetFillColor(19); 
    cSideBySide->DrawClonePad();
    sprintf(savename,"m2acccompare_%ipt.gif",ipt);
    cSideBySide->SaveAs(savename);
    cSideBySide->Clear();
    //cout << h->GetNbinsX() << endl;
    //h = (TH1D *) ht->Rebin(2,"h");

  }

  cPS->SaveAs("m2TofAccCompare.gif");
}


void SlicetoPSv0(TH2F *h2in,int cent, int tof, int idphi, int charge)
{
  TF1 *f_pi;
  TF1 *f_k;
  TF1 *f_pr;
  TF1 *f_all;
  c1 = new TCanvas;
  cPS = new TCanvas("cPS","cPS",4000,4000);
  cout << "busted" << endl;
  char gifname[64];
  cPS->Divide(6,6);
  TH1D* h;
  //cout << "in pT bin: ";
  //h2in->RebinY();
  for(int ipt=minptbin; ipt<=maxptbin+1; ipt++)
  {
    //cout << ipt-minptbin+1 << " ";
    ht = (TH1D *) h2in->ProjectionX("ht",ipt+1,ipt+1);
    //cout << h->GetNbinsX() << endl;
    h = (TH1D *) ht->Rebin(2,"h");
    c1 = fit_m2_2gaus(h,cent,tof,charge,idphi,ipt);

    //c->cd();
    //h->Draw();
    //f_pi = fit_m2pi(h);
    //f_k = fit_m2k(h);
    //f_pr = fit_m2prot(h);

    //f_all->Draw("same");
    cPS->cd(ipt-minptbin+1);
    c1->DrawClonePad();
    //sprintf(gifname,"PSgifs/test%i.gif",ipt);
    //c1->SaveAs(gifname);
  }
  //for(int ipt=maxptbin-13; ipt<=maxptbin+1; ipt+=2)  // combine two pt bins into one for higher pT.
  //{
  //  ht = (TH1D *) h2in->ProjectionX("ht",ipt+1,ipt+1);
  //  ht2 = (TH1D *) h2in->ProjectionX("ht2",ipt+2,ipt+2);
  //  ht->Add(ht2);
  //  h = (TH1D *) ht->Rebin(2,"h");
  //  c1 = fit_m2_2gaus(h,cent,tof,charge,idphi,ipt);
  //  cPS->cd(ipt-minptbin+1);
  //  c1->DrawClonePad();
  //}

  sprintf(gifname,"PSgifs/%s_PS.gif",h2in->GetName());
  cPS->SaveAs(gifname);

  //delete c;
  delete c1;
  delete cPS;

  //cout << endl;

  return;
}

TCanvas * trackSorter(TH2F *h2in, int accthreshold, int ptbin)
{
  float binwidth = 0.2;

  char titlestring[128];
  int maxbin = h2in->GetNbinsY();
  int midbin = h2in->GetYaxis()->FindBin(accthreshold);
  int lowbin = 0; 
  cout << "plotting: " << lowbin << " to " << midbin << " to " << maxbin << endl;

  TH1D * hfire = h2in->ProjectionX("hfire",midbin+1,maxbin);
  TH1D * hveto = h2in->ProjectionX("hveto",lowbin,midbin);
  TH1D * hboth = h2in->ProjectionX("hboth",lowbin,maxbin);

  c_acccompare = new TCanvas("c_acccompare","c_acccompare",500,500);
  c_acccompare->cd();
  sprintf(titlestring,"m^{2}_{TOF}, %g<pT<%g GeV/c; m^{2}_{TOF} (GeV/c^2); N",ptbin*binwidth+0.5,0.5+ptbin*binwidth+binwidth);
  cout << "pT bin: " << ptbin << " writing: " <<titlestring << endl;
  hboth->SetTitle(titlestring);
  hboth->Draw();
  hboth->SetLineColor(kBlack);
  hveto->Draw("same");
  hveto->SetLineColor(kRed);
  hfire->Draw("same");
  hfire->SetLineColor(kBlue);

  hboth->SetLineWidth(2);
  hveto->SetLineWidth(2);
  hfire->SetLineWidth(2);

  l_pion->Draw("same");
  l_kaon->Draw("same");
  l_prot->Draw("same");


  //c_acccompare->SaveAs("acccompare.jpg");
  return c_acccompare;
}

float setACCthresh(int ptbin)
{
  float thresh=0;
  if(ptbin==7)  thresh=3;
  if(ptbin>=8)  thresh=4;
  if(ptbin>=11)  thresh=5;
  if(ptbin>=13)  thresh=6;
  if(ptbin>=16)  thresh=2;

  return thresh;
}