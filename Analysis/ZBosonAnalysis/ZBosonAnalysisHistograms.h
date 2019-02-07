////////////////////////////////////////////////////////////////////////////////
#include "TROOT.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include <iostream>

void ZBosonAnalysis::define_histograms()
{
  // HISTOGRAMS
  
  // Global variables histograms
  hist_mLL         = new TH1F("hist_mLL",        "Mass of Dilepton System; m_{ll};Events", 30, 60, 120);
  hist_etmiss       = new TH1F("hist_etmiss",      "Missing Transverse Momentum;E_{T,Miss} [GeV];Events", 20, 0,200);
  hist_vxp_z        = new TH1F("hist_vxp_z",       "Primary Vertex Position; z_{Vertex}; Events", 40, -200,200);
  hist_pvxp_n       = new TH1F("hist_pvxp_n",      "Number of Vertices; N_{vertex}; Events", 30, -0.5,29.5);
 
  // Jet variables histograms
  hist_n_jets           = new TH1F("hist_n_jets",          "Number of Jets;N_{jets};Events", 10, -0.5, 9.5);
  hist_leadjet_pt       = new TH1F("hist_leadjet_pt",      "Leading Jet Transverse Momentum;p_{T}^{leadjet} [GeV];Jets", 20, 0, 200);
  hist_leadjet_m        = new TH1F("hist_leadjet_m",       "Leading Jet Mass; m^{leadjet} [GeV]; Jets", 20, 0, 20);
  hist_leadjet_jvf      = new TH1F("hist_leadjet_jvf",     "Leading Jet Vertex Fraction; JVF^{leadjet} ; Jets", 20, 0, 1);
  hist_leadjet_eta      = new TH1F("hist_leadjet_eta",     "Leading Jet Pseudorapidity; #eta^{leadjet}; Jets", 30, -3, 3);
  hist_leadjet_MV1      = new TH1F("hist_leadjet_MV1",     "Leading Jet MV1; MV1 weight^{leadjet} ; Jets", 20, 0, 1);

  // Leading Lepton histograms
  hist_leadleptpt   = new TH1F("hist_leadleptpt",  "Leading Lepton Transverse Momentum;p_{T}^{leadlep} [GeV];Leptons", 20, 0, 200);
  hist_leadlepteta  = new TH1F("hist_leadlepteta", "Leading Lepton Pseudorapidity; #eta^{leadlep}; Leptons", 30, -3, 3);
  hist_leadleptE    = new TH1F("hist_leadleptE",   "Leading Lepton Energy; E^{leadlep} [GeV]; Leptons", 30, 0, 300);
  hist_leadleptphi  = new TH1F("hist_leadleptphi", "Leading Lepton Azimuthal Angle ; #phi^{leadlep}; Leptons", 32, -3.2, 3.2);
  hist_leadleptch   = new TH1F("hist_leadleptch",  "Leading Lepton Charge; Q^{leadlep}; Leptons", 7, -1.75, 1.75);
  hist_leadleptID   = new TH1F("hist_leadleptID",  "Leading Lepton Absolute PDG ID; |PDG ID|^{leadlep}; Leptons",  31, -0.5, 30.5);
  hist_leadlept_ptc  = new TH1F("hist_leadlept_ptc", "Leading Lepton Relative Transverse Momentum Isolation; ptconerel30^{leadlep}; Leptons", 40, -0.1, 0.4);
  hist_leadleptetc  = new TH1F("hist_leadleptetc", "Leading Lepton Relative Transverse Energy Isolation; etconerel20^{leadlep}; Leptons", 40, -0.1, 0.4);
  hist_leadlepz0    = new TH1F("hist_leadlepz0",   "Leading Lepton z0 impact parameter; z_{0}^{leadlep} [mm]; Leptons", 40, -1, 1);
  hist_leadlepd0    = new TH1F("hist_leadlepd0",   "Leading Lepton d0 impact parameter; d_{0}^{leadlep} [mm]; Leptons", 40, -1, 1);

  // Subleading Lepton histograms
  hist_subleadleptpt  = new TH1F("hist_subleadleptpt", "Subleading Lepton Transverse Momentum;p_{T}^{traillep} [GeV];Leptons", 20, 0, 200);
  hist_subleadlepteta = new TH1F("hist_subleadlepteta","Subleading Lepton Pseudorapidity; #eta^{traillep}; Leptons", 10, -3, 3);
  hist_subleadleptE   = new TH1F("hist_subleadleptE",  "Subleading Lepton Energy; E^{traillep} [GeV]; Leptons", 30, 0, 300);
  hist_subleadleptphi = new TH1F("hist_subleadleptphi","Subleading Lepton Azimuthal Angle ; #phi^{traillep}; Leptons", 32, -3.2, 3.2);
  hist_subleadleptch  = new TH1F("hist_subleadleptch", "Subleading Lepton Charge; Q^{traillep}; Leptons", 7, -1.75, 1.75);
  hist_subleadleptID  = new TH1F("hist_subleadleptID", "Subleading Lepton Absolute PDG ID; |PDG ID|^{traillep}; Leptons",  31, -0.5, 30.5);
  hist_subleadlept_ptc = new TH1F("hist_subleadlept_ptc","Subleading Lepton Relative Transverse Momentum Isolation; ptconerel30^{traillep} [GeV]; Leptons", 40, -0.1, 0.4);
  hist_subleadleptetc = new TH1F("hist_subleadleptetc","Subleading Lepton Relative Transverse Energy Isolation; etconerel20^{traillep} [GeV]; Leptons", 40, -0.1, 0.4);
  hist_subleadlepz0   = new TH1F("hist_subleadlepz0",  "Subleading Lepton z0 impact parameter; z_{0}^{traillep} [mm]; Leptons", 40, -1, 1);
  hist_subleadlepd0   = new TH1F("hist_subleadlepd0",  "Trailing Lepton d0 impact parameter; d_{0}^{traillep} [mm]; Leptons", 40, -1, 1);

}

////////////////////////////////////////////////////////////////////////////////
void ZBosonAnalysis::FillOutputList()
{
  // histograms

  // Add Global variables histograms
  GetOutputList()->Add(hist_etmiss);
  GetOutputList()->Add(hist_vxp_z);
  GetOutputList()->Add(hist_pvxp_n);
  GetOutputList()->Add(hist_mLL);

  // Add Leading Lepton histograms
  GetOutputList()->Add(hist_leadleptpt);
  GetOutputList()->Add(hist_leadlepteta);
  GetOutputList()->Add(hist_leadleptE);
  GetOutputList()->Add(hist_leadleptphi);
  GetOutputList()->Add(hist_leadleptch);
  GetOutputList()->Add(hist_leadleptID);
  GetOutputList()->Add(hist_leadlept_ptc);
  GetOutputList()->Add(hist_leadleptetc);
  GetOutputList()->Add(hist_leadlepz0);
  GetOutputList()->Add(hist_leadlepd0);

  // Add Subleading Lepton histograms
  GetOutputList()->Add(hist_subleadleptpt);
  GetOutputList()->Add(hist_subleadlepteta);
  GetOutputList()->Add(hist_subleadleptE);
  GetOutputList()->Add(hist_subleadleptphi);
  GetOutputList()->Add(hist_subleadleptch);
  GetOutputList()->Add(hist_subleadleptID);
  GetOutputList()->Add(hist_subleadlept_ptc);
  GetOutputList()->Add(hist_subleadleptetc);
  GetOutputList()->Add(hist_subleadlepz0);
  GetOutputList()->Add(hist_subleadlepd0);

  //Add Jet variables histograms
  GetOutputList()->Add(hist_n_jets);
  GetOutputList()->Add(hist_leadjet_pt);
  GetOutputList()->Add(hist_leadjet_m);
  GetOutputList()->Add(hist_leadjet_jvf);
  GetOutputList()->Add(hist_leadjet_eta);
  GetOutputList()->Add(hist_leadjet_MV1);

}

////////////////////////////////////////////////////////////////////////////////
void ZBosonAnalysis::WriteHistograms()
{
  // histograms

  // Write Global histograms
  hist_etmiss->Write();
  hist_vxp_z->Write();
  hist_pvxp_n->Write();
  hist_mLL->Write();

  //Write Leading Lepton histograms
  hist_leadleptpt->Write();
  hist_leadlepteta->Write();
  hist_leadleptE->Write();
  hist_leadleptphi->Write();
  hist_leadleptch->Write();
  hist_leadleptID->Write();
  hist_leadlept_ptc->Write();
  hist_leadleptetc->Write();
  hist_leadlepz0->Write();
  hist_leadlepd0->Write();

  //Write Subleading Lepton histograms
  hist_subleadleptpt->Write();
  hist_subleadlepteta->Write();
  hist_subleadleptE->Write();
  hist_subleadleptphi->Write();
  hist_subleadleptch->Write();
  hist_subleadleptID->Write();
  hist_subleadlept_ptc->Write();
  hist_subleadleptetc->Write();
  hist_subleadlepz0->Write();
  hist_subleadlepd0->Write();

  //Write Jet variables histograms
  hist_n_jets->Write();
  hist_leadjet_pt->Write();
  hist_leadjet_m->Write();
  hist_leadjet_jvf->Write();
  hist_leadjet_eta->Write();
  hist_leadjet_MV1->Write();

}

void ZBosonAnalysis::FillHistogramsGlobal( double m, float w , TString s)
{

  //Fill Global histograms
  if (s.Contains("hist_mLL")) hist_mLL->Fill(m,w);

  if (s.Contains("hist_etmiss")) hist_etmiss->Fill(m,w);

  if (s.Contains("hist_vxp_z")) hist_vxp_z->Fill(m,w);

  if (s.Contains("hist_pvxp_n")) hist_pvxp_n->Fill(m,w);

}

void ZBosonAnalysis::FillHistogramsLeadlept( double m, float w , TString s)
{
  //Fill Leading lepton histograms
  if (s.Contains("hist_leadleptpt")) hist_leadleptpt->Fill(m,w);

  if (s.Contains("hist_leadlepteta")) hist_leadlepteta->Fill(m,w);

  if (s.Contains("hist_leadleptE")) hist_leadleptE->Fill(m,w);

  if (s.Contains("hist_leadleptphi")) hist_leadleptphi->Fill(m,w);

  if (s.Contains("hist_leadleptch")) hist_leadleptch->Fill(m,w);

  if (s.Contains("hist_leadleptID")) hist_leadleptID->Fill(m,w);

  if (s.Contains("hist_leadlept_ptc")) hist_leadlept_ptc->Fill(m,w);

  if (s.Contains("hist_leadleptetc")) hist_leadleptetc->Fill(m,w);

  if (s.Contains("hist_leadlepz0")) hist_leadlepz0->Fill(m,w);

  if (s.Contains("hist_leadlepd0")) hist_leadlepd0->Fill(m,w);

}

void ZBosonAnalysis::FillHistogramsSubleadlept( double m, float w , TString s)
{
  //Fill Subleading lepton histograms
  if (s.Contains("hist_subleadleptpt")) hist_subleadleptpt->Fill(m,w);

  if (s.Contains("hist_subleadlepteta")) hist_subleadlepteta->Fill(m,w);

  if (s.Contains("hist_subleadleptE")) hist_subleadleptE->Fill(m,w);

  if (s.Contains("hist_subleadleptphi")) hist_subleadleptphi->Fill(m,w);

  if (s.Contains("hist_subleadleptch")) hist_subleadleptch->Fill(m,w);

  if (s.Contains("hist_subleadleptID")) hist_subleadleptID->Fill(m,w);

  if (s.Contains("hist_subleadlept_ptc")) hist_subleadlept_ptc->Fill(m,w);

  if (s.Contains("hist_subleadleptetc")) hist_subleadleptetc->Fill(m,w);

  if (s.Contains("hist_subleadlepz0")) hist_subleadlepz0->Fill(m,w);

  if (s.Contains("hist_subleadlepd0")) hist_subleadlepd0->Fill(m,w);
}

void ZBosonAnalysis::FillHistogramsLeadJet( double m, float w , TString s)
{
  //Fill Leading Jet histograms
  if (s.Contains("hist_n_jets")) hist_n_jets->Fill(m,w);

  if (s.Contains("hist_leadjet_pt")) hist_leadjet_pt->Fill(m,w);

  if (s.Contains("hist_leadjet_m")) hist_leadjet_m->Fill(m,w);

  if (s.Contains("hist_leadjet_jvf")) hist_leadjet_jvf->Fill(m,w);

  if (s.Contains("hist_leadjet_eta")) hist_leadjet_eta->Fill(m,w);

  if (s.Contains("hist_leadjet_MV1")) hist_leadjet_MV1->Fill(m,w);

}

////////////////////////////////////////////////////////////////////////////////
