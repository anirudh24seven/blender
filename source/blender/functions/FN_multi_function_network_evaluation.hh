#pragma once

/** \file
 * \ingroup fn
 */

#include "FN_multi_function_network.hh"

namespace blender::fn {

class MFNetworkEvaluationStorage;

class MFNetworkEvaluator : public MultiFunction {
 private:
  Vector<const MFOutputSocket *> inputs_;
  Vector<const MFInputSocket *> outputs_;

 public:
  MFNetworkEvaluator(Vector<const MFOutputSocket *> inputs, Vector<const MFInputSocket *> outputs);

  void call(IndexMask mask, MFParams params, MFContext context) const override;

 private:
  using Storage = MFNetworkEvaluationStorage;

  void copy_inputs_to_storage(MFParams params, Storage &storage) const;
  void copy_outputs_to_storage(
      MFParams params,
      Storage &storage,
      Vector<const MFInputSocket *> &outputs_to_initialize_in_the_end) const;

  void evaluate_network_to_compute_outputs(MFContext &global_context, Storage &storage) const;

  void evaluate_function(MFContext &global_context,
                         const MFFunctionNode &function_node,
                         Storage &storage) const;

  bool can_do_single_value_evaluation(const MFFunctionNode &function_node, Storage &storage) const;

  void initialize_remaining_outputs(MFParams params,
                                    Storage &storage,
                                    Span<const MFInputSocket *> remaining_outputs) const;
};

}  // namespace blender::fn
