PORTNAME=	copyq
DISTVERSION=	9.0.0
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/hluk/CopyQ/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-${FLAVOR}
DISTNAME=	CopyQ-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt${FLAVOR:S/qt//} based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS=		qt5 qt6
FLAVOR?=		qt5
qt5_CONFLICTS_INSTALL=	copyq-qt6
qt6_CONFLICTS_INSTALL=	copyq-qt5

USES=		cmake gl kde:${FLAVOR:S/qt//} pkgconfig qt:${FLAVOR:S/qt//} \
		xorg
USE_GL=		gl
_USE_KDE_qt5=	ecm:build notifications
_USE_KDE_qt6=	ecm:build notifications statusnotifieritem
USE_KDE=	${_USE_KDE_${FLAVOR}}
_USE_QT5=	core dbus declarative gui network svg wayland widgets x11extras \
		xml buildtools:build qmake:build
_USE_QT6=	base declarative svg wayland translations:build
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}
USE_XORG=	ice sm x11 xext xfixes xtst

_QT6_CMAKE_ARGS=	-DWITH_QT6:BOOL=TRUE
CMAKE_ARGS=		${_QT${FLAVOR:S/qt//}_CMAKE_ARGS}

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		PLUGINS
OPTIONS_DEFAULT=	PLUGINS
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
