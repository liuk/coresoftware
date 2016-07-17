// $Id: $                                                                                             

/*!
 * \file PHGeomTGeo.h
 * \brief 
 * \author Jin Huang <jhuang@bnl.gov>
 * \version $Revision:   $
 * \date $Date: $
 */

#ifndef PHGEOMTGEO_H_
#define PHGEOMTGEO_H_

#include <phool/PHObject.h>

class TGeoManager;

/*!
 * \brief PHGeomTGeo provide run-time access to TGeoManger. It is non-persistent and it shall NOT be saved to DST.
 */
class PHGeomTGeo : public PHObject
{
public:
  PHGeomTGeo();
  virtual
  ~PHGeomTGeo();

  /** identify Function from PHObject
      @param os Output Stream
   */
  virtual void identify(std::ostream& os = std::cout) const;

  /// Clear Event
  virtual void Reset();

  /// isValid returns non zero if object contains vailid data
  virtual int isValid() const;

  //! The pointer TGeoManager should be the current gGeoManager
  void
  SetGeometry(TGeoManager * g);

  TGeoManager *
  GetGeometry();

protected:

  //! Since ROOT force TGeoManager is a unique object via global pointer gGeoManager,
  //! this function checks whether _fGeom is still the current gGeoManager which avoids operates on an invalid pointer
  bool ConsistencyCheck() const;

  //! store and stream the full geometry via DST objects
  TGeoManager * _fGeom;

//  ClassDef(PHGeomTGeo,1)
};

#endif /* PHGEOMTGEO_H_ */
