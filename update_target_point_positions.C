#include "update_target_point_positions.h"

//IBAMR INCLUDES
#include <ibamr/IBTargetPointForceSpec.h>

//IBTK INCLUDES
#includes <ibtk/LNodeIndexData.h>

//NAMESPACE
using namespace IBAMR 

void 
update_target_positions(tbox::Pointer<hier::PatchHierarchy<NDIM>> hierarchy, 
			LDataManager* const lag_manager, 
			const double current_time, 
			const double dt)
{
  const int finest_in = hierarchy->getFinestLevelNumber();

  //have to specify wave amplitude and frequency of oscillations

  alpha = 0.3;  //amplitude of compression 
  beta = 0.5;  //frequency of compression

  //get lagrangian index range
  const std::pair<int,int>& tube_lag_idxs = lag_manager->getLagrangianStructureIndexRange(0, finest_in);
    
  //get the patch data descriptor index for the LNodeIndexData
  const int lag_node_index_idx = lag_manager->getLNodeIndexPatchDescriptorIndex();

  //update the target point positions in their assiciated target point forces
  tbox::Pointer<hier::PatchLevel<NDIM>>level = hierarchy->getPatchLevel(finest_in);
  for (SAMRAI::hier::PatchLevel<NDIM>::Iterator p(level); p; p++)
    {
      SAMRAI::tbox::Pointer<SAMRAI::hier::Patch<NDIM>> patch = level->getPatch(p());
      const SAMRAI::hier::Box<NDIM>& patch_box = patch->getBox();
      const SAMRAI::tbox::Pointer<LNodeIndexData> idx_data = patch->getPatchData(lag_node_index_idx);
