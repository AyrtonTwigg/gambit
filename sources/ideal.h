//
// File: ideal.h  --  Declaration of gIdeal data type
// 
// $Id$
//

#ifndef IDEAL_H
#define IDEAL_H

#include "gpolylst.h"
#include "odometer.h"

/*
   By the Hilbert basis theorem, every ideal is generated by some finite
basis, and for computational purposes we essentially think of ideals
as bases.  There are some important operations, however, that differ
across the various bases generating a single ideal, and for this
reason we will have a separate basis class.  Operator == is defined
setwise -- computationally we sort the two bases and then compare
termwise.
   In class ideal operator == is defined in terms of the ideal generated.
Computationally two ideals agree if their ordered reduced Grobner bases are
the same.
 */

// ***********************
//      class gIdeal
// ***********************

template <class T> class gIdeal {
 private:
   const gSpace*      Space;
   const term_order*  order;
         gPolyList<T> basis;
   
 public:
  gIdeal(const gSpace *, const term_order *); // Null gIdeal constructor
  gIdeal(const gSpace *, const term_order *,
	      const gList< gPoly<T> *> &);
  gIdeal(const term_order *, const gPolyList<T> &);
  gIdeal(const gIdeal<T> &);

  ~gIdeal();

   // Operators
   gIdeal<T>& operator=(const gIdeal<T> &);

   bool      operator==(const gIdeal<T> &) const;
   bool      operator!=(const gIdeal<T> &) const;
   gIdeal<T> operator+ (const gIdeal<T> &) const;
   gIdeal<T> operator* (const gIdeal<T> &) const;

   // Information
   inline int               Dmnsn()            const { return Space->Dmnsn(); }
   inline const gSpace*     TheSpace()         const { return Space         ; }
   inline int               NoBasisElements()  const { return basis.Length(); }
   inline const term_order* Order()            const { return order; }
   inline gPolyList<T>      CanonicalBasis()   const { return basis; }
          gIdeal<T>         MonomialIdeal()    const;
          gList<exp_vect>   MonomialBasis()    const;
                // This returns a monomial basis of the ring of polynomial
                // functions on the variety V(I), where I is the given ideal.
                // It fails if the variety is not zero dimensional.
          bool              IsRoot(const gVector<T>&) const;

   bool ZeroDimensional()    const;
   bool IsEntireRing()       const;
   bool Contains(gPoly<T> &) const;
};  

#endif //# IDEAL_H