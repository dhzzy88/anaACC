struct parstruct {
  float ptrange[2];
  int   Nrebin;           
  int   kUseLogLowBins; 
  int   twogausfit;       
  int   threegausfit;     
  float protmeanvariance; 
  float protwidthvariance;
  float pionmeanrange[2]; 
  float kaonmeanrange[2]; 
  float protmeanrange[2]; 
  float pionwidthrange[2];
  float kaonwidthrange[2];
  float protwidthrange[2];
  float pionfitrange[2];  
  float kaonfitrange[2];  
  float protfitrange[2];  
  float tunepionheight[6];
  float tunepionwidth[6]; 
  float tunepionmean[6]; 
  float tunekaonheight[6];
  float tunekaonwidth[6]; 
  float tunekaonmean[6];  
  float tuneprotheight[6];
  float tuneprotwidth[6]; 
  float tuneprotmean[6];  
} fitTuning;

parstruct loadFitParamsnoEP() {

  parstruct fitTuning;
  if(ptbin==13 && ich==0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << " FOR NO EP..." << endl;
    float ptrange[2] = {3.5,4};
    int    Nrebin            = 1;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.0,0.3};
    float  protmeanrange[2]  = {0.8,0.95};
    float  pionwidthrange[2] = {0.1,0.5};
    float  kaonwidthrange[2] = {0.1,0.1};
    float  protwidthrange[2] = {0.000001,0.00001};
    float  pionfitrange[2]   = {-0.1,0.2};
    float  kaonfitrange[2]   = {-0.1,0.4};
    float  protfitrange[2]   = {0.5,1.1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,0.95,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1,1,1,1,1.05,1};
    float tunekaonwidth[6]  = {1,1,1,1,0.95,1};
    float tunekaonmean[6]   = {0,0,0,0,0.1,0};
    float tuneprotheight[6] = {1,1,1,1,.0013,1};
    float tuneprotwidth[6]  = {1,1,1,1,.018,1};
    float tuneprotmean[6]   = {0,0,0,0,0.05,0};
  }

  if(ptbin==14 && ich==0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << " FOR NO EP..." << endl;
    float ptrange[2] = {4,4.5};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.2};
    float  kaonmeanrange[2]  = {0.0,0.3};
    float  protmeanrange[2]  = {0.8,0.95};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.1,0.1};
    float  protwidthrange[2] = {0.000001,0.00001};
    float  pionfitrange[2]   = {-0.0,0.2};
    float  kaonfitrange[2]   = {-0.1,0.4};
    float  protfitrange[2]   = {0.5,1.1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,0.50,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1,1,1,1,1.35,1};
    float tunekaonwidth[6]  = {1,1,1,1,1.1,1};
    float tunekaonmean[6]   = {0,0,0,0,0.02,0};
    float tuneprotheight[6] = {1,1,1,1,.0013,1};
    float tuneprotwidth[6]  = {1,1,1,1,.018,1};
    float tuneprotmean[6]   = {0,0,0,0,0.05,0};
  }

    if(ptbin==13 && ich==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << " FOR NO EP..." << endl;
    float ptrange[2] = {3.5,4};
    int    Nrebin            = 1;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.0,0.3};
    float  protmeanrange[2]  = {0.8,0.95};
    float  pionwidthrange[2] = {0.1,0.5};
    float  kaonwidthrange[2] = {0.01,0.2};
    float  protwidthrange[2] = {0.01,0.1};
    float  pionfitrange[2]   = {-0.1,0.2};
    float  kaonfitrange[2]   = {-0.1,0.4};
    float  protfitrange[2]   = {0.5,1.1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,0.95,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1,1,1,1,17,1};
    float tunekaonwidth[6]  = {1,1,1,1,20.5,1};
    float tunekaonmean[6]   = {0,0,0,0,-0.06,0};
    float tuneprotheight[6] = {1,1,1,1,.001,1};
    float tuneprotwidth[6]  = {1,1,1,1,.0145,1};
    float tuneprotmean[6]   = {0,0,0,0,-0.1,0};
  }

  fitTuning.Nrebin = Nrebin;           
  fitTuning.kUseLogLowBins = kUseLogLowBins;   
  fitTuning.twogausfit = twogausfit;       
  fitTuning.threegausfit = threegausfit;     
  fitTuning.protmeanvariance = protmeanvariance; 
  fitTuning.protwidthvariance = protwidthvariance;

  for(int i=0; i<=1; i++) {
    fitTuning.ptrange[i] = ptrange[i];
    fitTuning.pionmeanrange[i]  = pionmeanrange[i]; 
    fitTuning.kaonmeanrange[i]  = kaonmeanrange[i]; 
    fitTuning.protmeanrange[i]  = protmeanrange[i]; 
    fitTuning.pionwidthrange[i] = pionwidthrange[i];
    fitTuning.kaonwidthrange[i] = kaonwidthrange[i];
    fitTuning.protwidthrange[i] = protwidthrange[i];
    fitTuning.pionfitrange[i]   = pionfitrange[i];  
    fitTuning.kaonfitrange[i]   = kaonfitrange[i];  
    fitTuning.protfitrange[i]   = protfitrange[i];  
  }

  for(int i=0; i<=5; i++) {
    fitTuning.tunepionheight[i] = tunepionheight[i];
    fitTuning.tunepionwidth[i]  = tunepionwidth[i]; 
    fitTuning.tunepionmean[i]   = tunepionmean[i];  
    fitTuning.tunekaonheight[i] = tunekaonheight[i];
    fitTuning.tunekaonwidth[i]  = tunekaonwidth[i]; 
    fitTuning.tunekaonmean[i]   = tunekaonmean[i];  
    fitTuning.tuneprotheight[i] = tuneprotheight[i];
    fitTuning.tuneprotwidth[i]  = tuneprotwidth[i]; 
    fitTuning.tuneprotmean[i]   = tuneprotmean[i];  
  }
  return fitTuning;
}
