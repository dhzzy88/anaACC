//#include "/phenix/hhj/mmendoza/Style.h"
#include "../tunefits/ana_idv2.h"
//#include "../tunefits/drawYield.C"

//#include "Run8dA_pid.h"

int minptbin=4;
int maxptbin=40;  //40

//TCanvas *c_h = new TCanvas("c_h","c_h",500,500);
TCanvas *canvas = new TCanvas("canvas","canvas",1500,1500);
TH1F * h_m2vspt_allphi;

void Run8dA_pid()
{
  
  TFile infile("anaacc2698.root");
  setup();
  TH2F *h2_m2vspt_v2_temp[2][2][5][35];  
  TH2F *h2_m2vspt_v2[2][2][5][35];  
  h2temp = new TH2F;
  char histgrab[128];
  int histnum = 0;

  cout << "now plotting: " << endl;
  for(int ich=0 ; ich<2 ; ich++) {
    for(int itof=0 ; itof<2 ; itof++) {
      for(int icent=0 ; icent<5 ; icent++) {
        
        for(int iphi=0 ; iphi<=32 ; iphi++) {
          sprintf(histgrab,"h2_m2vspt_dphi%i_ch%i_itof%i_cent%i",iphi,ich,itof,icent);
          h2_m2vspt_v2_temp[ich][itof][icent][iphi] = (TH2F*)infile.Get(histgrab);
          //cout << "loading: " << h2_m2vspt_v2_temp[ich][itof][icent][iphi] << endl;
          //if(icent==0)
          //{
          //  if(iphi==0) h2temp = h2_m2vspt_v2[ich][itof][icent][iphi];
          //  h2temp->Add(h2_m2vspt_v2[ich][itof][icent][iphi]);
          //}
        } 


        int newbins = 0;
        for(iphi=0;iphi<=28;iphi+=4)
        { 
          //cout << "\t" << histnum << "\t" << iphi << "\t" << newbins << endl;    histnum++;
          h2_m2vspt_v2[ich][itof][icent][newbins] = h2_m2vspt_v2_temp[ich][itof][icent][iphi];
          h2_m2vspt_v2[ich][itof][icent][newbins]->Add(h2_m2vspt_v2_temp[ich][itof][icent][iphi+1]);
          h2_m2vspt_v2[ich][itof][icent][newbins]->Add(h2_m2vspt_v2_temp[ich][itof][icent][iphi+2]);
          h2_m2vspt_v2[ich][itof][icent][newbins]->Add(h2_m2vspt_v2_temp[ich][itof][icent][iphi+3]);
          SlicetoPS(h2_m2vspt_v2[ich][itof][icent][newbins],icent,itof,newbins,ich);
          newbins++; //remaps original phibins to smaller arrays
          //cout << "add : " << iphi << "\t" << iphi+1 << "\t" << iphi+2 << "\t" << iphi+3 << endl;
        }
      } 
    } 
  }

cout << "finished slicing" << endl;  

/*
  
*/

  //SlicetoPS(h2_m2vspt_v2_temp[0][1][2][7],2,1,7,0);  //void SlicetoPS(TH2F *h2in,int cent, int tof, int idphi, int charge)

  //h2temp->ProjectionX("h");
  //canvas->cd();
  //h->Draw();
  //canvas->SetLogy();
  //TF1 *ft1 = fit_m2pi(h)->Draw("same");
  //TF1 *ft2 = fit_m2k(h)->Draw("same");
  //TF1 *ft3 = fit_m2prot(h)->Draw("same");
  ////fit_m2all(ft1,ft2,ft3)->Draw("same");
  //canvas->SaveAs("h2temp.gif");





  //setup();

  //cout << h2->GetYaxis()->GetNbins() << endl;
  //Slicer(h2,0.5,5); // (input 2d hist, pt minf, pt max)
  /*
  for(int i=0; i<=1; i++) {    //which tof 0-east, 1-west
    for(int j=0; j<=1; j++) {  //charge 0-neg, 1-pos
      for(int k=0; k<=4; k++) { //centbin 0 - MB, 1 - 0-20, 2 - 20-40, 3 - 40-60, 4 - 60-88
      
    //int i=0;  int j=0;  int k=0;
    
    //fitm2(i,j,k,thisptonly);  //slices into ptbins and fits for 
    

    }//cent
    }//charge
  }//tof
  */
  //draw_postagestamps();
  
  
  write();
}


void SlicetoPS(TH2F *h2in,int cent, int tof, int idphi, int charge)
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

TCanvas * fit_m2_2gaus(TH1D * h, int centbin, int whichtof, int charge, int idphi, int iptbin)
{
  //ofstream fm2pion(fPar+whichtoflabel[whichtof]+"_"+fPart[0]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  //ofstream fm2kaon(fPar+whichtoflabel[whichtof]+"_"+fPart[1]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  //ofstream fm2proton(fPar+whichtoflabel[whichtof]+"_"+fPart[2]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  
  TCanvas * c_h = new TCanvas("c_h","c_h",1000,1000);
  float pt=(iptbin-4)*0.1+0.45;
  c_h->cd();
  //c_h->Clear();
    
  float par[6];
  
  bool kUseLogLowBins = 1;
  //h->Draw();
  h->Sumw2();
  h->SetAxisRange(-0.5,2.0);
  fun_pion->SetLineColor(kCyan+1);
  fun_kaon->SetLineColor(kCyan+2);
  fun_proton->SetLineColor(kCyan+3);
    
  if(iptbin<=8)     { c_h->SetLogy(kUseLogLowBins); }
  else if(iptbin>8)   { c_h->SetLogy(0); }
    
  h->Draw(); gPad->Update();
  float pionhpeak = findpeak(h,-0.1,0.1);
  float kaonhpeak = findpeak(h,0.2,0.3);
  float prothpeak = findpeak(h,0.5,1.5);

  
  //cout << "pion peak: " << pionhpeak << "\t kaon peak: " << kaonhpeak << "\t prot peak:" << prothpeak << endl;
     
   

    //Trial fit for pion
    fun1->SetRange(-0.05,0.05);
    fun1->SetParameters(1,0.02,0.02);
  //fun1->SetParameters(1,h->GetBinCenter(h->GetMaximumBin()),0.01);
  //cout << "maximum:                                " << h->GetBinCenter(h->GetMaximumBin()) << " or " << findpeak(h,0.2,0.3) << endl;
  //fun1->SetParLimits(1,-0.03,0.03);
  //fun1->SetParLimits(2,0.007,0.05);
  if(iptbin<8) {
    fun1->SetParameters(1,pionhpeak,0.02);
    fun1->SetParLimits(1,-0.03,0.09);
    fun1->SetParLimits(2,0.009,0.1);
  }
  
    h->Fit("fun1","RQ0N","same");
  
    //Trial fit for kaon
    fun2->SetRange(0.2,0.3);
    //fun2->SetParameters(1,0.25,0.02);
  fun2->SetParameters(1,kaonhpeak,0.02);
  fun2->SetParLimits(2,0.01,0.06);
  /*
  if(iptbin<5) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParameters(1,findpeak(hclone,0.2,0.3),0.02);
    fun2->SetParLimits(2,0.001,0.03);
  }
  if(iptbin<8) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParLimits(2,0.001,0.04);
  }
  if(iptbin>8) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParLimits(2,0.001,0.06);
  }
  */
    h->Fit("fun2","RQ0N","same");
  
    //Trial fit for proton
    fun3->SetRange(0.72,1.1);
    fun3->SetParameters(1,prothpeak,0.02);
    h->Fit("fun3","RQN+");

    //**********************************
    //Set initial parameters for the pion
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun1->GetParameter(ipar);
      fun1->SetParameter(ipar, par[ipar]); }
    if(iptbin>18)      { fun1->SetRange(par[1]-2.0*par[2], par[1]+1.0*par[2]); }
    else if(iptbin>28) { fun1->SetRange(-0.2, 0.1); }
    else               { fun1->SetRange(par[1]-2.0*par[2], par[1]+2.0*par[2]); }
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial pion fit, cent: " 
  //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    if(iptbin<=18) { h->Fit("fun1","RQN+","same"); }  //unquiet these later
    else           { h->Fit("fun1","RQN","same");  }  //unquiet these later

    //**********************************
    //Set initial parameters for the kaon   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun2->GetParameter(ipar);
      fun2->SetParameter(ipar, par[ipar]); }  
    //fun2->SetParLimits(2,fun1->GetParameter(2)-0.01,fun1->GetParameter(2)+0.01); //original
    //fun2->SetParLimits(2,.01,.07); //new
    fun2->SetParLimits(1, .99* kaonhpeak,1.01*kaonhpeak); //old !
  if(centbin>3) { fun2->SetParLimits(1, .99* kaonhpeak,1.05*kaonhpeak); }
    //fun2->SetParLimits(1, 0.9* findpeak(hclone,0.2,0.3),1.1* findpeak(hclone,0.2,0.3)); //new
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial kaon fit, cent: " 
  //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
  if(iptbin<=18)   { h->Fit("fun2","RQN+","same"); }  //unquiet these later
    else           { h->Fit("fun2","RQN","same");  }  //unquiet these later

    //**********************************
    //Set initial parameters for the proton   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun3->GetParameter(ipar);
      fun3->SetParameter(ipar, par[ipar]); }
    fun3->SetRange(par[1]-2.0*par[2], par[1]+2.0*par[2]);
    if(iptbin<=18) { fun3->SetRange(0.8, par[1]+1.5*par[2]); }
    fun3->SetParLimits(1,0.8,1.1);
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial proton fit, cent: " 
  //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;

    h->Fit("fun3","RQN+","same");   //unquiet this later

    //**********************************
    //Set parameters in individual pion, kaon, and proton functions
    //**********************************
    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_pion->SetParameter(ipar,   fun1->GetParameter(ipar));
      fun_pion->SetParError(ipar,    fun1->GetParError(ipar));
      fun_kaon->SetParameter(ipar,   fun2->GetParameter(ipar));
      fun_kaon->SetParError(ipar,    fun2->GetParError(ipar));
      fun_proton->SetParameter(ipar, fun3->GetParameter(ipar));
      fun_proton->SetParError(ipar,  fun3->GetParError(ipar)); }

    //cout << fun_proton->GetParameter(0) << endl;
            
    //**********************************
    // Refit pion+kaon once they merge 
    //**********************************
    if(iptbin>=18) {//18
      //Trial fit for pion+kaon
      fun->SetParameter(0,fun1->GetParameter(0));
      fun->SetParameter(1,fun1->GetParameter(1)); //mean
      fun->SetParameter(2,fun1->GetParameter(2)); //sigma
      fun->SetParameter(3,fun2->GetParameter(0));
      fun->SetParameter(4,fun2->GetParameter(1)); 
      fun->SetParameter(5,fun2->GetParameter(2));
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
      //h->Fit("fun","RQ","same"); //unquiet this later
   
      //**********************************
      //Set initial parameters for pion+kaon   
      //**********************************
    
    for(int ipar=0; ipar<6; ipar++){
    par[ipar] = fun->GetParameter(ipar);
    fun->SetParameter(ipar, par[ipar]);
    if(ipar==1) { fun->SetParLimits(ipar, -0.1,0.09); }//pion mean
    if(ipar==2) { fun->SetParLimits(ipar, 0.007,0.25); }//pion width
    if(ipar==4) { fun->SetParLimits(ipar,  0.20,0.30); }//kaon mean
    if(ipar==5) { fun->SetParLimits(ipar, -0.05, +0.05); }
    if(iptbin>18) {
      if(ipar==5) { fun->SetParLimits(ipar, -0.02, +0.02); } }
      }
      fun->SetRange(par[1]-2.0*par[2], par[4]+2.0*(par[2]+par[5]));
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~final merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
      h->Fit("fun","RQN+","same"); //unquiet this later
    
        //**********************************
        //Set parameters in individual pion and kaon functions
        //**********************************
      for(int ipar=0 ; ipar<3 ; ipar++) {
    fun_pion->SetParameter(ipar, fun->GetParameter(ipar));
    fun_pion->SetParError(ipar, fun->GetParError(ipar));
    fun_kaon->SetParameter(ipar, fun->GetParameter(ipar+3));
    fun_kaon->SetParError(ipar, fun->GetParError(ipar+3)); }
      fun_kaon->SetParameter(2, fun->GetParameter(2)+fun->GetParameter(5));
      fun_kaon->SetParError(2, fun->GetParError(2)+fun->GetParError(5)); 
      
    }//End conditional: iptbin>18


    //**********************************
    //This is the end of the fitting, just plotting now ...
    //**********************************

    setFunctionRanges(2.5);//sigma
    
    //drawFrame(gPad->GetFrame()->GetX1(),gPad->GetFrame()->GetY1(),gPad->GetFrame()->GetX2(),gPad->GetFrame()->GetY2(),"m^{2} [GeV^{2}/c^{4}]","Raw Counts");
    //char gifname[100];
    //sprintf(gifname,"%s%s%s%s%s%s%2.2f%s%2.2f","m2",whichtoflabel[whichtof].Data(),"_",chargelabel[charge].Data(),"_",centbinlabel[centbin].Data(),(iptbin)*0.1,"~",(iptbin+1)*0.1);
    //h->Draw("same");

    fun_pion->Draw("same");
    fun_kaon->Draw("same");
    fun->Draw("same");
    //fun_proton->Draw("same");
    
    char text[100];
    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{#pi}(fit) = ",fun_pion->GetParameter(1),fun_pion->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_pion->GetLineColor(),0.03,0.65,0.075);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{#pi}(fit)) = ",fun_pion->GetParameter(2),fun_pion->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_pion->GetLineColor(),0.03,0.70,0.125);

    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{k}(fit) = ",fun_kaon->GetParameter(1), fun_kaon->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_kaon->GetLineColor(),0.03,0.65,0.185);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{k}(fit)) = ",fun_kaon->GetParameter(2), fun_kaon->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_kaon->GetLineColor(),0.03,0.70,0.235);

    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{p}(fit) = ",fun_proton->GetParameter(1), fun_proton->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_proton->GetLineColor(),0.03,0.65,0.295+0.5*(iptbin>5&&iptbin<9)*kUseLogLowBins);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{p}(fit)) = ",fun_proton->GetParameter(2), fun_proton->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_proton->GetLineColor(),0.03,0.70,0.345+0.5*(iptbin>5&&iptbin<9)*kUseLogLowBins);
    
    drawLabel(TString("rootbin=")+long(iptbin),1,0.03,0.975,0.35,32);
/*
    //**********************************
    // Spit out the parameters
    //**********************************
    for(int isig=0 ; isig<3 ; isig++) {
      //Individual Pions
      gPionYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gPionYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(0)/h->GetBinWidth(0));
      gPionYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gPionYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(0)/h->GetBinWidth(0));
      double bc = h->Integral(h->FindBin(fun_pion->GetParameter(1)-fun_pion->GetParameter(2)*(1+isig)),
            h->FindBin(fun_pion->GetParameter(1)+fun_pion->GetParameter(2)*(1+isig)));
      gPionYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gPionYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gPionYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gPionYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));
      
      //Individual Kaons
      gKaonYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gKaonYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(0)/h->GetBinWidth(0));
      gKaonYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gKaonYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(0)/h->GetBinWidth(0));
      bc = h->Integral(h->FindBin(fun_kaon->GetParameter(1)-fun_kaon->GetParameter(2)*(1+isig)),
           h->FindBin(fun_kaon->GetParameter(1)+fun_kaon->GetParameter(2)*(1+isig)));
      gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));

      //Individual Kaons
      gProtYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gProtYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(0)/h->GetBinWidth(0));
      gProtYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gProtYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(0)/h->GetBinWidth(0));
      bc = h->Integral(h->FindBin(fun_proton->GetParameter(1)-fun_proton->GetParameter(2)*(1+isig)),
           h->FindBin(fun_proton->GetParameter(1)+fun_proton->GetParameter(2)*(1+isig))); 
      gProtYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gProtYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gProtYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gProtYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));
  */  
/*
    char sigbin[8];
    sprintf(sigbin,"%d",isig);
     
    ofstream fpionyield(fPar+whichtoflabel[whichtof]+"_"+fPart[0]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");
      ofstream fkaonyield(fPar+whichtoflabel[whichtof]+"_"+fPart[1]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");
      ofstream fprotyield(fPar+whichtoflabel[whichtof]+"_"+fPart[2]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");
*/
/*
    }
    
  
    gPionMass[whichtof][charge][centbin][idphi]->SetPoint(gPionMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(1));
    gPionMass[whichtof][charge][centbin][idphi]->SetPointError(gPionMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(1));
    gPionWidth[whichtof][charge][centbin][idphi]->SetPoint(gPionWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(2));
    gPionWidth[whichtof][charge][centbin][idphi]->SetPointError(gPionWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(2));
    
    gKaonMass[whichtof][charge][centbin][idphi]->SetPoint(gKaonMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(1));
    gKaonMass[whichtof][charge][centbin][idphi]->SetPointError(gKaonMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(1));
    gKaonWidth[whichtof][charge][centbin][idphi]->SetPoint(gKaonWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(2));
    gKaonWidth[whichtof][charge][centbin][idphi]->SetPointError(gKaonWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(2));
    
    gProtMass[whichtof][charge][centbin][idphi]->SetPoint(gProtMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(1));
    gProtMass[whichtof][charge][centbin][idphi]->SetPointError(gProtMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(1));
    gProtWidth[whichtof][charge][centbin][idphi]->SetPoint(gProtWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(2));
    gProtWidth[whichtof][charge][centbin][idphi]->SetPointError(gProtWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(2));
    if(iptbin<=20){
      fm2pion<<fun1->GetParameter(1)<<" "<<fun1->GetParError(1)<<endl;
      fm2pion<<fun1->GetParameter(2)<<" "<<fun1->GetParError(2)<<endl;
      
      fm2kaon<<fun2->GetParameter(1)<<" "<<fun2->GetParError(1)<<endl;
      fm2kaon<<fun2->GetParameter(2)<<" "<<fun2->GetParError(2)<<endl;
    }
    else {
      fm2pion<<fun->GetParameter(1)<<" "<<fun->GetParError(1)<<endl;
      fm2pion<<fun->GetParameter(2)<<" "<<fun->GetParError(2)<<endl;
      
      fm2kaon<<fun->GetParameter(4)<<" "<<fun->GetParError(4)<<endl;
      fm2kaon<<fun->GetParameter(5)<<" "<<fun->GetParError(5)<<endl;
    }
    fm2proton<<fun3->GetParameter(1)<<" "<<fun3->GetParError(1)<<endl;
    fm2proton<<fun3->GetParameter(2)<<" "<<fun3->GetParError(2)<<endl;
  
  
  fm2pion.close();
  fm2kaon.close();
  fm2proton.close();
*/
  //write();

    return c_h;
}

TF1 * fit_m2pi(TH1D *h)
{
	//h->Sumw2();
    h->SetAxisRange(-0.5,2.0);
    int iptbin=3;
    //if(iptbin<=8) 		{ Canvas->SetLogy(kUseLogLowBins); }
    //else if(iptbin>8) 	{ Canvas->SetLogy(0); }
    
    //h->Draw(); gPad->Update();

	TH1D *hclone = (TH1D *)h->Clone("hclone");

	float pionhpeak = findpeak(hclone,-0.1,0.1);
	
	cout << "pion peak: " << pionhpeak << "\t";
    
	 

    //Trial fit for pion
    fun1->SetRange(-0.05,0.05);
    fun1->SetParameters(1,0.02,0.02);
	//fun1->SetParameters(1,h->GetBinCenter(h->GetMaximumBin()),0.01);
	//cout << "maximum:                                " << h->GetBinCenter(h->GetMaximumBin()) << " or " << findpeak(h,0.2,0.3) << endl;
	//fun1->SetParLimits(1,-0.03,0.03);
	//fun1->SetParLimits(2,0.007,0.05);
	if(iptbin<8) {
	  fun1->SetParameters(1,pionhpeak,0.02);
	  fun1->SetParLimits(1,-0.03,0.09);
	  fun1->SetParLimits(2,0.009,0.1);
	}
	
    h->Fit("fun1","RQ0N","same");

    return fun1;
}

TF1 * fit_m2k(TH1D * h)
{
  	//h->Sumw2();
    h->SetAxisRange(-0.5,2.0);
    int iptbin=3;
    //if(iptbin<=8) 		{ Canvas->SetLogy(kUseLogLowBins); }
    //else if(iptbin>8) 	{ Canvas->SetLogy(0); }
    
    //h->Draw(); gPad->Update();

	TH1D *hclone = (TH1D *)h->Clone("hclone");
	float kaonhpeak = findpeak(hclone,0.2,0.4);

	cout << "kaon peak: " << kaonhpeak << "\t";
    //Trial fit for kaon
    fun2->SetRange(0.15,0.3);
    //fun2->SetParameters(1,0.25,0.02);
	fun2->SetParameters(1,kaonhpeak,0.02);
	fun2->SetParLimits(2,0.01,0.02);
	/*
	if(iptbin<5) {
	  //fun2->SetParLimits(1,0.2,0.3);
	  fun2->SetParameters(1,findpeak(hclone,0.2,0.3),0.02);
	  fun2->SetParLimits(2,0.001,0.03);
	}
	if(iptbin<8) {
	  //fun2->SetParLimits(1,0.2,0.3);
	  fun2->SetParLimits(2,0.001,0.04);
	}
	if(iptbin>8) {
	  //fun2->SetParLimits(1,0.2,0.3);
	  fun2->SetParLimits(2,0.001,0.06);
	}
	*/
    h->Fit("fun2","RQ0N","same");

    return fun2;

}

TF1 * fit_m2prot(TH1D * h)
{
  float prothpeak = findpeak(hclone,0.5,1.5);
  
  cout << "prot peak:" << prothpeak << endl;

  //Trial fit for proton
  fun3->SetRange(0.72,1.3);
  fun3->SetParameters(1,prothpeak,0.02);
  fun3->SetParLimits(2,0.01,0.04);
  h->Fit("fun3","RQN+");
  
  return fun3;

}


float findpeak(TH1D* inputhist, float lowbound, float highbound)
{
//c1 = new TCanvas("c1","",0,0,800,500);
  /*
  float xlow = inputhist->FindBin(lowbound);
  float xhigh= inputhist->FindBin(highbound);  
  
  cout << "xlow: " << xlow << "\t xhigh: " << xhigh  << endl;
  
  inputhist->GetXaxis()->SetRange(xlow,xhigh);
  */
  
  inputhist->GetXaxis()->SetRangeUser(lowbound,highbound);
  float peakloc = inputhist->GetBinCenter(inputhist->GetMaximumBin());
  
  inputhist->GetXaxis()->UnZoom();
  
  return peakloc;
  
}


void setup()
{
  //setStyleWide();
  Canvas = new TCanvas("Canvas","",0,0,800,500);
  Canvas->Draw();
  Canvas->Update();
  Canvas->cd();

  fun_pion->SetLineColor(kCyan+1);
  fun_kaon->SetLineColor(kCyan+2);
  fun_proton->SetLineColor(kCyan+3);
  
  TString g = "g";
  for(long itof=0 ; itof<2 ; itof++) {
    for(long ich=0 ; ich<2 ; ich++) {
      for(long isig=0 ; isig<3 ; isig++) {
		    for(int centbin=0; centbin<=4; centbin++) {
          for(long idphi=0 ; idphi<=7 ; idphi++) {
          	gPionYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gPionYield[itof][ich][isig][centbin][idphi]->SetName(g+"PionYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(20+4*ich);
          	gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
          	gPionYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"PionYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
          	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

          	gKaonYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gKaonYield[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(21+4*ich);
          	gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
          	gKaonYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
          	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

          	gProtYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gProtYield[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(22+4*ich);
          	gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
          	gProtYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
          	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
          	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
          	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

          	  
            gPionMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gPionMass[itof][ich][centbin][idphi]->SetName(g+"PionMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gPionMass[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
            gPionMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gPionWidth[itof][ich][centbin][idphi] = new TGraphErrors();
            gPionWidth[itof][ich][centbin][idphi]->SetName(g+"PionWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gPionWidth[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
            gPionWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gKaonMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gKaonMass[itof][ich][centbin][idphi]->SetName(g+"KaonMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gKaonMass[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
            gKaonMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gKaonWidth[itof][ich][centbin][idphi] = new TGraphErrors();
            gKaonWidth[itof][ich][centbin][idphi]->SetName(g+"KaonWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gKaonWidth[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
            gKaonWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gProtMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gProtMass[itof][ich][centbin][idphi]->SetName(g+"ProtMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gProtMass[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
            gProtMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gProtWidth[itof][ich][centbin][idphi] = new TGraphErrors(); 
            gProtWidth[itof][ich][centbin][idphi]->SetName(g+"ProtWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gProtWidth[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
            gProtWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
          }  
        } 
      }
    }
  }
}

void write()
{
  cout << "now write output." << endl;  
  
  TFile fOutFile("fittingoutput.root","RECREATE");
  fOutFile.cd();
  
  for(long itof=0 ; itof<2 ; itof++) {
    for(long ich=0 ; ich<2 ; ich++) {
      for(long isig=0 ; isig<3 ; isig++) {
        for(long centbin=0 ; centbin<=4 ; centbin++) {
	        for(long idphi=0 ; idphi<=7 ; idphi++) {
      	    gPionYield[itof][ich][isig][centbin][idphi]->Write();
            gPionYieldBC[itof][ich][isig][centbin][idphi]->Write();
            
      	    gKaonYield[itof][ich][isig][centbin][idphi]->Write();
      	    gKaonYieldBC[itof][ich][isig][centbin][idphi]->Write();
      	    
      	    gProtYield[itof][ich][isig][centbin][idphi]->Write();
      	    gProtYieldBC[itof][ich][isig][centbin][idphi]->Write();

            gPionMass[itof][ich][centbin][idphi]->Write();
            gPionWidth[itof][ich][centbin][idphi]->Write();
            
            gKaonMass[itof][ich][centbin][idphi]->Write();
            gKaonWidth[itof][ich][centbin][idphi]->Write();
            
            gProtMass[itof][ich][centbin][idphi]->Write();
            gProtWidth[itof][ich][centbin][idphi]->Write();
      	  } 
        } 
      }
    }
  }
  fOutFile.Close();
}

  
void drawLabel(char *title, int color, double size, double x, double y, int pos=12)
{
  double x0 = gPad->GetFrame()->GetX1();
  double x1 = gPad->GetFrame()->GetX2();
  double y0 = gPad->GetFrame()->GetY1();
  double y1 = gPad->GetFrame()->GetY2();
  
  double dx = x1-x0;
  double dy = y1-y0;
  
  double xtitle=0,ytitle=0;
    
  if(gPad->GetLogy()==0) {
    xtitle = x0+x*dx;
    ytitle = y1-y*dy; }
  else {
    xtitle = x0+x*dx;
    y0 = pow(10.,y0);
    y1 = pow(10.,y1);
    ytitle = pow(10,log10(y1)-log10(y1/y0)*y); }
  
  //newTLatex(xtitle,ytitle,title,color,pos,size,0);
}

void setFunctionRanges(double nsigma=2.5)
{
  fun_pion->SetRange(fun_pion->GetParameter(1)-nsigma*fun_pion->GetParameter(2),
		     fun_pion->GetParameter(1)+nsigma*fun_pion->GetParameter(2));
  
  fun_kaon->SetRange(fun_kaon->GetParameter(1)-nsigma*fun_kaon->GetParameter(2),
		     fun_kaon->GetParameter(1)+nsigma*fun_kaon->GetParameter(2));
  
  fun_proton->SetRange(fun_proton->GetParameter(1)-nsigma*fun_proton->GetParameter(2),
		       fun_proton->GetParameter(1)+nsigma*fun_proton->GetParameter(2));
}
