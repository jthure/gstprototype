# name of your binary
bin_PROGRAMS = gst-app

# list of source files
# the prefix is the name of the binary
gst_app_SOURCES = main.c play.c

# list of headers we're not going to install
noinst_HEADERS = gst-app.h play.h

# our CFLAGS and LDFLAGS used for compiling and linking
# make sure you prefix these with the name of your binary
gst_app_CFLAGS = $(GST_CFLAGS) -no-pie -O2 -g -I/usr/local/include -I/usr/include/python3.6m -I/usr/include/python3.6m  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -lpython3.6m
gst_app_LDFLAGS = $(GST_LIBS)  -O2 -g  -I/usr/include/python3.6m -I/usr/include/python3.6m  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-sXpGnM/python3.6-3.6.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -m64  -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/usr/lib -lpython3.6m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -L/usr/local/lib -L/opt/local/lib -lpthread -ldl  -lutil -lm -lgmp -lpbc -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -lpython3.6m
