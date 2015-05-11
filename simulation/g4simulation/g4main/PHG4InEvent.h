#ifndef PHG4InEvent_H__
#define PHG4InEvent_H__

#include <phool/PHObject.h>

#include <map>
#include <set>

class PHG4Particle;
class PHG4VtxPoint;

class PHG4InEvent: public PHObject
{
 public:
  PHG4InEvent() {}
  virtual ~PHG4InEvent();

  virtual void identify(std::ostream& os = std::cout) const;
  void Reset();
  // this one is for HepMC records where we want to keep the HepMC vertex numbering
  int AddVtxHepMC(const int id, const double x, const double y, const double z, const double t);
  int AddVtx(const double x, const double y, const double z, const double t);
  int AddVtx(const int id,const PHG4VtxPoint &);
  int AddParticle(const int vtxid, PHG4Particle *particle);
  void AddEmbeddedParticle(PHG4Particle *particle) {embedded_particlelist.insert(particle);}

  //  PHG4VtxPoint *GetVtx() {return vtxlist.begin()->second;}
  std::pair< std::map<int, PHG4VtxPoint *>::const_iterator, std::map<int, PHG4VtxPoint *>::const_iterator > GetVertices() const;
  std::pair< std::multimap<int,PHG4Particle *>::const_iterator, std::multimap<int,PHG4Particle *>::const_iterator > GetParticles(const int vtxid) const;
  std::pair< std::multimap<int,PHG4Particle *>::const_iterator, std::multimap<int,PHG4Particle *>::const_iterator > GetParticles() const;
  std::pair< std::multimap<int,PHG4Particle *>::iterator, std::multimap<int,PHG4Particle *>::iterator > GetParticles_Modify();
  std::pair< std::set<PHG4Particle *>::const_iterator, std::set<PHG4Particle *>::const_iterator> GetEmbeddedParticles() const
    {return std::make_pair(embedded_particlelist.begin(), embedded_particlelist.end());}
  int isEmbeded(PHG4Particle *) const;
  int GetNEmbedded() const {return embedded_particlelist.size();}
  int GetNVtx() const {return vtxlist.size();}
  void DeleteParticle(std::multimap<int,PHG4Particle *>::iterator &iter);

 protected:

  int AddVtxCommon(PHG4VtxPoint *newvtx);
  std::map<int,PHG4VtxPoint *> vtxlist;
  std::multimap<int,PHG4Particle *> particlelist;
  std::set<PHG4Particle *> embedded_particlelist;

  ClassDef(PHG4InEvent,1)
};

#endif