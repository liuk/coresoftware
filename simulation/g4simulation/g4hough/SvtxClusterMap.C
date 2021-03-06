#include "SvtxClusterMap.h"

#include "SvtxCluster.h"

using namespace std;

ClassImp(SvtxClusterMap)

SvtxClusterMap::SvtxClusterMap()
: _map() {
}

SvtxClusterMap::~SvtxClusterMap() {
  _map.clear();
}

void SvtxClusterMap::identify(ostream& os) const {
  os << "SvtxClusterMap: size = " << _map.size() << endl;
  return;  
}

const SvtxCluster* SvtxClusterMap::get(unsigned int id) const {
  ConstIter iter = _map.find(id);
  if (iter == _map.end()) return NULL;  
  return &iter->second;
}

SvtxCluster* SvtxClusterMap::get(unsigned int id) {
  Iter iter = _map.find(id);
  if (iter == _map.end()) return NULL;
  return &iter->second;
}

SvtxCluster* SvtxClusterMap::insert(const SvtxCluster &clus) {
  unsigned int index = 0;
  if (!_map.empty()) index = _map.rbegin()->first + 1;
  _map.insert(make_pair( index , SvtxCluster(clus) ));
  _map[index].set_id(index);
  return (&_map[index]);
}
