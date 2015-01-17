#ifndef SIMPHOTONCOUNTERALG_H
#define SIMPHOTONCOUNTERALG_H

/*!
 * Title:   SimPhotonCounterALG Class
 * Author:  Wes Ketchum (wketchum@lanl.gov)
 *
 * Description: Alg class that counts up sim photons, leading towards 
 *              comparisons with flashes and flash hypotheses.
*/

#include "SimPhotonCounter.h"
#include "FlashHypothesis.h"

#include "fhiclcpp/ParameterSet.h"

#include "Geometry/Geometry.h"
#include "OpDigiProperties.h"

namespace opdet{

  class SimPhotonCounterAlg{

  public:
    SimPhotonCounterAlg(fhicl::ParameterSet const&);

    void InitializeCounters(geo::Geometry const&,
			    opdet::OpDigiProperties const&);
    
    void AddSimPhotonCollection(sim::SimPhotonsCollection const&);

    void ClearCounters();

    FlashHypothesisCollection GetFlashHypothesisCollection(size_t);
    std::vector<float> const& PromptPhotonVector(size_t);
    std::vector<float> const& LatePhotonVector(size_t);
    
  private:
    
    std::vector< std::vector<float> > fWavelengthRanges;
    std::vector< std::vector<float> > fTimeRanges;
    std::vector<SimPhotonCounter>     fCounters;

    void FillAllRanges(std::vector<fhicl::ParameterSet> const&);
    void FillRanges(fhicl::ParameterSet const&);
	
  };
  
}


#endif
