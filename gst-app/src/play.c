/* Copyright (C) 2006 Tim-Philipp Müller <tim centricular net>
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

#include "play.h"
#include "gst/base/gstbasetransform.h"

const char *params = "eJyNVMtOxDAM/JWq5x7ibhw7fAoIrRa04rK3BSSE+Hf8GK+WG4e0jRM/xjPu9/q2Pizf6/H4ejldr8ej7daXr/fzdd0Ws36eLh/nsD71uS2s2yJ9W4hkW8awj303ywEWaupfbqd2exxwoGRXw2KbbovNd5qbR562hi0ZWHZR2RO4RzvkDbeKhVH39FqmH/r13ePaQ3vGJOIM4G4qWJyJw0blgYzUJh7dsg1JK/fbie3UTnjAuXkh7c+Vwhvo/B6QSdzvCVEBPbI7on6ojX2It7Bxhp4tcw3bD3r+MU4e/8sXU/IVhTPWLAKdty659N7gwKNkFMewi2Rj40yybU5DUCu3Zlbr0YvoiiSYFIbnGYyOccsVWMF+MDizrQzewysaTjtln5ghMAUvkcwbHvrSEqFWC6ZWLTsqjzqJEs8ArUFGq3IDOUOBLFm6hyzNugIzsmacSDpQU8iy7aUPl8ZQgEiVEuaIOjJ6DQmZCgqaEMy0TJk1aYaboM3Te8fi3dGMUp1AjjGBe8nPcxebGFcC/uirIF2pO6emJQUKMWPE738J9/SjgIDoE1gIY5BH/T5G3nK5DeCKUXCSPL0zkSKtYUxhS/r5dPz8AqJ66EY=";
const char *pk_a = "eJyNU7tOBDEM/JXV1lvE2SR2+BWETgeiggLpAAkh/h2PHxElxeYuyWQ8Htvf+9sL7Xfb9365PL1eb7fLRXf749f7820/Nj39vL5+PNvpfadj63Js0o+N6MRSsAwsLRaZClKg2H09toHrojcDT/XB1N+mX2fdK4Cqwlk5u25YgA4kUG2CB7ctYjEDwkFvRwA1Owa/bgYkFugtLscU9DP4CiLpHx6ejQdRBFf/iCgI7KGMOAI3dJtmS9Ew5gMkdTNkrmVENoaAQuTJK2J1amEnA2AglTNyxqYPtwz5G5CSs5hQceOgDKlYshTqINVcPdNVJRvspKiUtHhRSxB2i4044rE4neAsAjYtyKimld1r1s35ESFMZo8EqsejMsNW5CkBRXdMdg4rY/RVTboo5pS4b9E+3PwzMkrns9xIEg0D6lmiGyuFLJTa+oY4DZpxjw4a9PCjQ/D2Uv87IigrRsRNK26NEYOPR/ZyCoAsKw7Jmqm+eqa5dgAsU/KK4nfyepQT6baG2d4C2Y14MdZkcYDRXVLSgRmTI2EcRWBJW9eYlxU/YsBYE4gcowdQK85y9LGmSVKSBKcXPKL0LGheUBqJFAfHG2tStKw12enR5E/Vfn4BZhPqKQ==";
const char *sk_a = "eJyVT0kOwjAM/EqUcw5xsLPwFYSignpqbwEkVPXvjJN8gIOX8XgZH7ZtZK/msLU+96W1WoHs4/tam3UG1c+yv9devXF2RmCZnInRmYRIvrs8XYLxBbS2wWIBEXoLsqLVhAhjYMESIlE2AAVN/KAYLaIMMWaQRLqfENS28K/cKOOqsK5TkXHu1SNTux/lLBOotOLHsEB/1kc8z0F9S/xQ2LuAU5nxMsSeP+KAS1U=";
const char *pk_b = "eJyNU8FuHTEI/JXVnvdgvDbY/ZUqekqinJJDpNdWqqL8ezwMbHvM4e2zAcMwDB/7+6vsP7aP/XZ7fnu832+3dduf/v56ue/Htqx/Ht9+v7j1Z5dj6+PYrBzbOI9NylyXZRBZN+v0SK3LPXEQuBo+y27rYMs8erg0HozlmLbOFSl1HYyGidRlRaCwpzUgMCRErIwwN+BYEGYhDDxGGLK3ZVdldkX5de7AVE7iQUCH8WRFPER3bKwGBLVIj+pFWM89cwYKKYMlHBgY8HTKxxqtOwUS0ewuEI9APZCrAroRrhRQJui9sDD+nVlAQjcA72/UszayqpbvNBvOuKtyG+SGZANciYrwjKzsI/apyhnzY9IalJ7895BiUfuiRUQ5cJdCC6ptJoehD5/FGZwWCS9Aoy92XcmWSDZnyp+7ek2I+PQrWEJFEnLCdOnJdqxll0oAKg+fawXeX+t3FwQ67JdsZJIFcqgxMZeapgU8T2+rB289eaPSSkqqE9Slfs9aNOpY6Ic8p7K4l0nNNRqLTXKFu7Z8isZFYsiMXDMUDsnq/0Rb6sXVZjkRFGmxBzDSkV1ACsg0UnT5nsrK1fgnsUpLi53EHdCcMjQ/SvKXK60xuc8vei3qsg==";
const char *sk_b = "eJyVTzEOwyAQ+wpiZuAIcJd+papQWmVKNtpKVZS/1xdI9w4W2Jizb7N1IXsxmy3lsU61lgJm75/nXK0zUN/T+poP9RrFmQRIciaPAE6i4AyDiDRRCBwg70+HV4ZbilDUlmEbnIkMLfXvQ//S7DqVvDT9yKPbjj51CX+3HXUexoy+QVCDQ0/i2DIYGaO6swbzWSi31hSwUQptQ/K/cnhm6QqrVzfKre3+Bd4vS0Y=";
const char *rk_ab = "eJxFUDFuxDAM+4qR2YPk2LLcrxSH4FrcdlvaAkXRv5eMbHSII5EiTflnO4735/08j2N7Sdvb98fj3HIC+nV/fj4u9LWOnJrn5Iavoe45aSloNKeKpqNuIFRwuAAAoQrZAOsefxWg3VhQQ6PCscrDCYOrO6idSJtqiYtDWINtcDLYW5+yiMMIRQLugyYlAvqVxybShSouRLmuTgWcwaP7XIemDOS2duNY0QgwuCgC+ZKtQNcdKMaIARX5f7xrBzZma3yfaNvnc7T5Nr7W1NvvHwACUdM=";

void
play_uri (const gchar * uri)
{
  GstStateChangeReturn sret;
  GstElement *playbin, *audiosink, *videosink, *videoflip, *myfilter, *filter_bin, *source, *sink, *pipeline, *pre_enc, *pre_re_enc, *pre_dec;
  GstPad *pad, *ghost_pad;
  GstMessage *msg = NULL;
  GstBus *bus;

  g_print ("Trying to play %s ...\n", uri);

  // source = gst_element_factory_make("urisourcebin", "source");
  source = gst_element_factory_make("videotestsrc", "source");
  sink = gst_element_factory_make("filesink", "sink");
  videosink = gst_element_factory_make ("autovideosink", "videosink");
  pre_enc = gst_element_factory_make("myfilter", "pre_enc");
  pre_re_enc = gst_element_factory_make("myfilter", "pre_re_enc");
  pre_dec = gst_element_factory_make("myfilter", "pre_dec");
  

  pipeline = gst_pipeline_new("pipeline");

  if(!pipeline || !source || !videosink || !pre_enc || !pre_re_enc || !pre_dec){
    g_printerr("Not all elements could be created.\n");
    return;
  }
  gst_bin_add_many(GST_BIN(pipeline), source, pre_enc, pre_re_enc, pre_dec, videosink, NULL);
  if(gst_element_link_many(source, pre_enc, pre_re_enc, pre_dec, videosink, NULL) != TRUE){
    g_printerr("Elements could not be linked.\n");
  }



  // playbin = gst_element_factory_make ("playbin", "playbin");
  // if (playbin == NULL) goto no_playbin;

  // /* get playbin's bus - we'll watch it for messages */
  // bus = gst_pipeline_get_bus (GST_PIPELINE (playbin));
  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  g_object_set (source, "pattern", 0, NULL);

  g_object_set (pre_enc, "params", params, NULL);
  g_object_set (pre_enc, "mode", 0, NULL);
  g_object_set (pre_enc, "pk", pk_a, NULL);
  g_object_set (pre_enc, "sk", sk_a, NULL);

  g_object_set (pre_re_enc, "params", params, NULL);
  g_object_set (pre_re_enc, "mode", 1, NULL);
  g_object_set (pre_re_enc, "rk", rk_ab, NULL);

  g_object_set (pre_dec, "params", params, NULL);
  g_object_set (pre_dec, "mode", 2, NULL);
  g_object_set (pre_dec, "pk", pk_b, NULL);
  g_object_set (pre_dec, "sk", sk_b, NULL);

  // /* set audio sink */
  // audiosink = gst_element_factory_make ("autoaudiosink", "audiosink");
  // if (audiosink == NULL) goto no_autoaudiosink;
  // g_object_set (playbin, "audio-sink", audiosink, NULL);

  // /* set video sink */
  // videosink = gst_element_factory_make ("autovideosink", "videosink");
  // if (videosink == NULL) goto no_autovideosink;
  // g_object_set (playbin, "video-sink", videosink, NULL);

  
  // myfilter = gst_element_factory_make("myfilter", "myfilter");
  // if(myfilter == NULL) goto no_myfilter;



  // g_object_set(videoflip, "video-direction", 2, NULL);
  // g_object_set(playbin, "video-filter", myfilter, NULL);

  /* set URI to play back */
  // g_object_set (playbin, "uri", uri, NULL);
  // g_object_set (source, "uri", uri, NULL);

  // GST_DEBUG_BIN_TO_DOT_FILE(playbin, GST_DEBUG_GRAPH_SHOW_ALL, "playbin");

  /* and GO GO GO! */
  // gst_element_set_state (GST_ELEMENT (playbin), GST_STATE_PLAYING);
  gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_PLAYING);

  /* wait (blocks!) until state change either completes or fails */
  // sret = gst_element_get_state (GST_ELEMENT (playbin), NULL, NULL, -1);
  sret = gst_element_get_state (GST_ELEMENT (pipeline), NULL, NULL, -1);

  switch (sret) {
    case GST_STATE_CHANGE_FAILURE:{
      msg = gst_bus_poll (bus, GST_MESSAGE_ERROR, 0);
      goto got_error_message;
    }
    case GST_STATE_CHANGE_SUCCESS:{
      GstMessage *msg;

      g_print ("Playing ...\n");

      while (1) {
        gint64 dur, pos;

        if (gst_element_query_duration (playbin, GST_FORMAT_TIME, &dur) &&
            gst_element_query_position (playbin, GST_FORMAT_TIME, &pos)) {
          g_print ("  %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\n",
              GST_TIME_ARGS (pos), GST_TIME_ARGS (dur));
        }

        /* check if we finished or if there was an error,
         * but don't wait/block if neither is the case */
        msg = gst_bus_poll (bus, GST_MESSAGE_EOS | GST_MESSAGE_ERROR, 0);

        if (msg && GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR)
          goto got_error_message;

        if (msg && GST_MESSAGE_TYPE (msg) == GST_MESSAGE_EOS) {
          g_print ("Finished.\n");
          break;
        }

        /* sleep for one second */
        g_usleep (G_USEC_PER_SEC * 1);
      }
      break;
    }
    default:
      g_assert_not_reached ();
  }

  /* shut down and free everything */
  gst_element_set_state (playbin, GST_STATE_NULL);
  gst_object_unref (playbin);
  gst_object_unref (bus);
  return;

/* ERRORS */
got_error_message:
  {
    if (msg) {
      GError *err = NULL;
      gchar *dbg_str = NULL;

      gst_message_parse_error (msg, &err, &dbg_str);
      g_printerr ("FAILED to play %s: %s\n%s\n", uri, err->message,
          (dbg_str) ? dbg_str : "(no debugging information)");
      g_error_free (err);
      g_free (dbg_str);
      gst_message_unref (msg);
    } else {
      g_printerr ("FAILED to play %s: unknown error\n", uri);
    }

    /* shut down and free everything */
    gst_element_set_state (playbin, GST_STATE_NULL);
    gst_object_unref (playbin);
    gst_object_unref (bus);
    return;
  }

no_playbin:
  {
    g_error ("Could not create GStreamer 'playbin' element. "
        "Please install it");
    /* not reached, g_error aborts */
    return;
  }

no_autoaudiosink:
  {
    g_error ("Could not create GStreamer 'autoaudiosink' element. "
        "Please install it");
    /* not reached, g_error aborts */
    return;
  }

no_autovideosink:
  {
    g_error ("Could not create GStreamer 'autovideosink' element. "
        "Please install it");
    /* not reached, g_error aborts */
    return;
  }
no_videoflip:
  {
    g_error ("Could not create GStreamer 'videoflip' element. "
        "Please install it");
    /* not reached, g_error aborts */
    return;
  }
no_myfilter:
  {
    g_error ("Could not create GStreamer 'myfilter' element. "
        "Please install it");
    /* not reached, g_error aborts */
    return;
  }
}


