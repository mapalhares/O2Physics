// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

// jet finder B+ data charged task
//
/// \author Nima Zardoshti <nima.zardoshti@cern.ch>

#include "PWGJE/JetFinders/jetFinderHF.cxx"

using JetFinderBplusDataCharged = JetFinderHFTask<aod::CandidatesBplusData, aod::CandidatesBplusMCD, aod::CandidatesBplusMCP, aod::JetTracksSubBplus, aod::JetParticlesSubBplus, aod::BplusChargedJets, aod::BplusChargedJetConstituents, aod::BplusChargedEventWiseSubtractedJets, aod::BplusChargedEventWiseSubtractedJetConstituents>;

WorkflowSpec defineDataProcessing(ConfigContext const& cfgc)
{
  std::vector<o2::framework::DataProcessorSpec> tasks;

  tasks.emplace_back(adaptAnalysisTask<JetFinderBplusDataCharged>(cfgc,
                                                                  SetDefaultProcesses{{{"processChargedJetsData", true}}},
                                                                  TaskName{"jet-finder-bplus-data-charged"}));

  return WorkflowSpec{tasks};
}
