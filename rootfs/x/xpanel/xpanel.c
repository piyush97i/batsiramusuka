#include <dev/devserv.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <kstring.h>
#include <sconf.h>
#include <x/xclient.h>

typedef struct {
	uint32_t fg_color, bg_color;
	font_t* font;
	graph_t* g;
} panel_t;

static int32_t read_config(panel_t* panel, const char* fname, int32_t *w, int32_t *h) {
	sconf_t *conf = sconf_load(fname);	
	if(conf == NULL)
		return -1;
	
	const char* v = sconf_get(conf, "bg_color");
	if(v[0] != 0) 
		panel->bg_color = argb_int(atoi_base(v, 16));

	v = sconf_get(conf, "fg_color");
	if(v[0] != 0) 
		panel->fg_color = argb_int(atoi_base(v, 16));

	v = sconf_get(conf, "font");
	if(v[0] != 0) 
		panel->font = get_font_by_name(v);

	v = sconf_get(conf, "width");
	if(v[0] != 0) 
		*w = atoi_base(v, 10);

	v = sconf_get(conf, "height");
	if(v[0] != 0) 
		*h = atoi_base(v, 10);
	sconf_free(conf, MFS);
	return 0;
}

int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	gsize_t size = { 1024, 20 };
	int style = X_STYLE_NO_FRAME | X_STYLE_ALPHA;
	x_t x;
	panel_t panel;
	panel.fg_color = 0xff111111;
	panel.bg_color = 0xff888888;
	panel.font = get_font_by_name("8x16");
	x_get_scr_size("/dev/X0", &size);

	read_config(&panel, "/etc/x/xpanel.conf", &size.w, &size.h);

	if(x_open("/dev/X0", &x) != 0)
		return -1;

	x_move_to(&x, 0, 0);
	x_resize_to(&x, size.w, size.h);
	panel.g = x_get_graph(&x);
	x_set_style(&x, style);
	x_set_state(&x, X_STATE_NORMAL);
	clear(panel.g, panel.bg_color);
	draw_text(panel.g, 2, 4, "EwokOS micro-kernel OS v0.01", panel.font, panel.fg_color);

	while(true) {
		x_ev_t ev;
		if(x_get_event("/dev/X0", &ev) == 0) {
			/*if(ev.type == X_EV_MOUSE) {
				if(ev.state == X_EV_MOUSE_DOWN) {
				}
			}
			*/
		}
		else {
			sleep(0);
		}
	}
	graph_free(panel.g);
	x_close(&x);
	return 0;
}
