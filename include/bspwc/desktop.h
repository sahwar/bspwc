#ifndef DESKTOP_H
#define DESKTOP_H

#include <wayland-server.h>

#include "bspwc/output.h"
#include "bspwc/window.h"

#define DEFAULT_DESKTOP_NAME "desktop"

struct desktop
{
	struct output* output;

	char name[8]; // is 8 chars too much or too little ?

	struct desktop* next;
	struct desktop* previous;

	struct wl_list windows; // window::link
};

struct desktop* create_desktop(struct output* output);
void destroy_desktop(struct desktop* desktop);

bool desktop_insert_window(struct desktop* desktop, struct window* window);

#endif // DESKTOP_H