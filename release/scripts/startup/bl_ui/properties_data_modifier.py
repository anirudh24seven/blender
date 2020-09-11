# <pep8 compliant>
import bpy
from bpy.types import Panel
from bpy.app.translations import pgettext_iface as iface_


class ModifierButtonsPanel:
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'WINDOW'
    bl_context = "modifier"
    bl_options = {'HIDE_HEADER'}


class DATA_PT_modifiers(ModifierButtonsPanel, Panel):
    bl_label = "Modifiers"

    @classmethod
    def poll(cls, context):
        ob = context.object
        return ob and ob.type != 'GPENCIL'

    def draw(self, context):
        layout = self.layout
        layout.operator_menu_enum("object.modifier_add", "type")
        layout.template_modifiers()


class DATA_PT_gpencil_modifiers(ModifierButtonsPanel, Panel):
    bl_label = "Modifiers"

    @classmethod
    def poll(cls, context):
        ob = context.object
        return ob and ob.type == 'GPENCIL'

    def draw(self, context):
        layout = self.layout
        layout.operator_menu_enum("object.gpencil_modifier_add", "type")
        layout.template_grease_pencil_modifiers()


classes = (
    DATA_PT_modifiers,
    DATA_PT_gpencil_modifiers,
)

if __name__ == "__main__":  # only for live edit.
    from bpy.utils import register_class

    for cls in classes:
        register_class(cls)
