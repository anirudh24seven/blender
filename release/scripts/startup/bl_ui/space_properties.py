# <pep8 compliant>
from bpy.types import Header, Panel


class PROPERTIES_HT_header(Header):
    bl_space_type = 'PROPERTIES'

    def draw(self, _context):
        layout = self.layout

        layout.template_header()


class PROPERTIES_PT_navigation_bar(Panel):
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'NAVIGATION_BAR'
    bl_label = "Navigation Bar"
    bl_options = {'HIDE_HEADER'}

    def draw(self, context):
        layout = self.layout

        view = context.space_data

        layout.scale_x = 1.4
        layout.scale_y = 1.4
        layout.prop_tabs_enum(view, "context", icon_only=True)


classes = (
    PROPERTIES_HT_header,
    PROPERTIES_PT_navigation_bar,
)

if __name__ == "__main__":  # only for live edit.
    from bpy.utils import register_class
    for cls in classes:
        register_class(cls)
