import bpy

class NewSimulation(bpy.types.Operator):
    """Create a new simulation data block and edit it in the opened simulation editor"""

    bl_idname = "simulation.new"
    bl_label = "New Simulation"
    bl_options = {'REGISTER', 'UNDO'}

    @classmethod
    def poll(cls, context):
        return context.area.type == 'NODE_EDITOR' and context.space_data.tree_type == 'SimulationNodeTree'

    def execute(self, context):
        simulation = bpy.data.simulations.new("Simulation")
        context.space_data.simulation = simulation
        return {'FINISHED'}

classes = (
    NewSimulation,
)
