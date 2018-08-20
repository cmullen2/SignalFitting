{

  TString job=gSystem->Getenv("JOBNAME");
  TString fileDir=gSystem->Getenv("FILEDIR");
  TString prevFitDir=gSystem->Getenv("PREVFITNAME");
  TString weightsPath = fileDir + "/" + prevFitDir + "/Weights" + job + ".root";
  cout << " The weights from the previous fit that will be used for this fit are taken from " <<weightsPath <<endl; 
  
  THSsPlot* RF=new THSsPlot(job);
//  RF->LoadVariable("Coplanarity[-50,50]");//should be same name as variable in tree 
  RF->LoadVariable("Coplanarity[-50,50]");//should be same name as variable in tree 
  RooRealVar * var=RF->GetWorkSpace()->var("Coplanarity");
  var->setBins(100); //number of bins used in PDF histogram
  RF->SetIDBranchName("UID");//this is needed if ID != "UID"

  RF->SetBinDir(fileDir+"/"+job);
//  RF->ConfigureSavedBins("/w/work1/home/chris/LatestAnalysisRuns/Data/DataJul17/HaspectOutput/Fitting/All3Binned1FilesProtonW10/");
 
  RF->Factory("RooHSEventsHistPDF::Sig(Coplanarity,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RooHSEventsHistPDF* pdf=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("Sig"));
  RF->LoadSpeciesPDF("Sig",1);

  cout << " Past the signal pdf "  <<endl; 
  RF->Factory("RooHSEventsHistPDF::BG(Coplanarity,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RooHSEventsHistPDF* pdfb=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("BG"));
  RF->LoadSpeciesPDF("BG",1);



  // Multi Pion BG's
/*  RF->Factory("RooHSEventsHistPDF::PEta(Coplanarity,alphaPEta[0,0,20],offPEta[0,-2,2],scalePEta[1,0.8,1.2])"); //4
  RooHSEventsHistPDF* pdfPEta=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PEta")); //2
  RF->LoadSpeciesPDF("PEta",1); //1
*/

/*  RF->Factory("RooHSEventsHistPDF::NEta(Coplanarity,alphaNEta[0,0,20],offNEta[0,-2,2],scaleNEta[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfNEta=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("NEta"));
  RF->LoadSpeciesPDF("NEta",1);
*/
/*
  RF->Factory("RooHSEventsHistPDF::NPi0Pi0(Coplanarity,alphaNPi0Pi0[0,0,20],offNPi0Pi0[0,-2,2],scaleNPi0Pi0[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfNPi0Pi0=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("NPi0Pi0"));
  RF->LoadSpeciesPDF("NPi0Pi0",1);

  cout << " Past the NPi0Pi0 LOading "  <<endl; 

  RF->Factory("RooHSEventsHistPDF::NPipPim(Coplanarity,alphaNPipPim[0,0,20],offNPipPim[0,-2,2],scaleNPipPim[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfNPipPim=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("NPipPim"));
  RF->LoadSpeciesPDF("NPipPim",1);

  cout << " Past the NPipPim Loading "  <<endl; 

  RF->Factory("RooHSEventsHistPDF::NPipPi0(Coplanarity,alphaNPipPi0[0,0,20],offNPipPi0[0,-2,2],scaleNPipPi0[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfNPipPi0=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("NPipPi0"));
  RF->LoadSpeciesPDF("NPipPi0",1);

  cout << " Past the NPipPi0 Loading "  <<endl; 
*/
  RF->Factory("RooHSEventsHistPDF::PPi0Pi0(Coplanarity,alphaPPi0Pi0[0,0,20],offPPi0Pi0[0,-2,2],scalePPi0Pi0[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfPPi0Pi0=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PPi0Pi0"));
  RF->LoadSpeciesPDF("PPi0Pi0",1);

  cout << " Past the PPi0Pi0 Loading "  <<endl; 
/*
  RF->Factory("RooHSEventsHistPDF::PPipPim(Coplanarity,alphaPPipPim[0,0,20],offPPipPim[0,-2,2],scalePPipPim[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfPPipPim=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PPipPim"));
  RF->LoadSpeciesPDF("PPipPim",1);

  cout << " Past the PPipPim Loading "  <<endl; 

  RF->Factory("RooHSEventsHistPDF::PPi0Pim(Coplanarity,alphaPPi0Pim[0,0,20],offPPi0Pim[0,-2,2],scalePPi0Pim[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfPPi0Pim=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PPi0Pim"));
  RF->LoadSpeciesPDF("PPi0Pim",1);

  cout << " Past the PPi0Pim Loading "  <<endl; 

  RF->Factory("RooHSEventsHistPDF::PCompton(Coplanarity,alphaPCompton[0,0,20],offPCompton[0,-2,2],scalePCompton[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfPCompton=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PCompton"));
  RF->LoadSpeciesPDF("PCompton",1);

  cout << " Past the PCompton Loading "  <<endl; 
*/
/*
  RF->Factory("RooHSEventsHistPDF::NCompton(Coplanarity,alphaNCompton[0,0,20],offNCompton[0,-2,2],scaleNCompton[1,0.8,1.2])");
  RooHSEventsHistPDF* pdfNCompton=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("NCompton"));
  RF->LoadSpeciesPDF("NCompton",1);
*/
 	//Chebychev or 2nd order poly as bg
//  RF->Factory("Chebychev:BG(Coplanarity,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3], a2[-0.1,-0.3,0.3]}  )");
//  RF->Factory("Polynomial:BG2(Coplanarity,a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3])");
//  RF->LoadSpeciesPDF("BG2",1);
//  RF->LoadSpeciesPDF("BG",1);

//  cout << " Past the signal pdf2 "  <<endl; 
  RF->GetWorkSpace()->var("scaleB")->setConstant();
  RF->GetWorkSpace()->var("alphaB")->setConstant();
  RF->GetWorkSpace()->var("offB")->setConstant();


// Multi pion bg
/*
  RF->GetWorkSpace()->var("scalePEta")->setConstant();
  RF->GetWorkSpace()->var("alphaPEta")->setConstant();
  RF->GetWorkSpace()->var("offPEta")->setConstant();
  
  RF->GetWorkSpace()->var("scaleNEta")->setConstant();
  RF->GetWorkSpace()->var("alphaNEta")->setConstant();
  RF->GetWorkSpace()->var("offNEta")->setConstant();
*/
/*
  RF->GetWorkSpace()->var("scaleNPi0Pi0")->setConstant();
  RF->GetWorkSpace()->var("alphaNPi0Pi0")->setConstant();
  RF->GetWorkSpace()->var("offNPi0Pi0")->setConstant();

  RF->GetWorkSpace()->var("scaleNPipPim")->setConstant();
  RF->GetWorkSpace()->var("alphaNPipPim")->setConstant();
  RF->GetWorkSpace()->var("offNPipPim")->setConstant();

  RF->GetWorkSpace()->var("scaleNPipPi0")->setConstant();
  RF->GetWorkSpace()->var("alphaNPipPi0")->setConstant();
  RF->GetWorkSpace()->var("offNPipPi0")->setConstant();
*/
  RF->GetWorkSpace()->var("scalePPi0Pi0")->setConstant();
  RF->GetWorkSpace()->var("alphaPPi0Pi0")->setConstant();
  RF->GetWorkSpace()->var("offPPi0Pi0")->setConstant();
/*

  RF->GetWorkSpace()->var("scalePPipPim")->setConstant();
  RF->GetWorkSpace()->var("alphaPPipPim")->setConstant();
  RF->GetWorkSpace()->var("offPPipPim")->setConstant();


  RF->GetWorkSpace()->var("scalePPi0Pim")->setConstant();
  RF->GetWorkSpace()->var("alphaPPi0Pim")->setConstant();
  RF->GetWorkSpace()->var("offPPi0Pim")->setConstant();

  RF->GetWorkSpace()->var("scalePCompton")->setConstant();
  RF->GetWorkSpace()->var("alphaPCompton")->setConstant();
  RF->GetWorkSpace()->var("offPCompton")->setConstant();
*/
/*
  RF->GetWorkSpace()->var("scaleNCompton")->setConstant();
  RF->GetWorkSpace()->var("alphaNCompton")->setConstant();
  RF->GetWorkSpace()->var("offNCompton")->setConstant();
*/


//  cout << " Past the signal pdf3 "  <<endl; 
  RF->LoadWeights(weightsPath,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
  //RF->LoadWeights("/w/work1/home/chris/LatestAnalysisRuns/Data/DataJul17/HaspectOutput/Fitting/FitProtonTiming10Bins1Files/binFitTweights.root","HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
  RF->SetWeightName("Sig"); //Events in timing coincidence
 //Should now be the inv mass one right above! and in weights path too

//BG Weights: This method does not work
/*
  TString weightsPathPEta = fileDir + "/InvMassPEta/Weights" + job + ".root";
  pdfPEta->LoadWeights("PEtaT",weightsPathPEta,"HSsWeights"); 
//  RF->SetWeightName("PEtaT"); //Events in timing coincidence
  

  TString weightsPathNEta = fileDir + "/InvMassNEta/Weights" + job + ".root";
  pdfNEta->LoadWeights("NEtaT", weightsPathNEta,"HSsWeights"); 
//  RF->SetWeightName("NEtaT"); //Events in timing coincidence


  cout << " Past the SignalWeights Loading "  <<endl; 
  TString weightsPathPPi0Pi0 = fileDir + "/InvMassPPi0Pi0/Weights" + job + ".root";
  pdfPPi0Pi0->LoadWeights("PPi0Pi0T",weightsPathPPi0Pi0,"HSsWeights"); //WILL NEED TO BE CHANGED TO Sig AS THIS IS THE NEW NAME USED IN THE INV MASS FIT
//  RF->SetWeightName("PPi0Pi0T"); //Events in timing coincidence

  cout << " Past the PPi0Pi0Weights Loading "  <<endl; 
  TString weightsPathPPi0Pim = fileDir + "/InvMassPPi0Pim/Weights" + job + ".root";
  pdfPPi0Pim->LoadWeights("PPi0PimT",weightsPathPPi0Pim,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
//  RF->SetWeightName("PPi0PimT"); //Events in timing coincidence


  cout << " Past the PPi0PimWeights Loading "  <<endl; 

  TString weightsPathPPipPim = fileDir + "/InvMassPPipPim/Weights" + job + ".root";
  pdfPPipPim->LoadWeights("PPipPimT",weightsPathPPipPim,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
//  RF->SetWeightName("PPipPimT"); //Events in timing coincidence

  cout << " Past the PPipPimWeights Loading "  <<endl; 

  TString weightsPathNPi0Pi0 = fileDir + "/InvMassNPi0Pi0/Weights" + job + ".root";
  pdfNPi0Pi0->LoadWeights("NPi0Pi0T",weightsPathNPi0Pi0,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
//  RF->SetWeightName("NPi0Pi0T"); //Events in timing coincidence

  cout << " Past the NPi0Pi0Weights Loading "  <<endl; 
  TString weightsPathNPipPi0 = fileDir + "/InvMassNPipPi0/Weights" + job + ".root";
  pdfNPipPi0->LoadWeights("NPipPi0T",weightsPathNPipPi0,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
//  RF->SetWeightName("NPipPi0T"); //Events in timing coincidence

  cout << " Past the NPipPi0Weights Loading "  <<endl; 
 
  TString weightsPathNPipPim = fileDir + "/InvMassNPipPim/Weights" + job + ".root";
  pdfNPipPim->LoadWeights("NPipPimT",weightsPathNPipPim,"HSsWeights"); //Cp first to scratch or read from work? What is quicker? What is standard?
//  RF->SetWeightName("NPipPimT"); //Events in timing coincidence


  cout << " Past the NPipPimWeights Loading "  <<endl; 
  TString weightsPathPCompton = fileDir + "/InvMassPCompton/Weights" + job + ".root";
  pdfPCompton->LoadWeights("PCompton",weightsPathPCompton,"HSsWeights"); 

  cout << " Past the PComptonWeights Loading "  <<endl; 
*/
/*
  TString weightsPathNCompton = fileDir + "/InvMassNCompton/Weights" + job + ".root";
  pdfNCompton->LoadWeights("NCompton",weightsPathNCompton,"HSsWeights"); 
*/



//  cout << " Past the signal pdf4 "  <<endl; 
  gBenchmark->Start("Binned");
  RF->AddGausConstraint(pdf->AlphaConstraint());
  RF->AddGausConstraint(pdf->OffConstraint());
  RF->AddGausConstraint(pdf->ScaleConstraint());
  RF->AddGausConstraint(pdfb->AlphaConstraint());
  RF->AddGausConstraint(pdfb->OffConstraint());
  RF->AddGausConstraint(pdfb->ScaleConstraint());

//Multi pion bg
/*
  RF->AddGausConstraint(pdfPEta->AlphaConstraint());
  RF->AddGausConstraint(pdfPEta->OffConstraint());
  RF->AddGausConstraint(pdfPEta->ScaleConstraint());

  RF->AddGausConstraint(pdfNEta->AlphaConstraint());
  RF->AddGausConstraint(pdfNEta->OffConstraint());
  RF->AddGausConstraint(pdfNEta->ScaleConstraint());
*/
/*
  RF->AddGausConstraint(pdfNPi0Pi0->AlphaConstraint());
  RF->AddGausConstraint(pdfNPi0Pi0->OffConstraint());
  RF->AddGausConstraint(pdfNPi0Pi0->ScaleConstraint());

  RF->AddGausConstraint(pdfNPipPim->AlphaConstraint());
  RF->AddGausConstraint(pdfNPipPim->OffConstraint());
  RF->AddGausConstraint(pdfNPipPim->ScaleConstraint());

  RF->AddGausConstraint(pdfNPipPi0->AlphaConstraint());
  RF->AddGausConstraint(pdfNPipPi0->OffConstraint());
  RF->AddGausConstraint(pdfNPipPi0->ScaleConstraint());
*/
  RF->AddGausConstraint(pdfPPi0Pi0->AlphaConstraint());
  RF->AddGausConstraint(pdfPPi0Pi0->OffConstraint());
  RF->AddGausConstraint(pdfPPi0Pi0->ScaleConstraint());

/*
  RF->AddGausConstraint(pdfPPipPim->AlphaConstraint());
  RF->AddGausConstraint(pdfPPipPim->OffConstraint());
  RF->AddGausConstraint(pdfPPipPim->ScaleConstraint());

  RF->AddGausConstraint(pdfPPi0Pim->AlphaConstraint());
  RF->AddGausConstraint(pdfPPi0Pim->OffConstraint());
  RF->AddGausConstraint(pdfPPi0Pim->ScaleConstraint());

  RF->AddGausConstraint(pdfPCompton->AlphaConstraint());
  RF->AddGausConstraint(pdfPCompton->OffConstraint());
  RF->AddGausConstraint(pdfPCompton->ScaleConstraint());
*/
/*
  RF->AddGausConstraint(pdfNCompton->AlphaConstraint());
  RF->AddGausConstraint(pdfNCompton->OffConstraint());
  RF->AddGausConstraint(pdfNCompton->ScaleConstraint());
*/

//  RF->FitSavedBins(2);
cout << "BEFORE CALLING FIT BATCH BIN" << endl;  
// RF->FitBatchBin(1,"Data");
  RF->FitBatchBin(1);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");

  RF->GetWeights()->Save(); //Added Cam 4th Feb 2018, think this is now needed to be able to load weights later

}
