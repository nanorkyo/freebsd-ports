PORTNAME=	openal-soft
PORTVERSION=	1.21.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://openal-soft.org/openal-releases/

PATCH_SITES=	https://github.com/kcat/${PORTNAME}/commit/
PATCHFILES+=	440b59704c82684786bf7e251b4882f2a12c4c06.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Software implementation of the OpenAL specification
WWW=		https://openal-soft.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang tar:bzip2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_DATADIR:STRING="${PREFIX}/etc"
CMAKE_OFF=	ALSOFT_BACKEND_ALSA ALSOFT_DLOPEN ALSOFT_EXAMPLES \
		ALSOFT_REQUIRE_QSA ALSOFT_REQUIRE_SOLARIS
CMAKE_ON=	ALSOFT_BACKEND_WAVE

# do not link with librt and libdl.
LDFLAGS+=	-Wl,--as-needed
LDFLAGS_i386=	-Wl,-z,notext

PLIST_SUB=	SOVERSION=${PORTVERSION}

OPTIONS_DEFINE=		CONFIG EXAMPLES JACK OSS PORTAUDIO PULSEAUDIO \
			SDL SNDIO UTILS
OPTIONS_DEFAULT=	OSS UTILS
OPTIONS_SUB=		yes

CONFIG_DESC=	Install configuration utility (needs Qt 5)
UTILS_DESC=	Build and install utility programs

CONFIG_USES=		qt:5
CONFIG_USE=		QT=core,gui,widgets,buildtools:build,qmake:build
CONFIG_CMAKE_BOOL_OFF=	ALSOFT_NO_CONFIG_UTIL
CONFIG_CMAKE_ON=	-DALSOFT_NO_QT5:BOOL=OFF

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	ALSOFT_BACKEND_JACK ALSOFT_REQUIRE_JACK

OSS_CMAKE_BOOL=	ALSOFT_BACKEND_OSS ALSOFT_REQUIRE_OSS

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	ALSOFT_BACKEND_PORTAUDIO ALSOFT_REQUIRE_PORTAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ALSOFT_BACKEND_PULSEAUDIO ALSOFT_REQUIRE_PULSEAUDIO

SDL_USES=	localbase sdl
SDL_USE=	SDL=sdl2
SDL_CMAKE_BOOL=	ALSOFT_BACKEND_SDL2 ALSOFT_REQUIRE_SDL2

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ALSOFT_BACKEND_SNDIO ALSOFT_REQUIRE_SNDIO

UTILS_LIB_DEPENDS=	libmysofa.so:audio/libmysofa
UTILS_CMAKE_BOOL=	ALSOFT_UTILS

.include <bsd.port.pre.mk>

# The following is actually meant for lld 15.0 and later, but the ports
# framework does not support LINKER_TYPE and LINKER_VERSION yet.
.if ${COMPILER_TYPE} == "clang"
# Turn off checking of dynamic relocations, to avoid lld diagnostics about
# possibly incorrect addend values.
LDFLAGS_i386+=	-Wl,--no-check-dynamic-relocations
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc/openal|${ETCDIR}|' \
		${WRKSRC}/alc/alconfig.cpp

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
