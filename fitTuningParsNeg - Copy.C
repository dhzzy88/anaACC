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

parstruct loadFitParamsNeg(int ptbin) {

  parstruct fitTuning;

  if(ptbin == 8 && fireACC ==0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.1,2.3};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.01,0.1};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.008,0.1};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,1.1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,1,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {0.94,0.98,0.9,0.95,1,0.98};
    float tunekaonwidth[6]  = {1.1,1.08,1.03,1.08,1.15,1.12};
    float tunekaonmean[6]   = {-0.01,0.01,0.01,0.015,-0.01,-0.005};
    float tuneprotheight[6] = {0.96,0.95,0.93,0.9,0.955,0.93};
    float tuneprotwidth[6]  = {0.03,0.75,0.19,0.54,0.73,0.1};
    float tuneprotmean[6]   = {0,0,0,0.003,0.005,0};
  }

  if(ptbin == 9 && fireACC ==0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.3,2.5};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.01,0.1};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.008,0.1};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,1.1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,1,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};

    float tunekaonheight[6] = {1.04,0.94,0.95,0.88,0.98,1.02};
    float tunekaonwidth[6]  = {1.25,1.1,1.1,1.05,1.12,1.12};
    float tunekaonmean[6]   = {0.03,0.008,0.005,0.015,-0.01,-0.01};

    float tuneprotheight[6] = {1.12,1.07,1.07,1.05,1.07,1.1};
    float tuneprotwidth[6]  = {0.1,0.4,0.25,0.65,0.72,0.2};
    float tuneprotmean[6]   = {0,0,0.0,0.005,0,0};
  }

  if(ptbin == 10 && fireACC ==0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.5,2.7};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.23,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.002,0.07};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.15};
    float  pionfitrange[2]   = {-0.2,0.1};
    float  kaonfitrange[2]   = {0.1,0.4};
    float  protfitrange[2]   = {0.6,1};
    float tunepionheight[6] = {1,1,1,1,1,1};
    float tunepionwidth[6]  = {1,1,1,1,1,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};

    float tunekaonheight[6] = {1.15,1.13,1.05,1.1,1.05,1.23};
    float tunekaonwidth[6]  = {1.1,1.03,1.03,1.1,1.05,1};
    float tunekaonmean[6]   = {-0.05,-0.08,-0.05,-0.03,-0.03,-0.08};

    float tuneprotheight[6] = {0.89,0.88,0.92,0.92,0.91,0.86};
    float tuneprotwidth[6]  = {0.65,0.65,0.5,0.47,0.5,0.67};
    float tuneprotmean[6]   = {-0.03,0.0,-0.03,-0.03,-0.03,-0.02};
  }


  if(ptbin ==11 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.7,2.9};
    int    Nrebin            = 8;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.1,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.2};
    float  protwidthrange[2] = {0.05,0.2};
    float  pionfitrange[2]   = {-0.4,0.2};
    float  kaonfitrange[2]   = {-0.4,0.4};
    float  protfitrange[2]   = {0.5,1.2};
    float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    float tunepionwidth[6]  = {1,1.02,1.02,1.02,1.02,1.05};
    float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    float tunekaonheight[6] = {1.08,1.1,1.14,1.13,1.13,1.1};
    float tunekaonwidth[6]  = {1.02,1.05,1.07,1.05,1.05,1.03};
    float tunekaonmean[6]   = {-0.02,-0.0,-0.04,-0.01,-0.01,-0.01};
    
    float tuneprotheight[6] = {0.83,0.85,0.86,0.8,0.83,0.88};
    float tuneprotwidth[6]  = {0.75,0.67,0.67,0.68,0.7,0.62};
    float tuneprotmean[6]   = {0.0,0.0,0.0,0.01,0.03,0.02};
  }

  if(ptbin ==12 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {3.0,3.5};
    int    Nrebin            = 10;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {-0.0,0.1};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.25};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {-0.4,0.4};
    float  protfitrange[2]   = {0.6,1.2};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    float tunekaonheight[6] = {1.15,1.18,1.18,1.3,1.17,1.25};
    float tunekaonwidth[6]  = {1.45,1.4,1.55,1.7,1.5,1.6};
    float tunekaonmean[6]   = {-0.025,-0.02,-0.0,-0.02,0.02,0};
    
    float tuneprotheight[6] = {1.22,1.12,1.17,1.1,1.11,1.15};
    float tuneprotwidth[6]  = {1.45,1.3,1.35,0.1,1.3,1.4};
    float tuneprotmean[6]   = {-0.07,0,-0.01,0.0,-0.05,0};
  }
  
  if(ptbin ==13 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {3.5,4.0};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0,0.2};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.15};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {0.2,0.4};
    float  protfitrange[2]   = {0.8,1.3};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    //float tunekaonheight[6] = {1.1,1.1,0.86,0.94,0.93,1};
    //float tuneprotheight[6] = {0.65*-10E-5,0.5*-10E-5,0.6*-10E-5,0.6*-10E-5,0.6*-10E-5,0.64*-10E-5};

    float tunekaonheight[6] = {1,1,1,1,1,1};
    float tuneprotheight[6] = {1,1,1,1,1,1};

    float tunekaonwidth[6]  = {1,1,1,1,1,1};
    float tunekaonmean[6]   = {0,0,0,0,0,0};
    
    float tuneprotwidth[6]  = {1,1,1,1,1,1};
    float tuneprotmean[6]   = {0,0,0,0,0,0};
  }  
/*
  if(ptbin ==13 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {3.5,4.0};
    int    Nrebin            = 5;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0,0.2};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.3};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {-0.5,0.4};
    float  protfitrange[2]   = {0.6,1.4};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};
    float tunekaonheight[6] = {1.28,1.23,1.2,1.25,1.48,1.28};
    float tunekaonwidth[6]  = {1.67,1.5,1.5,1.55,1.6,1.7};
    float tunekaonmean[6]   = {-0.07,0.03,0.0,-0.0,0.1,0.0};
    float tuneprotheight[6] = {1.36,1.12,1.2,1.15,1.15,1.1};
    float tuneprotwidth[6]  = {1.7,1.3,1.45,0.5,1.35,0.1};
    float tuneprotmean[6]   = {0.02,0.05,0.02,0.03,0.05,0.03};
  }  
  */
  if(ptbin ==14 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {4.0,4.5};
    int    Nrebin            = 5;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0,0.2};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.2};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {-0.4,0.4};
    float  protfitrange[2]   = {0.6,1.2};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    float tunekaonheight[6] = {1.68,1.43,1.35,1.5,1.62,1.6};
    float tunekaonwidth[6]  = {2.2,1.8,1.7,1.7,1.9,1.7};
    float tunekaonmean[6]   = {-0.05,0.05,0.0,0.07,0.07,0.07};
    
    float tuneprotheight[6] = {1.0,1,0.97,1.08,0.95,0.95};
    float tuneprotwidth[6]  = {-0.25,-0.1,-0.01,0.2,-0.1,-0.15};
    float tuneprotmean[6]   = {0.2,0.1,0.07,0.02,0.07,-0.03};
  }
  
  if(ptbin ==15 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {4.5,5.5};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0,0.2};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.15};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {-0.4,0.4};
    float  protfitrange[2]   = {0.6,1.2};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    float tunekaonheight[6] = {1.3,1.39,1.32,1.39,1.23,1.24};
    float tunekaonwidth[6]  = {1.7,1.6,1.7,1.7,1.5,1.55};
    float tunekaonmean[6]   = {-0.04,0.07,0.02,-0.05,-0.05,0.01};
    
    float tuneprotheight[6] = {1.2,1,1.09,1.1,1.15,1.03};
    float tuneprotwidth[6]  = {1.4,1.2,0.1,-0.05,1.3,-0.05};
    float tuneprotmean[6]   = {0.01,0,0.02,0,0.0,0};
  }

  if(ptbin ==16 && fireACC == 0) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {5.5,6.5};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0,0.2};
    float  protmeanrange[2]  = {0.85,0.9};
    float  pionwidthrange[2] = {0.05,0.1};
    float  kaonwidthrange[2] = {0.05,0.15};
    float  protwidthrange[2] = {0.05,0.15};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {-0.4,0.4};
    float  protfitrange[2]   = {0.6,1.2};
    //float tunepionheight[6] = {1.15,1.15,1.08,1.12,1.08,1.12};
    //float tunepionwidth[6]  = {1,1.02,1.02.02,1.02,1.02,1.05};
    //float tunepionmean[6]   = {0.02,0.02,0.02,0.02,0.02,0.01};

    float tunekaonheight[6] = {1.3,1.39,1.32,1.39,1.23,1.24};
    float tunekaonwidth[6]  = {1.7,1.6,1.7,1.7,1.5,1.55};
    float tunekaonmean[6]   = {-0.04,0.07,0.02,-0.05,-0.05,0.01};
    
    float tuneprotheight[6] = {1.2,1,1.09,1.1,1.15,1.03};
    float tuneprotwidth[6]  = {1.4,1.2,0.1,-0.05,1.3,-0.05};
    float tuneprotmean[6]   = {0.01,0,0.02,0,0.0,0};
  } 

  if(ptbin == 8 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.1,2.3};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 0;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.02,0.2};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.008,0.1};
    float  pionfitrange[2]   = {-0.2,0.2};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,1.1};
    float tunepionheight[6] = {1,0.99,0.95,1.02,0.97,1.0};
    float tunepionwidth[6]  = {0.95,0.95,0.85,0.86,0.94,0.94};
    float tunepionmean[6]   = {-0.0,-0.0,-0.015,0.0,0,0};
    //float tunekaonheight[6] = {1,0.93,0.94,0.96,0.96,1};
    //float tunekaonwidth[6]  = {1.18,1.05,1.15,1.12,1,1.18};
    //float tunekaonmean[6]   = {0.01,0.015,0.01,0.015,0.02,0.015};
    //float tuneprotheight[6] = {0.98,1.0,0.95,0.97,0.97,1};
    //float tuneprotwidth[6]  = {0.1,0.67,0.2,0.65,0.65,0.1};
    //float tuneprotmean[6]   = {0,0,0,0.005,0,0};
  }

  if(ptbin == 9 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.1,2.3};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.05,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.2,0.05};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.04,1.01,1.09,1.01,1.01,0.99};
    float tunepionwidth[6]  = {0.95,0.97,1.05,0.96,0.9,0.95};
    float tunepionmean[6]   = {0,0,0,0,-0.01,0};
  }

  if(ptbin == 10 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.5,2.7};
    int ptbin = 10;
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.05,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.02,0.15};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.01,0.1};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.1};
    float tunepionheight[6] = {1,1,1.02,0.98,1,0.96};
    float tunepionwidth[6]  = {0.95,0.98,1,0.9,0.98,1.02};
    float tunepionmean[6]   = {0,0,0,0,0,0};
  }

  if(ptbin == 11 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {2.7,2.9};
    int    Nrebin            = 5,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.05,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.2,0.05};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.06,0.98,1.04,1.02,1.02,0.98};
    float tunepionwidth[6]  = {1.02,0.93,0.97,0.97,0.95,0.92};
    float tunepionmean[6]   = {0.01,0,0,0,0,0};
  }

  if(ptbin == 12 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {3.0,3.5};
    int    Nrebin            = 8,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.05,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.2,0.05};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.16,1.14,1.03,1.1,1.12,1.2};
    float tunepionwidth[6]  = {1.17,1.1,1,1.1,1.15,1.2};
    float tunepionmean[6]   = {0.02,0.05,0.02,0.02,0.01,0.03};
  }
  
  if(ptbin == 13 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {3.5,4.0};
    int    Nrebin            = 2,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,-0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.1,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.2,0.2};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1,1,1,1,1,1};
    //float tunepionheight[6] = {1.1,1.2,1.35,1.33,1.2,1.35};
    float tunepionwidth[6]  = {1.02,1.07,1.05,1.08,1,1.05};
    float tunepionmean[6]   = {0.02,0.02,0.07,0.07,0.05,0.05};
  }

  if(ptbin == 14 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {4.0,4.5};
    int    Nrebin            = 5,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,-0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.1,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.5,0.2};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.31,1.32,1.37,1.29,1.3,1.62};
    float tunepionwidth[6]  = {1.05,1.0,1.18,1.25,1.15,1.05};
    float tunepionmean[6]   = {0.06,0.02,0.05,0.0,0.045,0.03};
  }

  if(ptbin == 15 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {4.5,5.5};
    int    Nrebin            = 5,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,-0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.1,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.5,0.5};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.1,1.2,1.35,1.33,1.2,1.35};
    float tunepionwidth[6]  = {1.02,1.07,1.05,1.08,1,1.05};
    float tunepionmean[6]   = {0.02,0.02,0.07,0.07,0.05,0.05};
  }

  if(ptbin == 16 && fireACC ==1) {
    cout << "Loading params for ptbin " << ptbin << " with fireACC: " << fireACC << "..." << endl;
    float ptrange[2] = {5.5,6.5};
    int    Nrebin            = 5,
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,-0.05};
    float  kaonmeanrange[2]  = {0.2,0.3};
    float  protmeanrange[2]  = {0.8,0.9};
    float  pionwidthrange[2] = {0.1,0.2};
    float  kaonwidthrange[2] = {0.005,0.01};
    float  protwidthrange[2] = {0.005,0.1};
    float  pionfitrange[2]   = {-0.5,0.5};
    float  kaonfitrange[2]   = {0.1,0.3};
    float  protfitrange[2]   = {0.7,0.9};
    float tunepionheight[6] = {1.1,1.2,1.35,1.33,1.2,1.35};
    float tunepionwidth[6]  = {1.02,1.07,1.05,1.08,1,1.05};
    float tunepionmean[6]   = {0.02,0.02,0.07,0.07,0.05,0.05};
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
