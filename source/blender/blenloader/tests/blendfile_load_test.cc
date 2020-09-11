/** The Original Code is Copyright (C) 2019 by Blender Foundation.
 */
#include "blendfile_loading_base_test.h"

class BlendfileLoadingTest : public BlendfileLoadingBaseTest {
};

TEST_F(BlendfileLoadingTest, CanaryTest)
{
  /* Load the smallest blend file we have in the SVN lib/tests directory. */
  if (!blendfile_load("modifier_stack/array_test.blend")) {
    return;
  }
  depsgraph_create(DAG_EVAL_RENDER);
  EXPECT_NE(nullptr, this->depsgraph);
}
