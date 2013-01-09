#pragma once
#ifndef HANDLE_STORAGE_H_
#define HANDLE_STORAGE_H_

#include <vdpau/vdpau_x11.h>
#include <glib.h>

typedef uint32_t    HandleType;
#define HANDLE_TYPE_ANY                         (HandleType)0
#define HANDLE_TYPE_DEVICE                      (HandleType)1
#define HANDLE_TYPE_PRESENTATION_QUEUE_TARGET   (HandleType)2
#define HANDLE_TYPE_PRESENTATION_QUEUE          (HandleType)3
#define HANDLE_TYPE_VIDEO_MIXER                 (HandleType)4

typedef struct {
    HandleType type;
} VdpGenericHandle;

typedef struct {
    HandleType type;
    Display *display;
    int screen;
} VdpDeviceData;

typedef struct {
    HandleType type;
    int device;
    Drawable drawable;
} VdpPresentationQueueTargetData;

typedef struct {
    HandleType type;
    int device;
    int presentationQueueTarget;
} VdpPresentationQueueData;

typedef struct {
    HandleType type;
    VdpDevice device;
} VdpVideoMixerData;


void handlestorage_initialize(void);
int handlestorage_add(void *data);
int handlestorage_valid(int handle, HandleType type);
void * handlestorage_get(int handle);
void handlestorage_destory(void);


#endif /* HANDLE_STORAGE_H_ */
