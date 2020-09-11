#include "FN_multi_function.hh"

namespace blender::fn {

class DummyMultiFunction : public MultiFunction {
 public:
  DummyMultiFunction()
  {
    this->get_builder("Dummy");
  }

  void call(IndexMask UNUSED(mask),
            MFParams UNUSED(params),
            MFContext UNUSED(context)) const override
  {
  }
};

static DummyMultiFunction dummy_multi_function_;
const MultiFunction &dummy_multi_function = dummy_multi_function_;

}  // namespace blender::fn
