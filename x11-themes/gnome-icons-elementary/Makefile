PORTNAME=	elementary
DISTVERSION=	8.1.0
CATEGORIES=	x11-themes gnome
PKGNAMEPREFIX=	gnome-icons-

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Elementary icon set
WWW=		https://github.com/elementary/icons

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

USES=		gettext gnome meson python:build

USE_GITHUB=	yes
GH_PROJECT=	icons

USE_GNOME=	librsvg2

MESON_ARGS=	-Dpalettes=false \
		-Dvolume_icons=false

NO_ARCH=	yes

.include <bsd.port.mk>
