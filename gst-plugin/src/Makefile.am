# Note: plugindir is set in configure

##############################################################################
# TODO: change libgstplugin.la to something else, e.g. libmysomething.la     #
##############################################################################
plugin_LTLIBRARIES = libgstmyfilter.la

##############################################################################
# TODO: for the next set of variables, name the prefix if you named the .la, #
#  e.g. libmysomething.la => libmysomething_la_SOURCES                       #
#                            libmysomething_la_CFLAGS                        #
#                            libmysomething_la_LIBADD                        #
#                            libmysomething_la_LDFLAGS                       #
##############################################################################

## Plugin 1
# sources used to compile this plug-in
libgstmyfilter_la_SOURCES = gstmyfilter.c gstmyfilter.h charm_embed_api.c charm_embed_api.h

# compiler and linker flags used to compile this plugin, set in configure.ac
libgstmyfilter_la_CFLAGS = $(GST_CFLAGS) -O2 -g  -I/usr/include/python3.6m -I/usr/include/python3.6m  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes
# libgstmyfilter_la_CFLAGS = $(GST_CFLAGS) -I/usr/include/python3.6m -L/usr/local/lib -L/opt/local/lib -lpthread -ldl  -lutil -lm -lgmp -lpbc -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv  -Wall -Wstrict-prototypes -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/usr/lib -Xlinker -export-dynamic -Wl,-O0 -Wl,-Bsymbolic-functions -lpthread -ldl  -lutil -lm -lpython3.6m
libgstmyfilter_la_LIBADD = $(GST_LIBS) /usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/libpython3.6m.so
# libgstmyfilter_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS) -I/usr/include/python3.6m -L/usr/local/lib -L/opt/local/lib -lpthread -ldl  -lutil -lm -lgmp -lpbc -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/usr/lib  -Xlinker -export-dynamic -Wl,-O0 -Wl,-Bsymbolic-functions -lpthread -ldl  -lutil -lm -lpython3.6m
libgstmyfilter_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS) -O2 -g  -I/usr/include/python3.6m -I/usr/include/python3.6m  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -m64  -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/usr/lib -lpython3.6m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -L/usr/local/lib -L/opt/local/lib -lpthread -ldl  -lutil -lm -lgmp -lpbc -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -lpython3.6m
# libgstmyfilter_la_LDADD = /usr/local/lib/libcharm.a
libgstmyfilter_la_LIBTOOLFLAGS = --tag=disable-static



## Plugin 2 (audio filter example)

# sources used to compile this plug-in
# libgstaudiofilterexample_la_SOURCES = gstaudiofilter.c

# # compiler and linker flags used to compile this plugin, set in configure.ac
# libgstaudiofilterexample_la_CFLAGS = $(GST_CFLAGS)
# libgstaudiofilterexample_la_LIBADD = $(GST_LIBS)
# libgstaudiofilterexample_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
# libgstaudiofilterexample_la_LIBTOOLFLAGS = --tag=disable-static

# headers we need but don't want installed
noinst_HEADERS = gstmyfilter.h charm_embed_api.h
