{

  TString job=gSystem->Getenv("JOBNAME");
  TString fileDir=gSystem->Getenv("FILEDIR");
  TString prevFitDir=gSystem->Getenv("PREVFITNAME");
  TString weightsPath = fileDir + "/" + prevFitDir + "/Weights" + job + ".root";
  cout << " The weights from the previous fit that will be used for this fit are taken from " <<weightsPath <<endl; 
  
  THSsPlot* RF=new THSsPlot(job);
  RF->LoadVariable("Coplanarity[-50,50]");//should be same name as variable in tree 
  RooRealVar * var=RF->GetWorkSpace()->var("Coplanarity");
  var->setBins(100); //number of bins used in PDF histogram
  RF->SetIDBranchName("UID");//this is needed if ID != "UID"
  RF->SetBinDir(fileDir+"/"+job);
 
  RF->Factory("RooHSEventsHistPDF::Sig(Coplanarity,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RooHSEventsHistPDF* pdf=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("Sig"));
  RF->LoadSpeciesPDF("Sig",1);

  cout << " Past the signal pdf "  <<endl; 
  RF->Factory("RooHSEventsHistPDF::BG(Coplanarity,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RooHSEventsHistPDF* pdfb=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("BG"));
  RF->LoadSpeciesPDF("BG",1);


//----------------------------------------------------------------------------------------------------


  // Multi Pion BG's
  RF->Factory("RooHSEventsHistPDF::PEta(Coplanarity,alphaPEta[0,0,20],offPEta[0,-2,2],scalePEta[1,0.8,1.2])"); //4
  RooHSEventsHistPDF* pdfPEta=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("PEta")); //2
  RF->LoadSpeciesPDF("PEta",1); //1


//----------------------------------------------------------------------------------------------------

  RF->GetWorkSpace()->var("scaleB")->setConstant();
  RF->GetWorkSpace()->var("alphaB")->setConstant();
  RF->GetWorkSpace()->var("offB")->setConstant();


// Multi pion bg

  RF->GetWorkSpace()->var("scalePEta")->setConstant();
  RF->GetWorkSpace()->var("alphaPEta")->setConstant();
  RF->GetWorkSpace()->var("offPEta")->setConstant();


//----------------------------------------------------------------------------------------------------



  RF->LoadWeights(weightsPath,"HSsWeights"); 
  RF->SetWeightName("Sig"); //Events in timing coincidence

//BG Weights

  TString weightsPathPEta = fileDir + "/InvMassPEta/Weights" + job + ".root";
  pdfPEta->LoadWeights("PEtaT",weightsPathPEta,"HSsWeights"); 
  

//----------------------------------------------------------------------------------------------------


//  cout << " Past the signal pdf4 "  <<endl; 
  gBenchmark->Start("Binned");
  RF->AddGausConstraint(pdf->AlphaConstraint());
  RF->AddGausConstraint(pdf->OffConstraint());
  RF->AddGausConstraint(pdf->ScaleConstraint());
  RF->AddGausConstraint(pdfb->AlphaConstraint());
  RF->AddGausConstraint(pdfb->OffConstraint());
  RF->AddGausConstraint(pdfb->ScaleConstraint());

//Multi pion bg

  RF->AddGausConstraint(pdfPEta->AlphaConstraint());
  RF->AddGausConstraint(pdfPEta->OffConstraint());
  RF->AddGausConstraint(pdfPEta->ScaleConstraint());


//-----------------------------------------------------------------------------------------------------

  cout << "BEFORE CALLING FIT BATCH BIN" << endl;  
  RF->FitBatchBin(1,"Data");
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");

  RF->GetWeights()->Save(); //Added Cam 4th Feb 2018, think this is now needed to be able to load weights later

}
