PORTNAME=	gnome-power-manager
PORTVERSION=	3.32.0
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop
WWW=		https://projects.gnome.org/gnome-power-manager/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-builder:devel/appstream-glib
LIB_DEPENDS=	libupower-glib.so:sysutils/upower

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase:ldflags meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack
MESON_ARGS=	-Denable-tests=false

GLIB_SCHEMAS=	org.gnome.power-manager.gschema.xml

OPTIONS_DEFINE=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook2html:textproc/docbook-utils \
			docbook-sgml>0:textproc/docbook-sgml

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -e "s|subdir('man')||g" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
