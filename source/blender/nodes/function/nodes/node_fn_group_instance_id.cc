#include "node_function_util.hh"

static bNodeSocketTemplate fn_node_group_instance_id_out[] = {
    {SOCK_STRING, N_("Identifier")},
    {-1, ""},
};

static void fn_node_group_instance_id_expand_in_mf_network(
    blender::nodes::NodeMFNetworkBuilder &builder)
{
  const blender::nodes::DNode &node = builder.dnode();
  std::string id = "/";
  for (const blender::nodes::DParentNode *parent = node.parent(); parent;
       parent = parent->parent()) {
    id = "/" + parent->node_ref().name() + id;
  }
  builder.construct_and_set_matching_fn<blender::fn::CustomMF_Constant<std::string>>(
      std::move(id));
}

void register_node_type_fn_group_instance_id()
{
  static bNodeType ntype;

  fn_node_type_base(&ntype, FN_NODE_GROUP_INSTANCE_ID, "Group Instance ID", 0, 0);
  node_type_socket_templates(&ntype, nullptr, fn_node_group_instance_id_out);
  ntype.expand_in_mf_network = fn_node_group_instance_id_expand_in_mf_network;
  nodeRegisterType(&ntype);
}
