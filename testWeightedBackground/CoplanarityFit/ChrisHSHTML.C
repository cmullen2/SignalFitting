//run with
// setenv FILEDIR $PWD/outBins/
// root --THSBins HSSubmitBatch.C
void ChrisHSHTML(){
  //Open file containing binning information in a THSBins
  //This also contains entry lists for each event analysed
  TString fileDir=gSystem->Getenv("FILEDIR");
  TFile* file=new TFile(fileDir+"/DataEntries.root");
  THSBins* DataBins=(THSBins*)file->Get("HSDataBins");

//  TString FitName = "CoplanarityMultiBGsNewWeightsCodeLess1000Entries/";
//  TString FitVariable="Coplanarity";


//  TString FitName = "ConeAngleMultiBGs/";
//  TString FitVariable="ConeAngle";

//  TString FitName = "MissMassMultiBGs/";
//  TString FitVariable="MissMass";


//  TString FitName = "InvMassSigCheb/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassNPi0Pi0/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassNPipPim/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassNPipPi0/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassPPi0Pi0/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassPPipPim/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassPPi0Pim/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassPCompton/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassPEta/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassNCompton/";
//  TString FitVariable="InvMass";

//  TString FitName = "InvMassNEta/";
//  TString FitVariable="InvMass";

  TString FitName = "TimingProton/";
  TString FitVariable="GammaAveTagDiffTime";

  gSystem->Setenv("FITNAME",FitName);
  gSystem->Setenv("FITVAR",FitVariable);
  cout << " Getting Fit Result  "<< FitName<< "for fit of " << FitVariable << endl;
  gSystem->Exec("mkdir -p /home/chris/public_html/Meetings/outhtmlNew/Neutron/$FITNAME$FITVAR"); 



  ofstream outHtml;
  TString outDir="/home/chris/public_html/Meetings/outhtmlNew/Neutron/"+FitName+FitVariable +"/";
  outHtml.open(outDir+"summary.html");
  TCanvas *can = new TCanvas("can","can",800,600);
  gStyle->SetOptFit();

  outHtml << "<HTML>" << endl;
  outHtml << "<head>" << endl;
  outHtml << "<style>" << endl;
  outHtml << "body {" << endl;
  outHtml << "    background-color: white;" << endl;
  outHtml << "}" << endl;
  outHtml << "" << endl;
  outHtml << "h1 {" << endl;
  outHtml << "    color: black;" << endl;
  outHtml << "    margin-left: 40px;" << endl;
  outHtml << "    background-color: lightgrey;" << endl;
  outHtml << "}" << endl;
  outHtml << "td {" << endl;
  outHtml << "    border: 1px solid black;" << endl;
  outHtml << "    text-align: center;" << endl;
  outHtml << "}" << endl;
  outHtml << "</style>" << endl;
  outHtml << "</head> " << endl;
  outHtml << "<body>" << endl;
  outHtml << "<TABLE>" << endl;


  Int_t histcounter=0;

 //Get Previous fit name to determine weights
//  TString PrevFitName = "InvMassSigCheb";
//  TString PrevFitName = "InvMassGaussCheb";
//  TString PrevFitName = "TimingProton";
 // TString PrevFitName = "TimingNeutron";
//  cout << "Previous fit directory to take weights from is " << PrevFitName << endl;
//  gSystem->Setenv("PREVFITNAME",PrevFitName);
  
  for(Int_t i=0;i<DataBins->GetN();i++){	
  //for(Int_t i=22;i<23;i++){	
    //loop through the bins and get the workspace files for fitting
    TString JobName=DataBins->GetBinName(i);
    cout<<"Getting Result from JobName "<<JobName<< endl;
    gSystem->Setenv("JOBNAME",JobName);
    cout << "First " <<gPad <<endl;
 
    if(histcounter%4==0){//Make an array to store four header names? Can then just use array[0] etc It will not work on the first iteration! Could just use DataBins GetBinName(i,i+1,i+1,i+3)
	outHtml << "<TR>";   //Need to add condition here to set up 4 headers for the next four fits  
	outHtml << "<TD><h1>"+JobName+"</h1>";
	outHtml << "<TD><h1>"+DataBins->GetBinName(i+1) +"</h1>";
	outHtml << "<TD><h1>"+DataBins->GetBinName(i+2)+"</h1>";
	outHtml << "<TD><h1>"+DataBins->GetBinName(i+3)+"</h1>";

	outHtml << "<TR>";   //Need to add condition here to set up 4 headers for the next four fits  
}
    histcounter++;





    TFile *ResultFile= TFile::Open(fileDir+"/"+FitName+"Results"+JobName+".root");
    if(!ResultFile){
	
        TString imFileName=JobName+FitVariable+"1";
	//can->SaveAs(outDir+imFileName);
	//can->Clear();
	gPad->SaveAs(outDir+imFileName);
	TString DefaultImage = "../../stoneimage.gif" ;
        outHtml << "<td><image src=\""+DefaultImage+"\" width=\"80%\"></image>" << endl;
	continue;
	}

    TH1F* result=(TH1F*) ResultFile->Get(JobName+FitVariable+"1");
    result->Draw();
    TString imFileName=JobName+FitVariable+"1.gif" ;
    gPad->Update();
    //TPaveStats *st=(TPaveStats*)result->FindObject("stats");
    TString TextBox = JobName + "TotalPDF0_paramBox";
    TPaveText * st = (TPaveText*)gPad->GetPrimitive(TextBox);
    gPad->Modified();
    gPad->Update();	
    st->SetX1NDC(0.6);
    st->SetX2NDC(0.8);
    st->SetY1NDC(0);		
    st->SetY2NDC(0.9);		
    gPad->SaveAs(outDir+imFileName);

    outHtml << "<td><image src=\""+imFileName+"\" width=\"80%\"></image>" << endl;

  }
}
 
