#ifndef __JETINPUT_H__
#define __JETINPUT_H__

#include <phool/PHCompositeNode.h>
#include "Jet.h"
#include <vector>

class JetInput {
  
public:

  virtual ~JetInput() {}

  virtual std::vector<Jet*> get_input(PHCompositeNode *topNode) {
    return std::vector<Jet*>();
  }


protected:
  JetInput() {}
  
private:
    
};

#endif