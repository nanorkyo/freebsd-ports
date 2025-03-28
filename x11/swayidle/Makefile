PORTNAME=	swayidle
DISTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	28950f787813.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	26e192a5f1b2.patch:-p1 # https://github.com/swaywm/swayidle/pull/89
PATCHFILES+=	f2f7e4d0a7c8.patch:-p1 # https://github.com/swaywm/swayidle/pull/89

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Idle management daemon for Wayland
WWW=		https://github.com/swaywm/swayidle

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.27:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

OPTIONS_DEFINE=	BASU MANPAGES
OPTIONS_DEFAULT=BASU MANPAGES

BASU_DESC=		ConsoleKit2 support via basu (experimental)
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	logind

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
# https://github.com/ConsoleKit2/ConsoleKit2/issues/150
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		${WRKSRC}/main.c
	@${REINPLACE_CMD} -e 's,systemd,ConsoleKit2,g' \
		-Ee '/conf/!s,logind(/elogind)?,ConsoleKit2,g' \
		${WRKSRC}/${PORTNAME}.1.scd

.include <bsd.port.mk>
