//
// FILE: lemkesub.h -- Solve efg by lemke on nfg
//
// $Id$
//

#ifndef LEMKESUB_H
#define LEMKESUB_H

#include "subsolve.h"
#include "lemke.h"

class efgLcpNfgSolve : public SubgameSolver  {
private:
  int npivots;
  LemkeParams params;

  void SolveSubgame(const FullEfg &, const EFSupport &,
		    gList<BehavSolution> &, gStatus &);
  EfgAlgType AlgorithmID(void) const { return algorithmEfg_LCP_NFG; }    

public:
  efgLcpNfgSolve(const LemkeParams &, int max = 0);
  virtual ~efgLcpNfgSolve();

  int NumPivots(void) const   { return npivots; }
};

#endif   // LEMKESUB_H