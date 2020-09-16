/** \file
 * \ingroup editorui
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ID;
struct PointerRNA;
struct PreviewImage;
struct Scene;
struct bContext;
struct Collection;

enum eIconSizes;

typedef struct IconFile {
  struct IconFile *next, *prev;
  char filename[256]; /* FILE_MAXFILE size */
  int index;
} IconFile;

#define ICON_DEFAULT_HEIGHT 16
#define ICON_DEFAULT_WIDTH 16

#define ICON_DEFAULT_HEIGHT_TOOLBAR 32

#define ICON_DEFAULT_HEIGHT_SCALE ((int)(UI_UNIT_Y * 0.8f))
#define ICON_DEFAULT_WIDTH_SCALE ((int)(UI_UNIT_X * 0.8f))

#define PREVIEW_DEFAULT_HEIGHT 128

typedef enum eAlertIcon {
  ALERT_ICON_WARNING = 0,
  ALERT_ICON_QUESTION = 1,
  ALERT_ICON_ERROR = 2,
  ALERT_ICON_INFO = 3,
  ALERT_ICON_BLENDER = 4,
  ALERT_ICON_MAX,
} eAlertIcon;

struct ImBuf *UI_alert_image(eAlertIcon icon);

/*
 * Resizable Icons for Blender
 */
void UI_icons_init(void);
void UI_icons_reload_internal_textures(void);

int UI_icon_get_width(int icon_id);
int UI_icon_get_height(int icon_id);
bool UI_icon_get_theme_color(int icon_id, unsigned char color[4]);

void UI_id_icon_render(const struct bContext *C,
                       struct Scene *scene,
                       struct ID *id,
                       const bool big,
                       const bool use_job);
int UI_preview_render_size(enum eIconSizes size);

void UI_icon_draw(float x, float y, int icon_id);
void UI_icon_draw_alpha(float x, float y, int icon_id, float alpha);
void UI_icon_draw_preview(float x, float y, int icon_id, float aspect, float alpha, int size);

void UI_icon_draw_ex(float x,
                     float y,
                     int icon_id,
                     float aspect,
                     float alpha,
                     float desaturate,
                     const uchar mono_color[4],
                     const bool mono_border);

void UI_icons_free(void);
void UI_icons_free_drawinfo(void *drawinfo);

void UI_icon_draw_cache_begin(void);
void UI_icon_draw_cache_end(void);

struct ListBase *UI_iconfile_list(void);
int UI_iconfile_get_index(const char *filename);

struct PreviewImage *UI_icon_to_preview(int icon_id);

int UI_rnaptr_icon_get(struct bContext *C, struct PointerRNA *ptr, int rnaicon, const bool big);
int UI_idcode_icon_get(const int idcode);
int UI_library_icon_get(const struct ID *id);
int UI_mode_icon_get(const int mode);
int UI_collection_color_icon_get(const struct Collection *collection);

#ifdef __cplusplus
}
#endif
