PORTNAME=	cinnamon-settings-daemon
PORTVERSION=	5.4.4
PORTREVISION=	6
CATEGORIES=	sysutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cinnamon desktop settings daemon
WWW=		https://github.com/linuxmint/cinnamon-settings-daemon

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	cinnamon-session:x11/cinnamon-session \
		gln:sysutils/coreutils
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libgudev-1.0.so:devel/libgudev \
		libcolord.so:graphics/colord \
		liblcms2.so:graphics/lcms2 \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxklavier.so:x11/libxklavier \
		libnspr4.so:devel/nspr \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libupower-glib.so:sysutils/upower \
		libpulse.so:audio/pulseaudio \
		libnotify.so:devel/libnotify \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	cinnamon-session:x11/cinnamon-session

USES=		compiler:c11 gettext-tools gnome localbase meson pkgconfig \
		python:build shebangfix xorg
USE_GNOME=	cairo dconf gdkpixbuf gtk30 intltool libgnomekbd pango
USE_XORG=	x11 xext xfixes xi

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

MESON_ARGS=	-Duse_logind=disabled

SHEBANG_GLOB=	*.py
BINARY_ALIAS=	ln=gln

USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.cinnamon.settings-daemon.enums.xml \
		org.cinnamon.settings-daemon.peripherals.gschema.xml \
		org.cinnamon.settings-daemon.peripherals.wacom.gschema.xml \
		org.cinnamon.settings-daemon.plugins.color.gschema.xml \
		org.cinnamon.settings-daemon.plugins.gschema.xml \
		org.cinnamon.settings-daemon.plugins.housekeeping.gschema.xml \
		org.cinnamon.settings-daemon.plugins.media-keys.gschema.xml \
		org.cinnamon.settings-daemon.plugins.power.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xrandr.gschema.xml \
		org.cinnamon.settings-daemon.plugins.xsettings.gschema.xml

OPTIONS_DEFINE=	CUPS SMARTCARD WACOM
OPTIONS_DEFAULT=CUPS SMARTCARD WACOM
OPTIONS_SUB=	yes

CUPS_MESON_ENABLED=	use_cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

SMARTCARD_DESC=	Smartcard support
SMARTCARD_MESON_ENABLED=	use_smartcard
SMARTCARD_LIB_DEPENDS=	libnss3.so:security/nss

WACOM_DESC=	Tablet support with libwacom
WACOM_MESON_ENABLED=	use_wacom
WACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
WACOM_USE=	gnome=librsvg2

post-patch:
	# Adhere to our hier(7).
	@${MKDIR} ${WRKSRC}/files${PREFIX}
	@${MV} ${WRKSRC}/files/usr/share ${WRKSRC}/files${PREFIX}

.include <bsd.port.mk>
