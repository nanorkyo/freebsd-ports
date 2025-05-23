PORTNAME=	dbus
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://chiselapp.com/user/schelte/repository/dbus/uv/
PKGNAMESUFFIX=	-tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl interface to the D-Bus messaging system
WWW=		http://chiselapp.com/user/schelte/repository/dbus/home

LICENSE=	ISCL

LIB_DEPENDS=	libdbus-1.so:devel/dbus
BUILD_DEPENDS=	dtplite:devel/tcllib

USES=		pkgconfig tcl:tea

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/dbus
PORTDOCS=	*

TEST_TARGET=	do-test

PLIST_FILES=	lib/dbus/lib${TCL_PKG_LIB_PREFIX}${TCL_PKG}.so \
		lib/dbus/pkgIndex.tcl \
		share/man/mann/dbus.n.gz

post-patch:
	${REINPLACE_CMD} \
	    -e '/^INSTALL_PROGRAM/s|$$| -s|' \
	    ${WRKSRC}/Makefile.in

do-test:
	DBUS=$$(${LOCALBASE}/bin/dbus-daemon --session --print-address --fork --print-pid); \
	DBUS_ADDR=$$(echo $$DBUS | ${AWK} '{print $$1}'); \
	DBUS_PID=$$(echo $$DBUS | ${AWK} '{print $$2}'); \
	DBUS_ENV=DBUS_SESSION_BUS_ADDRESS=$$DBUS_ADDR; \
	${SETENV} ${MAKE_ENV} $$DBUS_ENV ${MAKE} -C ${WRKSRC} test; \
	kill $$DBUS_PID

.include <bsd.port.mk>
