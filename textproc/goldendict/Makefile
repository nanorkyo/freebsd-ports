PORTNAME=	goldendict
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Feature-rich dictionary lookup program
WWW=		http://goldendict.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		liblzo2.so:archivers/lzo2 \
		libogg.so:audio/libogg \
		libtiff.so:graphics/tiff \
		libvorbis.so:audio/libvorbis \
		libzstd.so:archivers/zstd

USES=		compiler:c++11-lang gnome iconv:wchar_t pkgconfig \
		qmake qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	vedgy
GH_TAGNAME=	5a87a71
USE_XORG=	x11 xtst
USE_QT=		buildtools:build linguisttools:build \
		core declarative gui help network printsupport \
		sql svg webchannel webengine widgets x11extras xml

QMAKE_ARGS=	${PORTNAME}.pro CONFIG+="use_qtwebengine zim_support"

OPTIONS_DEFINE=	EPWING FFMPEG MULTIMEDIA OPENCC
OPTIONS_DEFAULT=	EPWING FFMPEG MULTIMEDIA OPENCC

EPWING_DESC=		Japanese EPWING dictionary format support
EPWING_LIB_DEPENDS=	libeb.so:japanese/eb
EPWING_QMAKE_OFF=	CONFIG+="no_epwing_support"

FFMPEG_LIB_DEPENDS=	libao.so:audio/libao \
			libavutil.so:multimedia/ffmpeg
FFMPEG_QMAKE_OFF=	CONFIG+="no_ffmpeg_player"

MULTIMEDIA_DESC=	Multimedia support with QMediaPlayer
MULTIMEDIA_USE=		QT=multimedia
MULTIMEDIA_QMAKE_OFF=	CONFIG+="no_qtmultimedia_player"

OPENCC_DESC=		Chinese conversion support via OpenCC
OPENCC_LIB_DEPENDS=	libopencc.so:chinese/opencc
OPENCC_QMAKE_ON=	CONFIG+="chinese_conversion_support"

post-patch:
	@${REINPLACE_CMD} -e '/QMAKE_CXXFLAGS += -rdynamic/d ; \
	    /^VERSION = /s,git,&-${GH_ACCOUNT}-${GH_TAGNAME},' \
		${WRKSRC}/goldendict.pro
	@${REINPLACE_CMD} -e '/^#include <stdio\.h>/ { x; \
		s/^/#include <locale.h>/; G; }' ${WRKSRC}/main.cc

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/share/applications/ecp.*

.include <bsd.port.mk>
