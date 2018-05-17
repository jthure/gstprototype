/*
 * GStreamer
 * Copyright (C) 2005 Thomas Vander Stichele <thomas@apestaart.org>
 * Copyright (C) 2005 Ronald S. Bultje <rbultje@ronald.bitfreak.net>
 * Copyright (C) 2018 jonas <<user@hostname.org>>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * SECTION:element-myfilter
 *
 * FIXME:Describe myfilter here.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch -v -m fakesrc ! myfilter ! fakesink silent=TRUE
 * ]|
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gst/gst.h>
#include <gstreamer-1.0/gst/base/gstbasetransform.h>

#include "gstmyfilter.h"
#include "charm_embed_api.h"
#include <Python.h>

GST_DEBUG_CATEGORY_STATIC(gst_my_filter_debug);
#define GST_CAT_DEFAULT gst_my_filter_debug

/* Filter signals and args */
enum
{
  /* FILL ME */
  LAST_SIGNAL
};

enum
{
  PROP_0,
  PROP_SILENT,
  PROP_PRE_MODE
};
/* the capabilities of the inputs and outputs.
 *
 * describe the real formats here.
 */
static GstStaticPadTemplate sink_factory = GST_STATIC_PAD_TEMPLATE("sink",
                                                                   GST_PAD_SINK,
                                                                   GST_PAD_ALWAYS,
                                                                   GST_STATIC_CAPS("ANY"));

static GstStaticPadTemplate src_factory = GST_STATIC_PAD_TEMPLATE("src",
                                                                  GST_PAD_SRC,
                                                                  GST_PAD_ALWAYS,
                                                                  GST_STATIC_CAPS("ANY"));

#define gst_my_filter_parent_class parent_class
G_DEFINE_TYPE(GstMyFilter, gst_my_filter, GST_TYPE_BASE_TRANSFORM);

static void gst_my_filter_set_property(GObject *object, guint prop_id,
                                       const GValue *value, GParamSpec *pspec);
static void gst_my_filter_get_property(GObject *object, guint prop_id,
                                       GValue *value, GParamSpec *pspec);

// static gboolean gst_my_filter_sink_event (GstPad * pad, GstObject * parent, GstEvent * event);
// static GstFlowReturn gst_my_filter_chain (GstPad * pad, GstObject * parent, GstBuffer * buf);
static GstFlowReturn gst_my_filter_transform(GstBaseTransform *trans, GstBuffer *in_buf, GstBuffer *out_buf);
/* GObject vmethod implementations */

/* initialize the myfilter's class */
static void gst_my_filter_class_init(GstMyFilterClass *klass)
{
  GObjectClass *gobject_class;
  GstElementClass *gstelement_class;

  gobject_class = (GObjectClass *)klass;
  gstelement_class = (GstElementClass *)klass;

  gobject_class->set_property = gst_my_filter_set_property;
  gobject_class->get_property = gst_my_filter_get_property;

  g_object_class_install_property(gobject_class, PROP_SILENT,
                                  g_param_spec_boolean("silent", "Silent", "Produce verbose output ?",
                                                       FALSE, G_PARAM_READWRITE));

  gst_element_class_set_details_simple(gstelement_class,
                                       "MyFilter",
                                       "FIXME:Generic",
                                       "FIXME:Generic Template Element",
                                       "jonas <<user@hostname.org>>");

  gst_element_class_add_pad_template(gstelement_class,
                                     gst_static_pad_template_get(&src_factory));
  gst_element_class_add_pad_template(gstelement_class,
                                     gst_static_pad_template_get(&sink_factory));

  GST_BASE_TRANSFORM_CLASS(klass)->transform = GST_DEBUG_FUNCPTR(gst_my_filter_transform);
}

/* initialize the new element
 * instantiate pads and add them to element
 * set pad calback functions
 * initialize instance structure
 */
static Charm_t *InitSignatureScheme(const char *class_file, const char *class_name)
{
  PyObject *py_class_name, *module = NULL, *func = NULL, *class_instance = NULL, *args = NULL;
  py_class_name = PyUnicode_FromString(class_file);
  module = PyImport_Import(py_class_name);
  Free(py_class_name);
  if (module != NULL)
  {
    debug("successful import: '%s'\n", module->ob_type->tp_name);
    func = PyObject_GetAttrString(module, class_name);
    debug("got attr string: '%s'\n", func->ob_type->tp_name);
    if (func && PyCallable_Check(func))
    {
      args = PyTuple_New(0);
      debug("calling class init.\n");
      // instantiate class_instance = ClassName()
      class_instance = PyObject_CallObject(func, args);
      debug("success: \n");
      Free(args);
    }
    else
    {
      // call failed
      if (PyErr_Occurred())
        PyErr_Print();
      fprintf(stderr, "Cannot find function.\n");
    }
    Free(func);
    Free(module);
    return (Charm_t *)class_instance;
  }
  else
  {
    if (PyErr_Occurred())
      PyErr_Print();
    fprintf(stderr, "Cannot complete import.\n");
  }
}
static void
gst_my_filter_init(GstMyFilter *filter)
{
  GST_INFO_OBJECT(filter, "Initializing plugin");
  Charm_t *module = NULL, *group = NULL, *scheme = NULL, *sig = NULL, *hyb = NULL;

  InitializeCharm();
  PyObject *pModule = NULL, *pClassName = NULL;
  pClassName = PyUnicode_FromString("charm.adapters.abenc_adapt_hybrid");
	pModule = PyImport_Import(pClassName);

  group = InitPairingGroup(module, "SS512");
  if (group == NULL)
  {
    printf("could not import pairing group.\n");
    return;
  }
  sig = InitSignatureScheme("charm.schemes.pksig.lamport_jm", "Lamport");
  scheme = InitScheme("charm.schemes.prenc.pre_afgh06_temp_jm", "AFGH06Temp", group);
  if (scheme == NULL)
  {
    printf("could not create scheme.\n");
    return;
  }
  hyb = InitAdapter("charm.adapters.abenc_adapt_hybrid", "HybridUniPREnc", scheme);
  if(hyb == NULL)
  {
    printf("could not create hybrid.\n");
    return;
  }

  Charm_t *params = CallMethod(scheme, "setup", "");
  Charm_t *keys = CallMethod(scheme, "keygen", "%O", params);
  Charm_t *pk = GetIndex(keys, 0);
  Charm_t *sk = GetIndex(keys, 1);

  filter->scheme = scheme;
  filter->group = group;
  filter->params = params;
  filter->pk = pk;
  filter->sk = sk;

  // filter->sinkpad = gst_pad_new_from_static_template (&sink_factory, "sink");
  // gst_pad_set_event_function (filter->sinkpad,
  //                             GST_DEBUG_FUNCPTR(gst_my_filter_sink_event));
  // gst_pad_set_chain_function (filter->sinkpad,
  //                             GST_DEBUG_FUNCPTR(gst_my_filter_chain));
  // GST_PAD_SET_PROXY_CAPS (filter->sinkpad);
  // gst_element_add_pad (GST_ELEMENT (filter), filter->sinkpad);

  // filter->srcpad = gst_pad_new_from_static_template (&src_factory, "src");
  // GST_PAD_SET_PROXY_CAPS (filter->srcpad);
  // gst_element_add_pad (GST_ELEMENT (filter), filter->srcpad);

  filter->silent = FALSE;
}

static void
gst_my_filter_set_property(GObject *object, guint prop_id,
                           const GValue *value, GParamSpec *pspec)
{
  GstMyFilter *filter = GST_MYFILTER(object);

  switch (prop_id)
  {
  case PROP_SILENT:
    filter->silent = g_value_get_boolean(value);
    break;
  case PROP_PRE_MODE:
    filter->mode = g_value_get_int(value);
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    break;
  }
}

static void
gst_my_filter_get_property(GObject *object, guint prop_id,
                           GValue *value, GParamSpec *pspec)
{
  GstMyFilter *filter = GST_MYFILTER(object);

  switch (prop_id)
  {
  case PROP_SILENT:
    g_value_set_boolean(value, filter->silent);
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    break;
  }
}

/* GstElement vmethod implementations */

/* this function handles sink events */
// static gboolean
// gst_my_filter_sink_event (GstPad * pad, GstObject * parent, GstEvent * event)
// {
//   GstMyFilter *filter;
//   gboolean ret;

//   filter = GST_MYFILTER (parent);

//   GST_LOG_OBJECT (filter, "Received %s event: %" GST_PTR_FORMAT,
//       GST_EVENT_TYPE_NAME (event), event);

//   switch (GST_EVENT_TYPE (event)) {
//     case GST_EVENT_CAPS:
//     {
//       GstCaps * caps;

//       gst_event_parse_caps (event, &caps);
//       /* do something with the caps */

//       /* and forward */
//       ret = gst_pad_event_default (pad, parent, event);
//       break;
//     }
//     default:
//       ret = gst_pad_event_default (pad, parent, event);
//       break;
//   }
//   return ret;
// }

// static GstFlowReturn gst_my_filter_transform(GstBaseTransform *trans, GstBuffer *in_buf, GstBuffer *out_Buf){
//   GstMyFilter *filter = GST_MYFILTER(trans);
//   if(!filter->silent) g_print("I'm in the transform function\n");

//   return GST_FLOW_OK;
// }

static GstFlowReturn
gst_my_filter_transform(GstBaseTransform *trans, GstBuffer *in_buf, GstBuffer *out_buf)
{
  GstMyFilter *filter = GST_MYFILTER(trans);
  if (!filter->silent) g_print("I'm in the transform function\n");
  GstMapInfo in_map, out_map;
  gst_buffer_map(in_buf, &in_map, GST_MAP_READ);
  gst_buffer_map(out_buf, &out_map, GST_MAP_WRITE);
  // GetDict(filter->params, "")

  if(filter->mode == PRE_ENCRYPT)
  {
    CallMethod(filter->scheme, "encrypt_lvl2", "");
  } else if(filter->mode == PRE_DECRYPT)
  {
    CallMethod(filter->scheme, "decrypt_lvl1", "");
  } else
  {
    CallMethod(filter->scheme, "re_encrypt", "");
  }

  return GST_FLOW_OK;
}

/* chain function
 * this function does the actual processing
 */
// static GstFlowReturn
// gst_my_filter_chain (GstPad * pad, GstObject * parent, GstBuffer * buf)
// {
//   GstMyFilter *filter;

//   filter = GST_MYFILTER (parent);

//   if (!filter->silent)
//     g_print ("I'm plugged, therefore I'm in.\n");

//   /* just push out the incoming buffer without touching it */
//   return gst_pad_push (filter->srcpad, buf);
// }

/* entry point to initialize the plug-in
 * initialize the plug-in itself
 * register the element factories and other features
 */
static gboolean
myfilter_init(GstPlugin *myfilter)
{
  /* debug category for fltering log messages
   *
   * exchange the string 'Template myfilter' with your description
   */
  GST_DEBUG_CATEGORY_INIT(gst_my_filter_debug, "myfilter",
                          0, "Template myfilter");

  return gst_element_register(myfilter, "myfilter", GST_RANK_NONE,
                              GST_TYPE_MYFILTER);
}

/* PACKAGE: this is usually set by autotools depending on some _INIT macro
 * in configure.ac and then written into and defined in config.h, but we can
 * just set it ourselves here in case someone doesn't use autotools to
 * compile this code. GST_PLUGIN_DEFINE needs PACKAGE to be defined.
 */
#ifndef PACKAGE
#define PACKAGE "myfirstmyfilter"
#endif

/* gstreamer looks for this structure to register myfilters
 *
 * exchange the string 'Template myfilter' with your myfilter description
 */
GST_PLUGIN_DEFINE(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    myfilter,
    "Template myfilter",
    myfilter_init,
    VERSION,
    "LGPL",
    "GStreamer",
    "http://gstreamer.net/")
