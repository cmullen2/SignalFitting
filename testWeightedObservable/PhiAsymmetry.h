/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef PHIASYMMETRY
#define PHIASYMMETRY

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class PhiAsymmetry : public RooAbsPdf {
public:
  PhiAsymmetry() {} ; 
  PhiAsymmetry(const char *name, const char *title,
	      RooAbsReal& _Phi,
	      RooAbsReal& _Pol,
	      RooAbsCategory& _PolState,
	      RooAbsReal& _A,
	      RooAbsReal& _B);
  PhiAsymmetry(const PhiAsymmetry& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new PhiAsymmetry(*this,newname); }
  inline virtual ~PhiAsymmetry() { }

protected:

  RooRealProxy Phi ;
  RooRealProxy Pol ;
  RooCategoryProxy PolState ;
  RooRealProxy A ;
  RooRealProxy B ;
  
  Double_t evaluate() const ;

private:

  ClassDef(PhiAsymmetry,1) // Your description goes here...
};
 
#endif
